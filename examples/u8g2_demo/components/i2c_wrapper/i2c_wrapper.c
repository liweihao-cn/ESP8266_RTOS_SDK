/**
 * @file i2c_wrapper.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-10-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "esp_err.h"

#include "driver/i2c.h"

#define I2C_USER_MASTER_NUMBER I2C_NUM_0
#define I2C_USER_MASTER_SCL_IO 4
#define I2C_USER_MASTER_SDA_IO 5

esp_err_t i2c_wrapper_init(void)
{
	i2c_config_t conf;
	conf.mode = I2C_MODE_MASTER;
	conf.sda_io_num = I2C_USER_MASTER_SDA_IO;
	conf.sda_pullup_en = 1;
	conf.scl_io_num = I2C_USER_MASTER_SCL_IO;
	conf.scl_pullup_en = 1;
	conf.clk_stretch_tick = 300; // 300 ticks, Clock stretch is about 210us, you can make changes according to the actual situation.
	ESP_ERROR_CHECK(i2c_driver_install(I2C_USER_MASTER_NUMBER, conf.mode));
	ESP_ERROR_CHECK(i2c_param_config(I2C_USER_MASTER_NUMBER, &conf));
	return ESP_OK;
}

esp_err_t i2c_wrapper_write(uint8_t addr, uint8_t *data, size_t length)
{
	int ret;
	i2c_cmd_handle_t cmd = i2c_cmd_link_create();
	i2c_master_start(cmd);
	i2c_master_write_byte(cmd, addr, 1);
	i2c_master_write(cmd, (uint8_t *)data, length, 1);
	i2c_master_stop(cmd);
	ret = i2c_master_cmd_begin(I2C_USER_MASTER_NUMBER, cmd, 1000 / portTICK_RATE_MS);
	i2c_cmd_link_delete(cmd);

	return ret;
}
