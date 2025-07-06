#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include "STM32F407xx.h"  // Include device-specific header

/******************** GPIO Pin Configuration Structure ********************/
typedef struct {
	uint8_t GPIO_PinNumber;        // Pin number (0 to 15)
	uint8_t GPIO_PinMode;          // Mode: Input, Output, Alternate Function, Analog, Interrupt
	uint8_t GPIO_PinSpeed;         // Speed: Low, Medium, Fast, High
	uint8_t GPIO_PinPuPdControl;   // Pull-up/Pull-down configuration
	uint8_t GPIO_PinOPType;        // Output type: Push-pull/Open-drain
	uint8_t GPIO_PinAltFunMode;    // Alternate function mode (if used)
} GPIO_PinConfig_t;

/******************** GPIO Handle Structure ********************/
typedef struct {
	GPIO_RegDef_t *pGPIOx;             // Pointer to GPIO port base address
	GPIO_PinConfig_t GPIO_PinConfig;   // GPIO pin configuration settings
} GPIO_Handle_t;

/******************** GPIO Driver APIs ********************/

// Enable or disable peripheral clock for the given GPIO port
void GPIO_PeriClockControl(GPIO_RegDef_t* pGPIOx, uint8_t EnorDi);

// Initialize the GPIO pin with the given handle configuration
void GPIO_Init(GPIO_Handle_t* pGPIOHandle);

// De-initialize/reset all registers of the given GPIO port
void GPIO_DeInit(GPIO_RegDef_t* pGPIOx);

// Read the state of a specific input pin (0 or 1)
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

// Read the 16-bit input port value
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);

// Write a value (0 or 1) to a specific output pin
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);

// Write a 16-bit value directly to the output port
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);

// Toggle the current state of the output pin
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

// Configure NVIC for GPIO interrupt
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);

// Set priority for a given IRQ number
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);

// Handle the interrupt (clear the EXTI line)
void GPIO_IRQHandling(uint8_t PinNumber);


/******************** GPIO Pin Numbers ********************/
#define GPIO_PIN_NO_0  				0
#define GPIO_PIN_NO_1  				1
#define GPIO_PIN_NO_2  				2
#define GPIO_PIN_NO_3  				3
#define GPIO_PIN_NO_4  				4
#define GPIO_PIN_NO_5  				5
#define GPIO_PIN_NO_6  				6
#define GPIO_PIN_NO_7  				7
#define GPIO_PIN_NO_8  				8
#define GPIO_PIN_NO_9  				9
#define GPIO_PIN_NO_10  			10
#define GPIO_PIN_NO_11 				11
#define GPIO_PIN_NO_12  			12
#define GPIO_PIN_NO_13 				13
#define GPIO_PIN_NO_14 				14
#define GPIO_PIN_NO_15 				15

/******************** GPIO Modes ********************/
#define GPIO_MODE_IN 		0   // Input mode
#define GPIO_MODE_OUT 		1   // Output mode
#define GPIO_MODE_ALTFN 	2   // Alternate function mode
#define GPIO_MODE_ANALOG 	3   // Analog mode
#define GPIO_MODE_IT_FT     4   // Interrupt mode - falling edge trigger
#define GPIO_MODE_IT_RT     5   // Interrupt mode - rising edge trigger
#define GPIO_MODE_IT_RFT    6   // Interrupt mode - both edge trigger

/******************** Output Types ********************/
#define GPIO_OP_TYPE_PP   0   // Push-pull
#define GPIO_OP_TYPE_OD   1   // Open-drain

/******************** GPIO Output Speed ********************/
#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_FAST			2
#define GPIO_SPEED_HIGH			3   // Fixed typo from GPOI_SPEED_HIGH

/******************** Pull-up / Pull-down Configuration ********************/
#define GPIO_NO_PUPD   		0   // No pull-up, pull-down
#define GPIO_PIN_PU			1   // Pull-up
#define GPIO_PIN_PD			2   // Pull-down

#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
