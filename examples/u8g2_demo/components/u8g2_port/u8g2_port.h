/**
 * @file u8g2_port.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-10-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef __U8G2_PORT_H__
#define __U8G2_PORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "u8g2.h"

uint8_t u8x8_byte_esp_hw_i2c(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);
uint8_t u8x8_esp_gpio_and_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);

#endif
