#ifndef __stubs__H
#define __stubs__H

#include "types.h"

#include "ps2/veronica/prog/main.h"
#include "ps2/veronica/prog/ps2_SystemLoadScreen.h"
#include "ps2/veronica/prog/ps2_SystemSaveScreen.h"

// adxwrap
void PlayAdx(unsigned int SlotNo, unsigned int PartitionId,
             unsigned int FileId);
void StopAdx(unsigned int SlotNo);
int PlayMovieMain();
int PlayStartMovieEx(int MovieNo, int MovieType, int PauseFlag);
void SetVolumeAdx2(unsigned int SlotNo, float Volume);

// backup
void BupInit(void);
void BupExit(void);

// effect.c
void bhSetFontTexture(void *datp);

// expand 
void Init_Expand();
int Expand(register char* s, register unsigned char* d);

// sdc
int GetSoundMode();
void SetSoundModeEx(int Mode, int Flag);
void SetSoundMode(int Mode);

// sdfunc
void ExitApplication();
void InitSofdecSystem(int Mode);
void ExitSofdecSystem();
void InitSoundProgram();
void ExitSoundProgram();
void StartVibrationEx(int AtrbId, int VibNo);
void StopVibrationBasic(int PortNo);
void StopVibrationEx();
void PlayBgmEx2(unsigned int PatId, int BgmNo, int FadeInRate, int Volume);
void PlayVoiceEx2(int PatId, int VoiceNo, NJS_POINT3 *pPos, int Mode,
                  int FadeInRate, int PauseFlag);
void bhReleaseFreeMemory(void *mp);
void CallSystemSeBasic(int SeNo, int Volume, int FxLevel);
void CallSystemSe(int param,
                  int SeNo); // first parameter is not present on the DWARF

void RequestAdjustDisplay(int AdjustX, int AdjustY);
void RequestAllStopSoundEx(int AdxFlag, int InSoundFlag, int FadeCount);
int GetInsideFileSize(unsigned int PartitionId, unsigned int FileId);
int GetReadFileStatus();
int RequestReadInsideFile(unsigned int PartitionId, unsigned int FileId,
                          void *DestPtr);
int MountSoundAfs();
void UnmountSoundAfs();

void SetAdjustDisplay();
void SetEventVibrationMode(int Mode);
int WaitPrePlayMovie();

void InitFirstSofdec();

// NaSystem
void njSetBackColor(Uint32 col1, Uint32 col2, Uint32 col3);
void njTextureFilterMode(Int mode);

// NaDraw
void njDrawPolygon(NJS_POLYGON_VTX *polygon, Int count, Int trans);

// njplus
void npPlusInit();
void npSetMemory(unsigned char* memp, unsigned int size, char dat);
void npSetMemoryL(unsigned int* memp, unsigned int size, int dat);

// padman
int CheckSoftResetKeyFlag(int ControllerId);
void ClearSoftResetKeyFlag(int ControllerId);

extern PAD_WRK Pad[4];
extern int SoftResetFlag;
extern int CurrentPortId;

// pwksub
unsigned char *bhGetFreeMemory(int size, int param);

// ps2_NaDraw.c
void njDrawQuadTexture(QUAD *q, float z);
void njQuadTextureStart(int trans);
void njQuadTextureEnd();
void njSetQuadTexture(int texid, unsigned int col);

// ps2_NaFog.c
void njFogEnable();
void njFogDisable();

// ps2_NaMatrix.c
void njInitMatrix(NJS_MATRIX *m, Sint32 n, Int flag);
void    njGetMatrix(NJS_MATRIX *m);

// ps2_NaMem.c
void njMemCopy4(void *dst, const void *src, Sint32 num);

// ps2_NaTextureFunction.c
void	njInitTextureBuffer(Sint8 *addr,Uint32 size);
void njInitTexture(NJS_TEXMEMLIST *addr, Uint32 n);
void njExitTexture(void);
Sint32 njLoadTexture(NJS_TEXLIST *texlist);
Sint32 njSetTexture(NJS_TEXLIST *texlist);
void njSetPaletteMode(Uint32 mode);
Uint32 njGetPaletteMode(void);
void njSetPaletteData(Sint32 offset, Sint32 count, void *data);
void njReleaseTextureAll(void);
Sint32 njReleaseTexture(NJS_TEXLIST *texlist);
Sint32 njSetTextureNum(Uint32 n);
void njSetTextureInfo(NJS_TEXINFO *info, Uint16 *tex, Sint32 Type,
                      Sint32 nWidth, Sint32 nHeight);
void njSetTextureName(NJS_TEXNAME *texname, void *addr, Uint32 globalIndex,
                      Uint32 attr);

// ps2_NaDebugFontFunction
void 	njInitPrint(Uint32 *texture,Uint32 size,Uint32 attr);
void 	njExitPrint(void);
void	njPrintSize(Uint16 size);

// ps2_NaView
void    njSetAspect(Float ax, Float ay);
void    njInitView(NJS_VIEW *v);
void    njSetView(NJS_VIEW *v);
void    njClipZ(Float n, Float f);

// ps2_NaSystem
void	njSetVertexBuffer(Uint32 *buffer,Sint32 size);
void	njInitVertexBuffer( Sint32 op, Sint32 om, Sint32 tp, Sint32 tm ,Sint32 pt);
void    njPolygonCullingMode( Int mode );
void    njTextureShadingMode( Int mode );
void	njSetBorderColor(Uint32 color );

// ps2_NinjaCnk
void njInit3D(NJS_VERTEX_BUF *vbuf, Int vn);

// ps2_MemoryCard.c
MEMORYCARDSTATE *CreateMemoryCard(MEMORYCARDSTATE *pCard);
int CreateMemoryCardSubDirectory(MEMORYCARDSTATE *pCard);
int CheckMcSelectPortInfoState(unsigned int ulPort);
int GetMcSelectPortType(MEMORYCARDSTATE *pCard, unsigned int ulPort);


// ps2_SystemLoadScreen.c
SYSLOAD_SCREEN *CreateSysLoadScreen(SYSLOAD_SCREEN *pSysLoad,
                                    void *vpWorkPtrSys);
int ExecuteSysLoadScreen(SYSLOAD_SCREEN *pSysLoad);

// ps2_SystemSaveScreen.c
int ExecuteSysSaveScreen(SYSSAVE_SCREEN *pSysSave);
SYSSAVE_SCREEN *CreateSysSaveScreen(SYSSAVE_SCREEN *pSysSave,
                                    void *vpWorkPtrSys,
                                    unsigned short usSaveMesMode,
                                    unsigned short usSaveWriteMode);

// ps2_dummy
int Ps2CheckTextureAlpha(void *pp);
void PS2_jikken();

extern unsigned int Ps2_sys_cnt;

// ps2_sg_malloc
void syFree(void *ap);
void *syMalloc(unsigned int nbytes);

// ps2_sg_pd
void pdSetMode(Sint32 mode);

// ps2_sg_sybt
Void   syBtExit     ( Void );

// ps2_sg_sycfg
Sint32 syCfgSetSoundMode(Sint32 nMode);

// ps2_sg_sycbl
SYE_CBL syCblCheck( void );


// ps2_texture.c
void bhCopyMainmem2Texmem(NJS_TEXLIST *tlp);
char *bhCopyTexmem2MainmemSub(NJS_TEXLIST *tlp, char *adr);
void bhGarbageTexture(NJS_TEXMEMLIST *addr, unsigned int n);

// message.c
int bhDispMessage(float px, float py, float pri, int mes_typ, int mes_idx,
                  int color, int count);

extern float FontScaleX;
extern float FontScaleCR;
extern const unsigned char FontSz[126];

// sbinit
void sbInitSystem(Int mode, Int frame, Int count);
void sbExitSystem(void);

// system.h
int bhCalcVtxBuffer();
void bhChangeHWSetting();
void bhInitSystem();
void bhInitRoomChangeSystem();
void bhSysCallInit();
void bhSysCallDiscChange();
void bhSysCallSoundMuseum();
void bhSysCallWarning();
void bhSysCallIpl();
void bhSysCallFirstmovie();
void bhSysCallTitle();
void bhSysCallOpening();
void bhFirstGameStart();
void bhSysCallPad();
void bhSysCallGame();
void bhCheckSubTask();
void bhSysCallEvent();
void bhSysCallMap();
void bhSysCallItemselect();
void bhSysCallDoordemo();
void bhSysCallMovie();
void bhSysCallEnding();
void bhSysCallGameover();
void bhSysCallTypewriter();
void bhSysCallOption();
void bhSysCallCompEvent();
void bhSysCallMonitor();
void bhSysCallSndMonitor();
void bhSysCallScreenSaver();
void bhReturnTitle();
void bhExitGame();
void bhSetEventTimer(int mode);
void EasyDispMessage(float PosY, unsigned int MessageNo);

// sync
void bhInitVSync();
void bhClearVSync();
void bhControlVSync();
void bhControlEOR();
void bhCheckPadPort();
void bhCheckSoftReset();

// vibman
int CheckVibrationUnit(unsigned int PortId);
int GetUseVibrationUnit();
void SetUseVibrationUnit(int Flag);

#endif
