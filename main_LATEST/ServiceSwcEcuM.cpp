/******************************************************************************/
/* File   : ServiceSwcEcuM.cpp                                                */
/*                                                                            */
/* Author : Nagaraja HULIYAPURADA MATA                                        */
/*                                                                            */
/* License / Warranty / Terms and Conditions                                  */
/*                                                                            */
/* Everyone is permitted to copy and distribute verbatim copies of this lice- */
/* nse document, but changing it is not allowed. This is a free, copyright l- */
/* icense for software and other kinds of works. By contrast, this license is */
/* intended to guarantee your freedom to share and change all versions of a   */
/* program, to make sure it remains free software for all its users. You have */
/* certain responsibilities, if you distribute copies of the software, or if  */
/* you modify it: responsibilities to respect the freedom of others.          */
/*                                                                            */
/* All rights reserved. Copyright © 1982 Nagaraja HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/NagarajaHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "ServiceSwcEcuM.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define SERVICESWCECUM_AR_RELEASE_VERSION_MAJOR                                4
#define SERVICESWCECUM_AR_RELEASE_VERSION_MINOR                                3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(SERVICESWCECUM_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible SERVICESWCECUM_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(SERVICESWCECUM_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible SERVICESWCECUM_AR_RELEASE_VERSION_MINOR!"
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
VAR(module_ServiceSwcEcuM, SERVICESWCECUM_VAR) ServiceSwcEcuM;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
static FUNC(void, SERVICESWCECUM_CODE) SetProgrammableInterrupts(
   void
){
}

static FUNC(void, SERVICESWCECUM_CODE) DriverInitX(
            uint8                            lu8SizeDriverInitData
   ,        infServiceEcuMClient*            const* laptrinfServiceEcuMClient
   ,  const ConstModule_TypeAbstract* const* laptrConstModule
   ,        CfgModule_TypeAbstract*   const* laptrCfgModule
){
   for(
      uint8 lu8IndexServiceEcuMClient = 0;
            lu8IndexServiceEcuMClient < lu8SizeDriverInitData;
            lu8IndexServiceEcuMClient ++
   ){
#if(STD_ON == ServiceSwcEcuM_CheckNullPtr)
      if(
            NULL_PTR
         != (laptrinfServiceEcuMClient[lu8IndexServiceEcuMClient]->InitFunction)
      ){
#endif
         laptrinfServiceEcuMClient[lu8IndexServiceEcuMClient]->InitFunction(
               laptrConstModule[lu8IndexServiceEcuMClient]
            ,  laptrCfgModule[lu8IndexServiceEcuMClient]
         );
#if(STD_ON == ServiceSwcEcuM_CheckNullPtr)
      }
      else{
#if(STD_ON == ServiceSwcEcuM_DevErrorDetect)
         ServiceDet_ReportError(
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

#include "Const.hpp"
FUNC(void, SERVICESWCECUM_CODE) module_ServiceSwcEcuM::DriverInitZero(
   void
){
   lptrConst = &(Const.ConstServiceSwcEcuM);

   DriverInitX(
         lptrConst->u8SizeDriverInitData_Zero
      ,  &(lptrConst->aptrinfServiceEcuMClient_Zero[0])
      ,  &(lptrConst->aptrConstModule_Zero[0])
      ,  &(lptrConst->aptrCfgModule_Zero[0])
   );
}

FUNC(void, SERVICESWCECUM_CODE) module_ServiceSwcEcuM::DriverInitOne(
   void
){
   DriverInitX(
         lptrConst->u8SizeDriverInitData_One
      ,  &(lptrConst->aptrinfServiceEcuMClient_One[0])
      ,  &(lptrConst->aptrConstModule_One[0])
      ,  &(lptrConst->aptrCfgModule_One[0])
   );
}

static FUNC(void, SERVICESWCECUM_CODE) OnGoOffOne(
   void
){
}

static FUNC(void, SERVICESWCECUM_CODE) OnGoOffTwo(
   void
){
}

static FUNC(void, SERVICESWCECUM_CODE) Reset(
   void
){
}

static FUNC(void, SERVICESWCECUM_CODE) SwitchOff(
   void
){
}

FUNC(void, SERVICESWCECUM_CODE) module_ServiceSwcEcuM::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, SERVICESWCECUM_CONST,       SERVICESWCECUM_APPL_CONST) lptrConstModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   SERVICESWCECUM_CONFIG_DATA, SERVICESWCECUM_APPL_CONST) lptrCfgModule
){
#if(STD_ON == ServiceSwcEcuM_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrConstModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrConst = (const ConstServiceSwcEcuM_Type*)lptrConstModule;
         lptrCfg   = lptrCfgModule;
      }
      else{
#if(STD_ON == ServiceSwcEcuM_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == ServiceSwcEcuM_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == ServiceSwcEcuM_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SERVICESWCECUM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SERVICESWCECUM_CODE) module_ServiceSwcEcuM::DeInitFunction(
   void
){
#if(STD_ON == ServiceSwcEcuM_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == ServiceSwcEcuM_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == ServiceSwcEcuM_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SERVICESWCECUM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SERVICESWCECUM_CODE) module_ServiceSwcEcuM::MainFunction(
   void
){
#if(STD_ON == ServiceSwcEcuM_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == ServiceSwcEcuM_InitCheck)
   }
   else{
#if(STD_ON == ServiceSwcEcuM_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SERVICESWCECUM_E_UNINIT
      );
#endif
   }
#endif
}

#include "Cfg.hpp"
FUNC(void, SERVICESWCECUM_CODE) module_ServiceSwcEcuM::StartPreServiceOs(
   void
){
   lptrCfg = (CfgServiceSwcEcuM_Type*)&(PBcfgGen_ROM.CfgServiceSwcEcuM);

   SetProgrammableInterrupts();
   DriverInitZero();
   ((ConstServiceSwcEcuM_Type*)lptrConst)->ptrinfServiceEcuM_ServiceSwcEcuM->ServiceDeterminePbConfiguration();

   //Check consistency of configuration data

   DriverInitOne();
   lptrConst->ptrinfServiceEcuM_ServiceSwcEcuM->GetValidatedWakeupEvents();

   //Select default shutdown target

   lptrConst->ptrinfServiceEcuM_ServiceSwcEcuM->LoopServiceDetection();
}

FUNC(void, SERVICESWCECUM_CODE) module_ServiceSwcEcuM::StartPostServiceOs(
   void
){
   lptrConst->ptrinfServiceSchM_ServiceEcuM->Start();
   lptrConst->ptrinfServiceSchM_ServiceEcuM->StartTiming();
}

FUNC(void, SERVICESWCECUM_CODE) module_ServiceSwcEcuM::OffPreServiceOs(
   void
){
   OnGoOffOne();
   ((lptrConst->aptrinfServiceEcuMClient_One)[IndexServiceEcuMClient_ServiceBswM])->DeInitFunction();//TBD: Simplify
   ((lptrConst->aptrinfServiceEcuMClient_One)[IndexServiceEcuMClient_ServiceSchM])->DeInitFunction();//TBD: Simplify

   if(lptrConst->ptrinfServiceEcuM_ServiceSwcEcuM->GetPendingWakeupEvents()){
      lptrConst->ptrinfServiceEcuM_ServiceSwcEcuM->SelectShutdownTarget();
   }
}

FUNC(void, SERVICESWCECUM_CODE) module_ServiceSwcEcuM::OffPostServiceOs(
   void
){
   OnGoOffTwo();
   Reset();
   SwitchOff();
}

FUNC(void, SERVICESWCECUM_CODE) module_ServiceSwcEcuM::EnableWakeupSources(
   void
){
}

FUNC(void, SERVICESWCECUM_CODE) module_ServiceSwcEcuM::GenerateRamHash(
   void
){
}

FUNC(void, SERVICESWCECUM_CODE) module_ServiceSwcEcuM::CheckRamHash(
   void
){
}

FUNC(void, SERVICESWCECUM_CODE) module_ServiceSwcEcuM::ErrorHook(
   void
){
}

// Go to sleep sequence
// ServiceBswM.CurrentWakeupSources();
// ServiceSwcEcuM.EnableWakeupSources();
// ServiceOs.GetResource();

// Go to halt sequence
// ServiceOs.DisableAllInterrupts();
// Swc_EcuE.GenerateRamHash();
// McalMcu.SetMode(HALT);

// Go to poll sequence
// ...

// Go to wake-up restart sequence
// ...

// Go to wake-up validation sequence
// ...

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

