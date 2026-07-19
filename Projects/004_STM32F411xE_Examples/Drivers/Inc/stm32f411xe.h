/*
 * stm32f411xe.h
 *
 *  Created on: Jun 15, 2026
 */

#ifndef INC_STM32F411XE_H_
#define INC_STM32F411XE_H_

/* Includes */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Interrupt Set-Enable Registers */
#define NVIC_ISER0      (*(volatile uint32_t* const) ((uint32_t) 0xE000E100UL))
#define NVIC_ISER1      (*(volatile uint32_t* const) ((uint32_t) 0xE000E104UL))
#define NVIC_ISER2      (*(volatile uint32_t* const) ((uint32_t) 0xE000E108UL))

/* Interrupt Clear-Enable Registers */
#define NVIC_ICER0      (*(volatile uint32_t* const) ((uint32_t) 0xE000E180UL))
#define NVIC_ICER1      (*(volatile uint32_t* const) ((uint32_t) 0xE000E184UL))
#define NVIC_ICER2      (*(volatile uint32_t* const) ((uint32_t) 0xE000E188UL))

/* Interrupt Priority Registers Base Address */
#define NVIC_IPR_BASE_ADDR  ((volatile uint32_t* const) ((uint32_t) 0xE000E400UL))

/* Memory Base Addresses */
#define FLASH_BASE_ADDR        ((uint32_t) 0x08000000UL)
#define SYS_MEMORY_BASE_ADDR   ((uint32_t) 0x1FFF0000UL)
#define OTP_AREA_BASE_ADDR     ((uint32_t) 0x1FFF7800UL)
#define SRAM1_BASE_ADDR        ((uint32_t) 0x20000000UL)
#define SRAM_BASE_ADDR         SRAM1_BASE_ADDR

/* Bus Peripheral Base Addresses */
#define PERIPH_BASE_ADDR       ((uint32_t) 0x40000000UL)
#define APB1_PERIPH_BASE_ADDR  PERIPH_BASE_ADDR
#define APB2_PERIPH_BASE_ADDR  ((uint32_t) 0x40010000UL)
#define AHB1_PERIPH_BASE_ADDR  ((uint32_t) 0x40020000UL)
#define AHB2_PERIPH_BASE_ADDR  ((uint32_t) 0x50000000UL)

/* Peripheral Base Addresses */
#define RCC_BASE_ADDR          ((uint32_t) 0x40023800UL)
#define SYSCFG_BASE_ADDR       ((uint32_t) 0x40013800UL)
#define EXTI_BASE_ADDR         ((uint32_t) 0x40013C00UL)

#define GPIOA_BASE_ADDR        ((uint32_t) 0x40020000UL)
#define GPIOB_BASE_ADDR        ((uint32_t) 0x40020400UL)
#define GPIOC_BASE_ADDR        ((uint32_t) 0x40020800UL)
#define GPIOD_BASE_ADDR        ((uint32_t) 0x40020C00UL)
#define GPIOE_BASE_ADDR        ((uint32_t) 0x40021000UL)
#define GPIOH_BASE_ADDR        ((uint32_t) 0x40021C00UL)

#define SPI1_BASE_ADDR         ((uint32_t) 0x40013000UL)
#define SPI2_BASE_ADDR         ((uint32_t) 0x40003800UL)
#define SPI3_BASE_ADDR         ((uint32_t) 0x40003C00UL)
#define SPI4_BASE_ADDR         ((uint32_t) 0x40013400UL)
#define SPI5_BASE_ADDR         ((uint32_t) 0x40015000UL)

#define I2C1_BASE_ADDR         ((uint32_t) 0x40005400UL)
#define I2C2_BASE_ADDR         ((uint32_t) 0x40005800UL)
#define I2C3_BASE_ADDR         ((uint32_t) 0x40005C00UL)

#define USART1_BASE_ADDR       ((uint32_t) 0x40011000UL)
#define USART2_BASE_ADDR       ((uint32_t) 0x40004400UL)
#define USART6_BASE_ADDR       ((uint32_t) 0x40011400UL)

/* General Purpose I/O (GPIO) Register Definition Structure */
typedef struct {
	volatile uint32_t MODER;      /* GPIO port mode register,                             Address offset: 0x00 */
	volatile uint32_t OTYPER;     /* GPIO port output type register,                      Address offset: 0x04 */
	volatile uint32_t OSPEEDR;    /* GPIO port output speed register,                     Address offset: 0x08 */
	volatile uint32_t PUPDR;      /* GPIO port pull-up/pull-down register,                Address offset: 0x0C */
	volatile const uint32_t IDR;  /* GPIO port input data register (read-only),           Address offset: 0x10 */
	volatile uint32_t ODR;        /* GPIO port output data register,                      Address offset: 0x14 */
	volatile uint32_t BSRR;       /* GPIO port bit set/reset register,                    Address offset: 0x18 */
	volatile uint32_t LCKR;       /* GPIO port configuration lock register,               Address offset: 0x1C */
	volatile uint32_t AFR[2];     /* GPIO alternate function registers [0]=Low, [1]=High, Address offset: 0x20-0x24 */
} GPIO_RegDef_t;

/* Reset and Clock Control (RCC) Register Definition Structure */
typedef struct {
	volatile uint32_t CR;                /* RCC clock control register,                  Address offset: 0x00 */
	volatile uint32_t PLLCFGR;           /* RCC PLL configuration register,              Address offset: 0x04 */
	volatile uint32_t CFGR;              /* RCC clock configuration register,            Address offset: 0x08 */
	volatile uint32_t CIR;               /* RCC clock interrupt register,                Address offset: 0x0C */
	volatile uint32_t AHB1RSTR;          /* RCC AHB1 peripheral reset register,          Address offset: 0x10 */
	volatile uint32_t AHB2RSTR;          /* RCC AHB2 peripheral reset register,          Address offset: 0x14 */
	volatile const uint32_t reserved1[2];/* Reserved,                                    Address offset: 0x18-0x1C */
	volatile uint32_t APB1RSTR;          /* RCC APB1 peripheral reset register,          Address offset: 0x20 */
	volatile uint32_t APB2RSTR;          /* RCC APB2 peripheral reset register,          Address offset: 0x24 */
	volatile const uint32_t reserved2[2];/* Reserved,                                    Address offset: 0x28-0x2C */
	volatile uint32_t AHB1ENR;           /* RCC AHB1 peripheral clock enable register,   Address offset: 0x30 */
	volatile uint32_t AHB2ENR;           /* RCC AHB2 peripheral clock enable register,   Address offset: 0x34 */
	volatile const uint32_t reserved3[2];/* Reserved,                                    Address offset: 0x38-0x3C */
	volatile uint32_t APB1ENR;           /* RCC APB1 peripheral clock enable register,   Address offset: 0x40 */
	volatile uint32_t APB2ENR;           /* RCC APB2 peripheral clock enable register,   Address offset: 0x44 */
	volatile const uint32_t reserved4[2];/* Reserved,                                    Address offset: 0x48-0x4C */
	volatile uint32_t AHB1LPENR;         /* RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
	volatile uint32_t AHB2LPENR;         /* RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
	volatile const uint32_t reserved5[2];/* Reserved,                                    Address offset: 0x58-0x5C */
	volatile uint32_t APB1LPENR;         /* RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
	volatile uint32_t APB2LPENR;         /* RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
	volatile const uint32_t reserved6[2];/* Reserved,                                    Address offset: 0x68-0x6C */
	volatile uint32_t BDCR;              /* RCC backup domain control register,          Address offset: 0x70 */
	volatile uint32_t CSR;               /* RCC clock control & status register,         Address offset: 0x74 */
	volatile const uint32_t reserved7[2];/* Reserved,                                    Address offset: 0x78-0x7C */
	volatile uint32_t SSCGR;             /* RCC spread spectrum clock generation register,               Address offset: 0x80 */
	volatile uint32_t PLLI2SCFGR;        /* RCC PLLI2S configuration register,           Address offset: 0x84 */
	volatile const uint32_t reserved8;   /* Reserved,                                    Address offset: 0x88 */
	volatile uint32_t DCKCFGR;           /* RCC dedicated clocks configuration register, Address offset: 0x8C */
} RCC_RegDef_t;

/* External Interrupt/Event Controller (EXTI) Register Definition Structure */
typedef struct {
	volatile uint32_t IMR;   /* EXTI interrupt mask register,              Address offset: 0x00 */
	volatile uint32_t EMR;   /* EXTI event mask register,                  Address offset: 0x04 */
	volatile uint32_t RTSR;  /* EXTI rising trigger selection register,    Address offset: 0x08 */
	volatile uint32_t FTSR;  /* EXTI falling trigger selection register,   Address offset: 0x0C */
	volatile uint32_t SWIER; /* EXTI software interrupt event register,    Address offset: 0x10 */
	volatile uint32_t PR;    /* EXTI pending register,                     Address offset: 0x14 */
} EXTI_RegDef_t;

/* System Configuration Controller (SYSCFG) Register Definition Structure */
typedef struct {
	volatile uint32_t MEMRMP;     /* SYSCFG memory remap register,                          Address offset: 0x00 */
	volatile uint32_t PMC;        /* SYSCFG peripheral mode configuration register,         Address offset: 0x04 */
	volatile uint32_t EXTICR[4];  /* SYSCFG external interrupt configuration registers 1-4, Address offset: 0x08-0x14 */
	volatile const uint32_t reserved1; /* Reserved,                                         Address offset: 0x18-0x1C */
	volatile uint32_t CMPCR;      /* SYSCFG compensation cell control register,             Address offset: 0x20 */
} SYSCFG_RegDef_t;

/* Peripheral Register Definition Structures Cast to Base Addresses */
#define GPIOA   ((GPIO_RegDef_t* const)   GPIOA_BASE_ADDR)
#define GPIOB   ((GPIO_RegDef_t* const)   GPIOB_BASE_ADDR)
#define GPIOC   ((GPIO_RegDef_t* const)   GPIOC_BASE_ADDR)
#define GPIOD   ((GPIO_RegDef_t* const)   GPIOD_BASE_ADDR)
#define GPIOE   ((GPIO_RegDef_t* const)   GPIOE_BASE_ADDR)
#define GPIOH   ((GPIO_RegDef_t* const)   GPIOH_BASE_ADDR)
#define RCC     ((RCC_RegDef_t* const)    RCC_BASE_ADDR)
#define EXTI    ((EXTI_RegDef_t* const)   EXTI_BASE_ADDR)
#define SYSCFG  ((SYSCFG_RegDef_t* const) SYSCFG_BASE_ADDR)

/* Clock Enable and Disable Macros for Peripherals */
#define SPI1_PERIPH_CLK_EN()   (RCC->APB2ENR |=  (0x1UL << 12))
#define SPI1_PERIPH_CLK_DIS()  (RCC->APB2ENR &= ~(0x1UL << 12))
#define SPI2_PERIPH_CLK_EN()   (RCC->APB1ENR |=  (0x1UL << 14))
#define SPI2_PERIPH_CLK_DIS()  (RCC->APB1ENR &= ~(0x1UL << 14))
#define SPI3_PERIPH_CLK_EN()   (RCC->APB1ENR |=  (0x1UL << 15))
#define SPI3_PERIPH_CLK_DIS()  (RCC->APB1ENR &= ~(0x1UL << 15))
#define SPI4_PERIPH_CLK_EN()   (RCC->APB2ENR |=  (0x1UL << 13))
#define SPI4_PERIPH_CLK_DIS()  (RCC->APB2ENR &= ~(0x1UL << 13))
#define SPI5_PERIPH_CLK_EN()   (RCC->APB2ENR |=  (0x1UL << 20))
#define SPI5_PERIPH_CLK_DIS()  (RCC->APB2ENR &= ~(0x1UL << 20))

#define I2C1_PERIPH_CLK_EN()   (RCC->APB1ENR |=  (0x1UL << 21))
#define I2C1_PERIPH_CLK_DIS()  (RCC->APB1ENR &= ~(0x1UL << 21))
#define I2C2_PERIPH_CLK_EN()   (RCC->APB1ENR |=  (0x1UL << 22))
#define I2C2_PERIPH_CLK_DIS()  (RCC->APB1ENR &= ~(0x1UL << 22))
#define I2C3_PERIPH_CLK_EN()   (RCC->APB1ENR |=  (0x1UL << 23))
#define I2C3_PERIPH_CLK_DIS()  (RCC->APB1ENR &= ~(0x1UL << 23))

#define USART1_PERIPH_CLK_EN()  (RCC->APB2ENR |=  (0x1UL << 4))
#define USART1_PERIPH_CLK_DIS() (RCC->APB2ENR &= ~(0x1UL << 4))
#define USART2_PERIPH_CLK_EN()  (RCC->APB1ENR |=  (0x1UL << 17))
#define USART2_PERIPH_CLK_DIS() (RCC->APB1ENR &= ~(0x1UL << 17))
#define USART6_PERIPH_CLK_EN()  (RCC->APB2ENR |=  (0x1UL << 5))
#define USART6_PERIPH_CLK_DIS() (RCC->APB2ENR &= ~(0x1UL << 5))

/* Generic Status Definitions for Peripheral Enable/Disable/Set/Reset */
#define ENABLE		((uint8_t) 0x1UL)
#define DISABLE		((uint8_t) 0x0UL)
#define SET         ENABLE
#define RESET       DISABLE

/* Interrupt Request Numbers for Peripherals */
#define IRQ_NUMBER_WWDG               ((uint8_t) 0UL)   /* Window watchDog interrupt */
#define IRQ_NUMBER_PVD                ((uint8_t) 1UL)   /* PVD through EXTI line detection interrupt */
#define IRQ_NUMBER_EXTI16             ((uint8_t) 1UL)   /* EXTI line 16 interrupt */
#define IRQ_NUMBER_TAMP_STAMP         ((uint8_t) 2UL)   /* Tamper and timeStamp interrupts through the EXTI line */
#define IRQ_NUMBER_EXTI21             ((uint8_t) 2UL)   /* EXTI line 21 interrupt */
#define IRQ_NUMBER_RTC_WKUP           ((uint8_t) 3UL)   /* RTC wake-up interrupt through the EXTI line */
#define IRQ_NUMBER_EXTI22             ((uint8_t) 3UL)   /* EXTI line 22 interrupt */
#define IRQ_NUMBER_FLASH              ((uint8_t) 4UL)   /* FLASH global interrupt */
#define IRQ_NUMBER_RCC                ((uint8_t) 5UL)   /* RCC global interrupt */
#define IRQ_NUMBER_EXTI0              ((uint8_t) 6UL)   /* EXTI line 0 interrupt */
#define IRQ_NUMBER_EXTI1              ((uint8_t) 7UL)   /* EXTI line 1 interrupt */
#define IRQ_NUMBER_EXTI2              ((uint8_t) 8UL)   /* EXTI line 2 interrupt */
#define IRQ_NUMBER_EXTI3              ((uint8_t) 9UL)   /* EXTI line 3 interrupt */
#define IRQ_NUMBER_EXTI4              ((uint8_t) 10UL)  /* EXTI line 4 interrupt */
#define IRQ_NUMBER_DMA1_Stream0       ((uint8_t) 11UL)  /* DMA1 stream 0 global interrupt */
#define IRQ_NUMBER_DMA1_Stream1       ((uint8_t) 12UL)  /* DMA1 stream 1 global interrupt */
#define IRQ_NUMBER_DMA1_Stream2       ((uint8_t) 13UL)  /* DMA1 stream 2 global interrupt */
#define IRQ_NUMBER_DMA1_Stream3       ((uint8_t) 14UL)  /* DMA1 stream 3 global interrupt */
#define IRQ_NUMBER_DMA1_Stream4       ((uint8_t) 15UL)  /* DMA1 stream 4 global interrupt */
#define IRQ_NUMBER_DMA1_Stream5       ((uint8_t) 16UL)  /* DMA1 stream 5 global interrupt */
#define IRQ_NUMBER_DMA1_Stream6       ((uint8_t) 17UL)  /* DMA1 stream 6 global interrupt */
#define IRQ_NUMBER_ADC                ((uint8_t) 18UL)  /* ADC1 global interrupts */
#define IRQ_NUMBER_EXTI9_5            ((uint8_t) 23UL)  /* External line[9:5] interrupts */
#define IRQ_NUMBER_TIM1_BRK_TIM9      ((uint8_t) 24UL)  /* TIM1 break interrupt and TIM9 global interrupt */
#define IRQ_NUMBER_TIM1_UP_TIM10      ((uint8_t) 25UL)  /* TIM1 update interrupt and TIM10 global interrupt */
#define IRQ_NUMBER_TIM1_TRG_COM_TIM11 ((uint8_t) 26UL)  /* TIM1 trigger and commutation interrupt and TIM11 global interrupt */
#define IRQ_NUMBER_TIM1_CC            ((uint8_t) 27UL)  /* TIM1 capture compare interrupt */
#define IRQ_NUMBER_TIM2               ((uint8_t) 28UL)  /* TIM2 global interrupt */
#define IRQ_NUMBER_TIM3               ((uint8_t) 29UL)  /* TIM3 global interrupt */
#define IRQ_NUMBER_TIM4               ((uint8_t) 30UL)  /* TIM4 global interrupt */
#define IRQ_NUMBER_I2C1_EV            ((uint8_t) 31UL)  /* I2C1 event interrupt */
#define IRQ_NUMBER_I2C1_ER            ((uint8_t) 32UL)  /* I2C1 error interrupt */
#define IRQ_NUMBER_I2C2_EV            ((uint8_t) 33UL)  /* I2C2 event interrupt */
#define IRQ_NUMBER_I2C2_ER            ((uint8_t) 34UL)  /* I2C2 error interrupt */
#define IRQ_NUMBER_SPI1               ((uint8_t) 35UL)  /* SPI1 global interrupt */
#define IRQ_NUMBER_SPI2               ((uint8_t) 36UL)  /* SPI2 global interrupt */
#define IRQ_NUMBER_USART1             ((uint8_t) 37UL)  /* USART1 global interrupt */
#define IRQ_NUMBER_USART2             ((uint8_t) 38UL)  /* USART2 global interrupt */
#define IRQ_NUMBER_EXTI15_10          ((uint8_t) 40UL)  /* External line[15:10] interrupts */
#define IRQ_NUMBER_RTC_Alarm          ((uint8_t) 41UL)  /* RTC alarm (A and B) through EXTI line interrupt */
#define IRQ_NUMBER_EXTI17             ((uint8_t) 41UL)  /* EXTI line 17 interrupt */
#define IRQ_NUMBER_OTG_FS_WKUP        ((uint8_t) 42UL)  /* USB OTG FS wake-up through EXTI line interrupt */
#define IRQ_NUMBER_EXTI18             ((uint8_t) 41UL)  /* EXTI line 18 interrupt */
#define IRQ_NUMBER_DMA1_Stream7       ((uint8_t) 47UL)  /* DMA1 stream 7 global interrupt */
#define IRQ_NUMBER_SDIO               ((uint8_t) 49UL)  /* SDIO global interrupt */
#define IRQ_NUMBER_TIM5               ((uint8_t) 50UL)  /* TIM5 global interrupt */
#define IRQ_NUMBER_SPI3               ((uint8_t) 51UL)  /* SPI3 global interrupt */
#define IRQ_NUMBER_DMA2_Stream0       ((uint8_t) 56UL)  /* DMA2 stream 0 global interrupt */
#define IRQ_NUMBER_DMA2_Stream1       ((uint8_t) 57UL)  /* DMA2 stream 1 global interrupt */
#define IRQ_NUMBER_DMA2_Stream2       ((uint8_t) 58UL)  /* DMA2 stream 2 global interrupt */
#define IRQ_NUMBER_DMA2_Stream3       ((uint8_t) 59UL)  /* DMA2 stream 3 global interrupt */
#define IRQ_NUMBER_DMA2_Stream4       ((uint8_t) 60UL)  /* DMA2 stream 4 global interrupt */
#define IRQ_NUMBER_OTG_FS             ((uint8_t) 67UL)  /* USB OTG FS global interrupt */
#define IRQ_NUMBER_DMA2_Stream5       ((uint8_t) 68UL)  /* DMA2 stream 5 global interrupt */
#define IRQ_NUMBER_DMA2_Stream6       ((uint8_t) 69UL)  /* DMA2 stream 6 global interrupt */
#define IRQ_NUMBER_DMA2_Stream7       ((uint8_t) 70UL)  /* DMA2 stream 7 global interrupt */
#define IRQ_NUMBER_USART6             ((uint8_t) 71UL)  /* USART6 global interrupt */
#define IRQ_NUMBER_I2C3_EV            ((uint8_t) 72UL)  /* I2C3 event interrupt */
#define IRQ_NUMBER_I2C3_ER            ((uint8_t) 73UL)  /* I2C3 error interrupt */
#define IRQ_NUMBER_FPU                ((uint8_t) 81UL)  /* FPU global interrupt */
#define IRQ_NUMBER_SPI4               ((uint8_t) 84UL)  /* SPI4 global interrupt */
#define IRQ_NUMBER_SPI5               ((uint8_t) 85UL)  /* SPI5 global interrupt */

/* Programmable Interrupt Priority Levels */
#define IRQ_PRIORITY_0       ((uint8_t) 0UL)
#define IRQ_PRIORITY_1       ((uint8_t) 1UL)
#define IRQ_PRIORITY_2       ((uint8_t) 2UL)
#define IRQ_PRIORITY_3       ((uint8_t) 3UL)
#define IRQ_PRIORITY_4       ((uint8_t) 4UL)
#define IRQ_PRIORITY_5       ((uint8_t) 5UL)
#define IRQ_PRIORITY_6       ((uint8_t) 6UL)
#define IRQ_PRIORITY_7       ((uint8_t) 7UL)
#define IRQ_PRIORITY_8       ((uint8_t) 8UL)
#define IRQ_PRIORITY_9       ((uint8_t) 9UL)
#define IRQ_PRIORITY_10      ((uint8_t) 10UL)
#define IRQ_PRIORITY_11      ((uint8_t) 11UL)
#define IRQ_PRIORITY_12      ((uint8_t) 12UL)
#define IRQ_PRIORITY_13      ((uint8_t) 13UL)
#define IRQ_PRIORITY_14      ((uint8_t) 14UL)
#define IRQ_PRIORITY_15      ((uint8_t) 15UL)

#ifdef __cplusplus
}
#endif

#endif /* INC_STM32F411XE_H_ */
