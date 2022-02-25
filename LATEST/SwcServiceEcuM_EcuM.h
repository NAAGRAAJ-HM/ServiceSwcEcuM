#pragma once
/*****************************************************/
/* File   : SwcServiceEcuM_EcuM.h                    */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "Compiler_Cfg_SwcServiceEcuM.h"

#include "EcuM_Client.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/
class interface_SwcServiceEcuM_EcuM : public interface_EcuM_Client{
   public:
/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
      virtual FUNC(void, SWCSERVICEECUM_CODE) InitFunction   (void) = 0;
      virtual FUNC(void, SWCSERVICEECUM_CODE) DeInitFunction (void) = 0;
      virtual FUNC(void, SWCSERVICEECUM_CODE) StartPreOs     (void) = 0;
      virtual FUNC(void, SWCSERVICEECUM_CODE) StartPostOs    (void) = 0;
      virtual FUNC(void, SWCSERVICEECUM_CODE) OffPreOs       (void) = 0;
      virtual FUNC(void, SWCSERVICEECUM_CODE) OffPostOs      (void) = 0;
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
extern interface_SwcServiceEcuM_EcuM *EcuM_Client_ptr_SwcServiceEcuM;

/*****************************************************/
/* EOF                                               */
/*****************************************************/

