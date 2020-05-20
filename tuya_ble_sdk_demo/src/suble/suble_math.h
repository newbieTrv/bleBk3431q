/**
****************************************************************************
* @file      suble_math.h
* @brief     suble_math
* @author    suding
* @version   V1.0.0
* @date      2020-04
* @note
******************************************************************************
* @attention
*
* <h2><center>&copy; COPYRIGHT 2020 Tuya </center></h2>
*/


#ifndef __SUBLE_MATH_H__
#define __SUBLE_MATH_H__

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
uint8_t suble_math_hexstr2hexarray(uint8_t *hexstr, int size, uint8_t *hexarray);
void suble_math_reverse_byte(void* buf, uint32_t size);


#ifdef __cplusplus
}
#endif

#endif //__SUBLE_MATH_H__
