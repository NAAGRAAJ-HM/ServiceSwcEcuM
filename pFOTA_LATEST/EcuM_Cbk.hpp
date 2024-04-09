

#ifndef ECUM_CBK_H
#define ECUM_CBK_H

#include "Std_Types.hpp"
#include "Types_CfgSwcServiceEcuM.hpp"

FUNC(void, ECUM_CODE) EcuM_SetWakeupEvent( EcuM_WakeupSourceType WakeupSource );
FUNC(void, ECUM_CODE) EcuM_CheckWakeup( EcuM_WakeupSourceType WakeupSource );

#endif

