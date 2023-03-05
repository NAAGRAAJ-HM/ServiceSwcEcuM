/******************************************************************************/
/* File   : ServiceSwcEcuM.cpp                                                */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.hpp"

#include "ServiceSwcEcuM.hpp"
#include "infServiceSwcEcuM_ServiceStartUp.hpp"

#include "CalloutStubsServiceSwcEcuM.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
typedef struct{
         ServiceSwcEcuM_TypeShutdownTarget ShutdownTarget;
   const CfgServiceSwcEcuM_Type*           CfgServiceSwcEcuM_lptr;
         Std_TypeReturn                    bIsInitDone;
}ServiceSwcEcuM_TypeContext;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(ServiceSwcEcuM_TypeContext, SERVICESWCECUM_VAR) ServiceSwcEcuM_Context;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, SERVICESWCECUM_CODE) ServiceSwcEcuM_InitFunction(void){
#if(CfgServiceSwcEcuM_EnableInterrupts == STD_ON)
                                                   CalloutStubsServiceSwcEcuM_SetProgrammableInterrupts();
#endif
                                                   CalloutStubsServiceSwcEcuM_DriverInitZero();
   ServiceSwcEcuM_Context.CfgServiceSwcEcuM_lptr = CalloutStubsServiceSwcEcuM_PbConfigurationDetermine();
                                                   CalloutStubsServiceSwcEcuM_CheckPbConfiguration();
                                                   CalloutStubsServiceSwcEcuM_DriverInitOne(ServiceSwcEcuM_Context.CfgServiceSwcEcuM_lptr);
                                                   CalloutStubsServiceSwcEcuM_SetDefinedMcuWakeupSource();

   ServiceSwcEcuM_Context.ShutdownTarget.Mode                         = ServiceSwcEcuM_Context.CfgServiceSwcEcuM_lptr->DefaultShutdownTarget.Mode;
   ServiceSwcEcuM_Context.ShutdownTarget.Target                       = ServiceSwcEcuM_Context.CfgServiceSwcEcuM_lptr->DefaultShutdownTarget.Target;
   ServiceSwcEcuM_Context.ShutdownTarget.Cause                        = ServiceSwcEcuM_Context.CfgServiceSwcEcuM_lptr->DefaultShutdownTarget.Cause;
   ServiceSwcEcuM_Context.ShutdownTarget.ValidatedWakeupEvents.bReset = 1;
   ServiceSwcEcuM_Context.bIsInitDone                                 = E_OK;

                                                   CalloutStubsServiceSwcEcuM_SwitchOsAppMode();
                                                   CalloutStubsServiceSwcEcuM_StartOs();
}

FUNC(void, SERVICESWCECUM_CODE) ServiceSwcEcuM_DeInitFunction(void){
   // TBD: ReSim.DeInitFunction();
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

