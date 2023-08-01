#pragma once
/******************************************************************************/
/* File   : Types_SwcServiceEcuM.h                                            */
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

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
typedef enum{
      SwcServiceEcuM_ePhaseInitClear
   ,  SwcServiceEcuM_ePhaseStartOsPre
   ,  SwcServiceEcuM_ePhaseStartOsPost
   ,  SwcServiceEcuM_ePhaseUp
   ,  SwcServiceEcuM_ePhaseShutdownOsPre
   ,  SwcServiceEcuM_ePhaseShutdownOsPost
   ,  SwcServiceEcuM_ePhaseSleep
}Type_SwcServiceEcuM_ePhase;

typedef uint8  Type_SwcServiceEcuM_tTargetShutdown;
typedef uint8  Type_SwcServiceEcuM_tCauseShutdown;
typedef uint16 Type_SwcServiceEcuM_tModeShutdown;

typedef struct{
   Type_SwcServiceEcuM_tTargetShutdown tTargetShutdown;
   Type_SwcServiceEcuM_tCauseShutdown  tCauseShutdown;
   Type_SwcServiceEcuM_tModeShutdown   mode;
}Type_SwcServiceEcuM_stInfoTargetShutdown;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
