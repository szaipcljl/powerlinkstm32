/****************************************************************************

  (c) SYSTEC electronic GmbH, D-07973 Greiz, August-Bebel-Str. 29
      www.systec-electronic.com

  Project:      openPOWERLINK

  Description:  include file for CFM module

  License:

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.

    3. Neither the name of SYSTEC electronic GmbH nor the names of its
       contributors may be used to endorse or promote products derived
       from this software without prior written permission. For written
       permission, please contact info@systec-electronic.com.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
    FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
    COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
    ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.

    Severability Clause:

        If a provision of this License is or becomes illegal, invalid or
        unenforceable in any jurisdiction, that shall not affect:
        1. the validity or enforceability in that jurisdiction of any other
           provision of this License; or
        2. the validity or enforceability in other jurisdictions of that or
           any other provision of this License.

  -------------------------------------------------------------------------

                $RCSfile: EplCfmu.h,v $

                $Author: D.Krueger $

                $Revision: 1.3 $  $Date: 2010/01/14 12:58:03 $

                $State: Exp $

                Build Environment:
                    GCC V3.4

  -------------------------------------------------------------------------

  Revision History:

  2009/12/14 d.k.:   start of the implementation


****************************************************************************/

#ifndef _EPLCFMU_H_
#define _EPLCFMU_H_

#if (((EPL_MODULE_INTEGRATION) & (EPL_MODULE_CFM)) != 0)

#include "EplNmt.h"
#include "EplCfm.h"

/***************************************************************************/
/*                                                                         */
/*                                                                         */
/*          G L O B A L   D E F I N I T I O N S                            */
/*                                                                         */
/*                                                                         */
/***************************************************************************/

//---------------------------------------------------------------------------
// const defines
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// typedef
//---------------------------------------------------------------------------


typedef tEplKernel (PUBLIC* tEplCfmCbEventCnProgress)
(tEplCfmEventCnProgress* pEventCnProgress_p);


typedef tEplKernel (PUBLIC* tEplCfmCbEventCnResult) (unsigned int uiNodeId_p, tEplNmtNodeCommand NodeCommand_p);



//---------------------------------------------------------------------------
// function prototypes
//---------------------------------------------------------------------------

tEplKernel EplCfmuAddInstance(tEplCfmCbEventCnProgress pfnCbEventCnProgress_p, tEplCfmCbEventCnResult pfnCbEventCnResult_p);

tEplKernel EplCfmuDelInstance(void);

tEplKernel EplCfmuProcessNodeEvent(unsigned int uiNodeId_p, tEplNmtNodeEvent NodeEvent_p);

BOOL EplCfmuIsSdoRunning(unsigned int uiNodeId_p);


#endif

#endif // _EPLCFMU_H_
