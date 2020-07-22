#include "suble_common.h"




/*********************************************************************
 * LOCAL CONSTANT
 */

/*********************************************************************
 * LOCAL STRUCT
 */

/*********************************************************************
 * LOCAL VARIABLE
 */

/*********************************************************************
 * VARIABLE
 */
volatile bool g_system_sleep = false;

/*********************************************************************
 * LOCAL FUNCTION
 */




/*********************************************************
FN: 
*/
void suble_init_func(uint8_t location)
{
    switch(location)
    {
        case 0: {
//            suble_gpio_init();
//            suble_battery_init();
        } break;
        
        case 1: {
        } break;
        
        case 2: {
            suble_test_func();
            suble_local_timer_start();
            tuya_ble_app_init();
            suble_adv_start();
        } break;
        
        default: {
        } break;
    }
}

/*********************************************************
FN: 
*/
void suble_mainloop(void)
{
    tuya_ble_main_tasks_exec();
    suble_svc_notify_handler();
}




/*********************************************************
FN: 
*/
void suble_system_reset(void)
{
    TUYA_APP_LOG_DEBUG("device reset");
    platform_reset(0);
}

/*********************************************************
FN: 
*/
void suble_factory_reset(void)
{
    sf_port_flash_erase(SF_AREA0_BASE, 2);
    sf_port_flash_erase(SF_AREA1_BASE, 2);
    sf_port_flash_erase(SF_AREA2_BASE, 2);
    sf_port_flash_erase(SF_AREA3_BASE, 2);
    sf_port_flash_erase(SF_AREA4_BASE, 2);
    suble_flash_init();
}

/*********************************************************
FN: 
*/
static uint32_t fiq_tmp;
static uint32_t irq_tmp;
void suble_enter_critical(void)
{
    fiq_tmp = __disable_fiq();
    irq_tmp = __disable_irq();
}
void suble_exit_critical(void)
{
    if(!fiq_tmp) {
        __enable_fiq();
    }
    if(!irq_tmp) {
        __enable_irq();
    }
}




/*********************************************************
FN: 
*/
void suble_log_init(void)
{
    elog_init();
//    elog_set_fmt(ELOG_LVL_DEBUG, ELOG_FMT_LVL);
    elog_start();
}

/*********************************************************
FN: 
*/
void suble_log_hexdump(const char *name, uint8_t *buf, uint16_t size)
{
    elog_hexdump(name, 8, buf, size);
}

/*********************************************************
FN: 
*/
void suble_log_hexdump_for_tuya_ble_sdk(const char *name, uint8_t width, uint8_t *buf, uint16_t size)
{
    elog_hexdump(name, width, buf, size);
}

/*********************************************************
FN: 
*/
void suble_log_hexdump_empty(const char *name, uint8_t width, uint8_t *buf, uint16_t size)
{
    //empty
}




















