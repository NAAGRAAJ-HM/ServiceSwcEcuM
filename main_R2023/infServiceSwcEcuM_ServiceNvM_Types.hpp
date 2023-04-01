#pragma once
/******************************************************************************/
/* File   : infServiceSwcEcuM_ServiceNvM_Types.hpp                            */
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

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define IndexServiceEcuMClient_ServiceBswM                                    49
#define IndexServiceEcuMClient_ServiceSchM                                    50
#define SizeDriverInitData_One                                                51
#define SizeDriverInitData_Zero                                                7

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class NvM_BlocksRom_ServiceSwcEcuM_Type:
      public ConstModule_TypeAbstract
{
   public:
      uint8                           u8SizeDriverInitData_One;
      infServiceEcuMClient*           aptrinfServiceEcuMClient_One     [SizeDriverInitData_One];
      const ConstModule_TypeAbstract* aptrConstModule_One              [SizeDriverInitData_One];
      CfgModule_TypeAbstract*         aptrCfgModule_One                [SizeDriverInitData_One];
      uint8                           u8SizeDriverInitData_Zero;
      infServiceEcuMClient*           aptrinfServiceEcuMClient_Zero    [SizeDriverInitData_Zero];
      const ConstModule_TypeAbstract* aptrConstModule_Zero             [SizeDriverInitData_Zero];
      CfgModule_TypeAbstract*         aptrCfgModule_Zero               [SizeDriverInitData_Zero];
      infServiceEcuM_ServiceSwcEcuM*  ptrinfServiceEcuM_ServiceSwcEcuM;
      infServiceSchM_ServiceEcuM*     ptrinfServiceSchM_ServiceEcuM;
};

class NvM_BlocksNv_ServiceSwcEcuM_Type:
      public CfgModule_TypeAbstract
{
};

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

