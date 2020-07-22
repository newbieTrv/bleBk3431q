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

/*********************************************************************
 * LOCAL FUNCTION
 */




/*********************************************************
FN: 
*/



/*********************************************************************
 * LOCAL CONSTANTS
 */
#define KEY_COUNT_1  (4/1)
#define KEY_COUNT_2  (300/1)
#define KEY_COUNT_3  (1000/1)

enum
{
    KEY_STATE_READY = 0,
    KEY_STATE_PRESSED_1,
    KEY_STATE_PRESSED_2,
    KEY_STATE_RELEASE,
    KEY_STATE_RELEASE_0, //4
    KEY_STATE_RELEASE_1,
    KEY_STATE_RELEASE_2,
};

/*********************************************************************
 * LOCAL STRUCT
 */

/*********************************************************************
 * LOCAL VARIABLES
 */




/*********************************************************
FN: 按键处理函数
*/
static void suble_key_state_handler(uint8_t state)
{
//    UART_PRINTF("KEY_STATE: %d\r\n", state);
    switch(state)
    {
        case KEY_STATE_PRESSED_1: {
            suble_battery_sample_start();
        } break;
        
        case KEY_STATE_PRESSED_2: {
        } break;
        
        case KEY_STATE_RELEASE_1: {
        } break;
        
        default: {
        } break;
    }
}

/*********************************************************
FN: 按键超时处理
*/
void suble_key_timeout_handler(void)
{
    #define SUBLE_KEY_TIME      5
    #define SUBLE_VALID_LEVEL   SUBLE_LEVEL_LOW
    static uint8_t  key_log[SUBLE_KEY_TIME];
    static uint32_t key_log_idx = 0;
    uint32_t key_log_sum = 0;
    static uint32_t key_count   = 0;
    static bool     key_pressed = true;
    static int      key_state   = KEY_STATE_READY;
    
    //按键计数
    key_count++;
    //中间消抖计数
    key_log_idx++;
    if(key_log_idx == SUBLE_KEY_TIME)
    {
        key_log_idx = 0;
    }
    
    //记录前10次的状态
    if(suble_gpio_get_input(SUBLE_IN_PIN_1) == SUBLE_VALID_LEVEL) {
        key_log[key_log_idx] = 0;
    } else {
        key_log[key_log_idx] = 1;
    }
    //统计前10次的状态
    for(uint8_t idx=0; idx<SUBLE_KEY_TIME; idx++) {
        key_log_sum += key_log[idx];
    }
    //无效次数大于7次
    if(key_log_sum > 4) {
        key_pressed = false;
        memset(key_log, 0, SUBLE_KEY_TIME);
    }
    
//    UART_PRINTF(": %d\r\n", key_pressed);
    if(key_pressed == true)
    {
        if(key_count == KEY_COUNT_1) {
            if(key_state == KEY_STATE_READY) {
                key_state = KEY_STATE_PRESSED_1;
                suble_key_state_handler(key_state);
            }
        }
        else if(key_count == KEY_COUNT_2) {
            if(key_state == KEY_STATE_PRESSED_1) {
                key_state = KEY_STATE_PRESSED_2;
                suble_key_state_handler(key_state);
            }
        }
        else if(key_count == KEY_COUNT_3) {
            if(key_state == KEY_STATE_PRESSED_2) {
                //超时释放
                key_state = KEY_STATE_RELEASE;
            }
        }
    }
    else {
        if(key_count <= KEY_COUNT_1) {
            if(key_state == KEY_STATE_READY) {
                key_state = KEY_STATE_RELEASE_0;
            }
        }
        else if((key_count > KEY_COUNT_1) && (key_count <= KEY_COUNT_2)) {
            if(key_state == KEY_STATE_PRESSED_1) {
                key_state = KEY_STATE_RELEASE_1;
            }
        }
        else if((key_count > KEY_COUNT_2) && (key_count <= KEY_COUNT_3)) {
            if(key_state == KEY_STATE_PRESSED_2) {
                key_state = KEY_STATE_RELEASE_2;
            }
        }
    }
    
    //释放
    if(key_state >= KEY_STATE_RELEASE) {
        suble_key_state_handler(key_state);
        
        key_count = 0;
        key_pressed = true;
        key_state = KEY_STATE_READY;
        suble_timer_stop_0(SUBLE_TIMER_KEY_TIMEOUT);
    }
}





