#include "../../../ps2/veronica/prog/effsub3.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw.h"
#include "../../../ps2/veronica/prog/ps2_NaFog.h"
#include "../../../ps2/veronica/prog/ps2_NaGraphics3D.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaMem.h"
#include "../../../ps2/veronica/prog/ps2_NaSystem.h"
#include "../../../ps2/veronica/prog/ps2_NaTextureFunction.h"
#include "../../../ps2/veronica/prog/ps2_NinjaCnk.h"
#include "../../../ps2/veronica/prog/ps2_NinjaPtcl.h"

static unsigned int owk_scn_noG;

static void (*FuncTbl[4])(O_WRK* oP) = 
{
	NULL,
	bhEff_PtclSpriteDrawB,
	bhEff_PtclLineDraw,
	NULL
};

EFF302PRM_WORK Eff302Prm[20] = 
{
    { 1.0f, -0.08f,  20.0f, 0.5f, 0.5f,  0.025f, 16, {  0,  2,  4,  6,  8, 10 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.4f,   0.0f,  45.0f, 1.0f, 1.0f,  0.025f, 20, {  0,  1,  8,  9, 16, 17 }, { 0.0f, -0.06533334, 0.0f } },
    { 1.2f, -0.08f,  10.0f, 0.5f, 0.5f,  0.025f, 16, {  0,  0,  0,  0,  0,  0 }, { 0.0f, -0.03266667, 0.0f } },
    { 1.0f, -0.05f,  60.0f, 0.5f, 0.5f,  0.025f, 24, {  0,  0,  0,  0,  0,  0 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.4f,   0.0f,  45.0f, 1.0f, 1.0f,  0.025f, 20, { -1, -1,  0,  0,  1,  1 }, { 0.0f, -0.06533334, 0.0f } },
    { 0.5f, -0.05f,  55.0f, 0.1f, 0.8f,   0.01f,  5, { -1, -1, -1, -1, -1,  0 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.6f, -0.05f,  50.0f, 0.1f, 0.8f,   0.02f,  7, { -1, -1, -1, -1, -1,  0 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.7f, -0.05f,  45.0f, 0.1f, 0.8f,   0.03f,  9, { -1, -1, -1, -1, -1,  0 }, { 0.0f, -0.03266667, 0.0f } },
    { 1.0f, -0.01f,  20.0f, 0.1f, 0.8f,   0.03f, 12, { -1, -1, -1, -1,  0,  1 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.8f, -0.05f,  20.0f, 0.5f, 0.5f,  0.025f, 12, { -1, -1, -1, -1,  0,  0 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.3f,   0.0f, 360.0f, 1.0f, 1.0f,  0.025f, 16, {  0,  0,  0,  0,  0,  0 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.3f,   0.0f,  45.0f, 0.0f, 1.0f,  0.025f,  7, { -1, -1, -1, -1, -1,  0 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.2f,   0.0f, 360.0f, 1.0f, 1.0f,  0.025f, 12, {  0,  0,  0,  0,  0,  0 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.3f,   0.0f, 180.0f, 0.5f, 0.5f,  0.025f, 16, {  0,  2,  4,  6,  8, 10 }, { 0.0f, -0.03266667, 0.0f } },
    { 1.0f, -0.08f, 360.0f, 1.0f, 1.0f,  0.035f,  9, {  0,  0,  2,  2,  5,  5 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.4f,   0.0f, 150.0f, 1.0f, 1.0f,   0.04f, 16, {  0,  0,  2,  2,  5,  5 }, { 0.0f, -0.03266667, 0.0f } },
    { 0.4f, -0.02f,  60.0f, 1.0f, 1.0f,   0.04f, 10, { -1,  0,  0,  0,  1,  1 }, { 0.0f, -0.016333334,0.0f } },
    { 0.5f, -0.04f,  45.0f, 1.0f, 1.0f,  0.045f, 10, {  0,  0,  1,  2,  3,  5 }, { 0.0f, -0.06533334, 0.0f } },
    { 0.8f, -0.05f,  60.0f, 0.5f, 1.0f,   0.05f, 12, {  0,  0,  1,  1,  2,  3 }, { 0.0f, -0.098000005,0.0f } },
    { 0.4f,   0.0f,  60.0f, 0.5f, 0.5f, 0.0055f, 40, { -1, -1,  0,  0,  1,  1 }, { 0.0f, -0.02f,      0.0f } }
};

static const UV_WORK Tex5uv[9] = 
{
    { 0.09375f, 0.15625f, 0.12500f, 0.12500f },   
    { 0.46875f, 0.00000f, 0.15625f, 0.15625f },   
    { 0.37500f, 0.15625f, 0.15625f, 0.15625f },   
    { 0.00000f, 0.00000f, 0.15625f, 0.15625f },   
    { 0.00000f, 0.15625f, 0.09375f, 0.09375f },   
    { 0.21875f, 0.15625f, 0.15625f, 0.15625f },   
    { 0.65625f, 0.84375f, 0.12500f, 0.15625f },   
    { 0.81250f, 0.59375f, 0.18750f, 0.18750f },   
    { 0.78125f, 0.78125f, 0.21875f, 0.21875f }   
};

// 100% matching!
static O_WRK* AllocOwork()
{
    O_WRK* oP;
    int o_no;

    o_no = owk_scn_noG;
    
    for (oP = &eff[o_no]; o_no < 512; o_no++, oP++) 
    {
        if (!(oP->flg & 0x3))
        {
            npSetMemory((unsigned char*)oP, sizeof(*oP), 0);
            
            oP->flg = 0x2;
            
            owk_scn_noG = o_no + 1;
            
            return oP;
        }
    }
    
    return NULL;
}

// 100% matching!
O_WRK* AllocOworkOne()
{
    O_WRK* oP;
    int o_no;

    o_no = 512;

    oP = eff;
    
    for ( ; o_no > 0; o_no--, oP++) 
    {
        if (!(oP->flg & 0x3))
        {
            npSetMemory((unsigned char*)oP, sizeof(*oP), 0);
            
            oP->flg = 0x2;
            
            return oP;
        }
    }
    
    return NULL;
}

// 100% matching!
void bhClrEff_RY()
{
    O_WRK* oP;
	int i;

    oP = eff;
    
    for (i = 0; i < 512; i++, oP++) 
    {
        if ((oP->flg & 0x1))
        {
            switch (oP->id) 
            {                     
            case 301:
                oP->flg = 0;
                break;
            case 302:
                *(int*)oP->exp1 = 0;
                *(int*)oP->exp0 = 0;
                
                oP->flg = 0;
                break;
            }
        }
    }
}

// 100% matching!
int bhSetBloodPoolLnk(BH_PWORK* ewP, NJS_POINT3* posP, int ay, BP_WORK* tabP, int pal_bnk)
{
    O_WRK* o0P, *o1P;    
    int eff_no;     
    E17_WORK* e17P; 
    
    if ((o0P = AllocOworkOne()) != NULL) 
    {
        if ((o1P = AllocOworkOne()) != NULL)
        {
            e17P = (E17_WORK*)o1P;

			eff_no = 300;
            
            o0P->flg = 0x200001;
            
            o0P->id   = eff_no;
            o0P->type = 0;
            
            o0P->tex_id = 17;
            
            o0P->mdlver = 0;
            
            o0P->flr_no = 0;
            
            *(NJS_POINT3*)&o0P->px = *posP;
            
            o0P->py += 0.01f;
            
            njAddVector((NJS_VECTOR*)&o0P->px, &tabP->off_pos);
            
            o0P->py += 0.001f * sys->bl_ct;
            
            sys->bl_ct = (sys->bl_ct + 1) & 0x1FF;
            
            o0P->lox = o0P->loy = o0P->loz = 0;
            o0P->sx  = o0P->sy  = o0P->sz  = 1.0f;
            o0P->ax  = o0P->ay  = o0P->az  = 0;
            
            o0P->mlwP = &sys->efm[300];
            
            o0P->lkwkp = (unsigned char*)ewP;
            o0P->lkono = 0;
            
            o0P->mtx = (NJS_MATRIX*)o0P->mtxbuf;
            
            o0P->pvp = o0P->pv;
            o0P->tvp = e17P->tv_buf;
            
            o0P->pn = 16;
            
            o0P->bl_src = 8;
            o0P->bl_dst = 6;
            
            o0P->ani_ct = pal_bnk;
            
            o0P->exp0 = (unsigned char*)e17P;
            
            o0P->mode0 = 0;
            
            e17P->eff_dir = ay;
            
            e17P->srd_dir = tabP->srd_dir;
            e17P->srd_pos = tabP->srd_pos;
            
            e17P->bld_spd = tabP->bld_spd;
            
            e17P->srt_spd[0] = tabP->srt_spd[0];
            e17P->srt_spd[1] = tabP->srt_spd[1];
            e17P->srt_spd[2] = tabP->srt_spd[2];
            e17P->srt_spd[3] = tabP->srt_spd[3];
            e17P->srt_spd[4] = tabP->srt_spd[4];
            
            e17P->srt_vtx[0] = tabP->srt_dir[0];
            e17P->srt_vtx[1] = tabP->srt_dir[1];
            e17P->srt_vtx[2] = tabP->srt_dir[2];
            e17P->srt_vtx[3] = tabP->srt_dir[3];
            e17P->srt_vtx[4] = tabP->srt_dir[4];
            
            return 1;
        }
        
        o0P->flg = 0;
    }
    
    return 0;
}

// 99.53% matching
void bhEff300(O_WRK* oP)
{
    static const int VtxTbl[16] = 
    {
        0, 1, 3, 5, 7, 9, 11, 13, 15, 14, 12, 10, 8, 6, 4, 2
    };
    E17_WORK* e17P; 

    e17P = (E17_WORK*)oP->exp0;

    switch (oP->mode0) 
    {
    case 0:
    {
        NJS_POINT3 center;    
        float spd;           
        int ang;            
        int tmp; // not from DWARF
        NJS_TEXTURE_VTX* tvP;
        NJS_POINT3* spdP;    
        int i;               
        
        spd = e17P->srd_pos * e17P->bld_spd;
        ang = e17P->srd_dir;
        
        center.x = spd * -njCos(ang);
        center.y = 0;
        center.z = spd * njSin(ang);

        tvP  = &e17P->tv_buf[0];
        spdP = &e17P->tv_spd[0];
        
        ang = e17P->eff_dir + 16384;
        
        for (i = 0; i < 16; i++, tvP++, spdP++) 
        {
            tmp = 4096 * i;
            
            spd = e17P->bld_spd;
            
            if (!(i & 0x1)) 
            {
                tmp *= -1;
            }
            
            ang += tmp;
            
            tvP->x = tvP->y = tvP->z = 0;
            
            tvP->u = 0.5f + (0.5f * njCos(ang));
            tvP->v = 0.5f + (0.5f * njSin(ang));
            
            tvP->col = 0xF0808080;
            
            spdP->x = spd * njCos(ang);
            spdP->y = 0;
            spdP->z = spd * -njSin(ang);
            
            njSubVector(spdP, &center);
        }
        
        oP->ct0 = 0;
        
        oP->mode0++;
        break;
    }
    case 1:
    {
        int ang;             
        int tmp;             
        float spd;           
        NJS_POINT3* addP;    
        NJS_TEXTURE_VTX* tvP; 
        int i;               
        int srt_no;           
        
        addP = &e17P->tv_spd[0];
        tvP  = &e17P->tv_buf[0];
        
        for (i = 0; i < 16; ) 
        {
            njAddVector((NJS_VECTOR*)&tvP->x, addP);
            
            addP->x *= 0.98f;
            addP->z *= 0.98f;
            
            i++;
            tvP++;
            addP++;
        }
        
        for (srt_no = 0; srt_no < 5; srt_no++) 
        {
            float spd;     
            
            spd = e17P->srt_spd[srt_no];
            
            if (spd != 0) 
            {
                NJS_POINT3 add;
                NJS_TEXTURE_VTX* tvP; 
                int pnt;              
                NJS_POINT3 pos;       

                tvP = e17P->tv_buf;
                
                pnt = e17P->srt_vtx[srt_no];
                
                add = e17P->tv_spd[VtxTbl[pnt]];
                
                pos = *(NJS_POINT3*)&oP->px;
                
                njAddVector(&pos, (NJS_VECTOR*)&tvP[VtxTbl[pnt & 0xF]].x);
                
                if (bhCheckWallType(&pos, 0, 0.2f, 0) != NULL) 
                {
                    e17P->srt_spd[srt_no] = 0;
                } 
                else 
                {
                    add.x *= spd;
                    add.z *= spd;
                    
                    njAddVector((NJS_VECTOR*)&tvP[VtxTbl[pnt & 0xF]].x,       &add);
                    
                    add.x *= 0.9f;
                    add.z *= 0.9f;
                    
                    njAddVector((NJS_VECTOR*)&tvP[VtxTbl[(pnt + 1) & 0xF]].x, &add);
                    njAddVector((NJS_VECTOR*)&tvP[VtxTbl[(pnt - 1) & 0xF]].x, &add);
                    
                    add.x *= 0.4f;
                    add.z *= 0.4f;
                    
                    njAddVector((NJS_VECTOR*)&tvP[VtxTbl[(pnt + 2) & 0xF]].x, &add);
                    njAddVector((NJS_VECTOR*)&tvP[VtxTbl[(pnt - 2) & 0xF]].x, &add);
                    
                    add.x *= 0.2f;
                    add.z *= 0.2f;
                    
                    njAddVector((NJS_VECTOR*)&tvP[VtxTbl[(pnt + 3) & 0xF]].x, &add);
                    njAddVector((NJS_VECTOR*)&tvP[VtxTbl[(pnt - 3) & 0xF]].x, &add);
                }
            }
        }
         
        if (oP->ct0++ > 256) 
        {
            oP->mode0++;
            
            oP->ct0 = 0;
        }
    }
    case 2:
    {
        BH_PWORK* ewP; 
        
        ewP = (BH_PWORK*)oP->lkwkp;
        
        if ((ewP == NULL) || ((!(ewP->stflg & 0x1000000)) && ((sys->pt_flg & 0x2)))) 
        {
            sys->ef_trs[sys->ef_trsn++] = oP;
        }
        
        break;
    }
    } 
}

// 
// Start address: 0x247140
void bhEff301(O_WRK* oP)
{
	UV_WORK* uvP;
	float siz_y;
	float siz_x;
	//float siz_y;
	//float siz_x;
	int ay;
	float off_set;
	//_anon36* htP;
	float adj;
	NJS_POINT3 pos;
	float rng;
	//int ay;
	int ax;
	//_anon36* htP;
	Eff301PRM_WORK* prmP;
	static const Eff301PRM_WORK Eff301Prm[7] = 
	{
		{ 0xFFC0C0C0, 30.0f,  90.0f },
		{ 0xFFC0C0C0, 30.0f,  90.0f },
		{ 0xFFC0C0C0, 30.0f,  60.0f },
		{ 0xFFC0C0C0, 50.0f,  60.0f },
		{ 0xFFC0C0C0, 50.0f,  30.0f },
		{ 0xFFC0C0C0, 50.0f,  30.0f },
		{ 0xFFC0C0C0, 50.0f, 270.0f }
	};
	static const unsigned char AnmTbl[4][2] = 
	{
		{ 3, 6 }, { 4, 7 }, { 5, 8 }, { 3, 6 }
	};
	// Line 556, Address: 0x247140, Func Offset: 0
	// Line 585, Address: 0x247164, Func Offset: 0x24
	// Line 587, Address: 0x247180, Func Offset: 0x40
	// Line 598, Address: 0x247188, Func Offset: 0x48
	// Line 602, Address: 0x247244, Func Offset: 0x104
	// Line 606, Address: 0x247250, Func Offset: 0x110
	// Line 605, Address: 0x247258, Func Offset: 0x118
	// Line 606, Address: 0x24725c, Func Offset: 0x11c
	// Line 602, Address: 0x247260, Func Offset: 0x120
	// Line 607, Address: 0x247264, Func Offset: 0x124
	// Line 602, Address: 0x247268, Func Offset: 0x128
	// Line 608, Address: 0x24726c, Func Offset: 0x12c
	// Line 609, Address: 0x247270, Func Offset: 0x130
	// Line 602, Address: 0x247274, Func Offset: 0x134
	// Line 614, Address: 0x24727c, Func Offset: 0x13c
	// Line 615, Address: 0x2472d0, Func Offset: 0x190
	// Line 616, Address: 0x247320, Func Offset: 0x1e0
	// Line 615, Address: 0x247324, Func Offset: 0x1e4
	// Line 621, Address: 0x247328, Func Offset: 0x1e8
	// Line 622, Address: 0x247344, Func Offset: 0x204
	// Line 621, Address: 0x247348, Func Offset: 0x208
	// Line 622, Address: 0x24734c, Func Offset: 0x20c
	// Line 623, Address: 0x247358, Func Offset: 0x218
	// Line 629, Address: 0x24737c, Func Offset: 0x23c
	// Line 630, Address: 0x2473b0, Func Offset: 0x270
	// Line 632, Address: 0x2473f4, Func Offset: 0x2b4
	// Line 631, Address: 0x2473f8, Func Offset: 0x2b8
	// Line 632, Address: 0x2473fc, Func Offset: 0x2bc
	// Line 633, Address: 0x247414, Func Offset: 0x2d4
	// Line 634, Address: 0x247418, Func Offset: 0x2d8
	// Line 635, Address: 0x247424, Func Offset: 0x2e4
	// Line 636, Address: 0x247440, Func Offset: 0x300
	// Line 635, Address: 0x24744c, Func Offset: 0x30c
	// Line 636, Address: 0x247450, Func Offset: 0x310
	// Line 635, Address: 0x247454, Func Offset: 0x314
	// Line 636, Address: 0x247458, Func Offset: 0x318
	// Line 639, Address: 0x247460, Func Offset: 0x320
	// Line 635, Address: 0x247464, Func Offset: 0x324
	// Line 639, Address: 0x247468, Func Offset: 0x328
	// Line 635, Address: 0x24746c, Func Offset: 0x32c
	// Line 639, Address: 0x24747c, Func Offset: 0x33c
	// Line 635, Address: 0x247484, Func Offset: 0x344
	// Line 636, Address: 0x24748c, Func Offset: 0x34c
	// Line 637, Address: 0x247490, Func Offset: 0x350
	// Line 638, Address: 0x247494, Func Offset: 0x354
	// Line 639, Address: 0x247498, Func Offset: 0x358
	// Line 640, Address: 0x2474b0, Func Offset: 0x370
	// Line 641, Address: 0x2474b4, Func Offset: 0x374
	// Line 640, Address: 0x2474b8, Func Offset: 0x378
	// Line 641, Address: 0x2474c0, Func Offset: 0x380
	// Line 643, Address: 0x2474cc, Func Offset: 0x38c
	// Line 644, Address: 0x2474d4, Func Offset: 0x394
	// Line 650, Address: 0x2474dc, Func Offset: 0x39c
	// Line 653, Address: 0x2474e8, Func Offset: 0x3a8
	// Line 655, Address: 0x247504, Func Offset: 0x3c4
	// Line 656, Address: 0x247514, Func Offset: 0x3d4
	// Line 657, Address: 0x247534, Func Offset: 0x3f4
	// Line 656, Address: 0x24753c, Func Offset: 0x3fc
	// Line 657, Address: 0x24755c, Func Offset: 0x41c
	// Line 658, Address: 0x247564, Func Offset: 0x424
	// Line 660, Address: 0x247570, Func Offset: 0x430
	// Line 661, Address: 0x24758c, Func Offset: 0x44c
	// Line 662, Address: 0x247590, Func Offset: 0x450
	// Line 663, Address: 0x247594, Func Offset: 0x454
	// Line 664, Address: 0x2475c0, Func Offset: 0x480
	// Line 665, Address: 0x2475cc, Func Offset: 0x48c
	// Line 667, Address: 0x2475d4, Func Offset: 0x494
	// Line 668, Address: 0x2475dc, Func Offset: 0x49c
	// Line 670, Address: 0x2475e4, Func Offset: 0x4a4
	// Line 674, Address: 0x2475ec, Func Offset: 0x4ac
	// Line 677, Address: 0x2475f4, Func Offset: 0x4b4
	// Line 679, Address: 0x24760c, Func Offset: 0x4cc
	// Line 680, Address: 0x247640, Func Offset: 0x500
	// Line 679, Address: 0x247644, Func Offset: 0x504
	// Line 680, Address: 0x247648, Func Offset: 0x508
	// Line 682, Address: 0x247650, Func Offset: 0x510
	// Line 683, Address: 0x247658, Func Offset: 0x518
	// Line 684, Address: 0x24766c, Func Offset: 0x52c
	// Line 685, Address: 0x247680, Func Offset: 0x540
	// Line 689, Address: 0x247694, Func Offset: 0x554
	// Line 691, Address: 0x247698, Func Offset: 0x558
	// Line 693, Address: 0x2476ac, Func Offset: 0x56c
	// Line 694, Address: 0x2476bc, Func Offset: 0x57c
	// Line 695, Address: 0x2476c0, Func Offset: 0x580
	// Line 696, Address: 0x2476c8, Func Offset: 0x588
	// Line 698, Address: 0x2476f0, Func Offset: 0x5b0
	// Line 700, Address: 0x247704, Func Offset: 0x5c4
	// Line 702, Address: 0x247724, Func Offset: 0x5e4
	// Line 700, Address: 0x247728, Func Offset: 0x5e8
	// Line 703, Address: 0x247748, Func Offset: 0x608
	// Line 704, Address: 0x247750, Func Offset: 0x610
	// Line 708, Address: 0x247754, Func Offset: 0x614
	// Line 715, Address: 0x24775c, Func Offset: 0x61c
	// Line 716, Address: 0x247764, Func Offset: 0x624
	// Line 719, Address: 0x247768, Func Offset: 0x628
	// Line 716, Address: 0x247774, Func Offset: 0x634
	// Line 719, Address: 0x247778, Func Offset: 0x638
	// Line 720, Address: 0x24777c, Func Offset: 0x63c
	// Line 719, Address: 0x247780, Func Offset: 0x640
	// Line 720, Address: 0x247784, Func Offset: 0x644
	// Line 721, Address: 0x24778c, Func Offset: 0x64c
	// Line 722, Address: 0x247798, Func Offset: 0x658
	// Line 723, Address: 0x2477a4, Func Offset: 0x664
	// Line 724, Address: 0x2477b0, Func Offset: 0x670
	// Line 726, Address: 0x2477bc, Func Offset: 0x67c
	// Line 731, Address: 0x2477c8, Func Offset: 0x688
	// Line 732, Address: 0x2477e0, Func Offset: 0x6a0
	// Line 733, Address: 0x2477ec, Func Offset: 0x6ac
	// Line 734, Address: 0x247810, Func Offset: 0x6d0
	// Line 735, Address: 0x247844, Func Offset: 0x704
	// Line 738, Address: 0x24784c, Func Offset: 0x70c
	// Line 739, Address: 0x247850, Func Offset: 0x710
	// Line 738, Address: 0x24785c, Func Offset: 0x71c
	// Line 741, Address: 0x247860, Func Offset: 0x720
	// Line 738, Address: 0x247864, Func Offset: 0x724
	// Line 739, Address: 0x24786c, Func Offset: 0x72c
	// Line 740, Address: 0x247878, Func Offset: 0x738
	// Line 741, Address: 0x247884, Func Offset: 0x744
	// Line 742, Address: 0x24789c, Func Offset: 0x75c
	// Line 743, Address: 0x2478d0, Func Offset: 0x790
	// Line 747, Address: 0x2478d8, Func Offset: 0x798
	// Line 748, Address: 0x2478f8, Func Offset: 0x7b8
	// Line 750, Address: 0x24791c, Func Offset: 0x7dc
	// Line 751, Address: 0x247928, Func Offset: 0x7e8
	// Line 752, Address: 0x247930, Func Offset: 0x7f0
	// Line 754, Address: 0x24793c, Func Offset: 0x7fc
	// Line 758, Address: 0x247948, Func Offset: 0x808
	// Line 759, Address: 0x247960, Func Offset: 0x820
	// Line 760, Address: 0x24796c, Func Offset: 0x82c
	// Line 761, Address: 0x247990, Func Offset: 0x850
	// Line 762, Address: 0x2479c4, Func Offset: 0x884
	// Line 765, Address: 0x2479cc, Func Offset: 0x88c
	// Line 766, Address: 0x2479d4, Func Offset: 0x894
	// Line 768, Address: 0x2479e0, Func Offset: 0x8a0
	// Line 765, Address: 0x2479e4, Func Offset: 0x8a4
	// Line 766, Address: 0x2479ec, Func Offset: 0x8ac
	// Line 767, Address: 0x2479f0, Func Offset: 0x8b0
	// Line 766, Address: 0x247a00, Func Offset: 0x8c0
	// Line 767, Address: 0x247a08, Func Offset: 0x8c8
	// Line 768, Address: 0x247a14, Func Offset: 0x8d4
	// Line 769, Address: 0x247a2c, Func Offset: 0x8ec
	// Line 770, Address: 0x247a60, Func Offset: 0x920
	// Line 777, Address: 0x247a68, Func Offset: 0x928
	// Line 780, Address: 0x247a70, Func Offset: 0x930
	// Line 777, Address: 0x247a74, Func Offset: 0x934
	// Line 779, Address: 0x247a7c, Func Offset: 0x93c
	// Line 780, Address: 0x247a8c, Func Offset: 0x94c
	// Line 783, Address: 0x247a94, Func Offset: 0x954
	// Line 784, Address: 0x247af0, Func Offset: 0x9b0
	// Line 786, Address: 0x247b08, Func Offset: 0x9c8
	// Line 784, Address: 0x247b0c, Func Offset: 0x9cc
	// Line 785, Address: 0x247b10, Func Offset: 0x9d0
	// Line 784, Address: 0x247b18, Func Offset: 0x9d8
	// Line 786, Address: 0x247b1c, Func Offset: 0x9dc
	// Line 788, Address: 0x247b40, Func Offset: 0xa00
	// Line 792, Address: 0x247b4c, Func Offset: 0xa0c
	// Line 793, Address: 0x247b64, Func Offset: 0xa24
	// Line 794, Address: 0x247b70, Func Offset: 0xa30
	// Line 795, Address: 0x247b94, Func Offset: 0xa54
	// Line 796, Address: 0x247bc8, Func Offset: 0xa88
	// Line 799, Address: 0x247bd0, Func Offset: 0xa90
	// Line 800, Address: 0x247bd4, Func Offset: 0xa94
	// Line 799, Address: 0x247be0, Func Offset: 0xaa0
	// Line 802, Address: 0x247be4, Func Offset: 0xaa4
	// Line 799, Address: 0x247be8, Func Offset: 0xaa8
	// Line 800, Address: 0x247bf0, Func Offset: 0xab0
	// Line 801, Address: 0x247bfc, Func Offset: 0xabc
	// Line 802, Address: 0x247c08, Func Offset: 0xac8
	// Line 803, Address: 0x247c20, Func Offset: 0xae0
	// Line 805, Address: 0x247c58, Func Offset: 0xb18
	// Line 806, Address: 0x247c64, Func Offset: 0xb24
	// Line 810, Address: 0x247c6c, Func Offset: 0xb2c
	// Line 811, Address: 0x247c90, Func Offset: 0xb50
	// Line 812, Address: 0x247cb4, Func Offset: 0xb74
	// Line 813, Address: 0x247cc0, Func Offset: 0xb80
	// Line 817, Address: 0x247ccc, Func Offset: 0xb8c
	// Line 818, Address: 0x247ce4, Func Offset: 0xba4
	// Line 819, Address: 0x247cf0, Func Offset: 0xbb0
	// Line 820, Address: 0x247d10, Func Offset: 0xbd0
	// Line 821, Address: 0x247d44, Func Offset: 0xc04
	// Line 825, Address: 0x247d4c, Func Offset: 0xc0c
	// Line 826, Address: 0x247d58, Func Offset: 0xc18
	// Line 831, Address: 0x247d64, Func Offset: 0xc24
	// Line 827, Address: 0x247d68, Func Offset: 0xc28
	// Line 826, Address: 0x247d70, Func Offset: 0xc30
	// Line 832, Address: 0x247d74, Func Offset: 0xc34
	// Line 826, Address: 0x247d78, Func Offset: 0xc38
	// Line 827, Address: 0x247d88, Func Offset: 0xc48
	// Line 831, Address: 0x247d8c, Func Offset: 0xc4c
	// Line 832, Address: 0x247d90, Func Offset: 0xc50
	// Line 827, Address: 0x247d98, Func Offset: 0xc58
	// Line 828, Address: 0x247da0, Func Offset: 0xc60
	// Line 831, Address: 0x247dac, Func Offset: 0xc6c
	// Line 832, Address: 0x247db0, Func Offset: 0xc70
	// Line 834, Address: 0x247db4, Func Offset: 0xc74
	// Line 831, Address: 0x247db8, Func Offset: 0xc78
	// Line 834, Address: 0x247dbc, Func Offset: 0xc7c
	// Line 832, Address: 0x247dc0, Func Offset: 0xc80
	// Line 834, Address: 0x247dc4, Func Offset: 0xc84
	// Line 835, Address: 0x247dc8, Func Offset: 0xc88
	// Line 832, Address: 0x247dcc, Func Offset: 0xc8c
	// Line 835, Address: 0x247dd0, Func Offset: 0xc90
	// Line 836, Address: 0x247dd8, Func Offset: 0xc98
	// Line 837, Address: 0x247de4, Func Offset: 0xca4
	// Line 838, Address: 0x247df0, Func Offset: 0xcb0
	// Line 839, Address: 0x247dfc, Func Offset: 0xcbc
	// Line 840, Address: 0x247e04, Func Offset: 0xcc4
	// Line 841, Address: 0x247e10, Func Offset: 0xcd0
	// Line 844, Address: 0x247e18, Func Offset: 0xcd8
	// Line 846, Address: 0x247e3c, Func Offset: 0xcfc
	// Line 847, Address: 0x247e54, Func Offset: 0xd14
	// Line 848, Address: 0x247e80, Func Offset: 0xd40
	// Line 851, Address: 0x247e88, Func Offset: 0xd48
	// Line 854, Address: 0x247e90, Func Offset: 0xd50
	// Line 855, Address: 0x247e98, Func Offset: 0xd58
	// Line 872, Address: 0x247ea4, Func Offset: 0xd64
	// Line 854, Address: 0x247ea8, Func Offset: 0xd68
	// Line 855, Address: 0x247eb0, Func Offset: 0xd70
	// Line 856, Address: 0x247eb4, Func Offset: 0xd74
	// Line 859, Address: 0x247ec0, Func Offset: 0xd80
	// Line 855, Address: 0x247ec4, Func Offset: 0xd84
	// Line 856, Address: 0x247ecc, Func Offset: 0xd8c
	// Line 859, Address: 0x247ed0, Func Offset: 0xd90
	// Line 860, Address: 0x247ed4, Func Offset: 0xd94
	// Line 856, Address: 0x247ee0, Func Offset: 0xda0
	// Line 859, Address: 0x247ee8, Func Offset: 0xda8
	// Line 860, Address: 0x247eec, Func Offset: 0xdac
	// Line 862, Address: 0x247ef0, Func Offset: 0xdb0
	// Line 859, Address: 0x247ef4, Func Offset: 0xdb4
	// Line 862, Address: 0x247ef8, Func Offset: 0xdb8
	// Line 860, Address: 0x247efc, Func Offset: 0xdbc
	// Line 862, Address: 0x247f00, Func Offset: 0xdc0
	// Line 863, Address: 0x247f04, Func Offset: 0xdc4
	// Line 860, Address: 0x247f08, Func Offset: 0xdc8
	// Line 863, Address: 0x247f0c, Func Offset: 0xdcc
	// Line 864, Address: 0x247f14, Func Offset: 0xdd4
	// Line 865, Address: 0x247f20, Func Offset: 0xde0
	// Line 866, Address: 0x247f2c, Func Offset: 0xdec
	// Line 867, Address: 0x247f38, Func Offset: 0xdf8
	// Line 868, Address: 0x247f40, Func Offset: 0xe00
	// Line 869, Address: 0x247f4c, Func Offset: 0xe0c
	// Line 872, Address: 0x247f54, Func Offset: 0xe14
	// Line 873, Address: 0x247f80, Func Offset: 0xe40
	// Line 874, Address: 0x247fac, Func Offset: 0xe6c
	// Line 875, Address: 0x247fb4, Func Offset: 0xe74
	// Line 882, Address: 0x247fb8, Func Offset: 0xe78
	// Line 884, Address: 0x247fc4, Func Offset: 0xe84
	// Line 882, Address: 0x247fc8, Func Offset: 0xe88
	// Line 884, Address: 0x247fd0, Func Offset: 0xe90
	// Line 885, Address: 0x247fdc, Func Offset: 0xe9c
	// Line 887, Address: 0x247fec, Func Offset: 0xeac
	// Line 888, Address: 0x247ffc, Func Offset: 0xebc
	// Line 889, Address: 0x24800c, Func Offset: 0xecc
	// Line 890, Address: 0x248014, Func Offset: 0xed4
	// Line 891, Address: 0x248024, Func Offset: 0xee4
	// Line 892, Address: 0x248034, Func Offset: 0xef4
	// Line 893, Address: 0x24803c, Func Offset: 0xefc
	// Line 894, Address: 0x248044, Func Offset: 0xf04
	// Line 895, Address: 0x24804c, Func Offset: 0xf0c
	// Line 898, Address: 0x248060, Func Offset: 0xf20
	// Func End, Address: 0x248088, Func Offset: 0xf48
	scePrintf("bhEff301 - UNIMPLEMENTED!\n");
}

static const PD_WORK PtclDat00[2] = 
{ 
	{ 0, 255, 1 }, { 0, 224, 1 } 
};
static const PD_WORK PtclDat01[2] = 
{ 
	{ 1, 255, 1 }, { 1, 224, 1 } 
};
static const PD_WORK PtclDat02[2] = 
{ 
	{ 2, 255, 1 }, { 3, 224, 1 } 
};
static const PD_WORK PtclDat03[1] = 
{ 
	{ 4, 255, 1 } 
};
static const PD_WORK PtclDat04[2] = 
{ 
	{ 5, 255, 2 }, { 11, 128, 1 } 
};
static const PD_WORK PtclDat05[2] = 
{ 
	{ 6, 255, 2 }, { 11, 128, 1 } 
};
static const PD_WORK PtclDat06[2] = 
{ 
	{ 7, 255, 2 }, { 11, 128, 1 } 
};
static const PD_WORK PtclDat07[2] = 
{ 
	{ 8, 255, 2 }, { 11, 128, 1 } 
};
static const PD_WORK PtclDat08[1] = 
{ 
	{ 9, 255, 1 } 
};
static const PD_WORK PtclDat09[2] = 
{ 
	{ 10, 255, 1 }, { 10, 224, 1 } 
};
static const PD_WORK PtclDat10[1] = 
{ 
	{ 12, 255, 1 } 
};
static const PD_WORK PtclDat11[1] = 
{ 
	{ 13, 255, 1 } 
};
static const PD_WORK PtclDat12[2] = 
{ 
	{ 14, 255, 1 }, { 14, 160, 1 } 
};
static const PD_WORK PtclDat13[2] = 
{ 
	{ 15, 255, 1 }, { 15, 160, 1 } 
};
static const PD_WORK PtclDat14[1] = 
{ 
	{ 16, 255, 1 } 
};
static const PD_WORK PtclDat15[2] = 
{ 
	{ 17, 255, 1 }, { 17, 160, 1 } 
};
static const PD_WORK PtclDat16[2] = 
{ 
	{ 18, 255, 1 }, { 18, 160, 1 } 
};
static const PD_WORK PtclDat17[1] = 
{ 
	{ 0, 255, 1 } 
};
static const PD_WORK PtclDat18[1] = 
{ 
	{ 19, 255, 1 } 
};

static const PT_WORK PtclTbl[19] = 
{
    { 2, PtclDat00 },
    { 2, PtclDat01 },
    { 2, PtclDat02 },
    { 1, PtclDat03 },
    { 2, PtclDat04 },
    { 2, PtclDat05 },
    { 2, PtclDat06 },
    { 2, PtclDat07 },
    { 1, PtclDat08 },
    { 2, PtclDat09 },
    { 1, PtclDat10 },
    { 1, PtclDat11 },
    { 2, PtclDat12 },
    { 2, PtclDat13 },
    { 1, PtclDat14 },
    { 2, PtclDat15 },
    { 2, PtclDat16 },
    { 1, PtclDat17 },
    { 1, PtclDat18 }
};

// 100% matching!
O_WRK* bhSetEffParticle(BH_PWORK* ewP, int lnk_no, NJS_POINT3* offP, NJS_POINT3* dirP, unsigned int color, int typ_no)
{
   PT_WORK* ptP;    
    PD_WORK* pdP;  
    O_WRK* oP;        
    E02_WORK* e02aP; 
    int set_no; // different position than DWARF     
    E02_WRK* e02bP;   
    unsigned int tmp; 
    
	ptP = (PT_WORK*)&PtclTbl[typ_no];
    pdP = ptP->pdP;
    
    owk_scn_noG = 0;

    for (set_no = ptP->set_num; set_no > 0; set_no--, pdP++)  
    {
        oP = AllocOwork();
        
        e02aP = (E02_WORK*)AllocOwork();
        e02bP = (E02_WRK*)AllocOwork();

        if ((oP == NULL) || (e02aP == NULL) || (e02bP == NULL)) 
        {
            if (oP != NULL) 
            {
                oP->flg = 0;
            }
            
            if (e02aP != NULL) 
            {
                e02aP->flg = 0;
            }
            
            if (e02bP != NULL) 
            {
                e02bP->flg = 0;
            }
            
            return NULL;
        }

        oP->exp0 = (unsigned char*)e02aP;
        oP->exp1 = (unsigned char*)e02bP;
        
        oP->func = (void*)FuncTbl[pdP->drw_typ];
        
        oP->type = pdP->mov_no;
        
        oP->id = 302;
        
        oP->txp[0] = &sys->ef_tlist;
        
        oP->tex_id = sys->ef_tn[4];
        
        oP->mtn_attr = (((color   & 0xFF00FF) * (pdP->col_lv + 1)) >> 8) & 0xFF00FF;
        oP->mtn_attr |= ((((color & 0xFF00)   * (pdP->col_lv + 1)) >> 8) & 0xFF00) | 0xFF000000;
        
        oP->mtn_no = (oP->mtn_attr & 0xFFFFFF) | 0x20000000;

        if (ewP != NULL)
        {
            oP->flg = 0x81;
            
            oP->lkwkp = (unsigned char*)ewP;
            oP->lkono = lnk_no;
            
            if (offP != NULL) 
            {
                *(NJS_POINT3*)&oP->lox = *offP;
            }
            else 
            {
                oP->lox = oP->loy = oP->loz = 0;
            }
        }
        else 
        {
            oP->flg = 1;
            
            oP->lkwkp = NULL;
            oP->lkono = lnk_no;
            
            *(NJS_POINT3*)&oP->px = *offP;
        }

        oP->mtx = (NJS_MATRIX*)oP->mtxbuf;
        
        *(NJS_POINT3*)&oP->xn = *dirP;
        
        njUnitVector((NJS_VECTOR*)&oP->xn);
    }

    return oP;
}

// 100% matching!
O_WRK* bhSetEffParticleMk2(BH_PWORK* ewP, int lnk_no, NJS_POINT3* offP, NJS_POINT3* dirP, unsigned int src_col, unsigned int dst_col, int typ_no)
{
    PT_WORK* ptP;    
    PD_WORK* pdP;  
    O_WRK* oP;        
    E02_WORK* e02aP; 
    int set_no; // different position than DWARF     
    E02_WRK* e02bP;   
    unsigned int tmp; 
    
	ptP = (PT_WORK*)&PtclTbl[typ_no];
    pdP = ptP->pdP;
    
    owk_scn_noG = 0;

    for (set_no = ptP->set_num; set_no > 0; set_no--, pdP++) 
    {
        oP = AllocOwork();
        
        e02aP = (E02_WORK*)AllocOwork();
        e02bP = (E02_WRK*)AllocOwork();

        if ((oP == NULL) || (e02aP == NULL) || (e02bP == NULL)) 
        {
            if (oP != NULL) 
            {
                oP->flg = 0;
            }
            
            if (e02aP != NULL) 
            {
                e02aP->flg = 0;
            }
            
            if (e02bP != NULL) 
            {
                e02bP->flg = 0;
            }
            
            return NULL;
        }

        oP->exp0 = (unsigned char*)e02aP;
        oP->exp1 = (unsigned char*)e02bP;
        
        oP->func = (void*)FuncTbl[pdP->drw_typ];
        
        oP->type = pdP->mov_no;
        
        oP->id = 302;
        
        oP->txp[0] = &sys->ef_tlist;
        
        oP->tex_id = sys->ef_tn[4];
        
        oP->mtn_attr = (((src_col   & 0xFF00FF) * (pdP->col_lv + 1)) >> 8) & 0xFF00FF;
        oP->mtn_attr |= ((((src_col & 0xFF00)   * (pdP->col_lv + 1)) >> 8) & 0xFF00) | 0xFF000000;
        
        oP->mtn_no = dst_col; 

        if (ewP != NULL)
        {
            oP->flg = 0x81;
            
            oP->lkwkp = (unsigned char*)ewP;
            oP->lkono = lnk_no;
            
            if (offP != NULL) 
            {
                *(NJS_POINT3*)&oP->lox = *offP;
            }
            else 
            {
                oP->lox = oP->loy = oP->loz = 0;
            }
        }
        else 
        {
            oP->flg = 1;
            
            oP->lkwkp = NULL;
            oP->lkono = lnk_no;
            
            *(NJS_POINT3*)&oP->px = *offP;
        }

        oP->mtx = (NJS_MATRIX*)oP->mtxbuf;
        
        *(NJS_POINT3*)&oP->xn = *dirP;
        
        njUnitVector((NJS_VECTOR*)&oP->xn);
    }

    return oP;
}

// 
// Start address: 0x248590
void bhEff302(O_WRK* oP)
{
	float spd;
	NJS_POINT3* dP;
	int stg_stt;
	float* spdP;
	NJS_POINT3* dirP;
	NJS_POINT3* grvP;
	NJS_POINT3* posP;
	int stg_vtx;
	int vtx_num;
	float s_rnd;
	float p_rnd;
	float b_spd;
	//float* spdP;
	//NJS_POINT3* posP;
	int i;
	//NJS_POINT3* grvP;
	int* timP;
	int stg_no;
	E02_WORK* e02aP;
	int* subP;
	int* addP;
	int cnt;
	int dst;
	int src;
	int tmp;
	int az;
	int ay;
	int ax;
	//NJS_POINT3* dirP;
	float** spdPP;
	NJS_POINT3** bufPP;
	//int* timP;
	//int i;
	//_anon7* prmP;
	//_anon3* e02bP;
	//E02_WORK* e02aP;
	// Line 1201, Address: 0x248590, Func Offset: 0
	// Line 1203, Address: 0x2485cc, Func Offset: 0x3c
	// Line 1207, Address: 0x2485ec, Func Offset: 0x5c
	// Line 1209, Address: 0x2485f0, Func Offset: 0x60
	// Line 1208, Address: 0x2485f8, Func Offset: 0x68
	// Line 1209, Address: 0x2485fc, Func Offset: 0x6c
	// Line 1227, Address: 0x248600, Func Offset: 0x70
	// Line 1230, Address: 0x248608, Func Offset: 0x78
	// Line 1231, Address: 0x24860c, Func Offset: 0x7c
	// Line 1214, Address: 0x248610, Func Offset: 0x80
	// Line 1209, Address: 0x248614, Func Offset: 0x84
	// Line 1214, Address: 0x248618, Func Offset: 0x88
	// Line 1209, Address: 0x24861c, Func Offset: 0x8c
	// Line 1214, Address: 0x248620, Func Offset: 0x90
	// Line 1215, Address: 0x248624, Func Offset: 0x94
	// Line 1209, Address: 0x248628, Func Offset: 0x98
	// Line 1232, Address: 0x248630, Func Offset: 0xa0
	// Line 1215, Address: 0x248634, Func Offset: 0xa4
	// Line 1216, Address: 0x248638, Func Offset: 0xa8
	// Line 1234, Address: 0x24863c, Func Offset: 0xac
	// Line 1216, Address: 0x248644, Func Offset: 0xb4
	// Line 1217, Address: 0x248648, Func Offset: 0xb8
	// Line 1218, Address: 0x248650, Func Offset: 0xc0
	// Line 1219, Address: 0x248658, Func Offset: 0xc8
	// Line 1220, Address: 0x248670, Func Offset: 0xe0
	// Line 1221, Address: 0x248678, Func Offset: 0xe8
	// Line 1222, Address: 0x248680, Func Offset: 0xf0
	// Line 1223, Address: 0x248688, Func Offset: 0xf8
	// Line 1224, Address: 0x2486a0, Func Offset: 0x110
	// Line 1226, Address: 0x2486a8, Func Offset: 0x118
	// Line 1227, Address: 0x2486b0, Func Offset: 0x120
	// Line 1235, Address: 0x2486bc, Func Offset: 0x12c
	// Line 1236, Address: 0x2486c4, Func Offset: 0x134
	// Line 1235, Address: 0x2486c8, Func Offset: 0x138
	// Line 1237, Address: 0x2486d0, Func Offset: 0x140
	// Line 1236, Address: 0x2486d4, Func Offset: 0x144
	// Line 1237, Address: 0x2486d8, Func Offset: 0x148
	// Line 1238, Address: 0x2486dc, Func Offset: 0x14c
	// Line 1239, Address: 0x2486f0, Func Offset: 0x160
	// Line 1238, Address: 0x2486f8, Func Offset: 0x168
	// Line 1239, Address: 0x248700, Func Offset: 0x170
	// Line 1243, Address: 0x248710, Func Offset: 0x180
	// Line 1245, Address: 0x248714, Func Offset: 0x184
	// Line 1246, Address: 0x248718, Func Offset: 0x188
	// Line 1247, Address: 0x248764, Func Offset: 0x1d4
	// Line 1248, Address: 0x2487b0, Func Offset: 0x220
	// Line 1250, Address: 0x2487fc, Func Offset: 0x26c
	// Line 1248, Address: 0x248808, Func Offset: 0x278
	// Line 1251, Address: 0x24880c, Func Offset: 0x27c
	// Line 1250, Address: 0x248814, Func Offset: 0x284
	// Line 1251, Address: 0x24881c, Func Offset: 0x28c
	// Line 1252, Address: 0x248824, Func Offset: 0x294
	// Line 1253, Address: 0x24883c, Func Offset: 0x2ac
	// Line 1254, Address: 0x248850, Func Offset: 0x2c0
	// Line 1262, Address: 0x24885c, Func Offset: 0x2cc
	// Line 1263, Address: 0x248860, Func Offset: 0x2d0
	// Line 1261, Address: 0x248864, Func Offset: 0x2d4
	// Line 1264, Address: 0x248868, Func Offset: 0x2d8
	// Line 1265, Address: 0x24886c, Func Offset: 0x2dc
	// Line 1267, Address: 0x248870, Func Offset: 0x2e0
	// Line 1268, Address: 0x24888c, Func Offset: 0x2fc
	// Line 1269, Address: 0x2488a8, Func Offset: 0x318
	// Line 1271, Address: 0x2488b0, Func Offset: 0x320
	// Line 1272, Address: 0x2488cc, Func Offset: 0x33c
	// Line 1273, Address: 0x2488f0, Func Offset: 0x360
	// Line 1275, Address: 0x248900, Func Offset: 0x370
	// Line 1276, Address: 0x248920, Func Offset: 0x390
	// Line 1277, Address: 0x24894c, Func Offset: 0x3bc
	// Line 1279, Address: 0x248960, Func Offset: 0x3d0
	// Line 1280, Address: 0x248968, Func Offset: 0x3d8
	// Line 1281, Address: 0x248984, Func Offset: 0x3f4
	// Line 1282, Address: 0x2489ac, Func Offset: 0x41c
	// Line 1287, Address: 0x2489c0, Func Offset: 0x430
	// Line 1288, Address: 0x2489c8, Func Offset: 0x438
	// Line 1292, Address: 0x2489d0, Func Offset: 0x440
	// Line 1306, Address: 0x2489d4, Func Offset: 0x444
	// Line 1307, Address: 0x2489d8, Func Offset: 0x448
	// Line 1308, Address: 0x2489e0, Func Offset: 0x450
	// Line 1310, Address: 0x2489f0, Func Offset: 0x460
	// Line 1307, Address: 0x2489f4, Func Offset: 0x464
	// Line 1310, Address: 0x2489f8, Func Offset: 0x468
	// Line 1312, Address: 0x248a00, Func Offset: 0x470
	// Line 1315, Address: 0x248a0c, Func Offset: 0x47c
	// Line 1317, Address: 0x248a14, Func Offset: 0x484
	// Line 1318, Address: 0x248a18, Func Offset: 0x488
	// Line 1319, Address: 0x248a1c, Func Offset: 0x48c
	// Line 1320, Address: 0x248a20, Func Offset: 0x490
	// Line 1321, Address: 0x248a24, Func Offset: 0x494
	// Line 1323, Address: 0x248a28, Func Offset: 0x498
	// Line 1324, Address: 0x248a30, Func Offset: 0x4a0
	// Line 1325, Address: 0x248a44, Func Offset: 0x4b4
	// Line 1326, Address: 0x248a7c, Func Offset: 0x4ec
	// Line 1327, Address: 0x248ab4, Func Offset: 0x524
	// Line 1329, Address: 0x248aec, Func Offset: 0x55c
	// Line 1330, Address: 0x248b08, Func Offset: 0x578
	// Line 1329, Address: 0x248b10, Func Offset: 0x580
	// Line 1330, Address: 0x248b34, Func Offset: 0x5a4
	// Line 1332, Address: 0x248b3c, Func Offset: 0x5ac
	// Line 1333, Address: 0x248b48, Func Offset: 0x5b8
	// Line 1334, Address: 0x248b54, Func Offset: 0x5c4
	// Line 1335, Address: 0x248b5c, Func Offset: 0x5cc
	// Line 1337, Address: 0x248b60, Func Offset: 0x5d0
	// Line 1338, Address: 0x248b68, Func Offset: 0x5d8
	// Line 1340, Address: 0x248b78, Func Offset: 0x5e8
	// Line 1343, Address: 0x248b84, Func Offset: 0x5f4
	// Line 1344, Address: 0x248b94, Func Offset: 0x604
	// Line 1347, Address: 0x248ba4, Func Offset: 0x614
	// Line 1348, Address: 0x248bd0, Func Offset: 0x640
	// Line 1350, Address: 0x248bdc, Func Offset: 0x64c
	// Line 1351, Address: 0x248be4, Func Offset: 0x654
	// Line 1352, Address: 0x248bec, Func Offset: 0x65c
	// Line 1354, Address: 0x248bf0, Func Offset: 0x660
	// Line 1352, Address: 0x248bf4, Func Offset: 0x664
	// Line 1353, Address: 0x248bfc, Func Offset: 0x66c
	// Line 1354, Address: 0x248c08, Func Offset: 0x678
	// Line 1357, Address: 0x248c0c, Func Offset: 0x67c
	// Line 1359, Address: 0x248c10, Func Offset: 0x680
	// Line 1360, Address: 0x248c14, Func Offset: 0x684
	// Line 1359, Address: 0x248c18, Func Offset: 0x688
	// Line 1360, Address: 0x248c1c, Func Offset: 0x68c
	// Line 1359, Address: 0x248c20, Func Offset: 0x690
	// Line 1360, Address: 0x248c28, Func Offset: 0x698
	// Line 1363, Address: 0x248c38, Func Offset: 0x6a8
	// Line 1371, Address: 0x248c44, Func Offset: 0x6b4
	// Line 1379, Address: 0x248c48, Func Offset: 0x6b8
	// Line 1377, Address: 0x248c4c, Func Offset: 0x6bc
	// Line 1373, Address: 0x248c50, Func Offset: 0x6c0
	// Line 1374, Address: 0x248c5c, Func Offset: 0x6cc
	// Line 1375, Address: 0x248c60, Func Offset: 0x6d0
	// Line 1379, Address: 0x248c70, Func Offset: 0x6e0
	// Line 1382, Address: 0x248c78, Func Offset: 0x6e8
	// Line 1383, Address: 0x248c7c, Func Offset: 0x6ec
	// Line 1386, Address: 0x248cb4, Func Offset: 0x724
	// Line 1387, Address: 0x248cc4, Func Offset: 0x734
	// Line 1390, Address: 0x248cc8, Func Offset: 0x738
	// Line 1391, Address: 0x248cd4, Func Offset: 0x744
	// Line 1390, Address: 0x248cd8, Func Offset: 0x748
	// Line 1393, Address: 0x248ce0, Func Offset: 0x750
	// Line 1397, Address: 0x248ce8, Func Offset: 0x758
	// Line 1393, Address: 0x248cf0, Func Offset: 0x760
	// Line 1394, Address: 0x248cfc, Func Offset: 0x76c
	// Line 1395, Address: 0x248d10, Func Offset: 0x780
	// Line 1397, Address: 0x248d20, Func Offset: 0x790
	// Line 1398, Address: 0x248d28, Func Offset: 0x798
	// Line 1399, Address: 0x248d2c, Func Offset: 0x79c
	// Line 1398, Address: 0x248d38, Func Offset: 0x7a8
	// Line 1399, Address: 0x248d40, Func Offset: 0x7b0
	// Line 1400, Address: 0x248d48, Func Offset: 0x7b8
	// Line 1403, Address: 0x248d50, Func Offset: 0x7c0
	// Line 1405, Address: 0x248d58, Func Offset: 0x7c8
	// Line 1412, Address: 0x248d6c, Func Offset: 0x7dc
	// Func End, Address: 0x248da8, Func Offset: 0x818
	scePrintf("bhEff302 - UNIMPLEMENTED!\n");
}

// 100% matching!
static void bhEff_PtclSpriteDrawB(O_WRK* oP)
{
    E02_WORK* e02aP;  
    int stg_no, stg_num;       
    float scl;        
    NJS_POINT3* bufP; 

    e02aP = (E02_WORK*)oP->exp0;
    
    njGetSystemAttr((NJS_SYS_ATTR*)&e02aP->atr_bak);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njTextureFilterMode(0);
    
    njSetMatrix(NULL, cam.mtx);
    njSetTexture(oP->txp[0]);
    
    if ((e02aP->stg_num != 0) && (e02aP->stg_num != 0)) 
    {
        // empty
    } 
    
    stg_num = e02aP->stg_num;
    stg_no  = e02aP->stg_stt;
    
    for (; stg_num > 0; stg_num--, stg_no++)
    {
        scl  = e02aP->stg_scl[stg_no];
        bufP = e02aP->stg_buf[stg_no];
        
        njPtclSpriteStart(oP->tex_id + (e02aP->stg_tim[stg_no] & 3), e02aP->stg_col[stg_no], 1);
        
        njPtclDrawSprite(&bufP[0],  4, scl, scl);
        njPtclDrawSprite(&bufP[4],  4, scl, scl);
        njPtclDrawSprite(&bufP[8],  4, scl, scl);
        njPtclDrawSprite(&bufP[12], 4, scl, scl);
        
        njPtclSpriteEnd();
    } 
    
    njSetSystemAttr((NJS_SYS_ATTR*)&e02aP->atr_bak);
}

// 100% matching!
static void bhEff_PtclLineDraw(O_WRK* oP)
{
    E02_WORK* e02aP;     
    int stg_num, stg_no;       
    NJS_POINT3COL* p3cP; 
    int* colP;          
    int col;             
    int i;              
    float* spdP;        
    NJS_POINT3* dirP, *p3P, *grvP;    
    NJS_POINT3 vct;      
    float spd, scl;         
    float* pntP;        
    
    e02aP = (E02_WORK*)oP->exp0;
    
    njSetMatrix(NULL, cam.mtx);

    stg_num = e02aP->stg_num;
    stg_no  = e02aP->stg_stt;

    p3cP = &e02aP->lne_p3c;

    e02aP->lne_p3c.p   = e02aP->lne_pnt;
    e02aP->lne_p3c.col = e02aP->lne_col;
    e02aP->lne_p3c.tex = NULL;
    e02aP->lne_p3c.num = 1;

    for (; stg_num > 0; stg_no++, stg_num--) 
    {
        col = e02aP->stg_col[stg_no];
        
        dirP = &e02aP->vtx_dir[15];
        grvP = &e02aP->stg_grv[stg_no];

        e02aP->lne_col[0].color = col & 0xFFFFFF;
        e02aP->lne_col[1].color = col;

        spdP = e02aP->stg_spd[stg_no];
        p3P  = e02aP->stg_buf[stg_no];

        for (i = 0; i < 16; i++) 
        {
            spd = *spdP;

            scl = spd * e02aP->scale;
             
            pntP = (float*)e02aP->lne_pnt;
            
            scl = scl * 100.0f;
            
            *pntP++ = p3P->x;
            *pntP++ = p3P->y;
            *pntP++ = p3P->z;

            vct.x = dirP->x * spd;
            vct.y = dirP->y * spd;
            vct.z = dirP->z * spd;

            njAddVector(&vct, grvP);

            *pntP++ = p3P->x + (vct.x * scl);
            *pntP++ = p3P->y + (vct.y * scl);
            *pntP++ = p3P->z + (vct.z * scl);

            njDrawLine3D(p3cP, p3cP->num, 0x40);

            p3P++;
            spdP++;
            dirP--;
        }
    } 
}

// 99.66% matching
void bhEff303(O_WRK* oP)
{
    ANM_WORK* anmP; 
    DSP_WRK* dspP;  
    const PRM_WORK* prmP;
	static const PRM_WORK PrmTbl[8] =
	{
		{ 3, 0xC0C0C0C0, 0.01f,  -1 },
		{ 4, 0xC0C0C0C0, 0.02f,  -1 },
		{ 5, 0xC0C0C0C0, 0.04f,  -1 },
		{ 3, 0xC0C0C0C0, 0.08f,  -1 },
		{ 3, 0xC0F0F0F0, 0.75f, 228 },
		{ 4, 0xC0808080, 0.75f, 198 },
		{ 5, 0xC0C0C0C0, 0.75f, 208 },
		{ 3, 0xC0808080, 0.75f, 160 }
	};

    anmP = (ANM_WORK*)((char*)oP + 1028);
    dspP =  (DSP_WRK*)((char*)oP + 1060);

    switch (oP->mode0)
    {                              
    case 0: 
        prmP = &PrmTbl[oP->type];
        
        sys->bl_ct = (sys->bl_ct + 1) & 0x1FF;
        
        oP->py += 0.001f * sys->bl_ct;
        
        oP->tex_id = 5;
        
        oP->flg = 0x200001;
        
        oP->bl_src = 8;
        oP->bl_dst = 6;
        
        oP->sx = oP->sy = oP->sz = 0;
        
        oP->spd = prmP->speed;
        
        oP->frm_no   = prmP->time;
        oP->frm_mode = 16;
        
        oP->sxb *= 2.0f;
        oP->szb *= 2.0f;
        
        oP->ani_ct = oP->mdlver;
        
        oP->tvp = dspP->VtxBuf;
        
        oP->ax += 16384;
        
        anmP->uv_tabP = (UV_WORK*)Tex5uv;
        
        anmP->anm_no = prmP->anm_no;
        
        ryRapAnmColSet(anmP, prmP->color, prmP->color & 0xFFFFFF, oP->frm_mode);
        ryRapDspSet((NJS_POINT3*)&oP->px, dspP, 1.0f);
        ryRapTexAnm(anmP, dspP, FALSE);
        
        oP->mode0++;
        break;
    case 1:
        if ((oP->sxb - oP->sx) < 0.01f) 
        {
            oP->mode0++;
        } 
        else 
        {
            oP->sx += oP->spd * (oP->sxb - oP->sx);
            oP->sy += oP->spd * (oP->szb - oP->sy);
        }
        
        sys->ef_trs[sys->ef_trsn++] = oP;
        break;
    case 2:
        sys->ef_trs[sys->ef_trsn++] = oP;
        
        if ((oP->frm_no > 0) && (--oP->frm_no == 0))
        {
            oP->mode0++;
        }
        
        break;
    case 3:
        if ((int)--oP->frm_mode >= 0) 
        {
            anmP->color += anmP->col_add;
            anmP->color -= anmP->col_sub;
            
            ryRapTexAnm(anmP, dspP, FALSE);
            
            sys->ef_trs[sys->ef_trsn++] = oP;
        }
        else 
        {
            oP->flg = 0;
        }
        
        break;
    }
}

// 100% matching!
static int bhCheckCamWall2D(NJS_POINT3* srcP, NJS_POINT3* vctP, NJS_POINT3* rtnP, float rng_x, float rng_y)
{
    NJS_LINE lne;
	static const NJS_PLANE pln = 
	{
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f
	};
    
    njCalcPoint(cam.mtx,  srcP, (NJS_POINT3*)&lne.px);
    njCalcVector(cam.mtx, vctP, (NJS_VECTOR*)&lne.vx);
    
    if ((njInnerProduct((NJS_VECTOR*)&pln.vx, (NJS_VECTOR*)&lne.vx) < 0.0f) && (!njDistanceL2PL(&lne, &pln, rtnP)))
    {
        if (((-rng_x < rtnP->x) && (rtnP->x < rng_x)) && ((-rng_y < rtnP->y) && (rtnP->y < rng_y)))
        {
            rtnP->z = njDistanceP2P((NJS_POINT3*)&lne.px, rtnP);
            
            rtnP->x = 320.0f + (320.0f * (rtnP->x / rng_x));
            rtnP->y = 240.0f + (240.0f * (rtnP->y / rng_y));
            
            return 1;
        }
    }
    
    return 0;
}

// 100% matching!
O_WRK* rySetShadow(BH_PWORK* ewP, int obj0, int obj1, int obj2, float off_a, float off_b)
{
	O_WRK* oP;
    O_WORK* owP;
            
    oP = AllocOworkOne();
    
    if (oP != NULL) 
    {
        oP->flg = 0x8240001;
        
        oP->id   = 304;
        oP->type = 0;
        
        oP->tex_id = -1;
        
        oP->mdlver = 0;
        
        oP->sx = oP->sy = oP->sz = 1.0f;
        oP->ax = oP->ay = oP->az = 0;
        oP->px = oP->py = oP->pz = 0;
        
        oP->mlwP = &sys->efm[1];
        
        oP->lkwkp = (unsigned char*)ewP;
        oP->lkono = 0;
        
        oP->mtx = (NJS_MATRIX*)oP->mtxbuf;
        
        oP->xn = off_a;
        oP->zn = off_b;
        
        owP = ewP->mlwP->owP;
        
        oP->ct0 = (int)&owP[obj0].mtx[12]; // this doesn't look too healthy
        oP->ct1 = (int)&owP[obj1].mtx[12];
        oP->ct2 = (int)&owP[obj2].mtx[12];
    }
    
    return oP;
}

// 
// Start address: 0x2496f0
void bhEff304(O_WRK* oP)
{
	BH_PWORK* ewP;
	NJS_POINT3 dlt;
	NJS_POINT3 pos;
	NJS_POINT3 vct;
	float tmp;
	NJS_POINT3* p2P;
	//float tmp;
	NJS_POINT3* p1P;
	NJS_POINT3* p0P;
	float rb;
	float ra;
	NJS_POINT3* pbP;
	NJS_POINT3* paP;
	NJS_POINT3 pp;
	// Line 1754, Address: 0x2496f0, Func Offset: 0
	// Line 1764, Address: 0x249714, Func Offset: 0x24
	// Line 1765, Address: 0x249718, Func Offset: 0x28
	// Line 1768, Address: 0x24971c, Func Offset: 0x2c
	// Line 1770, Address: 0x249724, Func Offset: 0x34
	// Line 1768, Address: 0x249728, Func Offset: 0x38
	// Line 1769, Address: 0x24973c, Func Offset: 0x4c
	// Line 1770, Address: 0x249750, Func Offset: 0x60
	// Line 1782, Address: 0x249764, Func Offset: 0x74
	// Line 1788, Address: 0x249768, Func Offset: 0x78
	// Line 1772, Address: 0x24976c, Func Offset: 0x7c
	// Line 1774, Address: 0x249774, Func Offset: 0x84
	// Line 1788, Address: 0x24977c, Func Offset: 0x8c
	// Line 1786, Address: 0x249780, Func Offset: 0x90
	// Line 1772, Address: 0x249788, Func Offset: 0x98
	// Line 1774, Address: 0x24978c, Func Offset: 0x9c
	// Line 1786, Address: 0x249790, Func Offset: 0xa0
	// Line 1788, Address: 0x249794, Func Offset: 0xa4
	// Line 1775, Address: 0x249798, Func Offset: 0xa8
	// Line 1773, Address: 0x24979c, Func Offset: 0xac
	// Line 1787, Address: 0x2497a0, Func Offset: 0xb0
	// Line 1789, Address: 0x2497a4, Func Offset: 0xb4
	// Line 1775, Address: 0x2497ac, Func Offset: 0xbc
	// Line 1791, Address: 0x2497b0, Func Offset: 0xc0
	// Line 1795, Address: 0x2497c0, Func Offset: 0xd0
	// Line 1796, Address: 0x2497c4, Func Offset: 0xd4
	// Line 1793, Address: 0x2497c8, Func Offset: 0xd8
	// Line 1797, Address: 0x2497cc, Func Offset: 0xdc
	// Line 1792, Address: 0x2497d0, Func Offset: 0xe0
	// Line 1801, Address: 0x2497d4, Func Offset: 0xe4
	// Line 1802, Address: 0x2497dc, Func Offset: 0xec
	// Line 1808, Address: 0x2497ec, Func Offset: 0xfc
	// Line 1809, Address: 0x2497fc, Func Offset: 0x10c
	// Line 1808, Address: 0x249800, Func Offset: 0x110
	// Line 1809, Address: 0x249808, Func Offset: 0x118
	// Line 1811, Address: 0x249810, Func Offset: 0x120
	// Line 1817, Address: 0x249838, Func Offset: 0x148
	// Line 1820, Address: 0x249848, Func Offset: 0x158
	// Line 1817, Address: 0x24984c, Func Offset: 0x15c
	// Line 1829, Address: 0x249850, Func Offset: 0x160
	// Line 1830, Address: 0x249854, Func Offset: 0x164
	// Line 1817, Address: 0x249858, Func Offset: 0x168
	// Line 1832, Address: 0x24985c, Func Offset: 0x16c
	// Line 1817, Address: 0x249864, Func Offset: 0x174
	// Line 1818, Address: 0x24986c, Func Offset: 0x17c
	// Line 1820, Address: 0x249884, Func Offset: 0x194
	// Line 1828, Address: 0x24989c, Func Offset: 0x1ac
	// Line 1829, Address: 0x2498a4, Func Offset: 0x1b4
	// Line 1828, Address: 0x2498a8, Func Offset: 0x1b8
	// Line 1829, Address: 0x2498b4, Func Offset: 0x1c4
	// Line 1830, Address: 0x2498c4, Func Offset: 0x1d4
	// Line 1832, Address: 0x2498d4, Func Offset: 0x1e4
	// Line 1833, Address: 0x2498ec, Func Offset: 0x1fc
	// Line 1834, Address: 0x249908, Func Offset: 0x218
	// Line 1835, Address: 0x24991c, Func Offset: 0x22c
	// Line 1836, Address: 0x24992c, Func Offset: 0x23c
	// Line 1837, Address: 0x249934, Func Offset: 0x244
	// Line 1841, Address: 0x249950, Func Offset: 0x260
	// Line 1842, Address: 0x24995c, Func Offset: 0x26c
	// Line 1849, Address: 0x249968, Func Offset: 0x278
	// Line 1851, Address: 0x24996c, Func Offset: 0x27c
	// Line 1853, Address: 0x249984, Func Offset: 0x294
	// Line 1854, Address: 0x2499b4, Func Offset: 0x2c4
	// Line 1856, Address: 0x2499c8, Func Offset: 0x2d8
	// Line 1857, Address: 0x2499d4, Func Offset: 0x2e4
	// Line 1856, Address: 0x2499d8, Func Offset: 0x2e8
	// Line 1857, Address: 0x2499e0, Func Offset: 0x2f0
	// Line 1862, Address: 0x249a14, Func Offset: 0x324
	// Func End, Address: 0x249a3c, Func Offset: 0x34c
	scePrintf("bhEff304 - UNIMPLEMENTED!\n");
}

#pragma divbyzerocheck on

// 100% matching!
void bhEff305(O_WRK* oP) 
{
	static const Eff305PRM_WORK Eff305Prm[4] = 
	{
		{ 0x70F0C080, 0.1f, -0.01f, 16, 1.5f, 1.5f, 3.0f },
		{ 0x70F0C080, 0.1f, -0.01f, 20, 1.5f, 2.0f, 3.0f },
		{ 0x70F0C080, 0.1f, -0.01f, 24, 1.5f, 2.5f, 3.5f },
		{ 0x70F0C080, 0.1f, -0.01f, 28, 1.5f, 3.0f, 3.5f }
	};
	static const UV_WORK Tex2uv[8] = 
	{
		{ 0.12500000f, 0.00000000f, 0.12109375f, 0.12109375f }, 
		{ 0.25000000f, 0.00000000f, 0.12109375f, 0.12109375f }, 
		{ 0.37500000f, 0.00000000f, 0.12109375f, 0.12109375f }, 
		{ 0.50000000f, 0.00000000f, 0.12109375f, 0.12109375f }, 
		{ 0.62500000f, 0.00000000f, 0.12109375f, 0.12109375f }, 
		{ 0.75000000f, 0.00000000f, 0.12109375f, 0.12109375f }, 
		{ 0.87500000f, 0.00000000f, 0.12109375f, 0.12109375f }, 
		{ 0.87500000f, 0.00000000f, 0.12109375f, 0.12109375f } 
	};

    switch (oP->mode0)
    {                     
    case 0:
    {
        const Eff305PRM_WORK* prmP;
        NJS_POINT3 vct;       
        float dst;           
        int ay, ax;              
        
        oP->flg = 0x4300001;
        
        oP->tex_id = 2;
        
        oP->ani_ct = 0;
        
        oP->bl_src = 8;
        oP->bl_dst = 10;
        
        prmP = &Eff305Prm[oP->type];
        
        oP->spd = prmP->speed;
        
        oP->shp_ct = prmP->accel;
        
        oP->ct0 = prmP->time;
        oP->ct1 = prmP->color;
        oP->ct2 = (prmP->color / oP->ct0) & 0xFF000000;
        oP->ct3 = 0;
        
        oP->sx = oP->sy = prmP->src_scl;
        
        oP->sx *= oP->sxb;
        oP->sy *= oP->syb;
        
        oP->lox = oP->loy = prmP->dst_scl;
        
        oP->lox = ((oP->lox * oP->sxb) - oP->sx) / oP->ct0;
        oP->loy = ((oP->loy * oP->syb) - oP->sy) / oP->ct0;
        
        oP->xn = oP->yn = oP->zn = 0;
        
        oP->gpx = oP->gpy = 0.1f * sys->winds;
        
        dst = prmP->offset;
        
        vct = *(NJS_POINT3*)&cam.wpx;
        
        njSubVector(&vct, (NJS_VECTOR*)&oP->px);
        
        njUnitVector(&vct);
        
        oP->px += vct.x * dst;
        oP->py += vct.y * dst;
        oP->pz += vct.z * dst;
        
        ay = oP->ay;
        ax = oP->ax;
        
        oP->aox = -njSin(ay) * njCos(ax);
        oP->aoy =  njSin(ax);
        oP->aoz = -njCos(ay) * njCos(ax);
        
        oP->mode0++;
    }
    case 1:
    {
        float spd;        
        int ay;           
        float sp;          
        const UV_WORK* uvP;        
        NJS_TEXTURE_VTX* tvP; 
        unsigned int col;    
        
        if (oP->ct0-- <= 0) 
        {
            oP->flg = 0;
            break;
        }
        
        spd = oP->spd;
        
        oP->px += oP->aox * spd;
        oP->py += oP->aoy * spd;
        oP->pz += oP->aoz * spd;
        
        njAddVector((NJS_VECTOR*)&oP->px, (NJS_VECTOR*)&oP->xn);
        
        oP->yn -= -0.0054444447f;
        
        spd += oP->shp_ct;
        
        if (spd > 0)
        {
            oP->spd = spd; 
        }
        
        sp = oP->gpx;
        
        ay = sys->windr;
        
        oP->px += sp * -njSin(ay);
        oP->pz += sp * -njCos(ay);
        
        oP->gpx += oP->gpy;
        
        col = oP->ct1;
        
        uvP = &Tex2uv[oP->ct3];
        
        oP->tv[0].u   = uvP->u;
        oP->tv[0].v   = uvP->v;
        oP->tv[0].col = col;
        
        oP->tv[1].u   = uvP->u + uvP->xs;
        oP->tv[1].v   = uvP->v;
        oP->tv[1].col = col;
        
        oP->tv[2].u   = uvP->u;
        oP->tv[2].v   = uvP->v + uvP->ys;
        oP->tv[2].col = col;
        
        oP->tv[3].u   = uvP->u + uvP->xs;
        oP->tv[3].v   = uvP->v + uvP->ys;
        oP->tv[3].col = col;
        
        oP->ct1 -= oP->ct2;
        
        oP->sx += oP->lox;
        oP->sy += oP->loy;
        
        if (oP->ct3 < 7) 
        {
            oP->ct3++;
        }
        
        sys->ef_trs[sys->ef_trsn++] = oP;
        break;
    }
    }
}

#pragma divbyzerocheck off

// 
// Start address: 0x249eb0
void bhEff306(O_WRK* oP)
{
	unsigned int col;
	NJS_TEXTURE_VTX* tvP;
	UV_WORK* uvP;
	float dst;
	NJS_POINT3 vct;
	float rnd;
	float dst_scl;
	Eff306PRM_WORK* prmP;
	static const int ColTbl[4] = 
	{
		0xFFF0F0F0, 0xFF808080, 0xFFD0D0D0, 0xFFC0C0C0
	};
	static const UV_WORK Tex8uv[10] = 
	{
		{    0.0f,    0.0f, 0.18359375f, 0.18359375f },
		{ 0.1875f,    0.0f, 0.18359375f, 0.18359375f },
		{  0.375f,    0.0f, 0.18359375f, 0.18359375f },
		{ 0.5625f,    0.0f, 0.18359375f, 0.18359375f },
		{   0.75f,    0.0f, 0.18359375f, 0.18359375f },
		{    0.0f, 0.1875f, 0.18359375f, 0.18359375f },
		{ 0.1875f, 0.1875f, 0.18359375f, 0.18359375f },
		{  0.375f, 0.1875f, 0.18359375f, 0.18359375f },
		{ 0.5625f, 0.1875f, 0.18359375f, 0.18359375f },
		{   0.75f, 0.1875f, 0.18359375f, 0.18359375f }
	};
	static const UV_WORK Tex9uv[10] = 
	{
		{  0.0f,  0.0f, 0.24609375f, 0.24609375f },
		{ 0.25f,  0.0f, 0.24609375f, 0.24609375f },
		{  0.5f,  0.0f, 0.24609375f, 0.24609375f },
		{ 0.75f,  0.0f, 0.24609375f, 0.24609375f },
		{  0.0f, 0.25f, 0.24609375f, 0.24609375f },
		{ 0.25f, 0.25f, 0.24609375f, 0.24609375f },
		{  0.5f, 0.25f, 0.24609375f, 0.24609375f },
		{ 0.75f, 0.25f, 0.24609375f, 0.24609375f },
		{  0.0f,  0.5f, 0.24609375f, 0.24609375f },
		{ 0.25f,  0.5f, 0.24609375f, 0.24609375f }
	};
	static UV_WORK* TexTab[10] = 
	{
		NULL, NULL, NULL, NULL, 
		NULL, NULL, NULL, NULL, 
		Tex8uv, Tex9uv
	};
	static const Eff306PRM_WORK Eff306Prm[8] = 
	{
		{ 8, 0,  4,  32, 3.0f, 0.2f, 1.5f },
		{ 8, 0,  4,  48, 3.0f, 0.2f, 1.5f },
		{ 8, 2,  8,  64, 3.0f, 0.3f, 2.0f },
		{ 8, 2,  8,  80, 3.0f, 0.3f, 2.0f },
		{ 8, 1, 16,  96, 3.0f, 0.5f, 2.5f },
		{ 8, 1, 16, 112, 3.0f, 0.5f, 2.5f },
		{ 8, 0,  4,  48, 3.0f, 0.2f, 1.0f },
		{ 8, 0,  4,  32, 3.0f, 0.2f, 1.0f }
	};
	// Line 2014, Address: 0x249eb0, Func Offset: 0
	// Line 2073, Address: 0x249ec4, Func Offset: 0x14
	// Line 2076, Address: 0x249f08, Func Offset: 0x58
	// Line 2078, Address: 0x249f14, Func Offset: 0x64
	// Line 2077, Address: 0x249f18, Func Offset: 0x68
	// Line 2078, Address: 0x249f1c, Func Offset: 0x6c
	// Line 2079, Address: 0x249f20, Func Offset: 0x70
	// Line 2083, Address: 0x249f28, Func Offset: 0x78
	// Line 2085, Address: 0x249f78, Func Offset: 0xc8
	// Line 2089, Address: 0x249f84, Func Offset: 0xd4
	// Line 2085, Address: 0x249f8c, Func Offset: 0xdc
	// Line 2086, Address: 0x249f9c, Func Offset: 0xec
	// Line 2088, Address: 0x249fa0, Func Offset: 0xf0
	// Line 2089, Address: 0x249fa8, Func Offset: 0xf8
	// Line 2090, Address: 0x249fbc, Func Offset: 0x10c
	// Line 2091, Address: 0x249fc8, Func Offset: 0x118
	// Line 2092, Address: 0x249fd0, Func Offset: 0x120
	// Line 2093, Address: 0x249fd8, Func Offset: 0x128
	// Line 2094, Address: 0x249fec, Func Offset: 0x13c
	// Line 2095, Address: 0x24a004, Func Offset: 0x154
	// Line 2097, Address: 0x24a00c, Func Offset: 0x15c
	// Line 2098, Address: 0x24a054, Func Offset: 0x1a4
	// Line 2100, Address: 0x24a060, Func Offset: 0x1b0
	// Line 2105, Address: 0x24a06c, Func Offset: 0x1bc
	// Line 2107, Address: 0x24a084, Func Offset: 0x1d4
	// Line 2108, Address: 0x24a08c, Func Offset: 0x1dc
	// Line 2107, Address: 0x24a094, Func Offset: 0x1e4
	// Line 2108, Address: 0x24a09c, Func Offset: 0x1ec
	// Line 2109, Address: 0x24a0c4, Func Offset: 0x214
	// Line 2111, Address: 0x24a0fc, Func Offset: 0x24c
	// Line 2113, Address: 0x24a114, Func Offset: 0x264
	// Line 2116, Address: 0x24a11c, Func Offset: 0x26c
	// Line 2117, Address: 0x24a14c, Func Offset: 0x29c
	// Line 2118, Address: 0x24a184, Func Offset: 0x2d4
	// Line 2119, Address: 0x24a194, Func Offset: 0x2e4
	// Line 2120, Address: 0x24a198, Func Offset: 0x2e8
	// Line 2119, Address: 0x24a1a0, Func Offset: 0x2f0
	// Line 2120, Address: 0x24a1a4, Func Offset: 0x2f4
	// Line 2121, Address: 0x24a1b0, Func Offset: 0x300
	// Line 2123, Address: 0x24a1b8, Func Offset: 0x308
	// Line 2126, Address: 0x24a1c0, Func Offset: 0x310
	// Line 2131, Address: 0x24a1c4, Func Offset: 0x314
	// Line 2133, Address: 0x24a1d4, Func Offset: 0x324
	// Line 2135, Address: 0x24a1f4, Func Offset: 0x344
	// Line 2133, Address: 0x24a1f8, Func Offset: 0x348
	// Line 2143, Address: 0x24a1fc, Func Offset: 0x34c
	// Line 2135, Address: 0x24a208, Func Offset: 0x358
	// Line 2144, Address: 0x24a214, Func Offset: 0x364
	// Line 2135, Address: 0x24a218, Func Offset: 0x368
	// Line 2136, Address: 0x24a220, Func Offset: 0x370
	// Line 2141, Address: 0x24a230, Func Offset: 0x380
	// Line 2143, Address: 0x24a234, Func Offset: 0x384
	// Line 2144, Address: 0x24a248, Func Offset: 0x398
	// Line 2145, Address: 0x24a250, Func Offset: 0x3a0
	// Line 2147, Address: 0x24a258, Func Offset: 0x3a8
	// Line 2156, Address: 0x24a25c, Func Offset: 0x3ac
	// Line 2147, Address: 0x24a260, Func Offset: 0x3b0
	// Line 2156, Address: 0x24a264, Func Offset: 0x3b4
	// Line 2147, Address: 0x24a268, Func Offset: 0x3b8
	// Line 2148, Address: 0x24a274, Func Offset: 0x3c4
	// Line 2149, Address: 0x24a288, Func Offset: 0x3d8
	// Line 2156, Address: 0x24a29c, Func Offset: 0x3ec
	// Line 2153, Address: 0x24a2a0, Func Offset: 0x3f0
	// Line 2156, Address: 0x24a2a8, Func Offset: 0x3f8
	// Line 2153, Address: 0x24a2b0, Func Offset: 0x400
	// Line 2156, Address: 0x24a2b4, Func Offset: 0x404
	// Line 2153, Address: 0x24a2b8, Func Offset: 0x408
	// Line 2156, Address: 0x24a2bc, Func Offset: 0x40c
	// Line 2158, Address: 0x24a2c0, Func Offset: 0x410
	// Line 2156, Address: 0x24a2c4, Func Offset: 0x414
	// Line 2158, Address: 0x24a2c8, Func Offset: 0x418
	// Line 2159, Address: 0x24a2d4, Func Offset: 0x424
	// Line 2161, Address: 0x24a2d8, Func Offset: 0x428
	// Line 2162, Address: 0x24a2f0, Func Offset: 0x440
	// Line 2164, Address: 0x24a2f4, Func Offset: 0x444
	// Line 2165, Address: 0x24a30c, Func Offset: 0x45c
	// Line 2167, Address: 0x24a310, Func Offset: 0x460
	// Line 2168, Address: 0x24a330, Func Offset: 0x480
	// Line 2171, Address: 0x24a334, Func Offset: 0x484
	// Line 2174, Address: 0x24a354, Func Offset: 0x4a4
	// Func End, Address: 0x24a368, Func Offset: 0x4b8
	scePrintf("bhEff306 - UNIMPLEMENTED!\n");
}

// 100% matching!
OR_WORK* bhSetRapEff(int eff_no, void* datP, int lng_siz)
{
    OR_WORK* orP;
    
    if ((orP = (OR_WORK*)AllocOworkOne()) != NULL) 
    {
        orP->flg = 1;
        
        orP->id = eff_no;
        
        if (datP != NULL) 
        {
            njMemCopy4(&orP->free4, datP, lng_siz);
        }
    }
    
    return orP;
}

// 
// Start address: 0x24a3e0
void bhEff307(OR_WORK* orP)
{
	int* colP;
	int* alpP;
	int flg;
	int idx;
	float sp;
	int ay;
	NJS_POINT3 wnd;
	NJS_POINT3* vctP;
	//int idx;
	int vtx;
	//_anon51* r07P;
	// Line 2200, Address: 0x24a3e0, Func Offset: 0
	// Line 2204, Address: 0x24a40c, Func Offset: 0x2c
	// Line 2207, Address: 0x24a438, Func Offset: 0x58
	// Line 2208, Address: 0x24a444, Func Offset: 0x64
	// Line 2209, Address: 0x24a448, Func Offset: 0x68
	// Line 2210, Address: 0x24a44c, Func Offset: 0x6c
	// Line 2214, Address: 0x24a458, Func Offset: 0x78
	// Line 2210, Address: 0x24a464, Func Offset: 0x84
	// Line 2214, Address: 0x24a46c, Func Offset: 0x8c
	// Line 2210, Address: 0x24a474, Func Offset: 0x94
	// Line 2211, Address: 0x24a478, Func Offset: 0x98
	// Line 2214, Address: 0x24a484, Func Offset: 0xa4
	// Line 2223, Address: 0x24a49c, Func Offset: 0xbc
	// Line 2224, Address: 0x24a4bc, Func Offset: 0xdc
	// Line 2225, Address: 0x24a4e0, Func Offset: 0x100
	// Line 2227, Address: 0x24a4f0, Func Offset: 0x110
	// Line 2228, Address: 0x24a500, Func Offset: 0x120
	// Line 2227, Address: 0x24a508, Func Offset: 0x128
	// Line 2228, Address: 0x24a518, Func Offset: 0x138
	// Line 2229, Address: 0x24a524, Func Offset: 0x144
	// Line 2231, Address: 0x24a52c, Func Offset: 0x14c
	// Line 2233, Address: 0x24a538, Func Offset: 0x158
	// Line 2231, Address: 0x24a53c, Func Offset: 0x15c
	// Line 2232, Address: 0x24a544, Func Offset: 0x164
	// Line 2241, Address: 0x24a554, Func Offset: 0x174
	// Line 2232, Address: 0x24a558, Func Offset: 0x178
	// Line 2233, Address: 0x24a560, Func Offset: 0x180
	// Line 2234, Address: 0x24a56c, Func Offset: 0x18c
	// Line 2235, Address: 0x24a578, Func Offset: 0x198
	// Line 2236, Address: 0x24a590, Func Offset: 0x1b0
	// Line 2238, Address: 0x24a5a8, Func Offset: 0x1c8
	// Line 2242, Address: 0x24a5ac, Func Offset: 0x1cc
	// Line 2243, Address: 0x24a5b4, Func Offset: 0x1d4
	// Line 2254, Address: 0x24a5c0, Func Offset: 0x1e0
	// Line 2255, Address: 0x24a5d0, Func Offset: 0x1f0
	// Line 2256, Address: 0x24a5d4, Func Offset: 0x1f4
	// Line 2258, Address: 0x24a5ec, Func Offset: 0x20c
	// Line 2259, Address: 0x24a5f4, Func Offset: 0x214
	// Line 2260, Address: 0x24a600, Func Offset: 0x220
	// Line 2262, Address: 0x24a60c, Func Offset: 0x22c
	// Line 2263, Address: 0x24a618, Func Offset: 0x238
	// Line 2269, Address: 0x24a628, Func Offset: 0x248
	// Line 2263, Address: 0x24a62c, Func Offset: 0x24c
	// Line 2269, Address: 0x24a64c, Func Offset: 0x26c
	// Line 2270, Address: 0x24a650, Func Offset: 0x270
	// Line 2269, Address: 0x24a654, Func Offset: 0x274
	// Line 2272, Address: 0x24a660, Func Offset: 0x280
	// Line 2274, Address: 0x24a670, Func Offset: 0x290
	// Line 2272, Address: 0x24a674, Func Offset: 0x294
	// Line 2274, Address: 0x24a678, Func Offset: 0x298
	// Line 2278, Address: 0x24a688, Func Offset: 0x2a8
	// Line 2274, Address: 0x24a690, Func Offset: 0x2b0
	// Line 2276, Address: 0x24a694, Func Offset: 0x2b4
	// Line 2278, Address: 0x24a69c, Func Offset: 0x2bc
	// Line 2279, Address: 0x24a6a4, Func Offset: 0x2c4
	// Line 2281, Address: 0x24a6b8, Func Offset: 0x2d8
	// Line 2288, Address: 0x24a6d0, Func Offset: 0x2f0
	// Line 2289, Address: 0x24a6d4, Func Offset: 0x2f4
	// Line 2287, Address: 0x24a6d8, Func Offset: 0x2f8
	// Line 2290, Address: 0x24a6dc, Func Offset: 0x2fc
	// Line 2292, Address: 0x24a6e4, Func Offset: 0x304
	// Line 2293, Address: 0x24a700, Func Offset: 0x320
	// Line 2295, Address: 0x24a710, Func Offset: 0x330
	// Line 2296, Address: 0x24a724, Func Offset: 0x344
	// Line 2298, Address: 0x24a728, Func Offset: 0x348
	// Line 2299, Address: 0x24a730, Func Offset: 0x350
	// Line 2298, Address: 0x24a734, Func Offset: 0x354
	// Line 2299, Address: 0x24a748, Func Offset: 0x368
	// Line 2301, Address: 0x24a760, Func Offset: 0x380
	// Line 2302, Address: 0x24a76c, Func Offset: 0x38c
	// Line 2306, Address: 0x24a7b4, Func Offset: 0x3d4
	// Func End, Address: 0x24a7e0, Func Offset: 0x400
	scePrintf("bhEff307 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEff307Drw(OR_WORK* orP) 
{
    R07_WORK* r07P; 
    int vtx;       
    int tgr;        
    int idx;       
    float frm;    
    float tu_l, tu_r;     
    int col;       
     
    r07P = (R07_WORK*)orP->free4;
    
    vtx = r07P->vtx_num;
    
    njTextureFilterMode(1);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 10);
    
    njFogDisable();

    if (r07P->eff_prm.texP != NULL) 
    {
        njSetTexture(r07P->eff_prm.texP);
        njSetTextureNum(r07P->eff_prm.tex_id);
    }

    frm = 0;
    
    tgr = 0;
    idx = 0;
    
    njOverhauserSpline((float*)&r07P->VtxBufS[0].x, (float*)&r07P->poly[0].x, NULL, 0);
    njOverhauserSpline((float*)&r07P->VtxBufD[0].x, (float*)&r07P->poly[1].x, NULL, 0);

    while (TRUE)
    {
        frm += r07P->eff_prm.frm_inc;
        
        if (frm > 1.0f) 
        {
            frm -= 1.0f;
            
            idx++;
        }

        if (idx > (vtx - 3))
        {
            break;
        }

        tgr ^= 2;

        njOverhauserSpline((float*)&r07P->VtxBufS[idx].x, (float*)&r07P->poly[tgr].x,     NULL, frm);
        njOverhauserSpline((float*)&r07P->VtxBufD[idx].x, (float*)&r07P->poly[tgr + 1].x, NULL, frm);

        if (r07P->eff_prm.texP != NULL)
        {
            if ((tgr & 0x2)) 
            {
                tu_l = frm;
                tu_r = frm - r07P->eff_prm.frm_inc;
            } 
            else 
            {
                tu_r = frm;
                tu_l = frm - r07P->eff_prm.frm_inc;
            }

            col = ryLinerColor(r07P->VtxCol[idx], r07P->VtxCol[idx + 1], tu_r);
            
            r07P->poly[0].col = r07P->poly[1].col = col;

            col = ryLinerColor(r07P->VtxCol[idx], r07P->VtxCol[idx + 1], tu_l);
            
            r07P->poly[2].col = r07P->poly[3].col = col;

            r07P->poly[0].u = tu_l;
            r07P->poly[0].v = 0;
            
            r07P->poly[1].u = tu_l;
            r07P->poly[1].v = 1.0f;

            r07P->poly[2].u = tu_r;
            r07P->poly[2].v = 0;
            
            r07P->poly[3].u = tu_r;
            r07P->poly[3].v = 1.0f;

            njDrawTexture3DEx(r07P->poly, 4, 1);
        } 
        else
        {
            col = ryLinerColor(r07P->VtxCol[idx], r07P->VtxCol[idx + 1], frm);
            
            npDrawPlane((NJS_POINT3*)&r07P->poly[0].x, (NJS_POINT3*)&r07P->poly[1].x, (NJS_POINT3*)&r07P->poly[3].x, (NJS_POINT3*)&r07P->poly[2].x, col);
        }
    }
    
    njFogEnable();
}

// 100% matching!
void bhSetEffGunSpark(NJS_POINT3* posP, NJS_POINT3* dirP, unsigned int src_col, unsigned int dst_col, int typ_no)
{
    OR_WORK* orP;
    PMB_WORK* pmbP;
	static const Eff308PRM_WORK Eff308Prm[4] = 
	{
		{  8,                0.5f, 0.9800000190734863f, 1.0f,  5, 55.0f, 0.800000011920929f, 4, -0.03266666829586029f },
		{ 10, 0.6000000238418579f, 0.9800000190734863f, 2.0f,  7, 50.0f, 0.800000011920929f, 4, -0.03266666829586029f },
		{ 12,  0.699999988079071f, 0.9800000190734863f, 3.0f,  9, 45.0f, 0.800000011920929f, 4, -0.03266666829586029f },
		{ 12,                1.0f, 0.9800000190734863f, 3.0f, 12, 20.0f, 0.800000011920929f, 4, -0.03266666829586029f }
	};
    
    orP = bhSetRapEff(308, (void*)&Eff308Prm[typ_no], 9);
    
    if (orP != NULL) 
    {
        pmbP = (PMB_WORK*)((char*)orP + 180);
        
        pmbP->vtx_pos = *posP;
        pmbP->vtx_dir = *dirP;
        
        pmbP->col_src = src_col;
        pmbP->col_dst = dst_col;
        
        pmbP->gnd_hgh = posP->y - 100.0f;
    }
}

// 100% matching!
void bhSetEffSpark(NJS_POINT3* posP, NJS_POINT3* dirP, unsigned int src_col, unsigned int dst_col, int typ_no)
{
    OR_WORK* orP;
    PMB_WORK* pmbP;
    LGT_WORK* lP;
	static const Eff308PRM_WORK Eff308Prm[2] = 
	{
		{ 16,  1.0f, 0.9800000190734863f, 4.0f, 16, 120.0f, 1.899999976158142f, 16, -0.09800000488758087f },
		{ 16, 0.75f, 0.9800000190734863f, 4.0f, 16, 180.0f, 1.899999976158142f, 16, -0.09800000488758087f }
	};
    
    orP = bhSetRapEff(308, (void*)&Eff308Prm[typ_no], 9);
    
    if (orP != NULL) 
    {
        pmbP = (PMB_WORK*)orP->free4 + 1;

        pmbP->vtx_pos = *posP;
        pmbP->vtx_dir = *dirP;
        
        pmbP->col_src = src_col;
        pmbP->col_dst = dst_col;
        
        pmbP->gnd_hgh = bhGetGroundPosition(posP);
        
        lP = &rom->lgtp[2];
        
        if (!(lP->flg & 0x1)) 
        {
            lP->ct0 = 0;
            
            lP->lkono = 0;
            
            lP->vx = lP->vy = lP->vz = 0;
        }
        
        lP->lkono++;
        
        lP->flg |= 0x3;
        
        lP->type = 13;
        
        lP->aspd = 16;
        
        lP->lkflg = 0;
        lP->lsrc  = 4;
        
        lP->nr = 15.0f;
        lP->fr = 30.0f;
        
        *(NJS_POINT3*)&lP->vx = *dirP;
        *(NJS_POINT3*)&lP->px = *posP;
        
        lP->r = 3.0f;
        lP->g = 1.8f;
        lP->b = 0.7f;
    }
}

// 
// Start address: 0x24ac90
void bhEff308(OR_WORK* orP)
{
	float sp;
	int ay;
	unsigned int* colP;
	NJS_POINT3* dirP;
	NJS_POINT3* vtxP;
	NJS_POINT3 wnd;
	int i;
	int tmp;
	int dst;
	int src;
	int tim;
	int* subP;
	int* addP;
	int* timP;
	//int i;
	//unsigned int* colP;
	//NJS_POINT3* vtxP;
	//int i;
	//float sp;
	//int ay;
	int ax;
	//NJS_POINT3* dirP;
	//int i;
	PMB_WORK* pmbP;
	//_anon4* r08P;
	// Line 2468, Address: 0x24ac90, Func Offset: 0
	// Line 2473, Address: 0x24acc0, Func Offset: 0x30
	// Line 2469, Address: 0x24acc4, Func Offset: 0x34
	// Line 2473, Address: 0x24acc8, Func Offset: 0x38
	// Line 2476, Address: 0x24ace4, Func Offset: 0x54
	// Line 2477, Address: 0x24acf0, Func Offset: 0x60
	// Line 2483, Address: 0x24acfc, Func Offset: 0x6c
	// Line 2484, Address: 0x24ad08, Func Offset: 0x78
	// Line 2485, Address: 0x24ad54, Func Offset: 0xc4
	// Line 2486, Address: 0x24ada0, Func Offset: 0x110
	// Line 2488, Address: 0x24adbc, Func Offset: 0x12c
	// Line 2486, Address: 0x24adc0, Func Offset: 0x130
	// Line 2488, Address: 0x24adc4, Func Offset: 0x134
	// Line 2486, Address: 0x24adc8, Func Offset: 0x138
	// Line 2488, Address: 0x24ade4, Func Offset: 0x154
	// Line 2489, Address: 0x24adec, Func Offset: 0x15c
	// Line 2490, Address: 0x24adfc, Func Offset: 0x16c
	// Line 2491, Address: 0x24ae0c, Func Offset: 0x17c
	// Line 2492, Address: 0x24ae20, Func Offset: 0x190
	// Line 2493, Address: 0x24ae24, Func Offset: 0x194
	// Line 2492, Address: 0x24ae28, Func Offset: 0x198
	// Line 2493, Address: 0x24ae48, Func Offset: 0x1b8
	// Line 2501, Address: 0x24ae50, Func Offset: 0x1c0
	// Line 2498, Address: 0x24ae54, Func Offset: 0x1c4
	// Line 2501, Address: 0x24ae58, Func Offset: 0x1c8
	// Line 2502, Address: 0x24ae60, Func Offset: 0x1d0
	// Line 2506, Address: 0x24ae6c, Func Offset: 0x1dc
	// Line 2502, Address: 0x24ae70, Func Offset: 0x1e0
	// Line 2503, Address: 0x24ae7c, Func Offset: 0x1ec
	// Line 2506, Address: 0x24ae80, Func Offset: 0x1f0
	// Line 2503, Address: 0x24ae84, Func Offset: 0x1f4
	// Line 2504, Address: 0x24ae88, Func Offset: 0x1f8
	// Line 2506, Address: 0x24ae98, Func Offset: 0x208
	// Line 2515, Address: 0x24aea0, Func Offset: 0x210
	// Line 2511, Address: 0x24aea4, Func Offset: 0x214
	// Line 2512, Address: 0x24aea8, Func Offset: 0x218
	// Line 2515, Address: 0x24aeac, Func Offset: 0x21c
	// Line 2518, Address: 0x24aeb4, Func Offset: 0x224
	// Line 2519, Address: 0x24aefc, Func Offset: 0x26c
	// Line 2520, Address: 0x24af00, Func Offset: 0x270
	// Line 2522, Address: 0x24af04, Func Offset: 0x274
	// Line 2523, Address: 0x24af20, Func Offset: 0x290
	// Line 2524, Address: 0x24af38, Func Offset: 0x2a8
	// Line 2526, Address: 0x24af40, Func Offset: 0x2b0
	// Line 2527, Address: 0x24af5c, Func Offset: 0x2cc
	// Line 2528, Address: 0x24af7c, Func Offset: 0x2ec
	// Line 2530, Address: 0x24af90, Func Offset: 0x300
	// Line 2531, Address: 0x24afb0, Func Offset: 0x320
	// Line 2532, Address: 0x24afd4, Func Offset: 0x344
	// Line 2534, Address: 0x24afe8, Func Offset: 0x358
	// Line 2535, Address: 0x24aff0, Func Offset: 0x360
	// Line 2536, Address: 0x24b00c, Func Offset: 0x37c
	// Line 2537, Address: 0x24b030, Func Offset: 0x3a0
	// Line 2538, Address: 0x24b048, Func Offset: 0x3b8
	// Line 2542, Address: 0x24b060, Func Offset: 0x3d0
	// Line 2543, Address: 0x24b064, Func Offset: 0x3d4
	// Line 2545, Address: 0x24b08c, Func Offset: 0x3fc
	// Line 2557, Address: 0x24b098, Func Offset: 0x408
	// Line 2561, Address: 0x24b09c, Func Offset: 0x40c
	// Line 2562, Address: 0x24b0a4, Func Offset: 0x414
	// Line 2553, Address: 0x24b0a8, Func Offset: 0x418
	// Line 2554, Address: 0x24b0ac, Func Offset: 0x41c
	// Line 2561, Address: 0x24b0b0, Func Offset: 0x420
	// Line 2555, Address: 0x24b0bc, Func Offset: 0x42c
	// Line 2564, Address: 0x24b0c0, Func Offset: 0x430
	// Line 2566, Address: 0x24b0d0, Func Offset: 0x440
	// Line 2564, Address: 0x24b0d4, Func Offset: 0x444
	// Line 2566, Address: 0x24b0d8, Func Offset: 0x448
	// Line 2572, Address: 0x24b0e8, Func Offset: 0x458
	// Line 2566, Address: 0x24b0f0, Func Offset: 0x460
	// Line 2568, Address: 0x24b0f4, Func Offset: 0x464
	// Line 2572, Address: 0x24b0fc, Func Offset: 0x46c
	// Line 2573, Address: 0x24b104, Func Offset: 0x474
	// Line 2574, Address: 0x24b110, Func Offset: 0x480
	// Line 2575, Address: 0x24b118, Func Offset: 0x488
	// Line 2580, Address: 0x24b11c, Func Offset: 0x48c
	// Line 2575, Address: 0x24b124, Func Offset: 0x494
	// Line 2578, Address: 0x24b12c, Func Offset: 0x49c
	// Line 2580, Address: 0x24b140, Func Offset: 0x4b0
	// Line 2581, Address: 0x24b148, Func Offset: 0x4b8
	// Line 2583, Address: 0x24b154, Func Offset: 0x4c4
	// Line 2584, Address: 0x24b164, Func Offset: 0x4d4
	// Line 2585, Address: 0x24b174, Func Offset: 0x4e4
	// Line 2586, Address: 0x24b184, Func Offset: 0x4f4
	// Line 2588, Address: 0x24b194, Func Offset: 0x504
	// Line 2589, Address: 0x24b1a4, Func Offset: 0x514
	// Line 2591, Address: 0x24b1b4, Func Offset: 0x524
	// Line 2592, Address: 0x24b1cc, Func Offset: 0x53c
	// Line 2593, Address: 0x24b1e4, Func Offset: 0x554
	// Line 2595, Address: 0x24b1ec, Func Offset: 0x55c
	// Line 2593, Address: 0x24b1f0, Func Offset: 0x560
	// Line 2596, Address: 0x24b1f4, Func Offset: 0x564
	// Line 2599, Address: 0x24b218, Func Offset: 0x588
	// Line 2600, Address: 0x24b22c, Func Offset: 0x59c
	// Line 2605, Address: 0x24b264, Func Offset: 0x5d4
	// Func End, Address: 0x24b294, Func Offset: 0x604
	scePrintf("bhEff308 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEff308Drw(OR_WORK* orP) 
{
    R08_WORK* r08P;      
    int i;               
    NJS_POINT3COL* p3cP; 
    int* timP;          
   
    r08P = (R08_WORK*)orP->free4;
    
    njSetMatrix(NULL, cam.mtx);
    
    p3cP = &r08P->lne_p3c;
    timP = r08P->TimBuf;
    
    for (i = 0; i < r08P->prm_a.vtx_num; i++, timP++)
    {
        if (*timP != 0) 
        {
            p3cP->p   = r08P->VtxBuf[i];
            p3cP->col = (NJS_COLOR*)r08P->VtxCol[i];
            p3cP->tex = NULL;
            p3cP->num = 1;
            
            njDrawLine3D(p3cP, p3cP->num, 0x40);
        }
    }
}

// 100% matching!
static int ryLinerColor(int src_col, int dst_col, float rate)
{
    int rte; 
    int tmp; 
    int col; 
    
    rte = 256.0f * rate;
    
    col = (src_col  + ((rte * ((dst_col & 0xFF)     - (src_col & 0xFF)))     >> 8)) & 0xFF;
    col |= (src_col + ((rte * ((dst_col & 0xFF00)   - (src_col & 0xFF00)))   >> 8)) & 0xFF00;
    col |= (src_col + ((rte * ((dst_col & 0xFF0000) - (src_col & 0xFF0000))) >> 8)) & 0xFF0000;
    
    dst_col >>= 8;
    
    tmp = dst_col & 0xFF0000;
    
    src_col >>= 8;
    
    col |= ((src_col + ((rte * (tmp - (src_col & 0xFF0000))) >> 8)) << 8) & 0xFF000000;
    
    return col;
}

// 100% matching!
OR_WORK* rySetEffBlood(NJS_MATRIX* mtxP, NJS_POINT3* posP, NJS_POINT3* dirP, int typ_no)
{
    OR_WORK* orP; 
    PMB_WRK* pmbP;
    int mode;     
    R09_WORK* r09P; 
    static const Eff309PRM_WORK Eff309Prm[6] = 
	{
		{  0.5f, 0.98f, 4.0f,   1.0f, { 0, 0, 2,  5, -1, -1, -1, -1 }, 55.0f, 0.8f, 0xFFFFFFFF, 0xC0FFFFFF, -0.032666668f, 0 },
		{  0.5f, 0.98f, 2.0f,   1.1f, { 0, 0, 0,  1,  1,  2, -1, -1 }, 60.0f, 0.8f, 0xFFFFFFFF, 0xC0FFFFFF, -0.032666668f, 0 },
		{ 0.75f, 0.75f, 1.5f, 1.125f, { 0, 1, 2,  5,  6,  7, -1, -1 }, 45.0f, 0.8f, 0xFFFFFFFF, 0xC0FFFFFF, -0.032666668f, 0 },
		{  0.5f, 0.98f, 4.0f,   1.0f, { 0, 2, 5, -1, -1, -1, -1, -1 }, 55.0f, 0.8f, 0xFFFFFFFF, 0xC0FFFFFF, -0.032666668f, 2 },
		{  0.5f, 0.98f, 2.0f,   1.1f, { 0, 0, 1,  1,  2, -1, -1, -1 }, 60.0f, 0.8f, 0xFFFFFFFF, 0xC0FFFFFF, -0.032666668f, 2 },
		{ 0.75f, 0.75f, 1.5f, 1.125f, { 0, 1, 5,  6,  7, -1, -1, -1 }, 45.0f, 0.8f, 0xFFFFFFFF, 0xC0FFFFFF, -0.032666668f, 2 }
	};
    
    mode = 0;
    
    if ((typ_no & 0x80000000)) 
    {
        mode |= 0x1;
    }
    
    if ((typ_no & 0x40000000)) 
    {
        mode |= 0x2;
    }

	typ_no &= 0x3FFFFFFF;
    
    orP = bhSetRapEff(309, (void*)&Eff309Prm[typ_no], 12);
    
    if (orP != NULL)
    {
        pmbP = (PMB_WRK*)((char*)orP + 192);
        
        pmbP->vtx_mtxP = mtxP;
        pmbP->vtx_pos  = *posP;
        pmbP->vtx_dir  = *dirP;
            
        r09P = (R09_WORK*)orP->free4;
        
        r09P->texP   = &sys->ef_tlist;
        r09P->tex_id = sys->ef_tn[5];
        
        r09P->type = mode;
    }
    
    return orP;
}

// 99.88% matching
void bhEff309(OR_WORK* orP) 
{
    R09_WORK* r09P;   
    PMB_WRK* pmbP;    
    static const UV_WORK Tex5Buv[12] = 
	{
		{ 0.1875f, 0.4375f, 0.12109375f, 0.12109375f },
		{ 0.0625f, 0.4375f, 0.12109375f, 0.12109375f },
		{ 0.8125f, 0.3125f, 0.12109375f, 0.12109375f },
		{ 0.6875f, 0.3125f, 0.12109375f, 0.12109375f },
		{ 0.5625f, 0.3125f, 0.12109375f, 0.12109375f },
		{ 0.4375f, 0.3125f, 0.12109375f, 0.12109375f },
		{ 0.3125f, 0.3125f, 0.12109375f, 0.12109375f },
		{ 0.1875f, 0.3125f, 0.12109375f, 0.12109375f },
		{ 0.4375f, 0.3125f, 0.12109375f, 0.12109375f },
		{ 0.3125f, 0.3125f, 0.12109375f, 0.12109375f },
		{ 0.1875f, 0.3125f, 0.12109375f, 0.12109375f },
		{ 0.0625f, 0.3125f, 0.12109375f, 0.12109375f }
	};
    
    r09P = (R09_WORK*)orP->free4;
    pmbP = &r09P->prm_b;

    if (r09P->mode != 2) 
    {
        switch (r09P->mode) 
        {
        case 0:
        {
            int i;           
            rap_tex_typ* rtP;  

            rtP = r09P->RapTex;
            
            orP->func = (void*)bhEff309Drw;
            
            r09P->freeP = rtP;
            
            for (i = 5; i > 0; i--, rtP++) 
            {
                rtP->mode  = 0;
                rtP->nextP = &rtP[1];
            }
            
            rtP->mode  = 0;
            rtP->nextP = NULL;
            
            njSetMatrix(lcmat, pmbP->vtx_mtxP);
            
            njInvertMatrix(lcmat);
            
            if (!(r09P->type & 0x1)) 
            {
                njCalcPoint(lcmat, &pmbP->vtx_pos, &pmbP->vtx_pos);
            }
            
            if (!(r09P->type & 0x2)) 
            {
                njCalcVector(lcmat, &pmbP->vtx_dir, &pmbP->vtx_dir);
            }
            
            njUnitVector(&pmbP->vtx_dir);
            
            r09P->mode++;
        }
        case 1:
        {
            int i;      
            char* timP; 

            timP = r09P->prm_a.SetTim;
            
            for (i = 6; i > 0; i--, timP++)
            {
                if ((*timP)-- == 0) 
                {
                    rap_tex_typ* rtP; 
                    NJS_POINT3 pos;  
                    NJS_POINT3* dirP; 
                    float sp;         

                    rtP         = r09P->freeP;
                    r09P->freeP = rtP->nextP;
                    
                    rtP->mode = -1;
                    
                    njCalcPoint(pmbP->vtx_mtxP, &pmbP->vtx_pos, &pos);
                    
                    ryRapDspSet(&pos, &rtP->dsp_wrk, r09P->prm_a.scale);
                    
                    njSetMatrix(lcmat, pmbP->vtx_mtxP);
                    
                    njRotateY(lcmat, 182.04445f * (r09P->prm_a.ang_rand * ((-rand() / -2147483648.0f) - 0.5f)));
                    njRotateX(lcmat, 182.04445f * (r09P->prm_a.ang_rand * ((-rand() / -2147483648.0f) - 0.5f)));
                    
                    dirP = &rtP->mov_wrk.vtx_vel;
                    
                    sp = r09P->prm_a.speed + (r09P->prm_a.spd_rand * ((-rand() / -2147483648.0f) - 0.5f));
                    
                    njCalcVector(lcmat, &pmbP->vtx_dir, dirP);
                    
                    dirP->x *= sp;
                    dirP->y *= sp;
                    dirP->z *= sp;
                    
                    rtP->anm_wrk.uv_tabP = (UV_WORK*)Tex5Buv;
                    rtP->anm_wrk.anm_no  = 12;
                    
                    ryRapAnmColSet(&rtP->anm_wrk, r09P->prm_a.col_src, r09P->prm_a.col_dst, 12);
                }
            }
            
            break;
        }
        }
    }
    
    {
        int i;            
        rap_tex_typ* rtP; 

        rtP = r09P->RapTex;
        
        r09P->busyP = NULL;
        
        for (i = 5; i > 0; i--, rtP++) 
        {
            if (rtP->mode != 0)
            {
                NJS_POINT3* dirP; 
                float acl;        

                dirP = &rtP->mov_wrk.vtx_vel; 
                
                acl = r09P->prm_a.accel;
                
                njAddVector(&rtP->dsp_wrk.vtx_pos, dirP);
                
                dirP->x *= acl;
                dirP->y *= acl;
                dirP->z *= acl;
                
                dirP->y += r09P->prm_a.gravity;
                
                rtP->dsp_wrk.vtx_scl *= r09P->prm_a.scl_accel;
                
                if (ryRapTexAnm(&rtP->anm_wrk, &rtP->dsp_wrk, 1) >= 0) 
                {
                    rtP->nextP  = r09P->busyP;
                    r09P->busyP = rtP;
                } 
                else
                {
                    rtP->mode = 0;
                }
            }
        }
    }
    
    if (r09P->busyP == NULL) 
    {
        orP->flg = 0;
    }
    else 
    {
        sys->ef_fnc[sys->ef_fncn++] = (O_WRK*)orP;
    }
} 

// 100% matching!
void bhEff309Drw(OR_WORK* orP) 
{
    R09_WORK* r09P;

    r09P = (R09_WORK*)orP->free4;
    
    njTextureFilterMode(1);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    ryRapTexDrw(r09P->texP, r09P->tex_id + r09P->prm_a.pal_bank, r09P->busyP);
}

// 100% matching!
static void ryRapTexDrw(NJS_TEXLIST* texP, int tex_id, rap_tex_typ* rtP)
{
	NJS_POINT3 scl;
    
    njSetTexture(texP);
    njSetTextureNum(tex_id);
    
    njDrawTexture3DExStart(1);
    
    njPushMatrixEx();
    
    for (; rtP != NULL; rtP = rtP->nextP) 
    {
        njSetMatrix(NULL, cam.mtx);
        
        njTranslateV(NULL, &rtP->dsp_wrk.vtx_pos);
        njUnitRotPortion(NULL);
        
        scl.x = scl.y = scl.z = rtP->dsp_wrk.vtx_scl;
        
        njScaleEx(&scl);
        
        njDrawTexture3DExSetData(rtP->dsp_wrk.VtxBuf, 4);
    } 
    
    njPopMatrixEx();
    
    njDrawTexture3DExEnd();
}

// 100% matching!
static int ryRapTexAnm(ANM_WORK* anmP, DSP_WRK* dspP, int bol)
{
    int anm_no; 
    UV_WORK* uvP; 
    float* tvP;   
    unsigned int col; 
    
    anm_no = anmP->anm_no;
    
    if (anm_no >= 0) 
    {
        col = anmP->color;
        
        uvP = &anmP->uv_tabP[anm_no];
        tvP = &dspP->VtxBuf->u; 
        
        *tvP++     = uvP->u;
        *tvP++     = uvP->v;
        *(int*)tvP = col;

        tvP += 4;
        
        *tvP++     = uvP->u;
        *tvP++     = uvP->v + uvP->ys;
        *(int*)tvP = col;

        tvP += 4;
        
        *tvP++     = uvP->u + uvP->xs;
        *tvP++     = uvP->v;
        *(int*)tvP = col;

        tvP += 4;
        
        *tvP++     = uvP->u + uvP->xs;
        *tvP++     = uvP->v + uvP->ys;
        *(int*)tvP = col;
        
        if (bol != FALSE) 
        {
            anmP->anm_no--;
            
            anmP->color += anmP->col_add;
            anmP->color -= anmP->col_sub;
        }
    }
    
    return anm_no;
}

// 100% matching!
static void ryRapDspSet(NJS_POINT3* posP, DSP_WRK* dspP, float scl)
{
    float* vbP;
    float tmp; // not from DWARF

    tmp = 0.5f;
    
    dspP->vtx_scl = scl;
    dspP->vtx_pos = *posP;

    vbP = &dspP->VtxBuf->x;  
    
    *vbP++ = -tmp;
    *vbP++ = tmp;
    *vbP   = 0;

    vbP += 4;  
    
    *vbP++ = -tmp;
    *vbP++ = -tmp;
    *vbP   = 0;

    vbP += 4;
    
    *vbP++ = tmp;
    *vbP++ = tmp;
    *vbP   = 0;

    vbP += 4;
    
    *vbP++ = tmp;
    *vbP++ = -tmp;
    *vbP   = 0;
}

#pragma divbyzerocheck on 

// 100% matching!
static void ryRapAnmColSet(ANM_WORK* anmP, int src_col, int dst_col, int col_cnt)
{
    int tmp;            
    unsigned int* addP, *subP; 
    
    addP = (unsigned int*)&anmP->col_add; 
    subP = (unsigned int*)&anmP->col_sub; 
    
    anmP->color = src_col;      
    
    tmp = ((dst_col & 0xFF)     - (src_col & 0xFF))     / col_cnt;
    
    if (tmp < 0)
    {
        *subP = ~tmp & 0xFF;
    } 
    else 
    {
        *addP = tmp  & 0xFF;
    }
    
    tmp = ((dst_col & 0xFF00)   - (src_col & 0xFF00))   / col_cnt;
    
    if (tmp < 0) 
    {
        *subP |= ~tmp & 0xFF00;
    }
    else 
    {
        *addP |= tmp  & 0xFF00;
    }
    
    tmp = ((dst_col & 0xFF0000) - (src_col & 0xFF0000)) / col_cnt;
    
    if (tmp < 0) 
    {
        *subP |= ~tmp & 0xFF0000;
    }
    else
    {
        *addP |= tmp  & 0xFF0000;
    }
    
    src_col >>= 16;
    dst_col >>= 16;
    
    tmp = ((dst_col & 0xFF00)   - (src_col & 0xFF00))   / col_cnt;
    
    if (tmp < 0) 
    {
        *subP |= (~tmp & 0xFF00) << 16;
    } 
    else 
    {
        *addP |= (tmp & 0xFF00)  << 16;
    }
}

#pragma divbyzerocheck off

// 100% matching!
void bhEff30a(OR_WORK* orP)
{
    R0A_WORK* r0aP; 

    r0aP = (R0A_WORK*)orP->free4; 

    switch (r0aP->prm_a.type) 
    {                               
    case 0:                                        
        break;
    case 1:                                        
        cam.ofx = cam.ofy = cam.ofz = 0; 
        break;
    case 2:                                        
        if ((sys->cb_flg & 0x4)) 
        {
            *(int*)orP = 0; 
            break;
        }
        
        if ((sys->sp_flg & 0x1))
        {
            switch (r0aP->mode)
            {                      
            case 0:                                 
                r0aP->ang_x = r0aP->ang_y = r0aP->prm_a.ang_fst;
                
                r0aP->mode++;
            case 1:                                 
                njSetMatrix(lcmat, cam.mtx);
                
                r0aP->off_pos.y = r0aP->prm_a.y_rang * njSin(r0aP->ang_y);
                r0aP->off_pos.x = r0aP->prm_a.x_rang * njCos(r0aP->ang_x);
                
                r0aP->off_pos.z = 0; 
                
                njCalcVector(lcmat, &r0aP->off_pos, &r0aP->off_pos);
                
                r0aP->ang_x += r0aP->prm_a.add_ax;
                r0aP->ang_y += r0aP->prm_a.add_ay;
                
                r0aP->prm_a.x_rang *= r0aP->prm_a.x_rate;
                r0aP->prm_a.y_rang *= r0aP->prm_a.y_rate;
                
                if ((r0aP->prm_a.x_rang + r0aP->prm_a.y_rang) < 0.01f) 
                {
                    r0aP->dst_pos.x = r0aP->dst_pos.y = r0aP->dst_pos.z = 0;
                    
                    *(int*)orP = 0; 
                }
                
                break;
            }
            
            njAddVector((NJS_VECTOR*)&cam.ofx, &r0aP->off_pos);
        }
        
        break;
    }
}

// 100% matching!
void bhEff349(OR_WORK* orP) 
{
    R49_WORK* r49P;
    
    r49P = (R49_WORK*)orP->free4;

    if (r49P->fnc_prcP != NULL) 
    {
        r49P->fnc_prcP(&r49P->free);
    }
    
    if (r49P->fnc_drwP != NULL) 
    {
        orP->func                   = (void*)r49P->fnc_drwP;
        sys->ef_fnc[sys->ef_fncn++] = (O_WRK*)orP;
    }
}

// 100% matching!
OR_WORK* rySetEffBlood2(NJS_MATRIX* mtxP, NJS_POINT3* posP, NJS_POINT3* dirP, int typ_no)
{
    OR_WORK* orP;
    PMB_WRK* pmbP;
    int mode;
    R0B_WORK* r0bP;
    EFF30bPRM_WORK Eff30bPrm[6] = 
	{
		{ 0.25f, 0.5f, 0.8f, 15.0f, 0.02f, 16, 0xF0802000, 0xF0400000, -0.03266667f,  56, 16, 0.96f },
		{  0.4f, 1.0f, 0.9f, 25.0f, 0.05f, 16, 0xF0802000, 0xF0400000, -0.03266667f,  56, 16, 0.96f },
		{  0.4f, 4.0f, 0.8f, 40.0f, 0.05f, 16, 0xF0802000, 0xF0400000, -0.03266667f, 448,  0, 0.98f },
		{  1.0f, 2.0f, 0.8f, 20.0f,  0.1f,  8, 0xF0004030, 0xF0404020, -0.03266667f,  56, 16,  0.9f },
		{  1.5f, 3.0f, 0.8f, 20.0f, 0.08f, 12, 0xF0004030, 0xF0404020, -0.03266667f,  56, 16, 0.98f },
		{  2.0f, 4.0f, 0.8f, 30.0f, 0.06f, 16, 0xF0104030, 0xF0404020, -0.03266667f,  56, 16, 0.99f }
	};
    
    mode = 0;
    
    if ((typ_no & 0x80000000)) 
    {
        mode |= 0x1;
    }
    
    if ((typ_no & 0x40000000)) 
    {
        mode |= 0x2;
    }

	typ_no &= 0x3FFFFFFF;
    
    orP = bhSetRapEff(311, (void*)&Eff30bPrm[typ_no], 12);
    
    if (orP != NULL)
    {
        pmbP = (PMB_WRK*)((char*)orP + 192);
        
        pmbP->vtx_mtxP = mtxP;
        pmbP->vtx_pos  = *posP;
        pmbP->vtx_dir  = *dirP;
            
        r0bP = (R0B_WORK*)orP->free4;
        
        r0bP->texP   = &sys->ef_tlist;
        r0bP->tex_id = sys->ef_tn[4];
        
        r0bP->type = mode;
    }
    
    return orP;
}

// 
// Start address: 0x24c070
void bhEff30b(OR_WORK* orP)
{
	eff30b_vtx_buf_typ* vbP;
	NJS_POINT3* dirP;
	float max;
	float min;
	float rng;
	VTXBUF_WORK* vtxP;
	int num;
	//eff30b_vtx_buf_typ* vbP;
	//int num;
	//eff30b_vtx_buf_typ* vbP;
	//_anon38* pmbP;
	R0B_WORK* r0bP;
	// Line 3191, Address: 0x24c070, Func Offset: 0
	// Line 3196, Address: 0x24c0a8, Func Offset: 0x38
	// Line 3192, Address: 0x24c0ac, Func Offset: 0x3c
	// Line 3196, Address: 0x24c0b0, Func Offset: 0x40
	// Line 3199, Address: 0x24c0cc, Func Offset: 0x5c
	// Line 3201, Address: 0x24c0d8, Func Offset: 0x68
	// Line 3204, Address: 0x24c0dc, Func Offset: 0x6c
	// Line 3202, Address: 0x24c0e0, Func Offset: 0x70
	// Line 3201, Address: 0x24c0e4, Func Offset: 0x74
	// Line 3202, Address: 0x24c0e8, Func Offset: 0x78
	// Line 3204, Address: 0x24c0ec, Func Offset: 0x7c
	// Line 3205, Address: 0x24c0f8, Func Offset: 0x88
	// Line 3206, Address: 0x24c104, Func Offset: 0x94
	// Line 3207, Address: 0x24c128, Func Offset: 0xb8
	// Line 3208, Address: 0x24c14c, Func Offset: 0xdc
	// Line 3215, Address: 0x24c158, Func Offset: 0xe8
	// Line 3217, Address: 0x24c160, Func Offset: 0xf0
	// Line 3215, Address: 0x24c164, Func Offset: 0xf4
	// Line 3217, Address: 0x24c170, Func Offset: 0x100
	// Line 3215, Address: 0x24c178, Func Offset: 0x108
	// Line 3219, Address: 0x24c188, Func Offset: 0x118
	// Line 3220, Address: 0x24c19c, Func Offset: 0x12c
	// Line 3221, Address: 0x24c1a8, Func Offset: 0x138
	// Line 3222, Address: 0x24c1b4, Func Offset: 0x144
	// Line 3223, Address: 0x24c1c0, Func Offset: 0x150
	// Line 3224, Address: 0x24c1d0, Func Offset: 0x160
	// Line 3225, Address: 0x24c1d8, Func Offset: 0x168
	// Line 3230, Address: 0x24c1dc, Func Offset: 0x16c
	// Line 3237, Address: 0x24c1e8, Func Offset: 0x178
	// Line 3239, Address: 0x24c1f4, Func Offset: 0x184
	// Line 3241, Address: 0x24c1f8, Func Offset: 0x188
	// Line 3244, Address: 0x24c200, Func Offset: 0x190
	// Line 3246, Address: 0x24c20c, Func Offset: 0x19c
	// Line 3247, Address: 0x24c214, Func Offset: 0x1a4
	// Line 3248, Address: 0x24c264, Func Offset: 0x1f4
	// Line 3252, Address: 0x24c270, Func Offset: 0x200
	// Line 3254, Address: 0x24c278, Func Offset: 0x208
	// Line 3255, Address: 0x24c2c0, Func Offset: 0x250
	// Line 3256, Address: 0x24c308, Func Offset: 0x298
	// Line 3258, Address: 0x24c354, Func Offset: 0x2e4
	// Line 3259, Address: 0x24c360, Func Offset: 0x2f0
	// Line 3262, Address: 0x24c378, Func Offset: 0x308
	// Line 3265, Address: 0x24c388, Func Offset: 0x318
	// Line 3266, Address: 0x24c38c, Func Offset: 0x31c
	// Line 3267, Address: 0x24c390, Func Offset: 0x320
	// Line 3269, Address: 0x24c394, Func Offset: 0x324
	// Line 3270, Address: 0x24c3a8, Func Offset: 0x338
	// Line 3272, Address: 0x24c3b8, Func Offset: 0x348
	// Line 3273, Address: 0x24c3e0, Func Offset: 0x370
	// Line 3274, Address: 0x24c3e8, Func Offset: 0x378
	// Line 3278, Address: 0x24c3f4, Func Offset: 0x384
	// Line 3279, Address: 0x24c434, Func Offset: 0x3c4
	// Line 3284, Address: 0x24c438, Func Offset: 0x3c8
	// Line 3286, Address: 0x24c444, Func Offset: 0x3d4
	// Line 3287, Address: 0x24c45c, Func Offset: 0x3ec
	// Line 3288, Address: 0x24c47c, Func Offset: 0x40c
	// Line 3290, Address: 0x24c494, Func Offset: 0x424
	// Line 3291, Address: 0x24c4a4, Func Offset: 0x434
	// Line 3293, Address: 0x24c4b4, Func Offset: 0x444
	// Line 3294, Address: 0x24c4dc, Func Offset: 0x46c
	// Line 3296, Address: 0x24c4f8, Func Offset: 0x488
	// Line 3297, Address: 0x24c504, Func Offset: 0x494
	// Line 3300, Address: 0x24c510, Func Offset: 0x4a0
	// Line 3301, Address: 0x24c528, Func Offset: 0x4b8
	// Line 3303, Address: 0x24c538, Func Offset: 0x4c8
	// Line 3307, Address: 0x24c598, Func Offset: 0x528
	// Line 3308, Address: 0x24c59c, Func Offset: 0x52c
	// Line 3311, Address: 0x24c5c4, Func Offset: 0x554
	// Line 3312, Address: 0x24c5c8, Func Offset: 0x558
	// Func End, Address: 0x24c600, Func Offset: 0x590
	scePrintf("bhEff30b - UNIMPLEMENTED!\n");
}

// 100% matching!
static void bhEff30bDrw(OR_WORK* orP)
{
    R0B_WORK* r0bP;          
    VTXBUF_WORK* vtxP;      
    int num;                
    eff30b_vtx_buf_typ* vbP; 
    float scl;             
    static NJS_TEXTURE_VTX VtxBuf[4] = 
	{
		{ -1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 0x00000000 },
		{ -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0x00000000 },
		{  1.0f,  1.0f, 0.0f, 1.0f, 0.0f, 0x00000000 },
		{  1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 0x00000000 }
	};
    
    r0bP = (R0B_WORK*)orP->free4;
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njTextureFilterMode(0);
    
    njSetMatrix(NULL, cam.mtx);
    njSetTexture(r0bP->texP);
    
    njPushMatrixEx();
    
    vbP = r0bP->vtx_bufP;
    
    if (vbP != NULL) 
    {
        num = 28;
        
        do 
        {
            vtxP = vbP->VtxBuf;
            
            do 
            {
                scl = vtxP->scl * r0bP->eff_scale;
                
                njSetMatrix(NULL, cam.mtx);
                
                njTranslateV(NULL, &vtxP->pos);
                njUnitRotPortion(NULL);
                
                njScale(NULL, scl, scl, scl);
                
                VtxBuf[0].col = VtxBuf[1].col = VtxBuf[2].col = VtxBuf[3].col = vtxP->col;
                
                njSetTextureNum(r0bP->tex_id + (vtxP->time & 3));
                
                njDrawTexture3DEx(VtxBuf, 4, 1);
                
                num--;
                vtxP++;
            } while (num > 0);
            
            vbP = vbP->nextP;
            num = 28;
        } while (vbP != NULL);
    }
    
    njPopMatrixEx();
}

// 100% matching!
void bhEff30c(OR_WORK* orP) 
{
    R0_WK* r0cP;
    
    r0cP = (R0_WK*)orP->free4; 

    switch (r0cP->mode) 
    {                              
    case 0:
        orP->func = (void*)bhEff30cDrw;
        
        r0cP->erase = -1;
        
        r0cP->mtxP = (NJS_MATRIX*)r0cP->mtx_buf;
        
        r0cP->mode++;
    case 1:
        njSetMatrix(r0cP->mtxP, r0cP->prm.mtxP);
        
        njTranslate(r0cP->mtxP, r0cP->prm.pos[0], r0cP->prm.pos[1], r0cP->prm.pos[2]);
        njRotateXYZ(r0cP->mtxP, r0cP->prm.ang[0], r0cP->prm.ang[1], r0cP->prm.ang[2]);
        
        if (r0cP->erase == 0) 
        {
            *(int*)orP = 0; 
        }
        else 
		{
        	sys->ef_fnc[sys->ef_fncn++] = (O_WRK*)orP;
		}
		
        break;
    }
}

// 100% matching!
static void bhEff30cDrw(OR_WORK* orP)
{
    R0_WK* r0cP;
    
    r0cP = (R0_WK*)orP->free4;

    if (r0cP->prm.texP != NULL) 
    {
        njSetTexture(r0cP->prm.texP);
    }
    
    njPushMatrix(cam.mtx);
    njMultiMatrix(NULL, r0cP->mtxP);
    
    njCnkEasyMultiDrawModel((NJS_CNK_MODEL*)r0cP->prm.mdlP);
    
    njPopMatrixEx();
}
