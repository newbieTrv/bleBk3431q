/**
****************************************************************************
* @file      suble_uart.h
* @brief     suble_uart
* @author    suding
* @version   V1.0.0
* @date      2020-04
* @note
******************************************************************************
* @attention
*
* <h2><center>&copy; COPYRIGHT 2020 Tuya </center></h2>
*/


#ifndef __SUBLE_UART_H__
#define __SUBLE_UART_H__

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

/*********************************************************************
 * STRUCT
 */

/*********************************************************************
 * EXTERNAL VARIABLE
 */

/*********************************************************************
 * EXTERNAL FUNCTION
 */
void suble_uart1_init(void);
void suble_uart2_init(void);
void suble_uart1_send(const uint8_t* buf, uint32_t size);
void suble_uart2_send(const uint8_t* buf, uint32_t size);


#ifdef __cplusplus
}
#endif

#endif //__SUBLE_UART_H__
