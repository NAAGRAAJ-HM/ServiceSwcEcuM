#include "Std_Types.hpp"

#include "Types_SwcServiceComM.hpp"

#include "EcuM.hpp"
#include "EcuM_Cfg_SchM.hpp"
#include "NvM.hpp"
#include "Det.hpp"

#include "EcuM_Prv.hpp"

#define ECUM_START_SEC_CODE
#include "EcuM_Cfg_MemMap.hpp"
FUNC(Std_ReturnType, ECUM_CODE ) EcuM_SelectShutdownCause( VAR(Type_SwcServiceEcuM_tCauseShutdown, AUTOMATIC) tCauseShutdown )
{
   VAR(Std_ReturnType, AUTOMATIC) returnvalue_u8 = E_NOT_OK;
   if( TRUE == SwcServiceEcuM_bIsInitialised  )
   {
        if    (FALSE == EcuM_Lok_flgShutdownInfoDoNotUpdate_b )
        {
            if(tCauseShutdown < ECUM_CFG_NUM_SHUTDOWN_CAUSE)
            {
                SchM_Enter_EcuM();
                EcuM_Lok_dataSelectedShutdownCause_u8 = tCauseShutdown;
                EcuM_Rn_dataShutdownInfo_st.tCauseShutdown =EcuM_Lok_dataSelectedShutdownCause_u8;
                SchM_Exit_EcuM();
                (void)NvM_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_ECUM_CFG_NVM_BLOCK,TRUE);
                returnvalue_u8 = E_OK;
            }
            else{
                (void)Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SELECT_SHUT_CAUSE_APIID 
   ,     ECUM_E_INVALID_PAR);
            }
        }
        else{
            (void)Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SELECT_SHUT_CAUSE_APIID 
   ,     ECUM_E_SHUTDOWN_INFO_UPDATED);
        }
   }
   else{
        (void)Det_ReportError( ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SELECT_SHUT_CAUSE_APIID, ECUM_E_UNINIT );
   }
    return returnvalue_u8;
}

FUNC(Std_ReturnType, ECUM_CODE ) EcuM_GetShutdownCause(
          P2VAR(Type_SwcServiceEcuM_tCauseShutdown, AUTOMATIC, ECUM_APPL_DATA) shutdownCause )
        {
   VAR(Std_ReturnType, AUTOMATIC) return_value_u8= E_NOT_OK;
   if(FALSE == SwcServiceEcuM_bIsInitialised)
   {
        (void)Det_ReportError( ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_GET_SHUT_CAUSE_APIID, ECUM_E_UNINIT );
   }
   else{
        if(shutdownCause == NULL_PTR)
        {
            (void)Det_ReportError( ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_GET_SHUT_CAUSE_APIID, ECUM_E_NULL_POINTER );
        }
        else{
            SchM_Enter_EcuM();
            *shutdownCause = EcuM_Lok_dataSelectedShutdownCause_u8;
            SchM_Exit_EcuM();
            return_value_u8 = E_OK;
        }
   }
    return return_value_u8;
}

FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownTarget(
      VAR(Type_SwcServiceEcuM_eTargetShutdown, AUTOMATIC) leTargetShutdown
   ,  VAR(Type_SwcServiceEcuM_tModeShutdown,   AUTOMATIC) shutdownMode
){
   VAR(Std_ReturnType, AUTOMATIC) returnvalue_u8 = E_NOT_OK;
   if(TRUE == SwcServiceEcuM_bIsInitialised){
        if(FALSE == EcuM_Lok_flgShutdownInfoDoNotUpdate_b){
            if(
               (
                     (leTargetShutdown == SwcServiceEcuM_eTargetShutdown_RESET)
                  && (shutdownMode < ECUM_CFG_NUM_RESET_MODES)
               )
               || (leTargetShutdown == SwcServiceEcuM_eTargetShutdown_OFF)
            ){
                returnvalue_u8   =   E_OK;
            }
            else{
                (void)Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SELECT_SHUT_TAR_APIID, ECUM_E_STATE_PAR_OUT_OF_RANGE);
            }
            if(E_OK == returnvalue_u8){
                SchM_Enter_EcuM();
                SwcServiceEcuM_stInfoTargetShutdown.eTargetShutdown = leTargetShutdown;
               if(
                     (leTargetShutdown == SwcServiceEcuM_eTargetShutdown_RESET)
                  ||  (leTargetShutdown == SwcServiceEcuM_eTargetShutdown_SLEEP)
               ){
                  SwcServiceEcuM_stInfoTargetShutdown.mode = shutdownMode;
               }
                EcuM_Rn_dataShutdownInfo_st.eTargetShutdown = SwcServiceEcuM_stInfoTargetShutdown.eTargetShutdown;
                EcuM_Rn_dataShutdownInfo_st.mode            = SwcServiceEcuM_stInfoTargetShutdown.mode;
                SchM_Exit_EcuM();
                (void)NvM_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_ECUM_CFG_NVM_BLOCK,TRUE);
            }
            else{
            }
        }
        else{
            (void)Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SELECT_SHUT_TAR_APIID, ECUM_E_SHUTDOWN_INFO_UPDATED);
        }
   }
   else{
        (void)Det_ReportError( ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SELECT_SHUT_TAR_APIID, ECUM_E_UNINIT );
   }
    return returnvalue_u8;
}

FUNC(Std_ReturnType, ECUM_CODE ) EcuM_GetShutdownTarget(
      P2VAR(Type_SwcServiceEcuM_eTargetShutdown, AUTOMATIC, ECUM_APPL_DATA) eTargetShutdown
   ,  P2VAR(Type_SwcServiceEcuM_tModeShutdown,   AUTOMATIC, ECUM_APPL_DATA) shutdownMode
){
   VAR(Type_SwcServiceEcuM_eTargetShutdown, AUTOMATIC) dataShutdownTarget_u8;
   VAR(Type_SwcServiceEcuM_tModeShutdown,   AUTOMATIC) dataMode_u16;
   VAR(Std_ReturnType,                      AUTOMATIC) return_value_u8 = E_NOT_OK;
   if(FALSE == SwcServiceEcuM_bIsInitialised){
      (void)Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_GET_SHUT_TAR_APIID, ECUM_E_UNINIT);
   }
   else{
        if(eTargetShutdown == NULL_PTR){
            (void)Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_GET_SHUT_TAR_APIID, ECUM_E_NULL_POINTER);
        }
        else{
            SchM_Enter_EcuM();
            dataShutdownTarget_u8   =   SwcServiceEcuM_stInfoTargetShutdown.eTargetShutdown;
            dataMode_u16         =   SwcServiceEcuM_stInfoTargetShutdown.mode;
            SchM_Exit_EcuM();
            *eTargetShutdown   =   dataShutdownTarget_u8;
            if(shutdownMode == NULL_PTR){
                (void)Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_GET_SHUT_TAR_APIID, ECUM_E_PARAM_POINTER);
            }
            else if(
                  (dataShutdownTarget_u8 == SwcServiceEcuM_eTargetShutdown_RESET)
               || (dataShutdownTarget_u8 == SwcServiceEcuM_eTargetShutdown_SLEEP)
           ){
                *shutdownMode = dataMode_u16;
            }
            else{
            }
            return_value_u8 = E_OK;
        }
   }
    return return_value_u8;
}

#define ECUM_STOP_SEC_CODE
#include "EcuM_Cfg_MemMap.hpp"

