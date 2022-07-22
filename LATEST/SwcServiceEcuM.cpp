/******************************************************************************/
/* File   : SwcServiceEcuM.cpp                                                */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "SwcServiceEcuM.hpp"

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

static FUNC(void, SWCSERVICEECUM_CODE) DriverInitX(
      uint8                   lu8SizeDriverInitData
   ,  infEcuMClient*          laptrinfEcuMClient[]
   ,  CfgModule_TypeAbstract* laptrCfgModule[]
){
   for(
         uint8 lu8IndexEcuMClient = 0
      ;        lu8IndexEcuMClient < lu8SizeDriverInitData
      ;        lu8IndexEcuMClient ++
   ){
#if(STD_ON == SwcServiceEcuM_CheckNullPtr)
      if(
            NULL_PTR
         != (laptrinfEcuMClient[lu8IndexEcuMClient]->InitFunction)
      ){
#endif
         laptrinfEcuMClient[lu8IndexEcuMClient]->InitFunction(
            laptrCfgModule[lu8IndexEcuMClient]
         );
#if(STD_ON == SwcServiceEcuM_CheckNullPtr)
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
#endif
   }
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::DriverInitZero(
   void
){
   DriverInitX(
         lptrConstSwcServiceEcuM->u8SizeDriverInitData_Zero
      ,  lptrConstSwcServiceEcuM->aptrinfEcuMClient_Zero
      ,  lptrConstSwcServiceEcuM->aptrCfgModule_Zero
   );
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::DriverInitOne(
   void
){
   DriverInitX(
         lptrConstSwcServiceEcuM->u8SizeDriverInitData_One
      ,  lptrConstSwcServiceEcuM->aptrinfEcuMClient_One
      ,  lptrConstSwcServiceEcuM->aptrCfgModule_One
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

#include "CfgGen.hpp"
FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::StartPreOs(
   void
){
   lptrCfg = (CfgSwcServiceEcuM_Type*)&(PBcfgGen_ROM.CfgSwcServiceEcuM);

   SetProgrammableInterrupts();
   DriverInitZero();
   lptrConstSwcServiceEcuM->ptrinfEcuM_SwcServiceEcuM->DeterminePbConfiguration();

   //Check consistency of configuration data

   DriverInitOne();
   lptrConstSwcServiceEcuM->ptrinfEcuM_SwcServiceEcuM->GetValidatedWakeupEvents();

   //Select default shutdown target

   lptrConstSwcServiceEcuM->ptrinfEcuM_SwcServiceEcuM->LoopDetection();
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::StartPostOs(
   void
){
   lptrConstSwcServiceEcuM->ptrinfSchM_EcuM->Start();
   lptrConstSwcServiceEcuM->ptrinfSchM_EcuM->StartTiming();
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::OffPreOs(
   void
){
   OnGoOffOne();
   ((lptrConstSwcServiceEcuM->aptrinfEcuMClient_One)[IndexEcuMClient_BswM])->DeInitFunction();//TBD: Simplify
   ((lptrConstSwcServiceEcuM->aptrinfEcuMClient_One)[IndexEcuMClient_SchM])->DeInitFunction();//TBD: Simplify

   if(lptrConstSwcServiceEcuM->ptrinfEcuM_SwcServiceEcuM->GetPendingWakeupEvents()){
      lptrConstSwcServiceEcuM->ptrinfEcuM_SwcServiceEcuM->SelectShutdownTarget();
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

