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
@brief  VSCP helper library header compatibility wrapper.
@file   vscphelper_compat.h
@author Andreas Merkle, http://www.blue-andi.de

@section desc Description
Include this module instead of the VSCP helper library header vscphelperlib.h.

The vendored VSCP helper library headers (./common/vscphelper) are taken over
from the upstream release without modification. Since v15.2 they require two
workarounds, which are kept here in one place:

- vscp.h no longer includes canal.h, vscp-class.h and vscp-type.h. Users of
  vscphelperlib.h have to include them by themselves now.
- vscphelperlib.h declares parameters of type "struct canalMsg", but canal.h
  names the corresponding structure tag "structCanalMsg". The struct is
  therefore forward declared here, which keeps the build free of warnings.
  Note that the affected conversion functions cannot be called this way, but
  none of the CLI tools uses them.

*******************************************************************************/
/** @defgroup vscphelper_compat VSCP helper library header compatibility wrapper.
 * Include this module instead of the VSCP helper library header vscphelperlib.h.
 * @{
 */

/*
 * Don't forget to set JAVADOC_AUTOBRIEF to YES in the doxygen file to generate
 * a correct module description.
 */

#ifndef __VSCPHELPER_COMPAT_H__
#define __VSCPHELPER_COMPAT_H__

/*******************************************************************************
    INCLUDES
*******************************************************************************/
#include "canal.h"
#include "vscp.h"
#include "vscp-class.h"
#include "vscp-type.h"

/** Referenced by vscphelperlib.h, but not declared with this tag by canal.h. */
struct canalMsg;

#include "vscphelperlib.h"

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

/*******************************************************************************
    VARIABLES
*******************************************************************************/

/*******************************************************************************
    FUNCTIONS
*******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif  /* __VSCPHELPER_COMPAT_H__ */

/** @} */
