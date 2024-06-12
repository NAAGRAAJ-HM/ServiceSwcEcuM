#pragma once
/******************************************************************************/
/* File   : ServiceSwcEcuM_Version.hpp                                        */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define SERVICESWCECUM_AR_RELEASE_VERSION_MAJOR                                4
#define SERVICESWCECUM_AR_RELEASE_VERSION_MINOR                                3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(SERVICESWCECUM_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible SERVICESWCECUM_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(SERVICESWCECUM_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible SERVICESWCECUM_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

