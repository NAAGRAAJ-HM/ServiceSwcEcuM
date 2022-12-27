#pragma once
/******************************************************************************/
/* File   : ServiceSwcEcuM_core.hpp                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_ServiceSwcEcuM.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define SERVICESWCECUM_CORE_FUNCTIONALITIES                                    \
              FUNC(void, SERVICESWCECUM_CODE) StartPreServiceOs             (void);     \
              FUNC(void, SERVICESWCECUM_CODE) StartPostServiceOs            (void);     \
              FUNC(void, SERVICESWCECUM_CODE) OffPreServiceOs               (void);     \
              FUNC(void, SERVICESWCECUM_CODE) OffPostServiceOs              (void);     \
              FUNC(void, SERVICESWCECUM_CODE) EnableWakeupSources    (void);     \
              FUNC(void, SERVICESWCECUM_CODE) GenerateRamHash        (void);     \
              FUNC(void, SERVICESWCECUM_CODE) CheckRamHash           (void);     \
              FUNC(void, SERVICESWCECUM_CODE) ErrorHook              (void);     \

#define SERVICESWCECUM_CORE_FUNCTIONALITIES_VIRTUAL                            \
      virtual FUNC(void, SERVICESWCECUM_CODE) StartPreServiceOs             (void) = 0; \
      virtual FUNC(void, SERVICESWCECUM_CODE) StartPostServiceOs            (void) = 0; \
      virtual FUNC(void, SERVICESWCECUM_CODE) OffPreServiceOs               (void) = 0; \
      virtual FUNC(void, SERVICESWCECUM_CODE) OffPostServiceOs              (void) = 0; \
      virtual FUNC(void, SERVICESWCECUM_CODE) EnableWakeupSources    (void) = 0; \
      virtual FUNC(void, SERVICESWCECUM_CODE) GenerateRamHash        (void) = 0; \
      virtual FUNC(void, SERVICESWCECUM_CODE) CheckRamHash           (void) = 0; \
      virtual FUNC(void, SERVICESWCECUM_CODE) ErrorHook              (void) = 0; \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class class_ServiceSwcEcuM_Functionality{
   public:
      SERVICESWCECUM_CORE_FUNCTIONALITIES_VIRTUAL
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

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

