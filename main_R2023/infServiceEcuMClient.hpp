#pragma once
/******************************************************************************/
/* File   : infServiceEcuMClient.hpp                                                 */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.hpp"
#include "CompilerCfg_ServiceSwcEcuM.hpp"

#include "ConstModule.hpp"
#include "CfgModule.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class infServiceEcuMClient{
   public:
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
      virtual FUNC(void, SERVICESWCECUM_CODE) InitFunction(
            CONSTP2CONST(ConstModule_TypeAbstract, SERVICESWCECUM_CONST,       SERVICESWCECUM_APPL_CONST) lptrNvMBlocksRomModule
         ,  CONSTP2CONST(CfgModule_TypeAbstract,   SERVICESWCECUM_CONFIG_DATA, SERVICESWCECUM_APPL_CONST) lptrCfgModule
      ) = 0;

      virtual FUNC(void, SERVICESWCECUM_CODE) DeInitFunction (void) = 0;
};

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

