#ifndef ECUM_PRV_RTEACTIONS_H
#define ECUM_PRV_RTEACTIONS_H

#include "EcuM_Types.hpp"

//TBD: Other header file
extern FUNC(void, ECUM_CODE) EcuM_Lok_RteModeSwitch ( VAR(Rte_ModeType_EcuM_Mode, AUTOMATIC) Mode);
extern FUNC(uint8, ECUM_CODE ) EcuM_Lok_GetRteMode(void);

#endif
