/******************************************************************************/
/* File   : SwcServiceEcuM.cpp                                                */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "SwcServiceEcuM.hpp"
#include "infSwcServiceEcuM_Imp.hpp"

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
CONSTP2VAR(infSwcServiceEcuM_EcuM, SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) gptrinfSwcServiceEcuM_EcuM = &SwcServiceEcuM;

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
      const CfgEcuM_TypeDriverInitData* const lptrDriverInitData
   ,  uint8 luint8ListSize
){
   P2CONST(CfgEcuM_TypeDriverInitData, SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) DriverInitData_Indexed;
   for(
         uint8 luint8IndexEcuMClient = 0
      ;        luint8IndexEcuMClient < luint8ListSize 
      ;        luint8IndexEcuMClient ++
   ){
      DriverInitData_Indexed = &lptrDriverInitData[luint8IndexEcuMClient];
#if(STD_ON == SwcServiceEcuM_CheckNullPtr)
      if(
            NULL_PTR
         == (DriverInitData_Indexed->lptrinfEcuMClient_Module->InitFunction)
      ){
#if(STD_ON == SwcServiceEcuM_DevErrorDetect)
         Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
         );
#endif
      }
      else{
#endif
         DriverInitData_Indexed->lptrinfEcuMClient_Module->InitFunction(
            DriverInitData_Indexed->ptrPBcfgModule
         );
#if(STD_ON == SwcServiceEcuM_CheckNullPtr)
      }
#endif
   }
}

#include "CfgGen.hpp"
static FUNC(void, SWCSERVICEECUM_CODE) DriverInitZero(
   void
){
   DriverInitX(
         CfgGen_NvM.CfgSwcServiceEcuM.laDriverInitDataZero //TBD: lptrCfg
      ,  (
               sizeof(CfgGen_NvM.CfgSwcServiceEcuM.laDriverInitDataZero)
            /  sizeof(CfgEcuM_TypeDriverInitData)
         )
   );
}

static FUNC(void, SWCSERVICEECUM_CODE) DriverInitOne(
   void
){
   DriverInitX(
         CfgGen_NvM.CfgSwcServiceEcuM.laDriverInitDataOne //TBD: lptrCfg
      ,  (
               sizeof(CfgGen_NvM.CfgSwcServiceEcuM.laDriverInitDataOne)
            /  sizeof(CfgEcuM_TypeDriverInitData)
         )
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

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::StartPreOs(
   void
){
   SetProgrammableInterrupts();
   DriverInitZero();
   gptrinfEcuM_SwcServiceEcuM->DeterminePbConfiguration();

   //Check consistency of configuration data

   DriverInitOne();
   gptrinfEcuM_SwcServiceEcuM->GetValidatedWakeupEvents();

   //Select default shutdown target

   gptrinfEcuM_SwcServiceEcuM->LoopDetection();
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::StartPostOs(
   void
){
   gptrinfSchM_EcuM->Start();
   CfgGen_NvM.CfgSwcServiceEcuM.laDriverInitDataOne[IndexEcuMClient_BswM].lptrinfEcuMClient_Module->InitFunction((&CfgGen_NvM.CfgBswM));//TBD: lptrCfg
   CfgGen_NvM.CfgSwcServiceEcuM.laDriverInitDataOne[IndexEcuMClient_SchM].lptrinfEcuMClient_Module->InitFunction((&CfgGen_NvM.CfgSchM));
   gptrinfSchM_EcuM->StartTiming();
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::OffPreOs(
   void
){
   OnGoOffOne();
   CfgGen_NvM.CfgSwcServiceEcuM.laDriverInitDataOne[IndexEcuMClient_BswM].lptrinfEcuMClient_Module->DeInitFunction();//TBD: lptrCfg
   CfgGen_NvM.CfgSwcServiceEcuM.laDriverInitDataOne[IndexEcuMClient_SchM].lptrinfEcuMClient_Module->DeInitFunction();

   if(gptrinfEcuM_SwcServiceEcuM->GetPendingWakeupEvents()){
      gptrinfEcuM_SwcServiceEcuM->SelectShutdownTarget();
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

