/******************************************************************************/
/* File   : SwcServiceEcuM.cpp                                                */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "module.h"
#include "infSwcServiceEcuM_Version.h"
#include "infSwcServiceEcuM_EcuM.h"
#include "infSwcServiceEcuM_Dcm.h"
#include "infSwcServiceEcuM_SchM.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_SwcServiceEcuM:
      public abstract_module
   ,  public infSwcServiceEcuM_EcuM
{
   public:
      FUNC(void, SWCSERVICEECUM_CODE) InitFunction   (void);
      FUNC(void, SWCSERVICEECUM_CODE) DeInitFunction (void);
      FUNC(void, SWCSERVICEECUM_CODE) GetVersionInfo (void);
      FUNC(void, SWCSERVICEECUM_CODE) MainFunction   (void);
      FUNC(void, SWCSERVICEECUM_CODE) StartPreOs     (void);
      FUNC(void, SWCSERVICEECUM_CODE) StartPostOs    (void);
      FUNC(void, SWCSERVICEECUM_CODE) OffPreOs       (void);
      FUNC(void, SWCSERVICEECUM_CODE) OffPostOs      (void);
};

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
CONSTP2VAR(infEcuMClient,          SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) gptrinfEcuMClient_SwcServiceEcuM = &SwcServiceEcuM;
CONSTP2VAR(infDcmClient,           SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) gptrinfDcmClient_SwcServiceEcuM  = &SwcServiceEcuM;
CONSTP2VAR(infSchMClient,          SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) gptrinfSchMClient_SwcServiceEcuM = &SwcServiceEcuM;
CONSTP2VAR(infSwcServiceEcuM_EcuM, SWCSERVICEECUM_VAR, SWCSERVICEECUM_CONST) gptrinfSwcServiceEcuM_EcuM       = &SwcServiceEcuM;

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
         /*configuration abstract type*/
      );
   }
}

#include "infDet_EcuM.h"
#include "infDem_EcuM.h"
#include "infFls_EcuM.h"
#include "infNvM_EcuM.h"

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

#include "infCanIf_EcuM.h"
#include "infCryIf_EcuM.h"
#include "infEa_EcuM.h"
#include "infEthIf_EcuM.h"
#include "infFee_EcuM.h"
#include "infFrIf_EcuM.h"
#include "infLinIf_EcuM.h"
#include "infLinTp_EcuM.h"
#include "infMemIf_EcuM.h"
#include "infWdgIf_EcuM.h"
#include "infAdc_EcuM.h"
#include "infCan_EcuM.h"
#include "infCry_EcuM.h"
#include "infDio_EcuM.h"
#include "infEep_EcuM.h"
#include "infEth_EcuM.h"
#include "infFr_EcuM.h"
#include "infGpt_EcuM.h"
#include "infIcu_EcuM.h"
#include "infLin_EcuM.h"
#include "infMcu_EcuM.h"
#include "infOcu_EcuM.h"
#include "infPort_EcuM.h"
#include "infPwm_EcuM.h"
#include "infSpi_EcuM.h"
#include "infWdg_EcuM.h"
#include "infBswM_EcuM.h"
#include "infCom_EcuM.h"
#include "infComM_EcuM.h"
#include "infCsm_EcuM.h"
#include "infDcm_EcuM.h"
#include "infEcuM_SwcServiceEcuM.h"
#include "infFiM_EcuM.h"
#include "infNm_EcuM.h"
#include "infOs_EcuM.h"
#include "infPduR_EcuM.h"
#include "infSchM_EcuM.h"
#include "infSecOC_EcuM.h"
#include "infSokFm_EcuM.h"
#include "infStartUp_EcuM.h"
#include "infStbM_EcuM.h"
#include "infVkms_EcuM.h"
#include "infWdgM_EcuM.h"
#include "infRte_EcuM.h"
#include "infSwcServiceEcuM_EcuM.h"
#include "infSwcServiceOs_EcuM.h"

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

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::InitFunction(void){
   SwcServiceEcuM.IsInitDone = E_OK;
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::DeInitFunction(void){
   SwcServiceEcuM.IsInitDone = E_NOT_OK;
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::GetVersionInfo(void){
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
   gptrinfEcuMClient_BswM->InitFunction(/*TBD: configuration*/);
   gptrinfEcuMClient_SchM->InitFunction(/*TBD: configuration*/);
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

#include "SwcServiceEcuM_Unused.h"

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

