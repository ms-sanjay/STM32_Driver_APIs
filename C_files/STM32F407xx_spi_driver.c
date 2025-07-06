
#include "STM32F407xx_spi_driver.h"



void SPI_PeriClockControl(SPI_RegDef_t* pSPIx,uint8_t EnorDi)
{
	if(EnorDi ==ENABLE)
	{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_EN();
		}
		if(pSPIx == SPI2)
		{
			SPI2_PCLK_EN();
		}
		if(pSPIx == SPI3)
		{
			SPI3_PCLK_EN();
		}
	}
	else{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_DI();
		}
		if(pSPIx == SPI2)
		{
			SPI2_PCLK_DI();
		}
		if(pSPIx == SPI3)
		{
			SPI3_PCLK_DI();
		}
	}
}

void SPI_Init(SPI_Handle_t* pSPIHandle)
{

	uint32_t temp=0;

	SPI_PeriClockControl(pSPIHandle->pSPIx,ENABLE);

	pSPIHandle->pSPIx->CR1 |= (1<<6);

	temp |=(pSPIHandle->SPIConfig.SPI_DeviceMode << 2);
	if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD)
	{
		temp &= ~(1<<15);
	}
	else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD)
	{
		temp |= (1<<15);
	}
	else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RXONLY)
	{
		temp &= ~(1<<15);
		temp |= (1<<10);
	}

	temp |= pSPIHandle->SPIConfig.SPI_SclkSpeed <<3;
	temp |= pSPIHandle->SPIConfig.SPI_DFF <<11;
	temp |= pSPIHandle->SPIConfig.SPI_CPOL <<1;
	temp |= pSPIHandle->SPIConfig.SPI_CPHA <<0;

	pSPIHandle->pSPIx->CR1=temp;

}
void SPI_Deit(SPI_RegDef_t* pSPIx)
{
	if(pSPIx == SPI1)
	{
		SPI1_REG_RESET();
	}
	else if(pSPIx == SPI2)
	{
		SPI2_REG_RESET();
	}

	else if(pSPIx == SPI3)
	{
		SPI3_REG_RESET();
	}

}

void SPI_SendData(SPI_RegDef_t *pSPIx,uint8_t *pTxBuffer, uint32_t Len)
{
	while(Len>0)
	{
		while(!(pSPIx->SR & (1 << 1)));
		if( pSPIx->CR1 & (1<<11))
		{
			pSPIx->DR = *((uint16_t *)pTxBuffer);
			Len--;
			Len--;
			(uint16_t *)pTxBuffer++;
		}
		else{
			pSPIx->DR= *pTxBuffer;
			Len--;
			pTxBuffer++;
		}

	}
}
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len)
{
	while(Len>0)
	{
		while (!(pSPIx->SR & (1 << 0)));

		if (pSPIx->CR1 & (1 << 11))
		{
			*((uint16_t *)pRxBuffer) = (uint16_t)pSPIx->DR;
			pRxBuffer += 2;
			Len -= 2;
		}
		else  
		{
			*pRxBuffer = (uint8_t)pSPIx->DR;
			pRxBuffer++;
			Len--;
		}
	}

}

void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{

}
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{

}
void SPI_IRQHandling(SPI_Handle_t *pHandle)
{

}
