#pragma once

#include "Std_Types.h"
#include "Compiler_Cfg_Swc_EcuM.h"

class class_Swc_EcuM{
   public:
      FUNC(void, SWC_ECUM_CODE) StartPreOs             (void);
      FUNC(void, SWC_ECUM_CODE) StartPostOs            (void);
      FUNC(void, SWC_ECUM_CODE) OffPreOs               (void);
      FUNC(void, SWC_ECUM_CODE) OffPostOs              (void);
      FUNC(void, SWC_ECUM_CODE) EnableWakeupSources    (void);
      FUNC(void, SWC_ECUM_CODE) GenerateRamHash        (void);
      FUNC(void, SWC_ECUM_CODE) CheckRamHash           (void);
      FUNC(void, SWC_ECUM_CODE) ErrorHook              (void);
};

extern class_Swc_EcuM Swc_EcuM;

