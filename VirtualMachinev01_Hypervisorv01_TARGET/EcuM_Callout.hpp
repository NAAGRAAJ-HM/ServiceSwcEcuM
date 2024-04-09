#ifndef ECUM_CALLOUT_H
#define ECUM_CALLOUT_H

#include "EcuM_Cfg_Startup.hpp"

extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_ErrorHook                                (VAR(uint16, AUTOMATIC) reason);
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_OnGoOffOne                               (void);
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_OnGoOffTwo                               (void);
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_SwitchOff                             (void);
extern FUNC(void, ECUM_CALLOUT_CODE) SwcApplEcuM_vHandleReset                      (VAR(Type_McalMcu_eResetRequest,        AUTOMATIC) leResetRequest);
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_StartWakeupSources                       (VAR(Type_SwcServiceEcuM_tSourceWakeup, AUTOMATIC) wakeupSource);
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_StopWakeupSources                        (VAR(Type_SwcServiceEcuM_tSourceWakeup, AUTOMATIC) wakeupSource);
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_CheckValidation                          (VAR(Type_SwcServiceEcuM_tSourceWakeup, AUTOMATIC) wakeupSource);
extern FUNC(void, ECUM_CALLOUT_CODE) infSwcApplEcuMSwcServiceEcuM_vSwitchOsModeApp (void);

#endif

