#ifndef ECUM_H
#define ECUM_H

#include "EcuM_Types.hpp"
#include "EcuM_Generated_Types.hpp"
#include "EcuM_Cfg_Version.hpp"
#include "EcuM_Cbk.hpp"

#define ECUM_WKSTATUS_NONE                                                     0
#define ECUM_WKSTATUS_PENDING                                                  1
#define ECUM_WKSTATUS_VALIDATED                                                2
#define ECUM_WKSTATUS_EXPIRED                                                  3

#define Rte_Switch_currentMode_EcuM_Mode(data) (((VAR(Std_ReturnType, AUTOMATIC))RTE_E_OK))
#define RTE_E_OK                                            ((Std_ReturnType)0u)

extern VAR(Type_SwcServiceEcuM_stInfoTargetShutdown, ECUM_VAR_SAVED_ZONE0_UNSPECIFIED) EcuM_Rn_dataShutdownInfo_st;

extern FUNC(void, ECUM_CODE) infSwcServiceEcuMSwcServiceSchM_vMainFunction(void);
extern FUNC(void,     ECUM_CODE) EcuM_StartupTwo               (void);
extern FUNC(Std_ReturnType,     ECUM_CODE) EcuM_GoDown                   (VAR(uint16, AUTOMATIC) caller);
extern FUNC(void,     ECUM_CODE) EcuM_Shutdown                 (void);
extern FUNC(Type_SwcServiceEcuM_tSourceWakeup, ECUM_CODE) EcuM_GetValidatedWakeupEvents (void);
extern FUNC(Type_SwcServiceEcuM_tSourceWakeup, ECUM_CODE) EcuM_GetExpiredWakeupEvents   (void);
extern FUNC(Type_SwcServiceEcuM_tSourceWakeup, ECUM_CODE) EcuM_GetPendingWakeupEvents   (void);
extern FUNC(void ,     ECUM_CODE) EcuM_ClearWakeupEvent (  VAR(Type_SwcServiceEcuM_tSourceWakeup, AUTOMATIC) sources);
extern FUNC(void,     ECUM_CODE) EcuM_GetVersionInfo   (P2VAR(Std_VersionInfoType,     AUTOMATIC, ECUM_APPL_DATA) versioninfo);
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectBootTarget (  VAR(Type_SwcServiceEcuM_tBootTarget,     AUTOMATIC) target);
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetBootTarget    (P2VAR(Type_SwcServiceEcuM_tBootTarget,     AUTOMATIC, ECUM_APPL_DATA) target);

extern FUNC(Std_ReturnType, ECUM_CODE ) EcuM_GetShutdownTarget(
      P2VAR(Type_SwcServiceEcuM_eTargetShutdown, AUTOMATIC, ECUM_APPL_DATA) shutdownTarget
   ,  P2VAR(Type_SwcServiceEcuM_tModeShutdown,   AUTOMATIC, ECUM_APPL_DATA) shutdownMode
);

extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownTarget(
      VAR(Type_SwcServiceEcuM_eTargetShutdown, AUTOMATIC) shutdownTarget
   ,  VAR(Type_SwcServiceEcuM_tModeShutdown,   AUTOMATIC) shutdownMode
);

extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownCause(VAR(Type_SwcServiceEcuM_tCauseShutdown, AUTOMATIC) shutdownCause);

extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetShutdownCause(
   P2VAR(Type_SwcServiceEcuM_tCauseShutdown, AUTOMATIC, ECUM_APPL_DATA) shutdownCause
);

extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_Rn_NvMSingleBlockCallbackFunction (
      VAR(uint8, AUTOMATIC) ServiceId
   ,  VAR(uint8, AUTOMATIC) JobResult
);

#endif
