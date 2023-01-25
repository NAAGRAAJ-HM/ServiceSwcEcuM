#pragma once
/******************************************************************************/
/* File   : infServiceSwcEcuM_ServiceNvM.hpp                                  */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "infServiceEcuMClient.hpp"
#include "infServiceSwcEcuM_Imp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define CONSTSERVICESWCECUM_AR_RELEASE_VERSION_MAJOR                           4
#define CONSTSERVICESWCECUM_AR_RELEASE_VERSION_MINOR                           3
//#define SizeDriverInitData_One                                                51
//#define SizeDriverInitData_Zero                                                7

#define Const_DefaultInit_ConstServiceSwcEcuM                                                                                  \
   ,  {                                                                                                                        \
            {CONSTSERVICESWCECUM_AR_RELEASE_VERSION_MAJOR, CONSTSERVICESWCECUM_AR_RELEASE_VERSION_MINOR, 0x00,0xFF,0x01,'0','1','0'} \
         ,  SizeDriverInitData_One                                                                                             \
         ,  {                                                                                                                  \
                  &McalCan                                                                                                     \
               ,  &McalCry                                                                                                     \
               ,  &McalDio                                                                                                     \
               ,  &McalEep                                                                                                     \
               ,  &McalEth                                                                                                     \
/*             ,  &McalFls*/                                                                                                   \
               ,  &McalFr                                                                                                      \
               ,  &McalIcu                                                                                                     \
               ,  &McalOcu                                                                                                     \
               ,  &McalPwm                                                                                                     \
               ,  &McalSpi                                                                                                     \
               ,  &McalWdg                                                                                                     \
               ,  &EcuabCanIf                                                                                                  \
               ,  &EcuabCanTp                                                                                                  \
               ,  &EcuabCryIf                                                                                                  \
               ,  &EcuabEa                                                                                                     \
               ,  &EcuabEthIf                                                                                                  \
/*             ,  &EcuabFee*/                                                                                                  \
               ,  &EcuabFrIf                                                                                                   \
               ,  &EcuabFrTp                                                                                                   \
               ,  &EcuabJ1939Tp                                                                                                \
               ,  &EcuabLinIf                                                                                                  \
               ,  &EcuabLinTp                                                                                                  \
/*             ,  &EcuabMemIf*/                                                                                                \
               ,  &EcuabWdgIf                                                                                                  \
               ,  &ServiceCanNm                                                                                                \
               ,  &ServiceCanSm                                                                                                \
               ,  &ServiceCom                                                                                                  \
               ,  &ServiceComM                                                                                                 \
               ,  &ServiceCsm                                                                                                  \
               ,  &ServiceDcm                                                                                                  \
/*             ,  &ServiceDem*/                                                                                                \
/*             ,  &ServiceDet*/                                                                                                \
               ,  &ServiceDlt                                                                                                  \
/*             ,  &ServiceEcuM*/                                                                                               \
               ,  &ServiceFiM                                                                                                  \
               ,  &ServiceFrNm                                                                                                 \
               ,  &ServiceIpduM                                                                                                \
               ,  &ServiceNm                                                                                                   \
/*             ,  &ServiceNvM*/                                                                                                \
               ,  &ServiceOs                                                                                                   \
               ,  &ServicePduR                                                                                                 \
               ,  &ServiceSecOC                                                                                                \
               ,  &ServiceSokFm                                                                                                \
               ,  &ServiceStartUp                                                                                              \
               ,  &ServiceStbM                                                                                                 \
/*             ,  &ServiceSwcEcuM*/                                                                                            \
               ,  &ServiceVkms                                                                                                 \
                                                                                                                               \
               ,  &McalPort                                                                                                    \
               ,  &McalMcu                                                                                                     \
               ,  &McalAdc                                                                                                     \
               ,  &McalGpt                                                                                                     \
               ,  &ServiceWdgM                                                                                                 \
               ,  &McalLin                                                                                                     \
               ,  &ProjectARA                                                                                                  \
               ,  &ApplSwcFoc                                                                                                  \
               ,  &ServiceSwcOs                                                                                                \
                                                                                                                               \
               ,  &ServiceBswM                                                                                                 \
               ,  &ServiceSchM                                                                                                 \
            }                                                                                                                  \
         ,  {                                                                                                                  \
                  0 /*&(Const.ConstMcalCan)*/                                                                                        \
               ,  0 /*&(Const.ConstMcalCry)*/                                                                                        \
               ,  0 /*&(Const.ConstMcalDio)*/                                                                                        \
               ,  0 /*&(Const.ConstMcalEep)*/                                                                                        \
               ,  0 /*&(Const.ConstMcalEth)*/                                                                                        \
/*             ,  &(Const.ConstMcalFls)*/                                                                                      \
               ,  0 /*&(Const.ConstMcalFr)*/                                                                                         \
               ,  0 /*&(Const.ConstMcalIcu)*/                                                                                        \
               ,  0 /*&(Const.ConstMcalOcu)*/                                                                                        \
               ,  0 /*&(Const.ConstMcalPwm)*/                                                                                        \
               ,  0 /*&(Const.ConstMcalSpi)*/                                                                                        \
               ,  0 /*&(Const.ConstMcalWdg)*/                                                                                        \
               ,  0 /*&(Const.ConstEcuabCanIf)*/                                                                                     \
               ,  0 /*&(Const.ConstEcuabCanTp)*/                                                                                     \
               ,  0 /*&(Const.ConstEcuabCryIf)*/                                                                                     \
               ,  0 /*&(Const.ConstEcuabEa)*/                                                                                        \
               ,  0 /*&(Const.ConstEcuabEthIf)*/                                                                                     \
/*             ,  &(Const.ConstEcuabFee)*/                                                                                     \
               ,  0 /*&(Const.ConstEcuabFrIf)*/                                                                                      \
               ,  0 /*&(Const.ConstEcuabFrTp)*/                                                                                      \
               ,  0 /*&(Const.ConstEcuabJ1939Tp)*/                                                                                   \
               ,  0 /*&(Const.ConstEcuabLinIf)*/                                                                                     \
               ,  0 /*&(Const.ConstEcuabLinTp)*/                                                                                     \
/*             ,  &(Const.ConstEcuabMemIf)*/                                                                                   \
               ,  0 /*&(Const.ConstEcuabWdgIf)*/                                                                                     \
               ,  0 /*&(Const.ConstServiceCanNm)*/                                                                                   \
               ,  0 /*&(Const.ConstServiceCanSm)*/                                                                                   \
               ,  0 /*&(Const.ConstServiceCom)*/                                                                                     \
               ,  0 /*&(Const.ConstServiceComM)*/                                                                                    \
               ,  0 /*&(Const.ConstServiceCsm)*/                                                                                     \
               ,  0 /*&(Const.ConstServiceDcm)*/                                                                                     \
/*             ,  &(Const.ConstServiceDem)*/                                                                                   \
/*             ,  &(Const.ConstServiceDet)*/                                                                                   \
               ,  0 /*&(Const.ConstServiceDlt)*/                                                                                     \
/*             ,  &(Const.ConstServiceEcuM)*/                                                                                  \
               ,  0 /*&(Const.ConstServiceFiM)*/                                                                                     \
               ,  0 /*&(Const.ConstServiceFrNm)*/                                                                                    \
               ,  0 /*&(Const.ConstServiceIpduM)*/                                                                                   \
               ,  0 /*&(Const.ConstServiceNm)*/                                                                                      \
/*             ,  &(Const.ConstServiceNvM)*/                                                                                   \
               ,  0 /*&(Const.ConstServiceOs)*/                                                                                      \
               ,  0 /*&(Const.ConstServicePduR)*/                                                                                    \
               ,  0 /*&(Const.ConstServiceSecOC)*/                                                                                   \
               ,  0 /*&(Const.ConstServiceSokFm)*/                                                                                   \
               ,  0 /*&(Const.ConstServiceStartUp)*/                                                                                 \
               ,  0 /*&(Const.ConstServiceStbM)*/                                                                                    \
/*             ,  &(Const.ConstServiceSwcEcuM)*/                                                                               \
               ,  0 /*&(Const.ConstServiceVkms)*/                                                                                    \
                                                                                                                               \
               ,  0 /*&(Const.ConstMcalPort)*/                                                                                       \
               ,  0 /*&(Const.ConstMcalMcu)*/                                                                                        \
               ,  0 /*&(Const.ConstMcalAdc)*/                                                                                        \
               ,  0 /*&(Const.ConstMcalGpt)*/                                                                                        \
               ,  0 /*&(Const.ConstServiceWdgM)*/                                                                                    \
               ,  0 /*&(Const.ConstMcalLin)*/                                                                                        \
               ,  &(Const.ConstProjectARA)                                                                                     \
               ,  &(Const.ConstApplSwcFoc)                                                                                     \
               ,  0 /*&(Const.ConstServiceSwcOs)*/                                                                                   \
                                                                                                                               \
               ,  0 /*&(Const.ConstServiceBswM)*/                                                                                    \
               ,  0 /*&(Const.ConstServiceSchM)*/                                                                                    \
            }                                                                                                                  \
         ,  {                                                                                                                  \
                  &(CfgGen_ServiceNvM.CfgMcalCan)                                                                              \
               ,  &(CfgGen_ServiceNvM.CfgMcalCry)                                                                              \
               ,  &(CfgGen_ServiceNvM.CfgMcalDio)                                                                              \
               ,  &(CfgGen_ServiceNvM.CfgMcalEep)                                                                              \
               ,  &(CfgGen_ServiceNvM.CfgMcalEth)                                                                              \
/*             ,  &(CfgGen_ServiceNvM.CfgMcalFls)*/                                                                            \
               ,  &(CfgGen_ServiceNvM.CfgMcalFr)                                                                               \
               ,  &(CfgGen_ServiceNvM.CfgMcalIcu)                                                                              \
               ,  &(CfgGen_ServiceNvM.CfgMcalOcu)                                                                              \
               ,  &(CfgGen_ServiceNvM.CfgMcalPwm)                                                                              \
               ,  &(CfgGen_ServiceNvM.CfgMcalSpi)                                                                              \
               ,  &(CfgGen_ServiceNvM.CfgMcalWdg)                                                                              \
               ,  &(CfgGen_ServiceNvM.CfgEcuabCanIf)                                                                           \
               ,  &(CfgGen_ServiceNvM.CfgEcuabCanTp)                                                                           \
               ,  &(CfgGen_ServiceNvM.CfgEcuabCryIf)                                                                           \
               ,  &(CfgGen_ServiceNvM.CfgEcuabEa)                                                                              \
               ,  &(CfgGen_ServiceNvM.CfgEcuabEthIf)                                                                           \
/*             ,  &(CfgGen_ServiceNvM.CfgEcuabFee)*/                                                                           \
               ,  &(CfgGen_ServiceNvM.CfgEcuabFrIf)                                                                            \
               ,  &(CfgGen_ServiceNvM.CfgEcuabFrTp)                                                                            \
               ,  &(CfgGen_ServiceNvM.CfgEcuabJ1939Tp)                                                                         \
               ,  &(CfgGen_ServiceNvM.CfgEcuabLinIf)                                                                           \
               ,  &(CfgGen_ServiceNvM.CfgEcuabLinTp)                                                                           \
/*             ,  &(CfgGen_ServiceNvM.CfgEcuabMemIf)*/                                                                         \
               ,  &(CfgGen_ServiceNvM.CfgEcuabWdgIf)                                                                           \
               ,  &(CfgGen_ServiceNvM.CfgServiceCanNm)                                                                         \
               ,  &(CfgGen_ServiceNvM.CfgServiceCanSm)                                                                         \
               ,  &(CfgGen_ServiceNvM.CfgServiceCom)                                                                           \
               ,  &(CfgGen_ServiceNvM.CfgServiceComM)                                                                          \
               ,  &(CfgGen_ServiceNvM.CfgServiceCsm)                                                                           \
               ,  &(CfgGen_ServiceNvM.CfgServiceDcm)                                                                           \
/*             ,  &(CfgGen_ServiceNvM.CfgServiceDem)*/                                                                         \
/*             ,  &(CfgGen_ServiceNvM.CfgServiceDet)*/                                                                         \
               ,  &(CfgGen_ServiceNvM.CfgServiceDlt)                                                                           \
/*             ,  &(CfgGen_ServiceNvM.CfgServiceEcuM)*/                                                                        \
               ,  &(CfgGen_ServiceNvM.CfgServiceFiM)                                                                           \
               ,  &(CfgGen_ServiceNvM.CfgServiceFrNm)                                                                          \
               ,  &(CfgGen_ServiceNvM.CfgServiceIpduM)                                                                         \
               ,  &(CfgGen_ServiceNvM.CfgServiceNm)                                                                            \
/*             ,  &(CfgGen_ServiceNvM.CfgServiceNvM)*/                                                                         \
               ,  &(CfgGen_ServiceNvM.CfgServiceOs)                                                                            \
               ,  &(CfgGen_ServiceNvM.CfgServicePduR)                                                                          \
               ,  &(CfgGen_ServiceNvM.CfgServiceSecOC)                                                                         \
               ,  &(CfgGen_ServiceNvM.CfgServiceSokFm)                                                                         \
               ,  &(CfgGen_ServiceNvM.CfgServiceStartUp)                                                                       \
               ,  &(CfgGen_ServiceNvM.CfgServiceStbM)                                                                          \
/*             ,  &(CfgGen_ServiceNvM.CfgServiceSwcEcuM)*/                                                                     \
               ,  &(CfgGen_ServiceNvM.CfgServiceVkms)                                                                          \
                                                                                                                               \
               ,  &(CfgGen_ServiceNvM.CfgMcalPort)                                                                             \
               ,  &(CfgGen_ServiceNvM.CfgMcalMcu)                                                                              \
               ,  &(CfgGen_ServiceNvM.CfgMcalAdc)                                                                              \
               ,  &(CfgGen_ServiceNvM.CfgMcalGpt)                                                                              \
               ,  &(CfgGen_ServiceNvM.CfgServiceWdgM)                                                                          \
               ,  &(CfgGen_ServiceNvM.CfgMcalLin)                                                                              \
               ,  &(CfgGen_ServiceNvM.CfgProjectARA)                                                                           \
               ,  &(CfgGen_ServiceNvM.CfgApplSwcFoc)                                                                           \
               ,  &(CfgGen_ServiceNvM.CfgServiceSwcOs)                                                                         \
                                                                                                                               \
               ,  &(CfgGen_ServiceNvM.CfgServiceBswM)                                                                          \
               ,  &(CfgGen_ServiceNvM.CfgServiceSchM)                                                                          \
            }                                                                                                                  \
         ,  SizeDriverInitData_Zero                                                                                            \
         ,  {                                                                                                                  \
                  &ServiceDet                                                                                                  \
               ,  &ServiceDem                                                                                                  \
               ,  &McalFls                                                                                                     \
               ,  &EcuabFee                                                                                                    \
               ,  &EcuabMemIf                                                                                                  \
               ,  &ServiceNvM                                                                                                  \
               ,  &ServiceSwcEcuM                                                                                              \
/*             ,  &ServiceEcuM*/                                                                                               \
            }                                                                                                                  \
         ,  {                                                                                                                  \
                  0 /*&(Const.ConstServiceDet)*/                                                                                     \
               ,  0 /*&(Const.ConstServiceDem)*/                                                                                     \
               ,  0 /*&(Const.ConstMcalFls)*/                                                                                        \
               ,  0 /*&(Const.ConstEcuabFee)*/                                                                                       \
               ,  0 /*&(Const.ConstEcuabMemIf)*/                                                                                     \
               ,  0 /*&(Const.ConstServiceNvM)*/                                                                                     \
               ,  0 /*&(Const.ConstServiceSwcEcuM)*/                                                                                 \
/*             ,  &(Const.ConstServiceEcuM)*/                                                                                  \
            }                                                                                                                  \
         ,  {                                                                                                                  \
                  &(CfgGen_ServiceNvM.CfgServiceDet)                                                                           \
               ,  &(CfgGen_ServiceNvM.CfgServiceDem)                                                                           \
               ,  &(CfgGen_ServiceNvM.CfgMcalFls)                                                                              \
               ,  &(CfgGen_ServiceNvM.CfgEcuabFee)                                                                             \
               ,  &(CfgGen_ServiceNvM.CfgEcuabMemIf)                                                                           \
               ,  &(CfgGen_ServiceNvM.CfgServiceNvM)                                                                           \
               ,  &(CfgGen_ServiceNvM.CfgServiceSwcEcuM)                                                                       \
/*             ,  &(CfgGen_ServiceNvM.CfgServiceEcuM)*/                                                                        \
            }                                                                                                                  \
         ,  &ServiceEcuM                                                                                                       \
         ,  &ServiceSchM                                                                                                       \
      }                                                                                                                        \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(CONSTSERVICESWCECUM_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible CONSTSERVICESWCECUM_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(CONSTSERVICESWCECUM_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible CONSTSERVICESWCECUM_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

