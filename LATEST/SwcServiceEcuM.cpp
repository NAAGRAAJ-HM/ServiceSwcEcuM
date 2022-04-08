/******************************************************************************/
/* File   : SwcServiceEcuM.cpp                                                */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "infSwcServiceEcuM_EcuM.hpp"
#include "infSwcServiceEcuM_Dcm.hpp"
#include "infSwcServiceEcuM_SchM.hpp"

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
class module_SwcServiceEcuM:
      public abstract_module
   ,  public infSwcServiceEcuM_EcuM
{
   public:
      module_SwcServiceEcuM(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, SWCSERVICEECUM_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, SWCSERVICEECUM_CONFIG_DATA, SWCSERVICEECUM_APPL_CONST) lptrCfgModule
      );
      FUNC(void, SWCSERVICEECUM_CODE) DeInitFunction (void);
      FUNC(void, SWCSERVICEECUM_CODE) MainFunction   (void);

      FUNC(void, SWCSERVICEECUM_CODE) StartPreOs     (void);
      FUNC(void, SWCSERVICEECUM_CODE) StartPostOs    (void);
      FUNC(void, SWCSERVICEECUM_CODE) OffPreOs       (void);
      FUNC(void, SWCSERVICEECUM_CODE) OffPostOs      (void);
};

extern VAR(module_SwcServiceEcuM, SWCSERVICEECUM_VAR) SwcServiceEcuM;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient,          SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) gptrinfEcuMClient_SwcServiceEcuM = &SwcServiceEcuM;
CONSTP2VAR(infDcmClient,           SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) gptrinfDcmClient_SwcServiceEcuM  = &SwcServiceEcuM;
CONSTP2VAR(infSchMClient,          SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) gptrinfSchMClient_SwcServiceEcuM = &SwcServiceEcuM;
CONSTP2VAR(infSwcServiceEcuM_EcuM, SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) gptrinfSwcServiceEcuM_EcuM       = &SwcServiceEcuM;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/
//#include "CfgSwcServiceEcuM.hpp"

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_SwcServiceEcuM, SWCSERVICEECUM_VAR) SwcServiceEcuM(
   {
         SWCSERVICEECUM_AR_RELEASE_VERSION_MAJOR
      ,  SWCSERVICEECUM_AR_RELEASE_VERSION_MINOR
      ,  0x00
      ,  0xFF
      ,  0x01
      ,  '0'
      ,  '1'
      ,  '0'
   }
);

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
static FUNC(void, SWCSERVICEECUM_CODE) SetProgrammableInterrupts(void){
}

typedef struct{
   CONSTP2VAR(infEcuMClient, SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) lptrinfEcuMClient_Module;
   const CfgModule_TypeAbstract* ptrPBcfgModule;
}CfgEcuM_TypeDriverInitData;

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
      DriverInitData_Indexed->lptrinfEcuMClient_Module->InitFunction(
         DriverInitData_Indexed->ptrPBcfgModule
      );
   }
}

extern const CfgModule_TypeAbstract PBcfgAdc;
extern const CfgModule_TypeAbstract PBcfgBswM;
extern const CfgModule_TypeAbstract PBcfgCan;
extern const CfgModule_TypeAbstract PBcfgCanIf;
extern const CfgModule_TypeAbstract PBcfgCom;
extern const CfgModule_TypeAbstract PBcfgComM;
extern const CfgModule_TypeAbstract PBcfgCry;
extern const CfgModule_TypeAbstract PBcfgCryIf;
extern const CfgModule_TypeAbstract PBcfgCsm;
extern const CfgModule_TypeAbstract PBcfgDcm;
extern const CfgModule_TypeAbstract PBcfgDem;
extern const CfgModule_TypeAbstract PBcfgDet;
extern const CfgModule_TypeAbstract PBcfgDio;
extern const CfgModule_TypeAbstract PBcfgEa;
extern const CfgModule_TypeAbstract PBcfgEcuM;
extern const CfgModule_TypeAbstract PBcfgEep;
extern const CfgModule_TypeAbstract PBcfgEth;
extern const CfgModule_TypeAbstract PBcfgEthIf;
extern const CfgModule_TypeAbstract PBcfgFee;
extern const CfgModule_TypeAbstract PBcfgFiM;
extern const CfgModule_TypeAbstract PBcfgFls;
extern const CfgModule_TypeAbstract PBcfgFr;
extern const CfgModule_TypeAbstract PBcfgFrIf;
extern const CfgModule_TypeAbstract PBcfgGpt;
extern const CfgModule_TypeAbstract PBcfgIcu;
extern const CfgModule_TypeAbstract PBcfgLin;
extern const CfgModule_TypeAbstract PBcfgLinIf;
extern const CfgModule_TypeAbstract PBcfgLinTp;
extern const CfgModule_TypeAbstract PBcfgMcu;
extern const CfgModule_TypeAbstract PBcfgMemIf;
extern const CfgModule_TypeAbstract PBcfgNm;
extern const CfgModule_TypeAbstract PBcfgNvM;
extern const CfgModule_TypeAbstract PBcfgOcu;
extern const CfgModule_TypeAbstract PBcfgOs;
extern const CfgModule_TypeAbstract PBcfgPduR;
extern const CfgModule_TypeAbstract PBcfgPort;
extern const CfgModule_TypeAbstract PBcfgPwm;
extern const CfgModule_TypeAbstract PBcfgSchM;
extern const CfgModule_TypeAbstract PBcfgSecOC;
extern const CfgModule_TypeAbstract PBcfgSokFm;
extern const CfgModule_TypeAbstract PBcfgSpi;
extern const CfgModule_TypeAbstract PBcfgStbM;
extern const CfgModule_TypeAbstract PBcfgVkms;
extern const CfgModule_TypeAbstract PBcfgWdg;
extern const CfgModule_TypeAbstract PBcfgWdgIf;
extern const CfgModule_TypeAbstract PBcfgWdgM;

#include "infDet_EcuM.hpp"
#include "infDem_EcuM.hpp"
#include "infFls_EcuM.hpp"
#include "infNvM_EcuM.hpp"

static const CfgEcuM_TypeDriverInitData laDriverInitDataZero[] = {
      {gptrinfEcuMClient_Det, &PBcfgDet}
   ,  {gptrinfEcuMClient_Dem, &PBcfgDem}
   ,  {gptrinfEcuMClient_Fls, &PBcfgFls}
   ,  {gptrinfEcuMClient_NvM, &PBcfgNvM}
};

static FUNC(void, SWCSERVICEECUM_CODE) DriverInitZero(void){
   DriverInitX(
         laDriverInitDataZero
      ,  (
               sizeof(laDriverInitDataZero)
            /  sizeof(CONSTP2VAR(infEcuMClient, SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST))
         )
   );
}

#include "infCanIf_EcuM.hpp"
#include "infCryIf_EcuM.hpp"
#include "infEa_EcuM.hpp"
#include "infEthIf_EcuM.hpp"
#include "infFee_EcuM.hpp"
#include "infFrIf_EcuM.hpp"
#include "infLinIf_EcuM.hpp"
#include "infLinTp_EcuM.hpp"
#include "infMemIf_EcuM.hpp"
#include "infWdgIf_EcuM.hpp"
#include "infAdc_EcuM.hpp"
#include "infCan_EcuM.hpp"
#include "infCry_EcuM.hpp"
#include "infDio_EcuM.hpp"
#include "infEep_EcuM.hpp"
#include "infEth_EcuM.hpp"
#include "infFr_EcuM.hpp"
#include "infGpt_EcuM.hpp"
#include "infIcu_EcuM.hpp"
#include "infLin_EcuM.hpp"
#include "infMcu_EcuM.hpp"
#include "infOcu_EcuM.hpp"
#include "infPort_EcuM.hpp"
#include "infPwm_EcuM.hpp"
#include "infSpi_EcuM.hpp"
#include "infWdg_EcuM.hpp"
#include "infBswM_EcuM.hpp"
#include "infCom_EcuM.hpp"
#include "infComM_EcuM.hpp"
#include "infCsm_EcuM.hpp"
#include "infDcm_EcuM.hpp"
#include "infEcuM_SwcServiceEcuM.hpp"
#include "infFiM_EcuM.hpp"
#include "infNm_EcuM.hpp"
#include "infOs_EcuM.hpp"
#include "infPduR_EcuM.hpp"
#include "infSchM_EcuM.hpp"
#include "infSecOC_EcuM.hpp"
#include "infSokFm_EcuM.hpp"
#include "infStartUp_EcuM.hpp"
#include "infStbM_EcuM.hpp"
#include "infVkms_EcuM.hpp"
#include "infWdgM_EcuM.hpp"
#include "infRte_EcuM.hpp"
#include "infSwcServiceEcuM_EcuM.hpp"
#include "infSwcServiceOs_EcuM.hpp"

static const CfgEcuM_TypeDriverInitData laDriverInitDataOne[] = {
      {gptrinfEcuMClient_CanIf,          &PBcfgCanIf}
   ,  {gptrinfEcuMClient_CryIf,          &PBcfgCryIf}
   ,  {gptrinfEcuMClient_Ea,             &PBcfgEa}
   ,  {gptrinfEcuMClient_EthIf,          &PBcfgEthIf}
   ,  {gptrinfEcuMClient_Fee,            &PBcfgFee}
   ,  {gptrinfEcuMClient_FrIf,           &PBcfgFrIf}
   ,  {gptrinfEcuMClient_LinIf,          &PBcfgLinIf}
   ,  {gptrinfEcuMClient_LinTp,          &PBcfgLinTp}
   ,  {gptrinfEcuMClient_MemIf,          &PBcfgMemIf}
   ,  {gptrinfEcuMClient_WdgIf,          &PBcfgWdgIf}
   ,  {gptrinfEcuMClient_Adc,            &PBcfgAdc}
   ,  {gptrinfEcuMClient_Can,            &PBcfgCan}
   ,  {gptrinfEcuMClient_Cry,            &PBcfgCry}
   ,  {gptrinfEcuMClient_Dio,            &PBcfgDio}
   ,  {gptrinfEcuMClient_Eep,            &PBcfgEep}
   ,  {gptrinfEcuMClient_Eth,            &PBcfgEth}
// ,  {gptrinfEcuMClient_Fls,            &PBcfgFls}
   ,  {gptrinfEcuMClient_Fr,             &PBcfgFr}
   ,  {gptrinfEcuMClient_Gpt,            &PBcfgGpt}
   ,  {gptrinfEcuMClient_Icu,            &PBcfgIcu}
   ,  {gptrinfEcuMClient_Lin,            &PBcfgLin}
   ,  {gptrinfEcuMClient_Mcu,            &PBcfgMcu}
   ,  {gptrinfEcuMClient_Ocu,            &PBcfgOcu}
   ,  {gptrinfEcuMClient_Port,           &PBcfgPort}
   ,  {gptrinfEcuMClient_Pwm,            &PBcfgPwm}
   ,  {gptrinfEcuMClient_Spi,            &PBcfgSpi}
   ,  {gptrinfEcuMClient_Wdg,            &PBcfgWdg}
// ,  {gptrinfEcuMClient_BswM,           &PBcfgBswM}
   ,  {gptrinfEcuMClient_Com,            &PBcfgCom}
   ,  {gptrinfEcuMClient_ComM,           &PBcfgComM}
   ,  {gptrinfEcuMClient_Csm,            &PBcfgCsm}
   ,  {gptrinfEcuMClient_Dcm,            &PBcfgDcm}
// ,  {gptrinfEcuMClient_Dem,            &PBcfgDem}
// ,  {gptrinfEcuMClient_Det,            &PBcfgDet}
   ,  {gptrinfEcuMClient_FiM,            &PBcfgFiM}
   ,  {gptrinfEcuMClient_Nm,             &PBcfgNm}
// ,  {gptrinfEcuMClient_NvM,            &PBcfgNvM}
// ,  {gptrinfEcuMClient_Os,             &PBcfgOs}
   ,  {gptrinfEcuMClient_PduR,           &PBcfgPduR}
// ,  {gptrinfEcuMClient_SchM,           &PBcfgSchM}
   ,  {gptrinfEcuMClient_SecOC,          &PBcfgSecOC}
   ,  {gptrinfEcuMClient_SokFm,          &PBcfgSokFm}
// ,  {gptrinfEcuMClient_StartUp,        &PBcfgStartUp}
   ,  {gptrinfEcuMClient_StbM,           &PBcfgStbM}
   ,  {gptrinfEcuMClient_Vkms,           &PBcfgVkms}
   ,  {gptrinfEcuMClient_WdgM,           &PBcfgWdgM}
//   ,  {gptrinfEcuMClient_Rte,            &PBcfgRte}
//   ,  {gptrinfEcuMClient_SwcServiceEcuM, &PBcfgSwcServiceEcuM}
//   ,  {gptrinfEcuMClient_SwcServiceOs,   &PBcfgSwcServiceOs}
};

static FUNC(void, SWCSERVICEECUM_CODE) DriverInitOne(void){
   DriverInitX(
         laDriverInitDataOne
      ,  (
               sizeof(laDriverInitDataOne)
            /  sizeof(CONSTP2VAR(CfgEcuM_TypeDriverInitData, SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST))
         )
   );
}

static FUNC(void, SWCSERVICEECUM_CODE) OnGoOffOne(void){
}

static FUNC(void, SWCSERVICEECUM_CODE) OnGoOffTwo(void){
}

static FUNC(void, SWCSERVICEECUM_CODE) Reset(void){
}

static FUNC(void, SWCSERVICEECUM_CODE) SwitchOff(void){
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, SWCSERVICEECUM_CONFIG_DATA, SWCSERVICEECUM_APPL_CONST) lptrCfgModule
){
#if(STD_ON == SwcServiceEcuM_InitCheck)
   if(E_OK == IsInitDone){
#if(STD_ON == SwcServiceEcuM_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
#endif
      if(NULL_PTR == lptrCfgModule){
#if(STD_ON == SwcServiceEcuM_DevErrorDetect)
         Det_ReportError(
         );
#endif
      }
      else{
         if(STD_LOW){
// check lptrCfgModule for memory faults
            lptrCfg = lptrCfgModule;
         }
         else{
// use PBcfgCanIf as back-up configuration
//            lptrCfg = PBcfgSwcServiceEcuM;
         }
      }
      IsInitDone = E_OK;
#if(STD_ON == SwcServiceEcuM_InitCheck)
   }
#endif
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::DeInitFunction(void){
#if(STD_ON == SwcServiceEcuM_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == SwcServiceEcuM_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
#endif
      IsInitDone = E_NOT_OK;
#if(STD_ON == SwcServiceEcuM_InitCheck)
   }
#endif
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::MainFunction(void){
#if(STD_ON == SwcServiceEcuM_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == SwcServiceEcuM_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
#endif
#if(STD_ON == SwcServiceEcuM_InitCheck)
   }
#endif
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::StartPreOs(void){
   SetProgrammableInterrupts();
   DriverInitZero();
   gptrinfEcuM_SwcServiceEcuM->DeterminePbConfiguration();

   //Check consistency of configuration data

   DriverInitOne();
   gptrinfEcuM_SwcServiceEcuM->GetValidatedWakeupEvents();

   //Select default shutdown target

   gptrinfEcuM_SwcServiceEcuM->LoopDetection();
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::StartPostOs(void){
   gptrinfSchM_EcuM->Start();

   gptrinfEcuMClient_BswM->InitFunction(
      (const CfgModule_TypeAbstract*) NULL_PTR /* replace with configuration abstract type */
   );

   gptrinfEcuMClient_SchM->InitFunction(
      (const CfgModule_TypeAbstract*) NULL_PTR /* replace with configuration abstract type */
   );

   gptrinfSchM_EcuM->StartTiming();
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::OffPreOs(void){
   OnGoOffOne();
   gptrinfEcuMClient_BswM->DeInitFunction();
   gptrinfEcuMClient_SchM->DeInitFunction();

   if(gptrinfEcuM_SwcServiceEcuM->GetPendingWakeupEvents()){
      gptrinfEcuM_SwcServiceEcuM->SelectShutdownTarget();
   }
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::OffPostOs(void){
   OnGoOffTwo();
   Reset();
   SwitchOff();
}

class class_SwcServiceEcuM_Unused{
   public:
      FUNC(void, SWCSERVICEECUM_CODE) StartPreOs             (void);
      FUNC(void, SWCSERVICEECUM_CODE) StartPostOs            (void);
      FUNC(void, SWCSERVICEECUM_CODE) OffPreOs               (void);
      FUNC(void, SWCSERVICEECUM_CODE) OffPostOs              (void);
      FUNC(void, SWCSERVICEECUM_CODE) EnableWakeupSources    (void);
      FUNC(void, SWCSERVICEECUM_CODE) GenerateRamHash        (void);
      FUNC(void, SWCSERVICEECUM_CODE) CheckRamHash           (void);
      FUNC(void, SWCSERVICEECUM_CODE) ErrorHook              (void);
};

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

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

