/******************************************************************************/
/* File   : SwcServiceEcuM.cpp                                                */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.hpp"

#include "SwcServiceEcuM.hpp"
#include "infSwcServiceEcuMSwcServiceOs.hpp"
#include "infSwcServiceEcuMSwcServiceStartUp.hpp"

#include "CfgSwcServiceEcuM.hpp"
#include "CalloutStubsSwcServiceEcuM.hpp"
#include "infSwcServiceOsSwcServiceEcuM.hpp"

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
         SwcServiceEcuM_tstTargetShutdown ShutdownTarget;
   const CfgSwcServiceEcuM_tst*           CfgSwcServiceEcuM_lptr;
         Std_TypeReturn                   bIsInitDone;
}SwcServiceEcuM_tstContext;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(SwcServiceEcuM_tstContext, SWCSERVICEECUM_VAR) SwcServiceEcuM_Context;

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
                                                   CalloutStubsSwcServiceEcuM_SetDefinedMcuWakeupSource();

   SwcServiceEcuM_Context.ShutdownTarget.Mode                         = SwcServiceEcuM_Context.CfgSwcServiceEcuM_lptr->DefaultShutdownTarget.Mode;
   SwcServiceEcuM_Context.ShutdownTarget.Target                       = SwcServiceEcuM_Context.CfgSwcServiceEcuM_lptr->DefaultShutdownTarget.Target;
   SwcServiceEcuM_Context.ShutdownTarget.Cause                        = SwcServiceEcuM_Context.CfgSwcServiceEcuM_lptr->DefaultShutdownTarget.Cause;
   SwcServiceEcuM_Context.ShutdownTarget.ValidatedWakeupEvents.bReset = 1;
   SwcServiceEcuM_Context.bIsInitDone                                 = E_OK;

   CalloutStubsSwcServiceEcuM_SwitchOsAppMode();
   infSwcServiceOsSwcServiceEcuM_Start();
}

FUNC(void, SWCSERVICEECUM_CODE) infSwcServiceEcuMSwcServiceOs_StartupTwo(void){
   CalloutStubsSwcServiceEcuM_DriverInitOne(SwcServiceEcuM_Context.CfgSwcServiceEcuM_lptr);
}

FUNC(void, SWCSERVICEECUM_CODE) infSwcServiceEcuMSwcServiceOs_Shutdown(void){
   CalloutStubsSwcServiceEcuM_Shutdown();
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

