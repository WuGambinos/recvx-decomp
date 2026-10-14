#include "stubs.h"
#include "ps2/veronica/prog/main.h"
#include "ps2/veronica/prog/ps2_SystemLoadScreen.h"
#include "ps2/veronica/prog/ps2_SystemSaveScreen.h"
#include "ps2/veronica/prog/adv.h"

#include "rxi/log.h"

// adxwrap
void PlayAdx(unsigned int SlotNo, unsigned int PartitionId,
             unsigned int FileId) {}
void StopAdx(unsigned int SlotNo) {}
int PlayMovieMain() { return 0; }
int PlayStartMovieEx(int MovieNo, int MovieType, int PauseFlag) { return 0; }
void SetVolumeAdx2(unsigned int SlotNo, float Volume) {}

// backup
void BupInit(void) {}
void BupExit(void) {}

// effect.c
void bhSetFontTexture(void *datp) {}

// expand
void Init_Expand() {}
int Expand(register char *s, register unsigned char *d) {}

// sdc
int GetSoundMode() { return 0; }
void SetSoundModeEx(int Mode, int Flag) {}
void SetSoundMode(int Mode) {}

// sdfunc
void ExitApplication() { njUserExit(); }
void InitSofdecSystem(int Mode) {}
void ExitSofdecSystem() {}
void InitSoundProgram() {}
void ExitSoundProgram() {}
void StartVibrationEx(int AtrbId, int VibNo) {}
void StopVibrationBasic(int PortNo) {}
void StopVibrationEx() {}
void PlayBgmEx2(unsigned int PatId, int BgmNo, int FadeInRate, int Volume) {}
void PlayVoiceEx2(int PatId, int VoiceNo, NJS_POINT3 *pPos, int Mode,
                  int FadeInRate, int PauseFlag) {}
void bhReleaseFreeMemory(void *mp) {}
void CallSystemSeBasic(int SeNo, int Volume, int FxLevel) {}
void CallSystemSe(int param,
                  int SeNo) // first parameter is not present on the DWARF
{}
void RequestAdjustDisplay(int AdjustX, int AdjustY) {}
void RequestAllStopSoundEx(int AdxFlag, int InSoundFlag, int FadeCount) {}
int GetInsideFileSize(unsigned int PartitionId, unsigned int FileId) {
  return 0;
}
int GetReadFileStatus() { return 0; }
int RequestReadInsideFile(unsigned int PartitionId, unsigned int FileId,
                          void *DestPtr) {
  return 0;
}
int MountSoundAfs() { return 0; }
void UnmountSoundAfs() {}

void SetAdjustDisplay() {}
void SetEventVibrationMode(int Mode) {}
int WaitPrePlayMovie() { return 0; }
void InitFirstSofdec() {}

int PatId[4] = {-1, -1, -1, -1};

// NaSystem
void njSetBackColor(Uint32 col1, Uint32 col2, Uint32 col3) {}
void njTextureFilterMode(Int mode) {}

// NaDraw
void njDrawPolygon(NJS_POLYGON_VTX *polygon, Int count, Int trans) {}

// njplus
void npPlusInit() {}
void npSetMemory(unsigned char *memp, unsigned int size, char dat) {}
void npSetMemoryL(unsigned int *memp, unsigned int size, int dat) {}

// padman
int CheckSoftResetKeyFlag(int ControllerId) { return 0; }
void ClearSoftResetKeyFlag(int ControllerId) {}

PAD_WRK Pad[4] = {-1, -1, -1, -1};
int SoftResetFlag = -1;
int CurrentPortId = -1;

PAD_WRK Pad[4];
int SoftResetFlag;
int CurrentPortId;

// pwksub
unsigned char *bhGetFreeMemory(int size, int param) { return NULL; }

// ps2_NaDraw.c
void njDrawQuadTexture(QUAD *q, float z) {}
void njQuadTextureStart(int trans) {}
void njQuadTextureEnd() {}
void njSetQuadTexture(int texid, unsigned int col) {}

// ps2_NaFog.c
void njFogEnable() {}
void njFogDisable() {}

// ps2_NaMatrix.c
void njInitMatrix(NJS_MATRIX *m, Sint32 n, Int flag) {}
void njGetMatrix(NJS_MATRIX *m) {}

// ps2_NaMem.c
void njMemCopy4(void *dst, const void *src, Sint32 num) {}

// ps2_NaTextureFunction.c
void njInitTextureBuffer(Sint8 *addr, Uint32 size) {}
void njInitTexture(NJS_TEXMEMLIST *addr, Uint32 n) {}
void njExitTexture(void) {}
Sint32 njLoadTexture(NJS_TEXLIST *texlist) { return 0; }
Sint32 njSetTexture(NJS_TEXLIST *texlist) { return 0; }
void njSetPaletteMode(Uint32 mode) {}
Uint32 njGetPaletteMode(void) { return 0; }
void njSetPaletteData(Sint32 offset, Sint32 count, void *data) {}
void njReleaseTextureAll(void) {}
Sint32 njReleaseTexture(NJS_TEXLIST *texlist) { return 0; }
Sint32 njSetTextureNum(Uint32 n) { return 0; }
void njSetTextureInfo(NJS_TEXINFO *info, Uint16 *tex, Sint32 Type,
                      Sint32 nWidth, Sint32 nHeight) {}
void njSetTextureName(NJS_TEXNAME *texname, void *addr, Uint32 globalIndex,
                      Uint32 attr) {}

NJS_TEXMEMLIST *Ps2_current_texmemlist = {};

// ps2_NaDebugFontFunction
void njInitPrint(Uint32 *texture, Uint32 size, Uint32 attr) {}
void njExitPrint(void) {}
void njPrintSize(Uint16 size) {}

// ps2_NaView
void njSetAspect(Float ax, Float ay) {}
void njInitView(NJS_VIEW *v) {}
void njSetView(NJS_VIEW *v) {}
void njClipZ(Float n, Float f) {}

// ps2_NaSystem
void njSetVertexBuffer(Uint32 *buffer, Sint32 size) {}
void njInitVertexBuffer(Sint32 op, Sint32 om, Sint32 tp, Sint32 tm, Sint32 pt) {
}
void njPolygonCullingMode(Int mode) {}
void njTextureShadingMode(Int mode) {}
void njSetBorderColor(Uint32 color) {}

// ps2_NinjaCnk
void njInit3D(NJS_VERTEX_BUF *vbuf, Int vn) {}

// ps2_MemoryCard.c
MEMORYCARDSTATE *CreateMemoryCard(MEMORYCARDSTATE *pCard) { return NULL; }
int CreateMemoryCardSubDirectory(MEMORYCARDSTATE *pCard) { return 0; }
int CheckMcSelectPortInfoState(unsigned int ulPort) { return 0; }
int GetMcSelectPortType(MEMORYCARDSTATE *pCard, unsigned int ulPort) {
  return 0;
}

// ps2_SystemLoadScreen.c
SYSLOAD_SCREEN *CreateSysLoadScreen(SYSLOAD_SCREEN *pSysLoad,
                                    void *vpWorkPtrSys) {
  return NULL;
}
int ExecuteSysLoadScreen(SYSLOAD_SCREEN *pSysLoad) { return 0; }

// ps2_SystemSaveScreen.c
int ExecuteSysSaveScreen(SYSSAVE_SCREEN *pSysSave) { return 0; }
SYSSAVE_SCREEN *CreateSysSaveScreen(SYSSAVE_SCREEN *pSysSave,
                                    void *vpWorkPtrSys,
                                    unsigned short usSaveMesMode,
                                    unsigned short usSaveWriteMode) {
  return NULL;
}

// ps2_dummy
int Ps2CheckTextureAlpha(void *pp) { return 0; }
void PS2_jikken() {}
unsigned int palbuf[4096] = {};
NJS_MATRIX crmat = {};
extern float mbuf[128][16] = {};
unsigned int Ps2_sys_cnt = 0;

// ps2_sg_malloc
void syFree(void *ap) {}
void *syMalloc(unsigned int nbytes) { return NULL; }

// ps2_sg_pd
void pdSetMode(Sint32 mode) {}

// ps2_sg_sybt
Void syBtExit(Void) {}

// ps2_sg_sycbl
SYE_CBL syCblCheck(void) {}

// ps2_sg_sycfg
Sint32 syCfgSetSoundMode(Sint32 nMode) { return 0; }

// ps2_pxlconv
unsigned char *Ps2_PXLCONV = {};
// unsigned char* Ps2_PXLCONV __attribute__((aligned(64)));

// ps2_texture.c
void bhCopyMainmem2Texmem(NJS_TEXLIST *tlp) {}
char *bhCopyTexmem2MainmemSub(NJS_TEXLIST *tlp, char *adr) { return NULL; }
void bhGarbageTexture(NJS_TEXMEMLIST *addr, unsigned int n) {}

// message.c
int bhDispMessage(float px, float py, float pri, int mes_typ, int mes_idx,
                  int color, int count) {}

float FontScaleX = 0;
float FontScaleCR = 0;
const unsigned char FontSz[126] = {};

// sbinit
void sbInitSystem(Int mode, Int frame, Int count) {}
void sbExitSystem(void) {}

// system.h
int bhCalcVtxBuffer() {}
void bhChangeHWSetting() {}
void bhInitSystem() {}
void bhInitRoomChangeSystem() {}

void bhSysCallInit() {
  log_info("Inside bhSysCallInit");
  bhInitSystem();

  sys->tk_flg = 0x300002;
}

void bhSysCallWarning() { log_info("Inside bhSysCallWarning");
    njFogDisable(); 
    
    njSetBackColor(0x00000000, 0x00000000, 0x00000000);  
    
    if (Adv_FirstWarningMessage() != 0)
    { 
        sys->tk_flg = 0x300004; 
    }
}
void bhSysCallIpl() { log_info("Inside bhSysCallIpl"); }
void bhSysCallFirstmovie() { log_info("Inside bhSysCallFirstmovie"); }
void bhSysCallTitle() { log_info("Inside bhSysCallTitle"); }
void bhSysCallOpening() { log_info("Inside bhSysCallOpening"); }
void bhSysCallPad() { log_info("Inside bhSysCallPad"); }
void bhSysCallGame() { log_info("Inside bhSysCallGame"); }
void bhSysCallEvent() { log_info("Inside bhSysCallEvent"); }
void bhSysCallItemselect() { log_info("Inside bhSysCallItemselect"); }
void bhSysCallMap() { log_info("Inside bhSysCallMap"); }
void bhSysCallDoordemo() { log_info("Inside bhSysCallDoordemo"); }
void bhSysCallMovie() { log_info("Inside bhSysCallMovie"); }
void bhSysCallEnding() { log_info("Inside bhSysCallEnding"); }
void bhSysCallGameover() { log_info("Inside bhSysCallGameover"); }
void bhSysCallTypewriter() { log_info("Inside bhSysCallTypewriter"); }
void bhSysCallOption() { log_info("Inside bhSysCallOption"); }
void bhSysCallCompEvent() { log_info("Inside bhSysCallCompEvent"); }
void bhSysCallDiscChange() { log_info("Inside bhSysCallDiscChange"); }
void bhSysCallSoundMuseum() { log_info("Inside bhSysCallSoundMuseum"); }
void bhSysCallMonitor() { log_info("Inside bhSysCallMonitor"); }
void bhSysCallSndMonitor() { log_info("Inside bhSysCallSndMonitor"); }
void bhSysCallScreenSaver() { log_info("Inside bhSysCallScreenSaver"); }

void bhFirstGameStart() {}
void bhCheckSubTask() {}
void bhReturnTitle() {}
void bhExitGame() {}
void bhSetEventTimer(int mode) {}
void EasyDispMessage(float PosY, unsigned int MessageNo) {}

// sync
void bhInitVSync() {}
void bhClearVSync() {}
void bhControlVSync() {}
void bhControlEOR() {}
void bhCheckPadPort() {}
void bhCheckSoftReset() {}

// vibman
int CheckVibrationUnit(unsigned int PortId) { return 0; }
int GetUseVibrationUnit() { return 0; }
void SetUseVibrationUnit(int Flag) {}
