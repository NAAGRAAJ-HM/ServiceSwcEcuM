/******************************************************************************/
/* File   : SwcServiceEcuM.c                                                  */
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
#include "Std_Types.h"

#include "Types_SwcServiceEcuM.h"
#include "CfgSwcServiceEcuM.h"
#include "infSwcServiceEcuMSwcServiceStartUp.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(Type_SwcServiceEcuM_ePhase, SWCSERVICEECUM_VAR) SwcServiceEcuM_ePhase;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, SWCSERVICEECUM_CODE) infSwcServiceEcuMSwcServiceStartUp_InitFunction(void){
#if(ECUM_CFG_MULTICORE_ENABLED == STD_ON)
   if(
         ECUM_CFG_STARTUP_CORE
      == GetCoreID()
   ){
#endif
      SwcServiceEcuM_ePhase = SwcServiceEcuM_ePhaseStartOsPre;
/*
#if(ECUM_INTERRUPTS_ENABLE == TRUE)
      EcuM_AL_SetProgrammableInterrupts();
#endif
      EcuM_AL_DriverInitZero();
      EcuM_Rb_adrConfigPtr_st = EcuM_DeterminePbConfiguration();
      EcuM_Prv_PBPointerConsistencyCheck();
*/
#if(ECUM_CFG_MULTICORE_ENABLED       == STD_ON)
#if(ECUM_CFG_CCAS_INIT               == STD_OFF)
#if(ECUM_CFG_SLAVECORE_EARLIER_START == STD_ON)
      EcuM_Prv_StartSlaveCores();
#endif
#endif
   }
#endif
//   EcuM_AL_DriverInitOne(EcuM_Rb_adrConfigPtr_st);
#if(ECUM_CFG_MULTICORE_ENABLED == STD_ON)
   if(
         ECUM_CFG_STARTUP_CORE
      == GetCoreID()
   ){
#endif
/*
      EcuM_Prv_SetDefinedMcuWakeupSource();
      EcuM_Prv_dataSelectedShutdownTarget_st.ShutdownTarget = EcuM_Rb_adrConfigPtr_st->DefaultShutdownTarget.ShutdownTarget;
      EcuM_Prv_dataSelectedShutdownTarget_st.mode           = EcuM_Rb_adrConfigPtr_st->DefaultShutdownTarget.mode;
      EcuM_Prv_dataSelectedShutdownTarget_st.ShutdownCause  = EcuM_Rb_adrConfigPtr_st->DefaultShutdownTarget.ShutdownCause;
*/
#if(ECUM_STARTUP_DURATION == TRUE)
      EcuM_Prv_dataSelectedShutdownTarget_st.TimeMeasured   = EcuM_Rb_adrConfigPtr_st->DefaultShutdownTarget.TimeMeasured;
#endif
/*
      if(
            ECUM_NO_WKUP_SRC
         == (
                  EcuM_Prv_dataPendingWakeupEvents_u32
               |  EcuM_Prv_dataValidatedWakeupEvents_u32
            )
      ){
         EcuM_Prv_dataValidatedWakeupEvents_u32 |= EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_RESET;
         EcuM_Prv_dataValWkpEventsInd_u32       |= EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_RESET;
      }
*/
#if(ECUM_CFG_MULTICORE_ENABLED == STD_ON)
#if(ECUM_CFG_CCAS_INIT == STD_OFF)
#if(ECUM_CFG_SLAVECORE_EARLIER_START == STD_OFF)
      EcuM_Prv_StartSlaveCores();
#endif
#endif
#endif
//      EcuM_Prv_flgIsModuleInitialised_b  = TRUE;
#if(ECUM_CFG_MULTICORE_ENABLED == STD_ON)
   }
#endif
//   EcuM_SwitchOsAppMode();
#if(ECUM_CFG_CCAS_INIT == STD_OFF)
//   EcuM_Prv_StartOS();
#endif
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
