#include "Std_Types.hpp"

#include "Types_SwcServiceComM.hpp"

#include "CfgSwcServiceEcuM.hpp"
#include "EcuM.hpp"
#include "EcuM_Cfg_SchM.hpp"
#include "EcuM_RunTime.hpp"
#include "BswM_EcuM.hpp"
#include "CfgMcalMcu.hpp"
#include "ComM_EcuMBswM.hpp"
#include "Os.hpp"
#include "Det.hpp"

#include "EcuM_Callout.hpp"
#include "EcuM_Prv.hpp"

#define ECUM_START_SEC_VAR_POWER_ON_CLEARED_8
#include "EcuM_Cfg_MemMap.hpp"
VAR(Type_SwcServiceEcuM_tBootTarget,ECUM_VAR_POWER_ON_CLEARED_8)  EcuM_Lok_dataSelectedBootTarget_u8;
VAR(uint8,ECUM_VAR_POWER_ON_CLEARED_8)  EcuM_Lok_dataSelectedBootTargetInit_u8;
#define ECUM_STOP_SEC_VAR_POWER_ON_CLEARED_8
#include "EcuM_Cfg_MemMap.hpp"

#define ECUM_START_SEC_VAR_CLEARED_8
#include "EcuM_Cfg_MemMap.hpp"
VAR( uint8, ECUM_VAR_CLEARED_8 )  EcuM_Lok_SlaveCoreTimeoutCtr_u8;
VAR( Type_SwcServiceEcuM_tCauseShutdown, ECUM_VAR_CLEARED_8 )  EcuM_Lok_dataSelectedShutdownCause_u8 = 0;
#define ECUM_STOP_SEC_VAR_CLEARED_8
#include "EcuM_Cfg_MemMap.hpp"

#define ECUM_START_SEC_VAR_CLEARED_32
#include "EcuM_Cfg_MemMap.hpp"
VAR( Type_SwcServiceEcuM_tSourceWakeup, ECUM_VAR_CLEARED_32 ) EcuM_Lok_dataOldPendingWakeupEvents_u32;
VAR( Type_SwcServiceEcuM_tSourceWakeup, ECUM_VAR_CLEARED_32 ) EcuM_Lok_dataExpiredWakeupEvents_u32;
VAR( Type_SwcServiceEcuM_tSourceWakeup, ECUM_VAR_CLEARED_32 ) EcuM_Lok_dataClrWkpEventsInd_u32;
VAR( Type_SwcServiceEcuM_tSourceWakeup, ECUM_VAR_CLEARED_32 ) EcuM_Lok_dataPndWkpEventsInd_u32;
VAR( Type_SwcServiceEcuM_tSourceWakeup, ECUM_VAR_CLEARED_32 )EcuM_Lok_dataExpWkpEventsInd_u32;
#define ECUM_STOP_SEC_VAR_CLEARED_32
#include "EcuM_Cfg_MemMap.hpp"

#define ECUM_START_SEC_VAR_CLEARED_16
#include "EcuM_Cfg_MemMap.hpp"
VAR( uint16, ECUM_VAR_CLEARED_16 )  EcuM_Lok_WkpSrcValidationTimeoutCtr_u16;
#define ECUM_STOP_SEC_VAR_CLEARED_16
#include "EcuM_Cfg_MemMap.hpp"

#define ECUM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#include "EcuM_Cfg_MemMap.hpp"
VAR( Type_SwcServiceEcuM_stInfoTargetShutdown, ECUM_VAR_POWER_ON_CLEARED_UNSPECIFIED ) EcuM_Lok_dataShutdownInfo_st;
#define ECUM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#include "EcuM_Cfg_MemMap.hpp"

#define ECUM_START_SEC_VAR_CLEARED_BOOLEAN
#include "EcuM_Cfg_MemMap.hpp"
VAR( boolean, ECUM_VAR_CLEARED_BOOLEAN ) EcuM_Lok_flgIsStartupTwoCalled_ab[ECUM_CFG_NUM_OS_CORES];
VAR( boolean, ECUM_VAR_CLEARED_BOOLEAN ) EcuM_Lok_flgCoreReady_ab[ECUM_CFG_NUM_OS_CORES];
VAR(boolean, ECUM_VAR_CLEARED_BOOLEAN) EcuM_Lok_flgShutdownInfoDoNotUpdate_b;
VAR(boolean, ECUM_VAR_CLEARED_BOOLEAN) EcuM_Lok_flgGoDown_b;
VAR(boolean,ECUM_VAR_CLEARED_BOOLEAN)  EcuM_Lok_flgNvMReadStatus_b;
#define ECUM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "EcuM_Cfg_MemMap.hpp"

#define ECUM_START_SEC_CODE
#include "EcuM_Cfg_MemMap.hpp"
FUNC(void, ECUM_CODE ) EcuM_Lok_WakeupIndication(
   VAR(Type_SwcServiceEcuM_tSourceWakeup, AUTOMATIC) dataPendingWakeupEvents_u32
){
   VAR(uint8, AUTOMATIC) cntrLoopCtr_u8;
   VAR(uint8, AUTOMATIC) ctrLoopPNCNotify_u8;
   if(EcuM_Lok_dataPndWkpEventsInd_u32 != CfgSwcServiceEcuM_dSourceWakeupNone){
        BswM_EcuM_CurrentWakeup (EcuM_Lok_dataPndWkpEventsInd_u32, ECUM_WKSTATUS_PENDING);
   }
   if(SwcServiceEcuM_tSourceWakeup_ValInd !=CfgSwcServiceEcuM_dSourceWakeupNone){
      BswM_EcuM_CurrentWakeup(
            SwcServiceEcuM_tSourceWakeup_ValInd
         ,  ECUM_WKSTATUS_VALIDATED
      );
      for(
         cntrLoopCtr_u8 = 0;
         cntrLoopCtr_u8 < CfgSwcServiceEcuM_dNumSourceWakeup;
         cntrLoopCtr_u8 ++
      ){
            if(
                  ((CfgSwcServiceEcuM_castListInfoSourceWakeUp [cntrLoopCtr_u8].WakeupSourceId & SwcServiceEcuM_tSourceWakeup_ValInd)
                       != CfgSwcServiceEcuM_dSourceWakeupNone
                  )
               && (CfgSwcServiceEcuM_castListInfoSourceWakeUp[cntrLoopCtr_u8].IsComChannelPresent == TRUE)
            ){
                ComM_EcuM_WakeUpIndication(CfgSwcServiceEcuM_castListInfoSourceWakeUp[cntrLoopCtr_u8].ComChannelReferance);
            }
      }
   }
   if((EcuM_Lok_dataClrWkpEventsInd_u32 != CfgSwcServiceEcuM_dSourceWakeupNone) && ((EcuM_Lok_dataClrWkpEventsInd_u32 &
            (EcuM_Lok_dataPndWkpEventsInd_u32 | SwcServiceEcuM_tSourceWakeup_ValInd|EcuM_Lok_dataExpWkpEventsInd_u32)) ==
                    CfgSwcServiceEcuM_dSourceWakeupNone)){
        BswM_EcuM_CurrentWakeup (EcuM_Lok_dataClrWkpEventsInd_u32, ECUM_WKSTATUS_NONE);
   }
    SchM_Enter_EcuM();
    EcuM_Lok_dataPndWkpEventsInd_u32 = CfgSwcServiceEcuM_dSourceWakeupNone;
    SwcServiceEcuM_tSourceWakeup_ValInd = CfgSwcServiceEcuM_dSourceWakeupNone;
    EcuM_Lok_dataClrWkpEventsInd_u32 = CfgSwcServiceEcuM_dSourceWakeupNone;
    EcuM_Lok_dataExpWkpEventsInd_u32 = CfgSwcServiceEcuM_dSourceWakeupNone;
    SchM_Exit_EcuM();
   if(dataPendingWakeupEvents_u32 != (EcuM_Lok_dataOldPendingWakeupEvents_u32&dataPendingWakeupEvents_u32)){
        EcuM_StartWakeupSources (EcuM_Lok_dataOldPendingWakeupEvents_u32 ^ dataPendingWakeupEvents_u32);
   }
    EcuM_Lok_dataOldPendingWakeupEvents_u32 = dataPendingWakeupEvents_u32;
}

FUNC(void, ECUM_CODE) EcuM_Lok_DecValidationCtr(void){
   if(EcuM_Lok_WkpSrcValidationTimeoutCtr_u16 > 0){
        SchM_Enter_EcuM();
        EcuM_Lok_WkpSrcValidationTimeoutCtr_u16--;
        SchM_Exit_EcuM();
   }
}

FUNC(boolean, ECUM_CODE) EcuM_Lok_hasCheckWakeupSourceGetHandle_b( VAR(Type_SwcServiceEcuM_tSourceWakeup, AUTOMATIC)datasource_u32 ){
   VAR(boolean, AUTOMATIC) flgValidity_b = FALSE;
   if((datasource_u32 != CfgSwcServiceEcuM_dSourceWakeupNone) && ((ECUM_KNOWN_WAKEUP_SOURCES & datasource_u32) == datasource_u32) ){
      flgValidity_b = TRUE;
   }
   else{}
   return flgValidity_b;
}

FUNC(uint32, ECUM_CODE)EcuM_Lok_ComMWakeupHandling (VAR( Type_SwcServiceEcuM_tSourceWakeup, AUTOMATIC )  dataPendingWakeupEvents){
   VAR(uint32, AUTOMATIC) EcuM_CommchlWkupEvents_u32 = 0;
   VAR(uint8, AUTOMATIC) ctrLoop_u8 = 0;
   VAR(uint8, AUTOMATIC) ctrLoopPNCNotify_u8 = 0;
   for( ctrLoop_u8 = 0;ctrLoop_u8 < CfgSwcServiceEcuM_dNumSourceWakeup;ctrLoop_u8++ ){
        if( ( ( dataPendingWakeupEvents & CfgSwcServiceEcuM_castListInfoSourceWakeUp[ctrLoop_u8].WakeupSourceId ) != CfgSwcServiceEcuM_dSourceWakeupNone ) \
                && ( CfgSwcServiceEcuM_castListInfoSourceWakeUp[ctrLoop_u8].IsComChannelPresent == TRUE )
        ){
            ComM_EcuM_WakeUpIndication ( CfgSwcServiceEcuM_castListInfoSourceWakeUp[ctrLoop_u8].ComChannelReferance );
            EcuM_CommchlWkupEvents_u32 |= CfgSwcServiceEcuM_castListInfoSourceWakeUp[ctrLoop_u8].WakeupSourceId;
        }
        if( ( ( dataPendingWakeupEvents & CfgSwcServiceEcuM_castListInfoSourceWakeUp[ctrLoop_u8].WakeupSourceId ) != CfgSwcServiceEcuM_dSourceWakeupNone ) \
                && ( SwcServiceEcuM_pcstCfg->pcstListRefsPncWakeup[ctrLoop_u8].u8NumRefsPncComM > 0 )
        ){
        }
   }
    return EcuM_CommchlWkupEvents_u32;
}
#define ECUM_STOP_SEC_CODE
#include "EcuM_Cfg_MemMap.hpp"

