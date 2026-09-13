#include "../../../ps2/veronica/prog/en19.h"
#include "../../../ps2/veronica/prog/en29.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/subpl.h"

#pragma optimization_level 4

// ENEMY: Tentacle 

static void (*bhEne29_Mode0[6])(BH_PWORK*) = 
{
	bhEne29_Init,
	bhEne29_Move,
	bhEne29_Damage,
	bhEne29_Die,
	NULL,
	bhEne29_Event
};
static void (*bhEne29_BrainType[4])(BH_PWORK*) = 
{
	bhEne29_Br00,
	bhEne29_Br00,
	bhEne29_Br01,
	bhEne29_Br01
};

EA_WORK En29ActTbl[40] = 
{
    {   256,  0, 0, 0, 36, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    {   514,  2, 0, 0,  0, 1.0f,    0, (void*)bhEne29_Mv02 },
    {   768,  0, 0, 0, 24, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    {  1541,  5, 0, 0, 36, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    {  1799,  7, 0, 0,  0, 1.0f,    0, (void*)bhEne29_Mv02 },
    {  2053,  5, 0, 0, 24, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    {  2826, 10, 0, 0, 36, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    {  3084, 12, 0, 0,  0, 1.0f,    0, (void*)bhEne29_Mv02 },
    {  3338, 10, 0, 0, 24, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    {  4111, 15, 0, 0, 36, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    {  4369, 17, 0, 0,  0, 1.0f,    0, (void*)bhEne29_Mv02 },
    {  4623, 15, 0, 0, 24, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    {  7680,  0, 0, 0,  0, 1.0f,    0, (void*)bhEne29_Mv00 },
    {  7685,  5, 0, 0,  0, 1.0f,    0, (void*)bhEne29_Mv00 },
    {  7690, 10, 0, 0,  0, 1.0f,    0, (void*)bhEne29_Mv00 },
    {  7695, 15, 0, 0,  0, 1.0f,    0, (void*)bhEne29_Mv00 },
    { 65280,  0, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    { 65281,  1, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv01 },
    { 65282,  2, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv02 },
    { 65283,  3, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv03 },
    { 65284,  4, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv04 },
    { 65285,  5, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    { 65286,  6, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv01 },
    { 65287,  7, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv02 },
    { 65288,  8, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv03 },
    { 65289,  9, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv04 },
    { 65290, 10, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    { 65291, 11, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv01 },
    { 65292, 12, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv02 },
    { 65293, 13, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv03 },
    { 65294, 14, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv04 },
    { 65295, 15, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    { 65296, 16, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv01 },
    { 65297, 17, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv02 },
    { 65298, 18, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv03 },
    { 65299, 19, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv04 },
    { 65300, 20, 0, 0,  8, 1.0f,    0, (void*)bhEne29_Mv20 },
    { 65301, 21, 0, 0,  8, 1.0f,    0, (void*)bhEne29_Mv20 },
    { 65302, 22, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv00 },
    { 65303, 23, 0, 0,  8, 1.0f, 0x20, (void*)bhEne29_Mv00 }
};

static COMBWEP_WORK En29CombWepTbl[21] = 
{
    {  0, {  0,  0,  0 },   0, 0 },
    {  0, {  0,  0,  0 },   0, 0 },
    { 32, {  8,  0,  0 }, 160, 0 },
    { 32, { 11, 10,  9 },  90, 0 },
    { 32, { 11, 10,  9 },  90, 0 },
    { 32, { 11, 10,  9 },  90, 0 },
    { 32, { 11, 10,  9 },  90, 0 },
    {  0, {  0,  0,  0 },  30, 0 },
    { 32, {  4,  3,  2 },  30, 0 },
    { 32, { 11, 10,  9 },  90, 0 },
    { 32, { 11, 10,  9 },  60, 0 },
    { 32, { 16, 15, 14 },  80, 0 },
    { 32, {  4,  3,  2 },  30, 0 },
    { 32, {  9,  8,  7 },  90, 0 },
    {  1, {  1,  1,  1 },   0, 0 },
    {  1, {  1,  1,  1 },   0, 0 },
    {  1, {  1,  1,  1 },   0, 0 },
    {  1, {  1,  1,  1 },   0, 0 },
    {  1, {  1,  1,  1 },   0, 0 },
    { 24, { 11, 10,  9 },  60, 0 },
    {  1, {  1,  1,  1 },   0, 0 }
};
static COMBJOINT_WORK En29CombJointTbl[21] = { 0 };

ET_WORK TypPrm[4] = 
{
    { TC_OBJ_BODY00, TC_OBJ_BODY03, { 3.0f, 0.0f, 3.0f }, TC_OBJ_BODY11, 6.5f, TC_OBJ_BODY17, 6.5f },
    { TC_OBJ_BODY00, TC_OBJ_BODY03, { 3.0f, 0.0f, 3.0f }, TC_OBJ_BODY11, 6.0f, TC_OBJ_BODY16, 7.9f },
    { TC_OBJ_BODY00, TC_OBJ_BODY03, { 3.0f, 0.0f, 3.0f }, TC_OBJ_BODY08, 9.0f, TC_OBJ_BODY16, 8.0f },
    { TC_OBJ_BODY00, TC_OBJ_BODY03, { 3.0f, 0.0f, 3.0f }, TC_OBJ_BODY08, 9.0f, TC_OBJ_BODY16, 8.0f }
};
int E29EffTbl[9][4] = 
{
    { 0,      3,  0,   0 },
    { 0,      4,  0,   0 },
    { 0,      5,  0,   0 },
    { 1,      3,  0,   0 },
    { 1,      4,  0,   0 },
    { 1,      5,  0,   0 },
    { 2,      1,  2, 306 },
    { 3,      2,  5, 301 },
    { 4, 131072, 40, 298 }  
};

static const char En29FlpTbl[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
static const CPCL Ene29CapColTbl[15] = 
{
    {  1,  4, 20 },
    {  4,  6, 20 },
    {  6,  8, 18 },
    {  8, 10, 18 },
    {  9, 10, 16 },
    { 10, 11, 16 },
    { 11, 12, 14 },
    { 12, 13, 14 },
    { 13, 14, 12 },
    { 14, 15, 12 },
    { 15, 16, 10 },
    { 16, 17, 10 },
    { 17, 18,  8 },
    { 18, 19,  8 },
    {  0,  0,  0 }
};
static const ACT_TBL_WORK En29PlyActTbl[2] = 
{
    { 30, 0, 0, 8, 255, -1, 0x20, (void*)bhEne29_PlyDmg117 },
    { 31, 0, 0, 8, 255, -1, 0x20, (void*)bhEne29_PlyDmg118 }
};
static const ETTY_WORK En29DmgDat = { 0x8021, 29, 8, 0, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, { 0, 0, 0, 0 } };
static const DS_WORK E29DmgSet[5] = 
{
    { TC_OBJ_BODY00, TC_OBJ_BODY03, 2.0f, 16 },
    { TC_OBJ_BODY04, TC_OBJ_BODY07, 2.0f,  0 },
    { TC_OBJ_BODY08, TC_OBJ_BODY11, 2.0f, 16 },
    { TC_OBJ_BODY12, TC_OBJ_BODY15, 2.0f, 16 },
    { TC_OBJ_BODY16, TC_OBJ_BODY18, 2.0f, 16 }
};
/* unused below */
/*OFF_TBL_WORK E29OffTbl[20];
TC_BR_MODE0 InitBrnMde[4];*/

// 100% matching!
void bhEne29(BH_PWORK* ewP)
{
    if (ewP->type != 8)
    {
        bhEne29_Mode0[ewP->mode0](ewP);

        if (ewP->mode0 != TC_PRG_INIT)
        {
            ((en29_freework*)ewP->exp0)->mode0_bak = (unsigned char)ewP->mode0;
        }
    }
}

// 
// Start address: 0x210a70
static void bhEne29_Init(BH_PWORK* ewP)
{
	O_WRK* oP;
	NJS_POINT3* szP;
	//ATR_WORK* htP;
	ET_WORK* etP;
	ATR_WORK* htP;
	en29_freework* fwP;
	// Line 375, Address: 0x210a70, Func Offset: 0
	// Line 379, Address: 0x210a80, Func Offset: 0x10
	// Line 383, Address: 0x210aa4, Func Offset: 0x34
	// Line 386, Address: 0x210ab4, Func Offset: 0x44
	// Line 395, Address: 0x210abc, Func Offset: 0x4c
	// Line 388, Address: 0x210ac4, Func Offset: 0x54
	// Line 386, Address: 0x210ac8, Func Offset: 0x58
	// Line 390, Address: 0x210ad4, Func Offset: 0x64
	// Line 395, Address: 0x210ad8, Func Offset: 0x68
	// Line 386, Address: 0x210adc, Func Offset: 0x6c
	// Line 387, Address: 0x210b10, Func Offset: 0xa0
	// Line 388, Address: 0x210b1c, Func Offset: 0xac
	// Line 389, Address: 0x210b20, Func Offset: 0xb0
	// Line 390, Address: 0x210b24, Func Offset: 0xb4
	// Line 391, Address: 0x210b28, Func Offset: 0xb8
	// Line 392, Address: 0x210b38, Func Offset: 0xc8
	// Line 395, Address: 0x210b3c, Func Offset: 0xcc
	// Line 398, Address: 0x210b48, Func Offset: 0xd8
	// Line 401, Address: 0x210b4c, Func Offset: 0xdc
	// Line 410, Address: 0x210b50, Func Offset: 0xe0
	// Line 411, Address: 0x210b54, Func Offset: 0xe4
	// Line 414, Address: 0x210b58, Func Offset: 0xe8
	// Line 401, Address: 0x210b5c, Func Offset: 0xec
	// Line 402, Address: 0x210b60, Func Offset: 0xf0
	// Line 403, Address: 0x210b64, Func Offset: 0xf4
	// Line 404, Address: 0x210b68, Func Offset: 0xf8
	// Line 410, Address: 0x210b6c, Func Offset: 0xfc
	// Line 411, Address: 0x210b70, Func Offset: 0x100
	// Line 412, Address: 0x210b74, Func Offset: 0x104
	// Line 413, Address: 0x210b78, Func Offset: 0x108
	// Line 414, Address: 0x210b7c, Func Offset: 0x10c
	// Line 416, Address: 0x210b80, Func Offset: 0x110
	// Line 415, Address: 0x210b84, Func Offset: 0x114
	// Line 416, Address: 0x210b88, Func Offset: 0x118
	// Line 417, Address: 0x210b8c, Func Offset: 0x11c
	// Line 420, Address: 0x210b98, Func Offset: 0x128
	// Line 421, Address: 0x210b9c, Func Offset: 0x12c
	// Line 422, Address: 0x210ba0, Func Offset: 0x130
	// Line 423, Address: 0x210ba4, Func Offset: 0x134
	// Line 426, Address: 0x210ba8, Func Offset: 0x138
	// Line 424, Address: 0x210bac, Func Offset: 0x13c
	// Line 426, Address: 0x210bb0, Func Offset: 0x140
	// Line 425, Address: 0x210bb4, Func Offset: 0x144
	// Line 426, Address: 0x210bb8, Func Offset: 0x148
	// Line 429, Address: 0x210bbc, Func Offset: 0x14c
	// Line 430, Address: 0x210bc0, Func Offset: 0x150
	// Line 435, Address: 0x210bc4, Func Offset: 0x154
	// Line 436, Address: 0x210bc8, Func Offset: 0x158
	// Line 429, Address: 0x210bcc, Func Offset: 0x15c
	// Line 430, Address: 0x210bd4, Func Offset: 0x164
	// Line 437, Address: 0x210bd8, Func Offset: 0x168
	// Line 438, Address: 0x210bdc, Func Offset: 0x16c
	// Line 439, Address: 0x210be0, Func Offset: 0x170
	// Line 430, Address: 0x210be4, Func Offset: 0x174
	// Line 431, Address: 0x210bec, Func Offset: 0x17c
	// Line 446, Address: 0x210bf0, Func Offset: 0x180
	// Line 440, Address: 0x210bf4, Func Offset: 0x184
	// Line 446, Address: 0x210bf8, Func Offset: 0x188
	// Line 431, Address: 0x210bfc, Func Offset: 0x18c
	// Line 435, Address: 0x210c04, Func Offset: 0x194
	// Line 436, Address: 0x210c08, Func Offset: 0x198
	// Line 437, Address: 0x210c0c, Func Offset: 0x19c
	// Line 438, Address: 0x210c10, Func Offset: 0x1a0
	// Line 439, Address: 0x210c14, Func Offset: 0x1a4
	// Line 440, Address: 0x210c20, Func Offset: 0x1b0
	// Line 443, Address: 0x210c24, Func Offset: 0x1b4
	// Line 446, Address: 0x210c2c, Func Offset: 0x1bc
	// Line 448, Address: 0x210c40, Func Offset: 0x1d0
	// Line 449, Address: 0x210c48, Func Offset: 0x1d8
	// Line 450, Address: 0x210c50, Func Offset: 0x1e0
	// Line 451, Address: 0x210c58, Func Offset: 0x1e8
	// Line 452, Address: 0x210c60, Func Offset: 0x1f0
	// Line 453, Address: 0x210c68, Func Offset: 0x1f8
	// Line 458, Address: 0x210c70, Func Offset: 0x200
	// Line 461, Address: 0x210c74, Func Offset: 0x204
	// Line 462, Address: 0x210c80, Func Offset: 0x210
	// Line 463, Address: 0x210c88, Func Offset: 0x218
	// Line 464, Address: 0x210c90, Func Offset: 0x220
	// Line 465, Address: 0x210c98, Func Offset: 0x228
	// Line 470, Address: 0x210cb0, Func Offset: 0x240
	// Line 473, Address: 0x210cc0, Func Offset: 0x250
	// Line 474, Address: 0x210cc8, Func Offset: 0x258
	// Line 475, Address: 0x210ce4, Func Offset: 0x274
	// Line 474, Address: 0x210ce8, Func Offset: 0x278
	// Line 475, Address: 0x210cec, Func Offset: 0x27c
	// Line 476, Address: 0x210cf0, Func Offset: 0x280
	// Line 477, Address: 0x210cf4, Func Offset: 0x284
	// Line 481, Address: 0x210cfc, Func Offset: 0x28c
	// Line 482, Address: 0x210d10, Func Offset: 0x2a0
	// Line 499, Address: 0x210d28, Func Offset: 0x2b8
	// Line 500, Address: 0x210d40, Func Offset: 0x2d0
	// Func End, Address: 0x210d54, Func Offset: 0x2e4
}

// 
// Start address: 0x210d60
static void bhEne29_Move(BH_PWORK* ewP)
{
	//en29_freework* fwP;
	en29_freework* fwP;
	// Line 510, Address: 0x210d60, Func Offset: 0
	// Line 511, Address: 0x210d70, Func Offset: 0x10
	// Line 521, Address: 0x210d78, Func Offset: 0x18
	// Line 519, Address: 0x210d80, Func Offset: 0x20
	// Line 521, Address: 0x210d90, Func Offset: 0x30
	// Line 527, Address: 0x210da0, Func Offset: 0x40
	// Line 528, Address: 0x210db0, Func Offset: 0x50
	// Line 534, Address: 0x210db8, Func Offset: 0x58
	// Line 535, Address: 0x210dbc, Func Offset: 0x5c
	// Line 538, Address: 0x210dc0, Func Offset: 0x60
	// Line 539, Address: 0x210df0, Func Offset: 0x90
	// Line 545, Address: 0x210e20, Func Offset: 0xc0
	// Line 548, Address: 0x210e2c, Func Offset: 0xcc
	// Line 551, Address: 0x210e4c, Func Offset: 0xec
	// Line 554, Address: 0x210e68, Func Offset: 0x108
	// Line 557, Address: 0x210e74, Func Offset: 0x114
	// Line 560, Address: 0x210e94, Func Offset: 0x134
	// Line 562, Address: 0x210ea4, Func Offset: 0x144
	// Func End, Address: 0x210eb8, Func Offset: 0x158
}

// 100% matching!
static void bhEne29_Die()
{
	
}

// 100% matching!
static void bhEne29_Damage()
{

}

// 100% matching!
static void bhEne29_Event(BH_PWORK* ewP)
{
	en29_freework* fwP;

	fwP = (en29_freework*)ewP->exp0;

	fwP->hit_tabP->flg &= ~0x1;

    fwP->sdw_owkP->stflg |= 0x1000000;

    bhEne_Event(ewP);

    bhSetMotion(ewP, ewP->mtn_add, ewP->mtn_md, ewP->mtn_tp);

    bhEne29_CalcEnemy(ewP, (en29_freework*)ewP->exp0);
}

// 
// Start address: 0x210f50
static void bhEne29_Br00(BH_PWORK* ewP)
{
	int lop;
	int rte;
	TC_ACT_NO act;
	TC_BR_MODE1* br1P;
	TC_BR_MODE0* br0P;
	int sts;
	int typ;
	int* stsP;
	eaw_typ* eawP;
	en29_freework* fwP;
	// Line 612, Address: 0x210f50, Func Offset: 0
	// Line 624, Address: 0x210f6c, Func Offset: 0x1c
	// Line 613, Address: 0x210f74, Func Offset: 0x24
	// Line 620, Address: 0x210f78, Func Offset: 0x28
	// Line 624, Address: 0x210f84, Func Offset: 0x34
	// Line 614, Address: 0x210f90, Func Offset: 0x40
	// Line 620, Address: 0x210f94, Func Offset: 0x44
	// Line 616, Address: 0x210f98, Func Offset: 0x48
	// Line 624, Address: 0x210f9c, Func Offset: 0x4c
	// Line 625, Address: 0x210fa8, Func Offset: 0x58
	// Line 628, Address: 0x210fac, Func Offset: 0x5c
	// Line 625, Address: 0x210fb0, Func Offset: 0x60
	// Line 628, Address: 0x210fb4, Func Offset: 0x64
	// Line 632, Address: 0x210fbc, Func Offset: 0x6c
	// Line 636, Address: 0x210fc4, Func Offset: 0x74
	// Line 633, Address: 0x210fc8, Func Offset: 0x78
	// Line 634, Address: 0x210fcc, Func Offset: 0x7c
	// Line 635, Address: 0x210fd4, Func Offset: 0x84
	// Line 637, Address: 0x210fd8, Func Offset: 0x88
	// Line 641, Address: 0x210fe0, Func Offset: 0x90
	// Line 651, Address: 0x210fec, Func Offset: 0x9c
	// Line 652, Address: 0x210ffc, Func Offset: 0xac
	// Line 653, Address: 0x211008, Func Offset: 0xb8
	// Line 654, Address: 0x21101c, Func Offset: 0xcc
	// Line 656, Address: 0x211020, Func Offset: 0xd0
	// Line 657, Address: 0x211028, Func Offset: 0xd8
	// Line 658, Address: 0x211034, Func Offset: 0xe4
	// Line 659, Address: 0x211038, Func Offset: 0xe8
	// Line 668, Address: 0x21103c, Func Offset: 0xec
	// Line 670, Address: 0x211040, Func Offset: 0xf0
	// Line 673, Address: 0x211078, Func Offset: 0x128
	// Line 674, Address: 0x211084, Func Offset: 0x134
	// Line 676, Address: 0x21108c, Func Offset: 0x13c
	// Line 677, Address: 0x211094, Func Offset: 0x144
	// Line 678, Address: 0x2110b4, Func Offset: 0x164
	// Line 679, Address: 0x2110b8, Func Offset: 0x168
	// Line 681, Address: 0x2110bc, Func Offset: 0x16c
	// Line 682, Address: 0x2110c4, Func Offset: 0x174
	// Line 684, Address: 0x2110c8, Func Offset: 0x178
	// Line 686, Address: 0x2110dc, Func Offset: 0x18c
	// Line 689, Address: 0x2110e4, Func Offset: 0x194
	// Line 693, Address: 0x211108, Func Offset: 0x1b8
	// Line 694, Address: 0x21110c, Func Offset: 0x1bc
	// Line 697, Address: 0x211114, Func Offset: 0x1c4
	// Line 699, Address: 0x21111c, Func Offset: 0x1cc
	// Line 701, Address: 0x211120, Func Offset: 0x1d0
	// Line 704, Address: 0x211128, Func Offset: 0x1d8
	// Line 706, Address: 0x211138, Func Offset: 0x1e8
	// Line 711, Address: 0x21113c, Func Offset: 0x1ec
	// Line 714, Address: 0x211144, Func Offset: 0x1f4
	// Line 717, Address: 0x21116c, Func Offset: 0x21c
	// Line 719, Address: 0x211178, Func Offset: 0x228
	// Line 720, Address: 0x21117c, Func Offset: 0x22c
	// Line 721, Address: 0x211184, Func Offset: 0x234
	// Line 722, Address: 0x2111a0, Func Offset: 0x250
	// Line 724, Address: 0x2111a4, Func Offset: 0x254
	// Line 730, Address: 0x2111ac, Func Offset: 0x25c
	// Line 732, Address: 0x2111bc, Func Offset: 0x26c
	// Line 738, Address: 0x2111c4, Func Offset: 0x274
	// Line 744, Address: 0x2111d0, Func Offset: 0x280
	// Line 747, Address: 0x2111d8, Func Offset: 0x288
	// Line 750, Address: 0x211204, Func Offset: 0x2b4
	// Line 752, Address: 0x211208, Func Offset: 0x2b8
	// Line 755, Address: 0x211210, Func Offset: 0x2c0
	// Line 756, Address: 0x211220, Func Offset: 0x2d0
	// Line 757, Address: 0x21122c, Func Offset: 0x2dc
	// Line 758, Address: 0x211230, Func Offset: 0x2e0
	// Line 767, Address: 0x211234, Func Offset: 0x2e4
	// Line 768, Address: 0x211238, Func Offset: 0x2e8
	// Line 771, Address: 0x211244, Func Offset: 0x2f4
	// Line 772, Address: 0x211250, Func Offset: 0x300
	// Line 773, Address: 0x211264, Func Offset: 0x314
	// Line 775, Address: 0x211268, Func Offset: 0x318
	// Line 780, Address: 0x211274, Func Offset: 0x324
	// Func End, Address: 0x211294, Func Offset: 0x344
}

// 
// Start address: 0x2112a0
static void bhEne29_Br01(BH_PWORK* ewP)
{
	int lop;
	int rte;
	TC_ACT_NO act;
	TC_BR_MODE1* br1P;
	TC_BR_MODE0* br0P;
	int sts;
	int typ;
	int* stsP;
	eaw_typ* eawP;
	en29_freework* fwP;
	// Line 790, Address: 0x2112a0, Func Offset: 0
	// Line 791, Address: 0x2112bc, Func Offset: 0x1c
	// Line 798, Address: 0x2112c0, Func Offset: 0x20
	// Line 792, Address: 0x2112cc, Func Offset: 0x2c
	// Line 798, Address: 0x2112d0, Func Offset: 0x30
	// Line 802, Address: 0x2112e4, Func Offset: 0x44
	// Line 806, Address: 0x2112ec, Func Offset: 0x4c
	// Line 802, Address: 0x2112f4, Func Offset: 0x54
	// Line 803, Address: 0x21130c, Func Offset: 0x6c
	// Line 806, Address: 0x211314, Func Offset: 0x74
	// Line 810, Address: 0x21131c, Func Offset: 0x7c
	// Line 814, Address: 0x211324, Func Offset: 0x84
	// Line 815, Address: 0x211328, Func Offset: 0x88
	// Line 811, Address: 0x211334, Func Offset: 0x94
	// Line 812, Address: 0x211338, Func Offset: 0x98
	// Line 813, Address: 0x21133c, Func Offset: 0x9c
	// Line 815, Address: 0x211340, Func Offset: 0xa0
	// Line 818, Address: 0x21134c, Func Offset: 0xac
	// Line 828, Address: 0x211358, Func Offset: 0xb8
	// Line 829, Address: 0x211368, Func Offset: 0xc8
	// Line 830, Address: 0x211374, Func Offset: 0xd4
	// Line 831, Address: 0x211388, Func Offset: 0xe8
	// Line 833, Address: 0x211390, Func Offset: 0xf0
	// Line 834, Address: 0x211398, Func Offset: 0xf8
	// Line 835, Address: 0x2113a4, Func Offset: 0x104
	// Line 836, Address: 0x2113a8, Func Offset: 0x108
	// Line 845, Address: 0x2113ac, Func Offset: 0x10c
	// Line 847, Address: 0x2113b0, Func Offset: 0x110
	// Line 850, Address: 0x2113f4, Func Offset: 0x154
	// Line 851, Address: 0x211400, Func Offset: 0x160
	// Line 853, Address: 0x211408, Func Offset: 0x168
	// Line 854, Address: 0x211410, Func Offset: 0x170
	// Line 855, Address: 0x211430, Func Offset: 0x190
	// Line 856, Address: 0x211434, Func Offset: 0x194
	// Line 858, Address: 0x211438, Func Offset: 0x198
	// Line 859, Address: 0x211440, Func Offset: 0x1a0
	// Line 861, Address: 0x211448, Func Offset: 0x1a8
	// Line 863, Address: 0x211460, Func Offset: 0x1c0
	// Line 866, Address: 0x211468, Func Offset: 0x1c8
	// Line 869, Address: 0x21148c, Func Offset: 0x1ec
	// Line 871, Address: 0x211490, Func Offset: 0x1f0
	// Line 874, Address: 0x211498, Func Offset: 0x1f8
	// Line 876, Address: 0x2114a0, Func Offset: 0x200
	// Line 875, Address: 0x2114a4, Func Offset: 0x204
	// Line 878, Address: 0x2114a8, Func Offset: 0x208
	// Line 881, Address: 0x2114b0, Func Offset: 0x210
	// Line 883, Address: 0x2114c0, Func Offset: 0x220
	// Line 882, Address: 0x2114c4, Func Offset: 0x224
	// Line 887, Address: 0x2114c8, Func Offset: 0x228
	// Line 890, Address: 0x2114d0, Func Offset: 0x230
	// Line 893, Address: 0x2114f8, Func Offset: 0x258
	// Line 894, Address: 0x211504, Func Offset: 0x264
	// Line 896, Address: 0x211508, Func Offset: 0x268
	// Line 897, Address: 0x211510, Func Offset: 0x270
	// Line 898, Address: 0x211530, Func Offset: 0x290
	// Line 900, Address: 0x211534, Func Offset: 0x294
	// Line 906, Address: 0x21153c, Func Offset: 0x29c
	// Line 908, Address: 0x21154c, Func Offset: 0x2ac
	// Line 914, Address: 0x211554, Func Offset: 0x2b4
	// Line 920, Address: 0x211560, Func Offset: 0x2c0
	// Line 923, Address: 0x211568, Func Offset: 0x2c8
	// Line 926, Address: 0x211594, Func Offset: 0x2f4
	// Line 928, Address: 0x211598, Func Offset: 0x2f8
	// Line 931, Address: 0x2115a0, Func Offset: 0x300
	// Line 932, Address: 0x2115b0, Func Offset: 0x310
	// Line 933, Address: 0x2115bc, Func Offset: 0x31c
	// Line 942, Address: 0x2115c0, Func Offset: 0x320
	// Line 945, Address: 0x2115c8, Func Offset: 0x328
	// Line 948, Address: 0x2115f4, Func Offset: 0x354
	// Line 950, Address: 0x2115f8, Func Offset: 0x358
	// Line 954, Address: 0x211600, Func Offset: 0x360
	// Line 955, Address: 0x211618, Func Offset: 0x378
	// Line 956, Address: 0x21161c, Func Offset: 0x37c
	// Line 957, Address: 0x211628, Func Offset: 0x388
	// Line 958, Address: 0x211630, Func Offset: 0x390
	// Line 959, Address: 0x211638, Func Offset: 0x398
	// Line 962, Address: 0x211640, Func Offset: 0x3a0
	// Line 966, Address: 0x211654, Func Offset: 0x3b4
	// Line 968, Address: 0x211658, Func Offset: 0x3b8
	// Line 971, Address: 0x211664, Func Offset: 0x3c4
	// Line 972, Address: 0x211670, Func Offset: 0x3d0
	// Line 973, Address: 0x211684, Func Offset: 0x3e4
	// Line 974, Address: 0x211688, Func Offset: 0x3e8
	// Line 978, Address: 0x211694, Func Offset: 0x3f4
	// Func End, Address: 0x2116b4, Func Offset: 0x414
}

// 100% matching!
static void bhEne29_Mv00(BH_PWORK* ewP, en29_freework* fwP, int count) // parameters not present on DWARF
{

}

// 100% matching!
static void bhEne29_Mv01(BH_PWORK* ewP, en29_freework* fwP, int count)
{
	if (count == 0)
    {
        RequestEnemySe(sys->enow, (NJS_POINT3*)&ewP->mlwP->owP[fwP->bas_obj].mtx[12], 74498);
    }

    if (bhEne29_AttackHitCheck(ewP, fwP) != -1)
    {
        bhEne29_PlySetDamage(plp, fwP, 2);

        fwP->status |= 0x8;
    }
}

// 100% matching!
static void bhEne29_Mv02(BH_PWORK* ewP, en29_freework* fwP, int count)
{
	if (count == 0)
    {
        RequestEnemySe(sys->enow, (NJS_POINT3*)&ewP->mlwP->owP[fwP->bas_obj].mtx[12], 74499);
    }
}

// 100% matching!
static void bhEne29_Mv03(BH_PWORK* ewP, en29_freework* fwP, int count)
{
	if (count == 0)
    {
        RequestEnemySe(sys->enow, (NJS_POINT3*)&ewP->mlwP->owP[fwP->bas_obj].mtx[12], 74499);
    }

    if (bhEne29_AttackHitCheck(ewP, fwP) != -1)
    {
        bhEne29_PlySetDamage(plp, fwP, 2);

        fwP->status |= 0x8;
    }
}

// 100% matching!
static void bhEne29_Mv04(BH_PWORK* ewP, en29_freework* fwP, int count) // third parameter not present on DWARF
{
	if ((fwP->ene_act.mtn_rte < 65536) && (ChechPlayEnemySe(sys->enow, 74499) == 0))
    {
        RequestEnemySe(sys->enow, (NJS_POINT3*)&ewP->mlwP->owP[fwP->bas_obj].mtx[12], 74499);
    }
}

// 100% matching!
static void bhEne29_Mv20(BH_PWORK* ewP, en29_freework* fwP, int count) // third parameter not present on DWARF
{
	if (bhEne29_AttackHitCheck(ewP, fwP) != -1)
    {
        bhEne29_PlySetDamage(plp, fwP, 2);

        fwP->status |= 0x8;
    }
}

// 100% matching!
static void bhEne29_ActionInit(eaw_typ* eawP, EA_WORK* act_tblP, int tbl_num)
{
	eawP->act_tblP = act_tblP;

	eawP->tbl_num = tbl_num;

	eawP->act_now = 30;
}

// 100% matching!
static EA_WORK* bhEne29_ActionSearch(eaw_typ* eawP, int act_nw, int act_no)
{
    EA_WORK* eaP; 
    int key;     
    int high, low, middle;    
	int val;      
    
    eaP = eawP->act_tblP;
    
    key = ((unsigned char)act_nw << 8) | ((unsigned char)act_no << 0);
    
    high = eawP->tbl_num;
    low  = 0;

    while (low <= high) 
    {
        middle = (low + high) / 2;
         
        val = eaP[middle].label;

        if (key != val) 
        {
            if (key < val) 
            { 
                high = middle - 1;
            }
            else if (key > val) 
            { 
                low  = middle + 1;
            }
        } 
        else 
        {
            return &eaP[middle];
        }
    }
    
    return NULL;
}

// 100% matching!
static int bhEne29_ActionChange(BH_PWORK* ewP, eaw_typ* eawP, int act_dst)
{
	EA_WORK* eaP;
    
    if (((eaP = bhEne29_ActionSearch(eawP, eawP->act_now, act_dst)) == NULL) && (eawP->act_now != act_dst)) 
    {
        eaP = bhEne29_ActionSearch(eawP, -1, act_dst);
    }
    
    if (eaP != NULL) 
    {
        njMemCopy4(&eawP->b_act_flg, &eawP->act_flg, 7);
        
        eawP->b_mtn_md = ewP->mtn_md;
        
        eawP->act_flg = 0;
        
        eawP->prgP = eaP->prgP;
        
        eawP->act_cnt = 0;
        eawP->act_frm = eaP->frm_no;
        
        ewP->mtn_no = eaP->mtn_no;
        ewP->frm_no = eaP->frm_no * 65536;
        
        ewP->hokan_rate  = eaP->hkn_lvl * (65536.0 / 255.0);
        ewP->hokan_count = eaP->hkn_cnt;

        if ((eaP->flag & 0x20000)) 
        {
            ewP->mtn_add = 0;
        } 
        else if ((eaP->flag & 0x40000)) 
        {
            ewP->mtn_add = -65536;
        } 
        else 
        {
            ewP->mtn_add =  65536;
        }

        ewP->mtn_md = (unsigned short)eaP->flag;
        
        eawP->chg_rte = eaP->chg_rte * 65536.0f;
        
        eawP->act_now = act_dst;
        
        return 1;
    }
    
    return 0;
}

// 100% matching!
static int bhEne29_ActionMain(BH_PWORK* ewP, eaw_typ* eawP)
{
	short* s16P;
    
    if (eawP->prgP != NULL) 
    {
        eawP->prgP(ewP, ewP->exp0, eawP->act_cnt++);
    }
    
    s16P = (short*)&eawP->act_frm;
    
    s16P[1] += bhSetMotion(ewP, ewP->mtn_add, ewP->mtn_md, ewP->mtn_tp);
    s16P[0] =  ewP->frm_no / 65536;
    
    eawP->mtn_rte = ewP->frm_no / (ewP->mnwP[ewP->mtn_no].frm_num - 1);
    
    return 0;
}

// 100% matching!
static void bhEne29_TargetAnalyze(BH_PWORK* ewP, en29_freework* fwP)
{
    int* stsP;       
    NJS_POINT3* vP;  
    
    stsP = &fwP->status;

    if (((*stsP & 0x1)) && ((plp->hp < 0) || ((plp->flg & 0x2)))) 
    {
        *stsP |= 0x20;
    }

    vP = (NJS_POINT3*)&ewP->mlwP->owP[fwP->bas_obj].mtx[8];
    
    fwP->bas_ax = 10430.381f * asinf(vP->y);
    fwP->bas_ay = 10430.381f * atan2f(vP->x, vP->z);

    {
    NJS_POINT3 dlt; 
    int ad;          
    
    dlt = *(NJS_POINT3*)&ewP->mlwP->owP[fwP->bas_obj].mtx[12];
        
    njSubVector(&dlt, &fwP->tgt_pos);

    ad = (int)(10430.381f * atan2f(dlt.x, dlt.z)) - fwP->bas_ay;
        
    *stsP &= ~0xC00;
        
    if ((short)ad < 0) 
    {
        *stsP |= 0x800;
    } 
    else
    {
        *stsP |= 0x400;
    }
    }

    {
    int dlt;   
        
    dlt = (unsigned short)(plp->ay - fwP->bas_ay);
        
    if ((dlt & 0x8000)) 
    {
        dlt = (65536 - dlt) | 0x80000000;
    }
        
    fwP->dir_dlt = dlt;
    }

    *stsP &= ~0x200;

    {
    NJS_POINT3 dlt;
    float dst;      
    
    dlt = *(NJS_POINT3*)&ewP->mlwP->owP[fwP->atk_obj0].mtx[12];
        
    njSubVector(&dlt, &fwP->tgt_pos);

    vP = (NJS_POINT3*)&dlt.z;
        
    dst = (dlt.x * dlt.x) + (vP->x * vP->x);

    if (dst <= (fwP->atk_rng0 * fwP->atk_rng0)) 
    {
        *stsP |= 0x200;
    } 
    else 
    {
        dlt = *(NJS_POINT3*)&ewP->mlwP->owP[fwP->atk_obj1].mtx[12];
        
        njSubVector(&dlt, &fwP->tgt_pos);
        
        dst = (dlt.x * dlt.x) + (vP->x * vP->x);
        
        if (dst <= (fwP->atk_rng1 * fwP->atk_rng1))
        {
            *stsP |= 0x200;
        }
    }
    }
}

// 100% matching!
static void bhEne29_CalcEnemy(BH_PWORK* ewP, en29_freework* fwP)
{
	ATR_WORK* htP;

    bhCalcModel(ewP);

    CalcDmgEne(ewP, fwP);

    htP = fwP->hit_tabP;

    htP->px = ewP->mlwP->owP[fwP->atr_obj].mtx[12];
    htP->pz = ewP->mlwP->owP[fwP->atr_obj].mtx[14];
}

// 
// Start address: 0x211fc0
static void bhEne29_DmgCheck(BH_PWORK* ewP, en29_freework* fwP)
{
	DD_WRK* ddP;
	int dmg_obj;
	static const DD_WRK DmgDat[21] = 
	{
		{ 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 3, 1, 4 }, { 0, 3, 1, 4 },
		{ 0, 3, 1, 4 }, { 0, 3, 1, 4 }, { 1, 4, 2, 5 }, { 0, 3, 1, 4 },
		{ 0, 3, 0, 4 }, { 0, 3, 1, 4 }, { 0, 3, 1, 4 }, { 1, 4, 2, 5 },
		{ 0, 3, 1, 4 }, { 2, 4, 2, 5 }, { 2, 4, 2, 5 }, { 0, 8, 1, 8 },
		{ 0, 6, 1, 6 }, { 2, 4, 2, 5 }, { 2, 5, 2, 5 }, { 1, 3, 2, 4 },
		{ 2, 5, 2, 5 }
	};
	// Line 1349, Address: 0x211fc0, Func Offset: 0
	// Line 1377, Address: 0x211fd8, Func Offset: 0x18
	// Line 1379, Address: 0x211fe0, Func Offset: 0x20
	// Line 1383, Address: 0x211ff0, Func Offset: 0x30
	// Line 1386, Address: 0x211ffc, Func Offset: 0x3c
	// Line 1393, Address: 0x212014, Func Offset: 0x54
	// Line 1387, Address: 0x21201c, Func Offset: 0x5c
	// Line 1393, Address: 0x212020, Func Offset: 0x60
	// Line 1411, Address: 0x212028, Func Offset: 0x68
	// Line 1413, Address: 0x21202c, Func Offset: 0x6c
	// Line 1415, Address: 0x212038, Func Offset: 0x78
	// Line 1419, Address: 0x212044, Func Offset: 0x84
	// Line 1415, Address: 0x212048, Func Offset: 0x88
	// Line 1419, Address: 0x21204c, Func Offset: 0x8c
	// Line 1420, Address: 0x212058, Func Offset: 0x98
	// Line 1421, Address: 0x212064, Func Offset: 0xa4
	// Line 1423, Address: 0x212070, Func Offset: 0xb0
	// Line 1424, Address: 0x21207c, Func Offset: 0xbc
	// Line 1429, Address: 0x212084, Func Offset: 0xc4
	// Line 1430, Address: 0x2120a0, Func Offset: 0xe0
	// Line 1433, Address: 0x2120ac, Func Offset: 0xec
	// Line 1438, Address: 0x2120b8, Func Offset: 0xf8
	// Line 1439, Address: 0x2120c8, Func Offset: 0x108
	// Line 1440, Address: 0x2120d0, Func Offset: 0x110
	// Line 1441, Address: 0x2120d4, Func Offset: 0x114
	// Line 1442, Address: 0x2120dc, Func Offset: 0x11c
	// Line 1443, Address: 0x2120e8, Func Offset: 0x128
	// Line 1444, Address: 0x2120f0, Func Offset: 0x130
	// Line 1448, Address: 0x2120f8, Func Offset: 0x138
	// Line 1449, Address: 0x212114, Func Offset: 0x154
	// Line 1451, Address: 0x212118, Func Offset: 0x158
	// Line 1452, Address: 0x212120, Func Offset: 0x160
	// Line 1455, Address: 0x212124, Func Offset: 0x164
	// Line 1456, Address: 0x212130, Func Offset: 0x170
	// Line 1458, Address: 0x212138, Func Offset: 0x178
	// Line 1463, Address: 0x212154, Func Offset: 0x194
	// Line 1466, Address: 0x212168, Func Offset: 0x1a8
	// Line 1467, Address: 0x21217c, Func Offset: 0x1bc
	// Func End, Address: 0x212194, Func Offset: 0x1d4
}

// 
// Start address: 0x2121a0
static int bhEne29_AttackHitCheck(BH_PWORK* ewP, en29_freework* fwP)
{
	int ang;
	int i;
	static NJS_SPHERE spr;
	static const CLL_WORK E29Cll[6] = { { 18, 3.0f }, { 17, 3.0f }, { 15, 3.5f }, { 13, 4.0f }, { 11, 4.5f }, {  9, 4.5f } };
	// Line 1478, Address: 0x2121a0, Func Offset: 0
	// Line 1489, Address: 0x2121c8, Func Offset: 0x28
	// Line 1494, Address: 0x2121cc, Func Offset: 0x2c
	// Line 1502, Address: 0x2121dc, Func Offset: 0x3c
	// Line 1494, Address: 0x2121e0, Func Offset: 0x40
	// Line 1502, Address: 0x21220c, Func Offset: 0x6c
	// Line 1495, Address: 0x212210, Func Offset: 0x70
	// Line 1502, Address: 0x21221c, Func Offset: 0x7c
	// Line 1507, Address: 0x212244, Func Offset: 0xa4
	// Line 1508, Address: 0x21225c, Func Offset: 0xbc
	// Line 1510, Address: 0x212260, Func Offset: 0xc0
	// Line 1512, Address: 0x212274, Func Offset: 0xd4
	// Line 1510, Address: 0x212278, Func Offset: 0xd8
	// Line 1512, Address: 0x212280, Func Offset: 0xe0
	// Line 1515, Address: 0x212294, Func Offset: 0xf4
	// Line 1512, Address: 0x212298, Func Offset: 0xf8
	// Line 1515, Address: 0x2122a0, Func Offset: 0x100
	// Line 1518, Address: 0x2122a8, Func Offset: 0x108
	// Line 1520, Address: 0x2122b8, Func Offset: 0x118
	// Line 1522, Address: 0x2122bc, Func Offset: 0x11c
	// Func End, Address: 0x2122d8, Func Offset: 0x138
}

// 100% matching!
static int bhEne29_PlySetDamage(BH_PWORK* plP, en29_freework* fwP, int dmg_mde)
{
	static const int PlyDmgTbl[4] = { 5, 5, 5, 5 };
    int dir_mde;

    if (dmg_mde > 3) 
    {
        dmg_mde = 3;
    }
    
    if (!(plP->flg & 0x4)) 
    {
        plP->hp -= PlyDmgTbl[dmg_mde];
        
        if ((fwP->dir_dlt & 0x80000000))
        {
            dir_mde = ((fwP->status & 0x400)) ? 0 : (unsigned int)1;
        } 
        else
        {
            dir_mde = ((fwP->status & 0x400)) ? (unsigned int)1 : 0;
        }
        
        if (plP->hp > 0) 
        {
            if (dmg_mde < 3) 
            {
                plP->flg |=  0x210004;
                plP->flg &= ~0x40000;
                
                plP->mode0 = 2;
                plP->mode1 = dir_mde;
                plP->mode2 = dmg_mde;
                plP->mode3 = 0;
                
                fwP->p_status = 1;
                
                fwP->p_br_mde0 = 2;
                fwP->p_br_mde1 = 0;
            }
            else
            {
                CallPlayerVoice(1027);
                
                plP->flg |=  0x210004;
                plP->flg &= ~0x40000;
                
                plP->mode0 = 5;
                plP->mode1 = 0;
                plP->mode2 = 0;
                plP->mode3 = 0;
                
                fwP->ply_act.p_act_flg = 0;
                
                fwP->p_status = 1;
                
                fwP->p_br_mde0 = dir_mde;
                fwP->p_br_mde1 = 0;
                
                return 1;
            }
        }
    }
    
    return 0;
}

// 99.35% matching
static void bhEne29_PlyMoveMain(BH_PWORK* plP, en29_freework* fwP)
{
    int* stsP;
    int* br0P, *br1P;
    int act;  
    int lop;   

    stsP = &fwP->p_status;
    
    if ((*stsP & 0x1))
    {
        br0P = &fwP->p_br_mde0;
        br1P = &fwP->p_br_mde1;
        
        act = TC_ACT_ALL;
        
        lop = 0;
        
        do 
        {
            switch (*br0P) 
            {                     
            case TC_BR0_NORMAL:
                act = (*br1P != TC_BR1_FIRST) ? act : TC_ACT_000;
                break;
            case TC_BR0_ATTACK:
                act = (*br1P != TC_BR1_FIRST) ? act : TC_ACT_001;
                break;
            case TC_BR0_DAMAGE:
                plP->px += fwP->ply_dmg.x;
                plP->pz += fwP->ply_dmg.z;
                
                fwP->ply_dmg.x *= 0.8f;
                fwP->ply_dmg.z *= 0.8f;
                
                if (fabsf(fwP->ply_dmg.x + fwP->ply_dmg.z) < 0.01f)
                {
                    *stsP &= ~0x1;
                }
                
                break;
            }
        } while (lop-- != 0);
        
        if (act != TC_ACT_ALL) 
        {
            bhEne29_PlyActionChange(plP, &fwP->ply_act, act);
        }
        
        bhEne29_PlyActionMain(plP, &fwP->ply_act);
    }
}

// 100% matching!
static void bhEne29_PlyActionInit(BH_PWORK* ewP, PAW_WORK* pawP, ACT_TBL_WORK* act_tblP, int tbl_num)
{
	pawP->act_tblP = act_tblP;
    
    pawP->tbl_num = tbl_num;
    
    pawP->p_act_now = -1;
    
    pawP->ene_mnwP = ewP->mnwP;
    pawP->p_paramP = ewP->exp0;
}

// 100% matching!
static void bhEne29_PlyActionMain(BH_PWORK* plP, PAW_WORK* pawP)
{
	if ((pawP->p_act_flg & 0x7) == 2)
    {
        pawP->p_act_flg &= ~0x2;
        
        bhEne29_PlyActionChange(plP, pawP, pawP->p_act_jmp);
    }
    
    pawP->p_mtn_rte = plP->frm_no / (pawP->p_frm_num - 1);
    
    if (pawP->p_prgP != NULL) 
    {
        pawP->p_prgP(plP, pawP->p_paramP);
    }
    
    pawP->p_act_frm = plP->frm_no / 65536;
    
    if (pawP->p_act_frm == pawP->p_chg_frm) 
    {
        pawP->p_act_flg &= ~0x1;
    }
}

// 100% matching!
static int bhEne29_PlyActionChange(BH_PWORK* plP, PAW_WORK* pawP, int act_no)
{
	ACT_TBL_WORK* paP;
    
    paP = &pawP->act_tblP[act_no];
    
    if ((!(pawP->p_act_flg & 0x7)) && (pawP->p_act_now != act_no))
    {
        pawP->p_prgP = paP->prgP;
        
        pawP->p_act_now = act_no;
        pawP->p_act_flg = 1;
        
        if (act_no >= 0)
        {
            plP->mnwP = pawP->ene_mnwP;
            
            plP->mtn_no = paP->mtn_no;
            plP->frm_no = paP->frm_no * 65536;
            
            plP->hokan_count = paP->hkn_cnt;
            plP->hokan_rate  = paP->hkn_lvl * (65536.0 / 255.0);
            
            plP->mtn_add = 65536;
            plP->mtn_md  = (unsigned short)paP->flag;
                
            pawP->p_frm_num = plP->mnwP[paP->mtn_no].frm_num;
            
            pawP->p_act_frm = paP->frm_no;
            pawP->p_act_jmp = paP->act_jmp;
            
            if (pawP->p_act_jmp != -1)
            {
                pawP->p_act_flg |= 0x2;
            }
            
            if (paP->chg_frm != 0xFF) 
            {
                pawP->p_chg_frm = paP->chg_frm;
            } 
            else 
            {
                pawP->p_chg_frm = pawP->p_frm_num - 1;
            }
        }
        
        return 1;
    }
    
    return 0;
}

// 100% matching!
static void bhEne29_PlyDmg117(BH_PWORK* plP, en29_freework* fwP)
{
	int dlt;
	
    plP->px += fwP->ply_dmg.x;
    plP->pz += fwP->ply_dmg.z;

    fwP->ply_dmg.x *= 0.9f;
    fwP->ply_dmg.z *= 0.9f;

    if (fwP->ply_act.p_mtn_rte <= 49152) 
    {
		dlt = fwP->dmg_dir - plP->ay;

        if (njCos(dlt) < 0)
        {
            dlt += 32768;
        }

        plP->ay += (short)dlt / 32;
    }

    if (fwP->ply_act.p_mtn_rte >= 65536)
    {
        bhEne29_PlyDmgRtn(plP, fwP);
    }
}

// 100% matching!
static void bhEne29_PlyDmg118(BH_PWORK* plP, en29_freework* fwP)
{
	bhEne29_PlyDmg117(plP, fwP);
}

// 100% matching!
static void bhEne29_PlyDmgRtn(BH_PWORK* plP, en29_freework* fwP)
{
	plP->mnwP = plP->mnwPb;
	
	plP->flg   &= ~0x10004;
	plP->stflg &= ~0x10000; 
	
	plP->mode0 = 1;
	plP->mode1 = 0;
	plP->mode2 = 0;
	plP->mode3 = 0;
	
	fwP->p_status &= ~0x1;
}

// 99.98% matching
static void bhEne29_SetDmgEffect(BH_PWORK* ewP, int eff_typ)
{
    int* effP;       
    float px, py, pz; // not from DWARF

    effP = E29EffTbl[eff_typ];
    
    switch (effP[0]) 
    {                            
    case 0:
    {
        NJS_POINT3 dir;  
        
        dir.x = -ewP->dvx;
        dir.y = -ewP->dvy;
        dir.z = -ewP->dvz;
        
        rySetEffBlood2(&ewP->mlwP->owP[ewP->djnt_no].mtx, (NJS_POINT3*)&ewP->dpx, &dir, effP[1]);
        break;
    }
    case 1:
    {
        NJS_POINT3 dir; 
        
        dir.x = -ewP->dvx;
        dir.y = -ewP->dvy;
        dir.z = -ewP->dvz;
        
        rySetEffBlood(&ewP->mlwP->owP[ewP->djnt_no].mtx, (NJS_POINT3*)&ewP->dpx, &dir, effP[1]);
        break;
    }
    case 2:
    {
        NJS_VECTOR vct;   
        int i;          
        NJS_POINT3 dir;
        int djnt_no;    
        NJS_POINT3 off;

        vct = *(NJS_POINT3*)&ewP->dvx;
        
        njUnitVector(&vct);
        
        sys->ef.flg = 1;
        
        sys->ef.id = effP[3];
        
        sys->ef.ax = 10430.381f * asinf(vct.y);
        sys->ef.ay = 10430.381f * atan2f(-vct.x, -vct.z);
        
        sys->ef.sx = sys->ef.sy = sys->ef.sz = 1.0f;
        
        sys->ef.mdlver = effP[1];
        
        sys->ef.type = 0;
        
        *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&ewP->mlwP->owP[ewP->djnt_no].mtx[12];
        
        djnt_no = ewP->djnt_no;
        
        dir.x = -ewP->dvx;
        dir.y = -ewP->dvy;
        dir.z = -ewP->dvz;
        
        njUnitVector(&dir);
        
        for (i = effP[2]; i > 0; i--) 
        {
            if (djnt_no != 1) 
            {
                off.x = 3.0f * ((-rand() / -2.1474836E9f) - 0.5f);
                off.y = 3.0f * ((-rand() / -2.1474836E9f) - 0.5f);
                off.z = 3.0f *  (-rand() / -2.1474836E9f);
                
                bhSetEffectTb(&sys->ef, &off, (unsigned char*)ewP, djnt_no - 1);
            }
            
            off.x = 3.0f * ((-rand() / -2.1474836E9f) - 0.5f);
            off.y = 3.0f * ((-rand() / -2.1474836E9f) - 0.5f);
            off.z = 2.0f *  (-rand() / -2.1474836E9f);
            
            bhSetEffectTb(&sys->ef, &off, (unsigned char*)ewP, djnt_no);
            
            off.x = 3.0f *        ((-rand() / -2.1474836E9f) - 0.5f);
            off.y = 3.0f *        ((-rand() / -2.1474836E9f) - 0.5f);
            off.z = 1.0f + (2.0f * (-rand() / -2.1474836E9f));
            
            bhSetEffectTb(&sys->ef, &off, (unsigned char*)ewP, djnt_no);
            
            if (djnt_no != 19)
            {
                off.x = 3.0f * ((-rand() / -2.1474836E9f) - 0.5f);
                off.y = 3.0f * ((-rand() / -2.1474836E9f) - 0.5f);
                off.z = 3.0f *  (-rand() / -2.1474836E9f);
                
                bhSetEffectTb(&sys->ef, &off, (unsigned char*)ewP, djnt_no + 1);
            }
        }  
        
        break;
    }
    case 3:
    {  
        NJS_MATRIX* mtxP; 
        int i;      
    
        mtxP = (NJS_MATRIX*)&ewP->mlwP->owP[ewP->djnt_no].mtx[8];
        
        px = -(*mtxP)[0];
        py = -(*mtxP)[1];      
        pz = -(*mtxP)[2]; 
        
        sys->ef.flg = 1;
        
        sys->ef.id = effP[3];
        
        sys->ef.ax = 10430.381f * asinf(py);
        sys->ef.ay = 10430.381f * atan2f(-px, -pz);
        
        sys->ef.mdlver = effP[1];
        
        sys->ef.sx = sys->ef.sy = sys->ef.sz = 1.0f;
        
        sys->ef.type = 6;
        
        *(NJS_POINT3*)&sys->ef.px = *(NJS_POINT3*)&ewP->dpx;
        
        for (i = effP[2]; i > 0; i--)
        {
            bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        } 
        
        break;
    }
    case 4:
    {
        NJS_POINT3 off; 
        int djnt_no;  
        float scl;      
        
        djnt_no = ewP->djnt_no;
        
        scl = 0.000015258789f * effP[1];
        
        njSetMatrix(lcmat, &ewP->mlwP->owP[djnt_no].mtx);
        
        njInvertMatrix(lcmat);
        
        njCalcPoint(lcmat, (NJS_POINT3*)&ewP->dpx, &off);
        
        sys->ef.flg = 1;
        
        sys->ef.id = effP[3];
        
        sys->ef.ax = sys->ef.ay = 0;
        
        sys->ef.mdlver = 0;
        
        sys->ef.sx = sys->ef.sy = sys->ef.sz = scl;
        
        sys->ef.type = effP[2];
        
        sys->ef.px = sys->ef.py = sys->ef.pz = 0;
        
        bhSetEffectTb(&sys->ef, &off, (unsigned char*)ewP, djnt_no);
        break;
    }
    }
}

// 100% matching!
static void SetDmgEne(BH_PWORK* ewP, en29_freework* fwP, DS_WORK* dsP, int set_num) // first parameter not present on DWARF
{
    e19_dmg_typ* hedP, *edP; 

    edP = fwP->DmgWrk;
    
    fwP->dmg_eneP = edP;
    
    hedP = edP++;
    
    fwP->DmgWrk->nextP = fwP->DmgWrk;   
    
    for (; set_num > 0; set_num--, dsP++, edP++)
    {
        BH_PWORK* ewP;

        ewP = bhSetEnemy((ETTY_WORK*)&En29DmgDat, 0);
        
        ewP->flg2 |= dsP->or_flg2;
        
        edP->atr_top = dsP->atr_top;
        edP->atr_end = dsP->atr_end;
        edP->atr_rad = dsP->atr_rad;
        
        edP->ewP = ewP;
        
        edP->nextP  = hedP->nextP;
        hedP->nextP = edP;
    }
}

// 100% matching!
static void CalcDmgEne(BH_PWORK* ewP, en29_freework* fwP)
{
	O_WORK* owP;      
	e19_dmg_typ* hedP, *edP; 
	BH_PWORK* enP;    
	
    hedP = fwP->dmg_eneP;

    owP = ewP->mlwP->owP;

	for (edP = hedP->nextP; edP != hedP; edP = edP->nextP)
	{
		enP = edP->ewP;

		enP->watr.r = edP->atr_rad;

		enP->watr.c1 = *(NJS_POINT3*)&owP[edP->atr_top].mtx[12];
		enP->watr.c2 = *(NJS_POINT3*)&owP[edP->atr_end].mtx[12];

		enP->cpcl = ewP->cpcl;
		
		enP->mlwP = ewP->mlwP;
	} 
}

// 100% matching!
static void CheckDmgEne(BH_PWORK* ewP, en29_freework* fwP)
{
    BH_PWORK* dmgP;    
    e19_dmg_typ* hedP, *edP; 
    BH_PWORK* enP;    
    float d;          
    int* srcP, *dstP;        
    int num;          

    hedP = fwP->dmg_eneP;
    dmgP = NULL;
    
    for (edP = hedP->nextP; edP != hedP; edP = edP->nextP) 
    {
        enP = edP->ewP;
        
        if ((enP->flg & 0x4)) 
        {
            enP->flg &= ~0x4;
            
            d = 10000.0f;
            
            if (d > njDistanceP2P((NJS_POINT3*)&plp->px, (NJS_POINT3*)&enP->dpx)) 
            {
                dmgP = enP;
            }
        }
    }
    
    if (dmgP != NULL) 
    {
        if (!(ewP->flg & 0x4)) 
        {
            ewP->flg |= 0x4;
            
            num = 64;
            
            srcP = dmgP->dam;
            dstP = ewP->dam;
            
            ewP->djnt_no = dmgP->djnt_no;
            
            for (; num > 0; num--) 
            {
                *dstP++ = *srcP++;
            } 
            
            ewP->dpx = dmgP->dpx;
            ewP->dpy = dmgP->dpy;
            ewP->dpz = dmgP->dpz;
            
            ewP->dvx = dmgP->dvx;
            ewP->dvy = dmgP->dvy;
            ewP->dvz = dmgP->dvz;
            
            ewP->dax = dmgP->dax;
            ewP->day = dmgP->day;
            
            ewP->wpnr_no = dmgP->wpnr_no;
            
            ewP->comb_flg |= dmgP->comb_flg & 0x70;
        }
    }
}
