#pragma once
/******************************************************************************/
/* File   : ServiceSwcEcuM.hpp                                                */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "ConstServiceSwcEcuM.hpp"
#include "CfgServiceSwcEcuM.hpp"
#include "ServiceSwcEcuM_core.hpp"
#include "infServiceSwcEcuM_Exp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_ServiceSwcEcuM:
      INTERFACES_EXPORTED_SERVICESWCECUM
   ,  public abstract_module
   ,  public class_ServiceSwcEcuM_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
      const ConstServiceSwcEcuM_Type* lptrConst = (ConstServiceSwcEcuM_Type*)NULL_PTR;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
   private:
      FUNC(void, SERVICESWCECUM_CODE) DriverInitZero (void);
      FUNC(void, SERVICESWCECUM_CODE) DriverInitOne  (void);

   public:
      FUNC(void, SERVICESWCECUM_CODE) InitFunction(
            CONSTP2CONST(ConstModule_TypeAbstract, SERVICESWCECUM_CONST,       SERVICESWCECUM_APPL_CONST) lptrConstModule
         ,  CONSTP2CONST(CfgModule_TypeAbstract,   SERVICESWCECUM_CONFIG_DATA, SERVICESWCECUM_APPL_CONST) lptrCfgModule
      );
      FUNC(void, SERVICESWCECUM_CODE) DeInitFunction (void);
      FUNC(void, SERVICESWCECUM_CODE) MainFunction   (void);
      SERVICESWCECUM_CORE_FUNCTIONALITIES
};

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
extern VAR(module_ServiceSwcEcuM, SERVICESWCECUM_VAR) ServiceSwcEcuM;

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

