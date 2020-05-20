/**
****************************************************************************
* @file      suble_common.h
* @brief     suble_common
* @author    suding
* @version   V1.0.0
* @date      2020-04
* @note
******************************************************************************
* @attention
*
* <h2><center>&copy; COPYRIGHT 2020 Tuya </center></h2>
*/


#ifndef __SUBLE_COMMON_H__
#define __SUBLE_COMMON_H__

#ifdef __cplusplus
extern "C"
{
#endif

/*********************************************************************
 * INCLUDE
 */
//c lib
#include "stdio.h"
#include "stdlib.h"
#include "stdarg.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"
//stack
#include "gapc_task.h" // GAP Controller Task API
#include "gapm_task.h" // GAP Manager Task API
#include "ke_timer.h"
#include "co_utils.h"
#include "app.h"
#include "app_task.h"
#include "app_fff0.h"
//peripheral
#include "gpio.h"
#include "uart.h"
#include "flash.h"
#include "pwm.h"
#include "rtc.h"
#include "rf.h"
//suble
#include "suble_scan_adv.h"
#include "suble_gap.h"
#include "suble_svc.h"
#include "suble_gpio.h"
#include "suble_uart.h"
#include "suble_flash.h"
#include "suble_timer.h"
#include "suble_util.h"
#include "suble_test.h"
//cpt
#include "elog.h"
//tuya_ble_sdk
#include "tuya_ble_api.h"
#include "tuya_ble_app_demo.h"

/*********************************************************************
 * CONSTANT
 */
#define SUBLE_DEBUG_EN 1

#if (SUBLE_DEBUG_EN)
    #define SUBLE_PRINTF(...)   log_d(__VA_ARGS__)
    #define SUBLE_HEXDUMP       suble_log_hexdump
#else
    #define SUBLE_PRINTF(...)
    #define SUBLE_HEXDUMP       suble_log_hexdump_empty
#endif

typedef enum {
    SUBLE_SUCCESS = 0x00,
    SUBLE_ERROR_COMMON,
} suble_status_t;

/*********************************************************************
 * STRUCT
 */

/*********************************************************************
 * EXTERNAL VARIABLE
 */
extern volatile bool g_system_sleep;

/*********************************************************************
 * EXTERNAL FUNCTION
 */
void suble_init_func(uint8_t location);
void suble_mainloop(void);

/*********************************************************  log  *********************************************************/
void suble_log_init(void);
void suble_log_hexdump(const char *name, uint8_t *buf, uint16_t size);
void suble_log_hexdump_for_tuya_ble_sdk(const char *name, uint8_t width, uint8_t *buf, uint16_t size);
void suble_log_hexdump_empty(const char *name, uint8_t width, uint8_t *buf, uint16_t size);

void suble_system_reset(void);
void suble_enter_critical(void);
void suble_exit_critical(void);

#ifdef __cplusplus
}
#endif

#endif //__SUBLE_COMMON_H__
