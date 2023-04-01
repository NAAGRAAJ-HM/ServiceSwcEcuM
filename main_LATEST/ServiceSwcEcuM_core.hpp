#pragma once
/******************************************************************************/
/* File   : ServiceSwcEcuM_core.hpp                                           */
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

