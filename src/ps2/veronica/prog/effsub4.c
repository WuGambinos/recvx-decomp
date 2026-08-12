#include "../../../ps2/veronica/prog/effsub4.h"
#include "../../../ps2/veronica/prog/en01.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw.h"
#include "../../../ps2/veronica/prog/ps2_NaFog.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaSystem.h"
#include "../../../ps2/veronica/prog/ps2_NaTextureFunction.h"
#include "../../../ps2/veronica/prog/ps2_NinjaCnk.h"
#include "../../../ps2/veronica/prog/ps2_NinjaPtcl.h"

// 100% matching!
void bhEff_SetPtcl(BH_PWORK* epw, NJS_POINT3* pos, int tex_id)
{
    int i;
    int time; 

    time = (rand() % 4) * 4; 

    for (i = 0; i < 3; i++) 
    {
        bhEff_SetPtcl1(epw, pos, tex_id, time);
        
        time += 4;
    }
}

// 100% matching!
void bhEff_SetPtcl1(BH_PWORK* epw, NJS_POINT3* pos, int tex_id, int wcnt)
{
    EFFSUB365_WORK* effect; 
    O_WRK* op;             
    POINT ps;               
    int eff_no;           
    NJS_POINT3* vpos;
	NJS_VECTOR* avec;      
    float* size;           
	static float eff_tbl[2] = 
	{
		0.200000003f, 1.5f
	};

    ps.px = pos->x;
    ps.py = pos->y;
    ps.pz = pos->z;
    
    ps.ox = 0;
    ps.oy = 0;
    ps.oz = 0;
    
    if ((eff_no = bhSetEffect(365, &ps, NULL, 0)) != -1) 
    {
        NJS_POINT3 ps; 
        int i;         
        
        effect = (EFFSUB365_WORK*)bhEff_AllocOwork();
        
        op = &eff[eff_no];
        
        vpos = effect->vtx_pos;
        
        op->txp[0] = epw->mlwP->texP;
        op->tex_id = tex_id;
        
        op->exp0 = (unsigned char*)effect;
        
        op->func = (void*)bhEff_PtclSpriteDraw;
        
        op->ct3 = wcnt;
        
        effect->dtbl.num = 40;
        
        size = effect->size;
        
        effect->dtbl.exp0 = (unsigned char*)vpos;
        
        avec = effect->add_vec;
        
        effect->dtbl.exp1 = (unsigned char*)size;
        
        njUnitMatrix(NULL);
        
        njRotateY(NULL, epw->ay);
        
        for (i = 0; i < 40; i++) 
        {
            vpos->x = pos->x + (-0.5f + (-rand() / -2.1474836E9f));
            vpos->y = pos->y;
            vpos->z = pos->z + (-0.5f + (-rand() / -2.1474836E9f));
            
            ps.x = 0;
            ps.y = -(eff_tbl[0] + (eff_tbl[1] * (-rand() / -2.1474836E9f)));
            ps.z = 0;
            
            size[i] = -0.15f * ps.y;
            
            if (size[i] < 0.1f)
            {
                size[i] = 0.1f;
            }
            
            njCalcPoint(NULL, &ps, avec);
            
            vpos++;
            avec++;
        }
    }
}

// 
// Start address: 0x24cb70
void bhEff_SetPtcl2(NJS_POINT3* pos, NJS_MATRIX* mtx)
{
	float spd;
	int ang2;
	int ang;
	NJS_POINT3* vec;
	NJS_POINT3* vtx_p2;
	NJS_POINT3* vtx_p;
	int i;
	int eff_no;
	EFFSUB366_WORK* effect;
	O_WRK* op;
	POINT ps;
	static float eff_tbl[2] = 
	{
		1.0f, 2.0f
	};
	// Line 232, Address: 0x24cb70, Func Offset: 0
	// Line 241, Address: 0x24cb9c, Func Offset: 0x2c
	// Line 247, Address: 0x24cba8, Func Offset: 0x38
	// Line 241, Address: 0x24cbb0, Func Offset: 0x40
	// Line 242, Address: 0x24cbb4, Func Offset: 0x44
	// Line 247, Address: 0x24cbb8, Func Offset: 0x48
	// Line 242, Address: 0x24cbbc, Func Offset: 0x4c
	// Line 243, Address: 0x24cbc0, Func Offset: 0x50
	// Line 244, Address: 0x24cbc8, Func Offset: 0x58
	// Line 245, Address: 0x24cbcc, Func Offset: 0x5c
	// Line 247, Address: 0x24cbd0, Func Offset: 0x60
	// Line 253, Address: 0x24cbe8, Func Offset: 0x78
	// Line 255, Address: 0x24cbf0, Func Offset: 0x80
	// Line 258, Address: 0x24cc10, Func Offset: 0xa0
	// Line 257, Address: 0x24cc18, Func Offset: 0xa8
	// Line 258, Address: 0x24cc1c, Func Offset: 0xac
	// Line 280, Address: 0x24cc20, Func Offset: 0xb0
	// Line 259, Address: 0x24cc24, Func Offset: 0xb4
	// Line 260, Address: 0x24cc28, Func Offset: 0xb8
	// Line 272, Address: 0x24cc2c, Func Offset: 0xbc
	// Line 273, Address: 0x24cc30, Func Offset: 0xc0
	// Line 272, Address: 0x24cc34, Func Offset: 0xc4
	// Line 274, Address: 0x24cc38, Func Offset: 0xc8
	// Line 273, Address: 0x24cc3c, Func Offset: 0xcc
	// Line 278, Address: 0x24cc40, Func Offset: 0xd0
	// Line 274, Address: 0x24cc44, Func Offset: 0xd4
	// Line 280, Address: 0x24cc48, Func Offset: 0xd8
	// Line 281, Address: 0x24cc50, Func Offset: 0xe0
	// Line 282, Address: 0x24cc58, Func Offset: 0xe8
	// Line 284, Address: 0x24cc64, Func Offset: 0xf4
	// Line 286, Address: 0x24cc68, Func Offset: 0xf8
	// Line 287, Address: 0x24cc74, Func Offset: 0x104
	// Line 288, Address: 0x24cc80, Func Offset: 0x110
	// Line 290, Address: 0x24cc88, Func Offset: 0x118
	// Line 291, Address: 0x24cca8, Func Offset: 0x138
	// Line 292, Address: 0x24ccc4, Func Offset: 0x154
	// Line 294, Address: 0x24cce4, Func Offset: 0x174
	// Line 292, Address: 0x24cce8, Func Offset: 0x178
	// Line 294, Address: 0x24cd04, Func Offset: 0x194
	// Line 295, Address: 0x24cd1c, Func Offset: 0x1ac
	// Line 294, Address: 0x24cd20, Func Offset: 0x1b0
	// Line 295, Address: 0x24cd24, Func Offset: 0x1b4
	// Line 296, Address: 0x24cd30, Func Offset: 0x1c0
	// Line 298, Address: 0x24cd4c, Func Offset: 0x1dc
	// Line 296, Address: 0x24cd58, Func Offset: 0x1e8
	// Line 298, Address: 0x24cd5c, Func Offset: 0x1ec
	// Line 303, Address: 0x24cd64, Func Offset: 0x1f4
	// Line 300, Address: 0x24cd6c, Func Offset: 0x1fc
	// Line 301, Address: 0x24cd70, Func Offset: 0x200
	// Line 303, Address: 0x24cd74, Func Offset: 0x204
	// Line 305, Address: 0x24cd7c, Func Offset: 0x20c
	// Func End, Address: 0x24cdac, Func Offset: 0x23c
	scePrintf("bhEff_SetPtcl2 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24cdb0
void bhEff_SetPtcl2V(NJS_POINT3* pos, NJS_POINT3* dv, int wcnt)
{
	float spd;
	int ang2;
	int ang1;
	NJS_POINT3* vec;
	NJS_POINT3* vtx_p2;
	NJS_POINT3* vtx_p;
	int i;
	int eff_no;
	EFFSUB366_WORK* effect;
	O_WRK* op;
	POINT ps;
	static float eff_tbl[2] = 
	{
		1.0f, 2.0f
	};
	// Line 328, Address: 0x24cdb0, Func Offset: 0
	// Line 337, Address: 0x24cddc, Func Offset: 0x2c
	// Line 343, Address: 0x24cdec, Func Offset: 0x3c
	// Line 337, Address: 0x24cdf0, Func Offset: 0x40
	// Line 338, Address: 0x24cdf4, Func Offset: 0x44
	// Line 343, Address: 0x24cdf8, Func Offset: 0x48
	// Line 338, Address: 0x24ce00, Func Offset: 0x50
	// Line 339, Address: 0x24ce04, Func Offset: 0x54
	// Line 340, Address: 0x24ce0c, Func Offset: 0x5c
	// Line 341, Address: 0x24ce10, Func Offset: 0x60
	// Line 343, Address: 0x24ce14, Func Offset: 0x64
	// Line 349, Address: 0x24ce2c, Func Offset: 0x7c
	// Line 351, Address: 0x24ce34, Func Offset: 0x84
	// Line 354, Address: 0x24ce54, Func Offset: 0xa4
	// Line 353, Address: 0x24ce5c, Func Offset: 0xac
	// Line 354, Address: 0x24ce60, Func Offset: 0xb0
	// Line 355, Address: 0x24ce64, Func Offset: 0xb4
	// Line 356, Address: 0x24ce68, Func Offset: 0xb8
	// Line 368, Address: 0x24ce70, Func Offset: 0xc0
	// Line 369, Address: 0x24ce74, Func Offset: 0xc4
	// Line 368, Address: 0x24ce78, Func Offset: 0xc8
	// Line 370, Address: 0x24ce7c, Func Offset: 0xcc
	// Line 369, Address: 0x24ce80, Func Offset: 0xd0
	// Line 374, Address: 0x24ce84, Func Offset: 0xd4
	// Line 370, Address: 0x24ce88, Func Offset: 0xd8
	// Line 376, Address: 0x24ce8c, Func Offset: 0xdc
	// Line 378, Address: 0x24ce90, Func Offset: 0xe0
	// Line 379, Address: 0x24ce9c, Func Offset: 0xec
	// Line 380, Address: 0x24cea8, Func Offset: 0xf8
	// Line 382, Address: 0x24ceb0, Func Offset: 0x100
	// Line 383, Address: 0x24cecc, Func Offset: 0x11c
	// Line 384, Address: 0x24cee8, Func Offset: 0x138
	// Line 386, Address: 0x24cf08, Func Offset: 0x158
	// Line 384, Address: 0x24cf0c, Func Offset: 0x15c
	// Line 386, Address: 0x24cf28, Func Offset: 0x178
	// Line 387, Address: 0x24cf30, Func Offset: 0x180
	// Line 388, Address: 0x24cf38, Func Offset: 0x188
	// Line 389, Address: 0x24cf4c, Func Offset: 0x19c
	// Line 391, Address: 0x24cf5c, Func Offset: 0x1ac
	// Line 398, Address: 0x24cf60, Func Offset: 0x1b0
	// Line 396, Address: 0x24cf68, Func Offset: 0x1b8
	// Line 391, Address: 0x24cf6c, Func Offset: 0x1bc
	// Line 397, Address: 0x24cf70, Func Offset: 0x1c0
	// Line 391, Address: 0x24cf74, Func Offset: 0x1c4
	// Line 392, Address: 0x24cf78, Func Offset: 0x1c8
	// Line 393, Address: 0x24cf84, Func Offset: 0x1d4
	// Line 398, Address: 0x24cf90, Func Offset: 0x1e0
	// Line 400, Address: 0x24cf98, Func Offset: 0x1e8
	// Func End, Address: 0x24cfc8, Func Offset: 0x218
	scePrintf("bhEff_SetPtcl2V - UNIMPLEMENTED!\n");
}

// 100% matching!
static void bhEff_SetBlood5(NJS_POINT3* pos, NJS_VECTOR* vec, float size, int col)
{
    int tmp;

    sys->ef.id = 372;
    
    sys->ef.flg = 1;
    
    sys->ef.sx = size;
    sys->ef.sy = size;
    sys->ef.sz = 0;
    
    sys->ef.px = pos->x;
    sys->ef.py = pos->y;
    sys->ef.pz = pos->z;
    
    sys->ef.ay = 0;
    
    sys->ef.type = 0;
    
    sys->ef.mdlver = col;
    
    tmp = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    
    if (tmp != -1) 
    {
        eff[tmp].ct3 = 0;
        
        eff[tmp].xn = -vec->x;
        eff[tmp].yn = 0;
        eff[tmp].zn = -vec->z;
        
        eff[tmp].shp_ct = 0.5f;
        
        eff[tmp].aox = 0.98f;
        eff[tmp].aoy = -0.03f;
    }
}

// 
// Start address: 0x24d1c0
void bhEff_Sub350(O_WRK* op)
{
	int i;
	int tmp;
	float wk1;
	float wk0;
	NJS_POINT3 p2;
	NJS_POINT3 p1;
	static UV_WORK uvinfo[11] = 
	{
		{   0.0f,  96.0f,  16.0f,  16.0f },
		{   0.0f, 112.0f,  16.0f,  16.0f },
		{   0.0f, 128.0f,  16.0f,  16.0f },
		{   0.0f, 144.0f,  16.0f,  16.0f },
		{  16.0f,  96.0f,  24.0f,  24.0f },
		{  16.0f, 120.0f,  24.0f,  24.0f },
		{  40.0f,  96.0f,  32.0f,  32.0f },
		{  72.0f,  96.0f,  32.0f,  32.0f },
		{ 104.0f,  96.0f,  32.0f,  32.0f },
		{  40.0f, 128.0f,  32.0f,  32.0f },
		{  72.0f, 128.0f,  32.0f,  32.0f }
	};
	static EFF_ANIM anim00_tbl[9] = 
	{
		{  0,  1 },
		{  1,  1 },
		{  2,  1 },
		{  3,  1 },
		{  4,  1 },
		{  5,  1 },
		{  6,  1 },
		{  7,  1 },
		{ -2,  6 }   
	};
	static EFF_ANIM anim01_tbl[4] = 
	{
		{  8,  1 },
		{  9,  1 },
		{ 10,  1 },
		{ -1,  0 }   
	};
	static EFF_ANIM* anim_tbl[2] = 
	{
		anim00_tbl, anim01_tbl
	};
	// Line 559, Address: 0x24d1c0, Func Offset: 0
	// Line 596, Address: 0x24d1e4, Func Offset: 0x24
	// Line 599, Address: 0x24d21c, Func Offset: 0x5c
	// Line 600, Address: 0x24d228, Func Offset: 0x68
	// Line 603, Address: 0x24d22c, Func Offset: 0x6c
	// Line 606, Address: 0x24d230, Func Offset: 0x70
	// Line 611, Address: 0x24d234, Func Offset: 0x74
	// Line 616, Address: 0x24d238, Func Offset: 0x78
	// Line 600, Address: 0x24d23c, Func Offset: 0x7c
	// Line 603, Address: 0x24d248, Func Offset: 0x88
	// Line 604, Address: 0x24d24c, Func Offset: 0x8c
	// Line 606, Address: 0x24d250, Func Offset: 0x90
	// Line 607, Address: 0x24d25c, Func Offset: 0x9c
	// Line 608, Address: 0x24d268, Func Offset: 0xa8
	// Line 609, Address: 0x24d26c, Func Offset: 0xac
	// Line 610, Address: 0x24d270, Func Offset: 0xb0
	// Line 611, Address: 0x24d274, Func Offset: 0xb4
	// Line 613, Address: 0x24d278, Func Offset: 0xb8
	// Line 616, Address: 0x24d27c, Func Offset: 0xbc
	// Line 617, Address: 0x24d290, Func Offset: 0xd0
	// Line 619, Address: 0x24d2a8, Func Offset: 0xe8
	// Line 620, Address: 0x24d2c0, Func Offset: 0x100
	// Line 621, Address: 0x24d2d4, Func Offset: 0x114
	// Line 622, Address: 0x24d2d8, Func Offset: 0x118
	// Line 625, Address: 0x24d2e4, Func Offset: 0x124
	// Line 626, Address: 0x24d2f0, Func Offset: 0x130
	// Line 628, Address: 0x24d2fc, Func Offset: 0x13c
	// Line 629, Address: 0x24d304, Func Offset: 0x144
	// Line 637, Address: 0x24d310, Func Offset: 0x150
	// Line 638, Address: 0x24d318, Func Offset: 0x158
	// Line 649, Address: 0x24d324, Func Offset: 0x164
	// Line 646, Address: 0x24d328, Func Offset: 0x168
	// Line 637, Address: 0x24d32c, Func Offset: 0x16c
	// Line 649, Address: 0x24d330, Func Offset: 0x170
	// Line 648, Address: 0x24d334, Func Offset: 0x174
	// Line 637, Address: 0x24d338, Func Offset: 0x178
	// Line 638, Address: 0x24d33c, Func Offset: 0x17c
	// Line 646, Address: 0x24d348, Func Offset: 0x188
	// Line 638, Address: 0x24d34c, Func Offset: 0x18c
	// Line 639, Address: 0x24d360, Func Offset: 0x1a0
	// Line 640, Address: 0x24d370, Func Offset: 0x1b0
	// Line 643, Address: 0x24d37c, Func Offset: 0x1bc
	// Line 644, Address: 0x24d384, Func Offset: 0x1c4
	// Line 645, Address: 0x24d38c, Func Offset: 0x1cc
	// Line 646, Address: 0x24d394, Func Offset: 0x1d4
	// Line 649, Address: 0x24d3a0, Func Offset: 0x1e0
	// Line 652, Address: 0x24d3b4, Func Offset: 0x1f4
	// Line 655, Address: 0x24d3e0, Func Offset: 0x220
	// Line 656, Address: 0x24d3e8, Func Offset: 0x228
	// Line 657, Address: 0x24d3f4, Func Offset: 0x234
	// Line 656, Address: 0x24d3f8, Func Offset: 0x238
	// Line 657, Address: 0x24d3fc, Func Offset: 0x23c
	// Line 658, Address: 0x24d408, Func Offset: 0x248
	// Line 659, Address: 0x24d414, Func Offset: 0x254
	// Line 661, Address: 0x24d420, Func Offset: 0x260
	// Line 659, Address: 0x24d424, Func Offset: 0x264
	// Line 661, Address: 0x24d42c, Func Offset: 0x26c
	// Line 662, Address: 0x24d440, Func Offset: 0x280
	// Line 663, Address: 0x24d444, Func Offset: 0x284
	// Line 665, Address: 0x24d454, Func Offset: 0x294
	// Line 667, Address: 0x24d468, Func Offset: 0x2a8
	// Line 668, Address: 0x24d474, Func Offset: 0x2b4
	// Line 671, Address: 0x24d47c, Func Offset: 0x2bc
	// Line 674, Address: 0x24d488, Func Offset: 0x2c8
	// Line 675, Address: 0x24d48c, Func Offset: 0x2cc
	// Line 680, Address: 0x24d494, Func Offset: 0x2d4
	// Line 682, Address: 0x24d4a4, Func Offset: 0x2e4
	// Line 683, Address: 0x24d4ac, Func Offset: 0x2ec
	// Line 684, Address: 0x24d4b0, Func Offset: 0x2f0
	// Line 685, Address: 0x24d4b4, Func Offset: 0x2f4
	// Line 686, Address: 0x24d4bc, Func Offset: 0x2fc
	// Line 690, Address: 0x24d4c4, Func Offset: 0x304
	// Line 691, Address: 0x24d4c8, Func Offset: 0x308
	// Line 695, Address: 0x24d4d0, Func Offset: 0x310
	// Line 696, Address: 0x24d4d4, Func Offset: 0x314
	// Line 690, Address: 0x24d4d8, Func Offset: 0x318
	// Line 691, Address: 0x24d4dc, Func Offset: 0x31c
	// Line 697, Address: 0x24d4e0, Func Offset: 0x320
	// Line 691, Address: 0x24d4ec, Func Offset: 0x32c
	// Line 697, Address: 0x24d4f0, Func Offset: 0x330
	// Line 691, Address: 0x24d4f4, Func Offset: 0x334
	// Line 692, Address: 0x24d4f8, Func Offset: 0x338
	// Line 694, Address: 0x24d500, Func Offset: 0x340
	// Line 695, Address: 0x24d508, Func Offset: 0x348
	// Line 696, Address: 0x24d514, Func Offset: 0x354
	// Line 697, Address: 0x24d518, Func Offset: 0x358
	// Line 699, Address: 0x24d528, Func Offset: 0x368
	// Line 700, Address: 0x24d52c, Func Offset: 0x36c
	// Line 702, Address: 0x24d534, Func Offset: 0x374
	// Line 699, Address: 0x24d538, Func Offset: 0x378
	// Line 700, Address: 0x24d53c, Func Offset: 0x37c
	// Line 701, Address: 0x24d548, Func Offset: 0x388
	// Line 706, Address: 0x24d550, Func Offset: 0x390
	// Line 710, Address: 0x24d558, Func Offset: 0x398
	// Line 711, Address: 0x24d564, Func Offset: 0x3a4
	// Line 712, Address: 0x24d568, Func Offset: 0x3a8
	// Line 710, Address: 0x24d56c, Func Offset: 0x3ac
	// Line 711, Address: 0x24d578, Func Offset: 0x3b8
	// Line 719, Address: 0x24d580, Func Offset: 0x3c0
	// Line 711, Address: 0x24d584, Func Offset: 0x3c4
	// Line 712, Address: 0x24d590, Func Offset: 0x3d0
	// Line 713, Address: 0x24d5a4, Func Offset: 0x3e4
	// Line 714, Address: 0x24d5b8, Func Offset: 0x3f8
	// Line 715, Address: 0x24d5cc, Func Offset: 0x40c
	// Line 719, Address: 0x24d5e0, Func Offset: 0x420
	// Line 721, Address: 0x24d5ec, Func Offset: 0x42c
	// Line 723, Address: 0x24d5f8, Func Offset: 0x438
	// Line 724, Address: 0x24d60c, Func Offset: 0x44c
	// Line 725, Address: 0x24d620, Func Offset: 0x460
	// Line 727, Address: 0x24d634, Func Offset: 0x474
	// Line 729, Address: 0x24d644, Func Offset: 0x484
	// Line 733, Address: 0x24d64c, Func Offset: 0x48c
	// Line 732, Address: 0x24d654, Func Offset: 0x494
	// Line 733, Address: 0x24d660, Func Offset: 0x4a0
	// Line 735, Address: 0x24d68c, Func Offset: 0x4cc
	// Line 736, Address: 0x24d6b8, Func Offset: 0x4f8
	// Line 737, Address: 0x24d6c0, Func Offset: 0x500
	// Line 739, Address: 0x24d6c8, Func Offset: 0x508
	// Line 740, Address: 0x24d710, Func Offset: 0x550
	// Line 741, Address: 0x24d764, Func Offset: 0x5a4
	// Line 743, Address: 0x24d7b0, Func Offset: 0x5f0
	// Line 744, Address: 0x24d7c0, Func Offset: 0x600
	// Line 747, Address: 0x24d7c8, Func Offset: 0x608
	// Line 752, Address: 0x24d7d4, Func Offset: 0x614
	// Line 747, Address: 0x24d7e0, Func Offset: 0x620
	// Line 748, Address: 0x24d7ec, Func Offset: 0x62c
	// Line 749, Address: 0x24d804, Func Offset: 0x644
	// Line 752, Address: 0x24d81c, Func Offset: 0x65c
	// Line 754, Address: 0x24d840, Func Offset: 0x680
	// Line 755, Address: 0x24d864, Func Offset: 0x6a4
	// Line 754, Address: 0x24d870, Func Offset: 0x6b0
	// Line 755, Address: 0x24d878, Func Offset: 0x6b8
	// Line 756, Address: 0x24d87c, Func Offset: 0x6bc
	// Line 755, Address: 0x24d888, Func Offset: 0x6c8
	// Line 756, Address: 0x24d88c, Func Offset: 0x6cc
	// Line 757, Address: 0x24d890, Func Offset: 0x6d0
	// Line 756, Address: 0x24d89c, Func Offset: 0x6dc
	// Line 758, Address: 0x24d8a0, Func Offset: 0x6e0
	// Line 759, Address: 0x24d8f4, Func Offset: 0x734
	// Line 760, Address: 0x24d954, Func Offset: 0x794
	// Line 764, Address: 0x24d9ac, Func Offset: 0x7ec
	// Line 765, Address: 0x24d9b4, Func Offset: 0x7f4
	// Line 766, Address: 0x24d9b8, Func Offset: 0x7f8
	// Line 767, Address: 0x24d9bc, Func Offset: 0x7fc
	// Line 777, Address: 0x24d9c8, Func Offset: 0x808
	// Line 779, Address: 0x24d9d4, Func Offset: 0x814
	// Line 781, Address: 0x24da00, Func Offset: 0x840
	// Func End, Address: 0x24da24, Func Offset: 0x864
	scePrintf("bhEff_Sub350 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEff_Sub351(O_WRK* op) 
{
    static UV_WORK uvinfo[14] =
	{
		{  24.0f,  80.0f,  16.0f,  16.0f },
		{   0.0f,  48.0f,  24.0f,  24.0f },
		{   0.0f,  72.0f,  24.0f,  24.0f },
		{  24.0f,  48.0f,  32.0f,  32.0f },
		{  56.0f,  48.0f,  32.0f,  32.0f },
		{  88.0f,  48.0f,  40.0f,  40.0f },
		{ 128.0f,  48.0f,  40.0f,  40.0f },
		{   0.0f,   0.0f,  48.0f,  48.0f },
		{  48.0f,   0.0f,  48.0f,  48.0f },
		{  96.0f,   0.0f,  48.0f,  48.0f },
		{ 144.0f,   0.0f,  48.0f,  48.0f },
		{ 192.0f,   0.0f,  48.0f,  48.0f },
		{ 168.0f,  48.0f,  40.0f,  40.0f },
		{ 208.0f,  48.0f,  40.0f,  40.0f }
	};
	static EFF_ANIM anim00_tbl[15] = 
	{
		{  0,  1 }, {  1,  1 }, {  2,  1 }, {  3,  1 },
		{  4,  1 }, {  5,  1 }, {  6,  1 }, {  7,  1 },
		{  8,  1 }, {  9,  1 }, { 10,  1 }, { 11,  1 },
		{ 12,  1 }, { 13,  1 }, { -1,  0 }
	}; 
    
    switch (op->mode0) 
    {                           
    case 0:
        op->tv[0].col = 0x80808080;
        op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col;
        
        op->bl_src = 8;
        op->bl_dst = 10;
        
        op->flg   |= 0x4180000;
        op->stflg |= 0x20;
        
        op->ani_ct = 0;
        
        op->ct0 = 0;
        op->ct1 = 0;
        op->ct2 = 0;
        
        op->spd = 1.0f;
        
        op->mode2 = 0;
        op->mode0++;
        break;
    case 1:
        op->ct3--;
        
        if (op->ct3 >= 0)
        {
            break;
        }
        
        op->ct3 = 0;
        
        op->mode2 = 1;
        
        if ((op->flg & 0x80)) 
        {
            op->flg &= ~0x80;
        }
        
        op->mode0++;
    case 2:
        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
        
        if (++op->ct3 > 8)
        {
            op->tv[0].col += 0xF0000000;
            op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col;
        }

		break;
    }
    
    if (op->mode2 != 0) 
    {
        bhEff_SetSpriteAnime(op, anim00_tbl, uvinfo, 0);
    }
}

// 
// Start address: 0x24dbc0
void bhEff_Sub352(O_WRK* op)
{
	O_WORK* owk;
	NJS_POINT3 p2;
	NJS_POINT3 p1;
	static UV_WORK uvinfo[10] = 
	{
		{   0.0f,   0.0f,  48.0f,  48.0f },
		{  48.0f,   0.0f,  48.0f,  48.0f },
		{  96.0f,   0.0f,  48.0f,  48.0f },
		{ 144.0f,   0.0f,  48.0f,  48.0f },
		{ 192.0f,   0.0f,  48.0f,  48.0f },
		{   0.0f,  48.0f,  48.0f,  48.0f },
		{  48.0f,  48.0f,  48.0f,  48.0f },
		{  96.0f,  48.0f,  48.0f,  48.0f },
		{ 144.0f,  48.0f,  48.0f,  48.0f },
		{ 192.0f,  48.0f,  48.0f,  48.0f }
	};
	static EFF_ANIM anim00_tbl[11] = 
	{
		{  0,  1 }, {  1,  1 }, {  2,  1 }, {  3,  1 },
		{  4,  1 }, {  5,  1 }, {  6,  1 }, {  7,  1 },
		{  8,  1 }, {  9,  1 }, { -2,  0 }    
	};
	static EFF_ANIM *anim_tbl[1] = 
	{
		anim00_tbl
	};
	// Line 898, Address: 0x24dbc0, Func Offset: 0
	// Line 926, Address: 0x24dbe0, Func Offset: 0x20
	// Line 929, Address: 0x24dbf8, Func Offset: 0x38
	// Line 932, Address: 0x24dc04, Func Offset: 0x44
	// Line 938, Address: 0x24dc1c, Func Offset: 0x5c
	// Line 942, Address: 0x24dc54, Func Offset: 0x94
	// Line 943, Address: 0x24dc58, Func Offset: 0x98
	// Line 942, Address: 0x24dc5c, Func Offset: 0x9c
	// Line 943, Address: 0x24dc60, Func Offset: 0xa0
	// Line 945, Address: 0x24dc64, Func Offset: 0xa4
	// Line 948, Address: 0x24dc6c, Func Offset: 0xac
	// Line 950, Address: 0x24dc70, Func Offset: 0xb0
	// Line 951, Address: 0x24dc74, Func Offset: 0xb4
	// Line 957, Address: 0x24dc78, Func Offset: 0xb8
	// Line 945, Address: 0x24dc7c, Func Offset: 0xbc
	// Line 946, Address: 0x24dc84, Func Offset: 0xc4
	// Line 947, Address: 0x24dc88, Func Offset: 0xc8
	// Line 948, Address: 0x24dc8c, Func Offset: 0xcc
	// Line 950, Address: 0x24dc90, Func Offset: 0xd0
	// Line 951, Address: 0x24dc94, Func Offset: 0xd4
	// Line 952, Address: 0x24dc98, Func Offset: 0xd8
	// Line 953, Address: 0x24dc9c, Func Offset: 0xdc
	// Line 954, Address: 0x24dca0, Func Offset: 0xe0
	// Line 955, Address: 0x24dca4, Func Offset: 0xe4
	// Line 956, Address: 0x24dca8, Func Offset: 0xe8
	// Line 957, Address: 0x24dcac, Func Offset: 0xec
	// Line 958, Address: 0x24dcb0, Func Offset: 0xf0
	// Line 959, Address: 0x24dcb4, Func Offset: 0xf4
	// Line 960, Address: 0x24dcb8, Func Offset: 0xf8
	// Line 961, Address: 0x24dcbc, Func Offset: 0xfc
	// Line 962, Address: 0x24dcc0, Func Offset: 0x100
	// Line 964, Address: 0x24dcd4, Func Offset: 0x114
	// Line 966, Address: 0x24dce0, Func Offset: 0x120
	// Line 969, Address: 0x24dce8, Func Offset: 0x128
	// Line 970, Address: 0x24dcf4, Func Offset: 0x134
	// Line 971, Address: 0x24dcfc, Func Offset: 0x13c
	// Line 973, Address: 0x24dd0c, Func Offset: 0x14c
	// Line 971, Address: 0x24dd10, Func Offset: 0x150
	// Line 973, Address: 0x24dd14, Func Offset: 0x154
	// Line 971, Address: 0x24dd18, Func Offset: 0x158
	// Line 972, Address: 0x24dd1c, Func Offset: 0x15c
	// Line 973, Address: 0x24dd28, Func Offset: 0x168
	// Line 975, Address: 0x24dd38, Func Offset: 0x178
	// Line 986, Address: 0x24dd3c, Func Offset: 0x17c
	// Line 975, Address: 0x24dd44, Func Offset: 0x184
	// Line 977, Address: 0x24dd50, Func Offset: 0x190
	// Line 978, Address: 0x24dd54, Func Offset: 0x194
	// Line 979, Address: 0x24dd58, Func Offset: 0x198
	// Line 981, Address: 0x24dd5c, Func Offset: 0x19c
	// Line 982, Address: 0x24dd64, Func Offset: 0x1a4
	// Line 983, Address: 0x24dd6c, Func Offset: 0x1ac
	// Line 985, Address: 0x24dd74, Func Offset: 0x1b4
	// Line 986, Address: 0x24dd7c, Func Offset: 0x1bc
	// Line 988, Address: 0x24dd88, Func Offset: 0x1c8
	// Line 994, Address: 0x24dd90, Func Offset: 0x1d0
	// Line 995, Address: 0x24dd94, Func Offset: 0x1d4
	// Line 996, Address: 0x24dd98, Func Offset: 0x1d8
	// Line 999, Address: 0x24dda4, Func Offset: 0x1e4
	// Line 1000, Address: 0x24ddb0, Func Offset: 0x1f0
	// Line 1002, Address: 0x24ddbc, Func Offset: 0x1fc
	// Line 1003, Address: 0x24ddf0, Func Offset: 0x230
	// Line 1004, Address: 0x24ddf8, Func Offset: 0x238
	// Line 1012, Address: 0x24de04, Func Offset: 0x244
	// Line 1013, Address: 0x24de14, Func Offset: 0x254
	// Line 1015, Address: 0x24de28, Func Offset: 0x268
	// Line 1017, Address: 0x24de2c, Func Offset: 0x26c
	// Line 1020, Address: 0x24de34, Func Offset: 0x274
	// Line 1022, Address: 0x24de44, Func Offset: 0x284
	// Line 1024, Address: 0x24de54, Func Offset: 0x294
	// Line 1025, Address: 0x24de5c, Func Offset: 0x29c
	// Line 1028, Address: 0x24de64, Func Offset: 0x2a4
	// Line 1031, Address: 0x24de6c, Func Offset: 0x2ac
	// Line 1032, Address: 0x24de88, Func Offset: 0x2c8
	// Line 1034, Address: 0x24de8c, Func Offset: 0x2cc
	// Line 1036, Address: 0x24de9c, Func Offset: 0x2dc
	// Line 1047, Address: 0x24dea0, Func Offset: 0x2e0
	// Line 1049, Address: 0x24deb8, Func Offset: 0x2f8
	// Line 1054, Address: 0x24ded8, Func Offset: 0x318
	// Line 1056, Address: 0x24dee4, Func Offset: 0x324
	// Line 1064, Address: 0x24df10, Func Offset: 0x350
	// Line 1065, Address: 0x24df1c, Func Offset: 0x35c
	// Line 1066, Address: 0x24df20, Func Offset: 0x360
	// Line 1065, Address: 0x24df24, Func Offset: 0x364
	// Line 1064, Address: 0x24df28, Func Offset: 0x368
	// Line 1065, Address: 0x24df2c, Func Offset: 0x36c
	// Line 1064, Address: 0x24df30, Func Offset: 0x370
	// Line 1070, Address: 0x24df34, Func Offset: 0x374
	// Line 1064, Address: 0x24df38, Func Offset: 0x378
	// Line 1065, Address: 0x24df3c, Func Offset: 0x37c
	// Line 1066, Address: 0x24df44, Func Offset: 0x384
	// Line 1065, Address: 0x24df48, Func Offset: 0x388
	// Line 1066, Address: 0x24df50, Func Offset: 0x390
	// Line 1069, Address: 0x24df64, Func Offset: 0x3a4
	// Line 1070, Address: 0x24df84, Func Offset: 0x3c4
	// Line 1071, Address: 0x24df8c, Func Offset: 0x3cc
	// Line 1072, Address: 0x24df9c, Func Offset: 0x3dc
	// Line 1073, Address: 0x24dfa8, Func Offset: 0x3e8
	// Line 1074, Address: 0x24dfac, Func Offset: 0x3ec
	// Line 1072, Address: 0x24dfb0, Func Offset: 0x3f0
	// Line 1076, Address: 0x24dfb4, Func Offset: 0x3f4
	// Line 1072, Address: 0x24dfb8, Func Offset: 0x3f8
	// Line 1073, Address: 0x24dfc0, Func Offset: 0x400
	// Line 1074, Address: 0x24dfd8, Func Offset: 0x418
	// Line 1076, Address: 0x24dfec, Func Offset: 0x42c
	// Line 1077, Address: 0x24dff4, Func Offset: 0x434
	// Line 1079, Address: 0x24e004, Func Offset: 0x444
	// Line 1083, Address: 0x24e008, Func Offset: 0x448
	// Line 1079, Address: 0x24e00c, Func Offset: 0x44c
	// Line 1080, Address: 0x24e010, Func Offset: 0x450
	// Line 1081, Address: 0x24e018, Func Offset: 0x458
	// Line 1083, Address: 0x24e020, Func Offset: 0x460
	// Line 1085, Address: 0x24e024, Func Offset: 0x464
	// Func End, Address: 0x24e048, Func Offset: 0x488
	scePrintf("bhEff_Sub352 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24e050
void bhEff_Sub353(O_WRK* op)
{
	static UV_WORK uvinfo[1] = 
	{
		0.0f,   0.0f, 128.0f, 128.0f
	};
	// Line 1108, Address: 0x24e050, Func Offset: 0
	// Line 1111, Address: 0x24e094, Func Offset: 0x44
	// Line 1113, Address: 0x24e0a0, Func Offset: 0x50
	// Line 1115, Address: 0x24e0a4, Func Offset: 0x54
	// Line 1116, Address: 0x24e0a8, Func Offset: 0x58
	// Line 1118, Address: 0x24e0ac, Func Offset: 0x5c
	// Line 1113, Address: 0x24e0b0, Func Offset: 0x60
	// Line 1115, Address: 0x24e0bc, Func Offset: 0x6c
	// Line 1116, Address: 0x24e0c0, Func Offset: 0x70
	// Line 1118, Address: 0x24e0c4, Func Offset: 0x74
	// Line 1123, Address: 0x24e0c8, Func Offset: 0x78
	// Line 1118, Address: 0x24e0cc, Func Offset: 0x7c
	// Line 1119, Address: 0x24e0d4, Func Offset: 0x84
	// Line 1120, Address: 0x24e0e0, Func Offset: 0x90
	// Line 1121, Address: 0x24e0e4, Func Offset: 0x94
	// Line 1122, Address: 0x24e0e8, Func Offset: 0x98
	// Line 1123, Address: 0x24e0ec, Func Offset: 0x9c
	// Line 1124, Address: 0x24e0f0, Func Offset: 0xa0
	// Line 1125, Address: 0x24e0f4, Func Offset: 0xa4
	// Line 1127, Address: 0x24e0f8, Func Offset: 0xa8
	// Line 1130, Address: 0x24e104, Func Offset: 0xb4
	// Line 1131, Address: 0x24e110, Func Offset: 0xc0
	// Line 1133, Address: 0x24e11c, Func Offset: 0xcc
	// Line 1134, Address: 0x24e124, Func Offset: 0xd4
	// Line 1135, Address: 0x24e12c, Func Offset: 0xdc
	// Line 1143, Address: 0x24e138, Func Offset: 0xe8
	// Line 1145, Address: 0x24e154, Func Offset: 0x104
	// Line 1146, Address: 0x24e15c, Func Offset: 0x10c
	// Line 1149, Address: 0x24e164, Func Offset: 0x114
	// Line 1151, Address: 0x24e170, Func Offset: 0x120
	// Line 1153, Address: 0x24e180, Func Offset: 0x130
	// Line 1155, Address: 0x24e190, Func Offset: 0x140
	// Line 1156, Address: 0x24e198, Func Offset: 0x148
	// Line 1158, Address: 0x24e1a0, Func Offset: 0x150
	// Line 1162, Address: 0x24e1a8, Func Offset: 0x158
	// Line 1163, Address: 0x24e1c0, Func Offset: 0x170
	// Line 1164, Address: 0x24e1cc, Func Offset: 0x17c
	// Line 1166, Address: 0x24e1dc, Func Offset: 0x18c
	// Line 1168, Address: 0x24e1e4, Func Offset: 0x194
	// Line 1166, Address: 0x24e1ec, Func Offset: 0x19c
	// Line 1167, Address: 0x24e1f4, Func Offset: 0x1a4
	// Line 1168, Address: 0x24e204, Func Offset: 0x1b4
	// Line 1170, Address: 0x24e218, Func Offset: 0x1c8
	// Line 1174, Address: 0x24e21c, Func Offset: 0x1cc
	// Line 1177, Address: 0x24e224, Func Offset: 0x1d4
	// Line 1179, Address: 0x24e22c, Func Offset: 0x1dc
	// Line 1177, Address: 0x24e234, Func Offset: 0x1e4
	// Line 1178, Address: 0x24e23c, Func Offset: 0x1ec
	// Line 1179, Address: 0x24e24c, Func Offset: 0x1fc
	// Line 1181, Address: 0x24e260, Func Offset: 0x210
	// Line 1182, Address: 0x24e264, Func Offset: 0x214
	// Line 1189, Address: 0x24e268, Func Offset: 0x218
	// Line 1191, Address: 0x24e274, Func Offset: 0x224
	// Line 1195, Address: 0x24e298, Func Offset: 0x248
	// Line 1191, Address: 0x24e2a4, Func Offset: 0x254
	// Line 1192, Address: 0x24e2a8, Func Offset: 0x258
	// Line 1193, Address: 0x24e2b0, Func Offset: 0x260
	// Line 1194, Address: 0x24e2b8, Func Offset: 0x268
	// Line 1195, Address: 0x24e2c0, Func Offset: 0x270
	// Line 1196, Address: 0x24e2d0, Func Offset: 0x280
	// Line 1191, Address: 0x24e2e0, Func Offset: 0x290
	// Line 1192, Address: 0x24e2e8, Func Offset: 0x298
	// Line 1193, Address: 0x24e308, Func Offset: 0x2b8
	// Line 1194, Address: 0x24e320, Func Offset: 0x2d0
	// Line 1195, Address: 0x24e338, Func Offset: 0x2e8
	// Line 1196, Address: 0x24e360, Func Offset: 0x310
	// Line 1197, Address: 0x24e388, Func Offset: 0x338
	// Line 1198, Address: 0x24e390, Func Offset: 0x340
	// Line 1199, Address: 0x24e398, Func Offset: 0x348
	// Line 1200, Address: 0x24e3a0, Func Offset: 0x350
	// Line 1202, Address: 0x24e3a8, Func Offset: 0x358
	// Line 1204, Address: 0x24e3b4, Func Offset: 0x364
	// Line 1205, Address: 0x24e3dc, Func Offset: 0x38c
	// Line 1208, Address: 0x24e400, Func Offset: 0x3b0
	// Func End, Address: 0x24e408, Func Offset: 0x3b8
	scePrintf("bhEff_Sub353 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24e410
void bhEff_Sub354(O_WRK* op)
{
	NJS_POINT3 p2;
	NJS_POINT3 p1;
	NJS_POINT3 ofs;
	O_WORK* owk;
	static UV_WORK uvinfo[29] = 
	{
		{   0.0f,   0.0f,  40.0f,  40.0f },
		{  40.0f,   0.0f,  40.0f,  40.0f },
		{  80.0f,   0.0f,  40.0f,  40.0f },
		{ 120.0f,   0.0f,  40.0f,  40.0f },
		{ 160.0f,   0.0f,  40.0f,  40.0f },
		{ 200.0f,   0.0f,  40.0f,  40.0f },
		{   0.0f,  40.0f,  40.0f,  40.0f },
		{  40.0f,  40.0f,  40.0f,  40.0f },
		{  80.0f,  40.0f,  40.0f,  40.0f },
		{ 120.0f,  40.0f,  40.0f,  40.0f },
		{ 160.0f,  40.0f,  40.0f,  40.0f },
		{ 200.0f,  40.0f,  40.0f,  40.0f },
		{   0.0f,  96.0f,  40.0f,  24.0f },
		{  40.0f,  96.0f,  40.0f,  24.0f },
		{  80.0f,  96.0f,  40.0f,  24.0f },
		{ 120.0f,  96.0f,  40.0f,  24.0f },
		{ 160.0f,  96.0f,  40.0f,  24.0f },
		{ 200.0f,  96.0f,  40.0f,  24.0f },
		{   0.0f, 128.0f,  40.0f,  40.0f },
		{  40.0f, 128.0f,  40.0f,  40.0f },
		{  80.0f, 128.0f,  40.0f,  40.0f },
		{ 120.0f, 128.0f,  40.0f,  40.0f },
		{ 160.0f, 128.0f,  40.0f,  40.0f },
		{ 200.0f, 128.0f,  40.0f,  40.0f },
		{   0.0f, 176.0f,  48.0f,  48.0f },
		{  48.0f, 176.0f,  48.0f,  48.0f },
		{  96.0f, 176.0f,  48.0f,  48.0f },
		{ 144.0f, 176.0f,  48.0f,  48.0f },
		{ 192.0f, 176.0f,  48.0f,  48.0f }
	};
	static EFF_ANIM anim00_tbl[17] = 
	{
		{  0,  1 }, {  1,  1 }, {  2,  1 }, {  3,  1 },
		{  4,  1 }, {  5,  1 }, {  6,  1 }, {  7,  1 },
		{  8,  1 }, {  9,  1 }, { 10,  1 }, { 11,  1 },
		{ 11,  1 }, { 11,  1 }, { 11,  1 }, { 11,  1 },
		{ -1,  0 }
	};
	static EFF_ANIM anim01_tbl[7] = 
	{
		{ 12,  1 }, { 13,  1 }, { 14,  1 }, { 15,  1 },
		{ 16,  1 }, { 17,  1 }, { -1,  0 }
	};
	static EFF_ANIM anim02_tbl[7] = 
	{
		{ 18,  1 }, { 19,  1 }, { 20,  1 }, { 21,  1 },
		{ 22,  1 }, { 23,  1 }, { -1,  0 }
	};
	static EFF_ANIM anim03_tbl[6] = 
	{ 
		{ 24,  1 }, { 25,  1 }, { 26,  1 }, { 27,  1 },
		{ 28,  1 }, { -1,  0 }
	};
	static EFF_ANIM *anim_tbl[4] = 
	{
		anim00_tbl, anim01_tbl, anim02_tbl, anim03_tbl
	};
	unsigned int argb_tbl[2] = 
	{
		0xC0FFFFFF, 0x20FFFFFF
	};
	// Line 1226, Address: 0x24e410, Func Offset: 0
	// Line 1295, Address: 0x24e428, Func Offset: 0x18
	// Line 1226, Address: 0x24e42c, Func Offset: 0x1c
	// Line 1295, Address: 0x24e430, Func Offset: 0x20
	// Line 1226, Address: 0x24e434, Func Offset: 0x24
	// Line 1295, Address: 0x24e438, Func Offset: 0x28
	// Line 1301, Address: 0x24e448, Func Offset: 0x38
	// Line 1305, Address: 0x24e474, Func Offset: 0x64
	// Line 1306, Address: 0x24e47c, Func Offset: 0x6c
	// Line 1308, Address: 0x24e484, Func Offset: 0x74
	// Line 1323, Address: 0x24e48c, Func Offset: 0x7c
	// Line 1315, Address: 0x24e494, Func Offset: 0x84
	// Line 1328, Address: 0x24e498, Func Offset: 0x88
	// Line 1308, Address: 0x24e49c, Func Offset: 0x8c
	// Line 1309, Address: 0x24e4a4, Func Offset: 0x94
	// Line 1328, Address: 0x24e4a8, Func Offset: 0x98
	// Line 1309, Address: 0x24e4ac, Func Offset: 0x9c
	// Line 1310, Address: 0x24e4b4, Func Offset: 0xa4
	// Line 1312, Address: 0x24e4b8, Func Offset: 0xa8
	// Line 1313, Address: 0x24e4c0, Func Offset: 0xb0
	// Line 1315, Address: 0x24e4d0, Func Offset: 0xc0
	// Line 1316, Address: 0x24e4d4, Func Offset: 0xc4
	// Line 1318, Address: 0x24e4d8, Func Offset: 0xc8
	// Line 1319, Address: 0x24e4e0, Func Offset: 0xd0
	// Line 1320, Address: 0x24e4e8, Func Offset: 0xd8
	// Line 1322, Address: 0x24e4f0, Func Offset: 0xe0
	// Line 1323, Address: 0x24e4f8, Func Offset: 0xe8
	// Line 1325, Address: 0x24e504, Func Offset: 0xf4
	// Line 1326, Address: 0x24e50c, Func Offset: 0xfc
	// Line 1328, Address: 0x24e510, Func Offset: 0x100
	// Line 1330, Address: 0x24e514, Func Offset: 0x104
	// Line 1333, Address: 0x24e520, Func Offset: 0x110
	// Line 1334, Address: 0x24e52c, Func Offset: 0x11c
	// Line 1336, Address: 0x24e538, Func Offset: 0x128
	// Line 1337, Address: 0x24e540, Func Offset: 0x130
	// Line 1338, Address: 0x24e548, Func Offset: 0x138
	// Line 1346, Address: 0x24e554, Func Offset: 0x144
	// Line 1350, Address: 0x24e560, Func Offset: 0x150
	// Line 1352, Address: 0x24e570, Func Offset: 0x160
	// Line 1353, Address: 0x24e580, Func Offset: 0x170
	// Line 1361, Address: 0x24e590, Func Offset: 0x180
	// Line 1363, Address: 0x24e59c, Func Offset: 0x18c
	// Line 1365, Address: 0x24e5c8, Func Offset: 0x1b8
	// Line 1376, Address: 0x24e5d4, Func Offset: 0x1c4
	// Line 1377, Address: 0x24e5e0, Func Offset: 0x1d0
	// Line 1378, Address: 0x24e5e4, Func Offset: 0x1d4
	// Line 1377, Address: 0x24e5e8, Func Offset: 0x1d8
	// Line 1376, Address: 0x24e5ec, Func Offset: 0x1dc
	// Line 1377, Address: 0x24e5f0, Func Offset: 0x1e0
	// Line 1376, Address: 0x24e5f4, Func Offset: 0x1e4
	// Line 1382, Address: 0x24e5f8, Func Offset: 0x1e8
	// Line 1376, Address: 0x24e5fc, Func Offset: 0x1ec
	// Line 1377, Address: 0x24e600, Func Offset: 0x1f0
	// Line 1378, Address: 0x24e608, Func Offset: 0x1f8
	// Line 1377, Address: 0x24e60c, Func Offset: 0x1fc
	// Line 1378, Address: 0x24e614, Func Offset: 0x204
	// Line 1381, Address: 0x24e628, Func Offset: 0x218
	// Line 1382, Address: 0x24e648, Func Offset: 0x238
	// Line 1384, Address: 0x24e650, Func Offset: 0x240
	// Line 1385, Address: 0x24e6b8, Func Offset: 0x2a8
	// Line 1386, Address: 0x24e724, Func Offset: 0x314
	// Line 1388, Address: 0x24e728, Func Offset: 0x318
	// Line 1389, Address: 0x24e73c, Func Offset: 0x32c
	// Line 1390, Address: 0x24e748, Func Offset: 0x338
	// Line 1391, Address: 0x24e74c, Func Offset: 0x33c
	// Line 1389, Address: 0x24e750, Func Offset: 0x340
	// Line 1393, Address: 0x24e754, Func Offset: 0x344
	// Line 1389, Address: 0x24e758, Func Offset: 0x348
	// Line 1390, Address: 0x24e760, Func Offset: 0x350
	// Line 1391, Address: 0x24e778, Func Offset: 0x368
	// Line 1393, Address: 0x24e78c, Func Offset: 0x37c
	// Line 1394, Address: 0x24e794, Func Offset: 0x384
	// Line 1396, Address: 0x24e7a4, Func Offset: 0x394
	// Line 1397, Address: 0x24e7ac, Func Offset: 0x39c
	// Line 1398, Address: 0x24e7b4, Func Offset: 0x3a4
	// Line 1401, Address: 0x24e7bc, Func Offset: 0x3ac
	// Func End, Address: 0x24e7e0, Func Offset: 0x3d0
	scePrintf("bhEff_Sub354 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEff_Sub355(O_WRK* op) 
{
    switch (op->mode0) 
    {                             
    case 0:
        op->tv[0].col = 0xFF0000;
        op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col;
        
        op->bl_src = 8;
        op->bl_dst = 10;
        
        op->flg |= 0x40A0000;
        
        op->ani_ct = 2;
        
        op->tex_id = 4;
        
        op->ct1 = 0;
        op->ct2 = 0;
        
        op->sx = op->sxb;
        op->sy = op->syb;
        
        op->tv[0].u = 0;
        op->tv[0].v = 0;
        
        op->tv[3].u = 1.0f;
        op->tv[3].v = 1.0f;
        
        op->tv[1].u = op->tv[3].u;
        op->tv[1].v = op->tv[0].v;
        
        op->tv[2].u = op->tv[0].u;
        op->tv[2].v = op->tv[3].v;
        
        op->mode0++;
    case 1:
        op->ct3--;
        
        if (op->ct3 >= 0) 
        {
            break;
        }
        
        op->mode2 = 1;
        op->mode0++;
    case 2:
        op->tv[0].col += 0xF0000000;
        op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col;
        
        if ((op->tv[0].col & 0xFF000000) < 0x10000000) 
        {
            op->flg = 0;
        }
        
        break;
    }
    
    if ((((O_WRK*)op->exp0)->stflg & 0x1000000)) 
    {
        op->flg = 0;
    }
    
    if ((op->mode2 != 0) && (op->flg != 0))
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff_Sub356(O_WRK* op) 
{
    switch (op->mode0) 
    {
    case 0:
        op->mode0++;
        break;
    case 1:
        bhEne01_NikuhenEffect((BH_PWORK*)op->lkwkp, (NJS_POINT3*)&op->px, 4);
        
        op->mode0++;
        break;
    case 2:
        op->mode0++;
        break;
    case 3:
        bhEne01_NeckBloodEffect2((BH_PWORK*)op->lkwkp, 0);
        
        op->ct0 = 24;
        
        op->mode0++;
        break;
    case 4:
        if (--op->ct0 < 0) 
        {
            bhEne01_NeckBloodEffect2((BH_PWORK*)op->lkwkp, 1);
            
            op->ct0 = 12;
            
            op->mode0++;
        }
        
        break;
    case 5:
        if (--op->ct0 < 0) 
        {
            bhEne01_NeckBloodEffect2((BH_PWORK*)op->lkwkp, 2);
            
            op->flg = 0;
        }
        
        break;
    }
}

// 100% matching!
void bhEff_Sub357()
{

}

// 100% matching!
void bhEff_Sub360(O_WRK* op) 
{
    static UV_WORK bl00_uvinfo[17] = 
	{
		{  0.0f,    0.0f,   8.0f,   8.0f },
		{  0.0f,    8.0f,  16.0f,  16.0f },
		{  0.0f,   24.0f,  16.0f,  16.0f },
		{  16.0f,  24.0f,  24.0f,  24.0f },
		{  16.0f,   0.0f,  24.0f,  24.0f },
		{  40.0f,   0.0f,  32.0f,  32.0f },
		{  72.0f,   0.0f,  32.0f,  32.0f },
		{ 104.0f,   0.0f,  40.0f,  40.0f },
		{ 144.0f,   0.0f,  40.0f,  40.0f },
		{ 184.0f,   0.0f,  48.0f,  48.0f },
		{   0.0f,  48.0f,  48.0f,  48.0f },
		{  48.0f,  48.0f,  56.0f,  56.0f },
		{ 104.0f,  48.0f,  56.0f,  56.0f },
		{ 160.0f,  48.0f,  56.0f,  56.0f },
		{   0.0f, 104.0f,  56.0f,  56.0f },
		{  56.0f, 104.0f,  56.0f,  56.0f },
		{ 112.0f, 104.0f,  56.0f,  56.0f }
	};
	static UV_WORK bl01_uvinfo[5] = 
	{
		{  40.0f,  32.0f,   8.0f,   8.0f },
		{  40.0f,  40.0f,  16.0f,  16.0f },
		{  48.0f,  32.0f,  16.0f,  16.0f },
		{  64.0f,  32.0f,  16.0f,  16.0f },
		{  80.0f,  32.0f,  16.0f,  16.0f }
	};
	static EFF_ANIM blanim00_tbl[19] = 
	{
		{  0,  1 }, {  1,  1 }, {  2,  1 }, {  3,  1 },
		{  4,  1 }, {  5,  1 }, {  6,  1 }, {  7,  1 },
		{  8,  1 }, {  9,  1 }, { 10,  1 }, { 11,  1 },
		{ 12,  1 }, { 13,  1 }, { 14,  1 }, { 15,  1 },
		{ 16,  1 }, { 17,  1 }, { -1,  0 }
	};
	static EFF_ANIM blanim01_tbl[7] = 
	{
		{  0,  1 }, {  1,  1 }, {  2,  1 }, {  3,  1 },
		{  4,  1 }, {  5,  1 }, { -1,  0 }
	};
	UV_WORK* blood_uvinfo[2] = 
	{
		bl00_uvinfo, bl01_uvinfo
	};
	EFF_ANIM* anim_tbl[2] = 
	{ 
		blanim00_tbl, blanim01_tbl 
	};

    switch (op->mode0) 
    {                       
    case 0:
        op->tv[0].col = 0xC0C0C0C0;
        op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->flg   |= 0x4180000;
        op->stflg |= 0x20;
        
        op->ct0 = 0;
        op->ct1 = 0;
        op->ct2 = 0;
        
        op->spd = 1.0f;
        
        op->mode1 = 0;
        op->mode2 = 0;
        op->mode0++;
    case 1:
        op->ct3--;
        
        if (op->ct3 < 0) 
        {
            op->mode2 = 1;
            op->mode0++;  
        }
        
        break;
    case 2:
        break;
    }
    
    if (op->mode2 != 0) 
    {
    	bhEff_SetSpriteAnime(op, anim_tbl[op->mode1], blood_uvinfo[op->mode1], 0);
    }
}

// 100% matching!
void bhEff_Sub361(O_WRK* op) 
{
    static UV_WORK bl00_uvinfo[8] = 
	{
		{   0.0f,  88.0f,  48.0f,  48.0f },
		{  48.0f,  88.0f,  48.0f,  48.0f },
		{  96.0f,  88.0f,  48.0f,  48.0f },
		{ 144.0f,  88.0f,  48.0f,  48.0f },
		{ 192.0f,  88.0f,  48.0f,  48.0f },
		{   0.0f, 136.0f,  48.0f,  48.0f },
		{  48.0f, 136.0f,  48.0f,  48.0f },
		{  96.0f, 136.0f,  48.0f,  48.0f }
	};
	static UV_WORK bl01_uvinfo[9] = 
	{
		{  24.0f,  32.0f,  16.0f,  16.0f },
		{  24.0f,  48.0f,  16.0f,  16.0f },
		{  40.0f,  48.0f,  24.0f,  24.0f },
		{  40.0f,  72.0f,  32.0f,  32.0f },
		{   0.0f, 104.0f,  40.0f,  40.0f },
		{  40.0f, 104.0f,  40.0f,  40.0f },
		{  80.0f, 104.0f,  40.0f,  40.0f },
		{   0.0f, 144.0f,  40.0f,  40.0f },
		{  40.0f, 144.0f,  40.0f,  40.0f }
	};
	static EFF_ANIM blanim00_tbl[9] = 
	{
		{  0,  1 }, {  1,  1 }, {  2,  1 }, {  3,  1 },
		{  4,  1 }, {  5,  1 }, {  6,  1 }, {  7,  1 },
		{ -1,  0 }  
	};
	static EFF_ANIM blanim01_tbl[11] = 
	{
		{  0,  1 }, {  1,  1 }, {  2,  1 }, {  3,  1 },
		{  4,  1 }, {  5,  1 }, {  6,  1 }, {  7,  1 },
		{  8,  1 }, {  9,  1 }, { -1,  0 }   
	};
	UV_WORK* blood_uvinfo[2] = 
	{ 
		bl00_uvinfo, bl01_uvinfo
	};
	EFF_ANIM* anim_tbl[2] = 
	{ 
		blanim00_tbl, blanim01_tbl 
	};

    switch (op->mode0) 
    {                       
    case 0:
        if (op->type == 0) 
        {
            op->tv[0].col = 0xC0808080;
        }
        else 
        {
            op->tv[0].col = 0xFFC0C0C0;
        }
        
        op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->flg   |= 0x4180000;
        op->stflg |= 0x20;
        
        op->ct0 = 0;
        op->ct1 = 0;
        op->ct2 = 0;
        
        op->spd = 1.0f;
        
        op->mode1 = op->type;
        op->mode2 = 0;
        op->mode0++;
        break;
    case 1:
        op->ct3--;
        
        if (op->ct3 < 0) 
        {
            op->mode2 = 1;
            op->mode0++;  
        }
        
        break;
    case 2:
        break;
    }
    
    if (op->mode2 != 0) 
    {
    	bhEff_SetSpriteAnime(op, anim_tbl[op->mode1], blood_uvinfo[op->mode1], 0);
    }
}

// 
// Start address: 0x24ed30
void bhEff_Sub362(O_WRK* op)
{
	NJS_POINT3 n;
	NJS_POINT3 p2;
	NJS_POINT3 p1;
	static UV_WORK bl00_uvinfo[48] = 
	{
		{   0.0f,   0.0f,  32.0f,  32.0f },
		{  32.0f,   0.0f,  32.0f,  32.0f },
		{  64.0f,   0.0f,  32.0f,  32.0f },
		{  96.0f,   0.0f,  32.0f,  32.0f },
		{ 128.0f,   0.0f,  32.0f,  32.0f },
		{ 160.0f,   0.0f,  32.0f,  32.0f },
		{ 192.0f,   0.0f,  32.0f,  32.0f },
		{ 224.0f,   0.0f,  32.0f,  32.0f },
		{   0.0f,  96.0f,  48.0f,  48.0f },
		{  96.0f,  96.0f,  48.0f,  48.0f },
		{   0.0f,  32.0f,  32.0f,  32.0f },
		{  32.0f,  32.0f,  32.0f,  32.0f },
		{  64.0f,  32.0f,  32.0f,  32.0f },
		{  96.0f,  32.0f,  32.0f,  32.0f },
		{ 128.0f,  32.0f,  32.0f,  32.0f },
		{ 160.0f,  32.0f,  32.0f,  32.0f },
		{ 192.0f,  32.0f,  32.0f,  32.0f },
		{ 224.0f,  32.0f,  32.0f,  32.0f },
		{  48.0f,  96.0f,  48.0f,  48.0f },
		{ 144.0f,  96.0f,  48.0f,  48.0f },
		{   0.0f,  64.0f,  32.0f,  32.0f },
		{  32.0f,  64.0f,  32.0f,  32.0f },
		{  64.0f,  64.0f,  32.0f,  32.0f },
		{  96.0f,  64.0f,  32.0f,  32.0f },
		{ 128.0f,  64.0f,  32.0f,  32.0f },
		{ 160.0f,  64.0f,  32.0f,  32.0f },
		{ 192.0f,  64.0f,  32.0f,  32.0f },
		{ 224.0f,  64.0f,  32.0f,  32.0f },
		{   0.0f, 144.0f,  48.0f,  48.0f },
		{  96.0f, 144.0f,  48.0f,  48.0f },
		{   0.0f,  96.0f,  32.0f,  32.0f },
		{  32.0f,  96.0f,  32.0f,  32.0f },
		{  64.0f,  96.0f,  32.0f,  32.0f },
		{  96.0f,  96.0f,  32.0f,  32.0f },
		{ 128.0f,  96.0f,  32.0f,  32.0f },
		{ 160.0f,  96.0f,  32.0f,  32.0f },
		{ 192.0f,  96.0f,  32.0f,  32.0f },
		{ 224.0f,  96.0f,  32.0f,  32.0f },
		{  48.0f, 144.0f,  48.0f,  48.0f },
		{ 144.0f, 144.0f,  48.0f,  48.0f },
		{   0.0f, 224.0f,  32.0f,  32.0f },
		{  32.0f, 224.0f,  32.0f,  32.0f },
		{  64.0f, 224.0f,  32.0f,  32.0f },
		{  96.0f, 224.0f,  32.0f,  32.0f },
		{ 128.0f, 224.0f,  32.0f,  32.0f },
		{ 160.0f, 224.0f,  32.0f,  32.0f },
		{ 192.0f, 224.0f,  32.0f,  32.0f },
		{ 224.0f, 224.0f,  32.0f,  32.0f }
	};
	static EFF_ANIM blanim00_tbl[6] = 
	{
		{ 20,  1 }, { 21,  1 }, { 22,  1 }, { 23,  1 },
		{ 24,  1 }, { -2,  0 }   
	};
	static EFF_ANIM blanim01_tbl[6] =
	{
		{ 30,  1 }, { 31,  1 }, { 32,  1 }, { 33,  1 },
		{ 34,  1 }, { -2,  0 }  
	};
	static EFF_ANIM blanim02_tbl[6] = 
	{
		{  0,  1 }, {  1,  1 }, {  2,  1 }, {  3,  1 },
		{  4,  1 }, { -2,  0 }   
	};
	static EFF_ANIM blanim03_tbl[6] = 
	{
		{ 10,  1 }, { 11,  1 }, { 12,  1 }, { 13,  1 },
		{ 14,  1 }, { -2,  0 }   
	};
	static EFF_ANIM blanim04_tbl[6] = 
	{
		{ 40,  1 }, { 41,  1 }, { 42,  1 }, { 43,  1 },
		{ 44,  1 }, { -2,  0 }   
	};
	EFF_ANIM* anim_tbl[5] = 
	{
		blanim00_tbl, blanim01_tbl, blanim02_tbl, blanim03_tbl, blanim04_tbl
	};
	float eff_sub362_tbl[1][3] = 
	{
		{  2.0f, 0.05f, 0.97f }
	};
	// Line 1827, Address: 0x24ed30, Func Offset: 0
	// Line 1927, Address: 0x24ed3c, Func Offset: 0xc
	// Line 1827, Address: 0x24ed40, Func Offset: 0x10
	// Line 1927, Address: 0x24ed48, Func Offset: 0x18
	// Line 1935, Address: 0x24ed58, Func Offset: 0x28
	// Line 1927, Address: 0x24ed64, Func Offset: 0x34
	// Line 1935, Address: 0x24ed68, Func Offset: 0x38
	// Line 1927, Address: 0x24ed6c, Func Offset: 0x3c
	// Line 1935, Address: 0x24ed70, Func Offset: 0x40
	// Line 1948, Address: 0x24ed78, Func Offset: 0x48
	// Line 1935, Address: 0x24ed7c, Func Offset: 0x4c
	// Line 1948, Address: 0x24ed84, Func Offset: 0x54
	// Line 1951, Address: 0x24edb8, Func Offset: 0x88
	// Line 1952, Address: 0x24edc4, Func Offset: 0x94
	// Line 1955, Address: 0x24edc8, Func Offset: 0x98
	// Line 1957, Address: 0x24edcc, Func Offset: 0x9c
	// Line 1952, Address: 0x24edd0, Func Offset: 0xa0
	// Line 1955, Address: 0x24eddc, Func Offset: 0xac
	// Line 1956, Address: 0x24ede0, Func Offset: 0xb0
	// Line 1957, Address: 0x24ede4, Func Offset: 0xb4
	// Line 1958, Address: 0x24edf0, Func Offset: 0xc0
	// Line 1959, Address: 0x24edfc, Func Offset: 0xcc
	// Line 1960, Address: 0x24ee00, Func Offset: 0xd0
	// Line 1962, Address: 0x24ee04, Func Offset: 0xd4
	// Line 1964, Address: 0x24ee20, Func Offset: 0xf0
	// Line 1962, Address: 0x24ee24, Func Offset: 0xf4
	// Line 1963, Address: 0x24ee28, Func Offset: 0xf8
	// Line 1964, Address: 0x24ee2c, Func Offset: 0xfc
	// Line 1965, Address: 0x24ee30, Func Offset: 0x100
	// Line 1968, Address: 0x24ee38, Func Offset: 0x108
	// Line 1969, Address: 0x24ee68, Func Offset: 0x138
	// Line 1972, Address: 0x24ee74, Func Offset: 0x144
	// Line 1973, Address: 0x24ee80, Func Offset: 0x150
	// Line 1976, Address: 0x24ee8c, Func Offset: 0x15c
	// Line 1975, Address: 0x24ee90, Func Offset: 0x160
	// Line 1976, Address: 0x24ee94, Func Offset: 0x164
	// Line 1977, Address: 0x24ee98, Func Offset: 0x168
	// Line 1985, Address: 0x24eea4, Func Offset: 0x174
	// Line 1987, Address: 0x24eeb4, Func Offset: 0x184
	// Line 1988, Address: 0x24eecc, Func Offset: 0x19c
	// Line 1989, Address: 0x24eef4, Func Offset: 0x1c4
	// Line 1990, Address: 0x24ef0c, Func Offset: 0x1dc
	// Line 1993, Address: 0x24ef18, Func Offset: 0x1e8
	// Line 1995, Address: 0x24ef28, Func Offset: 0x1f8
	// Line 1996, Address: 0x24ef30, Func Offset: 0x200
	// Line 2000, Address: 0x24ef38, Func Offset: 0x208
	// Line 2001, Address: 0x24ef3c, Func Offset: 0x20c
	// Line 2005, Address: 0x24ef44, Func Offset: 0x214
	// Line 2006, Address: 0x24ef48, Func Offset: 0x218
	// Line 2000, Address: 0x24ef4c, Func Offset: 0x21c
	// Line 2001, Address: 0x24ef50, Func Offset: 0x220
	// Line 2009, Address: 0x24ef54, Func Offset: 0x224
	// Line 2001, Address: 0x24ef60, Func Offset: 0x230
	// Line 2009, Address: 0x24ef64, Func Offset: 0x234
	// Line 2001, Address: 0x24ef68, Func Offset: 0x238
	// Line 2002, Address: 0x24ef6c, Func Offset: 0x23c
	// Line 2004, Address: 0x24ef74, Func Offset: 0x244
	// Line 2005, Address: 0x24ef7c, Func Offset: 0x24c
	// Line 2006, Address: 0x24ef88, Func Offset: 0x258
	// Line 2009, Address: 0x24ef8c, Func Offset: 0x25c
	// Line 2011, Address: 0x24ef9c, Func Offset: 0x26c
	// Line 2012, Address: 0x24efa0, Func Offset: 0x270
	// Line 2015, Address: 0x24efa8, Func Offset: 0x278
	// Line 2011, Address: 0x24efac, Func Offset: 0x27c
	// Line 2012, Address: 0x24efb0, Func Offset: 0x280
	// Line 2013, Address: 0x24efbc, Func Offset: 0x28c
	// Line 2015, Address: 0x24efc0, Func Offset: 0x290
	// Line 2016, Address: 0x24efc8, Func Offset: 0x298
	// Line 2017, Address: 0x24efd0, Func Offset: 0x2a0
	// Line 2019, Address: 0x24f004, Func Offset: 0x2d4
	// Line 2020, Address: 0x24f008, Func Offset: 0x2d8
	// Line 2021, Address: 0x24f00c, Func Offset: 0x2dc
	// Line 2022, Address: 0x24f010, Func Offset: 0x2e0
	// Line 2023, Address: 0x24f014, Func Offset: 0x2e4
	// Line 2024, Address: 0x24f01c, Func Offset: 0x2ec
	// Line 2028, Address: 0x24f024, Func Offset: 0x2f4
	// Line 2029, Address: 0x24f02c, Func Offset: 0x2fc
	// Line 2030, Address: 0x24f030, Func Offset: 0x300
	// Line 2034, Address: 0x24f034, Func Offset: 0x304
	// Line 2036, Address: 0x24f054, Func Offset: 0x324
	// Line 2038, Address: 0x24f064, Func Offset: 0x334
	// Line 2039, Address: 0x24f084, Func Offset: 0x354
	// Line 2042, Address: 0x24f08c, Func Offset: 0x35c
	// Line 2045, Address: 0x24f0ac, Func Offset: 0x37c
	// Line 2046, Address: 0x24f0b4, Func Offset: 0x384
	// Line 2049, Address: 0x24f0bc, Func Offset: 0x38c
	// Line 2050, Address: 0x24f0c4, Func Offset: 0x394
	// Line 2049, Address: 0x24f0cc, Func Offset: 0x39c
	// Line 2050, Address: 0x24f0d4, Func Offset: 0x3a4
	// Line 2053, Address: 0x24f0e8, Func Offset: 0x3b8
	// Line 2055, Address: 0x24f0f0, Func Offset: 0x3c0
	// Line 2056, Address: 0x24f0fc, Func Offset: 0x3cc
	// Line 2057, Address: 0x24f118, Func Offset: 0x3e8
	// Line 2059, Address: 0x24f124, Func Offset: 0x3f4
	// Line 2061, Address: 0x24f140, Func Offset: 0x410
	// Line 2063, Address: 0x24f150, Func Offset: 0x420
	// Line 2064, Address: 0x24f170, Func Offset: 0x440
	// Line 2067, Address: 0x24f178, Func Offset: 0x448
	// Line 2070, Address: 0x24f198, Func Offset: 0x468
	// Line 2085, Address: 0x24f1a4, Func Offset: 0x474
	// Line 2087, Address: 0x24f1b0, Func Offset: 0x480
	// Line 2089, Address: 0x24f1d4, Func Offset: 0x4a4
	// Func End, Address: 0x24f1ec, Func Offset: 0x4bc
	scePrintf("bhEff_Sub362 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24f1f0
void bhEff_Sub363(O_WRK* op)
{
	static UV_WORK eff_uvinfo[12] =
	{
		{   0.0f, 160.0f,  32.0f,  32.0f }, {  32.0f, 160.0f,  32.0f,  32.0f }, {  64.0f, 160.0f,  32.0f,  32.0f }, 
		{  96.0f, 160.0f,  32.0f,  32.0f }, {   0.0f, 192.0f,  32.0f,  32.0f }, {  32.0f, 192.0f,  32.0f,  32.0f }, 
		{  64.0f, 192.0f,  32.0f,  32.0f }, {  96.0f, 192.0f,  32.0f,  32.0f }, {   0.0f, 224.0f,  32.0f,  32.0f }, 
		{  32.0f, 224.0f,  32.0f,  32.0f }, {  64.0f, 224.0f,  32.0f,  32.0f }, {  96.0f, 224.0f,  32.0f,  32.0f }
	};
	// Line 2106, Address: 0x24f1f0, Func Offset: 0
	// Line 2129, Address: 0x24f1fc, Func Offset: 0xc
	// Line 2132, Address: 0x24f228, Func Offset: 0x38
	// Line 2133, Address: 0x24f234, Func Offset: 0x44
	// Line 2136, Address: 0x24f238, Func Offset: 0x48
	// Line 2137, Address: 0x24f23c, Func Offset: 0x4c
	// Line 2138, Address: 0x24f240, Func Offset: 0x50
	// Line 2133, Address: 0x24f244, Func Offset: 0x54
	// Line 2136, Address: 0x24f250, Func Offset: 0x60
	// Line 2137, Address: 0x24f254, Func Offset: 0x64
	// Line 2138, Address: 0x24f258, Func Offset: 0x68
	// Line 2139, Address: 0x24f264, Func Offset: 0x74
	// Line 2141, Address: 0x24f270, Func Offset: 0x80
	// Line 2142, Address: 0x24f290, Func Offset: 0xa0
	// Line 2144, Address: 0x24f29c, Func Offset: 0xac
	// Line 2146, Address: 0x24f2a0, Func Offset: 0xb0
	// Line 2147, Address: 0x24f2b8, Func Offset: 0xc8
	// Line 2148, Address: 0x24f2dc, Func Offset: 0xec
	// Line 2149, Address: 0x24f2ec, Func Offset: 0xfc
	// Line 2151, Address: 0x24f314, Func Offset: 0x124
	// Line 2153, Address: 0x24f338, Func Offset: 0x148
	// Line 2154, Address: 0x24f340, Func Offset: 0x150
	// Line 2155, Address: 0x24f344, Func Offset: 0x154
	// Line 2156, Address: 0x24f350, Func Offset: 0x160
	// Line 2161, Address: 0x24f35c, Func Offset: 0x16c
	// Line 2164, Address: 0x24f368, Func Offset: 0x178
	// Line 2167, Address: 0x24f374, Func Offset: 0x184
	// Line 2168, Address: 0x24f37c, Func Offset: 0x18c
	// Line 2167, Address: 0x24f384, Func Offset: 0x194
	// Line 2168, Address: 0x24f388, Func Offset: 0x198
	// Line 2171, Address: 0x24f39c, Func Offset: 0x1ac
	// Line 2173, Address: 0x24f3c0, Func Offset: 0x1d0
	// Line 2174, Address: 0x24f3e8, Func Offset: 0x1f8
	// Line 2175, Address: 0x24f3f0, Func Offset: 0x200
	// Line 2178, Address: 0x24f3f8, Func Offset: 0x208
	// Line 2181, Address: 0x24f410, Func Offset: 0x220
	// Line 2182, Address: 0x24f428, Func Offset: 0x238
	// Line 2183, Address: 0x24f440, Func Offset: 0x250
	// Line 2215, Address: 0x24f448, Func Offset: 0x258
	// Line 2218, Address: 0x24f450, Func Offset: 0x260
	// Line 2226, Address: 0x24f458, Func Offset: 0x268
	// Line 2228, Address: 0x24f464, Func Offset: 0x274
	// Line 2229, Address: 0x24f46c, Func Offset: 0x27c
	// Line 2228, Address: 0x24f474, Func Offset: 0x284
	// Line 2229, Address: 0x24f47c, Func Offset: 0x28c
	// Line 2231, Address: 0x24f490, Func Offset: 0x2a0
	// Line 2233, Address: 0x24f494, Func Offset: 0x2a4
	// Line 2234, Address: 0x24f4a0, Func Offset: 0x2b0
	// Line 2237, Address: 0x24f4a8, Func Offset: 0x2b8
	// Line 2240, Address: 0x24f4b0, Func Offset: 0x2c0
	// Line 2241, Address: 0x24f4d0, Func Offset: 0x2e0
	// Func End, Address: 0x24f4e0, Func Offset: 0x2f0
	scePrintf("bhEff_Sub363 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEff_Sub364(O_WRK* op)
{
    switch (op->mode0) 
    {                          
    case 0:
        op->bl_src = 8;
        op->bl_dst = 10;
        
        op->flg |= 0x240000;
        
        op->ani_ct = 0;
        
        op->ct0 = 1;
        op->ct1 = 0;
        op->ct2 = 0;
        op->ct3 = 0;
        
        op->func = (void*)bhEff_ModelDraw;
        
        op->mode0++;
    case 1:
        if (--op->ct0 < 0) 
        {
            op->flg = 0;
        }
        
        break;
    }
    
    if (op->flg != 0) 
    {
        sys->ef_fnc[sys->ef_fncn] = op;
        
        sys->ef_fncn++;
    }
}

// 100% matching!
void bhEff_Sub365(O_WRK* op) 
{
    EFFSUB365_WORK* effect; 
    NJS_POINT3* vpos; 
    NJS_VECTOR* avec; 
    int i; 
	
    effect = (EFFSUB365_WORK*)op->exp0;
    
    vpos = effect->vtx_pos;
    avec = effect->add_vec;
    
    switch (op->mode0) 
    {                           
    case 0:
        op->tv->col = 0xFF404040;
        
        op->sx = 1.0f;
        op->sy = 1.0f;
        
        op->ct0 = 3;
        op->ct1 = 0;
        op->ct2 = 0;
        
        op->mode2 = 0;
        op->mode0++;
    case 1:
        op->ct3--;
        
        if (op->ct3 >= 0) 
        {
            break;
        }
        
        op->ct0 = 0;
        
        op->mode2 = 1;
        op->mode0++;
    case 2:
        for (i = 0; i < effect->dtbl.num; i++) 
        {
            vpos->x += avec->x;
            vpos->y += avec->y + (-0.02f * op->ct0);
            vpos->z += avec->z;

            vpos++;
            avec++;
        }
        
        op->ct0++;
        
        if (op->ct0 > 8) 
        {
            op->tv->col += 0xF0000000;
            
            if ((op->tv->col & 0xFF000000) < 0x10000000) 
            {
                op->flg          = 0;
                effect->dtbl.flg = 0;
            }
        }
    }
    
    if ((op->mode2 != 0) && (op->flg != 0)) 
    {
        sys->ef_fnc[sys->ef_fncn] = op;
        
        sys->ef_fncn++;
    }
}

// 
// Start address: 0x24f790
void bhEff_Sub366(O_WRK* op)
{
	int i;
	float* g;
	NJS_POINT3* vec;
	NJS_POINT3* vtx_p2;
	NJS_POINT3* vtx_p;
	EFFSUB366_WORK* effect;
	// Line 2411, Address: 0x24f790, Func Offset: 0
	// Line 2418, Address: 0x24f794, Func Offset: 0x4
	// Line 2413, Address: 0x24f79c, Func Offset: 0xc
	// Line 2414, Address: 0x24f7a0, Func Offset: 0x10
	// Line 2415, Address: 0x24f7a4, Func Offset: 0x14
	// Line 2418, Address: 0x24f7a8, Func Offset: 0x18
	// Line 2421, Address: 0x24f7cc, Func Offset: 0x3c
	// Line 2423, Address: 0x24f7d8, Func Offset: 0x48
	// Line 2424, Address: 0x24f7e0, Func Offset: 0x50
	// Line 2427, Address: 0x24f7e4, Func Offset: 0x54
	// Line 2428, Address: 0x24f7ec, Func Offset: 0x5c
	// Line 2429, Address: 0x24f7f0, Func Offset: 0x60
	// Line 2432, Address: 0x24f7f8, Func Offset: 0x68
	// Line 2433, Address: 0x24f800, Func Offset: 0x70
	// Line 2436, Address: 0x24f808, Func Offset: 0x78
	// Line 2437, Address: 0x24f810, Func Offset: 0x80
	// Line 2439, Address: 0x24f818, Func Offset: 0x88
	// Line 2440, Address: 0x24f820, Func Offset: 0x90
	// Line 2442, Address: 0x24f824, Func Offset: 0x94
	// Line 2443, Address: 0x24f82c, Func Offset: 0x9c
	// Line 2444, Address: 0x24f830, Func Offset: 0xa0
	// Line 2445, Address: 0x24f834, Func Offset: 0xa4
	// Line 2446, Address: 0x24f838, Func Offset: 0xa8
	// Line 2449, Address: 0x24f844, Func Offset: 0xb4
	// Line 2450, Address: 0x24f850, Func Offset: 0xc0
	// Line 2453, Address: 0x24f85c, Func Offset: 0xcc
	// Line 2452, Address: 0x24f860, Func Offset: 0xd0
	// Line 2453, Address: 0x24f864, Func Offset: 0xd4
	// Line 2454, Address: 0x24f868, Func Offset: 0xd8
	// Line 2462, Address: 0x24f874, Func Offset: 0xe4
	// Line 2464, Address: 0x24f878, Func Offset: 0xe8
	// Line 2462, Address: 0x24f88c, Func Offset: 0xfc
	// Line 2463, Address: 0x24f894, Func Offset: 0x104
	// Line 2464, Address: 0x24f898, Func Offset: 0x108
	// Line 2463, Address: 0x24f8a4, Func Offset: 0x114
	// Line 2464, Address: 0x24f8a8, Func Offset: 0x118
	// Line 2466, Address: 0x24f8b0, Func Offset: 0x120
	// Line 2467, Address: 0x24f8bc, Func Offset: 0x12c
	// Line 2468, Address: 0x24f8c4, Func Offset: 0x134
	// Line 2469, Address: 0x24f8cc, Func Offset: 0x13c
	// Line 2471, Address: 0x24f8d4, Func Offset: 0x144
	// Line 2472, Address: 0x24f8e4, Func Offset: 0x154
	// Line 2473, Address: 0x24f8fc, Func Offset: 0x16c
	// Line 2475, Address: 0x24f90c, Func Offset: 0x17c
	// Line 2477, Address: 0x24f920, Func Offset: 0x190
	// Line 2479, Address: 0x24f924, Func Offset: 0x194
	// Line 2480, Address: 0x24f928, Func Offset: 0x198
	// Line 2481, Address: 0x24f934, Func Offset: 0x1a4
	// Line 2482, Address: 0x24f940, Func Offset: 0x1b0
	// Line 2483, Address: 0x24f94c, Func Offset: 0x1bc
	// Line 2485, Address: 0x24f950, Func Offset: 0x1c0
	// Line 2486, Address: 0x24f954, Func Offset: 0x1c4
	// Line 2487, Address: 0x24f958, Func Offset: 0x1c8
	// Line 2488, Address: 0x24f95c, Func Offset: 0x1cc
	// Line 2489, Address: 0x24f960, Func Offset: 0x1d0
	// Line 2490, Address: 0x24f978, Func Offset: 0x1e8
	// Line 2492, Address: 0x24f984, Func Offset: 0x1f4
	// Line 2494, Address: 0x24f994, Func Offset: 0x204
	// Line 2495, Address: 0x24f9a0, Func Offset: 0x210
	// Line 2500, Address: 0x24f9ac, Func Offset: 0x21c
	// Line 2502, Address: 0x24f9bc, Func Offset: 0x22c
	// Line 2503, Address: 0x24f9cc, Func Offset: 0x23c
	// Line 2504, Address: 0x24f9d8, Func Offset: 0x248
	// Line 2506, Address: 0x24f9e8, Func Offset: 0x258
	// Line 2507, Address: 0x24f9ec, Func Offset: 0x25c
	// Line 2513, Address: 0x24f9f0, Func Offset: 0x260
	// Line 2515, Address: 0x24f9fc, Func Offset: 0x26c
	// Line 2517, Address: 0x24fa08, Func Offset: 0x278
	// Line 2518, Address: 0x24fa30, Func Offset: 0x2a0
	// Line 2521, Address: 0x24fa54, Func Offset: 0x2c4
	// Func End, Address: 0x24fa5c, Func Offset: 0x2cc
	scePrintf("bhEff_Sub366 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEff_Sub367(O_WRK* op) 
{
    EFFSUB367_WORK* effect; 
    NJS_POINT3* vtx_p;     
    float* g, *r;            
    int* rot, *rot_spd;          
    int i;               
  
    effect = (EFFSUB367_WORK*)op->exp0;
    
    vtx_p = effect->vtx_pos;
    
    g = effect->g;
    r = effect->r;
    
    rot     = effect->rot;
    rot_spd = effect->rot_spd;
    
    switch (op->mode0) 
    {                           
    case 0:
        op->tv[0].col = 0x80FFFFFF;
        
        op->sx = 1.0f;
        op->sy = 1.0f;
        
        op->ct0 = 3;
        op->ct1 = 0;
        op->ct2 = 0;
        op->ct3 = 0;
        
        op->mode0++;
    case 1:
        op->ct0++;
        op->ct1++;
        
        for (i = 0; i < effect->dtbl.num; i++)
        {
            *rot += *rot_spd;
            
            vtx_p->x = op->px - (*r   * njSin(*rot));
            vtx_p->z = op->pz - (*r++ * njCos(*rot));
            
            vtx_p->y += *g++ * op->ct0;
            
            rot_spd++;
            rot++;
            vtx_p++;
        }
        
        if (op->ct1 > 120) 
        {
            op->flg          = 0;
            effect->dtbl.flg = 0;
        }
        
        break;
    }
    
    if (op->flg != 0) 
    {
        sys->ef_fnc[sys->ef_fncn] = op;
        
        sys->ef_fncn++;
    }
}

// 100% matching!
void bhEff_Sub368(O_WRK* op)
{
    static UV_WORK uvinfo[1] =
	{
		0.0f, 160.0f,  48.0f,  56.0f    
	};
    
    switch (op->mode0) 
    {                             
    case 0:
        op->tv[0].col = 0x40808080;
        op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col;
        
        op->tv[0].x = -1.0f;
        op->tv[0].y = 0;
        op->tv[0].z = 0;
        
        op->tv[1].x = 1.0f;
        op->tv[1].y = 0;
        op->tv[1].z = 0;
        
        op->tv[2].x = -1.0f;
        op->tv[2].y = -2.0f;
        op->tv[2].z = 0;
        
        op->tv[3].x = 1.0f;
        op->tv[3].y = -2.0f;
        op->tv[3].z = 0;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->flg   |= 0x4080000;
        op->stflg |= 0x20;
        
        op->ani_ct = 0;
        
        op->ct0 = 0;
        op->ct1 = 0;
        op->ct2 = 120;
        
        op->mode2 = 0;
        op->mode0++;
        break;
    case 1:
        op->ct3--;
        
        if (op->ct3 >= 0) 
        {
            break;
        }
        
        op->mode2 = 1;
        op->mode0++;
    case 2:
        if (--op->ct2 < 0) 
        {
            op->mode0++;
        } 
        else 
        {
            op->syb *= 1.01f;
        }
    case 3:
        break;
    }
    
    if (op->mode2 != 0) 
    {
        bhEff_SetSprite(op, uvinfo, 0);
    }
}

// 100% matching!
void bhEff_Sub369(O_WRK* op) 
{
    static UV_WORK uvinfo[15] = 
	{
		{   0.0f,   0.0f,  16.0f,  16.0f },
		{  16.0f,   0.0f,  24.0f,  24.0f },
		{  40.0f,   0.0f,  24.0f,  24.0f },
		{  64.0f,   0.0f,  32.0f,  32.0f },
		{  96.0f,   0.0f,  48.0f,  48.0f },
		{ 144.0f,   0.0f,  48.0f,  48.0f },
		{ 192.0f,   0.0f,  64.0f,  64.0f },
		{   0.0f,  64.0f,  64.0f,  64.0f },
		{  64.0f,  64.0f,  64.0f,  64.0f },
		{ 128.0f,  64.0f,  64.0f,  64.0f },
		{ 192.0f,  64.0f,  64.0f,  64.0f },
		{   0.0f, 128.0f,  64.0f,  64.0f },
		{  64.0f, 128.0f,  64.0f,  64.0f },
		{ 128.0f, 128.0f,  64.0f,  64.0f },
		{ 192.0f, 128.0f,  64.0f,  64.0f }
	};
	static EFF_ANIM anim00_tbl[12] =
	{
		{  4,  1 }, {  5,  1 }, {  6,  1 }, {  7,  1 },
		{  8,  1 }, {  9,  1 }, { 10,  1 }, { 11,  1 },
		{ 12,  1 }, { 13,  1 }, { 14,  1 }, { -1,  0 }
	};
	static EFF_ANIM anim01_tbl[16] =
	{
		{  0,  1 }, {  1,  1 }, {  2, 1  }, {  3,  1 },
		{  4,  1 }, {  5,  1 }, {  6, 1  }, {  7,  1 },
		{  8,  1 }, {  9,  1 }, { 10, 1  }, { 11,  1 },
		{ 12,  1 }, { 13,  1 }, { 14, 1  }, { -1,  0 }
	};
	static EFF_ANIM* anim_tbl[2] =
	{
		anim00_tbl, anim01_tbl
	};
    
    switch (op->mode0)
    {                              
    case 0:
        op->tv[0].col = 0x40808080;
        op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col;
        
        op->bl_src = 8;
        op->bl_dst = 10;
        
        op->flg   |= 0x4180000;
        op->stflg |= 0x20;
        
        op->ani_ct = 0;
        
        op->ct0 = 0;
        op->ct1 = 0;
        op->ct2 = 0;
        
        op->spd = 1.0f;
        
        op->mode1 = op->type;
        op->mode2 = 0;
        op->mode0++;
        break;
    case 1:
        op->ct3--;
        
        if (op->ct3 >= 0) 
        {
            break;
        }
        
        op->mode2 = 1;
        op->mode0++;
    case 2:
        op->xn *= op->zn;
        
        op->px += op->xn * -njSin(op->ay);
        op->pz += op->xn * -njCos(op->ay);
        op->py += op->yn;
        break;
    }
    
    if (op->mode2 != 0)
    {
        bhEff_SetSpriteAnime(op, anim_tbl[op->mode1], uvinfo, 0);
    }
}

// 
// Start address: 0x24ff60
void bhEff_Sub370(O_WRK* op)
{
	int eno;
	NJS_POINT3 v2;
	NJS_POINT3 v1;
	EFF370_WORK* eff_p;
	static EFF370_WORK eff370_tbl[11] = 
	{
		{   0.5f,  0.98f, -0.02f, 371,   0,   4,   0 },
		{   0.3f,  0.98f, -0.02f, 371,   0,   4,   0 },
		{   0.2f,  0.98f, -0.04f, 371,   0,   4,   0 },
		{   0.7f,  0.98f, -0.04f, 371,   0,   4,   1 },
		{  0.25f,  0.98f, -0.03f, 371,   0,   2,   0 },
		{   0.5f,  0.98f, -0.03f, 371,   0,   3,   1 },
		{   0.7f,  0.98f, -0.04f, 373,   1,   4,   1 },
		{   0.5f,  0.98f, -0.03f, 373,   1,   3,   1 },
		{   0.5f,  0.97f, -0.05f, 373,   3,   2,   0 },
		{   0.0f,   0.0f,   0.0f,   0,   3,   3,   2 },
		{   0.5f,  0.98f, -0.03f, 373,   0,   3,   2 }
	};
	unsigned int bl_col[4] = 
	{
		0xFF5F0000, 0xFF400000, 0xFF400000, 0xFF400000
	};
	// Line 2870, Address: 0x24ff60, Func Offset: 0
	// Line 2889, Address: 0x24ff6c, Func Offset: 0xc
	// Line 2870, Address: 0x24ff70, Func Offset: 0x10
	// Line 2889, Address: 0x24ff74, Func Offset: 0x14
	// Line 2870, Address: 0x24ff78, Func Offset: 0x18
	// Line 2889, Address: 0x24ff7c, Func Offset: 0x1c
	// Line 2903, Address: 0x24ff8c, Func Offset: 0x2c
	// Line 2896, Address: 0x24ff90, Func Offset: 0x30
	// Line 2905, Address: 0x24ff98, Func Offset: 0x38
	// Line 2903, Address: 0x24ff9c, Func Offset: 0x3c
	// Line 2905, Address: 0x24ffa4, Func Offset: 0x44
	// Line 2903, Address: 0x24ffa8, Func Offset: 0x48
	// Line 2905, Address: 0x24ffac, Func Offset: 0x4c
	// Line 2908, Address: 0x24ffc4, Func Offset: 0x64
	// Line 2909, Address: 0x24ffc8, Func Offset: 0x68
	// Line 2930, Address: 0x24ffcc, Func Offset: 0x6c
	// Line 2931, Address: 0x24ffd0, Func Offset: 0x70
	// Line 2934, Address: 0x24ffdc, Func Offset: 0x7c
	// Line 2936, Address: 0x24ffec, Func Offset: 0x8c
	// Line 2938, Address: 0x24fff8, Func Offset: 0x98
	// Line 2944, Address: 0x24fffc, Func Offset: 0x9c
	// Line 2936, Address: 0x250000, Func Offset: 0xa0
	// Line 2937, Address: 0x25000c, Func Offset: 0xac
	// Line 2938, Address: 0x250024, Func Offset: 0xc4
	// Line 2939, Address: 0x250038, Func Offset: 0xd8
	// Line 2940, Address: 0x25004c, Func Offset: 0xec
	// Line 2941, Address: 0x250064, Func Offset: 0x104
	// Line 2942, Address: 0x25007c, Func Offset: 0x11c
	// Line 2944, Address: 0x250094, Func Offset: 0x134
	// Line 2946, Address: 0x2500b8, Func Offset: 0x158
	// Line 2949, Address: 0x2500c4, Func Offset: 0x164
	// Line 2952, Address: 0x2500d4, Func Offset: 0x174
	// Line 2954, Address: 0x2500fc, Func Offset: 0x19c
	// Line 2957, Address: 0x250104, Func Offset: 0x1a4
	// Line 2960, Address: 0x25012c, Func Offset: 0x1cc
	// Line 2963, Address: 0x250134, Func Offset: 0x1d4
	// Line 2965, Address: 0x250144, Func Offset: 0x1e4
	// Line 2970, Address: 0x250150, Func Offset: 0x1f0
	// Line 2971, Address: 0x250190, Func Offset: 0x230
	// Line 2972, Address: 0x2501b4, Func Offset: 0x254
	// Line 2976, Address: 0x2501bc, Func Offset: 0x25c
	// Line 2979, Address: 0x2501c4, Func Offset: 0x264
	// Line 2976, Address: 0x2501c8, Func Offset: 0x268
	// Line 2977, Address: 0x2501d4, Func Offset: 0x274
	// Line 2978, Address: 0x2501e8, Func Offset: 0x288
	// Line 2979, Address: 0x2501fc, Func Offset: 0x29c
	// Line 2981, Address: 0x25021c, Func Offset: 0x2bc
	// Line 2984, Address: 0x250224, Func Offset: 0x2c4
	// Line 2987, Address: 0x250230, Func Offset: 0x2d0
	// Line 2984, Address: 0x25023c, Func Offset: 0x2dc
	// Line 2985, Address: 0x250248, Func Offset: 0x2e8
	// Line 2986, Address: 0x250260, Func Offset: 0x300
	// Line 2987, Address: 0x250278, Func Offset: 0x318
	// Line 2990, Address: 0x250294, Func Offset: 0x334
	// Line 2992, Address: 0x2502a0, Func Offset: 0x340
	// Line 2994, Address: 0x2502c0, Func Offset: 0x360
	// Line 2995, Address: 0x2502e4, Func Offset: 0x384
	// Line 2994, Address: 0x2502f0, Func Offset: 0x390
	// Line 2995, Address: 0x2502f8, Func Offset: 0x398
	// Line 2996, Address: 0x2502fc, Func Offset: 0x39c
	// Line 2995, Address: 0x250308, Func Offset: 0x3a8
	// Line 2996, Address: 0x25030c, Func Offset: 0x3ac
	// Line 3000, Address: 0x250314, Func Offset: 0x3b4
	// Line 3002, Address: 0x250324, Func Offset: 0x3c4
	// Line 3008, Address: 0x250328, Func Offset: 0x3c8
	// Line 3002, Address: 0x25032c, Func Offset: 0x3cc
	// Line 3003, Address: 0x250330, Func Offset: 0x3d0
	// Line 3004, Address: 0x250338, Func Offset: 0x3d8
	// Line 3008, Address: 0x250340, Func Offset: 0x3e0
	// Line 3009, Address: 0x250368, Func Offset: 0x408
	// Line 3010, Address: 0x250378, Func Offset: 0x418
	// Line 3013, Address: 0x250380, Func Offset: 0x420
	// Line 3014, Address: 0x250388, Func Offset: 0x428
	// Line 3015, Address: 0x250390, Func Offset: 0x430
	// Line 3018, Address: 0x250398, Func Offset: 0x438
	// Line 3019, Address: 0x2503bc, Func Offset: 0x45c
	// Line 3020, Address: 0x2503d0, Func Offset: 0x470
	// Line 3021, Address: 0x2503e4, Func Offset: 0x484
	// Line 3022, Address: 0x2503f4, Func Offset: 0x494
	// Line 3023, Address: 0x250430, Func Offset: 0x4d0
	// Line 3024, Address: 0x25043c, Func Offset: 0x4dc
	// Line 3022, Address: 0x250448, Func Offset: 0x4e8
	// Line 3023, Address: 0x250454, Func Offset: 0x4f4
	// Line 3024, Address: 0x25045c, Func Offset: 0x4fc
	// Line 3027, Address: 0x250464, Func Offset: 0x504
	// Line 3029, Address: 0x25046c, Func Offset: 0x50c
	// Line 3030, Address: 0x250478, Func Offset: 0x518
	// Line 3032, Address: 0x25048c, Func Offset: 0x52c
	// Line 3037, Address: 0x250490, Func Offset: 0x530
	// Func End, Address: 0x2504a8, Func Offset: 0x548
	scePrintf("bhEff_Sub370 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEff_Sub371(O_WRK* op)
{
    static UV_WORK uvinfo[32] = 
	{
		{  48.0f,  40.0f,   8.0f,   8.0f },
		{  48.0f,  48.0f,   8.0f,   8.0f },
		{  64.0f,  72.0f,  16.0f,  16.0f },
		{   0.0f,  64.0f,  24.0f,  24.0f },
		{   0.0f,  40.0f,  24.0f,  24.0f },
		{  24.0f,  40.0f,  24.0f,  24.0f },
		{  56.0f,  40.0f,  32.0f,  32.0f },
		{  88.0f,  40.0f,  32.0f,  32.0f },
		{   0.0f,   0.0f,  40.0f,  40.0f },
		{  40.0f,   0.0f,  40.0f,  40.0f },
		{  80.0f,   0.0f,  40.0f,  40.0f },
		{ 120.0f,   0.0f,  40.0f,  40.0f },
		{ 160.0f,   0.0f,  40.0f,  40.0f },
		{ 200.0f,   0.0f,  40.0f,  40.0f },
		{  48.0f,  56.0f,   8.0f,   8.0f },
		{  48.0f,  64.0f,   8.0f,   8.0f },
		{  48.0f,  72.0f,  16.0f,  16.0f },
		{  24.0f,  64.0f,  24.0f,  24.0f },
		{ 120.0f,  40.0f,  32.0f,  32.0f },
		{ 152.0f,  40.0f,  32.0f,  32.0f },
		{ 184.0f,  40.0f,  32.0f,  32.0f },
		{ 216.0f,  40.0f,  32.0f,  32.0f },
		{  88.0f,  72.0f,  16.0f,  16.0f },
		{ 104.0f,  72.0f,  16.0f,  16.0f },
		{ 120.0f,  72.0f,  16.0f,  16.0f },
		{ 136.0f,  72.0f,  16.0f,  16.0f },
		{ 152.0f,  72.0f,  16.0f,  16.0f },
		{ 168.0f,  72.0f,  16.0f,  16.0f },
		{ 184.0f,  72.0f,  16.0f,  16.0f },
		{ 200.0f,  72.0f,  16.0f,  16.0f },
		{ 216.0f,  72.0f,  16.0f,  16.0f },
		{ 232.0f,  72.0f,  16.0f,  16.0f }
	};
	static EFF_ANIM anim00_tbl[15] =
	{
		{  0,  1 }, {  1,  1 }, {  2,  1 }, {  3,  1 },
		{  4,  1 }, {  5,  1 }, {  6,  1 }, {  7,  1 },
		{  8,  1 }, {  9,  1 }, { 10,  1 }, { 11,  1 },
		{ 12,  1 }, { 13,  1 }, { -1,  0 }
	};
	static EFF_ANIM anim01_tbl[9] =
	{
		{ 14,  1 }, { 15,  1 }, { 16,  1 }, { 17,  1 },
		{ 18,  1 }, { 19,  1 }, { 20,  1 }, { 21,  1 },
		{ -1,  0 }
	};
	static EFF_ANIM anim02_tbl[11] =
	{
		{ 22,  1 }, { 23,  1 }, { 24,  1 }, { 25,  1 },
		{ 26,  1 }, { 27,  1 }, { 28,  1 }, { 29,  1 },
		{ 30,  1 }, { 31,  1 }, { -1,  0 }
	};
	static EFF_ANIM anim03_tbl[11] =
	{
		{  4,  1 }, {  5,  1 }, {  6,  1 }, {  7,  1 },
		{  8,  1 }, {  9,  1 }, { 10,  1 }, { 11,  1 },
		{ 12,  1 }, { 13,  1 }, { -1,  0}
	};
	static EFF_ANIM* anim_tbl[4] =
	{
		anim00_tbl, anim01_tbl, anim02_tbl, anim03_tbl
	};
    
    switch (op->mode0) 
    {                          
    case 0:
        op->tv[0].col = 0xA0C0C0C0;
        op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->flg   |= 0x4180000;
        op->stflg |= 0x20;
        
        op->ani_ct = 0;
        
        op->ct0 = 0;
        op->ct1 = 0;
        op->ct2 = 0; 
        
        op->spd = 1.0f;
        
        op->mode1 = op->type;
        op->mode2 = 0;
        
        op->mode0++;
        break;
    case 1:
        op->ct3--;
        
        if (op->ct3 >= 0) 
        {
            break;
        }
        
        op->ct3 = 0;
        
        op->mode2 = 1;
        
        op->mode0++;
    case 2:
        op->shp_ct *= op->aox;
        
        if ((op->flg & 0x80))
        {
            op->lox += op->xn  * op->shp_ct;
            op->loy += (op->yn * op->shp_ct) + (op->aoy * op->ct3);
            op->loz += op->zn  * op->shp_ct;
        }
        else 
        {
            op->px += op->xn  * op->shp_ct;
            op->py += (op->yn * op->shp_ct) + (op->aoy * op->ct3);
            op->pz += op->zn  * op->shp_ct;
        }
        
        op->ct3++;
        
        if (op->type == 0) 
        {
            if (op->ct3 > 7) 
            {
                op->tv[0].col += 0xF8000000;
                op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col;
            }
        } 
        else if (op->ct3 > 6)
        {
            op->tv[0].col += 0xE0000000;
            op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col;
        }
    }
    
    if (op->mode2 != 0) 
    {
        bhEff_SetSpriteAnime(op, anim_tbl[op->mode1], uvinfo, 0);
    }
}

// 100% matching!
void bhEff_Sub372(O_WRK* op)
{
    static UV_WORK uvinfo[13] = 
	{ 
		{   0.0f,  80.0f,  16.0f,  16.0f },
		{   0.0f, 128.0f,  16.0f,  16.0f },
		{   0.0f,  96.0f,  16.0f,  16.0f },
		{   0.0f, 112.0f,  16.0f,  16.0f },
		{  16.0f,  80.0f,  32.0f,  32.0f },
		{  48.0f,  80.0f,  32.0f,  32.0f },
		{  80.0f,  80.0f,  32.0f,  32.0f },
		{ 112.0f,  80.0f,  32.0f,  32.0f },
		{ 144.0f,  80.0f,  32.0f,  32.0f },
		{ 176.0f,  80.0f,  32.0f,  32.0f },
		{ 208.0f,  80.0f,  32.0f,  32.0f },
		{  16.0f, 112.0f,  32.0f,  32.0f },
		{  48.0f, 112.0f,  32.0f,  32.0f }
	};
	static EFF_ANIM anim00_tbl[9] =
	{
		{  4,  1 }, {  5,  1 }, {  6,  1 }, {  7,  1 },
		{  8,  1 }, {  9,  1 }, { 10,  1 }, { 12,  1 },
		{ -1,  0 }
	};
	static EFF_ANIM* anim_tbl[1] =
	{
		anim00_tbl
	};
    
    switch (op->mode0) 
    {                           
    case 0:
        op->tv[0].col = -1;
        op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col;
        
        op->tex_id = 5;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->flg |= 0x4180000;
        
        op->ct0 = 0;
        op->ct1 = 0;
        op->ct2 = 0;
        
        op->spd = 1.0f;
        
        op->ani_ct = op->mdlver;
        
        op->mode1 = 0;
        op->mode2 = 0;
        op->mode0++;
        break;
    case 1:
        op->ct3--;
        
        if (op->ct3 >= 0) 
        {
            break;
        }
        
        op->ct3 = 0;
        
        op->mode2 = 1;
        op->mode0++;
    case 2:
        op->px += op->xn  * op->shp_ct;
        op->py += (op->yn * op->shp_ct) + (op->aoy * op->ct3);
        op->pz += op->zn  * op->shp_ct;
        
        op->ct3++;
        
        if (op->ct3 >= 5) 
        {
            op->tv[0].col += 0xD0000000;
            op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col;
        }
        
        break;
    }
    
    if (op->mode2 != 0) 
    {
        bhEff_SetSpriteAnime(op, anim_tbl[op->mode1], uvinfo, 0);
    }
}

// 100% matching!
void bhEff_Sub373(O_WRK* op)
{
    static UV_WORK uvinfo[13] = 
	{
		{   0.0f,  80.0f,  16.0f,  16.0f },
		{   0.0f, 128.0f,  16.0f,  16.0f },
		{   0.0f,  96.0f,  16.0f,  16.0f },
		{   0.0f, 112.0f,  16.0f,  16.0f },
		{  16.0f,  80.0f,  32.0f,  32.0f },
		{  48.0f,  80.0f,  32.0f,  32.0f },
		{  80.0f,  80.0f,  32.0f,  32.0f },
		{ 112.0f,  80.0f,  32.0f,  32.0f },
		{ 144.0f,  80.0f,  32.0f,  32.0f },
		{ 176.0f,  80.0f,  32.0f,  32.0f },
		{ 208.0f,  80.0f,  32.0f,  32.0f },
		{  16.0f, 112.0f,  32.0f,  32.0f },
		{  48.0f, 112.0f,  32.0f,  32.0f }
	};
	static EFF_ANIM anim00_tbl[11] =
	{
		{  2,  1 }, {  3,  1 }, {  4,  1}, {  5,  1},
		{  6,  1 }, {  7,  1 }, {  8,  1}, {  9,  1},
		{ 10,  1 }, { 12,  1 }, { -1,  0}
	};
	static EFF_ANIM* anim_tbl[1] =
	{
		anim00_tbl
	};
    
    switch (op->mode0) 
    {                          
    case 0:
        op->tv[0].col = -1;
        op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col;
        
        op->tex_id = 5;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->flg |= 0x4180000;
        
        op->ct0 = 0;
        op->ct1 = 0;
        op->ct2 = 0; 
        
        op->spd = 1.0f; 
        
        op->ani_ct = op->mdlver;
        
        op->mode1 = op->type;
        op->mode2 = 0;
        
        op->mode0++;
        break;
    case 1:
        op->ct3--;
        
        if (op->ct3 >= 0) 
        {
            break;
        }
        
        op->ct3 = 0;
        
        op->mode2 = 1;
        
        op->mode0++;
    case 2:
        op->shp_ct *= op->aox;
        
        if ((op->flg & 0x80)) 
        {
            op->lox += op->xn  * op->shp_ct;
            op->loy += (op->yn * op->shp_ct) + (op->aoy * op->ct3);
            op->loz += op->zn  * op->shp_ct;
        } 
        else 
        {
            op->px += op->xn  * op->shp_ct;
            op->py += (op->yn * op->shp_ct) + (op->aoy * op->ct3);
            op->pz += op->zn  * op->shp_ct;
        }
        
        op->ct3++;
        
        if (op->ct3 >= 5) 
        {
            op->tv[0].col += 0xE0000000;
            op->tv[3].col = op->tv[2].col = op->tv[1].col = op->tv[0].col;
        }
    }
    
    if (op->mode2 != 0) 
    {
        bhEff_SetSpriteAnime(op, anim_tbl[op->mode1], uvinfo, 0);
    }
}

// 
// Start address: 0x250b00
void bhEff_Sub398(O_WRK* op)
{
	int i;
	NJS_POINT3 ps;
	EFF_ANIM* bani;
	UV_WORK* uvp;
	static UV_WORK bl00_uvinfo[16] = 
	{
		{   0.0f,   0.0f,  24.0f,  24.0f },
		{  24.0f,   0.0f,  32.0f,  32.0f },
		{  56.0f,   0.0f,  40.0f,  40.0f },
		{  56.0f,  40.0f,  40.0f,  40.0f },
		{   8.0f,  32.0f,  48.0f,  48.0f },
		{  96.0f,   0.0f,  48.0f,  48.0f },
		{ 144.0f,   0.0f,  48.0f,  48.0f },
		{ 192.0f,   0.0f,  48.0f,  48.0f },
		{  96.0f,  48.0f,  48.0f,  48.0f },
		{ 144.0f,  48.0f,  48.0f,  48.0f },
		{ 192.0f,  48.0f,  48.0f,  48.0f },
		{   0.0f,  96.0f,  48.0f,  64.0f },
		{  48.0f,  96.0f,  48.0f,  64.0f },
		{  96.0f,  96.0f,  48.0f,  64.0f },
		{ 144.0f,  96.0f,  48.0f,  64.0f },
		{ 192.0f,  96.0f,  48.0f,  64.0f }
	};
	static UV_WORK bl01_uvinfo[7] = 
	{
		{   0.0f, 160.0f,  32.0f,  24.0f },
		{  32.0f, 160.0f,  32.0f,  24.0f },
		{  64.0f, 160.0f,  32.0f,  24.0f },
		{  96.0f, 160.0f,  32.0f,  24.0f },
		{ 128.0f, 160.0f,  32.0f,  24.0f },
		{ 160.0f, 160.0f,  32.0f,  24.0f },
		{ 192.0f, 160.0f,  32.0f,  24.0f }
	};
	static UV_WORK bl02_uvinfo[7] = 
	{
		{  0.0f,  184.0f,  24.0f,  24.0f },
		{  24.0f, 184.0f,  24.0f,  24.0f },
		{  48.0f, 184.0f,  24.0f,  24.0f },
		{  72.0f, 184.0f,  24.0f,  24.0f },
		{  96.0f, 184.0f,  24.0f,  24.0f },
		{ 120.0f, 184.0f,  24.0f,  24.0f },
		{ 144.0f, 184.0f,  24.0f,  24.0f }
	};
	static UV_WORK bl03_uvinfo[6] = 
	{
		{   0.0f, 208.0f,  16.0f,  16.0f },
		{  16.0f, 208.0f,  16.0f,  16.0f },
		{  32.0f, 208.0f,  16.0f,  16.0f },
		{  48.0f, 208.0f,  16.0f,  16.0f },
		{  64.0f, 208.0f,  16.0f,  16.0f },
		{  80.0f, 208.0f,  16.0f,  16.0f }
	};
	static UV_WORK bl04_uvinfo[6] = 
	{
		{ 224.0f, 160.0f,   8.0f,   8.0f },
		{ 224.0f, 168.0f,   8.0f,   8.0f },
		{ 224.0f, 176.0f,   8.0f,   8.0f },
		{ 232.0f, 160.0f,   8.0f,   8.0f },
		{ 232.0f, 168.0f,   8.0f,   8.0f },
		{ 232.0f, 176.0f,   8.0f,   8.0f }
	};
	static UV_WORK bl05_uvinfo[6] = 
	{
		{ 240.0f,  0.0f,   16.0f,  24.0f },
		{ 240.0f,  24.0f,  16.0f,  24.0f },
		{ 240.0f,  48.0f,  16.0f,  24.0f },
		{ 240.0f,  72.0f,  16.0f,  24.0f },
		{ 240.0f,  96.0f,  16.0f,  24.0f },
		{ 240.0f, 120.0f,  16.0f,  24.0f }
	};
	static UV_WORK bl06_uvinfo[6] = 
	{
		{   0.0f, 224.0f,  16.0f,  24.0f },
		{  16.0f, 224.0f,  16.0f,  24.0f },
		{  32.0f, 224.0f,  16.0f,  24.0f },
		{  48.0f, 224.0f,  16.0f,  24.0f },
		{  64.0f, 224.0f,  16.0f,  24.0f },
		{  80.0f, 224.0f,  16.0f,  24.0f }
	};
	static UV_WORK bl07_uvinfo[5] = 
	{
		{  96.0f, 208.0f,   8.0f,  16.0f },
		{ 104.0f, 208.0f,   8.0f,  16.0f },
		{ 112.0f, 208.0f,   8.0f,  16.0f },
		{ 120.0f, 208.0f,   8.0f,  16.0f },
		{ 128.0f, 208.0f,   8.0f,  16.0f }
	};
	static UV_WORK bl08_uvinfo[5] = 
	{
		{  96.0f, 224.0f,   8.0f,  16.0f },
		{ 104.0f, 224.0f,   8.0f,  16.0f },
		{ 112.0f, 224.0f,   8.0f,  16.0f },
		{ 120.0f, 224.0f,   8.0f,  16.0f },
		{ 128.0f, 224.0f,   8.0f,  16.0f }
	};
	static UV_WORK bl09_uvinfo[5] = 
	{
		{ 168.0f, 184.0f,  16.0f,  24.0f },
		{ 184.0f, 184.0f,  16.0f,  24.0f },
		{ 200.0f, 184.0f,  16.0f,  24.0f },
		{ 216.0f, 184.0f,  16.0f,  24.0f },
		{ 232.0f, 184.0f,  16.0f,  24.0f }
	};
	static UV_WORK bl10_uvinfo[5] =
	 {
		{  96.0f, 240.0f,   8.0f,  16.0f },
		{ 104.0f, 240.0f,   8.0f,  16.0f },
		{ 112.0f, 240.0f,   8.0f,  16.0f },
		{ 120.0f, 240.0f,   8.0f,  16.0f },
		{ 128.0f, 240.0f,   8.0f,  16.0f }
	};
	static UV_WORK* blood_uvinfo[11] = 
	{
		bl00_uvinfo, bl01_uvinfo, bl02_uvinfo, bl03_uvinfo,
		bl04_uvinfo, bl05_uvinfo, bl06_uvinfo, bl07_uvinfo,
		bl08_uvinfo, bl09_uvinfo, bl10_uvinfo
	};
	static EFF_ANIM blanim00_tbl[13] = 
	{
		{   1, 1 }, {   3, 1 }, {   5, 1 }, {   7, 1 },
		{   8, 2 }, {   9, 2 }, {  10, 2 }, {  11, 2 },
		{  12, 2 }, {  13, 2 }, {  14, 2 }, {  15, 2 },
		{  -1, 0 }
	};
	static EFF_ANIM blanim01_tbl[9] = 
	{
		{ 100, 3 }, {   0, 2 }, {   1, 2 }, {   2, 2 },
		{   3, 2 }, {   4, 2 }, {   5, 2 }, {   6, 2 },
		{  -1, 0 }
	};
	static EFF_ANIM blanim03_tbl[8] = 
	{
		{ 100, 4 }, {   0, 2 }, {   1, 2 }, {   2, 2 },
		{   3, 2 }, {   4, 2 }, {   5, 2 }, {  -1, 0 }
	};
	static EFF_ANIM blanim07_tbl[7] = 
	{
		{ 100, 8 }, {   0, 2 }, {   1, 2 }, {   2, 2 },
		{   3, 2 }, {   4, 2 }, {  -1, 0 }
	};
	EFF_ANIM* blanim_tbl[11] = 
	{  
		blanim00_tbl, blanim01_tbl, blanim01_tbl, blanim03_tbl,
		blanim03_tbl, blanim03_tbl, blanim03_tbl, blanim07_tbl,
		blanim07_tbl, blanim07_tbl, blanim07_tbl
	};
	float pos_tbl[11][2] = 
	{
		{   0.0f,   0.0f }, { -68.0f, -48.0f }, {  64.0f, -72.0f }, { -40.0f, -92.0f },
		{  40.0f,   8.0f }, { -48.0f,  12.0f }, {  60.0f, -12.0f }, {  16.0f,  36.0f },
		{ -32.0f,  12.0f }, { -64.0f, -24.0f }, {  -8.0f, -88.0f }
	};
	// Line 3600, Address: 0x250b00, Func Offset: 0
	// Line 3737, Address: 0x250b14, Func Offset: 0x14
	// Line 3600, Address: 0x250b1c, Func Offset: 0x1c
	// Line 3737, Address: 0x250b20, Func Offset: 0x20
	// Line 3751, Address: 0x250b34, Func Offset: 0x34
	// Line 3763, Address: 0x250b38, Func Offset: 0x38
	// Line 3737, Address: 0x250b3c, Func Offset: 0x3c
	// Line 3751, Address: 0x250b40, Func Offset: 0x40
	// Line 3737, Address: 0x250b44, Func Offset: 0x44
	// Line 3751, Address: 0x250b4c, Func Offset: 0x4c
	// Line 3737, Address: 0x250b50, Func Offset: 0x50
	// Line 3751, Address: 0x250b54, Func Offset: 0x54
	// Line 3763, Address: 0x250b84, Func Offset: 0x84
	// Line 3766, Address: 0x250ba0, Func Offset: 0xa0
	// Line 3767, Address: 0x250bac, Func Offset: 0xac
	// Line 3769, Address: 0x250bb0, Func Offset: 0xb0
	// Line 3772, Address: 0x250bb4, Func Offset: 0xb4
	// Line 3776, Address: 0x250bb8, Func Offset: 0xb8
	// Line 3783, Address: 0x250bbc, Func Offset: 0xbc
	// Line 3767, Address: 0x250bc0, Func Offset: 0xc0
	// Line 3769, Address: 0x250bcc, Func Offset: 0xcc
	// Line 3770, Address: 0x250bd0, Func Offset: 0xd0
	// Line 3771, Address: 0x250bd4, Func Offset: 0xd4
	// Line 3772, Address: 0x250bd8, Func Offset: 0xd8
	// Line 3773, Address: 0x250bdc, Func Offset: 0xdc
	// Line 3774, Address: 0x250be0, Func Offset: 0xe0
	// Line 3775, Address: 0x250be4, Func Offset: 0xe4
	// Line 3776, Address: 0x250be8, Func Offset: 0xe8
	// Line 3777, Address: 0x250bec, Func Offset: 0xec
	// Line 3778, Address: 0x250bf0, Func Offset: 0xf0
	// Line 3779, Address: 0x250bf4, Func Offset: 0xf4
	// Line 3780, Address: 0x250bf8, Func Offset: 0xf8
	// Line 3783, Address: 0x250bfc, Func Offset: 0xfc
	// Line 3784, Address: 0x250c00, Func Offset: 0x100
	// Line 3786, Address: 0x250c08, Func Offset: 0x108
	// Line 3787, Address: 0x250c10, Func Offset: 0x110
	// Line 3795, Address: 0x250c14, Func Offset: 0x114
	// Line 3786, Address: 0x250c18, Func Offset: 0x118
	// Line 3787, Address: 0x250c20, Func Offset: 0x120
	// Line 3788, Address: 0x250c24, Func Offset: 0x124
	// Line 3789, Address: 0x250c2c, Func Offset: 0x12c
	// Line 3790, Address: 0x250c34, Func Offset: 0x134
	// Line 3791, Address: 0x250c3c, Func Offset: 0x13c
	// Line 3792, Address: 0x250c40, Func Offset: 0x140
	// Line 3793, Address: 0x250c44, Func Offset: 0x144
	// Line 3794, Address: 0x250c48, Func Offset: 0x148
	// Line 3795, Address: 0x250c4c, Func Offset: 0x14c
	// Line 3796, Address: 0x250c50, Func Offset: 0x150
	// Line 3797, Address: 0x250c54, Func Offset: 0x154
	// Line 3798, Address: 0x250c58, Func Offset: 0x158
	// Line 3801, Address: 0x250c64, Func Offset: 0x164
	// Line 3805, Address: 0x250c70, Func Offset: 0x170
	// Line 3807, Address: 0x250c7c, Func Offset: 0x17c
	// Line 3805, Address: 0x250c80, Func Offset: 0x180
	// Line 3806, Address: 0x250c8c, Func Offset: 0x18c
	// Line 3807, Address: 0x250ca0, Func Offset: 0x1a0
	// Line 3808, Address: 0x250cb4, Func Offset: 0x1b4
	// Line 3809, Address: 0x250cf8, Func Offset: 0x1f8
	// Line 3810, Address: 0x250d10, Func Offset: 0x210
	// Line 3816, Address: 0x250d24, Func Offset: 0x224
	// Line 3810, Address: 0x250d2c, Func Offset: 0x22c
	// Line 3816, Address: 0x250d30, Func Offset: 0x230
	// Line 3810, Address: 0x250d34, Func Offset: 0x234
	// Line 3811, Address: 0x250d44, Func Offset: 0x244
	// Line 3812, Address: 0x250d5c, Func Offset: 0x25c
	// Line 3813, Address: 0x250d74, Func Offset: 0x274
	// Line 3814, Address: 0x250d8c, Func Offset: 0x28c
	// Line 3815, Address: 0x250da4, Func Offset: 0x2a4
	// Line 3816, Address: 0x250dbc, Func Offset: 0x2bc
	// Line 3825, Address: 0x250dd4, Func Offset: 0x2d4
	// Line 3831, Address: 0x250de4, Func Offset: 0x2e4
	// Line 3834, Address: 0x250de8, Func Offset: 0x2e8
	// Line 3835, Address: 0x250dec, Func Offset: 0x2ec
	// Line 3837, Address: 0x250df0, Func Offset: 0x2f0
	// Line 3834, Address: 0x250df4, Func Offset: 0x2f4
	// Line 3835, Address: 0x250e00, Func Offset: 0x300
	// Line 3837, Address: 0x250e08, Func Offset: 0x308
	// Line 3840, Address: 0x250e14, Func Offset: 0x314
	// Line 3841, Address: 0x250e1c, Func Offset: 0x31c
	// Line 3840, Address: 0x250e20, Func Offset: 0x320
	// Line 3841, Address: 0x250e28, Func Offset: 0x328
	// Line 3844, Address: 0x250e3c, Func Offset: 0x33c
	// Line 3847, Address: 0x250e44, Func Offset: 0x344
	// Line 3848, Address: 0x250e60, Func Offset: 0x360
	// Line 3850, Address: 0x250e70, Func Offset: 0x370
	// Line 3852, Address: 0x250e7c, Func Offset: 0x37c
	// Line 3853, Address: 0x250ea4, Func Offset: 0x3a4
	// Line 3856, Address: 0x250ec4, Func Offset: 0x3c4
	// Line 3857, Address: 0x250ecc, Func Offset: 0x3cc
	// Line 3859, Address: 0x250ed8, Func Offset: 0x3d8
	// Line 3862, Address: 0x250ee0, Func Offset: 0x3e0
	// Line 3859, Address: 0x250ee4, Func Offset: 0x3e4
	// Line 3860, Address: 0x250eec, Func Offset: 0x3ec
	// Line 3865, Address: 0x250ef0, Func Offset: 0x3f0
	// Line 3860, Address: 0x250ef4, Func Offset: 0x3f4
	// Line 3862, Address: 0x250ef8, Func Offset: 0x3f8
	// Line 3863, Address: 0x250f14, Func Offset: 0x414
	// Line 3865, Address: 0x250f28, Func Offset: 0x428
	// Line 3866, Address: 0x250f30, Func Offset: 0x430
	// Line 3867, Address: 0x250f44, Func Offset: 0x444
	// Line 3868, Address: 0x250f58, Func Offset: 0x458
	// Line 3871, Address: 0x250f68, Func Offset: 0x468
	// Line 3868, Address: 0x250f6c, Func Offset: 0x46c
	// Line 3871, Address: 0x250f78, Func Offset: 0x478
	// Line 3868, Address: 0x250f80, Func Offset: 0x480
	// Line 3869, Address: 0x250f8c, Func Offset: 0x48c
	// Line 3871, Address: 0x250fac, Func Offset: 0x4ac
	// Line 3873, Address: 0x250fb4, Func Offset: 0x4b4
	// Line 3875, Address: 0x250fc0, Func Offset: 0x4c0
	// Line 3873, Address: 0x250fcc, Func Offset: 0x4cc
	// Line 3874, Address: 0x250fd4, Func Offset: 0x4d4
	// Line 3875, Address: 0x250fe0, Func Offset: 0x4e0
	// Line 3876, Address: 0x250ff8, Func Offset: 0x4f8
	// Line 3877, Address: 0x251010, Func Offset: 0x510
	// Line 3878, Address: 0x251018, Func Offset: 0x518
	// Line 3879, Address: 0x251020, Func Offset: 0x520
	// Line 3880, Address: 0x251028, Func Offset: 0x528
	// Line 3883, Address: 0x251030, Func Offset: 0x530
	// Line 3885, Address: 0x25103c, Func Offset: 0x53c
	// Line 3886, Address: 0x251064, Func Offset: 0x564
	// Line 3891, Address: 0x251088, Func Offset: 0x588
	// Line 3893, Address: 0x251098, Func Offset: 0x598
	// Line 3894, Address: 0x2510a4, Func Offset: 0x5a4
	// Line 3896, Address: 0x2510b4, Func Offset: 0x5b4
	// Line 3897, Address: 0x2510b8, Func Offset: 0x5b8
	// Line 3900, Address: 0x2510c4, Func Offset: 0x5c4
	// Func End, Address: 0x2510e0, Func Offset: 0x5e0
	scePrintf("bhEff_Sub398 - UNIMPLEMENTED!\n");
}

// 100% matching!
static O_WRK* bhEff_AllocOwork()
{
    O_WRK* op;
    int i;

    op = eff;
    
    for (i = 0; i < 512; i++, op++) 
    {
        if (!(op->flg & 0x3))
        {
            npSetMemory((unsigned char*)op, sizeof(*op), 0);
            
            op->flg = 0x2;
            
            return op;
        }
    }
    
    return NULL;
}

// 100% matching!
static void bhEff_PtclSpriteDraw(O_WRK* op)
{
    D_WORK* dtbl;      
    NJS_POINT3* vtx_p; 
    float* size;      
    char atr[192];    
    int i;             
    
    dtbl = (D_WORK*)op->exp0;
    
    njGetSystemAttr((NJS_SYS_ATTR*)&atr);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 10);
    
    njTextureFilterMode(0);
    
    njSetMatrix(NULL, cam.mtx);
    njSetTexture(op->txp[0]);
    
    vtx_p = (NJS_POINT3*)dtbl->exp0;
    size  = (float*)dtbl->exp1;
    
    njPtclSpriteStart(op->tex_id, op->tv->col, 1);
    
    for (i = 0; i < dtbl->num; i++) 
    {
        njPtclDrawSprite(vtx_p, 1, *size, *size);
        
        vtx_p++; 
        size++;
    }
    
    njPtclSpriteEnd();
    
    njSetSystemAttr((NJS_SYS_ATTR*)&atr);
}

// 100% matching!
static void bhEff_LineDraw(O_WRK* op) 
{
    D_WORK* dtbl;           
    NJS_POINT3* vtx_p, *vtx_p2;       
    char atr[192];          
    int i;                 
    NJS_POLYGON_VTX poly[3]; 

    dtbl = (D_WORK*)op->exp0;
    
    njGetSystemAttr((NJS_SYS_ATTR*)&atr);
    
    njColorBlendingMode(0, op->bl_src);
    njColorBlendingMode(1, op->bl_dst);
    
    njFogDisable();
    
    njSetMatrix(NULL, cam.mtx);
    
    vtx_p  = (NJS_POINT3*)dtbl->exp0;
    vtx_p2 = (NJS_POINT3*)dtbl->exp1;
    
    poly[0].col = op->tv[0].col;
    poly[1].col = op->tv[0].col;
    poly[2].col = op->tv[1].col;
    
    for (i = 0; i < dtbl->num; i++) 
    {
        poly[0].x = vtx_p->x;
        poly[0].y = vtx_p->y;
        poly[0].z = vtx_p->z;
        
        poly[2].x = vtx_p2->x;
        poly[2].y = vtx_p2->y;
        poly[2].z = vtx_p2->z;
        
        poly[1].x = 0.2f + vtx_p->x;
        poly[1].y = 0.3f + vtx_p->y;
        poly[1].z = 0.2f + vtx_p->z;
        
        njDrawPolygon3DEx(poly, 3, 1);
        
        vtx_p++; 
        vtx_p2++; 
    }
    
    njFogEnable();
    
    njSetSystemAttr((NJS_SYS_ATTR*)&atr);
}

// 100% matching!
static void bhEff_SetSprite(O_WRK* op, UV_WORK* uvp, int mode)
{
    op->sx = op->sxb * (uvp->xs / 100.0f);
    op->sy = op->syb * (uvp->ys / 100.0f);
    
    op->tv[0].u = uvp->u / 255.0f;
    op->tv[0].v = uvp->v / 255.0f;
    
    op->tv[3].u = ((uvp->u + uvp->xs) - 1.0f) / 255.0f;
    op->tv[3].v = ((uvp->v + uvp->ys) - 1.0f) / 255.0f;
    
    op->tv[1].u = op->tv[3].u;
    op->tv[1].v = op->tv[0].v;
    
    op->tv[2].u = op->tv[0].u;
    op->tv[2].v = op->tv[3].v;
    
    if (op->flg != 0) 
    {
        if (mode == 0) 
        {
            sys->ef_trs[sys->ef_trsn] = op;
            
            sys->ef_trsn++;
        }
        else 
        {
            sys->ef_fnc[sys->ef_fncn] = op;
            
            sys->ef_fncn++;
        }
    }
}

// 99.79% matching (matches on NGC)
static void bhEff_SetSpriteAnime(O_WRK* op, EFF_ANIM* eff_anim, UV_WORK* uvp, int mode)
{
    EFF_ANIM* anim_p;
    
    anim_p = &eff_anim[op->ct1];
    
    if (anim_p->ptrn == -1)
    {
        op->flg = 0;
        return;
    }
    
    if (anim_p->ptrn == -2)
    {
        op->ct1 = anim_p->timer;
        
        anim_p = &eff_anim[op->ct1];
    }
    
    op->ct0++;
    
    if (anim_p->timer == op->ct0) 
    {
        op->ct0 = 0;
        
        if (op->spd != 0) 
        {
            op->ct1++;
        }
    }
    
    if (anim_p->ptrn < 100)
    {
        bhEff_SetSprite(op, &uvp[anim_p->ptrn], mode);
    }
}

// 100% matching!
static void bhEff_3DSpriteDraw(O_WRK* op)
{
    unsigned int tnm;
    
    njPushMatrixEx();
    
    if (((op->flg == 0) || ((op->flg & 0x1000000)) || ((op->stflg & 0x1000000))) || ((sys->gm_flg & 0x4000)) && ((op->mdflg & 0x40)))
    {
        njPopMatrixEx();
        return;
    }
    
    if ((op->flg & 0x20000000))
    {
        njTextureFilterMode(0);
    } 
    else
    {
        njTextureFilterMode(1);
    }
    
    if (!(op->stflg & 0x20)) 
    {
        njSetTexture(&sys->ef_tlist);
        
        tnm = sys->ef_tn[op->tex_id] + op->ani_ct;
        
        njSetTextureNum(tnm);
    } 
    else 
    {
        njSetTexture(op->txp[0]);
        
        tnm = op->tex_id + op->ani_ct;
        
        njSetTextureNum(tnm);
    }
    
    if ((op->flg & 0x10000000)) 
    {
        njSetPaletteBankNum(tnm, op->bank);
    }
    
    njPushMatrixEx();
    
    if ((!(op->flg & 0x80)) || ((op->flg & 0x200000)))
    {
        njUnitMatrix(NULL);
        
        njTranslateEx((NJS_VECTOR*)&op->px);
        njRotateEx(&op->ax, 0);
        
        njGetMatrix(op->mtx);
    }
    else 
    {
        njSetMatrix(op->mtx, &((O_WRK*)op->lkwkp)->mlwP->owP[op->lkono].mtx);
        
        njTranslate(op->mtx, op->lox, op->loy, op->loz);
        njRotateXYZ(op->mtx, op->ax,  op->ay,  op->az);
    }
    
    njPopMatrixEx();
    
    njMultiMatrix(NULL, op->mtx);
    
    if ((op->flg & 0x100000)) 
    {
        njUnitRotPortion(NULL);
        
        njRotateZ(NULL, op->az);
    }
    
    njScaleEx((NJS_VECTOR*)&op->sx);
    
    njColorBlendingMode(0, op->bl_src);
    njColorBlendingMode(1, op->bl_dst);
    
    njFogDisable();
    
    njDrawTexture3DEx(op->tvp, op->pn, 1);
    
    njFogEnable();
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njPopMatrixEx();
}

// 100% matching!
static void bhEff_ModelDraw(O_WRK* op)
{
    NJS_TEXNAME* tnp;
    ML_WORK* mlp;
    
    njCnkSetSimpleLightColor(1.0f, 1.0f, 1.0f);
    njCnkSetSimpleLightIntensity(1.0f, 0.8f);
    njCnkSetSimpleLight(0, 0.3f, 0.7f);
    
    njPushMatrixEx();
    
    op->flg = op->flg;
    
    if ((((op->flg & 0x1000000)) || ((op->stflg & 0x1000000))) || (((sys->gm_flg & 0x4000)) && ((op->mdflg & 0x40)))) 
    {
        njPopMatrixEx();
        return;
    }
    
    if ((op->flg & 0x20000000)) 
    {
        njTextureFilterMode(0);
    }
    else 
    {
        njTextureFilterMode(1);
    }
    
    mlp = op->mlwP;
    
    if (!(op->stflg & 0x20)) 
    {
        tnp = sys->ef_tlist.textures;
        
        sys->ef_tlist.textures = &tnp[op->tex_id + op->ani_ct];
        
        njSetTexture(&sys->ef_tlist);
        njSetTextureNum(0);
    } 
    else 
    {
        njSetTexture(op->txp[0]);
        njSetTextureNum(0);
    }
    
    njPushMatrixEx();
    
    if (((op->flg & 0x200000)) || (!(op->flg & 0x80))) 
    {
        njUnitMatrix(NULL);
        
        njTranslateEx((NJS_VECTOR*)&op->px);
        njRotateEx(&op->ax, 0);
        
        njGetMatrix(op->mtx);
    } 
    else 
    {
        njSetMatrix(op->mtx, &((O_WRK*)op->lkwkp)->mlwP->owP[op->lkono].mtx);
        
        njTranslate(op->mtx, op->lox, op->loy, op->loz);
        njRotateXYZ(op->mtx, op->ax,  op->ay,  op->az);
    }
    
    njPopMatrixEx();
    
    njMultiMatrix(NULL, op->mtx);
    
    njScaleEx((NJS_VECTOR*)&op->sx);
    
    if (op->flr_no != 0) 
    {
        npSetAllMatColor(&mlp->objP[op->mdlver], 1, op->tv->col);
    }
    
    njCnkSimpleMultiDrawModel(mlp->objP[op->mdlver].model);
    
    if (!(op->stflg & 0x20)) 
    {
        sys->ef_tlist.textures = tnp;
    }
            
    njPopMatrixEx();
}
