################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Src/stm32f411xe_gpio.c 

OBJS += \
./Drivers/Src/stm32f411xe_gpio.o 

C_DEPS += \
./Drivers/Src/stm32f411xe_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Src/%.o Drivers/Src/%.su Drivers/Src/%.cyclo: ../Drivers/Src/%.c Drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu17 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -I"C:/Users/HALUK/Documents/stm32_target_workspace/Projects/004_STM32F411xE_Examples/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -Wextra -pedantic -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wconversion -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-Src

clean-Drivers-2f-Src:
	-$(RM) ./Drivers/Src/stm32f411xe_gpio.cyclo ./Drivers/Src/stm32f411xe_gpio.d ./Drivers/Src/stm32f411xe_gpio.o ./Drivers/Src/stm32f411xe_gpio.su

.PHONY: clean-Drivers-2f-Src

