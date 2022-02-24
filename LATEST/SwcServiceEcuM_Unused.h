#pragma once
/*****************************************************/
/* File   : SwcServiceEcuM_Unused.h                  */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "Std_Types.h"
#include "Compiler_Cfg_SwcServiceEcuM.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/
class class_SwcServiceEcuM_Unused{
   public:
/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
      FUNC(void, SWCSERVICEECUM_CODE) StartPreOs             (void);
      FUNC(void, SWCSERVICEECUM_CODE) StartPostOs            (void);
      FUNC(void, SWCSERVICEECUM_CODE) OffPreOs               (void);
      FUNC(void, SWCSERVICEECUM_CODE) OffPostOs              (void);
      FUNC(void, SWCSERVICEECUM_CODE) EnableWakeupSources    (void);
      FUNC(void, SWCSERVICEECUM_CODE) GenerateRamHash        (void);
      FUNC(void, SWCSERVICEECUM_CODE) CheckRamHash           (void);
      FUNC(void, SWCSERVICEECUM_CODE) ErrorHook              (void);
};

/*****************************************************/
/* CONSTS                                            */
/*****************************************************/

/*****************************************************/
/* PARAMS                                            */
/*****************************************************/

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
//extern class_SwcServiceEcuM SwcServiceEcuM;

/*****************************************************/
/* EOF                                               */
/*****************************************************/

