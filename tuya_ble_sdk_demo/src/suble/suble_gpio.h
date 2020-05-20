/**
****************************************************************************
* @file      suble_gpio.h
* @brief     suble_gpio
* @author    suding
* @version   V1.0.0
* @date      2020-04
* @note
******************************************************************************
* @attention
*
* <h2><center>&copy; COPYRIGHT 2020 Tuya </center></h2>
*/


#ifndef __SUBLE_GPIO_H__
#define __SUBLE_GPIO_H__

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
#define SUBLE_OUT_PIN_0 0x12
#define SUBLE_OUT_PIN_1 0x13
#define SUBLE_IN_PIN_0  0x10
#define SUBLE_IN_PIN_1  0x11

enum
{
    SUBLE_LEVEL_INVALID = 0xFF,
    SUBLE_LEVEL_LOW  = 0,
    SUBLE_LEVEL_HIGH = 1,
};

/*********************************************************************
 * STRUCT
 */
typedef struct
{
    uint8_t pin;
    uint8_t level;
} suble_out_pin_t;

/*********************************************************************
 * EXTERNAL VARIABLE
 */

/*********************************************************************
 * EXTERNAL FUNCTION
 */
void    suble_gpio_init_output(uint8_t pin);
void    suble_gpio_init_input(uint8_t pin, uint8_t pull_type);
uint8_t suble_gpio_get_input(uint8_t pin);
uint8_t suble_gpio_get_output(uint8_t pin);
void    suble_gpio_set(uint8_t pin, uint8_t level);
void    suble_gpio_reverse(uint8_t pin);

void    suble_gpio_irq_init(void);

void    suble_gpio_init(void);

#ifdef __cplusplus
}
#endif

#endif //__SUBLE_GPIO_H__
