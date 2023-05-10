/*
 * TM1637.hpp
 *
 *  Created on: May 5, 2023
 *      Author: abramov.a
 */

#ifndef TM1637_HPP_
#define TM1637_HPP_

#include <stdint.h>
#include <array>
#include <map>
#include <string>
#include "stm32f1xx_hal.h"

// https://github.com/UsefulElectronics/stm32-tm1637-library
// https://www.youtube.com/watch?v=hrVOO_k5FOI&t=597s&ab_channel=UsefulElectronics

//==============================================================================
// Definitions
//==============================================================================
//Segments
//  --0x01--
// |        |
//0x20     0x02
// |        |
//  --0x40- -
// |        |
//0x10     0x04
// |        |
//  --0x08--

enum TM1637Status
{
	TM1637_OK = 0U,
	TM1637_ERROR
};

class TM1637 {
public:
	TM1637();
	virtual ~TM1637();

	void CLKhigh();
	void CLKlow();
	void SDOhigh();
	void SDOlow();
	void DataOut(uint8_t* TxBuffer);
	void TxData(uint8_t* data, uint8_t packetSize);
	void ACKcheck();
	void Initialize(uint8_t direction);
	void StartPacket();
	void EndPacket();
	void TxCommand(uint8_t* command);
	//void Effect(uint8_t rotationFrequency);
	void DisplayClear();
	uint8_t DisplayHandle(uint8_t brightness, std::string str);
	void FillBuffer(std::string str);
	TM1637Status SetBrighness(uint8_t brighnessLevel);

//private:
	std::array<uint8_t, 8> segments
	{
		0x01, // A SEG
		0x02, // B SEG
		0x04, // C SEG
		0x08, // D SEG
		0x10, // E SEG
		0x20, // F SEG
		0x40, // G SEG
		0x80  // DP SEG
	};

	std::array<uint8_t, 6> addresses
	{
		0xC0, // C0H
		0xC1, // C1H
		0xC2, // C2H
		0xC3, // C3H
		0xC4, // C4H
		0xC5  // C5H
	};

	std::array<uint8_t, 2> settings
	{
		0x00, // STM2DISPLAY
		0x01  // DISPLAY2STM
	};

	std::array<uint8_t, 5> commands
	{
		0x40, // DATA_SET
		0x44, // DATA_FIXED
		0x88, // DISPLAY_ON
		0x80, // DISPLAY_OFF
		0x08  // PACKET_SIZE
	};

	std::map<char, uint8_t> alphabet
	{
		{'0',0x3f},
		{'1',0x06},
		{'2',0x5b},
		{'3',0x4f},
		{'4',0x66},
		{'5',0x6d},
		{'6',0x7d},
		{'7',0x07},
		{'8',0x7f},
		{'9',0x6f}
	};

	GPIO_TypeDef* SCLK_SDO_Port = GPIOB;
	uint16_t SCLK_Pin = GPIO_PIN_6;
	uint16_t SDO_Pin = GPIO_PIN_7;
	uint8_t STM2DISPLAY = 0;
	uint8_t DISPLAY2STM = 1;

	uint8_t displayBuffer[4]{0};
};

#endif /* TM1637_HPP_ */

/*
	            case '_' : return 0x08;
	            case '^' : return 0x01; // ¯
	            case '-' : return 0x40;
	            case '*' : return 0x63; // °
	            case ' ' : return 0x00; // space
	            case 'A' : return 0x77; // upper case A
	            case 'a' : return 0x5f; // lower case a
	            case 'B' :              // lower case b
	            case 'b' : return 0x7c; // lower case b
	            case 'C' : return 0x39; // upper case C
	            case 'c' : return 0x58; // lower case c
	            case 'D' :              // lower case d
	            case 'd' : return 0x5e; // lower case d
	            case 'E' :              // upper case E
	            case 'e' : return 0x79; // upper case E
	            case 'F' :              // upper case F
	            case 'f' : return 0x71; // upper case F
	            case 'G' :              // upper case G
	            case 'g' : return 0x35; // upper case G
	            case 'H' : return 0x76; // upper case H
	            case 'h' : return 0x74; // lower case h
	            case 'I' : return 0x06; // 1
	            case 'i' : return 0x04; // lower case i
	            case 'J' : return 0x1e; // upper case J
	            case 'j' : return 0x16; // lower case j
	            case 'K' :              // upper case K
	            case 'k' : return 0x75; // upper case K
	            case 'L' :              // upper case L
	            case 'l' : return 0x38; // upper case L
	            case 'M' :              // twice tall n
	            case 'm' : return 0x37; // twice tall ∩
	            case 'N' :              // lower case n
	            case 'n' : return 0x54; // lower case n
	            case 'O' :              // lower case o
	            case 'o' : return 0x5c; // lower case o
	            case 'P' :              // upper case P
	            case 'p' : return 0x73; // upper case P
	            case 'Q' : return 0x7b; // upper case Q
	            case 'q' : return 0x67; // lower case q
	            case 'R' :              // lower case r
	            case 'r' : return 0x50; // lower case r
	            case 'S' :              // 5
	            case 's' : return 0x6d; // 5
	            case 'T' :              // lower case t
	            case 't' : return 0x78; // lower case t
	            case 'U' :              // lower case u
	            case 'u' : return 0x1c; // lower case u
	            case 'V' :              // twice tall u
	            case 'v' : return 0x3e; // twice tall u
	            case 'W' : return 0x7e; // upside down A
	            case 'w' : return 0x2a; // separated w
	            case 'X' :              // upper case H
	            case 'x' : return 0x76; // upper case H
	            case 'Y' :              // lower case y
	            case 'y' : return 0x6e; // lower case y
	            case 'Z' :              // separated Z
	            case 'z' : return 0x1b;
*/
