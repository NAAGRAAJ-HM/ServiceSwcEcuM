/*****************************************************/
/* File   : Swc_EcuM.cpp                             */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "EcuM.h"

#include "Swc_EcuM.h"
#include "SchM.h"
#include "BswM.h"

#include "EcuM_Client.h"

#include "Adc_EcuM.h"
#include "Can_EcuM.h"
#include "Dem.h"
#include "Det.h"
#include "Eth_EcuM.h"
#include "Fls_EcuM.h"
#include "Fr_EcuM.h"
#include "Gpt_EcuM.h"
#include "Icu_EcuM.h"
#include "Lin_EcuM.h"
#include "Mcu_EcuM.h"
#include "NvM.h"
#include "Ocu_EcuM.h"
#include "Port_EcuM.h"
#include "Pwm_EcuM.h"
#include "Spi_EcuM.h"
#include "Wdg_EcuM.h"
#include "WdgM.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/

/*****************************************************/
/* CONSTS                                            */
/*****************************************************/

/*****************************************************/
/* PARAMS                                            */
/*****************************************************/

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
class_Swc_EcuM Swc_EcuM;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
static FUNC(void, SWC_ECUM_CODE) SetProgrammableInterrupts(void){
}

static FUNC(void, SWC_ECUM_CODE) DriverInitZero(void){
   Det.InitFunction(/*configuration abstract type*/);
   Dem.InitFunction(/*configuration abstract type*/);
   Fls_EcuM_ptr->InitFunction(/*configuration abstract type*/);
   NvM.InitFunction(/*configuration abstract type*/);
}

static FUNC(void, SWC_ECUM_CODE) DriverInitOne(void){
   Mcu_EcuM_ptr->InitFunction(/*configuration abstract type*/);
   Port_EcuM_ptr->InitFunction(/*configuration abstract type*/);
   Gpt_EcuM_ptr->InitFunction(/*configuration abstract type*/);
   Wdg_EcuM_ptr->InitFunction(/*configuration abstract type*/);
   WdgM.InitFunction(/*configuration abstract type*/);
   Adc_EcuM_ptr->InitFunction(/*configuration abstract type*/);
   Icu_EcuM_ptr->InitFunction(/*configuration abstract type*/);
   Ocu_EcuM_ptr->InitFunction(/*configuration abstract type*/);

   Can_EcuM_ptr->InitFunction(/*configuration abstract type*/);
   Eth_EcuM_ptr->InitFunction(/*configuration abstract type*/);
   Fr_EcuM_ptr->InitFunction(/*configuration abstract type*/);
   Lin_EcuM_ptr->InitFunction(/*configuration abstract type*/);
   Pwm_EcuM_ptr->InitFunction(/*configuration abstract type*/);
   Spi_EcuM_ptr->InitFunction(/*configuration abstract type*/);
/*
   CanTrcv_EcuM_ptr->InitFunction(configuration abstract type);
   Com_EcuM_ptr->InitFunction(configuration abstract type);
   Nm_EcuM_ptr->InitFunction(configuration abstract type);
   EthSwt_EcuM_ptr->InitFunction(configuration abstract type);
   EthTrcv_EcuM_ptr->InitFunction(configuration abstract type);
   FrTrcv_EcuM_ptr->InitFunction(configuration abstract type);
   IoAbHw_EcuM_ptr->InitFunction(configuration abstract type);
   LinTrcv_EcuM_ptr->InitFunction(configuration abstract type);
   Os_EcuM_ptr->InitFunction(configuration abstract type);
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

FUNC(void, SWC_ECUM_CODE) class_Swc_EcuM::StartPreOs(void){
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
   BswM.InitFunction(/*TBD: configuration*/);
   SchM.InitFunction(/*TBD: configuration*/);
   SchM.StartTiming();
}

FUNC(void, SWC_ECUM_CODE) class_Swc_EcuM::OffPreOs(void){
   OnGoOffOne();
   BswM.DeInitFunction();
   SchM.DeInitFunction();

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

