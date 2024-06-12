#include "Std_Types.hpp"

#include "Types_SwcServiceComM.hpp"

#include "EcuM.hpp"
#include "EcuM_Callout.hpp"
#include "EcuM_Cfg_SchM.hpp"
#include "Rte_Main.hpp"
#include "Os.hpp"
#include "BswM.hpp"
#include "NvM.hpp"
#include "Det.hpp"
#include "EcuM_Prv.hpp"

#define ECUM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
#include "EcuM_Cfg_MemMap.hpp"
VAR( Type_SwcServiceEcuM_stInfoTargetShutdown, ECUM_VAR_SAVED_ZONE0_UNSPECIFIED ) EcuM_Rn_dataShutdownInfo_st;
#define ECUM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
#include "EcuM_Cfg_MemMap.hpp"

#define ECUM_START_SEC_CODE
#include "EcuM_Cfg_MemMap.hpp"
FUNC(void, ECUM_CODE) EcuM_StartupTwo(void){
   if(TRUE == SwcServiceEcuM_bIsInitialised){
      if(FALSE == EcuM_Lok_flgIsStartupTwoCalled_ab[0]){
        SwcServiceEcuM_ePhase = SwcServiceEcuM_ePhaseStartOsPost;
        EcuM_Lok_flgIsStartupTwoCalled_ab[0] = TRUE;
        SchM_Init();
        BswM_Init(SwcServiceEcuM_pcstCfg->stRefCfgModules.pcstCfgSwcServiceBswM);
   }
   else{
   }
        }
   else{
         (void)Det_ReportError(
               ECUM_MODULE_ID
            ,  ECUM_INSTANCE_ID
            ,  ECUM_START_TWO_APIID
            ,  ECUM_E_UNINIT
         );
         return;
     }
}

FUNC(Std_ReturnType, ECUM_CODE) EcuM_Rn_NvMSingleBlockCallbackFunction(
      VAR(uint8, AUTOMATIC) ServiceId
   ,  VAR(uint8, AUTOMATIC) JobResult
){
   VAR(Std_ReturnType, AUTOMATIC) returnvalue_u8 = E_NOT_OK;
   if(
         (ServiceId == 0x0c)
      && (JobResult == NVM_REQ_OK)
   ){
        EcuM_Lok_flgNvMReadStatus_b=TRUE;
        EcuM_Lok_dataShutdownInfo_st=EcuM_Rn_dataShutdownInfo_st;
        EcuM_Rn_dataShutdownInfo_st=SwcServiceEcuM_stInfoTargetShutdown;
        (void)NvM_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_ECUM_CFG_NVM_BLOCK,TRUE);
         returnvalue_u8   =   E_OK;
   }
   else if(
         (ServiceId == 0x13)
      && (JobResult == NVM_REQ_OK)
   ){
        returnvalue_u8   =   E_OK;
   }
   else{
   }
    return returnvalue_u8;
}
#define ECUM_STOP_SEC_CODE
#include "EcuM_Cfg_MemMap.hpp"
