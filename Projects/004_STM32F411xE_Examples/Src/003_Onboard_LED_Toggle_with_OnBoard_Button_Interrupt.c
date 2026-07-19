/*
 * 003_Onboard_LED_Toggle_with_OnBoard_Button_Interrupt.c
 *
 *  Created on: Jun 19, 2026
 */

/* Includes */
#include "stm32f411xe_gpio.h"

/* Definitions */

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
					.GPIO_PinMode = GPIO_MODE_INPUT_FE,
					.GPIO_PinPUPD = GPIO_NO_PUPD,
			}
	};

	GPIO_ClockControl(PA5_LED.GPIOx, ENABLE);
	GPIO_Init(&PA5_LED);
	GPIO_WriteToOutputPin(PA5_LED.GPIOx, PA5_LED.GPIOx_PinConfig.GPIO_PinNumber, GPIO_RESET);

	GPIO_ClockControl(PC13_BUTTON.GPIOx, ENABLE);
	GPIO_Init(&PC13_BUTTON);

	GPIO_IRQInterruptConfig(IRQ_NUMBER_EXTI15_10, ENABLE);
	GPIO_IRQPriorityConfig(IRQ_NUMBER_EXTI15_10, IRQ_PRIORITY_15);

	// Loop forever
	while (1) {
		// Do nothing
		__asm volatile("nop");
	}
}

/* Simple static software delay function */
void delay_with_loop(void)
{
	for (volatile uint32_t i = 0; i < 50000; i++) {
		__asm volatile("nop");
	}
}

void EXTI15_10_IRQHandler(void)
{
	GPIO_IRQHandling(GPIO_PIN_13);

	// Add a small delay for button debouncing to avoid multiple toggles because of mechanical switch noises
	delay_with_loop();

	GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_5);
}
