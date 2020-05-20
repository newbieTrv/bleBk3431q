/**
****************************************************************************
* @file      suble_gap.h
* @brief     suble_gap
* @author    suding
* @version   V1.0.0
* @date      2020-04
* @note
******************************************************************************
* @attention
*
* <h2><center>&copy; COPYRIGHT 2020 Tuya </center></h2>
*/


#ifndef __SUBLE_GAP_H__
#define __SUBLE_GAP_H__

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
#define SUBLE_BT_MAC_LEN                      BD_ADDR_LEN
#define SUBLE_BT_MAC_STR_LEN                  (SUBLE_BT_MAC_LEN*2)

#define SUBLE_CONN_INTERVAL_MIN               TUYA_CONN_INTERVAL_MIN //最小可接受的连接间隔
#define SUBLE_CONN_INTERVAL_MAX               TUYA_CONN_INTERVAL_MAX
#define SUBLE_SLAVE_LATENCY                   0
#define SUBLE_CONN_SUP_TIMEOUT                5000

/*********************************************************************
 * STRUCT
 */

/*********************************************************************
 * EXTERNAL VARIABLE
 */

/*********************************************************************
 * EXTERNAL FUNCTION
 */
void suble_gap_disconnect(uint16_t conn_handle, uint8_t hci_status_code);
void suble_gap_disconnect_for_tuya_ble_sdk(void);
void suble_gap_conn_param_update(uint16_t cMin, uint16_t cMax, uint16_t latency, uint16_t timeout);
void suble_gap_init_bt_mac(void);
void suble_gap_set_bt_mac(uint8_t *pMac);
void suble_gap_get_bt_mac(uint8_t *pMac, uint32_t size);

void suble_gap_conn_handler(void);
void suble_gap_disconn_handler(void);

#ifdef __cplusplus
}
#endif

#endif //__SUBLE_GAP_H__
