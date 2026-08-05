#ifndef _EFFSUB4_H_
#define _EFFSUB4_H_

#include "types.h"

typedef struct EFF370_WORK 
{
    // total size: 0x14
    float spd;   // offset 0x0, size 0x4
    float e;     // offset 0x4, size 0x4
    float g;     // offset 0x8, size 0x4
    short id;    // offset 0xC, size 0x2
    short col;   // offset 0xE, size 0x2
    short wcnt;  // offset 0x10, size 0x2
    short lmode; // offset 0x12, size 0x2
} EFF370_WORK;

typedef struct D_WORK
{
    // total size: 0x14
    unsigned int flg;    // offset 0x0, size 0x4
    unsigned int num;    // offset 0x4, size 0x4
    unsigned char* exp0; // offset 0x8, size 0x4
    unsigned char* exp1; // offset 0xC, size 0x4
    unsigned char* exp2; // offset 0x10, size 0x4
} D_WORK;

void bhEff_SetPtcl(BH_PWORK* epw, NJS_POINT3* pos, int tex_id);
void bhEff_SetPtcl1(BH_PWORK* epw, NJS_POINT3* pos, int tex_id, int wcnt);
void bhEff_SetPtcl2(NJS_POINT3* pos, NJS_MATRIX* mtx);
void bhEff_SetPtcl2V(NJS_POINT3* pos, NJS_POINT3* dv, int wcnt);
static void bhEff_SetBlood5(NJS_POINT3* pos, NJS_VECTOR* vec, float size, int col);
void bhEff_Sub350(O_WRK* op);
void bhEff_Sub351(O_WRK* op);
void bhEff_Sub352(O_WRK* op);
void bhEff_Sub353(O_WRK* op);
void bhEff_Sub354(O_WRK* op);
void bhEff_Sub355(O_WRK* op);
void bhEff_Sub356(O_WRK* op);
void bhEff_Sub357();
void bhEff_Sub360(O_WRK* op);
void bhEff_Sub361(O_WRK* op);
void bhEff_Sub362(O_WRK* op);
void bhEff_Sub363(O_WRK* op);
void bhEff_Sub364(O_WRK* op);
void bhEff_Sub365(O_WRK* op);
void bhEff_Sub366(O_WRK* op);
void bhEff_Sub367(O_WRK* op);
void bhEff_Sub368(O_WRK* op);
void bhEff_Sub369(O_WRK* op);
void bhEff_Sub370(O_WRK* op);
void bhEff_Sub371(O_WRK* op);
void bhEff_Sub372(O_WRK* op);
void bhEff_Sub373(O_WRK* op);
void bhEff_Sub398(O_WRK* op);
static O_WRK* bhEff_AllocOwork();
static void bhEff_PtclSpriteDraw(O_WRK* op);
static void bhEff_LineDraw(O_WRK* op);
static void bhEff_SetSprite(O_WRK* op, UV_WORK* uvp, int mode);
static void bhEff_SetSpriteAnime(O_WRK* op, EFF_ANIM* eff_anim, UV_WORK* uvp, int mode);
static void bhEff_3DSpriteDraw(O_WRK* op);
static void bhEff_ModelDraw(O_WRK* op);

#endif
