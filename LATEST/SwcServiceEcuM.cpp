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

#include "Adc_EcuM.h"
#include "BswM_EcuM.h"
#include "Can_EcuM.h"
#include "Dem_EcuM.h"
#include "Det_EcuM.h"
#include "Eth_EcuM.h"
#include "Fls_EcuM.h"
#include "Fr_EcuM.h"
#include "Gpt_EcuM.h"
#include "Icu_EcuM.h"
#include "Lin_EcuM.h"
#include "Mcu_EcuM.h"
#include "NvM_EcuM.h"
#include "Ocu_EcuM.h"
#include "Port_EcuM.h"
#include "Pwm_EcuM.h"
#include "SchM_EcuM.h"
#include "Spi_EcuM.h"
#include "Wdg_EcuM.h"
#include "WdgM_EcuM.h"

#include "EcuM_SwcServiceEcuM.h"

static FUNC(void, SWCSERVICEECUM_CODE) DriverInitZero(void){
   infEcuMClient* gptrinfEcuMClient_Det = 0;
   infEcuMClient* gptrinfEcuMClient_Dem = 0;
   infEcuMClient* gptrinfEcuMClient_Fls = 0;
   infEcuMClient* gptrinfEcuMClient_NvM = 0;

   gptrinfEcuMClient_Det->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Dem->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Fls->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_NvM->InitFunction(/*configuration abstract type*/);
}

static FUNC(void, SWCSERVICEECUM_CODE) DriverInitOne(void){
   infEcuMClient* gptrinfEcuMClient_Mcu = 0;
   infEcuMClient* gptrinfEcuMClient_Port = 0;
   infEcuMClient* gptrinfEcuMClient_Gpt = 0;
   infEcuMClient* gptrinfEcuMClient_Wdg = 0;
   infEcuMClient* gptrinfEcuMClient_WdgM = 0;
   infEcuMClient* gptrinfEcuMClient_Adc = 0;
   infEcuMClient* gptrinfEcuMClient_Icu = 0;
   infEcuMClient* gptrinfEcuMClient_Ocu = 0;
   infEcuMClient* gptrinfEcuMClient_Can = 0;
   infEcuMClient* gptrinfEcuMClient_Eth = 0;
   infEcuMClient* gptrinfEcuMClient_Fr = 0;
   infEcuMClient* gptrinfEcuMClient_Lin = 0;
   infEcuMClient* gptrinfEcuMClient_Pwm = 0;
   infEcuMClient* gptrinfEcuMClient_Spi = 0;

   gptrinfEcuMClient_Mcu->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Port->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Gpt->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Wdg->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_WdgM->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Adc->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Icu->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Ocu->InitFunction(/*configuration abstract type*/);

   gptrinfEcuMClient_Can->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Eth->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Fr->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Lin->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Pwm->InitFunction(/*configuration abstract type*/);
   gptrinfEcuMClient_Spi->InitFunction(/*configuration abstract type*/);
/*
   gptrinfEcuMClient_CanTrcv->InitFunction(configuration abstract type);
   gptrinfEcuMClient_Com->InitFunction(configuration abstract type);
   gptrinfEcuMClient_Nm->InitFunction(configuration abstract type);
   gptrinfEcuMClient_EthSwt->InitFunction(configuration abstract type);
   gptrinfEcuMClient_EthTrcv->InitFunction(configuration abstract type);
   gptrinfEcuMClient_FrTrcv->InitFunction(configuration abstract type);
   gptrinfEcuMClient_IoAbHw->InitFunction(configuration abstract type);
   gptrinfEcuMClient_LinTrcv->InitFunction(configuration abstract type);
   gptrinfEcuMClient_Os->InitFunction(configuration abstract type);
*/
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

