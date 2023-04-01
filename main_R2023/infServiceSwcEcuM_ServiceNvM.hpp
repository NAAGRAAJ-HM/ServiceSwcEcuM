#pragma once
/******************************************************************************/
/* File   : infServiceSwcEcuM_ServiceNvM.hpp                                  */
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
#include "infServiceEcuMClient.hpp"
#include "infServiceSwcEcuM_Imp.hpp"

extern const NvM_BlocksNv_Type NvM_BlocksNvRom; //TBD: move to header
extern       NvM_BlocksNv_Type NvM_BlocksNvRam; //TBD: move to header
extern const NvM_BlocksNv_Type Fls_Blocks;      //TBD: move to header

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
                  &(NvM_BlocksNvRam.NvM_BlocksNv_McalCan)                                                                          \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_McalCry)                                                                          \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_McalDio)                                                                          \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_McalEep)                                                                          \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_McalEth)                                                                          \
/*             ,  &(NvM_BlocksNvRam.NvM_BlocksNv_McalFls)*/                                                                        \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_McalFr)                                                                           \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_McalIcu)                                                                          \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_McalOcu)                                                                          \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_McalPwm)                                                                          \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_McalSpi)                                                                          \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_McalWdg)                                                                          \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_EcuabCanIf)                                                                       \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_EcuabCanTp)                                                                       \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_EcuabCryIf)                                                                       \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_EcuabEa)                                                                          \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_EcuabEthIf)                                                                       \
/*             ,  &(NvM_BlocksNvRam.NvM_BlocksNv_EcuabFee)*/                                                                       \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_EcuabFrIf)                                                                        \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_EcuabFrTp)                                                                        \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_EcuabJ1939Tp)                                                                     \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_EcuabLinIf)                                                                       \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_EcuabLinTp)                                                                       \
/*             ,  &(NvM_BlocksNvRam.NvM_BlocksNv_EcuabMemIf)*/                                                                     \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_EcuabWdgIf)                                                                       \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceCanNm)                                                                     \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceCanSm)                                                                     \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceCom)                                                                       \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceComM)                                                                      \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceCsm)                                                                       \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceDcm)                                                                       \
/*             ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceDem)*/                                                                     \
/*             ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceDet)*/                                                                     \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceDlt)                                                                       \
/*             ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceEcuM)*/                                                                    \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceFiM)                                                                       \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceFrNm)                                                                      \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceIpduM)                                                                     \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceNm)                                                                        \
/*             ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceNvM)*/                                                                     \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceOs)                                                                        \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR)                                                                      \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceSecOC)                                                                     \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceSokFm)                                                                     \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceStartUp)                                                                   \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceStbM)                                                                      \
/*             ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcEcuM)*/                                                                 \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceVkms)                                                                      \
                                                                                                                           \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_McalPort)                                                                         \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_McalMcu)                                                                          \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_McalAdc)                                                                          \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_McalGpt)                                                                          \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceWdgM)                                                                      \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_McalLin)                                                                          \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ProjectARA)                                                                       \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ApplSwcFoc)                                                                       \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcOs)                                                                     \
                                                                                                                           \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceBswM)                                                                      \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceSchM)                                                                      \
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
                  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceDet)                                                                       \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceDem)                                                                       \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_McalFls)                                                                          \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_EcuabFee)                                                                         \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_EcuabMemIf)                                                                       \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceNvM)                                                                       \
               ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcEcuM)                                                                   \
/*             ,  &(NvM_BlocksNvRam.NvM_BlocksNv_ServiceEcuM)*/                                                                    \
            }                                                                                                              \
         ,  &ServiceEcuM                                                                                                   \
         ,  &ServiceSchM                                                                                                   \
      }                                                                                                                    \

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

