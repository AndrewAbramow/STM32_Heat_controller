/*
 * TM1637.cpp
 *
 *  Created on: May 5, 2023
 *      Author: abramov.a
 */

#include "TM1637.hpp"

TM1637::TM1637() {
	// TODO Auto-generated constructor stub

}

TM1637::~TM1637() {
	// TODO Auto-generated destructor stub
}

void TM1637::CLKhigh()
{																	  	//SCL high period
	HAL_GPIO_WritePin(SCLK_SDO_Port, SCLK_Pin, GPIO_PIN_SET);		  	//Setting SCL frequency
	HAL_GPIO_WritePin(SCLK_SDO_Port, SCLK_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SCLK_SDO_Port, SCLK_Pin, GPIO_PIN_SET);
}

void TM1637::CLKlow()
{
	HAL_GPIO_WritePin(SCLK_SDO_Port, SCLK_Pin, GPIO_PIN_RESET);		//SCL low period
	HAL_GPIO_WritePin(SCLK_SDO_Port, SCLK_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SCLK_SDO_Port, SCLK_Pin, GPIO_PIN_RESET);
}

void TM1637::SDOhigh()
{
	HAL_GPIO_WritePin(SCLK_SDO_Port, SDO_Pin, GPIO_PIN_SET);			//SDO high period
	HAL_GPIO_WritePin(SCLK_SDO_Port, SDO_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SCLK_SDO_Port, SDO_Pin, GPIO_PIN_SET);
}

void TM1637::SDOlow()
{
	HAL_GPIO_WritePin(SCLK_SDO_Port, SDO_Pin, GPIO_PIN_RESET);			//SDO low period
	HAL_GPIO_WritePin(SCLK_SDO_Port, SDO_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SCLK_SDO_Port, SDO_Pin, GPIO_PIN_RESET);
}

void TM1637::StartPacket()												//Lower SDO line while CLK line is high
{
	CLKhigh();

	SDOhigh();
	SDOlow();

	CLKlow();
}

void TM1637::EndPacket()													//SDO line is pulled high while SCL line is high
{
	CLKlow();
	SDOlow();

	CLKhigh();
	SDOhigh();
}

void TM1637::DataOut(uint8_t* TxBuffer)							//Low level data transfer function
{
	for(int8_t j = 0; j < commands[4]; j++)								//Send least significant bit first
	{
		CLKlow();
		if(TxBuffer[j] == GPIO_PIN_SET)							//Check logic level
		{
			SDOhigh();
		}
		else
		{
			SDOlow();
		}
		CLKhigh();
	}
}

void TM1637::TxCommand(uint8_t* command)
{																		//Handles high level (bit by bit) transmission operation
	uint8_t byteData[8] = {0};

	for(uint8_t i = 0; i < commands[4]; i++)
	{
		byteData[i] = (command[0] & (0x01 << i)) && 1;																		//Convert from byte to bit per array element
	}
	StartPacket();												//Send start packet bit
	DataOut(byteData);											//Send one byte
	CLKlow();													//Send one CLK for acknowledgment
	CLKhigh();
	ACKcheck();													//wait for acknowledgment.
	if((command[0] & 0xC0) != (0xC0))										//Check if the received packet is not an address.
	{
		EndPacket();
	}
}

void TM1637::TxData(uint8_t* data, uint8_t packetSize)
{																		//Handles high level (bit by bit) transmission operation
	uint8_t byteData[8] = {0};

	for(uint8_t i = 0; i < packetSize; i++)
	{
		for(uint8_t j = 0; j < 8; j++)
		{
			byteData[j] = (data[i] & (0x01 << j)) && 1;
		}
		DataOut(byteData);
		CLKlow();
		CLKhigh();
		ACKcheck();	//Transmit byte by byte
	}
	EndPacket(); //Send end packet at the end of data transmission.
}

void TM1637::Initialize(uint8_t direction)								//Since SDI line is doing both transmission and reception
{																		//the corresponding GPIO pin must be reinitialized on the run
	GPIO_InitTypeDef GPIO_InitStruct = {0};								//To read ACK from TM1637 and to write data to it
	GPIO_InitStruct.Pin = SCLK_Pin;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	switch (direction)													//Depending on the function input initialize the pin as input or output
	{
		case 0:
			GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
			HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
			break;
		case 1:
			GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
			HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
			break;
	}
}

void TM1637::ACKcheck()
{
	//Wait for acknowledgment bit
	Initialize(settings[1]);										//initialize pin as input
	CLKlow();													//lower CLK line
	while(HAL_GPIO_ReadPin(SCLK_SDO_Port, SCLK_Pin))					//Wait until ACK bit is received
	Initialize(settings[0]);										//initialize pin as output for data transfer
}

void TM1637::DisplayClear()
{
	uint8_t emptyBuffer[4]{0};
	uint8_t commandCarrier[1]{0};
	commandCarrier[0] = commands[0];									//Send set data command
	TxCommand(commandCarrier);
	commandCarrier[0] = addresses[0];										//Set address
	TxCommand(commandCarrier);
	TxData(emptyBuffer, 4);
	commandCarrier[0] = commands[3];
	TxCommand(commandCarrier);
}

uint8_t TM1637::DisplayHandle(uint8_t brightness, std::string str)
{
	//This function handles the low level protocol used to set data address of TM1637 and turn the display on
	//#param Brightness is used to set the brightness level of the display. This function accepts Brightness value between 0 and 7
	//#param *DisplayBuffer is the buffer used to map data from the RAM to the display each element corresponds to one segment in the display
	uint8_t commandCarrier[1]{0};
	TM1637Status parameterFalidation = TM1637_ERROR;
	if(brightness <= 7)												//there are 7 levels of brightness
	{
	  commandCarrier[0] = commands[0];									//Send set data command
	  TxCommand(commandCarrier);
	  commandCarrier[0] = addresses[0];										//Set address
	  TxCommand(commandCarrier);

	  FillBuffer(str);
	  TxData(displayBuffer, 4);								//Map the data stored in RAM to the display
	  SetBrighness(brightness);								//Turn on display and set brightness
	  parameterFalidation = TM1637_OK;
	  return parameterFalidation;
	}
	return parameterFalidation;
}

TM1637Status TM1637::SetBrighness(uint8_t brighnessLevel)
{
	uint8_t brighnessBuffer[8] = {0};
	TM1637Status parameterFalidation = TM1637_ERROR;
	if(brighnessLevel <= 7)												//there are 7 levels of brightness
	{																	//Any value above that will be ignored.
		brighnessLevel = brighnessLevel | commands[2];					//Set Brightness level with display on command

		for(uint8_t i = 0; i < 8; i++)
		{
			brighnessBuffer[i] = (brighnessLevel & (0x01 << i)) && 1;
		}
		StartPacket();
		DataOut(brighnessBuffer);
		CLKlow();													//Send one CLK for acknowledgment
		CLKhigh();
		ACKcheck();													//wait for acknowledgment.
		EndPacket();
		parameterFalidation = TM1637_OK;
		return parameterFalidation;
	}
	return parameterFalidation;
}

void TM1637::FillBuffer(std::string str)
{
	uint8_t i = 0;
	std::for_each(str.begin(), str.end(), [this,&i](char& ch)
			{
				displayBuffer[i] = alphabet.at(ch);
				++i;
			});
}
