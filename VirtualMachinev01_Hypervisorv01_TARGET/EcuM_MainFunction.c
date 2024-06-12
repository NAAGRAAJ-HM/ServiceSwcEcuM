#include "Std_Types.hpp"

#include "Types_SwcServiceComM.hpp"

#include "EcuM.hpp"
#include "EcuM_Callout.hpp"
#include "EcuM_Cfg_SchM.hpp"
#include "BswM_EcuM.hpp"
#include "Rte_Main.hpp"
#include "Det.hpp"
#include "Os.hpp"
#include "EcuM_Prv.hpp"

#define ECUM_START_SEC_CODE
#include "EcuM_Cfg_MemMap.hpp"
static FUNC(void, ECUM_CODE ) EcuM_Lok_ProceedShutdown(void);
static FUNC(void, ECUM_CODE ) EcuM_Lok_WakeupValidation(void);
static FUNC(Std_ReturnType, ECUM_CODE ) EcuM_Lok_ShutdownSynchronization(void);

FUNC(void, ECUM_CODE) infSwcServiceEcuMSwcServiceSchM_vMainFunction(void){
   if(FALSE ==  SwcServiceEcuM_bIsInitialised){
      (void)Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_MAIN_FUNC_APIID, ECUM_E_UNINIT);
   }
   else if(E_NOT_OK ==  EcuM_Lok_ShutdownSynchronization()){
      SwcServiceEcuM_ePhase = SwcServiceEcuM_ePhaseUp;
      EcuM_Lok_WakeupValidation();
   }
   else{
   }
   return;
}

static FUNC(void, ECUM_CODE) EcuM_Lok_ProceedShutdown(void){
   EcuM_OnGoOffOne();
   BswM_Deinit();
   SchM_Deinit();
   ShutdownOS(E_OS_SYS_NO_RESTART);
}

static FUNC(void, ECUM_CODE) EcuM_Lok_WakeupValidation(void){
   VAR(uint8, AUTOMATIC) cntrLoopCtr_u8;
   VAR(Type_SwcServiceEcuM_tSourceWakeup, AUTOMATIC) dataPendingWakeupEvents_u32;
   VAR( uint16, ECUM_VAR) datawkpSrcValidationTimeoutCtr_u16;
        SchM_Enter_EcuM();
        dataPendingWakeupEvents_u32 = SwcServiceEcuM_tSourceWakeup_EventsPending;
        datawkpSrcValidationTimeoutCtr_u16 = EcuM_Lok_WkpSrcValidationTimeoutCtr_u16;
        SchM_Exit_EcuM();
        EcuM_Lok_WakeupIndication(dataPendingWakeupEvents_u32);
        if(EcuM_Lok_dataOldPendingWakeupEvents_u32 != CfgSwcServiceEcuM_dSourceWakeupNone){
            for(
               cntrLoopCtr_u8 = 0;
               cntrLoopCtr_u8 < CfgSwcServiceEcuM_dNumSourceWakeup;
               cntrLoopCtr_u8 ++
            ){
                if((CfgSwcServiceEcuM_castListInfoSourceWakeUp[cntrLoopCtr_u8].WakeupSourceId & EcuM_Lok_dataOldPendingWakeupEvents_u32) != CfgSwcServiceEcuM_dSourceWakeupNone){
                    EcuM_CheckValidation (CfgSwcServiceEcuM_castListInfoSourceWakeUp[cntrLoopCtr_u8].WakeupSourceId);
                }
                if((CfgSwcServiceEcuM_castListInfoSourceWakeUp[cntrLoopCtr_u8].WakeupSourceId &
                        SwcServiceEcuM_tSourceWakeup_Validated) != CfgSwcServiceEcuM_dSourceWakeupNone)
                {
                    SchM_Enter_EcuM();
                    EcuM_Lok_dataOldPendingWakeupEvents_u32 = SwcServiceEcuM_tSourceWakeup_EventsPending;
                     SchM_Exit_EcuM();
                }
            }
        }
   if(
         (datawkpSrcValidationTimeoutCtr_u16 == 0)
      && (
               (
                     EcuM_Lok_dataOldPendingWakeupEvents_u32
                  &  dataPendingWakeupEvents_u32
               )
            != CfgSwcServiceEcuM_dSourceWakeupNone
         )
   ){
        SchM_Enter_EcuM();
        EcuM_Lok_dataExpiredWakeupEvents_u32 ^= EcuM_Lok_dataOldPendingWakeupEvents_u32 ;
        SwcServiceEcuM_tSourceWakeup_EventsPending ^= EcuM_Lok_dataOldPendingWakeupEvents_u32;
        EcuM_Lok_dataOldPendingWakeupEvents_u32 = CfgSwcServiceEcuM_dSourceWakeupNone;
        SchM_Exit_EcuM();
        BswM_EcuM_CurrentWakeup ( EcuM_Lok_dataExpiredWakeupEvents_u32 , ECUM_WKSTATUS_EXPIRED);
        EcuM_StopWakeupSources (EcuM_Lok_dataExpiredWakeupEvents_u32 );
   }
    EcuM_Lok_DecValidationCtr();
    return;
}

static FUNC(Std_ReturnType, ECUM_CODE) EcuM_Lok_ShutdownSynchronization(void){
   VAR(Std_ReturnType, AUTOMATIC) return_value = E_NOT_OK;
        if(FALSE != EcuM_Lok_flgGoDown_b){
            EcuM_Lok_ProceedShutdown();
            return_value = E_OK;
        }
        else{
        }
    return return_value;
}

#define ECUM_STOP_SEC_CODE
#include "EcuM_Cfg_MemMap.hpp"
