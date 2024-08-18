#ifndef _pLATFORM_TYPES_H_
#define _pLATFORM_TYPES_H_

#include <stdio.h>
#include <stdlib.h>

#define CPU_TYPE_8 8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define CPU_TYPE_64 64

#define ZERO_INIT 0
#define ZERO 0

/** 
  * @brief: Define a new_data_type which is Standard Return Data_Type 
        Each Function in this Application will return Error state which indicates whether the function is Executed Successfully
        or Not Executed Successfully 
        R_NOK : indicates the Function has not run successfully
        R_OK  : indicates the Function has run successfully 
*/

typedef enum return_status
{
    R_NOK,
    R_OK
}return_status_t;

#define CPU_TYPE (CPU_TYPE_64)

/**************************************************************** */
#if (CPU_TYPE == CPU_TYPE_64)
typedef unsigned char boolean;
typedef  unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;
typedef signed long long sint64_t;
typedef float float32_t;
typedef double float64_t;
/**************************************************************** */


/**************************************************************** */
#elif (CPU_TYPE == CPU_TYPE_32)
typedef unsigned char boolean;
typedef  unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed long sint32_t;
typedef signed long long sint64_t;
typedef float float32_t;
typedef double float64_t;

/**************************************************************** */


/**************************************************************** */
#elif (CPU_TYPE == CPU_TYPE_16)
typedef unsigned char boolean;
typedef  unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed long sint32_t;
typedef signed long long sint64_t;
typedef float float32_t;
typedef double float64_t;
/**************************************************************** */


/**************************************************************** */
#elif (CPU_TYPE == CPU_TYPE_8)
typedef unsigned char boolean;
typedef  unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned short long uint24_t;
typedef unsigned long long uint32_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed short long sint24_t;
typedef signed long long sint32_t;
typedef float float32_t;
/**************************************************************** */

#endif

#endif