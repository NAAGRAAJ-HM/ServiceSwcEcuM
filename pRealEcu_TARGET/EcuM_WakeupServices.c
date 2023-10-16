#include "Std_Types.hpp"

#include "Types_SwcServiceComM.hpp"

#include "EcuM.hpp"
#include "EcuM_Cfg_SchM.hpp"
#include "BswM_EcuM.hpp"
#include "Det.hpp"

#include "EcuM_Prv.hpp"

#define ECUM_START_SEC_CODE
#include "EcuM_Cfg_MemMap.hpp"
FUNC(void, ECUM_CODE ) EcuM_SetWakeupEvent( VAR(Type_SwcServiceEcuM_tSourceWakeup, AUTOMATIC) sources )
{
   VAR(uint32, AUTOMATIC) EcuM_newWkupEvents_u32 = 0;
   VAR(uint16, AUTOMATIC) EcuM_WkpSrcValidationTimeoutCtr_u16 = 0;
   VAR(uint32, AUTOMATIC) EcuM_dataValidatedWakeupEvents_u32 = 0;
   VAR(uint32, AUTOMATIC) EcuM_dataPendingWakeupEvents_u32 = 0;
   VAR(uint8, AUTOMATIC) ctrLoop_u8 = 0;

   if( EcuM_Lok_hasCheckWakeupSourceGetHandle_b( sources ) == FALSE )
   {
        (void) Det_ReportError( ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SET_WKEVENT_APIID, ECUM_E_UNKNOWN_WAKEUP_SOURCE );
   }
   else{
        EcuM_newWkupEvents_u32 = ( sources & ( ~SwcServiceEcuM_tSourceWakeup_EventsPending ) & ( ~SwcServiceEcuM_tSourceWakeup_Validated )
                & ( ~EcuM_Lok_dataExpiredWakeupEvents_u32 ) );

        if( EcuM_newWkupEvents_u32 != CfgSwcServiceEcuM_dSourceWakeupNone )
        {
            EcuM_dataValidatedWakeupEvents_u32 = ( EcuM_newWkupEvents_u32 & ECUM_WAKEUP_SOURCES_WITHOUT_VALIDATION );
            EcuM_dataPendingWakeupEvents_u32   = ( EcuM_newWkupEvents_u32 & ECUM_WAKEUP_SOURCES_WITH_VALIDATION );
        }
        if( EcuM_dataPendingWakeupEvents_u32 != CfgSwcServiceEcuM_dSourceWakeupNone )
        {
            for( ctrLoop_u8 = 0;ctrLoop_u8 < CfgSwcServiceEcuM_dNumSourceWakeup;ctrLoop_u8++ )
            {
                if( ( ( EcuM_dataPendingWakeupEvents_u32 & CfgSwcServiceEcuM_castListInfoSourceWakeUp[ctrLoop_u8].WakeupSourceId ) != CfgSwcServiceEcuM_dSourceWakeupNone ) \
                        && ( CfgSwcServiceEcuM_castListInfoSourceWakeUp[ctrLoop_u8].ValidationTimeout > EcuM_WkpSrcValidationTimeoutCtr_u16 ) )
                {
                    EcuM_WkpSrcValidationTimeoutCtr_u16 = CfgSwcServiceEcuM_castListInfoSourceWakeUp[ctrLoop_u8].ValidationTimeout;
                }
            }
        }
        SwcServiceEcuM_tSourceWakeup_Validated |= EcuM_dataValidatedWakeupEvents_u32;
        SwcServiceEcuM_tSourceWakeup_ValInd |= EcuM_dataValidatedWakeupEvents_u32;
        SwcServiceEcuM_tSourceWakeup_EventsPending |=EcuM_dataPendingWakeupEvents_u32;
        EcuM_Lok_dataPndWkpEventsInd_u32 |=EcuM_dataPendingWakeupEvents_u32;
        if( EcuM_WkpSrcValidationTimeoutCtr_u16 > EcuM_Lok_WkpSrcValidationTimeoutCtr_u16 )
        {
            EcuM_Lok_WkpSrcValidationTimeoutCtr_u16 = EcuM_WkpSrcValidationTimeoutCtr_u16;
        }
   }
}

FUNC(void, ECUM_CODE ) EcuM_ValidateWakeupEvent( VAR(Type_SwcServiceEcuM_tSourceWakeup, AUTOMATIC) sources )
{
   VAR(uint32, AUTOMATIC) EcuM_CommchlWkupEvents_u32 = 0;
   VAR( Type_SwcServiceEcuM_tSourceWakeup, AUTOMATIC )  dataPendingWakeupEvents_u32 = 0;
   if( SwcServiceEcuM_bIsInitialised == FALSE )
   {
        (void) Det_ReportError( ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_VAL_WKEVENT_APIID, ECUM_E_UNINIT );
   }
   else if( EcuM_Lok_hasCheckWakeupSourceGetHandle_b( sources ) == FALSE )
   {
        (void) Det_ReportError( ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_VAL_WKEVENT_APIID
   ,     ECUM_E_UNKNOWN_WAKEUP_SOURCE );
   }
   else{
        SchM_Enter_EcuM();
        dataPendingWakeupEvents_u32 = SwcServiceEcuM_tSourceWakeup_EventsPending;
        SchM_Exit_EcuM();
        dataPendingWakeupEvents_u32 = dataPendingWakeupEvents_u32 & sources;
   }
   if( dataPendingWakeupEvents_u32 != CfgSwcServiceEcuM_dSourceWakeupNone )
   {
        EcuM_CommchlWkupEvents_u32 = EcuM_Lok_ComMWakeupHandling(dataPendingWakeupEvents_u32);
        if( SwcServiceEcuM_ePhase == SwcServiceEcuM_ePhaseUp )
        {
            dataPendingWakeupEvents_u32 = EcuM_CommchlWkupEvents_u32;
        }
        SchM_Enter_EcuM();
        SwcServiceEcuM_tSourceWakeup_Validated |= dataPendingWakeupEvents_u32;
        SwcServiceEcuM_tSourceWakeup_EventsPending &= ( ~dataPendingWakeupEvents_u32 );
        EcuM_Lok_dataPndWkpEventsInd_u32 &= ( ~dataPendingWakeupEvents_u32 );
        SchM_Exit_EcuM();
   }
   if(dataPendingWakeupEvents_u32 != CfgSwcServiceEcuM_dSourceWakeupNone)
           {
               BswM_EcuM_CurrentWakeup( dataPendingWakeupEvents_u32, ECUM_WKSTATUS_VALIDATED );
           }
    return;
}

FUNC(void, ECUM_CODE )EcuM_ClearWakeupEvent ( VAR(Type_SwcServiceEcuM_tSourceWakeup, AUTOMATIC) sources )
{
   if( SwcServiceEcuM_bIsInitialised == FALSE )
   {
        (void)Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_CLEAR_WKEVENT_APIID, ECUM_E_UNINIT);
   }
   else{
        if(EcuM_Lok_hasCheckWakeupSourceGetHandle_b(sources) == FALSE)
        {
            (void)Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_CLEAR_WKEVENT_APIID
   ,     ECUM_E_UNKNOWN_WAKEUP_SOURCE);
        }
        else{
                SchM_Enter_EcuM();
                if((sources &(SwcServiceEcuM_tSourceWakeup_EventsPending | SwcServiceEcuM_tSourceWakeup_Validated |
                        EcuM_Lok_dataExpiredWakeupEvents_u32 )) == CfgSwcServiceEcuM_dSourceWakeupNone)
                {
                }
                else{
                    EcuM_Lok_dataClrWkpEventsInd_u32 |= (sources &(SwcServiceEcuM_tSourceWakeup_EventsPending |
                            SwcServiceEcuM_tSourceWakeup_Validated | EcuM_Lok_dataExpiredWakeupEvents_u32 ));
                    if((SwcServiceEcuM_tSourceWakeup_EventsPending & sources)!= CfgSwcServiceEcuM_dSourceWakeupNone )
                    {
                        SwcServiceEcuM_tSourceWakeup_EventsPending  ^= (SwcServiceEcuM_tSourceWakeup_EventsPending & sources);
                        EcuM_Lok_dataPndWkpEventsInd_u32 ^= (EcuM_Lok_dataPndWkpEventsInd_u32 & sources);
                    }
                    if((SwcServiceEcuM_tSourceWakeup_Validated & sources)!= CfgSwcServiceEcuM_dSourceWakeupNone)
                    {
                        SwcServiceEcuM_tSourceWakeup_Validated^=(SwcServiceEcuM_tSourceWakeup_Validated & sources);
                        SwcServiceEcuM_tSourceWakeup_ValInd ^= (SwcServiceEcuM_tSourceWakeup_ValInd & sources);
                    }
                    if((EcuM_Lok_dataExpiredWakeupEvents_u32 & sources)!= CfgSwcServiceEcuM_dSourceWakeupNone)
                    {
                        EcuM_Lok_dataExpiredWakeupEvents_u32 ^=(EcuM_Lok_dataExpiredWakeupEvents_u32 & sources);
                        EcuM_Lok_dataExpWkpEventsInd_u32 ^=(EcuM_Lok_dataExpWkpEventsInd_u32 & sources);
                    }
                }
                SchM_Exit_EcuM();

        }
   }
}

FUNC( Type_SwcServiceEcuM_tSourceWakeup, ECUM_CODE ) EcuM_GetPendingWakeupEvents(void)
{
   uint32 PendingWakeupEvents = CfgSwcServiceEcuM_dSourceWakeupNone;
   if( SwcServiceEcuM_bIsInitialised == FALSE )
   {
        (void) Det_ReportError( ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_GET_PEND_APIID, ECUM_E_UNINIT );
        PendingWakeupEvents =  CfgSwcServiceEcuM_dSourceWakeupNone;
   }
   else{
        PendingWakeupEvents = SwcServiceEcuM_tSourceWakeup_EventsPending;
   }
    return PendingWakeupEvents;
}

FUNC( Type_SwcServiceEcuM_tSourceWakeup, ECUM_CODE ) EcuM_GetValidatedWakeupEvents(void)
{
   uint32 ValidatedWakeupEvents = CfgSwcServiceEcuM_dSourceWakeupNone;
   if( SwcServiceEcuM_bIsInitialised == FALSE )
   {
        (void) Det_ReportError( ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_GET_VALIDATE_APIID, ECUM_E_UNINIT );
        ValidatedWakeupEvents = CfgSwcServiceEcuM_dSourceWakeupNone;
   }
   else{
        ValidatedWakeupEvents = SwcServiceEcuM_tSourceWakeup_Validated;
   }
    return ValidatedWakeupEvents;
}

FUNC( Type_SwcServiceEcuM_tSourceWakeup, ECUM_CODE ) EcuM_GetExpiredWakeupEvents(void)
{
       uint32 ExpiredWakeupEvents = CfgSwcServiceEcuM_dSourceWakeupNone;
   if( SwcServiceEcuM_bIsInitialised == FALSE )
   {
        (void) Det_ReportError( ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_GET_EXPIRED_APIID, ECUM_E_UNINIT );
       ExpiredWakeupEvents = CfgSwcServiceEcuM_dSourceWakeupNone;
   }
   else{
     ExpiredWakeupEvents = EcuM_Lok_dataExpiredWakeupEvents_u32;
   }
    return ExpiredWakeupEvents;
}

FUNC(void, ECUM_CODE) EcuM_EndCheckWakeup(VAR(Type_SwcServiceEcuM_tSourceWakeup, AUTOMATIC) sources)
{
(void)sources;
}

#define ECUM_STOP_SEC_CODE
#include "EcuM_Cfg_MemMap.hpp"

