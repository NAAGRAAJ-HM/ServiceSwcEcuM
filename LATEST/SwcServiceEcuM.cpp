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
      uint8                            lu8SizeDriverInitData
   ,  infEcuMClient*            const* laptrinfEcuMClient
   ,  ConstModule_TypeAbstract* const* laptrConstModule
   ,  CfgModule_TypeAbstract*   const* laptrCfgModule
){
   for(
      uint8 lu8IndexEcuMClient = 0;
            lu8IndexEcuMClient < lu8SizeDriverInitData;
            lu8IndexEcuMClient ++
   ){
#if(STD_ON == SwcServiceEcuM_CheckNullPtr)
      if(
            NULL_PTR
         != (laptrinfEcuMClient[lu8IndexEcuMClient]->InitFunction)
      ){
#endif
         laptrinfEcuMClient[lu8IndexEcuMClient]->InitFunction(
               laptrConstModule[lu8IndexEcuMClient]
            ,  laptrCfgModule[lu8IndexEcuMClient]
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

#include "Const.hpp"
FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::DriverInitZero(
   void
){
   lptrConst = &(Const.ConstSwcServiceEcuM);

   DriverInitX(
         lptrConst->u8SizeDriverInitData_Zero
      ,  &(lptrConst->aptrinfEcuMClient_Zero[0])
      ,  &(lptrConst->aptrConstModule_Zero[0])
      ,  &(lptrConst->aptrCfgModule_Zero[0])
   );
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::DriverInitOne(
   void
){
   DriverInitX(
         lptrConst->u8SizeDriverInitData_One
      ,  &(lptrConst->aptrinfEcuMClient_One[0])
      ,  &(lptrConst->aptrConstModule_One[0])
      ,  &(lptrConst->aptrCfgModule_One[0])
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
      CONSTP2CONST(ConstModule_TypeAbstract, SWCSERVICEECUM_CONST,       SWCSERVICEECUM_APPL_CONST) lptrConstModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   SWCSERVICEECUM_CONFIG_DATA, SWCSERVICEECUM_APPL_CONST) lptrCfgModule
){
#if(STD_ON == SwcServiceEcuM_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrConstModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrConst = lptrConstModule;
         lptrCfg   = lptrCfgModule;
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
   ((ConstSwcServiceEcuM_Type*)lptrConst)->ptrinfEcuM_SwcServiceEcuM->DeterminePbConfiguration();

   //Check consistency of configuration data

   DriverInitOne();
   lptrConst->ptrinfEcuM_SwcServiceEcuM->GetValidatedWakeupEvents();

   //Select default shutdown target

   lptrConst->ptrinfEcuM_SwcServiceEcuM->LoopDetection();
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::StartPostOs(
   void
){
   lptrConst->ptrinfSchM_EcuM->Start();
   lptrConst->ptrinfSchM_EcuM->StartTiming();
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::OffPreOs(
   void
){
   OnGoOffOne();
   ((lptrConst->aptrinfEcuMClient_One)[IndexEcuMClient_BswM])->DeInitFunction();//TBD: Simplify
   ((lptrConst->aptrinfEcuMClient_One)[IndexEcuMClient_SchM])->DeInitFunction();//TBD: Simplify

   if(lptrConst->ptrinfEcuM_SwcServiceEcuM->GetPendingWakeupEvents()){
      lptrConst->ptrinfEcuM_SwcServiceEcuM->SelectShutdownTarget();
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

