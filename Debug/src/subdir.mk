################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Die.cpp \
../src/Game.cpp \
../src/Player.cpp \
../src/UI.cpp \
../src/Window.cpp \
../src/main.cpp 

OBJS += \
./src/Die.o \
./src/Game.o \
./src/Player.o \
./src/UI.o \
./src/Window.o \
./src/main.o 

CPP_DEPS += \
./src/Die.d \
./src/Game.d \
./src/Player.d \
./src/UI.d \
./src/Window.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__cplusplus=201103L -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


