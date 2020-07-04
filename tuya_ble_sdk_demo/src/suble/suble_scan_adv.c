#include "suble_common.h"




/*********************************************************************
 * LOCAL CONSTANT
 */
//广播和扫描响应数据
#define  DEFAULT_ADV_DATA                                                   \
            {                                                               \
                3,                                                          \
                {                                                           \
                    0x02,                                                   \
                    GAP_AD_TYPE_FLAGS,                                      \
                    GAP_LE_GEN_DISCOVERABLE_FLG | GAP_BR_EDR_NOT_SUPPORTED, \
                },                                                          \
            }
            
#define  DEFAULT_SCAN_RSP                                                   \
            {                                                               \
                6,                                                          \
                {                                                           \
                    0x05,                                                   \
                    GAP_AD_TYPE_COMPLETE_NAME,                              \
                    'D', 'e', 'm', 'o',                                     \
                },                                                          \
            }

//广播和扫描参数
#define  DEFAULT_ADV_PARAM                                                  \
            {                                                               \
                .adv_interval_min = SUBLE_ADV_INTERVAL_MIN,                 \
                .adv_interval_max = SUBLE_ADV_INTERVAL_MAX,                 \
                .adv_type         = GAPM_ADV_UNDIRECT,                      \
                .adv_power        = 0x00,                                   \
                .adv_channal_map  = 0x07,                          \
            }

/*********************************************************************
 * LOCAL STRUCT
 */

/*********************************************************************
 * LOCAL VARIABLE
 */

/*********************************************************************
 * VARIABLE
 */
adv_data_t      g_adv_data      = DEFAULT_ADV_DATA;
adv_data_t      g_scan_rsp      = DEFAULT_SCAN_RSP;
adv_param_t     g_adv_param     = DEFAULT_ADV_PARAM;

//更新广播参数
volatile bool g_adv_restart_glag = false;

/*********************************************************************
 * LOCAL FUNCTION
 */




/*********************************************************
FN: 启动广播
*/
void suble_adv_start(void)
{
    appm_start_advertising();
}

/*********************************************************
FN: 停止广播
*/
void suble_adv_stop(void)
{
    appm_stop_advertising();
}

/*********************************************************
FN: 更新广播和扫描响应数据
*/
void suble_adv_update_advDataAndScanRsp(void)
{
    appm_update_adv_data(g_adv_data.value, g_adv_data.len, g_scan_rsp.value, g_scan_rsp.len);
}

/*********************************************************
FN: 设置广播参数，结合 g_adv_param 使用
*/
void suble_adv_param_set(void)
{
    if(ke_state_get(TASK_APP) == APPM_ADVERTISING)
    {
        suble_adv_stop();
        g_adv_restart_glag = true;
    }
}
































