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

#include "EcuM_Client.h"

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
   ,  public interface_SwcServiceEcuM_EcuM
   ,  public interface_SwcServiceEcuM_SchM
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
module_SwcServiceEcuM SwcServiceEcuM;

interface_SwcServiceEcuM_EcuM *EcuM_Client_ptr_SwcServiceEcuM = &SwcServiceEcuM;
interface_SwcServiceEcuM_SchM *SchM_Client_ptr_SwcServiceEcuM = &SwcServiceEcuM;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
static FUNC(void, SWCSERVICEECUM_CODE) SetProgrammableInterrupts(void){
}

static FUNC(void, SWCSERVICEECUM_CODE) DriverInitZero(void){
   EcuM_Client_ptr_Det->InitFunction(/*configuration abstract type*/);
   EcuM_Client_ptr_Dem->InitFunction(/*configuration abstract type*/);
   EcuM_Client_ptr_Fls->InitFunction(/*configuration abstract type*/);
   EcuM_Client_ptr_NvM->InitFunction(/*configuration abstract type*/);
}

static FUNC(void, SWCSERVICEECUM_CODE) DriverInitOne(void){
   EcuM_Client_ptr_Mcu->InitFunction(/*configuration abstract type*/);
   EcuM_Client_ptr_Port->InitFunction(/*configuration abstract type*/);
   EcuM_Client_ptr_Gpt->InitFunction(/*configuration abstract type*/);
   EcuM_Client_ptr_Wdg->InitFunction(/*configuration abstract type*/);
   EcuM_Client_ptr_WdgM->InitFunction(/*configuration abstract type*/);
   EcuM_Client_ptr_Adc->InitFunction(/*configuration abstract type*/);
   EcuM_Client_ptr_Icu->InitFunction(/*configuration abstract type*/);
   EcuM_Client_ptr_Ocu->InitFunction(/*configuration abstract type*/);

   EcuM_Client_ptr_Can->InitFunction(/*configuration abstract type*/);
   EcuM_Client_ptr_Eth->InitFunction(/*configuration abstract type*/);
   EcuM_Client_ptr_Fr->InitFunction(/*configuration abstract type*/);
   EcuM_Client_ptr_Lin->InitFunction(/*configuration abstract type*/);
   EcuM_Client_ptr_Pwm->InitFunction(/*configuration abstract type*/);
   EcuM_Client_ptr_Spi->InitFunction(/*configuration abstract type*/);
/*
   EcuM_Client_ptr_CanTrcv->InitFunction(configuration abstract type);
   EcuM_Client_ptr_Com->InitFunction(configuration abstract type);
   EcuM_Client_ptr_Nm->InitFunction(configuration abstract type);
   EcuM_Client_ptr_EthSwt->InitFunction(configuration abstract type);
   EcuM_Client_ptr_EthTrcv->InitFunction(configuration abstract type);
   EcuM_Client_ptr_FrTrcv->InitFunction(configuration abstract type);
   EcuM_Client_ptr_IoAbHw->InitFunction(configuration abstract type);
   EcuM_Client_ptr_LinTrcv->InitFunction(configuration abstract type);
   EcuM_Client_ptr_Os->InitFunction(configuration abstract type);
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
   SwcServiceEcuM_Client_ptr_EcuM->DeterminePbConfiguration();

   //Check consistency of configuration data

   DriverInitOne();
   SwcServiceEcuM_Client_ptr_EcuM->GetValidatedWakeupEvents();

   //Select default shutdown target

   SwcServiceEcuM_Client_ptr_EcuM->LoopDetection();
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::StartPostOs(void){
   EcuM_Client_ptr_SchM->Start();
   EcuM_Client_ptr_BswM->InitFunction(/*TBD: configuration*/);
   EcuM_Client_ptr_SchM->InitFunction(/*TBD: configuration*/);
   EcuM_Client_ptr_SchM->StartTiming();
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::OffPreOs(void){
   OnGoOffOne();
   EcuM_Client_ptr_BswM->DeInitFunction();
   EcuM_Client_ptr_SchM->DeInitFunction();

   if(SwcServiceEcuM_Client_ptr_EcuM->GetPendingWakeupEvents()){
      SwcServiceEcuM_Client_ptr_EcuM->SelectShutdownTarget();
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

