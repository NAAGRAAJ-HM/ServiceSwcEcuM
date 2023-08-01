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
P2CONST(Type_CfgSwcServiceEcuM_st, SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONFIG_DATA) SwcServiceEcuM_pcstCfg;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, SWCAPPLECUM_CODE) infSwcApplEcuMSwcServiceEcuM_SetInterruptsProgrammable(void){
}

FUNC(void, SWCAPPLECUM_CODE) infSwcApplEcuMSwcServiceEcuM_InitDriverZero(void){
}

FUNC(const Type_CfgSwcServiceEcuM_st*, SWCAPPLECUM_CODE) infSwcApplEcuMSwcServiceEcuM_DetermineConfigurationPb(void){
   return 0;
}

FUNC(void, SWCSERVICEECUM_CODE) infSwcServiceEcuMSwcServiceStartUp_InitFunction(void){
   SwcServiceEcuM_ePhase = SwcServiceEcuM_ePhaseStartOsPre;
   infSwcApplEcuMSwcServiceEcuM_SetInterruptsProgrammable();
   infSwcApplEcuMSwcServiceEcuM_InitDriverZero();
   SwcServiceEcuM_pcstCfg = infSwcApplEcuMSwcServiceEcuM_DetermineConfigurationPb();
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
