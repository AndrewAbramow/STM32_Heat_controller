################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Cpp/Src/AdaptiveFilter.cpp \
../Cpp/Src/CppMain.cpp \
../Cpp/Src/DS18B20.cpp \
../Cpp/Src/HS42056.cpp \
../Cpp/Src/OnOffRegulator.cpp \
../Cpp/Src/PIDRegulator.cpp \
../Cpp/Src/RelayOutput.cpp \
../Cpp/Src/TM1637.cpp \
../Cpp/Src/Timing.cpp 

OBJS += \
./Cpp/Src/AdaptiveFilter.o \
./Cpp/Src/CppMain.o \
./Cpp/Src/DS18B20.o \
./Cpp/Src/HS42056.o \
./Cpp/Src/OnOffRegulator.o \
./Cpp/Src/PIDRegulator.o \
./Cpp/Src/RelayOutput.o \
./Cpp/Src/TM1637.o \
./Cpp/Src/Timing.o 

CPP_DEPS += \
./Cpp/Src/AdaptiveFilter.d \
./Cpp/Src/CppMain.d \
./Cpp/Src/DS18B20.d \
./Cpp/Src/HS42056.d \
./Cpp/Src/OnOffRegulator.d \
./Cpp/Src/PIDRegulator.d \
./Cpp/Src/RelayOutput.d \
./Cpp/Src/TM1637.d \
./Cpp/Src/Timing.d 


# Each subdirectory must supply rules for building sources it contributes
Cpp/Src/%.o Cpp/Src/%.su: ../Cpp/Src/%.cpp Cpp/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++20 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Andrew/Documents/MyProjects/STM32_PLC/Cpp/Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Cpp-2f-Src

clean-Cpp-2f-Src:
	-$(RM) ./Cpp/Src/AdaptiveFilter.d ./Cpp/Src/AdaptiveFilter.o ./Cpp/Src/AdaptiveFilter.su ./Cpp/Src/CppMain.d ./Cpp/Src/CppMain.o ./Cpp/Src/CppMain.su ./Cpp/Src/DS18B20.d ./Cpp/Src/DS18B20.o ./Cpp/Src/DS18B20.su ./Cpp/Src/HS42056.d ./Cpp/Src/HS42056.o ./Cpp/Src/HS42056.su ./Cpp/Src/OnOffRegulator.d ./Cpp/Src/OnOffRegulator.o ./Cpp/Src/OnOffRegulator.su ./Cpp/Src/PIDRegulator.d ./Cpp/Src/PIDRegulator.o ./Cpp/Src/PIDRegulator.su ./Cpp/Src/RelayOutput.d ./Cpp/Src/RelayOutput.o ./Cpp/Src/RelayOutput.su ./Cpp/Src/TM1637.d ./Cpp/Src/TM1637.o ./Cpp/Src/TM1637.su ./Cpp/Src/Timing.d ./Cpp/Src/Timing.o ./Cpp/Src/Timing.su

.PHONY: clean-Cpp-2f-Src

