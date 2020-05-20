/**
****************************************************************************
* @file      suble_scan_adv.h
* @brief     suble_scan_adv
* @author    suding
* @version   V1.0.0
* @date      2020-04
* @note
******************************************************************************
* @attention
*
* <h2><center>&copy; COPYRIGHT 2020 Tuya </center></h2>
*/


#ifndef __SUBLE_SCAN_ADV_H__
#define __SUBLE_SCAN_ADV_H__

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
#define  SUBLE_ADV_DATA_MAX_LEN     31

#define  SUBLE_ADV_INTERVAL_MIN     TUYA_ADV_INTERVAL
#define  SUBLE_ADV_INTERVAL_MAX     TUYA_ADV_INTERVAL

/*********************************************************************
 * STRUCT
 */
#pragma pack(1)
typedef struct
{
    double  adv_interval_min; //ms
    double  adv_interval_max; //ms
    uint8_t adv_type;
    uint8_t adv_power;
    uint8_t adv_channal_map;
} adv_param_t;

typedef struct
{
    uint32_t len;
    uint8_t  value[SUBLE_ADV_DATA_MAX_LEN];
} adv_data_t;
#pragma pack()

/*********************************************************************
 * EXTERNAL VARIABLE
 */
extern adv_data_t      g_adv_data;
extern adv_data_t      g_scan_rsp;
extern adv_param_t     g_adv_param;

//更新广播参数
extern volatile bool g_adv_restart_glag;

/*********************************************************************
 * EXTERNAL FUNCTION
 */
void suble_adv_start(void);
void suble_adv_stop(void);
void suble_adv_update_advDataAndScanRsp(void);
void suble_adv_param_set(void);


#ifdef __cplusplus
}
#endif

#endif //__SUBLE_SCAN_ADV_H__
