/******************************************************************************/
/* File   : SwcServiceEcuM.cpp                                                */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "CfgSwcServiceEcuM.hpp"
#include "SwcServiceEcuM_core.hpp"
#include "infSwcServiceEcuM_Exp.hpp"
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
class module_SwcServiceEcuM:
      INTERFACES_EXPORTED_SWCSERVICEECUM
   ,  public abstract_module
   ,  public class_SwcServiceEcuM_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

   public:
      FUNC(void, SWCSERVICEECUM_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, SWCSERVICEECUM_CONFIG_DATA, SWCSERVICEECUM_APPL_CONST) lptrCfgModule
      );
      FUNC(void, SWCSERVICEECUM_CODE) DeInitFunction (void);
      FUNC(void, SWCSERVICEECUM_CODE) MainFunction   (void);
      SWCSERVICEECUM_CORE_FUNCTIONALITIES
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

//TBD: Move to Cfg

#include "CfgGen.hpp"

//TBD: Move to Cfg
#include "infDet_EcuM.hpp"
#include "infDem_EcuM.hpp"
#include "infFls_EcuM.hpp"
#include "infFee_EcuM.hpp"
#include "infMemIf_EcuM.hpp"
#include "infNvM_EcuM.hpp"
#include "infEcuM_SwcServiceEcuM.hpp"

static const CfgEcuM_TypeDriverInitData laDriverInitDataZero[] = {
      {gptrinfEcuMClient_Det,   &(CfgGen.CfgDet)}
   ,  {gptrinfEcuMClient_Dem,   &(CfgGen.CfgDem)}
   ,  {gptrinfEcuMClient_Fls,   &(CfgGen.CfgFls)}
   ,  {gptrinfEcuMClient_Fee,   &(CfgGen.CfgFee)}
   ,  {gptrinfEcuMClient_MemIf, &(CfgGen.CfgMemIf)}
   ,  {gptrinfEcuMClient_NvM,   &(CfgGen.CfgNvM)}
// ,  {gptrinfEcuMClient_EcuM,  &(CfgGen.CfgEcuM)}
};

static FUNC(void, SWCSERVICEECUM_CODE) DriverInitZero(
   void
){
   DriverInitX(
         laDriverInitDataZero
      ,  (
               sizeof(laDriverInitDataZero)
            /  sizeof(CfgEcuM_TypeDriverInitData)
         )
   );
}

//TBD: Move to Cfg
#include "infCanIf_EcuM.hpp"
#include "infCanTp_EcuM.hpp"
#include "infCryIf_EcuM.hpp"
#include "infEa_EcuM.hpp"
#include "infEthIf_EcuM.hpp"
#include "infFrIf_EcuM.hpp"
#include "infFrTp_EcuM.hpp"
#include "infJ1939Tp_EcuM.hpp"
#include "infLinIf_EcuM.hpp"
#include "infLinTp_EcuM.hpp"
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
#include "infCanNm_EcuM.hpp"
#include "infCanSm_EcuM.hpp"
#include "infCom_EcuM.hpp"
#include "infComM_EcuM.hpp"
#include "infCsm_EcuM.hpp"
#include "infDcm_EcuM.hpp"
#include "infDlt_EcuM.hpp"
#include "infFiM_EcuM.hpp"
#include "infFrNm_EcuM.hpp"
#include "infIpduM_EcuM.hpp"
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

//TBD: Move to Cfg
static const CfgEcuM_TypeDriverInitData laDriverInitDataOne[] = {
      {gptrinfEcuMClient_CanIf,          &(CfgGen.CfgCanIf)}
   ,  {gptrinfEcuMClient_CanTp,          &(CfgGen.CfgCanTp)}
   ,  {gptrinfEcuMClient_CryIf,          &(CfgGen.CfgCryIf)}
   ,  {gptrinfEcuMClient_Ea,             &(CfgGen.CfgEa)}
   ,  {gptrinfEcuMClient_EthIf,          &(CfgGen.CfgEthIf)}
// ,  {gptrinfEcuMClient_Fee,            &(CfgGen.CfgFee)}
   ,  {gptrinfEcuMClient_FrIf,           &(CfgGen.CfgFrIf)}
   ,  {gptrinfEcuMClient_FrTp,           &(CfgGen.CfgFrTp)}
   ,  {gptrinfEcuMClient_J1939Tp,        &(CfgGen.CfgJ1939Tp)}
   ,  {gptrinfEcuMClient_LinIf,          &(CfgGen.CfgLinIf)}
   ,  {gptrinfEcuMClient_LinTp,          &(CfgGen.CfgLinTp)}
// ,  {gptrinfEcuMClient_MemIf,          &(CfgGen.CfgMemIf)}
   ,  {gptrinfEcuMClient_WdgIf,          &(CfgGen.CfgWdgIf)}
   ,  {gptrinfEcuMClient_Adc,            &(CfgGen.CfgAdc)}
   ,  {gptrinfEcuMClient_Can,            &(CfgGen.CfgCan)}
   ,  {gptrinfEcuMClient_Cry,            &(CfgGen.CfgCry)}
   ,  {gptrinfEcuMClient_Dio,            &(CfgGen.CfgDio)}
   ,  {gptrinfEcuMClient_Eep,            &(CfgGen.CfgEep)}
   ,  {gptrinfEcuMClient_Eth,            &(CfgGen.CfgEth)}
// ,  {gptrinfEcuMClient_Fls,            &(CfgGen.CfgFls)}
   ,  {gptrinfEcuMClient_Fr,             &(CfgGen.CfgFr)}
   ,  {gptrinfEcuMClient_Gpt,            &(CfgGen.CfgGpt)}
   ,  {gptrinfEcuMClient_Icu,            &(CfgGen.CfgIcu)}
   ,  {gptrinfEcuMClient_Lin,            &(CfgGen.CfgLin)}
   ,  {gptrinfEcuMClient_Mcu,            &(CfgGen.CfgMcu)}
   ,  {gptrinfEcuMClient_Ocu,            &(CfgGen.CfgOcu)}
   ,  {gptrinfEcuMClient_Port,           &(CfgGen.CfgPort)}
   ,  {gptrinfEcuMClient_Pwm,            &(CfgGen.CfgPwm)}
   ,  {gptrinfEcuMClient_Spi,            &(CfgGen.CfgSpi)}
   ,  {gptrinfEcuMClient_Wdg,            &(CfgGen.CfgWdg)}
// ,  {gptrinfEcuMClient_BswM,           &(CfgGen.CfgBswM)}
   ,  {gptrinfEcuMClient_CanNm,          &(CfgGen.CfgCanNm)}
   ,  {gptrinfEcuMClient_CanSm,          &(CfgGen.CfgCanSm)}
   ,  {gptrinfEcuMClient_Com,            &(CfgGen.CfgCom)}
   ,  {gptrinfEcuMClient_ComM,           &(CfgGen.CfgComM)}
   ,  {gptrinfEcuMClient_Csm,            &(CfgGen.CfgCsm)}
   ,  {gptrinfEcuMClient_Dcm,            &(CfgGen.CfgDcm)}
// ,  {gptrinfEcuMClient_Dem,            &(CfgGen.CfgDem)}
// ,  {gptrinfEcuMClient_Det,            &(CfgGen.CfgDet)}
   ,  {gptrinfEcuMClient_Dlt,            &(CfgGen.CfgDlt)}
// ,  {gptrinfEcuMClient_EcuM,           &(CfgGen.CfgEcuM)}
   ,  {gptrinfEcuMClient_FiM,            &(CfgGen.CfgFiM)}
   ,  {gptrinfEcuMClient_FrNm,           &(CfgGen.CfgFrNm)}
   ,  {gptrinfEcuMClient_IpduM,          &(CfgGen.CfgIpduM)}
   ,  {gptrinfEcuMClient_Nm,             &(CfgGen.CfgNm)}
// ,  {gptrinfEcuMClient_NvM,            &(CfgGen.CfgNvM)}
// ,  {gptrinfEcuMClient_Os,             &(CfgGen.CfgOs)}
   ,  {gptrinfEcuMClient_PduR,           &(CfgGen.CfgPduR)}
// ,  {gptrinfEcuMClient_SchM,           &(CfgGen.CfgSchM)}
   ,  {gptrinfEcuMClient_SecOC,          &(CfgGen.CfgSecOC)}
   ,  {gptrinfEcuMClient_SokFm,          &(CfgGen.CfgSokFm)}
// ,  {gptrinfEcuMClient_StartUp,        &(CfgGen.CfgStartUp)}
   ,  {gptrinfEcuMClient_StbM,           &(CfgGen.CfgStbM)}
   ,  {gptrinfEcuMClient_Vkms,           &(CfgGen.CfgVkms)}
   ,  {gptrinfEcuMClient_WdgM,           &(CfgGen.CfgWdgM)}
// ,  {gptrinfEcuMClient_Rte,            &(CfgGen.CfgRte)}
// ,  {gptrinfEcuMClient_SwcServiceEcuM, &(CfgGen.CfgSwcServiceEcuM)}
// ,  {gptrinfEcuMClient_SwcServiceOs,   &(CfgGen.CfgSwcServiceOs)}
};

static FUNC(void, SWCSERVICEECUM_CODE) DriverInitOne(
   void
){
   DriverInitX(
         laDriverInitDataOne
      ,  (
               sizeof(laDriverInitDataOne)
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
   gptrinfEcuMClient_BswM->InitFunction((&CfgGen.CfgBswM));
   gptrinfEcuMClient_SchM->InitFunction((&CfgGen.CfgSchM));
   gptrinfSchM_EcuM->StartTiming();
}

FUNC(void, SWCSERVICEECUM_CODE) module_SwcServiceEcuM::OffPreOs(
   void
){
   OnGoOffOne();
   gptrinfEcuMClient_BswM->DeInitFunction();
   gptrinfEcuMClient_SchM->DeInitFunction();

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

