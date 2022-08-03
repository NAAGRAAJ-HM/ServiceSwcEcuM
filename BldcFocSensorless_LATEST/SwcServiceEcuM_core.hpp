#pragma once
/******************************************************************************/
/* File   : SwcServiceEcuM_core.hpp                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_SwcServiceEcuM.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define SWCSERVICEECUM_CORE_FUNCTIONALITIES                                    \
              FUNC(void, SWCSERVICEECUM_CODE) StartPreOs             (void);     \
              FUNC(void, SWCSERVICEECUM_CODE) StartPostOs            (void);     \
              FUNC(void, SWCSERVICEECUM_CODE) OffPreOs               (void);     \
              FUNC(void, SWCSERVICEECUM_CODE) OffPostOs              (void);     \
              FUNC(void, SWCSERVICEECUM_CODE) EnableWakeupSources    (void);     \
              FUNC(void, SWCSERVICEECUM_CODE) GenerateRamHash        (void);     \
              FUNC(void, SWCSERVICEECUM_CODE) CheckRamHash           (void);     \
              FUNC(void, SWCSERVICEECUM_CODE) ErrorHook              (void);     \

#define SWCSERVICEECUM_CORE_FUNCTIONALITIES_VIRTUAL                            \
      virtual FUNC(void, SWCSERVICEECUM_CODE) StartPreOs             (void) = 0; \
      virtual FUNC(void, SWCSERVICEECUM_CODE) StartPostOs            (void) = 0; \
      virtual FUNC(void, SWCSERVICEECUM_CODE) OffPreOs               (void) = 0; \
      virtual FUNC(void, SWCSERVICEECUM_CODE) OffPostOs              (void) = 0; \
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
class class_SwcServiceEcuM_Functionality{
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

