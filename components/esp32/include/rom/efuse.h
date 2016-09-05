// Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _ROM_EFUSE_H_
#define _ROM_EFUSE_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup efuse_APIs efuse APIs
  * @brief     ESP32 efuse read/write APIs
  * @attention
  *
  */

/** @addtogroup efuse_APIs
  * @{
  */

/**
  * @brief  Do a efuse read operation, to update the efuse value to efuse read registers.
  *
  * @param  null
  *
  * @return null
  */
void ets_efuse_read_op(void);

/**
  * @brief  Do a efuse write operation, to update efuse write registers to efuse, then you need call ets_efuse_read_op again.
  *
  * @param  null
  *
  * @return null
  */
void ets_efuse_program_op(void);

/**
  * @brief  Read 8M Analog Clock value(8 bit) in efuse, the analog clock will not change with temperature.
  *         It can be used to test the external xtal frequency, do not touch this efuse field.
  *
  * @param  null
  *
  * @return u32: 1 for 100KHZ.
  */
uint32_t ets_efuse_get_8M_clock(void);

/**
  * @brief  Read spi pad configuration, show gpio number of flash pad, includes 5 pads.
  *
  * @param  null
  *
  * @return uint32_t: 0, invalid, flash pad decided by strapping
  *      else, bit[5:0] spiclk, bit[11:6] spiq, bit[17:12] spid, bit[23:18] spics0, bit[29:24] spihd
  */
uint32_t ets_efuse_get_spiconfig(void);

/**
  * @brief  A crc8 algorithm used in efuse check.
  *
  * @param  unsigned char const *p : Pointer to original data.
  *
  * @param  unsigned int len : Data length in byte.
  *
  * @return unsigned char: Crc value.
  */
unsigned char esp_crc8(unsigned char const *p, unsigned int len);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* _ROM_EFUSE_H_ */
