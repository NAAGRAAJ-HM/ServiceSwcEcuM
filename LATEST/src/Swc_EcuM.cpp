#include "EcuM.h"

#include "Swc_EcuM.h"

class_Swc_EcuM Swc_EcuM;

static void SetProgrammableInterrupts(void){
}

static void DriverInitZero(void){
}

static void DriverInitOne(void){
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
}

