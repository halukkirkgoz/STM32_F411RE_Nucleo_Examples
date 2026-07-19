/*
 * 002_Onboard_LED_Toggle_with_OnBoard_Button.c
 *
 *  Created on: Jun 18, 2026
 */

/* Includes */
#include "stm32f411xe_gpio.h"

/* Definitions */
#define BUTTON_PRESSED  ((uint8_t) 0UL)
#define BUTTON_RELEASED ((uint8_t) 1UL)

/* Globals */

/* Function Prototypes */
void delay_with_loop(void);

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

	GPIO_Handle_t PC13_BUTTON = {
			.GPIOx = GPIOC,
			.GPIOx_PinConfig = {
					.GPIO_PinNumber = GPIO_PIN_13,
					.GPIO_PinMode = GPIO_MODE_INPUT,
					.GPIO_PinPUPD = GPIO_NO_PUPD,
			}
	};

	GPIO_ClockControl(PA5_LED.GPIOx, ENABLE);
	GPIO_Init(&PA5_LED);
	GPIO_WriteToOutputPin(PA5_LED.GPIOx, PA5_LED.GPIOx_PinConfig.GPIO_PinNumber, GPIO_RESET);

	GPIO_ClockControl(PC13_BUTTON.GPIOx, ENABLE);
	GPIO_Init(&PC13_BUTTON);

	// Loop forever
	while (1) {
		if (GPIO_ReadFromInputPin(PC13_BUTTON.GPIOx, PC13_BUTTON.GPIOx_PinConfig.GPIO_PinNumber) == BUTTON_PRESSED) {
			// Add a small delay for button debouncing to avoid multiple toggles because of mechanical switch noises
			delay_with_loop();

			// Double check: Is the button still pressed after delay?
			if (GPIO_ReadFromInputPin(PC13_BUTTON.GPIOx, PC13_BUTTON.GPIOx_PinConfig.GPIO_PinNumber) == BUTTON_PRESSED) {
				GPIO_ToggleOutputPin(PA5_LED.GPIOx, PA5_LED.GPIOx_PinConfig.GPIO_PinNumber);

				// Wait for button release: Loop here as long as button is held down.
				while (GPIO_ReadFromInputPin(PC13_BUTTON.GPIOx, PC13_BUTTON.GPIOx_PinConfig.GPIO_PinNumber)
				        == BUTTON_PRESSED) {
					__asm volatile("nop");
				}
			}
		}
	}
}

/* Simple static software delay function */
void delay_with_loop(void)
{
	for (volatile uint32_t i = 0; i < 100000; i++) {
		__asm volatile("nop");
	}
}
