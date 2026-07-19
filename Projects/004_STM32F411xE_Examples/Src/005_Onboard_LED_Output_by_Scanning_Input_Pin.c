/*
 * 005_Onboard_LED_Output_by_Scanning_Input_Pin.c
 *
 *  Created on: Jun 23, 2026
 */

/* Includes */
#include "stm32f411xe_gpio.h"

/* Definitions */

/* Globals */

/* Function Prototypes */

/************/
int main(void)
{
	GPIO_Handle_t PA5_LED = {
			.GPIOx = GPIOA,
			.GPIOx_PinConfig = {
					.GPIO_PinNumber = GPIO_PIN_5,
					.GPIO_PinMode = GPIO_MODE_OUTPUT,
					.GPIO_PinOutputType = GPIO_OUTPUT_PUSH_PULL,
					.GPIO_PinOutputSpeed = GPIO_OUTPUT_SPEED_LOW,
					.GPIO_PinPUPD = GPIO_NO_PUPD,
			}
	};

	GPIO_Handle_t PA9_INPUT = {
			.GPIOx = GPIOA,
			.GPIOx_PinConfig = {
					.GPIO_PinNumber = GPIO_PIN_9,
					.GPIO_PinMode = GPIO_MODE_INPUT,
					.GPIO_PinPUPD = GPIO_PD,
			}
	};

	GPIO_ClockControl(PA5_LED.GPIOx, ENABLE);
	GPIO_Init(&PA5_LED);
	GPIO_WriteToOutputPin(PA5_LED.GPIOx, PA5_LED.GPIOx_PinConfig.GPIO_PinNumber, GPIO_RESET);

	GPIO_ClockControl(PA9_INPUT.GPIOx, ENABLE);
	GPIO_Init(&PA9_INPUT);

	// Loop forever
	while (1) {
		if (GPIO_ReadFromInputPin(PA9_INPUT.GPIOx, PA9_INPUT.GPIOx_PinConfig.GPIO_PinNumber) == SET) {
			GPIO_WriteToOutputPin(PA5_LED.GPIOx, PA5_LED.GPIOx_PinConfig.GPIO_PinNumber, GPIO_SET);
		} else {
			GPIO_WriteToOutputPin(PA5_LED.GPIOx, PA5_LED.GPIOx_PinConfig.GPIO_PinNumber, GPIO_RESET);
		}
	}
}
