/**
****************************************************************************
* @file      tuya_ble_app_demo.h
* @brief     tuya_ble_app_demo
* @author    suding
* @version   V1.0.0
* @date      2020-04
* @note
******************************************************************************
* @attention
*
* <h2><center>&copy; COPYRIGHT 2020 Tuya </center></h2>
*/


#ifndef __TUYA_BLE_APP_DEMO_H__
#define __TUYA_BLE_APP_DEMO_H__

#ifdef __cplusplus
extern "C"
{
#endif

/*********************************************************************
 * INCLUDE
 */
#include "tuya_ble_port_bk3431q.h"

/*********************************************************************
 * CONSTANT
 */
/*********************************************************  tuya  *********************************************************/
//PID-product id-产品id
//DID-device id -设备id（云端称作uuid）
#define TUYA_DEVICE_PID         "ujzporqr"
#define TUYA_DEVICE_MAC         "DC234D1C41AE"
#define TUYA_DEVICE_DID         "tuyac0913bc8172f"                  //16Byte
#define TUYA_DEVICE_AUTH_KEY    "UBAGZAqtAxTsyAEIKA1EVrN90Y9eZGkt"  //32Byte

#define TUYA_DEVICE_FIR_NAME    "KF_ble_CaWindow_bk3431q"      //固件标识名
#define TUYA_DEVICE_FVER_NUM    0x00000104                          //固件版本
#define TUYA_DEVICE_HVER_NUM    0x00000100                          //硬件版本
#define TUYA_DEVICE_FVER_STR    "1.4"                               //固件版本str
#define TUYA_DEVICE_HVER_STR    "1.0"                               //硬件版本str

//蓝牙参数
#define TUYA_ADV_INTERVAL       152.5                               //广播间隔, 范围: 20~10240ms, 推荐值: (152.5), (1022.5)
#define TUYA_CONN_INTERVAL_MIN  180                                 //连接间隔, 范围: 7.5~4000ms
#define TUYA_CONN_INTERVAL_MAX  200                                 //连接间隔, 范围: 7.5~4000ms

//event id
typedef enum
{
    APP_EVT_CONNECTED = 0,
    APP_EVT_DISCONNECTED,
} custom_evtid_t;

/*********************************************************************
 * STRUCT
 */
#pragma pack(1)
//dp point
typedef struct
{
    uint8_t dp_id;
    uint8_t dp_type;
    uint8_t dp_data_len;
    union
    {
        uint8_t dp_data[256];
    };
} demo_dp_t;

typedef struct
{
    uint32_t len;
    uint8_t  value[];
} custom_evt_data_t;
#pragma pack()

/*********************************************************************
 * EXTERNAL VARIABLE
 */
extern demo_dp_t g_demo_cmd;
extern demo_dp_t g_demo_rsp;

/*********************************************************************
 * EXTERNAL FUNCTION
 */
void tuya_ble_app_init(void);
void tuya_ble_app_evt_send(custom_evtid_t evtid);
void tuya_ble_app_evt_send_with_data(custom_evtid_t evtid, void* buf, uint32_t size);


#ifdef __cplusplus
}
#endif

#endif //__TUYA_BLE_APP_DEMO_H__

