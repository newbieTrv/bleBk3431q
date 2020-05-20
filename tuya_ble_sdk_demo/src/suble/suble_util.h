/**
****************************************************************************
* @file      suble_util.h
* @brief     suble_util
* @author    suding
* @version   V1.0.0
* @date      2020-04
* @note
******************************************************************************
* @attention
*
* <h2><center>&copy; COPYRIGHT 2020 Tuya </center></h2>
*/


#ifndef __SUBLE_UTIL_H__
#define __SUBLE_UTIL_H__

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
uint8_t  suble_util_check_sum8(uint8_t *buf, uint32_t size);
uint16_t suble_util_check_sum16(uint8_t *buf, uint32_t size);
uint16_t suble_util_crc16(uint8_t* buf, uint32_t size, uint16_t* p_crc);
uint32_t suble_util_crc32(uint8_t* buf, uint32_t size, uint32_t* p_crc);
void     suble_util_reverse_byte(void* buf, uint32_t size);
uint32_t suble_util_numarray2int(uint8_t *num_array, uint32_t start_idx, uint32_t size);

/*********************************************************  string  *********************************************************/
uint8_t  suble_util_str_hexchar2int(uint8_t hexchar);
uint8_t  suble_util_str_int2hexchar(uint8_t int_num);
uint32_t suble_util_str_hexstr2int(uint8_t* hexstr, uint32_t size, int* sum);
uint32_t suble_util_str_intstr2int(uint8_t* intstr, uint32_t size, int* sum);
uint32_t suble_util_str_hexstr2hexarray(uint8_t* hexstr, uint32_t size, uint8_t* hexarray);
uint32_t suble_util_str_hexarray2hexstr(uint8_t* hexarray, uint32_t size, uint8_t* hexstr);

#ifdef __cplusplus
}
#endif

#endif //__SUBLE_UTIL_H__
