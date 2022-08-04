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
#define SWCSERVICEECUM_CORE_FUNCTIONALITIES                                    \
              FUNC(void, SWCSERVICEECUM_CODE) StartPreServiceOs             (void);     \
              FUNC(void, SWCSERVICEECUM_CODE) StartPostServiceOs            (void);     \
              FUNC(void, SWCSERVICEECUM_CODE) OffPreServiceOs               (void);     \
              FUNC(void, SWCSERVICEECUM_CODE) OffPostServiceOs              (void);     \
              FUNC(void, SWCSERVICEECUM_CODE) EnableWakeupSources    (void);     \
              FUNC(void, SWCSERVICEECUM_CODE) GenerateRamHash        (void);     \
              FUNC(void, SWCSERVICEECUM_CODE) CheckRamHash           (void);     \
              FUNC(void, SWCSERVICEECUM_CODE) ErrorHook              (void);     \

#define SWCSERVICEECUM_CORE_FUNCTIONALITIES_VIRTUAL                            \
      virtual FUNC(void, SWCSERVICEECUM_CODE) StartPreServiceOs             (void) = 0; \
      virtual FUNC(void, SWCSERVICEECUM_CODE) StartPostServiceOs            (void) = 0; \
      virtual FUNC(void, SWCSERVICEECUM_CODE) OffPreServiceOs               (void) = 0; \
      virtual FUNC(void, SWCSERVICEECUM_CODE) OffPostServiceOs              (void) = 0; \
      virtual FUNC(void, SWCSERVICEECUM_CODE) EnableWakeupSources    (void) = 0; \
      virtual FUNC(void, SWCSERVICEECUM_CODE) GenerateRamHash        (void) = 0; \
      virtual FUNC(void, SWCSERVICEECUM_CODE) CheckRamHash           (void) = 0; \
      virtual FUNC(void, SWCSERVICEECUM_CODE) ErrorHook              (void) = 0; \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class class_ServiceSwcEcuM_Functionality{
   public:
      SWCSERVICEECUM_CORE_FUNCTIONALITIES_VIRTUAL
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

