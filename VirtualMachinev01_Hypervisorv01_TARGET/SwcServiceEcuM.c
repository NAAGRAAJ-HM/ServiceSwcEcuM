/******************************************************************************/
/* File   : SwcServiceEcuM.c                                                  */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.hpp"

#include "Types_SwcServiceEcuM.hpp"
#include "CfgSwcServiceEcuM.hpp"
#include "infSwcServiceEcuMSwcServiceStartUp.hpp"

#include "infSwcApplEcuMSwcServiceEcuM.hpp"

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
P2CONST(Type_CfgSwcServiceEcuM_st,                SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONFIG_DATA) SwcServiceEcuM_pcstCfg;
    VAR(Type_SwcServiceEcuM_tSourceWakeup,        SWCSERVICEECUM_VAR)                             SwcServiceEcuM_tSourceWakeup_EventsPending;
    VAR(Type_SwcServiceEcuM_tSourceWakeup,        SWCSERVICEECUM_VAR)                             SwcServiceEcuM_tSourceWakeup_Validated;
    VAR(Type_SwcServiceEcuM_tSourceWakeup,        SWCSERVICEECUM_VAR)                             SwcServiceEcuM_tSourceWakeup_ValInd;
    VAR(Type_SwcServiceEcuM_stInfoTargetShutdown, SWCSERVICEECUM_VAR)                             SwcServiceEcuM_stInfoTargetShutdown;
    VAR(Type_SwcServiceEcuM_ePhase,               SWCSERVICEECUM_VAR)                             SwcServiceEcuM_ePhase;
    VAR(boolean,                                  SWCSERVICEECUM_VAR)                             SwcServiceEcuM_bIsInitialised;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, SWCSERVICEECUM_CODE) infSwcServiceEcuMSwcServiceStartUp_InitFunction(void){
   SwcServiceEcuM_ePhase = SwcServiceEcuM_ePhaseStartOsPre;
   infSwcApplEcuMSwcServiceEcuM_vSetInterruptsProgrammable();
   infSwcApplEcuMSwcServiceEcuM_vInitDriverZero();
   SwcServiceEcuM_pcstCfg = infSwcApplEcuMSwcServiceEcuM_stDetermineConfigurationPb();
   infSwcApplEcuMSwcServiceEcuM_vCheckConsistency();
   infSwcApplEcuMSwcServiceEcuM_vInitDriverOne(SwcServiceEcuM_pcstCfg);
   infSwcApplEcuMSwcServiceEcuM_vSetSourceWakeup();

   SwcServiceEcuM_stInfoTargetShutdown.eTargetShutdown = SwcServiceEcuM_pcstCfg->stInfoTargetShutdownDefault.eTargetShutdown;
   SwcServiceEcuM_stInfoTargetShutdown.mode            = SwcServiceEcuM_pcstCfg->stInfoTargetShutdownDefault.mode;
   SwcServiceEcuM_stInfoTargetShutdown.tCauseShutdown  = SwcServiceEcuM_pcstCfg->stInfoTargetShutdownDefault.tCauseShutdown;

   if(
         CfgSwcServiceEcuM_dSourceWakeupNone
      == (
               SwcServiceEcuM_tSourceWakeup_EventsPending
            |  SwcServiceEcuM_tSourceWakeup_Validated
         )
   ){
      SwcServiceEcuM_tSourceWakeup_Validated |= CfgSwcServiceEcuM_dRESET;
      SwcServiceEcuM_tSourceWakeup_ValInd    |= CfgSwcServiceEcuM_dRESET;
   }
   SwcServiceEcuM_bIsInitialised  = TRUE;

   infSwcApplEcuMSwcServiceEcuM_vSwitchOsModeApp();
   infSwcApplEcuMSwcServiceEcuM_vStartOS();
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
