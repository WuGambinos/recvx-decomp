#ifndef _EFFSUB3_H_
#define _EFFSUB3_H_

#include "types.h"

typedef struct OR_WORK 
{
    // total size: 0x4E0
    unsigned int flg; // offset 0x0, size 0x4
    unsigned short id; // offset 0x4, size 0x2
    signed char free0[10]; // offset 0x6, size 0xA
    float px; // offset 0x10, size 0x4
    float py; // offset 0x14, size 0x4
    float pz; // offset 0x18, size 0x4
    signed int ax; // offset 0x1C, size 0x4
    signed int ay; // offset 0x20, size 0x4
    signed int az; // offset 0x24, size 0x4
    signed char free1[24]; // offset 0x28, size 0x18
    float pxb; // offset 0x40, size 0x4
    float pyb; // offset 0x44, size 0x4
    float pzb; // offset 0x48, size 0x4
    signed int axb; // offset 0x4C, size 0x4
    signed int ayb; // offset 0x50, size 0x4
    signed int azb; // offset 0x54, size 0x4
    signed char free2[12]; // offset 0x58, size 0xC
    float lox; // offset 0x64, size 0x4
    float loy; // offset 0x68, size 0x4
    float loz; // offset 0x6C, size 0x4
    signed char free3[24]; // offset 0x70, size 0x18
    unsigned int stflg; // offset 0x88, size 0x4
    unsigned int Dummy; // offset 0x8C, size 0x4
    signed char free4[1092]; // offset 0x90, size 0x444
    void (* func)(void *); // offset 0x4D4, size 0x4
    signed int idx; // offset 0x4D8, size 0x4
    signed int Dummy2; // offset 0x4DC, size 0x4
} OR_WORK;

typedef struct ANM_WORK {
    // total size: 0x14
    struct /* @anon9 */ {
        // total size: 0x10
        float u; // offset 0x0, size 0x4
        float v; // offset 0x4, size 0x4
        float xs; // offset 0x8, size 0x4
        float ys; // offset 0xC, size 0x4
    } * uv_tabP; // offset 0x0, size 0x4
    signed int anm_no; // offset 0x4, size 0x4
    signed int color; // offset 0x8, size 0x4
    signed int col_add; // offset 0xC, size 0x4
    signed int col_sub; // offset 0x10, size 0x4
} ANM_WORK;

typedef struct DSP_WORK {
    // total size: 0x70
    float vtx_scl; // offset 0x0, size 0x4
    struct /* @anon0 */ {
        // total size: 0xC
        float x; // offset 0x0, size 0x4
        float y; // offset 0x4, size 0x4
        float z; // offset 0x8, size 0x4
    } vtx_pos; // offset 0x4, size 0xC
    struct /* @anon6 */ {
        // total size: 0x18
        float x; // offset 0x0, size 0x4
        float y; // offset 0x4, size 0x4
        float z; // offset 0x8, size 0x4
        float u; // offset 0xC, size 0x4
        float v; // offset 0x10, size 0x4
        unsigned int col; // offset 0x14, size 0x4
    } VtxBuf[4]; // offset 0x10, size 0x60
} DSP_WORK;

typedef struct _rap_dsp_typ 
{
    // total size: 0xC
    struct /* @anon0 */ {
        // total size: 0xC
        float x; // offset 0x0, size 0x4
        float y; // offset 0x4, size 0x4
        float z; // offset 0x8, size 0x4
    } vtx_vel; // offset 0x0, size 0xC
} rap_dsp_typ;

typedef struct _rap_tex_typ {
    // total size: 0x98
    struct _rap_tex_typ * nextP; // offset 0x0, size 0x4
    signed int mode; // offset 0x4, size 0x4
    struct /* @anon21 */ {
        // total size: 0x70
        float vtx_scl; // offset 0x0, size 0x4
        struct /* @anon0 */ {
            // total size: 0xC
            float x; // offset 0x0, size 0x4
            float y; // offset 0x4, size 0x4
            float z; // offset 0x8, size 0x4
        } vtx_pos; // offset 0x4, size 0xC
        struct /* @anon6 */ {
            // total size: 0x18
            float x; // offset 0x0, size 0x4
            float y; // offset 0x4, size 0x4
            float z; // offset 0x8, size 0x4
            float u; // offset 0xC, size 0x4
            float v; // offset 0x10, size 0x4
            unsigned int col; // offset 0x14, size 0x4
        } VtxBuf[4]; // offset 0x10, size 0x60
    } dsp_wrk; // offset 0x8, size 0x70
    struct _rap_dsp_typ mov_wrk; // offset 0x78, size 0xC
    struct /* @anon20 */ {
        // total size: 0x14
        struct /* @anon9 */ {
            // total size: 0x10
            float u; // offset 0x0, size 0x4
            float v; // offset 0x4, size 0x4
            float xs; // offset 0x8, size 0x4
            float ys; // offset 0xC, size 0x4
        } * uv_tabP; // offset 0x0, size 0x4
        signed int anm_no; // offset 0x4, size 0x4
        signed int color; // offset 0x8, size 0x4
        signed int col_add; // offset 0xC, size 0x4
        signed int col_sub; // offset 0x10, size 0x4
    } anm_wrk; // offset 0x84, size 0x14
} rap_tex_typ;

static O_WRK* AllocOwork();
O_WRK* AllocOworkOne();
void bhClrEff_RY();
int bhSetBloodPoolLnk(BH_PWORK* ewP, NJS_POINT3* posP, int ay, BP_WORK* tabP, int pal_bnk);
void bhEff300(O_WRK* oP);
void bhEff301(O_WRK* oP);
O_WRK* bhSetEffParticle(BH_PWORK* ewP, int lnk_no, NJS_POINT3* offP, NJS_POINT3* dirP, unsigned int color, int typ_no);
O_WRK* bhSetEffParticleMk2(BH_PWORK* ewP, int lnk_no, NJS_POINT3* offP, NJS_POINT3* dirP, unsigned int src_col, unsigned int dst_col, int typ_no);
void bhEff302(O_WRK* oP);
void bhEff_PtclSpriteDrawB(O_WRK* oP);
void bhEff_PtclLineDraw(O_WRK* oP);
void bhEff303(O_WRK* oP);
int bhCheckCamWall2D(NJS_POINT3* srcP, NJS_POINT3* vctP, NJS_POINT3* rtnP, float rng_x, float rng_y);
O_WRK* rySetShadow(BH_PWORK* ewP, int obj0, int obj1, int obj2, float off_a, float off_b);
void bhEff304(O_WRK* oP);
void bhEff305(O_WRK* oP);
void bhEff306(O_WRK* oP);
OR_WORK* bhSetRapEff(int eff_no, void* datP, int lng_siz);
void bhEff307(OR_WORK* orP);
void bhEff307Drw(OR_WORK* orP);
void bhSetEffGunSpark(NJS_POINT3* posP, NJS_POINT3* dirP, unsigned int src_col, unsigned int dst_col, int typ_no);
void bhSetEffSpark(NJS_POINT3* posP, NJS_POINT3* dirP, unsigned int src_col, unsigned int dst_col, int typ_no);
void bhEff308(OR_WORK* orP);
void bhEff308Drw(OR_WORK* orP);
int ryLinerColor(int src_col, int dst_col, float rate);
OR_WORK* rySetEffBlood(NJS_MATRIX* mtxP, NJS_POINT3* posP, NJS_POINT3* dirP, int typ_no);
void bhEff309(OR_WORK* orP);
void bhEff309Drw(OR_WORK* orP);
void ryRapTexDrw(NJS_TEXLIST* texP, int tex_id, rap_tex_typ* rtP);
int ryRapTexAnm(ANM_WORK* anmP, DSP_WORK* dspP, int bol);
void ryRapDspSet(NJS_POINT3* posP, DSP_WORK* dspP, float scl);
void ryRapAnmColSet(ANM_WORK* anmP, int src_col, int dst_col, int col_cnt);
void bhEff30a(OR_WORK* orP);
void bhEff349(OR_WORK* orP);
OR_WORK* rySetEffBlood2(NJS_MATRIX* mtxP, NJS_POINT3* posP, NJS_POINT3* dirP, int typ_no);
void bhEff30b(OR_WORK* orP);
void bhEff30bDrw(OR_WORK* orP);
void bhEff30c(OR_WORK* orP);
void bhEff30cDrw(OR_WORK* orP);

#endif
