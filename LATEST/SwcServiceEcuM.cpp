/*****************************************************/
/* File   : SwcServiceEcuM.cpp                       */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "module.h"
#include "SwcServiceEcuM_EcuM.h"
#include "SwcServiceEcuM_SchM.h"
#include "SwcServiceEcuM_Unused.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/
class module_SwcServiceEcuM:
      public abstract_module
   ,  public infSwcServiceEcuM_EcuM
{
   public:
      FUNC(void, SWCSERVICEECUM_CODE) InitFunction   (void);
      FUNC(void, SWCSERVICEECUM_CODE) DeInitFunction (void);
      FUNC(void, SWCSERVICEECUM_CODE) MainFunction   (void);
      FUNC(void, SWCSERVICEECUM_CODE) StartPreOs     (void);
      FUNC(void, SWCSERVICEECUM_CODE) StartPostOs    (void);
      FUNC(void, SWCSERVICEECUM_CODE) OffPreOs       (void);
      FUNC(void, SWCSERVICEECUM_CODE) OffPostOs      (void);
};

/*****************************************************/
/* CONSTS                                            */
/*****************************************************/

/*****************************************************/
/* PARAMS                                            */
/*****************************************************/

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
module_SwcServiceEcuM   SwcServiceEcuM;
infEcuMClient*          gptrinfEcuMClient_SwcServiceEcuM = &SwcServiceEcuM;
infSchMClient*          gptrinfSchMClient_SwcServiceEcuM = &SwcServiceEcuM;
infSwcServiceEcuM_EcuM* gptrinfSwcServiceEcuM_EcuM       = &SwcServiceEcuM;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
static FUNC(void, SWCSERVICEECUM_CODE) SetProgrammableInterrupts(void){
}

#include "CanIf_EcuM.h"
#include "CryIf_EcuM.h"
#include "Ea_EcuM.h"
#include "EthIf_EcuM.h"
#include "Fee_EcuM.h"
#include "FrIf_EcuM.h"
#include "LinIf_EcuM.h"
#include "LinTp_EcuM.h"
#include "MemIf_EcuM.h"
#include "WdgIf_EcuM.h"
#include "Adc_EcuM.h"
#include "Can_EcuM.h"
#include "Cry_EcuM.h"
#include "Dio_EcuM.h"
#include "Eep_EcuM.h"
#include "Eth_EcuM.h"
#include "Fls_EcuM.h"
#include "Fr_EcuM.h"
#include "Gpt_EcuM.h"
#include "Icu_EcuM.h"
#include "Lin_EcuM.h"
#include "Mcu_EcuM.h"
#include "Ocu_EcuM.h"
#include "Port_EcuM.h"
#include "Pwm_EcuM.h"
#include "Spi_EcuM.h"
#include "Wdg_EcuM.h"
#include "BswM_EcuM.h"
#include "Com_EcuM.h"
#include "ComM_EcuM.h"
#include "Csm_EcuM.h"
#include "Dcm_EcuM.h"
#include "Dem_EcuM.h"
#include "Det_EcuM.h"
#include "FiM_EcuM.h"
#include "Nm_EcuM.h"
#include "NvM_EcuM.h"
#include "Os_EcuM.h"
#include "PduR_EcuM.h"
#include "SchM_EcuM.h"
#include "SecOC_EcuM.h"
#include "SokFm_EcuM.h"
#include "StartUp_EcuM.h"
#include "StbM_EcuM.h"
#include "Vkms_EcuM.h"
#include "WdgM_EcuM.h"
#include "Rte_EcuM.h"
#include "SwcServiceEcuM_EcuM.h"
#include "SwcServiceOs_EcuM.h"

#include "EcuM_SwcServiceEcuM.h"

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

