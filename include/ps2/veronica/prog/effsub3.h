#ifndef _EFFSUB3_H_
#define _EFFSUB3_H_

#include "types.h"

typedef struct OR_WORK 
{
    // total size: 0x4E0
    unsigned int flg;    // offset 0x0, size 0x4
    unsigned short id;   // offset 0x4, size 0x2
    char free0[10];      // offset 0x6, size 0xA
    float px;            // offset 0x10, size 0x4
    float py;            // offset 0x14, size 0x4
    float pz;            // offset 0x18, size 0x4
    int ax;              // offset 0x1C, size 0x4
    int ay;              // offset 0x20, size 0x4
    int az;              // offset 0x24, size 0x4
    char free1[24];      // offset 0x28, size 0x18
    float pxb;           // offset 0x40, size 0x4
    float pyb;           // offset 0x44, size 0x4
    float pzb;           // offset 0x48, size 0x4
    int axb;             // offset 0x4C, size 0x4
    int ayb;             // offset 0x50, size 0x4
    int azb;             // offset 0x54, size 0x4
    char free2[12];      // offset 0x58, size 0xC
    float lox;           // offset 0x64, size 0x4
    float loy;           // offset 0x68, size 0x4
    float loz;           // offset 0x6C, size 0x4
    char free3[24];      // offset 0x70, size 0x18
    unsigned int stflg;  // offset 0x88, size 0x4
    unsigned int Dummy;  // offset 0x8C, size 0x4
    char free4[1092];    // offset 0x90, size 0x444
    void (*func)(void*); // offset 0x4D4, size 0x4
    int idx;             // offset 0x4D8, size 0x4
    int Dummy2;          // offset 0x4DC, size 0x4
} OR_WORK;

typedef struct ANM_WORK 
{
    // total size: 0x14
    UV_WORK* uv_tabP; // offset 0x0, size 0x4
    int anm_no;       // offset 0x4, size 0x4
    int color;        // offset 0x8, size 0x4
    int col_add;      // offset 0xC, size 0x4
    int col_sub;      // offset 0x10, size 0x4
} ANM_WORK;

typedef struct DSP_WRK 
{
    // total size: 0x70
    float vtx_scl;             // offset 0x0, size 0x4
    NJS_POINT3 vtx_pos;        // offset 0x4, size 0xC
    NJS_TEXTURE_VTX VtxBuf[4]; // offset 0x10, size 0x60
} DSP_WRK;

typedef struct _rap_dsp_typ 
{
    // total size: 0xC
    NJS_POINT3 vtx_vel; // offset 0x0, size 0xC
} rap_dsp_typ;

typedef struct _rap_tex_typ rap_tex_typ;
struct _rap_tex_typ 
{
    // total size: 0x98
    rap_tex_typ* nextP;  // offset 0x0, size 0x4
    int mode;            // offset 0x4, size 0x4
    DSP_WRK dsp_wrk;    // offset 0x8, size 0x70
    rap_dsp_typ mov_wrk; // offset 0x78, size 0xC
    ANM_WORK anm_wrk;    // offset 0x84, size 0x14
};

typedef struct EFF302PRM_WORK 
{
    // total size: 0x30
    float vtx_speed;        // offset 0x0, size 0x4
    float vtx_accel;        // offset 0x4, size 0x4
    float ang_rand;         // offset 0x8, size 0x4
    float pos_rand;         // offset 0xC, size 0x4
    float spd_rand;         // offset 0x10, size 0x4
    float vtx_scale;        // offset 0x14, size 0x4
    int stg_erase;          // offset 0x18, size 0x4
    char stg_timer[6];      // offset 0x1C, size 0x6
    NJS_POINT3 vtx_gravity; // offset 0x24, size 0xC
} EFF302PRM_WORK;

typedef struct EFF30bPRM_WORK 
{
    // total size: 0x30
    float vtx_sp_min;     // offset 0x0, size 0x4
    float vtx_sp_max;     // offset 0x4, size 0x4
    float vtx_accel;      // offset 0x8, size 0x4
    float ang_rand;       // offset 0xC, size 0x4
    float vtx_scale;      // offset 0x10, size 0x4
    int vtx_erase;        // offset 0x14, size 0x4
    unsigned int col_src; // offset 0x18, size 0x4
    unsigned int col_dst; // offset 0x1C, size 0x4
    float vtx_gravity;    // offset 0x20, size 0x4
    int vtx_num;          // offset 0x24, size 0x4
    int eff_erase;        // offset 0x28, size 0x4
    float eff_rate;       // offset 0x2C, size 0x4
} EFF30bPRM_WORK;

typedef struct Eff301PRM_WORK 
{
    // total size: 0xC
    unsigned int color; // offset 0x0, size 0x4
    float vtx_range;    // offset 0x4, size 0x4
    float ang_rand;     // offset 0x8, size 0x4
} Eff301PRM_WORK;

typedef struct Eff305PRM_WORK 
{
    // total size: 0x1C
    unsigned int color; // offset 0x0, size 0x4
    float speed;        // offset 0x4, size 0x4
    float accel;        // offset 0x8, size 0x4
    int time;           // offset 0xC, size 0x4
    float offset;       // offset 0x10, size 0x4
    float src_scl;      // offset 0x14, size 0x4
    float dst_scl;      // offset 0x18, size 0x4
} Eff305PRM_WORK;

typedef struct Eff306PRM_WORK 
{
    // total size: 0x1C
    int tex_id;    // offset 0x0, size 0x4
    int wait;      // offset 0x4, size 0x4
    int time0;     // offset 0x8, size 0x4
    int time1;     // offset 0xC, size 0x4
    float offset;  // offset 0x10, size 0x4
    float src_scl; // offset 0x14, size 0x4
    float dst_scl; // offset 0x18, size 0x4
} Eff306PRM_WORK; 

typedef struct Eff308PRM_WORK 
{
    // total size: 0x24
    int vtx_num;    // offset 0x0, size 0x4
    float speed;    // offset 0x4, size 0x4
    float accel;    // offset 0x8, size 0x4
    float scale;    // offset 0xC, size 0x4
    int time;       // offset 0x10, size 0x4
    float ang_rand; // offset 0x14, size 0x4
    float spd_rand; // offset 0x18, size 0x4
    int tim_rand;   // offset 0x1C, size 0x4
    float gravity;  // offset 0x20, size 0x4
} Eff308PRM_WORK;

typedef struct Eff309PRM_WORK
{
    // total size: 0x30
    float speed;          // offset 0x0, size 0x4
    float accel;          // offset 0x4, size 0x4
    float scale;          // offset 0x8, size 0x4
    float scl_accel;      // offset 0xC, size 0x4
    char SetTim[8];       // offset 0x10, size 0x8
    float ang_rand;       // offset 0x18, size 0x4
    float spd_rand;       // offset 0x1C, size 0x4
    unsigned int col_src; // offset 0x20, size 0x4
    unsigned int col_dst; // offset 0x24, size 0x4
    float gravity;        // offset 0x28, size 0x4
    int pal_bank;         // offset 0x2C, size 0x4
} Eff309PRM_WORK;

typedef struct PD_WORK
{
    // total size: 0x4
    unsigned short mov_no; // offset 0x0, size 0x2
    unsigned char col_lv;  // offset 0x2, size 0x1
    unsigned char drw_typ; // offset 0x3, size 0x1
} PD_WORK;

typedef struct PT_WORK
{
    // total size: 0x8
    int set_num;  // offset 0x0, size 0x4
    PD_WORK* pdP; // offset 0x4, size 0x4
} PT_WORK;

typedef struct PRM_WORK 
{
    // total size: 0x10
    int anm_no;         // offset 0x0, size 0x4
    unsigned int color; // offset 0x4, size 0x4
    float speed;        // offset 0x8, size 0x4
    int time;           // offset 0xC, size 0x4
} PRM_WORK;

static O_WRK* AllocOwork();
O_WRK* AllocOworkOne();
void bhClrEff_RY();
int bhSetBloodPoolLnk(BH_PWORK* ewP, NJS_POINT3* posP, int ay, BP_WORK* tabP, int pal_bnk);
void bhEff300(O_WRK* oP);
void bhEff301(O_WRK* oP);
O_WRK* bhSetEffParticle(BH_PWORK* ewP, int lnk_no, NJS_POINT3* offP, NJS_POINT3* dirP, unsigned int color, int typ_no);
O_WRK* bhSetEffParticleMk2(BH_PWORK* ewP, int lnk_no, NJS_POINT3* offP, NJS_POINT3* dirP, unsigned int src_col, unsigned int dst_col, int typ_no);
void bhEff302(O_WRK* oP);
static void bhEff_PtclSpriteDrawB(O_WRK* oP);
static void bhEff_PtclLineDraw(O_WRK* oP);
void bhEff303(O_WRK* oP);
static int bhCheckCamWall2D(NJS_POINT3* srcP, NJS_POINT3* vctP, NJS_POINT3* rtnP, float rng_x, float rng_y);
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
static int ryLinerColor(int src_col, int dst_col, float rate);
OR_WORK* rySetEffBlood(NJS_MATRIX* mtxP, NJS_POINT3* posP, NJS_POINT3* dirP, int typ_no);
void bhEff309(OR_WORK* orP);
void bhEff309Drw(OR_WORK* orP);
static void ryRapTexDrw(NJS_TEXLIST* texP, int tex_id, rap_tex_typ* rtP);
static int ryRapTexAnm(ANM_WORK* anmP, DSP_WRK* dspP, int bol);
static void ryRapDspSet(NJS_POINT3* posP, DSP_WRK* dspP, float scl);
static void ryRapAnmColSet(ANM_WORK* anmP, int src_col, int dst_col, int col_cnt);
void bhEff30a(OR_WORK* orP);
void bhEff349(OR_WORK* orP);
OR_WORK* rySetEffBlood2(NJS_MATRIX* mtxP, NJS_POINT3* posP, NJS_POINT3* dirP, int typ_no);
void bhEff30b(OR_WORK* orP);
static void bhEff30bDrw(OR_WORK* orP);
void bhEff30c(OR_WORK* orP);
static void bhEff30cDrw(OR_WORK* orP);

#endif
