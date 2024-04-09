#pragma once

#include "EcuM_Cfg.hpp"
#include "EcuM_RunTime.hpp"

#define ECUM_CAUSE_UNKNOWN                       0
#define ECUM_CAUSE_ECU_STATE                     1
#define ECUM_CAUSE_WDGM                          2
#define ECUM_CAUSE_DCM                           3
#define ECUM_BOOT_TARGET_APP                     0
#define ECUM_BOOT_TARGET_OEM_BOOTLOADER          1
#define ECUM_BOOT_TARGET_SYS_BOOTLOADER          2

typedef uint16 Type_SwcServiceEcuM_tUser;
typedef uint8  Type_SwcServiceEcuM_tBootTarget;

typedef struct{
   Type_SwcServiceEcuM_tCauseShutdown tCauseShutdown;
}EcuM_ShutdownInfoType;

