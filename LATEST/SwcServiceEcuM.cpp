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
#define SWCSERVICEECUM_AR_RELEASE_MAJOR_VERSION                                4
#define SWCSERVICEECUM_AR_RELEASE_MINOR_VERSION                                3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(SWCSERVICEECUM_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION)
   #error "Incompatible SWCSERVICEECUM_AR_RELEASE_MAJOR_VERSION!"
#endif

#if(SWCSERVICEECUM_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)
   #error "Incompatible SWCSERVICEECUM_AR_RELEASE_MINOR_VERSION!"
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
         0x0000
      ,  0xFFFF
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

static FUNC(void, SWCSERVICEECUM_CODE) DriverInitX(
      const CONSTP2VAR(infEcuMClient, SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) *laptrinfEcuMClient_DriverInitList
   ,  uint8 luint8ListSize 
){
   P2VAR(infEcuMClient, SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) lptrinfEcuMClient_Indexed;
   for(
         uint8 luint8IndexEcuMClient = 0
      ;        luint8IndexEcuMClient < luint8ListSize 
      ;        luint8IndexEcuMClient ++
   ){
      lptrinfEcuMClient_Indexed = (P2VAR(infEcuMClient, SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST))laptrinfEcuMClient_DriverInitList[luint8IndexEcuMClient];
      lptrinfEcuMClient_Indexed->InitFunction(
         (const CfgModule_TypeAbstract*) NULL_PTR /* replace with configuration abstract type */
      );
   }
}

#include "infDet_EcuM.hpp"
#include "infDem_EcuM.hpp"
#include "infFls_EcuM.hpp"
#include "infNvM_EcuM.hpp"

static const CONSTP2VAR(infEcuMClient, SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) laptrinfEcuMClient_DriverInitZero[] = {
      gptrinfEcuMClient_Det
   ,  gptrinfEcuMClient_Dem
   ,  gptrinfEcuMClient_Fls
   ,  gptrinfEcuMClient_NvM
};

static FUNC(void, SWCSERVICEECUM_CODE) DriverInitZero(void){
   DriverInitX(
         laptrinfEcuMClient_DriverInitZero
      ,  (
               sizeof(laptrinfEcuMClient_DriverInitZero)
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

static const CONSTP2VAR(infEcuMClient, SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) laptrinfEcuMClient_DriverInitOne[] = {
      gptrinfEcuMClient_CanIf
   ,  gptrinfEcuMClient_CryIf
   ,  gptrinfEcuMClient_Ea
   ,  gptrinfEcuMClient_EthIf
   ,  gptrinfEcuMClient_Fee
   ,  gptrinfEcuMClient_FrIf
   ,  gptrinfEcuMClient_LinIf
   ,  gptrinfEcuMClient_LinTp
   ,  gptrinfEcuMClient_MemIf
   ,  gptrinfEcuMClient_WdgIf
   ,  gptrinfEcuMClient_Adc
   ,  gptrinfEcuMClient_Can
   ,  gptrinfEcuMClient_Cry
   ,  gptrinfEcuMClient_Dio
   ,  gptrinfEcuMClient_Eep
   ,  gptrinfEcuMClient_Eth
// ,  gptrinfEcuMClient_Fls
   ,  gptrinfEcuMClient_Fr
   ,  gptrinfEcuMClient_Gpt
   ,  gptrinfEcuMClient_Icu
   ,  gptrinfEcuMClient_Lin
   ,  gptrinfEcuMClient_Mcu
   ,  gptrinfEcuMClient_Ocu
   ,  gptrinfEcuMClient_Port
   ,  gptrinfEcuMClient_Pwm
   ,  gptrinfEcuMClient_Spi
   ,  gptrinfEcuMClient_Wdg
// ,  gptrinfEcuMClient_BswM
   ,  gptrinfEcuMClient_Com
   ,  gptrinfEcuMClient_ComM
   ,  gptrinfEcuMClient_Csm
   ,  gptrinfEcuMClient_Dcm
// ,  gptrinfEcuMClient_Dem
// ,  gptrinfEcuMClient_Det
   ,  gptrinfEcuMClient_FiM
   ,  gptrinfEcuMClient_Nm
// ,  gptrinfEcuMClient_NvM
// ,  gptrinfEcuMClient_Os
   ,  gptrinfEcuMClient_PduR
// ,  gptrinfEcuMClient_SchM
   ,  gptrinfEcuMClient_SecOC
   ,  gptrinfEcuMClient_SokFm
// ,  gptrinfEcuMClient_StartUp
   ,  gptrinfEcuMClient_StbM
   ,  gptrinfEcuMClient_Vkms
   ,  gptrinfEcuMClient_WdgM
   ,  gptrinfEcuMClient_Rte
   ,  gptrinfEcuMClient_SwcServiceEcuM
   ,  gptrinfEcuMClient_SwcServiceOs
};

static FUNC(void, SWCSERVICEECUM_CODE) DriverInitOne(void){
   DriverInitX(
         laptrinfEcuMClient_DriverInitOne
      ,  (
               sizeof(laptrinfEcuMClient_DriverInitOne)
            /  sizeof(CONSTP2VAR(infEcuMClient, SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST))
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
   if(E_OK == IsInitDone){
#if(STD_ON == SwcServiceEcuM_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
      if(NULL_PTR == lptrCfgModule){
#if(STD_ON == SwcServiceEcuM_DevErrorDetect)
         Det_ReportError(
         );
#endif
      }
      else{
// check lptrCfgModule for memory faults
// use PBcfg_SwcServiceEcuM as back-up configuration
      }
      IsInitDone = E_OK;
   }
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::DeInitFunction(void){
   if(E_OK != IsInitDone){
#if(STD_ON == SwcServiceEcuM_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
      IsInitDone = E_NOT_OK;
   }
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::MainFunction(void){
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

