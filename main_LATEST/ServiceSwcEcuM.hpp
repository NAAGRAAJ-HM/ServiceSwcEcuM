#pragma once
/******************************************************************************/
/* File   : ServiceSwcEcuM.hpp                                                */
/*                                                                            */
/* Author : Nagaraja HULIYAPURADA MATA                                        */
/*                                                                            */
/* License / Warranty / Terms and Conditions                                  */
/*                                                                            */
/* Everyone is permitted to copy and distribute verbatim copies of this lice- */
/* nse document, but changing it is not allowed. This is a free, copyright l- */
/* icense for software and other kinds of works. By contrast, this license is */
/* intended to guarantee your freedom to share and change all versions of a   */
/* program, to make sure it remains free software for all its users. You have */
/* certain responsibilities, if you distribute copies of the software, or if  */
/* you modify it: responsibilities to respect the freedom of others.          */
/*                                                                            */
/* All rights reserved. Copyright © 1982 Nagaraja HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/NagarajaHuliyapuradaMata?tab=repositories               */
/*                                                                            */
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

