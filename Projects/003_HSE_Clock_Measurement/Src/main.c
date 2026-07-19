#include <stdint.h>

// Base addresses for peripherals
#define RCC_BASE_ADDR        ((uint32_t) 0x40023800UL)
#define GPIOA_BASE_ADDR      ((uint32_t) 0x40020000UL)

// Offset addresses for relevant registers
#define RCC_CR_REG_OFFSET       ((uint32_t) 0x00000000UL)
#define RCC_CFGR_REG_OFFSET     ((uint32_t) 0x00000008UL)
#define RCC_AHB1ENR_REG_OFFSET  ((uint32_t) 0x00000030UL)
#define GPIOA_MODER_REG_OFFSET  ((uint32_t) 0x00000000UL)
#define GPIOA_AFRH_REG_OFFSET   ((uint32_t) 0x00000024UL)

// Register access via volatile pointers
#define RCC_CR_REG           (*(volatile uint32_t* const) (RCC_BASE_ADDR + RCC_CR_REG_OFFSET))        // RCC_CR register
#define RCC_CFGR_REG         (*(volatile uint32_t* const) (RCC_BASE_ADDR + RCC_CFGR_REG_OFFSET))      // RCC_CFGR register
#define RCC_AHB1ENR_REG      (*(volatile uint32_t* const) (RCC_BASE_ADDR + RCC_AHB1ENR_REG_OFFSET))   // RCC_AHB1ENR register
#define GPIOA_MODER_REG      (*(volatile uint32_t* const) (GPIOA_BASE_ADDR + GPIOA_MODER_REG_OFFSET)) // GPIOA_MODER register
#define GPIOA_AFRH_REG       (*(volatile uint32_t* const) (GPIOA_BASE_ADDR + GPIOA_AFRH_REG_OFFSET))  // GPIOA_AFRH register

int main(void)
{
	// Enable the HSE clock using HSEON bit field in RCC_CR
	RCC_CR_REG |= (0x1U << 16);

	// Bypass the HSE oscillator with an external clock using HSEBYP bit field in RCC_CR
	RCC_CR_REG |= (0x1U << 18);

	// Switch the system clock from default clock HSI to HSE oscillator
	RCC_CFGR_REG &= ~(0x3U << 0);
	RCC_CFGR_REG |= (0x1U << 0);

	// Configure the RCC_CFGR MCO1 bit fields to select HSE as clock source
	RCC_CFGR_REG &= ~(0x3U << 21);
	RCC_CFGR_REG |= (0x2U << 21);

	// Configure MCO1 prescaler if necessary for measurement purposes
	RCC_CFGR_REG &= ~(0x7U << 24);
	RCC_CFGR_REG |= (0x6U << 24); // Division by 4

	// Enable the peripheral clock for the GPIOA peripheral in RCC_AHB1ENR
	RCC_AHB1ENR_REG |= (0x1U << 0);

	// Configure the mode of GPIOA Pin 8 as alternate function mode
	GPIOA_MODER_REG &= ~(0x3U << 16);
	GPIOA_MODER_REG |= (0x2U << 16);

	// Select the alternate function AF0 for Port A Pin 8
	GPIOA_AFRH_REG &= ~(0xFU << 0);

	// Loop forever
	while (1) {
		// Do nothing
		__asm volatile("nop");
	}
}

/* Note: Default HSE system clock is 8 MHz for STM32F411RE. */
