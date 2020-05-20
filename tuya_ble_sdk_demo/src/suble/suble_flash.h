/**
****************************************************************************
* @file      suble_flash.h
* @brief     suble_flash
* @author    suding
* @version   V1.0.0
* @date      2020-04
* @note
******************************************************************************
* @attention
*
* <h2><center>&copy; COPYRIGHT 2020 Tuya </center></h2>
*/


#ifndef __SUBLE_FLASH_H__
#define __SUBLE_FLASH_H__

#ifdef __cplusplus
extern "C"
{
#endif

/*********************************************************************
 * INCLUDE
 */
#include "suble_common.h"

/*********************************************************************
 * CONSTANT
 */
#define SUBLE_FLASH_START_ADDR        0x44000
#define SUBLE_FLASH_END_ADDR          0x64000

//ota
#define SUBLE_FLASH_OTA_START_ADDR    SUBLE_FLASH_START_ADDR
#define SUBLE_FLASH_OTA_END_ADDR      0x64000
//mac
#define SUBLE_FLASH_BT_MAC_ADDR       0x7F000

/*********************************************************************
 * STRUCT
 */

/*********************************************************************
 * EXTERNAL VARIABLE
 */

/*********************************************************************
 * EXTERNAL FUNCTION
 */
void suble_flash_init(void);
void suble_flash_read(uint32_t addr, uint8_t *buf, uint32_t size);
void suble_flash_write(uint32_t addr, uint8_t *buf, uint32_t size);
void suble_flash_erase(uint32_t addr, uint32_t num);


#ifdef __cplusplus
}
#endif

#endif //__SUBLE_FLASH_H__
