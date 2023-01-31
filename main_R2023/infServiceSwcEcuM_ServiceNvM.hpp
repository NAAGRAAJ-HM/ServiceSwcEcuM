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

#include "Cfg.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define NvM_InitBlocksRom_ServiceSwcEcuM                                                                                   \
   ,  {                                                                                                                    \
            {SERVICESWCECUM_AR_RELEASE_VERSION_MAJOR, SERVICESWCECUM_AR_RELEASE_VERSION_MINOR, 0x00,0xFF,0x01,'0','1','0'} \
         ,  SizeDriverInitData_One                                                                                         \
         ,  {                                                                                                              \
                  &McalCan                                                                                                 \
               ,  &McalCry                                                                                                 \
               ,  &McalDio                                                                                                 \
               ,  &McalEep                                                                                                 \
               ,  &McalEth                                                                                                 \
/*             ,  &McalFls*/                                                                                               \
               ,  &McalFr                                                                                                  \
               ,  &McalIcu                                                                                                 \
               ,  &McalOcu                                                                                                 \
               ,  &McalPwm                                                                                                 \
               ,  &McalSpi                                                                                                 \
               ,  &McalWdg                                                                                                 \
               ,  &EcuabCanIf                                                                                              \
               ,  &EcuabCanTp                                                                                              \
               ,  &EcuabCryIf                                                                                              \
               ,  &EcuabEa                                                                                                 \
               ,  &EcuabEthIf                                                                                              \
/*             ,  &EcuabFee*/                                                                                              \
               ,  &EcuabFrIf                                                                                               \
               ,  &EcuabFrTp                                                                                               \
               ,  &EcuabJ1939Tp                                                                                            \
               ,  &EcuabLinIf                                                                                              \
               ,  &EcuabLinTp                                                                                              \
/*             ,  &EcuabMemIf*/                                                                                            \
               ,  &EcuabWdgIf                                                                                              \
               ,  &ServiceCanNm                                                                                            \
               ,  &ServiceCanSm                                                                                            \
               ,  &ServiceCom                                                                                              \
               ,  &ServiceComM                                                                                             \
               ,  &ServiceCsm                                                                                              \
               ,  &ServiceDcm                                                                                              \
/*             ,  &ServiceDem*/                                                                                            \
/*             ,  &ServiceDet*/                                                                                            \
               ,  &ServiceDlt                                                                                              \
/*             ,  &ServiceEcuM*/                                                                                           \
               ,  &ServiceFiM                                                                                              \
               ,  &ServiceFrNm                                                                                             \
               ,  &ServiceIpduM                                                                                            \
               ,  &ServiceNm                                                                                               \
/*             ,  &ServiceNvM*/                                                                                            \
               ,  &ServiceOs                                                                                               \
               ,  &ServicePduR                                                                                             \
               ,  &ServiceSecOC                                                                                            \
               ,  &ServiceSokFm                                                                                            \
               ,  &ServiceStartUp                                                                                          \
               ,  &ServiceStbM                                                                                             \
/*             ,  &ServiceSwcEcuM*/                                                                                        \
               ,  &ServiceVkms                                                                                             \
                                                                                                                           \
               ,  &McalPort                                                                                                \
               ,  &McalMcu                                                                                                 \
               ,  &McalAdc                                                                                                 \
               ,  &McalGpt                                                                                                 \
               ,  &ServiceWdgM                                                                                             \
               ,  &McalLin                                                                                                 \
               ,  &ProjectARA                                                                                              \
               ,  &ApplSwcFoc                                                                                              \
               ,  &ServiceSwcOs                                                                                            \
                                                                                                                           \
               ,  &ServiceBswM                                                                                             \
               ,  &ServiceSchM                                                                                             \
            }                                                                                                              \
         ,  {                                                                                                              \
                  &(NvM_BlocksRom.NvM_BlocksRom_McalCan)                                                                   \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_McalCry)                                                                   \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_McalDio)                                                                   \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_McalEep)                                                                   \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_McalEth)                                                                   \
/*             ,  &(NvM_BlocksRom.NvM_BlocksRom_McalFls)*/                                                                 \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_McalFr)                                                                    \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_McalIcu)                                                                   \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_McalOcu)                                                                   \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_McalPwm)                                                                   \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_McalSpi)                                                                   \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_McalWdg)                                                                   \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_EcuabCanIf)                                                                \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_EcuabCanTp)                                                                \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_EcuabCryIf)                                                                \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_EcuabEa)                                                                   \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_EcuabEthIf)                                                                \
/*             ,  &(NvM_BlocksRom.NvM_BlocksRom_EcuabFee)*/                                                                \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_EcuabFrIf)                                                                 \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_EcuabFrTp)                                                                 \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_EcuabJ1939Tp)                                                              \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_EcuabLinIf)                                                                \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_EcuabLinTp)                                                                \
/*             ,  &(NvM_BlocksRom.NvM_BlocksRom_EcuabMemIf)*/                                                              \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_EcuabWdgIf)                                                                \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceCanNm)                                                              \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceCanSm)                                                              \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceCom)                                                                \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceComM)                                                               \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceCsm)                                                                \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceDcm)                                                                \
/*             ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceDem)*/                                                              \
/*             ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceDet)*/                                                              \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceDlt)                                                                \
/*             ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceEcuM)*/                                                             \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceFiM)                                                                \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceFrNm)                                                               \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceIpduM)                                                              \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceNm)                                                                 \
/*             ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceNvM)*/                                                              \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceOs)                                                                 \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServicePduR)                                                               \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceSecOC)                                                              \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceSokFm)                                                              \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceStartUp)                                                            \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceStbM)                                                               \
/*             ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceSwcEcuM)*/                                                          \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceVkms)                                                               \
                                                                                                                           \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_McalPort)                                                                  \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_McalMcu)                                                                   \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_McalAdc)                                                                   \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_McalGpt)                                                                   \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceWdgM)                                                               \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_McalLin)                                                                   \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ProjectARA)                                                                \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ApplSwcFoc)                                                                \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceSwcOs)                                                              \
                                                                                                                           \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceBswM)                                                               \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceSchM)                                                               \
            }                                                                                                              \
         ,  {                                                                                                              \
                  &(CfgGen_ServiceNvM.CfgMcalCan)                                                                          \
               ,  &(CfgGen_ServiceNvM.CfgMcalCry)                                                                          \
               ,  &(CfgGen_ServiceNvM.CfgMcalDio)                                                                          \
               ,  &(CfgGen_ServiceNvM.CfgMcalEep)                                                                          \
               ,  &(CfgGen_ServiceNvM.CfgMcalEth)                                                                          \
/*             ,  &(CfgGen_ServiceNvM.CfgMcalFls)*/                                                                        \
               ,  &(CfgGen_ServiceNvM.CfgMcalFr)                                                                           \
               ,  &(CfgGen_ServiceNvM.CfgMcalIcu)                                                                          \
               ,  &(CfgGen_ServiceNvM.CfgMcalOcu)                                                                          \
               ,  &(CfgGen_ServiceNvM.CfgMcalPwm)                                                                          \
               ,  &(CfgGen_ServiceNvM.CfgMcalSpi)                                                                          \
               ,  &(CfgGen_ServiceNvM.CfgMcalWdg)                                                                          \
               ,  &(CfgGen_ServiceNvM.CfgEcuabCanIf)                                                                       \
               ,  &(CfgGen_ServiceNvM.CfgEcuabCanTp)                                                                       \
               ,  &(CfgGen_ServiceNvM.CfgEcuabCryIf)                                                                       \
               ,  &(CfgGen_ServiceNvM.CfgEcuabEa)                                                                          \
               ,  &(CfgGen_ServiceNvM.CfgEcuabEthIf)                                                                       \
/*             ,  &(CfgGen_ServiceNvM.CfgEcuabFee)*/                                                                       \
               ,  &(CfgGen_ServiceNvM.CfgEcuabFrIf)                                                                        \
               ,  &(CfgGen_ServiceNvM.CfgEcuabFrTp)                                                                        \
               ,  &(CfgGen_ServiceNvM.CfgEcuabJ1939Tp)                                                                     \
               ,  &(CfgGen_ServiceNvM.CfgEcuabLinIf)                                                                       \
               ,  &(CfgGen_ServiceNvM.CfgEcuabLinTp)                                                                       \
/*             ,  &(CfgGen_ServiceNvM.CfgEcuabMemIf)*/                                                                     \
               ,  &(CfgGen_ServiceNvM.CfgEcuabWdgIf)                                                                       \
               ,  &(CfgGen_ServiceNvM.CfgServiceCanNm)                                                                     \
               ,  &(CfgGen_ServiceNvM.CfgServiceCanSm)                                                                     \
               ,  &(CfgGen_ServiceNvM.CfgServiceCom)                                                                       \
               ,  &(CfgGen_ServiceNvM.CfgServiceComM)                                                                      \
               ,  &(CfgGen_ServiceNvM.CfgServiceCsm)                                                                       \
               ,  &(CfgGen_ServiceNvM.CfgServiceDcm)                                                                       \
/*             ,  &(CfgGen_ServiceNvM.CfgServiceDem)*/                                                                     \
/*             ,  &(CfgGen_ServiceNvM.CfgServiceDet)*/                                                                     \
               ,  &(CfgGen_ServiceNvM.CfgServiceDlt)                                                                       \
/*             ,  &(CfgGen_ServiceNvM.CfgServiceEcuM)*/                                                                    \
               ,  &(CfgGen_ServiceNvM.CfgServiceFiM)                                                                       \
               ,  &(CfgGen_ServiceNvM.CfgServiceFrNm)                                                                      \
               ,  &(CfgGen_ServiceNvM.CfgServiceIpduM)                                                                     \
               ,  &(CfgGen_ServiceNvM.CfgServiceNm)                                                                        \
/*             ,  &(CfgGen_ServiceNvM.CfgServiceNvM)*/                                                                     \
               ,  &(CfgGen_ServiceNvM.CfgServiceOs)                                                                        \
               ,  &(CfgGen_ServiceNvM.CfgServicePduR)                                                                      \
               ,  &(CfgGen_ServiceNvM.CfgServiceSecOC)                                                                     \
               ,  &(CfgGen_ServiceNvM.CfgServiceSokFm)                                                                     \
               ,  &(CfgGen_ServiceNvM.CfgServiceStartUp)                                                                   \
               ,  &(CfgGen_ServiceNvM.CfgServiceStbM)                                                                      \
/*             ,  &(CfgGen_ServiceNvM.CfgServiceSwcEcuM)*/                                                                 \
               ,  &(CfgGen_ServiceNvM.CfgServiceVkms)                                                                      \
                                                                                                                           \
               ,  &(CfgGen_ServiceNvM.CfgMcalPort)                                                                         \
               ,  &(CfgGen_ServiceNvM.CfgMcalMcu)                                                                          \
               ,  &(CfgGen_ServiceNvM.CfgMcalAdc)                                                                          \
               ,  &(CfgGen_ServiceNvM.CfgMcalGpt)                                                                          \
               ,  &(CfgGen_ServiceNvM.CfgServiceWdgM)                                                                      \
               ,  &(CfgGen_ServiceNvM.CfgMcalLin)                                                                          \
               ,  &(CfgGen_ServiceNvM.CfgProjectARA)                                                                       \
               ,  &(CfgGen_ServiceNvM.CfgApplSwcFoc)                                                                       \
               ,  &(CfgGen_ServiceNvM.CfgServiceSwcOs)                                                                     \
                                                                                                                           \
               ,  &(CfgGen_ServiceNvM.CfgServiceBswM)                                                                      \
               ,  &(CfgGen_ServiceNvM.CfgServiceSchM)                                                                      \
            }                                                                                                              \
         ,  SizeDriverInitData_Zero                                                                                        \
         ,  {                                                                                                              \
                  &ServiceDet                                                                                              \
               ,  &ServiceDem                                                                                              \
               ,  &McalFls                                                                                                 \
               ,  &EcuabFee                                                                                                \
               ,  &EcuabMemIf                                                                                              \
               ,  &ServiceNvM                                                                                              \
               ,  &ServiceSwcEcuM                                                                                          \
/*             ,  &ServiceEcuM*/                                                                                           \
            }                                                                                                              \
         ,  {                                                                                                              \
                  &(NvM_BlocksRom.NvM_BlocksRom_ServiceDet)                                                                \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceDem)                                                                \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_McalFls)                                                                   \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_EcuabFee)                                                                  \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_EcuabMemIf)                                                                \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceNvM)                                                                \
               ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceSwcEcuM)                                                            \
/*             ,  &(NvM_BlocksRom.NvM_BlocksRom_ServiceEcuM)*/                                                             \
            }                                                                                                              \
         ,  {                                                                                                              \
                  &(CfgGen_ServiceNvM.CfgServiceDet)                                                                       \
               ,  &(CfgGen_ServiceNvM.CfgServiceDem)                                                                       \
               ,  &(CfgGen_ServiceNvM.CfgMcalFls)                                                                          \
               ,  &(CfgGen_ServiceNvM.CfgEcuabFee)                                                                         \
               ,  &(CfgGen_ServiceNvM.CfgEcuabMemIf)                                                                       \
               ,  &(CfgGen_ServiceNvM.CfgServiceNvM)                                                                       \
               ,  &(CfgGen_ServiceNvM.CfgServiceSwcEcuM)                                                                   \
/*             ,  &(CfgGen_ServiceNvM.CfgServiceEcuM)*/                                                                    \
            }                                                                                                              \
         ,  &ServiceEcuM                                                                                                   \
         ,  &ServiceSchM                                                                                                   \
      }                                                                                                                    \

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

