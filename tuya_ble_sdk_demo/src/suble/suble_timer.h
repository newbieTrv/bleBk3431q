/**
****************************************************************************
* @file      suble_timer.h
* @brief     suble_timer
* @author    suding
* @version   V1.0.0
* @date      2020-04
* @note
******************************************************************************
* @attention
*
* <h2><center>&copy; COPYRIGHT 2020 Tuya </center></h2>
*/


#ifndef __SUBLE_TIMER_H__
#define __SUBLE_TIMER_H__

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
#define SUBLE_TIMER_MAX_NUM            20

#define SUBLE_TIMER_COUNT_ENDLESS      0xFFFFFFFF

typedef enum {
    SUBLE_TIMER_SINGLE_SHOT,
    SUBLE_TIMER_REPEATED,
} suble_timer_mode_t;

/*********************************************************************
 * STRUCT
 */
typedef struct
{
    uint32_t count;
    uint32_t delay;
} suble_timer_t;

typedef void (*suble_timer_handler_t)(void*);


/*********************************************************************
 * EXTERNAL VARIABLE
 */

/*********************************************************************
 * EXTERNAL FUNCTION
 */
/*********************************************************  suble_timer  *********************************************************/
void suble_timer_handler(ke_msg_id_t timer_id);
void suble_timer_start_0(ke_msg_id_t const timer_id, uint32_t ms, uint32_t count);
void suble_timer_stop_0(ke_msg_id_t const timer_id);
bool suble_timer_is_running(ke_msg_id_t const timer_id);

/*********************************************************  suble_timer app  *********************************************************/
uint32_t suble_timer_create(void** p_timer_id, uint32_t timeout_value_ms, suble_timer_mode_t mode, suble_timer_handler_t timeout_handler);
uint32_t suble_timer_delete(void* timer_id);
uint32_t suble_timer_start(void* timer_id);
uint32_t suble_timer_stop(void* timer_id);
uint32_t suble_timer_restart(void* timer_id, uint32_t timeout_value_ms);

/*********************************************************  RTC  *********************************************************/
void suble_local_timer_start(void);
void suble_update_timestamp(uint32_t app_timestamp);
uint32_t suble_get_app_timestamp_when_update(void);
uint32_t suble_get_local_timestamp(void);
uint32_t suble_get_timestamp(void);
uint32_t suble_get_old_timestamp(uint32_t old_local_timestamp);

/*********************************************************  delay  *********************************************************/
void suble_delay_ms(uint32_t ms);
void suble_delay_us(uint32_t us);

#ifdef __cplusplus
}
#endif

#endif //__SUBLE_TIMER_H__
