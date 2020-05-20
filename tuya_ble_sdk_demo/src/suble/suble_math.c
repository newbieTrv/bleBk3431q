#include "suble_math.h"




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
FN: ×Ö·û×ªint
*/
uint8_t suble_math_hexchar2int(uint8_t hexchar){
    switch(hexchar){
        case '0':return 0;
        case '1':return 1;
        case '2':return 2;
        case '3':return 3;
        case '4':return 4;
        case '5':return 5;
        case '6':return 6;
        case '7':return 7;
        case '8':return 8;
        case '9':return 9;
        case 'a':
        case 'A':return 10;
        case 'b':
        case 'B':return 11;
        case 'c':
        case 'C':return 12;
        case 'd':
        case 'D':return 13;
        case 'e':
        case 'E':return 14;
        case 'f':
        case 'F':return 15;
        default: return (uint8_t)-1;
    }
}

/*********************************************************
FN: int×ª×Ö·û
*/
uint8_t suble_math_int2hexchar(uint8_t int_num){
    switch(int_num){
        case 0:return '0';
        case 1:return '1';
        case 2:return '2';
        case 3:return '3';
        case 4:return '4';
        case 5:return '5';
        case 6:return '6';
        case 7:return '7';
        case 8:return '8';
        case 9:return '9';
        case 10:return 'a';
        case 11:return 'b';
        case 12:return 'c';
        case 13:return 'd';
        case 14:return 'e';
        case 15:return 'f';
//        case 10:return 'A';
//        case 11:return 'B';
//        case 12:return 'C';
//        case 13:return 'D';
//        case 14:return 'E';
//        case 15:return 'F';
        default:return (uint8_t)-1;
    }
}

/*********************************************************
FN: int×ª×Ö·û
*/
uint8_t suble_math_hexstr2hexarray(uint8_t *hexstr, int size, uint8_t *hexarray)
{
    uint8_t hex_num = 0;
	for(uint8_t idx=0; idx<size; idx++)
    {
        uint8_t tmp = suble_math_hexchar2int(hexstr[idx]);
        
        if(tmp == (uint8_t)-1) return 0;
        
        hex_num <<= 4;
        hex_num |= tmp;
        
        if((idx & 1) == 1){
            hexarray[idx>>1] = hex_num;
            hex_num = 0;
        }
	}
	return 1;
}

/*********************************************************
FN: 
*/
void suble_math_reverse_byte(void* buf, uint32_t size)
{
    uint8_t* p_tmp = buf;
    uint8_t  tmp;
    for(uint32_t idx=0; idx<size/2; idx++)
    {
        tmp = *(p_tmp+idx);
        *(p_tmp+idx) = *(p_tmp+size-1-idx);
        *(p_tmp+size-1-idx) = tmp;
    }
}





