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
      INTERFACES_EXPORTED_SWCSERVICEECUM
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
      FUNC(void, SWCSERVICEECUM_CODE) DriverInitZero (void);
      FUNC(void, SWCSERVICEECUM_CODE) DriverInitOne  (void);

   public:
      FUNC(void, SWCSERVICEECUM_CODE) InitFunction(
            CONSTP2CONST(ConstModule_TypeAbstract, SWCSERVICEECUM_CONST,       SWCSERVICEECUM_APPL_CONST) lptrConstModule
         ,  CONSTP2CONST(CfgModule_TypeAbstract,   SWCSERVICEECUM_CONFIG_DATA, SWCSERVICEECUM_APPL_CONST) lptrCfgModule
      );
      FUNC(void, SWCSERVICEECUM_CODE) DeInitFunction (void);
      FUNC(void, SWCSERVICEECUM_CODE) MainFunction   (void);
      SWCSERVICEECUM_CORE_FUNCTIONALITIES
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
extern VAR(module_ServiceSwcEcuM, SWCSERVICEECUM_VAR) ServiceSwcEcuM;

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

