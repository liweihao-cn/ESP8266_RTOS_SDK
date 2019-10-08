/**
 * @file i2c_wrapper.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-10-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef __I2C_WRAPPER_H__
#define __I2C_WRAPPER_H__

#include "esp_err.h"

esp_err_t i2c_wrapper_init(void);
esp_err_t i2c_wrapper_write(uint8_t addr, uint8_t *data, size_t length);

#endif
