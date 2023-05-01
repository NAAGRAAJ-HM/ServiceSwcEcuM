/******************************************************************************/
/* File   : SwcServiceEcuM.cpp                                                */
/*                                                                            */
/* Author : Raajnaag HULIYAPURADA MATA                                        */
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
/* All rights reserved. Copyright © 1982 Raajnaag HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/RaajnaagHuliyapuradaMata?tab=repositories               */
/*                                                                            */
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

