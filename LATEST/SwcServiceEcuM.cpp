/******************************************************************************/
/* File   : SwcServiceEcuM.cpp                                                */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "SwcServiceEcuM.hpp"
#include "infSwcServiceEcuM_Imp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define SWCSERVICEECUM_AR_RELEASE_VERSION_MAJOR                                4
#define SWCSERVICEECUM_AR_RELEASE_VERSION_MINOR                                3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(SWCSERVICEECUM_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible SWCSERVICEECUM_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(SWCSERVICEECUM_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible SWCSERVICEECUM_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient,          SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) gptrinfEcuMClient_SwcServiceEcuM = &SwcServiceEcuM;
CONSTP2VAR(infSwcServiceEcuM_EcuM, SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) gptrinfSwcServiceEcuM_EcuM       = &SwcServiceEcuM;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_SwcServiceEcuM, SWCSERVICEECUM_VAR) SwcServiceEcuM;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
static FUNC(void, SWCSERVICEECUM_CODE) SetProgrammableInterrupts(
   void
){
}

typedef struct{
   CONSTP2VAR(infEcuMClient, SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) lptrinfEcuMClient_Module;
   const CfgModule_TypeAbstract* ptrPBcfgModule;
}CfgEcuM_TypeDriverInitData;

static FUNC(void, SWCSERVICEECUM_CODE) DriverInitX(
      const CfgEcuM_TypeDriverInitData* const lptrDriverInitData
   ,  uint8 luint8ListSize
){
   P2CONST(CfgEcuM_TypeDriverInitData, SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) DriverInitData_Indexed;
   for(
         uint8 luint8IndexEcuMClient = 0
      ;        luint8IndexEcuMClient < luint8ListSize 
      ;        luint8IndexEcuMClient ++
   ){
      DriverInitData_Indexed = &lptrDriverInitData[luint8IndexEcuMClient];
#if(STD_ON == SwcServiceEcuM_CheckNullPtr)
      if(
            NULL_PTR
         == (DriverInitData_Indexed->lptrinfEcuMClient_Module->InitFunction)
      ){
#if(STD_ON == SwcServiceEcuM_DevErrorDetect)
         Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
         );
#endif
      }
      else{
#endif
         DriverInitData_Indexed->lptrinfEcuMClient_Module->InitFunction(
            DriverInitData_Indexed->ptrPBcfgModule
         );
#if(STD_ON == SwcServiceEcuM_CheckNullPtr)
      }
#endif
   }
}

//TBD: Move to Cfg

#include "CfgGen.hpp"

//TBD: Move to Cfg
#include "infDet_EcuM.hpp"
#include "infDem_EcuM.hpp"
#include "infFls_EcuM.hpp"
#include "infFee_EcuM.hpp"
#include "infMemIf_EcuM.hpp"
#include "infNvM_EcuM.hpp"
#include "infEcuM_SwcServiceEcuM.hpp"

static const CfgEcuM_TypeDriverInitData laDriverInitDataZero[] = {
      {gptrinfEcuMClient_Det,   &(CfgGen_NvM.CfgDet)}
   ,  {gptrinfEcuMClient_Dem,   &(CfgGen_NvM.CfgDem)}
   ,  {gptrinfEcuMClient_Fls,   &(CfgGen_NvM.CfgFls)}
   ,  {gptrinfEcuMClient_Fee,   &(CfgGen_NvM.CfgFee)}
   ,  {gptrinfEcuMClient_MemIf, &(CfgGen_NvM.CfgMemIf)}
   ,  {gptrinfEcuMClient_NvM,   &(CfgGen_NvM.CfgNvM)}
// ,  {gptrinfEcuMClient_EcuM,  &(CfgGen_NvM.CfgEcuM)}
};

static FUNC(void, SWCSERVICEECUM_CODE) DriverInitZero(
   void
){
   DriverInitX(
         laDriverInitDataZero
      ,  (
               sizeof(laDriverInitDataZero)
            /  sizeof(CfgEcuM_TypeDriverInitData)
         )
   );
}

//TBD: Move to Cfg
#include "infCanIf_EcuM.hpp"
#include "infCanTp_EcuM.hpp"
#include "infCryIf_EcuM.hpp"
#include "infEa_EcuM.hpp"
#include "infEthIf_EcuM.hpp"
#include "infFrIf_EcuM.hpp"
#include "infFrTp_EcuM.hpp"
#include "infJ1939Tp_EcuM.hpp"
#include "infLinIf_EcuM.hpp"
#include "infLinTp_EcuM.hpp"
#include "infWdgIf_EcuM.hpp"
#include "infAdc_EcuM.hpp"
#include "infCan_EcuM.hpp"
#include "infCry_EcuM.hpp"
#include "infDio_EcuM.hpp"
#include "infEep_EcuM.hpp"
#include "infEth_EcuM.hpp"
#include "infFr_EcuM.hpp"
#include "infGpt_EcuM.hpp"
#include "infIcu_EcuM.hpp"
#include "infLin_EcuM.hpp"
#include "infMcu_EcuM.hpp"
#include "infOcu_EcuM.hpp"
#include "infPort_EcuM.hpp"
#include "infPwm_EcuM.hpp"
#include "infSpi_EcuM.hpp"
#include "infWdg_EcuM.hpp"
#include "infBswM_EcuM.hpp"
#include "infCanNm_EcuM.hpp"
#include "infCanSm_EcuM.hpp"
#include "infCom_EcuM.hpp"
#include "infComM_EcuM.hpp"
#include "infCsm_EcuM.hpp"
#include "infDcm_EcuM.hpp"
#include "infDlt_EcuM.hpp"
#include "infFiM_EcuM.hpp"
#include "infFrNm_EcuM.hpp"
#include "infIpduM_EcuM.hpp"
#include "infNm_EcuM.hpp"
#include "infOs_EcuM.hpp"
#include "infPduR_EcuM.hpp"
#include "infSchM_EcuM.hpp"
#include "infSecOC_EcuM.hpp"
#include "infSokFm_EcuM.hpp"
#include "infStartUp_EcuM.hpp"
#include "infStbM_EcuM.hpp"
#include "infVkms_EcuM.hpp"
#include "infWdgM_EcuM.hpp"
#include "infRte_EcuM.hpp"
#include "infSwcServiceEcuM_EcuM.hpp"
#include "infSwcServiceOs_EcuM.hpp"

//TBD: Move to Cfg
static const CfgEcuM_TypeDriverInitData laDriverInitDataOne[] = {
      {gptrinfEcuMClient_CanIf,          &(CfgGen_NvM.CfgCanIf)}
   ,  {gptrinfEcuMClient_CanTp,          &(CfgGen_NvM.CfgCanTp)}
   ,  {gptrinfEcuMClient_CryIf,          &(CfgGen_NvM.CfgCryIf)}
   ,  {gptrinfEcuMClient_Ea,             &(CfgGen_NvM.CfgEa)}
   ,  {gptrinfEcuMClient_EthIf,          &(CfgGen_NvM.CfgEthIf)}
// ,  {gptrinfEcuMClient_Fee,            &(CfgGen_NvM.CfgFee)}
   ,  {gptrinfEcuMClient_FrIf,           &(CfgGen_NvM.CfgFrIf)}
   ,  {gptrinfEcuMClient_FrTp,           &(CfgGen_NvM.CfgFrTp)}
   ,  {gptrinfEcuMClient_J1939Tp,        &(CfgGen_NvM.CfgJ1939Tp)}
   ,  {gptrinfEcuMClient_LinIf,          &(CfgGen_NvM.CfgLinIf)}
   ,  {gptrinfEcuMClient_LinTp,          &(CfgGen_NvM.CfgLinTp)}
// ,  {gptrinfEcuMClient_MemIf,          &(CfgGen_NvM.CfgMemIf)}
   ,  {gptrinfEcuMClient_WdgIf,          &(CfgGen_NvM.CfgWdgIf)}
   ,  {gptrinfEcuMClient_Adc,            &(CfgGen_NvM.CfgAdc)}
   ,  {gptrinfEcuMClient_Can,            &(CfgGen_NvM.CfgCan)}
   ,  {gptrinfEcuMClient_Cry,            &(CfgGen_NvM.CfgCry)}
   ,  {gptrinfEcuMClient_Dio,            &(CfgGen_NvM.CfgDio)}
   ,  {gptrinfEcuMClient_Eep,            &(CfgGen_NvM.CfgEep)}
   ,  {gptrinfEcuMClient_Eth,            &(CfgGen_NvM.CfgEth)}
// ,  {gptrinfEcuMClient_Fls,            &(CfgGen_NvM.CfgFls)}
   ,  {gptrinfEcuMClient_Fr,             &(CfgGen_NvM.CfgFr)}
   ,  {gptrinfEcuMClient_Gpt,            &(CfgGen_NvM.CfgGpt)}
   ,  {gptrinfEcuMClient_Icu,            &(CfgGen_NvM.CfgIcu)}
   ,  {gptrinfEcuMClient_Lin,            &(CfgGen_NvM.CfgLin)}
   ,  {gptrinfEcuMClient_Mcu,            &(CfgGen_NvM.CfgMcu)}
   ,  {gptrinfEcuMClient_Ocu,            &(CfgGen_NvM.CfgOcu)}
   ,  {gptrinfEcuMClient_Port,           &(CfgGen_NvM.CfgPort)}
   ,  {gptrinfEcuMClient_Pwm,            &(CfgGen_NvM.CfgPwm)}
   ,  {gptrinfEcuMClient_Spi,            &(CfgGen_NvM.CfgSpi)}
   ,  {gptrinfEcuMClient_Wdg,            &(CfgGen_NvM.CfgWdg)}
// ,  {gptrinfEcuMClient_BswM,           &(CfgGen_NvM.CfgBswM)}
   ,  {gptrinfEcuMClient_CanNm,          &(CfgGen_NvM.CfgCanNm)}
   ,  {gptrinfEcuMClient_CanSm,          &(CfgGen_NvM.CfgCanSm)}
   ,  {gptrinfEcuMClient_Com,            &(CfgGen_NvM.CfgCom)}
   ,  {gptrinfEcuMClient_ComM,           &(CfgGen_NvM.CfgComM)}
   ,  {gptrinfEcuMClient_Csm,            &(CfgGen_NvM.CfgCsm)}
   ,  {gptrinfEcuMClient_Dcm,            &(CfgGen_NvM.CfgDcm)}
// ,  {gptrinfEcuMClient_Dem,            &(CfgGen_NvM.CfgDem)}
// ,  {gptrinfEcuMClient_Det,            &(CfgGen_NvM.CfgDet)}
   ,  {gptrinfEcuMClient_Dlt,            &(CfgGen_NvM.CfgDlt)}
// ,  {gptrinfEcuMClient_EcuM,           &(CfgGen_NvM.CfgEcuM)}
   ,  {gptrinfEcuMClient_FiM,            &(CfgGen_NvM.CfgFiM)}
   ,  {gptrinfEcuMClient_FrNm,           &(CfgGen_NvM.CfgFrNm)}
   ,  {gptrinfEcuMClient_IpduM,          &(CfgGen_NvM.CfgIpduM)}
   ,  {gptrinfEcuMClient_Nm,             &(CfgGen_NvM.CfgNm)}
// ,  {gptrinfEcuMClient_NvM,            &(CfgGen_NvM.CfgNvM)}
// ,  {gptrinfEcuMClient_Os,             &(CfgGen_NvM.CfgOs)}
   ,  {gptrinfEcuMClient_PduR,           &(CfgGen_NvM.CfgPduR)}
// ,  {gptrinfEcuMClient_SchM,           &(CfgGen_NvM.CfgSchM)}
   ,  {gptrinfEcuMClient_SecOC,          &(CfgGen_NvM.CfgSecOC)}
   ,  {gptrinfEcuMClient_SokFm,          &(CfgGen_NvM.CfgSokFm)}
// ,  {gptrinfEcuMClient_StartUp,        &(CfgGen_NvM.CfgStartUp)}
   ,  {gptrinfEcuMClient_StbM,           &(CfgGen_NvM.CfgStbM)}
   ,  {gptrinfEcuMClient_Vkms,           &(CfgGen_NvM.CfgVkms)}
   ,  {gptrinfEcuMClient_WdgM,           &(CfgGen_NvM.CfgWdgM)}
// ,  {gptrinfEcuMClient_Rte,            &(CfgGen_NvM.CfgRte)}
// ,  {gptrinfEcuMClient_SwcServiceEcuM, &(CfgGen_NvM.CfgSwcServiceEcuM)}
// ,  {gptrinfEcuMClient_SwcServiceOs,   &(CfgGen_NvM.CfgSwcServiceOs)}
};

static FUNC(void, SWCSERVICEECUM_CODE) DriverInitOne(
   void
){
   DriverInitX(
         laDriverInitDataOne
      ,  (
               sizeof(laDriverInitDataOne)
            /  sizeof(CfgEcuM_TypeDriverInitData)
         )
   );
}

static FUNC(void, SWCSERVICEECUM_CODE) OnGoOffOne(
   void
){
}

static FUNC(void, SWCSERVICEECUM_CODE) OnGoOffTwo(
   void
){
}

static FUNC(void, SWCSERVICEECUM_CODE) Reset(
   void
){
}

static FUNC(void, SWCSERVICEECUM_CODE) SwitchOff(
   void
){
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, SWCSERVICEECUM_CONFIG_DATA, SWCSERVICEECUM_APPL_CONST) lptrCfgModule
){
#if(STD_ON == SwcServiceEcuM_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(NULL_PTR != lptrCfgModule){
         lptrCfg = lptrCfgModule;
      }
      else{
#if(STD_ON == SwcServiceEcuM_DevErrorDetect)
         Det_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == SwcServiceEcuM_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == SwcServiceEcuM_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SWCSERVICEECUM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::DeInitFunction(
   void
){
#if(STD_ON == SwcServiceEcuM_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == SwcServiceEcuM_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == SwcServiceEcuM_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SWCSERVICEECUM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::MainFunction(
   void
){
#if(STD_ON == SwcServiceEcuM_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == SwcServiceEcuM_InitCheck)
   }
   else{
#if(STD_ON == SwcServiceEcuM_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SWCSERVICEECUM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::StartPreOs(
   void
){
   SetProgrammableInterrupts();
   DriverInitZero();
   gptrinfEcuM_SwcServiceEcuM->DeterminePbConfiguration();

   //Check consistency of configuration data

   DriverInitOne();
   gptrinfEcuM_SwcServiceEcuM->GetValidatedWakeupEvents();

   //Select default shutdown target

   gptrinfEcuM_SwcServiceEcuM->LoopDetection();
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::StartPostOs(
   void
){
   gptrinfSchM_EcuM->Start();
   gptrinfEcuMClient_BswM->InitFunction((&CfgGen_NvM.CfgBswM));
   gptrinfEcuMClient_SchM->InitFunction((&CfgGen_NvM.CfgSchM));
   gptrinfSchM_EcuM->StartTiming();
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::OffPreOs(
   void
){
   OnGoOffOne();
   gptrinfEcuMClient_BswM->DeInitFunction();
   gptrinfEcuMClient_SchM->DeInitFunction();

   if(gptrinfEcuM_SwcServiceEcuM->GetPendingWakeupEvents()){
      gptrinfEcuM_SwcServiceEcuM->SelectShutdownTarget();
   }
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::OffPostOs(
   void
){
   OnGoOffTwo();
   Reset();
   SwitchOff();
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::EnableWakeupSources(
   void
){
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::GenerateRamHash(
   void
){
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::CheckRamHash(
   void
){
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::ErrorHook(
   void
){
}

// Go to sleep sequence
// BswM.CurrentWakeupSources();
// SwcServiceEcuM.EnableWakeupSources();
// Os.GetResource();

// Go to halt sequence
// Os.DisableAllInterrupts();
// Swc_EcuE.GenerateRamHash();
// Mcu.SetMode(HALT);

// Go to poll sequence
// ...

// Go to wake-up restart sequence
// ...

// Go to wake-up validation sequence
// ...

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

