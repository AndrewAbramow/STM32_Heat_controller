################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Cpp/Src/adaptive_filter.cpp \
../Cpp/Src/cpp_main.cpp \
../Cpp/Src/ds18b20.cpp \
../Cpp/Src/hs42056.cpp \
../Cpp/Src/on_off_regulator.cpp \
../Cpp/Src/pid_regualtor.cpp \
../Cpp/Src/relay_output.cpp \
../Cpp/Src/timing.cpp \
../Cpp/Src/tm1637.cpp 

OBJS += \
./Cpp/Src/adaptive_filter.o \
./Cpp/Src/cpp_main.o \
./Cpp/Src/ds18b20.o \
./Cpp/Src/hs42056.o \
./Cpp/Src/on_off_regulator.o \
./Cpp/Src/pid_regualtor.o \
./Cpp/Src/relay_output.o \
./Cpp/Src/timing.o \
./Cpp/Src/tm1637.o 

CPP_DEPS += \
./Cpp/Src/adaptive_filter.d \
./Cpp/Src/cpp_main.d \
./Cpp/Src/ds18b20.d \
./Cpp/Src/hs42056.d \
./Cpp/Src/on_off_regulator.d \
./Cpp/Src/pid_regualtor.d \
./Cpp/Src/relay_output.d \
./Cpp/Src/timing.d \
./Cpp/Src/tm1637.d 


# Each subdirectory must supply rules for building sources it contributes
Cpp/Src/%.o Cpp/Src/%.su: ../Cpp/Src/%.cpp Cpp/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++20 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Andrew/Documents/MyProjects/STM32_PLC/Cpp/Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Cpp-2f-Src

clean-Cpp-2f-Src:
	-$(RM) ./Cpp/Src/adaptive_filter.d ./Cpp/Src/adaptive_filter.o ./Cpp/Src/adaptive_filter.su ./Cpp/Src/cpp_main.d ./Cpp/Src/cpp_main.o ./Cpp/Src/cpp_main.su ./Cpp/Src/ds18b20.d ./Cpp/Src/ds18b20.o ./Cpp/Src/ds18b20.su ./Cpp/Src/hs42056.d ./Cpp/Src/hs42056.o ./Cpp/Src/hs42056.su ./Cpp/Src/on_off_regulator.d ./Cpp/Src/on_off_regulator.o ./Cpp/Src/on_off_regulator.su ./Cpp/Src/pid_regualtor.d ./Cpp/Src/pid_regualtor.o ./Cpp/Src/pid_regualtor.su ./Cpp/Src/relay_output.d ./Cpp/Src/relay_output.o ./Cpp/Src/relay_output.su ./Cpp/Src/timing.d ./Cpp/Src/timing.o ./Cpp/Src/timing.su ./Cpp/Src/tm1637.d ./Cpp/Src/tm1637.o ./Cpp/Src/tm1637.su

.PHONY: clean-Cpp-2f-Src

