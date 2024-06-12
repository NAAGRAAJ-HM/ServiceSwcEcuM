#include "Std_Types.hpp"

#include "Types_SwcServiceComM.hpp"

#include "EcuM.hpp"
#include "EcuM_Callout.hpp"
#include "EcuM_RunTime.hpp"
#include "EcuM_Prv.hpp"
#include "Dem.hpp"
#include "ApplVect.hpp"
#include "Wdt.hpp"

uint8* __attribute__ ((section (".rdata"))) pClear;
uint32 __attribute__ ((section (".rdata"))) ulRamStart;
uint32 __attribute__ ((section (".rdata"))) ulRamEnd;

#include "Os.hpp"
#include "NvM.hpp"

#define ECUM_START_SEC_VAR_CLEARED_BOOLEAN
#include "EcuM_Cfg_MemMap.hpp"
static volatile boolean EcuM_IsOnGoOffOneReached_b;
static volatile boolean EcuM_IsOnGoOffTwoReached_b;
static volatile boolean EcuM_IsALSwitchOffReached_b;
#define ECUM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "EcuM_Cfg_MemMap.hpp"

#define ECUM_START_SEC_CALLOUT_CODE
#include "EcuM_Cfg_MemMap.hpp"
FUNC(void, ECUM_CALLOUT_CODE) EcuM_ErrorHook(
   VAR(uint16, AUTOMATIC) reason){
   while(1){
      Wdt_TriggerWD0();
   }
}

FUNC(void, ECUM_CALLOUT_CODE) EcuM_OnGoOffOne(void){
   EcuM_IsOnGoOffOneReached_b = TRUE;
}

FUNC(void, ECUM_CALLOUT_CODE) EcuM_OnGoOffTwo(void){
   EcuM_IsOnGoOffTwoReached_b = TRUE;
   Dem_Shutdown();
   Memstack_WriteAllBlocks();
}

extern Type_SwcServiceEcuM_eTargetShutdown infSwcApplEcuM_eGetShutdownTarget (void); //TBD: Localize to SwcApplEcuM
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_SwitchOff(void){
   Type_SwcServiceEcuM_eTargetShutdown leTargetShutdown;
   Type_SwcServiceEcuM_tModeShutdown   ucSdMode;
   EcuM_IsALSwitchOffReached_b = TRUE;
   EcuM_GetShutdownTarget(
         &leTargetShutdown
      ,  &ucSdMode
   );
   leTargetShutdown = infSwcApplEcuM_eGetShutdownTarget(); //TBD: Analyze, leTargetShutdown overwritten!

   switch(leTargetShutdown){
      case SwcServiceEcuM_eTargetShutdown_SLEEP: ApplMcu_vDeepStop();     break;
      case SwcServiceEcuM_eTargetShutdown_OFF:   ApplMcu_vShutdown();     break;
      default:                                   ApplMcu_vPerformReset(); break;
   }
}

FUNC(void, ECUM_CALLOUT_CODE) SwcApplEcuM_vHandleReset(
   VAR(Type_McalMcu_eResetRequest, AUTOMATIC) leResetRequest
){
   tFblBmHeader* pBootManHeader         = (tFblBmHeader*)cBootmanHeaderAddress;
         void(*pFblStart)        (void) = (      void(*)(void))(pBootManHeader->pFblStartFct);
   const void(*pSmartTesterStart)(void) = (const void(*)(void))(0x78000u);
   switch(leResetRequest){
      case McalMcu_eResetRequest_General:
         Wdt_TriggerWD0();
         ApplMcu_vPerformReset();
         break;
      case McalMcu_eResetRequest_Bootloader:
         Wdt_TriggerWD0();
         (*pFblStart)();
         break;
      case McalMcu_eResetRequest_SmartTester:
         Wdt_TriggerWD0();
         ulRamStart = 0xFEDF8000;
         ulRamEnd   = 0xFEE07C00;
         for(
            pClear = (uint8*)ulRamStart;
            pClear < (uint8*)ulRamEnd;
            pClear ++
         ){
            *pClear = 0x00;
         }
         (*pSmartTesterStart)();
         break;
      default:
         break;
   }
}

FUNC(void, ECUM_CALLOUT_CODE) EcuM_CheckWakeup(        VAR(Type_SwcServiceEcuM_tSourceWakeup, AUTOMATIC) wakeupSource){}
FUNC(void, ECUM_CALLOUT_CODE) EcuM_StartWakeupSources( VAR(Type_SwcServiceEcuM_tSourceWakeup, AUTOMATIC) wakeupSource){}
FUNC(void, ECUM_CALLOUT_CODE) EcuM_StopWakeupSources(  VAR(Type_SwcServiceEcuM_tSourceWakeup, AUTOMATIC) wakeupSource){}
FUNC(void, ECUM_CALLOUT_CODE) EcuM_CheckValidation(    VAR(Type_SwcServiceEcuM_tSourceWakeup, AUTOMATIC) wakeupSource){}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "EcuM_Cfg_MemMap.hpp"

