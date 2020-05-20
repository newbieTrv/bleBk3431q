/**
****************************************************************************
* @file      suble_svc.h
* @brief     suble_svc
* @author    suding
* @version   V1.0.0
* @date      2020-04
* @note
******************************************************************************
* @attention
*
* <h2><center>&copy; COPYRIGHT 2020 Tuya </center></h2>
*/


#ifndef __SUBLE_SVC_H__
#define __SUBLE_SVC_H__

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
void suble_svc_init(void);
void suble_svc_receive_data(uint8_t* buf, uint32_t size);
void suble_svc_send_data_complete(void);
void suble_svc_notify(uint8_t* buf, uint32_t size);
void suble_svc_notify_handler(void);


#ifdef __cplusplus
}
#endif

#endif //__SUBLE_SVC_H__
