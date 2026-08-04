#include "common.h"

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", start);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", make_sema);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", spucore_init);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", metaMsgCB);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", repeatCB);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", portinfo_init);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", test_error);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", iop_main_proc);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", TsndLoop);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", setModuleContext);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", TimerIntFunc);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", Tsnd_dmatrans);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", set_port_state_of_load);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", port_stop);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", snd_load_sqinit);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", treq_BGM);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", treq_ALL_REV);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", load_getport);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", treq_ALL_DMALOAD);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", treq_ALL_DMAAUTOLOAD);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", treq_ALL);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", treq_LOAD);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", treq_AUTOLOAD);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", tsndReqFunc);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", TsndFunc);

INCLUDE_ASM("config/asm/nonmatchings/tsnddrv", sceSdrChangeThreadPriority);
