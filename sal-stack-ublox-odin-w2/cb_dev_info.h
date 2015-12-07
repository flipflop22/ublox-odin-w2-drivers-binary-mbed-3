#ifndef __CB_DEV_INFO_H__
#define __CB_DEV_INFO_H__
/*------------------------------------------------------------------------------
 * Copyright (c) 2008 connectBlue AB, Sweden.
 * Any reproduction without written permission is prohibited by law.
 *------------------------------------------------------------------------------
 * Produced by connectBlue AB, Malm�, Sweden
 *------------------------------------------------------------------------------
 * Component: Device Information service
 * File     : 
 * Revision :
 *
 * Date     :
 * Author   :
 *------------------------------------------------------------------------------
 * Description: This declaration file contains all constants, types, macros and
 * interface definitions for the Device Information service
 *------------------------------------------------------------------------------
 */

#include "cb_comdefs.h"

/*==============================================================================
 * CONSTANTS
 *==============================================================================
 */
#define cbDEV_INFO_OK     0
#define cbDEV_INFO_ERROR -1

/*==============================================================================
 * TYPES
 *==============================================================================
 */

/*=============================================================================
 * EXPORTED FUNCTIONS
 *=============================================================================
 */
extern void  cbDEV_INFO_init(void);

extern cb_int32 cbDEV_INFO_register(
    cb_char *pManufacturer,
    cb_char *pModel,
    cb_char *pFwVersion,
    cb_uint16 startIndex);


extern cb_int32 cbDEV_INFO_getNbrOfAttributes(void);

#endif
