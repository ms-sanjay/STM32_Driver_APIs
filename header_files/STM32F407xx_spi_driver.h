#ifndef INC_STM32F407XX_SPI_DRIVER_H_
#define INC_STM32F407XX_SPI_DRIVER_H_

#include "STM32F407xx.h"

/*
 * Configuration structure for SPI peripheral
 */
typedef struct
{
	uint8_t SPI_DeviceMode;     /*!< Master or Slave mode */
	uint8_t SPI_BusConfig;      /*!< Full-duplex, Half-duplex or Simplex RX only */
	uint8_t SPI_SclkSpeed;      /*!< Clock speed (prescaler) */
	uint8_t SPI_DFF;            /*!< Data frame format (8 or 16 bits) */
	uint8_t SPI_CPOL;           /*!< Clock polarity */
	uint8_t SPI_CPHA;           /*!< Clock phase */
	uint8_t SPI_SSM;            /*!< Software slave management */
} SPI_Config_t;

/*
 * Handle structure for SPI peripheral
 */
typedef struct
{
	SPI_RegDef_t *pSPIx;        /*!< Pointer to SPIx peripheral base address */
	SPI_Config_t SPIConfig;     /*!< SPI configuration settings */
} SPI_Handle_t;

/*
 * @SPI_DeviceMode
 */
#define SPI_DEVICE_MODE_MASTER     1
#define SPI_DEVICE_MODE_SLAVE      0

/*
 * @SPI_BusConfig
 */
#define SPI_BUS_CONFIG_FD              1  /*!< Full Duplex */
#define SPI_BUS_CONFIG_HD              2  /*!< Half Duplex */
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY  3  /*!< Simplex RX only */

/*
 * @SPI_SclkSpeed (Clock Prescalers)
 */
#define SPI_SCLK_SPEED_DIV2        0
#define SPI_SCLK_SPEED_DIV4        1
#define SPI_SCLK_SPEED_DIV8        2
#define SPI_SCLK_SPEED_DIV16       3
#define SPI_SCLK_SPEED_DIV32       4
#define SPI_SCLK_SPEED_DIV64       5
#define SPI_SCLK_SPEED_DIV128      6
#define SPI_SCLK_SPEED_DIV256      7

/*
 * @SPI_DFF (Data Frame Format)
 */
#define SPI_DFF_8BITS              0
#define SPI_DFF_16BITS             1

/*
 * @SPI_CPOL (Clock Polarity)
 */
#define SPI_CPOL_LOW               0
#define SPI_CPOL_HIGH              1

/*
 * @SPI_CPHA (Clock Phase)
 */
#define SPI_CPHA_LOW               0
#define SPI_CPHA_HIGH              1

/*
 * @SPI_SSM (Software Slave Management)
 */
#define SPI_SSM_DI                 0
#define SPI_SSM_EN                 1

/*************************** APIs ***************************/

/*
 * Clock Control
 */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

/*
 * Init / De-init
 */
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_Deit(SPI_RegDef_t *pSPIx);

/*
 * Data Transmission and Reception
 */
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len);
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len);

/*
 * IRQ Configuration and ISR Handling
 */
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pHandle);

#endif /* INC_STM32F407XX_SPI_DRIVER_H_ */
