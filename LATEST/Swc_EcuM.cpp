/*****************************************************/
/* File   : Swc_EcuM.cpp                             */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "EcuM.h"

#include "Swc_EcuM_Unused.h"
#include "SchM.h"
#include "BswM.h"

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

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/
class module_Swc_EcuM:
      public class_module
   ,  public interface_Swc_EcuM
{
   public:
      FUNC(void, ECUM_CODE) InitFunction   (void);
      FUNC(void, ECUM_CODE) DeInitFunction (void);
      FUNC(void, ECUM_CODE) MainFunction   (void);
      FUNC(void, ECUM_CODE) StartPreOs     (void);
      FUNC(void, ECUM_CODE) StartPostOs    (void);
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
module_Swc_EcuM Swc_EcuM;

interface_EcuM_Client *EcuM_Client_ptr_Swc_EcuM = &Swc_EcuM;
interface_SchM_Client *SchM_Client_ptr_Swc_EcuM = &Swc_EcuM;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
static FUNC(void, SWC_ECUM_CODE) SetProgrammableInterrupts(void){
}

static FUNC(void, SWC_ECUM_CODE) DriverInitZero(void){
   EcuM_Client_ptr_Det->InitFunction(/*configuration abstract type*/);
   EcuM_Client_ptr_Dem->InitFunction(/*configuration abstract type*/);
   EcuM_Client_ptr_Fls->InitFunction(/*configuration abstract type*/);
   EcuM_Client_ptr_NvM->InitFunction(/*configuration abstract type*/);
}

static FUNC(void, SWC_ECUM_CODE) DriverInitOne(void){
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

static FUNC(void, SWC_ECUM_CODE) OnGoOffOne(void){
}

static FUNC(void, SWC_ECUM_CODE) OnGoOffTwo(void){
}

static FUNC(void, SWC_ECUM_CODE) Reset(void){
}

static FUNC(void, SWC_ECUM_CODE) SwitchOff(void){
}

FUNC(void, ECUM_CODE) module_Swc_EcuM::InitFunction(void){
}

FUNC(void, ECUM_CODE) module_Swc_EcuM::DeInitFunction(void){
}

FUNC(void, ECUM_CODE) module_Swc_EcuM::MainFunction(void){
//TBD MainFunctionRx, MainFunctionTx
}

FUNC(void, SWC_ECUM_CODE) module_Swc_EcuM::StartPreOs(void){
   SetProgrammableInterrupts();
   DriverInitZero();
   EcuM.DeterminePbConfiguration();

   //Check consistency of configuration data

   DriverInitOne();
   EcuM.GetValidatedWakeupEvents();

   //Select default shutdown target

   EcuM.LoopDetection();
}

FUNC(void, SWC_ECUM_CODE) class_Swc_EcuM::StartPostOs(void){
   SchM.Start();
   EcuM_Client_ptr_BswM->InitFunction(/*TBD: configuration*/);
   EcuM_Client_ptr_SchM->InitFunction(/*TBD: configuration*/);
   SchM.StartTiming();
}

FUNC(void, SWC_ECUM_CODE) class_Swc_EcuM::OffPreOs(void){
   OnGoOffOne();
   EcuM_Client_ptr_BswM->DeInitFunction();
   EcuM_Client_ptr_SchM->DeInitFunction();

   if(EcuM.GetPendingWakeupEvents()){
      EcuM.SelectShutdownTarget();
   }
}

FUNC(void, SWC_ECUM_CODE) class_Swc_EcuM::OffPostOs(void){
   OnGoOffTwo();
   Reset();
   SwitchOff();
}

FUNC(void, SWC_ECUM_CODE) class_Swc_EcuM::EnableWakeupSources(void){
}

FUNC(void, SWC_ECUM_CODE) class_Swc_EcuM::GenerateRamHash(void){
}

FUNC(void, SWC_ECUM_CODE) class_Swc_EcuM::CheckRamHash(void){
}

FUNC(void, SWC_ECUM_CODE) class_Swc_EcuM::ErrorHook(void){
}

// Go to sleep sequence
// BswM.CurrentWakeupSources();
// Swc_EcuM.EnableWakeupSources();
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

