#ifdef __cplusplus
extern "C"
{
#endif

#include "SwcServiceEcuM.hpp"
#include "fbl_inc.hpp"

FUNC(void, ECUM_CODE) EcuM_SetWakeupEvent( EcuM_WakeupSourceType WakeupSource ){
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)WakeupSource;
#endif
}

FUNC(void, ECUM_CODE) EcuM_CheckWakeup( EcuM_WakeupSourceType WakeupSource ){
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)WakeupSource;
#endif
}

#ifdef __cplusplus
}
#endif
