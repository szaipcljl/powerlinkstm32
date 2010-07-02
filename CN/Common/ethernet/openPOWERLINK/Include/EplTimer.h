/****************************************************************************

  (c) SYSTEC electronic GmbH, D-07973 Greiz, August-Bebel-Str. 29
      www.systec-electronic.com

  Project:      openPOWERLINK

  Description:  include file for Epl Timer-Module

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

                $RCSfile: EplTimer.h,v $

                $Author: D.Krueger $

                $Revision: 1.6 $  $Date: 2009/08/12 15:41:25 $

                $State: Exp $

                Build Environment:
                    GCC V3.4

  -------------------------------------------------------------------------

  Revision History:

  2006/07/06 k.t.:   start of the implementation


****************************************************************************/

#ifndef _EPLTIMER_H_
#define _EPLTIMER_H_

#include "EplInc.h"
#include "EplEvent.h"


//---------------------------------------------------------------------------
// const defines
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// typedef
//---------------------------------------------------------------------------

// type for timer handle
#if (TARGET_SYSTEM == _WIN32_)
typedef ULONG_PTR tEplTimerHdl;

#else

typedef unsigned long tEplTimerHdl;
#endif

typedef struct
{
    tEplEventSink   m_EventSink;
    union
    {
        DWORD           m_dwVal;
        void*           m_pVal;
    } m_Arg;
//    unsigned long   m_ulArg;    // d.k.: converted to unsigned long because
                                // it is never accessed as a pointer by the
                                // timer module and the data the
                                // pointer points to is not saved in any way.
                                // It is just a value. The user is responsible
                                // to store the data statically and convert
                                // the pointer between address spaces.

} tEplTimerArg;

typedef struct
{
    tEplTimerHdl    m_TimerHdl;
    union
    {
        DWORD           m_dwVal;
        void*           m_pVal;
    } m_Arg;
//    unsigned long   m_ulArg;    // d.k.: converted to unsigned long because
                                // it is never accessed as a pointer by the
                                // timer module and the data the
                                // pointer points to is not saved in any way.
                                // It is just a value.

} tEplTimerEventArg;

typedef tEplKernel (PUBLIC * tEplTimerkCallback) (
    tEplTimerEventArg* pEventArg_p);

//---------------------------------------------------------------------------
// function prototypes
//---------------------------------------------------------------------------


#endif  // #ifndef _EPLTIMER_H_

