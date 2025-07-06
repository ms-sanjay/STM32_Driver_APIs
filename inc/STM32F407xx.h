#include <stdint.h>

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#define __vo volatile  // Shortcut for 'volatile' keyword for register definitions

/****************** NVIC Register Base Addresses ******************/
#define NVIC_ISER0          ((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1          ((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2          ((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3          ((__vo uint32_t*)0xE000E10C)

#define NVIC_ICER0          ((__vo uint32_t*)0xE000E180)
#define NVIC_ICER1          ((__vo uint32_t*)0xE000E184)
#define NVIC_ICER2          ((__vo uint32_t*)0xE000E188)
#define NVIC_ICER3          ((__vo uint32_t*)0xE000E18C)

#define NVIC_PR_BASE_ADDR   ((__vo uint32_t*)0xE000E400)
#define NO_PR_BITS_IMPLEMENTED  4

/****************** Memory Base Addresses ******************/
#define FLASH_BASEADDR       0x08000000U
#define SRAM1_BASEADDR       0x20000000U
#define SRAM2_BASEADDR       0x2001C000U
#define ROM_BASEADDR         0x1FFF0000U
#define SRAM                 SRAM1_BASEADDR

/****************** Bus Peripheral Base Addresses ******************/
#define PERIPH_BASEADDR      0x40000000U
#define APB1PERIPH_BASEADDR  PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR  0x40010000U
#define AHB1PERIPH_BASEADDR  0x40020000U
#define AHB2PERIPH_BASEADDR  0x50000000U

/****************** AHB1 Peripheral Base Addresses ******************/
#define GPIOA_BASEADDR       (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR       (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR       (AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR       (AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR       (AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR       (AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR       (AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR       (AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR       (AHB1PERIPH_BASEADDR + 0x2000)
#define RCC_BASEADDR         (AHB1PERIPH_BASEADDR + 0x3800)

/****************** APB1 Peripheral Base Addresses ******************/
#define I2C1_BASEADDR        (APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR        (APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR        (APB1PERIPH_BASEADDR + 0x5C00)

#define SPI2_BASEADDR        (APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR        (APB1PERIPH_BASEADDR + 0x3C00)

#define USART2_BASEADDR      (APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR      (APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR       (APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR       (APB1PERIPH_BASEADDR + 0x5000)

/****************** APB2 Peripheral Base Addresses ******************/
#define SPI1_BASEADDR        (APB2PERIPH_BASEADDR + 0x3000)
#define USART1_BASEADDR      (APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR      (APB2PERIPH_BASEADDR + 0x1400)

#define SYSCFG_BASEADDR      (APB2PERIPH_BASEADDR + 0x3800)
#define EXTI_BASEADDR        (APB2PERIPH_BASEADDR + 0x3C00)

/****************** Peripheral Register Definition Structures ******************/

typedef struct {
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];  // AFR[0] = low, AFR[1] = high
} GPIO_RegDef_t;

typedef struct {
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;
	uint32_t RESERVED0;
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	uint32_t RESERVED1[2];
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;
	uint32_t RESERVED2;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	uint32_t RESERVED3[2];
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t AHB3LPENR;
	uint32_t RESERVED4;
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	uint32_t RESERVED5[2];
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	uint32_t RESERVED6[2];
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
	__vo uint32_t PLLSAICFGR;
	__vo uint32_t DCKCFGR;
	__vo uint32_t CKGATENR;
	__vo uint32_t DCKCFGR2;
} RCC_RegDef_t;

typedef struct {
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;
} EXTI_RegDef_t;

typedef struct {
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
	uint32_t RESERVED1[2];
	__vo uint32_t CMPCR;
	uint32_t RESERVED2[2];
	__vo uint32_t CFGR;
} SYSCFG_RegDef_t;

typedef struct {
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t SR;
	__vo uint32_t DR;
	__vo uint32_t CRCPR;
	__vo uint32_t RXCRCR;
	__vo uint32_t TXCRCR;
	__vo uint32_t I2SCFGR;
	__vo uint32_t I2SPR;
} SPI_RegDef_t;

typedef struct {
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t OAR1;
	__vo uint32_t OAR2;
	__vo uint32_t DR;
	__vo uint32_t SR1;
	__vo uint32_t SR2;
	__vo uint32_t CCR;
	__vo uint32_t TRISE;
	__vo uint32_t FLTR;
} I2C_RegDef_t;

/****************** Peripheral Instances ******************/
#define GPIOA  ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB  ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC  ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD  ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE  ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF  ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG  ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH  ((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI  ((GPIO_RegDef_t*)GPIOI_BASEADDR)

#define RCC     ((RCC_RegDef_t*)RCC_BASEADDR)
#define EXTI    ((EXTI_RegDef_t*)EXTI_BASEADDR)
#define SYSCFG  ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

#define SPI1    ((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2    ((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3    ((SPI_RegDef_t*)SPI3_BASEADDR)

#define I2C1    ((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2    ((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3    ((I2C_RegDef_t*)I2C3_BASEADDR)

/****************** Clock Enable Macros ******************/
#define GPIOA_PCLK_EN()     (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()     (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()     (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()     (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()     (RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()     (RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()     (RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()     (RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN()     (RCC->AHB1ENR |= (1 << 8))

// (Other clock macros omitted here due to length - let me know if you'd like me to include them in the same style)

/****************** Utility and Status Macros ******************/
#define ENABLE           1
#define DISABLE          0
#define SET              ENABLE
#define RESET            DISABLE
#define GPIO_PIN_SET     SET
#define GPIO_PIN_RESET   RESET

/****************** Interrupt Numbers ******************/
#define IRQ_NO_EXTI0       6
#define IRQ_NO_EXTI1       7
#define IRQ_NO_EXTI2       8
#define IRQ_NO_EXTI3       9
#define IRQ_NO_EXTI4      10
#define IRQ_NO_EXTI9_5    23
#define IRQ_NO_EXTI15_10  40

/****************** Helper Macros ******************/
#define GPIO_BASEADDR_TO_CODE(x) ((x == GPIOA) ? 0 : \
                                  (x == GPIOB) ? 1 : \
                                  (x == GPIOC) ? 2 : \
                                  (x == GPIOD) ? 3 : \
                                  (x == GPIOE) ? 4 : \
                                  (x == GPIOF) ? 5 : \
                                  (x == GPIOG) ? 6 : \
                                  (x == GPIOH) ? 7 : \
                                  (x == GPIOI) ? 8 : 0)

/****************** Include Drivers ******************/
#include "STM32F407xx_gpio_driver.h"
#include "STM32F407xx_spi_driver.h"

#endif /* INC_STM32F407XX_H_ */
