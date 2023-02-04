#pragma once
/******************************************************************************/
/* File   : infServiceSwcEcuM_ServiceNvM_Types.hpp                            */
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

