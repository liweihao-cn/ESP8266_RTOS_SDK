/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "i2c_wrapper.h"
#include "u8g2.h"
#include "u8g2_port.h"

u8g2_t u8g2;

void app_main()
{
	printf("Hello world!\n");

	esp_err_t ret;
	ret = i2c_wrapper_init();
	printf("i2c_wrapper_init %d\n", ret);

	u8g2_Setup_ssd1306_i2c_128x64_noname_f(&u8g2, U8G2_R0, u8x8_byte_esp_hw_i2c, u8x8_esp_gpio_and_delay); // init u8g2 structure
	u8g2_InitDisplay(&u8g2);																				// send init sequence to the display, display is in sleep mode after this,
	u8g2_SetPowerSave(&u8g2, 0);																			// wake up display
	u8g2_SetFont(&u8g2, u8g2_font_unifont_t_symbols);
	u8g2_DrawStr(&u8g2, 1, 20, "U8g2 on esp8266");
	u8g2_DrawGlyph(&u8g2, 100, 60, 0x2603);
	u8g2_SendBuffer(&u8g2);

	while (1);
}
