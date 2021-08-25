/*
 * MN15439A.h
 * striped down version for VFD32Hack Daughter board.
 *  Created on: Aug 23, 2021
 *      Author: TinLethax
 */

#ifndef MN15439A_H_
#define MN15439A_H_

#include "stm32f0xx_hal.h"
#include <stdbool.h>

#define ABCARRAY_SIZE 39

typedef struct {
	SPI_HandleTypeDef		*Bus;
	GPIO_TypeDef			*vfdGPIO;
	uint16_t 				BLANK_pin;
	uint16_t				LAT_pin;

}MN15439A;

// Display full 154x39 pixels frame buffer
// Buffer size of 160x39 (last horizontal pixel byte only contain 2 pixel on bit 7 and 6)
static uint8_t *FB0;

void VFDsetup(MN15439A *VFDDisp, SPI_HandleTypeDef *Bus, GPIO_TypeDef *vfdGPIO, uint16_t BLANK_pin, uint16_t LAT_pin);
void VFDLoadBMP(MN15439A *VFDDisp, uint8_t Grid);

#endif /* MN15439A_H_ */
