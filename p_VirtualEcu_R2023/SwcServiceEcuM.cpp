/******************************************************************************/
/* File   : SwcServiceEcuM.cpp                                                */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.hpp"

#include "SwcServiceEcuM.hpp"
#include "CalloutStubsSwcServiceEcuM.hpp"
#include "infSwcServiceEcuMSwcServiceStartUp.hpp"

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
         SwcServiceEcuM_TypeShutdownTarget ShutdownTarget;
   const CfgSwcServiceEcuM_Type*           CfgSwcServiceEcuM_lptr;
         Std_TypeReturn                    bIsInitDone;
}SwcServiceEcuM_TypeContext;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(SwcServiceEcuM_TypeContext, SWCSERVICEECUM_VAR) SwcServiceEcuM_Context;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, SWCSERVICEECUM_CODE) infSwcServiceEcuMSwcServiceStartUp_InitFunction(void){
#if(CfgSwcServiceEcuM_EnableInterrupts == STD_ON)
                                                   CalloutStubsSwcServiceEcuM_SetProgrammableInterrupts();
#endif
                                                   CalloutStubsSwcServiceEcuM_DriverInitZero();
   SwcServiceEcuM_Context.CfgSwcServiceEcuM_lptr = CalloutStubsSwcServiceEcuM_PbConfigurationDetermine();
                                                   CalloutStubsSwcServiceEcuM_CheckPbConfiguration();
                                                   CalloutStubsSwcServiceEcuM_DriverInitOne(SwcServiceEcuM_Context.CfgSwcServiceEcuM_lptr);
                                                   CalloutStubsSwcServiceEcuM_SetDefinedMcuWakeupSource();

   SwcServiceEcuM_Context.ShutdownTarget.Mode                         = SwcServiceEcuM_Context.CfgSwcServiceEcuM_lptr->DefaultShutdownTarget.Mode;
   SwcServiceEcuM_Context.ShutdownTarget.Target                       = SwcServiceEcuM_Context.CfgSwcServiceEcuM_lptr->DefaultShutdownTarget.Target;
   SwcServiceEcuM_Context.ShutdownTarget.Cause                        = SwcServiceEcuM_Context.CfgSwcServiceEcuM_lptr->DefaultShutdownTarget.Cause;
   SwcServiceEcuM_Context.ShutdownTarget.ValidatedWakeupEvents.bReset = 1;
   SwcServiceEcuM_Context.bIsInitDone                                 = E_OK;

                                                   CalloutStubsSwcServiceEcuM_SwitchOsAppMode();
                                                   CalloutStubsSwcServiceEcuM_StartOs();
}

FUNC(void, SWCSERVICEECUM_CODE) infSwcServiceEcuMSwcServiceStartUp_DeInitFunction(void){
   // TBD: ReSim.DeInitFunction();
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

