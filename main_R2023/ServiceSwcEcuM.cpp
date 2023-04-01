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

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

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

#include "infServiceNvM_ServiceEcuM.hpp"
#include "ReSimFm.hpp"
#include "ReSimCmd.hpp"
FUNC(void, SERVICESWCECUM_CODE) module_ServiceSwcEcuM::DriverInitZero(void){
// ReSim.InitFunction(); TBD: Enable ReSimFm again
   ReSimCmd_InitFunction();

   lptrNvMBlocksRom = &(NvM_BlocksRom.NvM_BlocksRom_ServiceSwcEcuM); // TBD: OOPS concepts
   DriverInitX(
         ((NvM_BlocksRom_ServiceSwcEcuM_Type*)lptrNvMBlocksRom)->u8SizeDriverInitData_Zero
      ,  &(((NvM_BlocksRom_ServiceSwcEcuM_Type*)lptrNvMBlocksRom)->aptrinfServiceEcuMClient_Zero[0])
      ,  &(((NvM_BlocksRom_ServiceSwcEcuM_Type*)lptrNvMBlocksRom)->aptrConstModule_Zero[0])
      ,  &(((NvM_BlocksRom_ServiceSwcEcuM_Type*)lptrNvMBlocksRom)->aptrCfgModule_Zero[0])
   );
}

FUNC(void, SERVICESWCECUM_CODE) module_ServiceSwcEcuM::DriverInitOne(void){
   DriverInitX(
         ((NvM_BlocksRom_ServiceSwcEcuM_Type*)lptrNvMBlocksRom)->u8SizeDriverInitData_One
      ,  &(((NvM_BlocksRom_ServiceSwcEcuM_Type*)lptrNvMBlocksRom)->aptrinfServiceEcuMClient_One[0])
      ,  &(((NvM_BlocksRom_ServiceSwcEcuM_Type*)lptrNvMBlocksRom)->aptrConstModule_One[0])
      ,  &(((NvM_BlocksRom_ServiceSwcEcuM_Type*)lptrNvMBlocksRom)->aptrCfgModule_One[0])
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
      CONSTP2CONST(ConstModule_TypeAbstract, SERVICESWCECUM_CONST,       SERVICESWCECUM_APPL_CONST) lptrNvMBlocksRomModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   SERVICESWCECUM_CONFIG_DATA, SERVICESWCECUM_APPL_CONST) lptrCfgModule
){
#if(STD_ON == ServiceSwcEcuM_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrNvMBlocksRomModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrNvMBlocksRom = lptrNvMBlocksRomModule;
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

extern const NvM_BlocksRom_Type NvM_BlocksRom;  //TBD: move to header
extern const NvM_BlocksNv_Type NvM_BlocksNvRom; //TBD: move to header
extern       NvM_BlocksNv_Type NvM_BlocksNvRam; //TBD: move to header
extern const NvM_BlocksNv_Type Fls_Blocks;      //TBD: move to header

FUNC(void, SERVICESWCECUM_CODE) module_ServiceSwcEcuM::StartPreServiceOs(
   void
){
   lptrCfg = (NvM_BlocksNv_ServiceSwcEcuM_Type*)&(NvM_BlocksNvRom.NvM_BlocksNv_ServiceSwcEcuM);

   SetProgrammableInterrupts();
   DriverInitZero();
   ((NvM_BlocksRom_ServiceSwcEcuM_Type*)lptrNvMBlocksRom)->ptrinfServiceEcuM_ServiceSwcEcuM->ServiceDeterminePbConfiguration();

   //Check consistency of configuration data

   DriverInitOne();
   ((NvM_BlocksRom_ServiceSwcEcuM_Type*)lptrNvMBlocksRom)->ptrinfServiceEcuM_ServiceSwcEcuM->GetValidatedWakeupEvents();

   //Select default shutdown target

   ((NvM_BlocksRom_ServiceSwcEcuM_Type*)lptrNvMBlocksRom)->ptrinfServiceEcuM_ServiceSwcEcuM->LoopServiceDetection();
}

FUNC(void, SERVICESWCECUM_CODE) module_ServiceSwcEcuM::StartPostServiceOs(
   void
){
   ((NvM_BlocksRom_ServiceSwcEcuM_Type*)lptrNvMBlocksRom)->ptrinfServiceSchM_ServiceEcuM->Start();
   ((NvM_BlocksRom_ServiceSwcEcuM_Type*)lptrNvMBlocksRom)->ptrinfServiceSchM_ServiceEcuM->StartTiming();
}

FUNC(void, SERVICESWCECUM_CODE) module_ServiceSwcEcuM::OffPreServiceOs(
   void
){
   OnGoOffOne();
   ((((NvM_BlocksRom_ServiceSwcEcuM_Type*)lptrNvMBlocksRom)->aptrinfServiceEcuMClient_One)[IndexServiceEcuMClient_ServiceBswM])->DeInitFunction();//TBD: Simplify
   ((((NvM_BlocksRom_ServiceSwcEcuM_Type*)lptrNvMBlocksRom)->aptrinfServiceEcuMClient_One)[IndexServiceEcuMClient_ServiceSchM])->DeInitFunction();//TBD: Simplify

   if(((NvM_BlocksRom_ServiceSwcEcuM_Type*)lptrNvMBlocksRom)->ptrinfServiceEcuM_ServiceSwcEcuM->GetPendingWakeupEvents()){
      ((NvM_BlocksRom_ServiceSwcEcuM_Type*)lptrNvMBlocksRom)->ptrinfServiceEcuM_ServiceSwcEcuM->SelectShutdownTarget();
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

