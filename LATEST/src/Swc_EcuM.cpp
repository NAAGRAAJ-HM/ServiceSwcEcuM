#include "EcuM.h"

#include "Swc_EcuM.h"
#include "SchM.h"
#include "BswM.h"

 #include "Det.h"
 #include "Dem.h"
 #include "Fls.h"
 #include "NvM.h"
 #include "Mcu.h"
 #include "Port.h"
 #include "Gpt.h"
 #include "Wdg.h"
 #include "WdgM.h"
 #include "Adc.h"
 #include "Icu.h"
 #include "Ocu.h"

class_Swc_EcuM Swc_EcuM;

static void SetProgrammableInterrupts(void){
}

static void DriverInitZero(void){
   Det.InitFunction(/*configuration abstract type*/);
   Dem.InitFunction(/*configuration abstract type*/);
   Fls.InitFunction(/*configuration abstract type*/);
   NvM.InitFunction(/*configuration abstract type*/);
}

static void DriverInitOne(void){
   Mcu.InitFunction(/*configuration abstract type*/);
   Port.InitFunction(/*configuration abstract type*/);
   Gpt.InitFunction(/*configuration abstract type*/);
   Wdg.InitFunction(/*configuration abstract type*/);
   WdgM.InitFunction(/*configuration abstract type*/);
   Adc.InitFunction(/*configuration abstract type*/);
   Icu.InitFunction(/*configuration abstract type*/);
   Ocu.InitFunction(/*configuration abstract type*/);
/*
BswM.InitFunction(configuration abstract type);
Can.InitFunction(configuration abstract type);
CanTrcv.InitFunction(configuration abstract type);
Com.InitFunction(configuration abstract type);
Nm.InitFunction(configuration abstract type);
Eth.InitFunction(configuration abstract type);
EthSwt.InitFunction(configuration abstract type);
EthTrcv.InitFunction(configuration abstract type);
Fr.InitFunction(configuration abstract type);
FrTrcv.InitFunction(configuration abstract type);
IoAbHw.InitFunction(configuration abstract type);
Lin.InitFunction(configuration abstract type);
LinTrcv.InitFunction(configuration abstract type);
Os.InitFunction(configuration abstract type);
Pwm.InitFunction(configuration abstract type);
SchM.InitFunction(configuration abstract type);
Spi.InitFunction(configuration abstract type);
*/
}

static void OnGoOffOne(void){
}

static void OnGoOffTwo(void){
}

static void Reset(void){
}

static void SwitchOff(void){
}

void class_Swc_EcuM::StartPreOs(void){
   SetProgrammableInterrupts();
   DriverInitZero();
   EcuM.DeterminePbConfiguration();

   //Check consistency of configuration data

   DriverInitOne();
   EcuM.GetValidatedWakeupEvents();

   //Select default shutdown target

   EcuM.LoopDetection();
}

void class_Swc_EcuM::StartPostOs(void){
   SchM.Start();
   BswM.InitFunction(/*TBD: configuration*/);
   SchM.InitFunction(/*TBD: configuration*/);
   SchM.StartTiming();
}

void class_Swc_EcuM::OffPreOs(void){
   OnGoOffOne();
   BswM.DeInitFunction();
   SchM.DeInitFunction();

   if(EcuM.GetPendingWakeupEvents()){
      EcuM.SelectShutdownTarget();
   }
}

void class_Swc_EcuM::OffPostOs(void){
   OnGoOffTwo();
   Reset();
   SwitchOff();
}

void class_Swc_EcuM::EnableWakeupSources(void){
}

void class_Swc_EcuM::GenerateRamHash(void){
}

void class_Swc_EcuM::CheckRamHash(void){
}

void class_Swc_EcuM::ErrorHook(void){
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

