################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DiamondProblem.cpp \
../src/Functor.cpp \
../src/VirtualCpp.cpp 

O_SRCS += \
../src/func.o 

OBJS += \
./src/DiamondProblem.o \
./src/Functor.o \
./src/VirtualCpp.o 

CPP_DEPS += \
./src/DiamondProblem.d \
./src/Functor.d \
./src/VirtualCpp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


