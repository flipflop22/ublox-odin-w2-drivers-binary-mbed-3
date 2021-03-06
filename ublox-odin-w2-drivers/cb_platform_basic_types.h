/*---------------------------------------------------------------------------
 * Copyright (c) 2016 u-blox AB, Sweden.
 * Any reproduction without written permission is prohibited by law.
 *
 * Component   : Wireless LAN driver
 * File        : cb_types.h
 *
 * Description : Common definitions for a GCC compatible compiler.
 *-------------------------------------------------------------------------*/

/**
 * @file cb_types.h Defines type required for the entire driver.
 * The defines in this file will have to be adapted for the platform.
 * @ingroup platform
 */

#ifndef _CB_PLATFORM_BASIC_TYPES_H_
#define _CB_PLATFORM_BASIC_TYPES_H_

#include <stdint.h>
#include <stdbool.h>

/*===========================================================================
 * TYPES
 *=========================================================================*/

/*===========================================================================
 * COMMON SYSTEM DEFINES
 *=========================================================================*/
#ifndef __GNUC__
#  error "This cb_platform_basic_types.h is only valid for GCC. Check your make target"
#endif


typedef int8_t                  cb_int8;
typedef int16_t                 cb_int16;
typedef int32_t                 cb_int32;
typedef int64_t                 cb_int64;

typedef uint8_t                 cb_uint8;
typedef uint16_t                cb_uint16;
typedef uint32_t                cb_uint32;
typedef uint64_t                cb_uint64;

typedef bool                    cb_boolean;
typedef char                    cb_char;
typedef int                     cb_int;

/**
 * Used when declaring an empty array that does not take up space in a struct.
 * Example: struct { cb_uint8 payload[cb_EMPTY_ARRAY]; }
 * In some compilers this is empty i.e. payload[]. While in some it requires a zero.
 * I.e. payload[0];
 * Use this define to get it working for your system.
 */
#define cb_EMPTY_ARRAY (0)

/*===========================================================================
 * DEFINES
 *=========================================================================*/

/**
 * Used in function definitions to declare an input parameter unused to avoid warnings.
 */
#define cb_UNUSED(x) UNUSED_ ## x __attribute__((unused))


/**
 * Define cb_ASSERT to the wanted assert handler.
 */
/*
#define cb_ASSERT(exp)              do { if (!(exp)) { \
                                        W_PRINT("ASSERT %s:%d\n", __FILE__, __LINE__); \
                                        while(1); \
                                    } } while(0)
*/
#include "cb_assert.h"


/**@{*/
/**
 * Packed struct defines.
 * - cb_PACKED_STRUCT_ATTR_PRE is used before the typedef'ed struct declaration.
 * - cb_PACKED_STRUCT_ATTR_INLINE_PRE is after the typedef but before the struct declaration.
 * - cb_PACKED_STRUCT_ATTR_INLINE_POST is used after the struct declaration but before the typedef'ed name.
 * - cb_PACKED_STRUCT_ATTR_POST is used after the entire struct declaration.
 * 
 * example:
 *      cb_PACKED_STRUCT_ATTR_PRE
 *      typedef cb_PACKED_STRUCT_ATTR_INLINE_PRE struct myPackedStruct {
 *          int a;
 *          int b;
 *      } cb_PACKED_STRUCT_ATTR_INLINE_POST myPackedStruct
 *      cb_PACKED_STRUCT_ATTR_POST
 *
 */
/*
#define cb_PACKED_STRUCT_ATTR_PRE
#define cb_PACKED_STRUCT_ATTR_INLINE_PRE
*/
#define cb_PACKED_STRUCT_ATTR_INLINE_POST       __attribute__ ((__packed__))
/*
#define cb_PACKED_STRUCT_ATTR_POST
*/
/**@}*/


#define DO_PRAGMA(x) _Pragma (#x)
#define TODO(x) DO_PRAGMA(message ("TODO - " #x))


#endif /* _CB_PLATFORM_BASIC_TYPES_H_ */

