#include "Std_Types.hpp"

#include "Types_SwcServiceComM.hpp"

#include "EcuM.hpp"
#include "EcuM_Cfg_SchM.hpp"
#include "Det.hpp"
#include "EcuM_Prv.hpp"

#define BOOT_TARGET_NOT_INITIALIZED                                            0
#define BOOT_TARGET_INITIALIZED                                                1

#define ECUM_START_SEC_CODE
#include "EcuM_Cfg_MemMap.hpp"
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetBootTarget(
   P2VAR(Type_SwcServiceEcuM_tBootTarget, AUTOMATIC, ECUM_APPL_DATA) target
){
   VAR(Std_ReturnType, AUTOMATIC) return_value_u8;
   if(NULL_PTR == target){
      (void)Det_ReportError(
            ECUM_MODULE_ID
         ,  ECUM_INSTANCE_ID
         ,  ECUM_GET_BOOT_APIID
         ,  ECUM_E_NULL_POINTER
      );
      return_value_u8 =  E_NOT_OK;
   }
   else{
      SchM_Enter_EcuM();
      if(BOOT_TARGET_NOT_INITIALIZED == EcuM_Lok_dataSelectedBootTargetInit_u8){
         *target = ECUM_BOOT_TARGET_OEM_BOOTLOADER;
      }
      else{
         *target = EcuM_Lok_dataSelectedBootTarget_u8;
      }
      SchM_Exit_EcuM();
      return_value_u8 =  E_OK;
   }
   return return_value_u8;
}

FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectBootTarget(
   VAR(Type_SwcServiceEcuM_tBootTarget, AUTOMATIC) target
){
   VAR(Std_ReturnType, AUTOMATIC) return_value_u8;
   if(
         (ECUM_BOOT_TARGET_APP            != target)
      && (ECUM_BOOT_TARGET_OEM_BOOTLOADER != target)
      && (ECUM_BOOT_TARGET_SYS_BOOTLOADER != target)
   ){
      (void)Det_ReportError(
            ECUM_MODULE_ID
         ,  ECUM_INSTANCE_ID
         ,  ECUM_SEL_BOOT_APIID
         ,  ECUM_E_INVALID_PAR
      );
      return_value_u8 = E_NOT_OK;
   }
   else{
      SchM_Enter_EcuM();
      EcuM_Lok_dataSelectedBootTarget_u8 = target;
      EcuM_Lok_dataSelectedBootTargetInit_u8 = BOOT_TARGET_INITIALIZED;
      SchM_Exit_EcuM();
      return_value_u8 = E_OK;
   }
   return return_value_u8;
}
#define ECUM_STOP_SEC_CODE
#include "EcuM_Cfg_MemMap.hpp"
