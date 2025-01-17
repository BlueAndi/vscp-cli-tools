/* The MIT License (MIT)
 *
 * Copyright (c) 2014 - 2025 Andreas Merkle
 * http://www.blue-andi.de
 * vscp@blue-andi.de
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

/*******************************************************************************
    DESCRIPTION
*******************************************************************************/
/**
@brief  Standard decision matrix XML parser
@file   dm_std_xml.h
@author Andreas Merkle, http://www.blue-andi.de

@section desc Description
This module contains an xml parser for a standard decision matrix format.

*******************************************************************************/
/** @defgroup dm_std_xml Standard decision matrix XML parser
 * Parse a standard decision matrix XML format.
 *
 * @{
 */

/*
 * Don't forget to set JAVADOC_AUTOBRIEF to YES in the doxygen file to generate
 * a correct module description.
 */

#ifndef __DM_STD_XML_H__
#define __DM_STD_XML_H__

/*******************************************************************************
    INCLUDES
*******************************************************************************/
#include <stdint.h>
#include "vscp_dm.h"

#if VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_ENABLE_DM )

#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
    COMPILER SWITCHES
*******************************************************************************/

/*******************************************************************************
    CONSTANTS
*******************************************************************************/

/*******************************************************************************
    MACROS
*******************************************************************************/

/*******************************************************************************
    TYPES AND STRUCTURES
*******************************************************************************/

/** This type defines the supported function return values. */
typedef enum
{
    DM_STD_XML_RET_OK = 0,  /**< Successful */
    DM_STD_XML_RET_ERROR,   /**< Failed */
    DM_STD_XML_RET_ENULL,   /**< Unexpected NULL pointer */
    DM_STD_XML_RET_EFILE    /**< File not found */

} DM_STD_XML_RET;

/*******************************************************************************
    VARIABLES
*******************************************************************************/

/*******************************************************************************
    FUNCTIONS
*******************************************************************************/

/**
 * This function initializes this module.
 */
extern void dm_std_xml_init(void);

/**
 * This function loads the content of a standard decision matrix xml file to the
 * specified memory location.
 *
 * @param[in]   fileName    Standard decision matrix xml file name
 * @param[out]  dm          Decision matrix storage
 * @param[in]   rows        Max. number of decision matrix rows in the storage
 * @return Status
 */
extern DM_STD_XML_RET dm_std_xml_load(char const * const fileName, vscp_dm_MatrixRow * const dm, uint8_t rows);

#ifdef __cplusplus
}
#endif

#endif  /* VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_ENABLE_DM ) */

#endif  /* __DM_STD_XML_H__ */

/** @} */
