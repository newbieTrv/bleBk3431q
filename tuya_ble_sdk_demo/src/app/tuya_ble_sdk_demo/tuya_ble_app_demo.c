#include "tuya_ble_app_demo.h"
#include "tuya_ble_stdlib.h"
#include "tuya_ble_type.h"
#include "tuya_ble_heap.h"
#include "tuya_ble_mem.h"
#include "tuya_ble_api.h"
#include "tuya_ble_port.h"
#include "tuya_ble_main.h"
#include "tuya_ble_secure.h"
#include "tuya_ble_data_handler.h"
#include "tuya_ble_storage.h"
#include "tuya_ble_sdk_version.h"
#include "tuya_ble_utils.h"
#include "tuya_ble_event.h"
#include "tuya_ble_log.h"
#include "tuya_ble_app_ota.h"
#include "tuya_ble_app_test.h"




/*********************************************************************
 * LOCAL CONSTANT
 */

/*********************************************************************
 * LOCAL STRUCT
 */

/*********************************************************************
 * LOCAL VARIABLE
 */
static const char auth_key_test[]  = TUYA_DEVICE_AUTH_KEY;
static const char device_id_test[] = TUYA_DEVICE_DID; //DC234D08C8EF

//tuya_ble_sdk init param
static tuya_ble_device_param_t tuya_ble_device_param = 
{
    .device_id_len    = DEVICE_ID_LEN,
    .p_type           = TUYA_BLE_PRODUCT_ID_TYPE_PID,
    .product_id_len   = 8,
    .bound_flag       = 0,
    .firmware_version = TUYA_DEVICE_FVER_NUM,
    .hardware_version = TUYA_DEVICE_HVER_NUM,
};

/*********************************************************************
 * VARIABLE
 */
demo_dp_t g_demo_cmd;
demo_dp_t g_demo_rsp;

/*********************************************************************
 * LOCAL FUNCTION
 */
static void tuya_ble_app_data_process(int32_t evt_id,void *data);
static void tuya_ble_sdk_callback(tuya_ble_cb_evt_param_t* event);




/*********************************************************
FN: 
*/
void tuya_ble_app_init(void)
{
    suble_flash_init();
    
    tuya_ble_app_test_init();
    
    //tuya_ble_sdk init
    memcpy(tuya_ble_device_param.product_id, TUYA_DEVICE_PID, 8);
    memcpy(tuya_ble_device_param.device_id,  device_id_test,  DEVICE_ID_LEN);
    memcpy(tuya_ble_device_param.auth_key,   auth_key_test,   AUTH_KEY_LEN);
    tuya_ble_sdk_init(&tuya_ble_device_param);
    
    //register tuya_ble_sdk callback
    tuya_ble_callback_queue_register(tuya_ble_sdk_callback);
    
    tuya_ble_app_ota_init();
}

/*********************************************************
FN: 
*/
static void tuya_ble_sdk_callback(tuya_ble_cb_evt_param_t* event)
{
    switch(event->evt)
    {
        case TUYA_BLE_CB_EVT_CONNECTE_STATUS: {
            if(event->connect_status == BONDING_CONN) {
                TUYA_APP_LOG_DEBUG("bonding and connecting");
            }
        } break;
        
        case TUYA_BLE_CB_EVT_DP_WRITE: {
            if(event->dp_write_data.p_data[2] == (event->dp_write_data.data_len - 3))
            {
                memcpy(&g_demo_cmd, event->dp_write_data.p_data, event->dp_write_data.data_len);
                memcpy(&g_demo_rsp, event->dp_write_data.p_data, event->dp_write_data.data_len);
                
                TUYA_APP_LOG_HEXDUMP_DEBUG("dp_cmd", (void*)&g_demo_cmd, g_demo_cmd.dp_data_len+3);
                
                tuya_ble_dp_data_report((void*)&g_demo_rsp, g_demo_rsp.dp_data_len+3);
                TUYA_APP_LOG_HEXDUMP_DEBUG("dp_rsp", (void*)&g_demo_rsp, g_demo_rsp.dp_data_len+3);
            }
        } break;
        
        case TUYA_BLE_CB_EVT_DP_DATA_REPORT_RESPONSE: {
            TUYA_APP_LOG_DEBUG("TUYA_BLE_CB_EVT_DP_DATA_REPORT_RESPONSE = %d",event->dp_response_data.status);
        } break;
        
        case TUYA_BLE_CB_EVT_DP_DATA_WTTH_TIME_REPORT_RESPONSE: {
            TUYA_APP_LOG_DEBUG("TUYA_BLE_CB_EVT_DP_DATA_WTTH_TIME_REPORT_RESPONSE = %d",event->dp_response_data.status);
        } break;
        
        case TUYA_BLE_CB_EVT_UNBOUND: {
            TUYA_APP_LOG_DEBUG("TUYA_BLE_CB_EVT_UNBOUND");
        } break;
        
        case TUYA_BLE_CB_EVT_ANOMALY_UNBOUND: {
            TUYA_APP_LOG_DEBUG("TUYA_BLE_CB_EVT_ANOMALY_UNBOUND");
        } break;
        
        case TUYA_BLE_CB_EVT_DEVICE_RESET: {
            TUYA_APP_LOG_DEBUG("TUYA_BLE_CB_EVT_DEVICE_RESET");
        } break;
        
        case TUYA_BLE_CB_EVT_DP_QUERY: {
//            TUYA_APP_LOG_DEBUG("TUYA_BLE_CB_EVT_DP_QUERY");
//            TUYA_APP_LOG_HEXDUMP_DEBUG("TUYA_BLE_CB_EVT_DP_QUERY", event->dp_query_data.p_data, event->dp_query_data.data_len);
        } break;
        
        case TUYA_BLE_CB_EVT_OTA_DATA: {
            tuya_ble_app_ota_handler(&event->ota_data);
        } break;
        
        case TUYA_BLE_CB_EVT_TIME_STAMP: {
            TUYA_APP_LOG_DEBUG("TUYA_BLE_CB_EVT_TIME_STAMP: %s, time_zone: %d",event->timestamp_data.timestamp_string,event->timestamp_data.time_zone);
        } break;
        
        case TUYA_BLE_CB_EVT_TIME_NORMAL: {
        } break;
        
        default: {
            TUYA_APP_LOG_DEBUG("tuya_ble_sdk_callback unknown event type 0x%04x", event->evt);
        } break;
    }
}

/*********************************************************
FN: 
*/
static void tuya_ble_app_data_process(int32_t evt_id, void *data)
{
    custom_evt_data_t* custom_data = data;
    
    switch (evt_id)
    {
        case APP_EVT_CONNECTED: {
            tuya_ble_connected_handler();
            tuya_ble_app_ota_disconn_handler();
        } break;
        
        case APP_EVT_DISCONNECTED: {
            tuya_ble_disconnected_handler();
        } break;
        
        default: {
        } break;
    }
    
    if(custom_data != NULL)
    {
        tuya_ble_free((void*)custom_data);
    }
}

/*********************************************************
FN: no data
*/
void tuya_ble_app_evt_send(custom_evtid_t evtid)
{
    tuya_ble_custom_evt_t custom_evt;
    
    custom_evt.evt_id = evtid;
    custom_evt.data = NULL;
    custom_evt.custom_event_handler = tuya_ble_app_data_process;
    
    tuya_ble_custom_event_send(custom_evt);
}

/*********************************************************
FN: 
*/
void tuya_ble_app_evt_send_with_data(custom_evtid_t evtid, void* buf, uint32_t size)
{
    custom_evt_data_t* custom_data = tuya_ble_malloc(sizeof(custom_evt_data_t) + size);
    if(custom_data)
    {
        tuya_ble_custom_evt_t custom_evt;
        
        custom_data->len = size;
        memcpy(custom_data->value, buf, size);
        
        custom_evt.evt_id = evtid;
        custom_evt.data = custom_data;
        custom_evt.custom_event_handler = tuya_ble_app_data_process;
        
        tuya_ble_custom_event_send(custom_evt);
    }
    else {
        TUYA_APP_LOG_DEBUG("tuya_ble_app_evt_send_with_data: malloc failed");
    }
}












