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
#if(ECUM_CFG_MULTICORE_ENABLED       == STD_ON)
#if(ECUM_CFG_CCAS_INIT               == STD_OFF)
#if(ECUM_CFG_SLAVECORE_EARLIER_START == STD_ON)
      EcuM_Prv_StartSlaveCores();
#endif
#endif
   }
#endif
#if(ECUM_CFG_MULTICORE_ENABLED == STD_ON)
   if(
         ECUM_CFG_STARTUP_CORE
      == GetCoreID()
   ){
#endif
#if(ECUM_STARTUP_DURATION == TRUE)
      EcuM_Prv_dataSelectedShutdownTarget_st.TimeMeasured   = EcuM_Rb_adrConfigPtr_st->DefaultShutdownTarget.TimeMeasured;
#endif
#if(ECUM_CFG_MULTICORE_ENABLED == STD_ON)
#if(ECUM_CFG_CCAS_INIT == STD_OFF)
#if(ECUM_CFG_SLAVECORE_EARLIER_START == STD_OFF)
      EcuM_Prv_StartSlaveCores();
#endif
#endif
#endif
#if(ECUM_CFG_MULTICORE_ENABLED == STD_ON)
   }
#endif
#if(ECUM_CFG_CCAS_INIT == STD_OFF)
#endif
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
