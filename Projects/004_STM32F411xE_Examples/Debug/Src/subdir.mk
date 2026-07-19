################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/005_Onboard_LED_Output_by_Scanning_Input_Pin.c \
../Src/itm_send_data.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/005_Onboard_LED_Output_by_Scanning_Input_Pin.o \
./Src/itm_send_data.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/005_Onboard_LED_Output_by_Scanning_Input_Pin.d \
./Src/itm_send_data.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu17 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -I"C:/Users/HALUK/Documents/stm32_target_workspace/Projects/004_STM32F411xE_Examples/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -Wextra -pedantic -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wconversion -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/005_Onboard_LED_Output_by_Scanning_Input_Pin.cyclo ./Src/005_Onboard_LED_Output_by_Scanning_Input_Pin.d ./Src/005_Onboard_LED_Output_by_Scanning_Input_Pin.o ./Src/005_Onboard_LED_Output_by_Scanning_Input_Pin.su ./Src/itm_send_data.cyclo ./Src/itm_send_data.d ./Src/itm_send_data.o ./Src/itm_send_data.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

