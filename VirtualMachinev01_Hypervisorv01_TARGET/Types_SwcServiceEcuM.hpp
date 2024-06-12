#pragma once
/******************************************************************************/
/* File   : Types_SwcServiceEcuM.hpp                                          */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
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
//TBD: Move to induviduell interface headers, if possible?
typedef uint32 Type_SwcServiceEcuM_tSourceWakeup;
typedef uint16 Type_SwcServiceEcuM_tModeShutdown;
typedef uint8  Type_SwcServiceEcuM_tCauseShutdown;

//TBD: Move to SwcApplEcuM?
typedef enum{
      SwcApplEcuM_eModeCoast_Start = 0x01U
   ,  SwcApplEcuM_eModeCoast_Stop  = 0x02U
   ,  SwcApplEcuM_eModeCoast_Over  = 0x03U
}Type_SwcApplEcuM_eModeCoast;

typedef enum{
      SwcServiceEcuM_eModeEcu_Off
   ,  SwcServiceEcuM_eModeEcu_Quiet
   ,  SwcServiceEcuM_eModeEcu_Full
   ,  SwcServiceEcuM_eModeEcu_Monitor
   ,  SwcServiceEcuM_eModeEcu_Wake
}Type_SwcServiceEcuM_eModesEcu;

typedef enum{
      SwcServiceEcuM_eEventEcu_None
   ,  SwcServiceEcuM_eEventEcu_IgnitionOff
   ,  SwcServiceEcuM_eEventEcu_IgnitionOn
   ,  SwcServiceEcuM_eEventEcu_POn
   ,  SwcServiceEcuM_eEventEcu_WakeUpByCan
   ,  SwcServiceEcuM_eEventEcu_WakeUpByTimer
   ,  SwcServiceEcuM_eEventEcu_TimeoutComm
   ,  SwcServiceEcuM_eEventEcu_VehicleStop
   ,  SwcServiceEcuM_eEventEcu_VehicleDrive
   ,  SwcServiceEcuM_eEventEcu_TimeoutCoast
   ,  SwcServiceEcuM_eEventEcu_DeepStop
   ,  SwcServiceEcuM_eEventEcu_Shutdown
}Type_SwcServiceEcuM_eEventsEcu;

typedef enum{
      SwcServiceEcuM_ePhaseInitClear
   ,  SwcServiceEcuM_ePhaseStartOsPre
   ,  SwcServiceEcuM_ePhaseStartOsPost
   ,  SwcServiceEcuM_ePhaseUp
   ,  SwcServiceEcuM_ePhaseShutdownOsPre
   ,  SwcServiceEcuM_ePhaseShutdownOsPost
   ,  SwcServiceEcuM_ePhaseSleep
}Type_SwcServiceEcuM_ePhase;

typedef enum{
      SwcServiceEcuM_eTargetShutdown_SLEEP
   ,  SwcServiceEcuM_eTargetShutdown_RESET
   ,  SwcServiceEcuM_eTargetShutdown_OFF
}Type_SwcServiceEcuM_eTargetShutdown;

typedef struct{
   Type_SwcServiceEcuM_eTargetShutdown eTargetShutdown;
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
//TBD: Move prototypes to respective interface headers
extern Type_SwcServiceEcuM_eModesEcu infSwcApplEcuM_eGetModeEcu(void);
extern void infSwcServiceEcuM_vSetEventEcu                   (Type_SwcServiceEcuM_eEventsEcu ucEvent);
extern void infSwcApplEcuMSwcApplDcm_vPrepareReset           (uint16 ushTimeout);
extern void infSwcApplEcuMSwcApplDcm_vPrepareBootloaderJump  (uint16 ushTimeout);
extern void infSwcApplEcuMSwcApplDcm_vPrepareSmartTesterJump (uint16 ushTimeout);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
