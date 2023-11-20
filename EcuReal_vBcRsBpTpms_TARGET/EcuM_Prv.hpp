#ifndef ECUM_PRV_H
#define ECUM_PRV_H

#include "Types_SwcServiceEcuM.hpp"
#include "EcuM_Cfg_Startup.hpp"

#define ECUM_MODULE_ID                  (10U)
#define ECUM_INSTANCE_ID                (0U)
#define ECUM_GETVERINFO_APIID           (0x00U)
#define ECUM_GODOWN_APIID               (0x1fU)
#define ECUM_INIT_APIID                 (0x01U)
#define ECUM_START_TWO_APIID            (0x1aU)
#define ECUM_SHUTDOWN_APIID             (0x02U)
#define ECUM_SELECT_SHUT_TAR_APIID      (0x06U)
#define ECUM_GET_SHUT_TAR_APIID         (0x09U)
#define ECUM_SELECT_SHUT_CAUSE_APIID    (0x1bU)
#define ECUM_GET_SHUT_CAUSE_APIID       (0x1cU)
#define ECUM_LAST_SHUT_TAR_APIID        (0x08U)
#define ECUM_GET_PEND_APIID             (0x0dU)
#define ECUM_CLEAR_WKEVENT_APIID        (0x16U)
#define ECUM_GET_VALIDATE_APIID         (0x15U)
#define ECUM_GET_EXPIRED_APIID          (0x19U)
#define ECUM_SEL_BOOT_APIID             (0x12U)
#define ECUM_GET_BOOT_APIID             (0x13U)
#define ECUM_MAIN_FUNC_APIID            (0x18U)
#define ECUM_SET_WKEVENT_APIID          (0x0cU)
#define ECUM_VAL_WKEVENT_APIID          (0x14U)
#define ECUM_GOHALT_APIID               (0x20U)
#define ECUM_GOPOLL_APIID               (0x21U)
#define ECUM_RB_MO_GETACTIVEPBINDEX_APIID   (0x22U)
#define ECUM_RB_MO_INITCHECK_APIID      (0x23U)
#define ECUM_RB_MO_INITCHECKINV_APIID   (0x24U)
#define ECUM_LAST_SHUT_CAUSE_APIID      (0x30U)
#define ECUM_E_OS_GET_RESOURCE_FAILED                                   (0x05U)
#define ECUM_E_OS_RELEASE_RESOURCE_FAILED                               (0x06U)
#define ECUM_E_UNINIT                                                   (0x10U)
#define ECUM_E_SERVICE_DISABLED                                         (0x11U)
#define ECUM_E_NULL_POINTER                                             (0x12U)
#define ECUM_E_INVALID_PAR                                              (0x13U)
#define ECUM_E_NVM_READ_FAILED                                          (0x1AU)
#define ECUM_E_PARAM_POINTER                                            (0x1BU)
#define ECUM_E_STATE_PAR_OUT_OF_RANGE                                   (0x16U)
#define ECUM_E_UNKNOWN_WAKEUP_SOURCE                                    (0x17U)
#define ECUM_E_RAM_CHECK_FAILED                                         (0x19U)
#define ECUM_E_COREREADY_TIMEOUT_EXPIRED                                (0x04U)
#define ECUM_E_SHUTDOWN_INFO_UPDATED                                   (0xFEU)
#define ECUM_E_CONFIGURATION_DATA_INCONSISTENT                          (0x18U)
#define ECUM_E_NULL_PTR_RETURNED                                        (0x30U)
#define ECUM_E_INVALID_PTR_RETURNED                                     (0x31U)
#define ECUM_E_START_CORE_FAILED                                        (0x32U)

extern VAR(Type_SwcServiceEcuM_tBootTarget,ECUM_VAR_POWER_ON_CLEARED_8)  EcuM_Lok_dataSelectedBootTarget_u8;
extern VAR(uint8,ECUM_VAR_POWER_ON_CLEARED_8)  EcuM_Lok_dataSelectedBootTargetInit_u8;
extern VAR(Type_SwcServiceEcuM_ePhase, SWCSERVICEECUM_VAR) SwcServiceEcuM_ePhase;
extern VAR( uint8, ECUM_VAR_CLEARED_8 )  EcuM_Lok_SlaveCoreTimeoutCtr_u8;
extern VAR( Type_SwcServiceEcuM_tCauseShutdown, ECUM_VAR)  EcuM_Lok_dataSelectedShutdownCause_u8;
extern VAR(Type_SwcServiceEcuM_stInfoTargetShutdown, ECUM_VAR_CLEARED_UNSPECIFIED)   SwcServiceEcuM_stInfoTargetShutdown;
extern VAR( Type_SwcServiceEcuM_tSourceWakeup, ECUM_VAR_CLEARED_32 )  SwcServiceEcuM_tSourceWakeup_EventsPending;
extern VAR( Type_SwcServiceEcuM_tSourceWakeup, ECUM_VAR_CLEARED_32 )  EcuM_Lok_dataOldPendingWakeupEvents_u32;
extern VAR( Type_SwcServiceEcuM_tSourceWakeup, ECUM_VAR_CLEARED_32 )  SwcServiceEcuM_tSourceWakeup_Validated;
extern VAR( Type_SwcServiceEcuM_tSourceWakeup, ECUM_VAR_CLEARED_32 )  EcuM_Lok_dataExpiredWakeupEvents_u32;
extern VAR( Type_SwcServiceEcuM_tSourceWakeup, ECUM_VAR_CLEARED_32 ) EcuM_Lok_dataClrWkpEventsInd_u32;
extern VAR( Type_SwcServiceEcuM_tSourceWakeup, ECUM_VAR_CLEARED_32 ) EcuM_Lok_dataPndWkpEventsInd_u32;
extern VAR( Type_SwcServiceEcuM_tSourceWakeup, ECUM_VAR_CLEARED_32 ) SwcServiceEcuM_tSourceWakeup_ValInd;
extern VAR( Type_SwcServiceEcuM_tSourceWakeup, ECUM_VAR_CLEARED_32 )EcuM_Lok_dataExpWkpEventsInd_u32;
extern VAR( uint16, ECUM_VAR_CLEARED_16 )  EcuM_Lok_WkpSrcValidationTimeoutCtr_u16;
extern VAR( boolean, ECUM_VAR_CLEARED_BOOLEAN ) EcuM_Lok_flgIsStartupTwoCalled_ab[ECUM_CFG_NUM_OS_CORES];
extern VAR(boolean,ECUM_VAR_CLEARED_BOOLEAN)  SwcServiceEcuM_bIsInitialised ;
extern VAR( boolean, ECUM_VAR_CLEARED_BOOLEAN ) EcuM_Lok_flgCoreReady_ab[ECUM_CFG_NUM_OS_CORES];
extern VAR(boolean, ECUM_VAR_CLEARED_BOOLEAN) EcuM_Lok_isEcuMGoDownFailed_b;
extern VAR(boolean, ECUM_VAR_CLEARED_BOOLEAN) EcuM_Lok_flgShutdownInfoDoNotUpdate_b;
extern VAR(boolean, ECUM_VAR_CLEARED_BOOLEAN) EcuM_Lok_flgGoDown_b;
extern VAR(boolean,ECUM_VAR_CLEARED_BOOLEAN)  EcuM_Lok_flgNvMReadStatus_b;
extern VAR( Type_SwcServiceEcuM_stInfoTargetShutdown, ECUM_VAR_POWER_ON_CLEARED_UNSPECIFIED ) EcuM_Lok_dataShutdownInfo_st;
extern FUNC(boolean, ECUM_CODE ) EcuM_Lok_hasCheckWakeupSourceGetHandle_b(
        VAR(Type_SwcServiceEcuM_tSourceWakeup, AUTOMATIC) datasource_u32);
extern FUNC(void, ECUM_CODE ) EcuM_Lok_WakeupIndication(
        VAR(Type_SwcServiceEcuM_tSourceWakeup, AUTOMATIC) dataPendingWakeupEvents_u32  );
extern FUNC(void, ECUM_CODE ) EcuM_Lok_DecValidationCtr(void);
extern FUNC(void, ECUM_CODE ) infSwcApplEcuMSwcServiceEcuM_vStartOS(void);
extern FUNC(uint32, ECUM_CODE)EcuM_Lok_ComMWakeupHandling(VAR(Type_SwcServiceEcuM_tSourceWakeup, AUTOMATIC )dataPendingWakeupEvents);
#endif

