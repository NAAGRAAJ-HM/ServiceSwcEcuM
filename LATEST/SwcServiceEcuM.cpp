/******************************************************************************/
/* File   : SwcServiceEcuM.cpp                                                */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "module.h"
#include "infSwcServiceEcuM_EcuM.h"
#include "infSwcServiceEcuM_Dcm.h"
#include "infSwcServiceEcuM_SchM.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_SwcServiceEcuM:
      public abstract_module
   ,  public infSwcServiceEcuM_EcuM
{
   public:
      FUNC(void, SWCSERVICEECUM_CODE) InitFunction   (void);
      FUNC(void, SWCSERVICEECUM_CODE) DeInitFunction (void);
      FUNC(void, SWCSERVICEECUM_CODE) GetVersionInfo (void);
      FUNC(void, SWCSERVICEECUM_CODE) MainFunction   (void);
      FUNC(void, SWCSERVICEECUM_CODE) StartPreOs     (void);
      FUNC(void, SWCSERVICEECUM_CODE) StartPostOs    (void);
      FUNC(void, SWCSERVICEECUM_CODE) OffPreOs       (void);
      FUNC(void, SWCSERVICEECUM_CODE) OffPostOs      (void);
};

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/


/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
VAR(module_SwcServiceEcuM, SWCSERVICEECUM_VAR) SwcServiceEcuM;
CONSTP2VAR(infEcuMClient, SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) gptrinfEcuMClient_SwcServiceEcuM = &SwcServiceEcuM;
CONSTP2VAR(infDcmClient,  SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) gptrinfDcmClient_SwcServiceEcuM  = &SwcServiceEcuM;
CONSTP2VAR(infSchMClient, SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) gptrinfSchMClient_SwcServiceEcuM = &SwcServiceEcuM;
infSwcServiceEcuM_EcuM* gptrinfSwcServiceEcuM_EcuM       = &SwcServiceEcuM;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
static FUNC(void, SWCSERVICEECUM_CODE) SetProgrammableInterrupts(void){
}

#include "infCanIf_EcuM.h"
#include "infCryIf_EcuM.h"
#include "infEa_EcuM.h"
#include "infEthIf_EcuM.h"
#include "infFee_EcuM.h"
#include "infFrIf_EcuM.h"
#include "infLinIf_EcuM.h"
#include "infLinTp_EcuM.h"
#include "infMemIf_EcuM.h"
#include "infWdgIf_EcuM.h"
#include "infAdc_EcuM.h"
#include "infCan_EcuM.h"
#include "infCry_EcuM.h"
#include "infDio_EcuM.h"
#include "infEep_EcuM.h"
#include "infEth_EcuM.h"
#include "infFls_EcuM.h"
#include "infFr_EcuM.h"
#include "infGpt_EcuM.h"
#include "infIcu_EcuM.h"
#include "infLin_EcuM.h"
#include "infMcu_EcuM.h"
#include "infOcu_EcuM.h"
#include "infPort_EcuM.h"
#include "infPwm_EcuM.h"
#include "infSpi_EcuM.h"
#include "infWdg_EcuM.h"
#include "infBswM_EcuM.h"
#include "infCom_EcuM.h"
#include "infComM_EcuM.h"
#include "infCsm_EcuM.h"
#include "infDcm_EcuM.h"
#include "infDem_EcuM.h"
#include "infDet_EcuM.h"
#include "infEcuM_SwcServiceEcuM.h"
#include "infFiM_EcuM.h"
#include "infNm_EcuM.h"
#include "infNvM_EcuM.h"
#include "infOs_EcuM.h"
#include "infPduR_EcuM.h"
#include "infSchM_EcuM.h"
#include "infSecOC_EcuM.h"
#include "infSokFm_EcuM.h"
#include "infStartUp_EcuM.h"
#include "infStbM_EcuM.h"
#include "infVkms_EcuM.h"
#include "infWdgM_EcuM.h"
#include "infRte_EcuM.h"
#include "infSwcServiceEcuM_EcuM.h"
#include "infSwcServiceOs_EcuM.h"

static FUNC(void, SWCSERVICEECUM_CODE) DriverInitZero(void){
   gptrinfEcuMClient_Det->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Dem->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Fls->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_NvM->InitFunction(/*configuration abstract type*/);
}

static FUNC(void, SWCSERVICEECUM_CODE) DriverInitOne(void){
   gptrinfEcuMClient_CanIf->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_CryIf->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Ea->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_EthIf->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Fee->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_FrIf->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_LinIf->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_LinTp->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_MemIf->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_WdgIf->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Adc->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Can->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Cry->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Dio->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Eep->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Eth->InitFunction(/*configuration abstract type*/);
// gptrinfEcuMClient_Fls->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Fr->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Gpt->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Icu->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Lin->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Mcu->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Ocu->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Port->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Pwm->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Spi->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Wdg->InitFunction(/*configuration abstract type*/);
// gptrinfEcuMClient_BswM->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Com->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_ComM->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Csm->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Dcm->InitFunction(/*configuration abstract type*/);
// gptrinfEcuMClient_Dem->InitFunction(/*configuration abstract type*/);
// gptrinfEcuMClient_Det->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_FiM->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Nm->InitFunction(/*configuration abstract type*/);
// gptrinfEcuMClient_NvM->InitFunction(/*configuration abstract type*/);
// gptrinfEcuMClient_Os->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_PduR->InitFunction(/*configuration abstract type*/);
// gptrinfEcuMClient_SchM->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_SecOC->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_SokFm->InitFunction(/*configuration abstract type*/);
// gptrinfEcuMClient_StartUp->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_StbM->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Vkms->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_WdgM->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Rte->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_SwcServiceEcuM->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_SwcServiceOs->InitFunction(/*configuration abstract type*/);
}

static FUNC(void, SWCSERVICEECUM_CODE) OnGoOffOne(void){
}

static FUNC(void, SWCSERVICEECUM_CODE) OnGoOffTwo(void){
}

static FUNC(void, SWCSERVICEECUM_CODE) Reset(void){
}

static FUNC(void, SWCSERVICEECUM_CODE) SwitchOff(void){
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::InitFunction(void){
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::DeInitFunction(void){
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::GetVersionInfo(void){
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::MainFunction(void){
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::StartPreOs(void){
   SetProgrammableInterrupts();
   DriverInitZero();
   gptrinfEcuM_SwcServiceEcuM->DeterminePbConfiguration();

   //Check consistency of configuration data

   DriverInitOne();
   gptrinfEcuM_SwcServiceEcuM->GetValidatedWakeupEvents();

   //Select default shutdown target

   gptrinfEcuM_SwcServiceEcuM->LoopDetection();
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::StartPostOs(void){
   gptrinfSchM_EcuM->Start();
   gptrinfEcuMClient_BswM->InitFunction(/*TBD: configuration*/);
   gptrinfEcuMClient_SchM->InitFunction(/*TBD: configuration*/);
   gptrinfSchM_EcuM->StartTiming();
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::OffPreOs(void){
   OnGoOffOne();
   gptrinfEcuMClient_BswM->DeInitFunction();
   gptrinfEcuMClient_SchM->DeInitFunction();

   if(gptrinfEcuM_SwcServiceEcuM->GetPendingWakeupEvents()){
      gptrinfEcuM_SwcServiceEcuM->SelectShutdownTarget();
   }
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::OffPostOs(void){
   OnGoOffTwo();
   Reset();
   SwitchOff();
}

#include "SwcServiceEcuM_Unused.h"

FUNC(void, SWCSERVICEECUM_CODE) class_SwcServiceEcuM_Unused::EnableWakeupSources(void){
}

FUNC(void, SWCSERVICEECUM_CODE) class_SwcServiceEcuM_Unused::GenerateRamHash(void){
}

FUNC(void, SWCSERVICEECUM_CODE) class_SwcServiceEcuM_Unused::CheckRamHash(void){
}

FUNC(void, SWCSERVICEECUM_CODE) class_SwcServiceEcuM_Unused::ErrorHook(void){
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

/*****************************************************/
/* EOF                                               */
/*****************************************************/

