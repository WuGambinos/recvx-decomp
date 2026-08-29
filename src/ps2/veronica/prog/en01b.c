#include "../../../ps2/veronica/prog/en01b.h"
#include "../../../ps2/veronica/prog/effsub3.h"
#include "../../../ps2/veronica/prog/en01.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/rutchk.h"
#include "../../../ps2/veronica/prog/zonzon.h"

void (*bhEne01_MoveTypeB[16])(BH_PWORK*) = 
{
	bhEne01_MVType00B,
	bhEne01_MVType00B,
	bhEne01_MVType02B,
	bhEne01_MVType02B,
	bhEne01_MVType00B,
	bhEne01_MVType00B,
	bhEne01_MVType02B,
	bhEne01_MVType02B,
	bhEne01_MVType00B,
	bhEne01_MVType02B,
	bhEne01_MVType00B,
	bhEne01_MVType00B,
	bhEne01_MVType00B,
	bhEne01_MVType00B,
	bhEne01_MVType00B,
	bhEne01_MVType00B
};
void (*bhEne01_MoveMode2B[17])(BH_PWORK*) = 
{
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_MV13B,
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_Dummy
};
void (*bhEne01_NageTypeB[16])(BH_PWORK*) = 
{
	bhEne01_NGType00B,
	bhEne01_NGType00B,
	bhEne01_NGType00B,
	bhEne01_NGType00B,
	bhEne01_NGType00B,
	bhEne01_NGType00B,
	bhEne01_NGType00B,
	bhEne01_NGType00B,
	bhEne01_NGType00B,
	bhEne01_NGType00B,
	bhEne01_NGType00B,
	bhEne01_NGType00B,
	bhEne01_NGType00B,
	bhEne01_NGType00B,
	bhEne01_NGType00B,
	bhEne01_NGType00B
};
void (*bhEne01_NageMode2B[4])(BH_PWORK*) = 
{
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_NG03B
};
void (*bhEne01_DamageTypeB[16])(BH_PWORK*) =
{
	bhEne01_DGType00B,
	bhEne01_DGType00B,
	bhEne01_DGType02B,
	bhEne01_DGType02B,
	bhEne01_DGType00B,
	bhEne01_DGType00B,
	bhEne01_DGType02B,
	bhEne01_DGType02B,
	bhEne01_DGType00B,
	bhEne01_DGType02B,
	bhEne01_DGType00B,
	bhEne01_DGType00B,
	bhEne01_DGType00B,
	bhEne01_DGType00B,
	bhEne01_DGType00B,
	bhEne01_DGType00B
};
void (*bhEne01_DamageMode2B[17])(BH_PWORK*) = 
{
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_DG05B,
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_DG09B,
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_DG12B,
	bhEne01_DG13B,
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_Dummy
}; 
void (*bhEne01_DieTypeB[16])(BH_PWORK*) = 
{
	bhEne01_DDType00B,
	bhEne01_DDType00B,
	bhEne01_DDType02B,
	bhEne01_DDType02B,
	bhEne01_DDType00B,
	bhEne01_DDType00B,
	bhEne01_DDType02B,
	bhEne01_DDType02B,
	bhEne01_DDType00B,
	bhEne01_DDType02B,
	bhEne01_DDType00B,
	bhEne01_DDType00B,
	bhEne01_DDType00B,
	bhEne01_DDType00B,
	bhEne01_DDType00B,
	bhEne01_DDType00B,
};
void (*bhEne01_DieMode2B[4])(BH_PWORK*) = 
{
	bhEne01_Dummy,
	bhEne01_Dummy,
	bhEne01_DD02B,
	bhEne01_Dummy
};

// 100% matching!
void bhEne01_Dummy()
{
	
}

// 100% matching!
void bhEne01_Brain02B(BH_PWORK* epw)
{
    unsigned char rid;
	NJS_POINT3 pos;

    EXP0_UC(0x28) |= 0x40;
    if (EXP0_UC(0x28) & 0x40)
    {
        rid = bhCheckRoute((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px, &pos);
        if (rid != 0xFF)
        {
            EXP0_F(0x58) = pos.x;
            EXP0_F(0x60) = pos.z;
        } 
        else
        {
            EXP0_F(0x58) = plp->px;
            EXP0_F(0x60) = plp->pz;
        }
    }
}

// 100% matching!
void bhEne01_MVType00B(BH_PWORK* epw)
{
	bhEne01_MoveMode2B[epw->mode2](epw);
}

// 100% matching!
void bhEne01_MVType02B(BH_PWORK* epw) 
{
    if (bhEne_EnemyAtariCheck((NJS_POINT3*)&plp->px, plp->flr_no, epw->id, 0) != NULL) 
    {
        EXP0_I(0x40) |=  0x20000000;
    }
    else 
    {
        EXP0_I(0x40) &= ~0x20000000;
    }
    
    if ((!(plp->flg & 0x4)) && (epw->mode2 == 3) && (bhEne01_EatCheck(epw, 2730, 5.5f, 0) != 0))
    {
        epw->mode0 = 2;
        epw->mode1 = 0;
        epw->mode2 = 3;
        epw->mode3 = 0;
        
        plp->flg |= 0x4;
    }
    else
    {
        if ((epw->mode1 & 0x1)) 
        {
            bhEne01_Brain02B(epw);
        }
        
        bhEne01_MoveMode2B[epw->mode2 + 10](epw);
    }
}

// 100% matching!
void bhEne01_MV13B(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        bhEne_ChgMtn(epw, 42, 0, 15);
        EXP0_I(0x40) &= ~0x1000000;
        EXP0_I(0x40) |= 0x2000000;
        epw->way = 256;
        epw->mode3++;

    case 1:
        ikou(epw, (NJS_POINT3*) (epw->exp0 + 0x58), epw->way);
        break;
    }
}

// 100% matching!
void bhEne01_NGType00B(BH_PWORK* epw)
{
    if (epw->mode3 == 0) 
    {
        if (bhCdirCheck(plp->ay, epw->ay) == 0) 
        {
            EXP0_I(0x40) |=  0x4000;
        }
        else 
        {
            EXP0_I(0x40) &= ~0x4000;
        }
    }
    
    bhEne01_NageMode2B[epw->mode2](epw);
}

// 
// Start address: 0x18a7a0
void bhEne01_NG03B(BH_PWORK* epw)
{
	int frm;
	BH_PWORK* sepw;
	BH_PWORK* pl;
	BH_PWORK* epp;
	// Line 447, Address: 0x18a7a0, Func Offset: 0
	// Line 449, Address: 0x18a7b4, Func Offset: 0x14
	// Line 455, Address: 0x18a7b8, Func Offset: 0x18
	// Line 448, Address: 0x18a7bc, Func Offset: 0x1c
	// Line 449, Address: 0x18a7c0, Func Offset: 0x20
	// Line 455, Address: 0x18a7c4, Func Offset: 0x24
	// Line 458, Address: 0x18a7f8, Func Offset: 0x58
	// Line 459, Address: 0x18a820, Func Offset: 0x80
	// Line 460, Address: 0x18a838, Func Offset: 0x98
	// Line 463, Address: 0x18a840, Func Offset: 0xa0
	// Line 465, Address: 0x18a844, Func Offset: 0xa4
	// Line 460, Address: 0x18a848, Func Offset: 0xa8
	// Line 463, Address: 0x18a850, Func Offset: 0xb0
	// Line 464, Address: 0x18a854, Func Offset: 0xb4
	// Line 465, Address: 0x18a858, Func Offset: 0xb8
	// Line 466, Address: 0x18a85c, Func Offset: 0xbc
	// Line 467, Address: 0x18a860, Func Offset: 0xc0
	// Line 468, Address: 0x18a874, Func Offset: 0xd4
	// Line 471, Address: 0x18a880, Func Offset: 0xe0
	// Line 473, Address: 0x18a894, Func Offset: 0xf4
	// Line 474, Address: 0x18a89c, Func Offset: 0xfc
	// Line 476, Address: 0x18a8a4, Func Offset: 0x104
	// Line 480, Address: 0x18a8ac, Func Offset: 0x10c
	// Line 482, Address: 0x18a8bc, Func Offset: 0x11c
	// Line 480, Address: 0x18a8c0, Func Offset: 0x120
	// Line 482, Address: 0x18a8c8, Func Offset: 0x128
	// Line 484, Address: 0x18a8e4, Func Offset: 0x144
	// Line 486, Address: 0x18a8f8, Func Offset: 0x158
	// Line 487, Address: 0x18a920, Func Offset: 0x180
	// Line 490, Address: 0x18a928, Func Offset: 0x188
	// Line 494, Address: 0x18a954, Func Offset: 0x1b4
	// Line 495, Address: 0x18a95c, Func Offset: 0x1bc
	// Line 498, Address: 0x18a968, Func Offset: 0x1c8
	// Line 501, Address: 0x18a970, Func Offset: 0x1d0
	// Line 503, Address: 0x18a974, Func Offset: 0x1d4
	// Line 505, Address: 0x18a984, Func Offset: 0x1e4
	// Line 507, Address: 0x18a990, Func Offset: 0x1f0
	// Line 508, Address: 0x18a99c, Func Offset: 0x1fc
	// Line 509, Address: 0x18a9a4, Func Offset: 0x204
	// Line 512, Address: 0x18a9b0, Func Offset: 0x210
	// Line 515, Address: 0x18a9bc, Func Offset: 0x21c
	// Line 517, Address: 0x18a9cc, Func Offset: 0x22c
	// Line 520, Address: 0x18a9d4, Func Offset: 0x234
	// Line 517, Address: 0x18a9d8, Func Offset: 0x238
	// Line 518, Address: 0x18a9e4, Func Offset: 0x244
	// Line 519, Address: 0x18a9f8, Func Offset: 0x258
	// Line 520, Address: 0x18aa0c, Func Offset: 0x26c
	// Line 525, Address: 0x18aa10, Func Offset: 0x270
	// Line 527, Address: 0x18aa28, Func Offset: 0x288
	// Line 528, Address: 0x18aa30, Func Offset: 0x290
	// Line 531, Address: 0x18aa3c, Func Offset: 0x29c
	// Line 533, Address: 0x18aa48, Func Offset: 0x2a8
	// Line 534, Address: 0x18aa4c, Func Offset: 0x2ac
	// Line 536, Address: 0x18aa50, Func Offset: 0x2b0
	// Line 537, Address: 0x18aa60, Func Offset: 0x2c0
	// Line 538, Address: 0x18aa68, Func Offset: 0x2c8
	// Line 541, Address: 0x18aa74, Func Offset: 0x2d4
	// Line 545, Address: 0x18aa80, Func Offset: 0x2e0
	// Line 546, Address: 0x18aa98, Func Offset: 0x2f8
	// Line 547, Address: 0x18aaa0, Func Offset: 0x300
	// Line 549, Address: 0x18aaac, Func Offset: 0x30c
	// Line 554, Address: 0x18aab8, Func Offset: 0x318
	// Line 557, Address: 0x18aae8, Func Offset: 0x348
	// Line 558, Address: 0x18aaec, Func Offset: 0x34c
	// Line 559, Address: 0x18aaf4, Func Offset: 0x354
	// Line 560, Address: 0x18aaf8, Func Offset: 0x358
	// Line 558, Address: 0x18aafc, Func Offset: 0x35c
	// Line 562, Address: 0x18ab00, Func Offset: 0x360
	// Line 558, Address: 0x18ab04, Func Offset: 0x364
	// Line 559, Address: 0x18ab0c, Func Offset: 0x36c
	// Line 560, Address: 0x18ab10, Func Offset: 0x370
	// Line 561, Address: 0x18ab14, Func Offset: 0x374
	// Line 562, Address: 0x18ab18, Func Offset: 0x378
	// Line 563, Address: 0x18ab1c, Func Offset: 0x37c
	// Line 567, Address: 0x18ab20, Func Offset: 0x380
	// Func End, Address: 0x18ab38, Func Offset: 0x398
	scePrintf("bhEne01_NG03B - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne01_DGType00B(BH_PWORK* epw)
{
	bhEne01_DamageMode2B[epw->mode2](epw);
}

// 100% matching!
void bhEne01_DGType02B(BH_PWORK* epw)
{
	bhEne01_DamageMode2B[epw->mode2 + 10](epw);
}

// 100% matching!
void bhEne01_DDType00B(BH_PWORK* epw)
{
	bhEne01_DieMode2B[epw->mode2](epw);
}

// 100% matching!
void bhEne01_DDType02B(BH_PWORK* epw)
{
	bhEne01_DieMode2B[epw->mode2](epw);
}

// 100% matching!
void bhEne01_DG05B(BH_PWORK* epw)
{
    BH_PWORK* epp; 
    O_WORK* owk;   
    NJS_POINT3 ps; 
    int frm;       
    
    epp = (BH_PWORK*)epw->lkwkp;

    switch (epw->mode3) 
    {
    case 0:
        bhEne_ChgMtn(epw, 224, 2293760, 0);
        
        EXP0_I(64) &= ~0x3000000;
        
        npCutSkin(epp, 1, 1, 9, 0, 0, 0);
        npCutSkin(epp, 0, 1, 9, 0, 0, 0);
        
        epw->flg   &= ~0x80;
        epw->stflg &= ~0x8;
        
        epw->flg |= 0x20;
        
        epw->px = epp->px;
        epw->py = epp->py;
        epw->pz = epp->pz;
        
        epw->ay = epp->ay;
        
        epw->flr_no = epp->flr_no;
        
        EXP0_I(124) = -1;
        
        epw->flg |= 0x8;
        
        EXP0_I(64) &= ~0xF;
        EXP0_I(64) |=  0x4;
        
        epw->mode3++;
    case 1:
        frm = epw->frm_no / 65536;
        
        if ((frm == 55) || (frm == 58)) 
        {
            bhEne01_SePlay(epp, (NJS_POINT3*)&epp->mlwP->owP[9].mtx[12], 8963);
        }
        
        if (((frm <= 36) == 0) && ((frm % 2) == 0)) 
        {
            ps.x = 2.0f - (4.0f * (-rand() / -2.1474836E9f));
            ps.y = 0;
            ps.z = 0;
            
            epp->djnt_no = 9;
            bhEne_SetBlood2(epp, 1, &ps, 0);
            
            epp->djnt_no = 1;
            bhEne_SetBlood2(epp, 1, &ps, 0);
        }
        
        if (frm == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
        {
            owk = epw->mlwP->owP;
            
            epw->px = owk[8].mtx[12];
            epw->pz = owk[8].mtx[14];
            
            bhEne_ChgMtn(epw, 39, 0, 0);
            
            EXP0_I(64) &= ~0x3000000;
            
            epw->ct0 = 20;
            
            epw->mode3++;
        }
        
        break;
    case 2:
        if (epw->ct0-- != 0) 
        {
            if (epw->hp < 0)
            {
                epw->mode0 = 4;
                epw->mode1 = 0;
                epw->mode2 = 2;
                epw->mode3 = 0;
                break;
            }
            
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;
            
            epw->type = 2;
            
            EXP0_I(64) &= ~0xF;
            EXP0_I(64) |=  0x4;
            
            epw->flg |= 0x20;
        }
        
        break;
    }
}

// 99.92% matching
void bhEne01_DG09B(BH_PWORK* epw)
{
    BH_PWORK* epp; 
    O_WORK* owk;   
    NJS_POINT3 ps; 
	int frm;       

    epp = (BH_PWORK*)epw->lkwkp;

    switch (epw->mode3) 
    {
    case 0:
        npCutSkin(epp, 1, 1, 9, 0.0f, 0.0f, 0.0f);
        npCutSkin(epp, 0, 1, 9, 0.0f, 0.0f, 0.0f);

        epw->flg   &= ~0x80;
        epw->stflg &= ~0x8;
        
        epw->flg |= 0x20;
        
        epw->px = epp->px;
        epw->py = epp->py;
        epw->pz = epp->pz;
        
        epw->ay = epp->ay;

        EXP0_I(124) = -1;
        
        epw->flg |= 0x8;
        
        EXP0_I(64) &= ~0xF;
        EXP0_I(64) |=  0x4;

        ps.x = 0;
        ps.y = 1.0f;       
        ps.z = 0;
        
        epp->djnt_no = 9;
        
        bhEne_SetBlood2(epp, 2, &ps, 0);

        epw->mode3++;
    case 1:
        frm = epw->frm_no / 65536;

        if (frm == 1)
        {
            NJS_POINT3 ps = { 0 }; 

            epw->dvx = -njSin(epw->ay);
            epw->dvy =  njSin(10922);
            epw->dvz = -njCos(epw->ay);
            
            epw->djnt_no = 9;
            
            bhSetEffParticle(epw, epw->djnt_no, &ps, (NJS_POINT3*)&epw->dvx, 0xFF800000, 5);
            bhSetEffParticle(epw, epw->djnt_no, &ps, (NJS_POINT3*)&epw->dvx, 0xFF800000, 5);
        }

        if (((epw->mtn_no == 350) && (frm < 28)) || ((epw->mtn_no == 351) && (frm <= 20)) || ((epw->mtn_no == 352) && (frm <= 20)) || ((epw->mtn_no == 353) && (frm <= 20))) 
        {
            if ((frm % 4) == 0) 
            {
                ps.x = 2.0f - (4.0f * (-rand() / -2.1474836E9f)); 
                ps.y = 0;
                ps.z = 0;
                
                epp->djnt_no = 9;
                bhEne_SetBlood2(epp, 1, &ps, 0);
                
                epp->djnt_no = 1;
                bhEne_SetBlood2(epp, 1, &ps, 0);
            }
        }
        else if ((frm % 3) == 0) 
        {
            ps.x = 2.0f - (4.0f * (-rand() / -2.1474836E9f));
            ps.y = 0;
            ps.z = 0;
            
            epp->djnt_no = 9;
            bhEne_SetBlood2(epp, 0, &ps, 0);
            
            epp->djnt_no = 1;
            bhEne_SetBlood2(epp, 0, &ps, 0);
        }
        
        if (frm == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            owk = &epw->mlwP->owP[8];
            
            epw->px = owk->mtx[12];  
            epw->pz = owk->mtx[14];  

            if (epw->mtn_no == 352) 
            {
                bhEne_ChgMtn(epw, 166, 0, 0);
                
                EXP0_I(64) &= ~0x3000000;
                
                epw->hp = -1;
            } 
            else 
            {
                bhEne_ChgMtn(epw, 39, 0, 0);
                
                EXP0_I(64) &= ~0x3000000;
            }

            epw->ct0 = 20;
            
            epw->mode3++;
        }
        
        break;
    case 2:
        if (epw->ct0-- != 0) 
        {
            if (epw->hp < 0) 
            {
                epw->mode0 = 4;
                epw->mode1 = 0;
                epw->mode2 = 2;
                epw->mode3 = 0;
            }
            else 
            {
                epw->mode0 = 1;
                epw->mode1 = 1;
                epw->mode2 = 3;
                epw->mode3 = 0;
                
                epw->type = 2;
                
                EXP0_I(64) &= ~0xF;
                EXP0_I(64) |=  0x4;
                
                epw->flg |= 0x20;
            }
        }
        
        break;
    }
}

// 100% matching!
void bhEne01_DG12B(BH_PWORK* epw)
{
    BH_PWORK* epp;
    
    epp = (BH_PWORK*)epw->lkwkp;
    
    switch (epw->mode3)
    {                            
    case 0:
        bhEne_ChgMtn(epw, 26, 0, 5);
        
        EXP0_I(64) &= ~0x3000000;
        
        if (epw->hp < 0)
        {
            bhEne01_SePlay(epp, (NJS_POINT3*)&epw->px, 16786197);
            
            epw->mode3 = 2;
        }
        else
        {
            bhEne01_SePlay(epp, (NJS_POINT3*)&epw->px, 16786196);
            
            epw->mode3++;
        }
    case 1:
        if ((epw->mtn_no == 26) && ((epw->frm_no / 65536) > 10)) 
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;
        }
        
        break;
    case 2:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
        {
            epw->mode0 = 4;
            epw->mode1 = 0;
            epw->mode2 = 2;
            epw->mode3 = 0;
            
            epw->mtn_add = 0;
        }
        
        break;
    }
}

// 100% matching!
void bhEne01_DG13B(BH_PWORK* epw) 
{    
    BH_PWORK* epp;
    
    epp = (BH_PWORK*)epw->lkwkp;
    
    switch (epw->mode3) 
    {                            
    case 0:
        bhEne_ChgMtn(epw, 26, 0, 5);
        
        EXP0_I(64) &= ~0x3000000;
        
        bhEne01_SePlay(epp, (NJS_POINT3*)&epw->px, 16786196);
        
        epw->mode3++;
    case 1:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
        {
            epw->mode0 = 4;
            epw->mode1 = 0;
            epw->mode2 = 2;
            epw->mode3 = 0;
            
            epw->mtn_add = 0;
        }
        
        break;
    }
}

// 99.94% matching
void bhEne01_DD02B(BH_PWORK* epw)
{
    O_WORK* owk;  
    NJS_POINT3 ps, pd; 
    NJS_LINE line; 

    switch (epw->mode3)
    {
    case 0:
        epw->flg |=  0x2;
        epw->flg &= ~0x28;
        
        if (!(epw->stflg & 0x100000)) 
        {
            owk = &epw->mlwP->owP[10];
            
            ps.x = 0;
            ps.y = 0;
            ps.z = 3.0f;
            
            njCalcPoint(&owk->mtx, &ps, &pd);
            
            pd.y = epw->py;
            
            bhSetBloodPoolLnk(NULL, &pd, epw->ay, &en01_BldTbl, 0);
        }
        
        if ((!(EXP0_I(0x40) & 0x100000)) && ((epw->stflg & 0x100000))) 
        {
            line.px = epw->px;
            line.py = epw->py;
            line.pz = epw->pz;
            
            line.vx = 0;
            line.vy = 18.2f;
            line.vz = 0;
            
            bhCheckL2Water(&line, &pd);
            
            if (&pd == NULL) 
            {
                pd.y = 0;
            }
            
            epw->xn = pd.y - 1.0f;
            epw->yn = epw->py;
            
            epw->ct0 = (rand() % 30) + 60;
            
            epw->mode3 = 2;
            break;
        }
        
        epw->mode3++;
        break;
    case 1:
        break;
    case 2:
        if (--epw->ct0 >= 0)
        {
            break;
        }
        
        EXP0_F(148) = 0;
        
        epw->ct0 = 0;
        
        epw->mode3++;
        break;
    case 3:
        epw->py = epw->yn + ((0.001f * (epw->ct0 * epw->ct0)) / 2.0f);
        
        epw->ct0++;
        
        if (epw->xn < epw->py) 
        {
            EXP0_F(148) = 0.5 * (-0.001f * epw->ct0);
            
            epw->ct0 = 0;
            
            epw->py = epw->xn;
            
            epw->mode3++;
        }
        
        break;
    case 4:
        epw->py = (epw->xn + (EXP0_F(148) * epw->ct0)) + ((0.001f * (epw->ct0 * epw->ct0)) / 2.0f);
        
        epw->ct0++;
        
        if (epw->xn < epw->py) 
        {
            *&EXP0_F(148) = -(0.5 * (*&EXP0_F(148) - (-0.001f * epw->ct0)));
            
            if (*&EXP0_F(148) > -0.04) 
            {
                *&EXP0_F(148) = -0.04f;
            }
            
            epw->ct0 = 0;
            
            epw->py = epw->xn;
        }
        
        break;
    }
}

// 100% matching!
void bhEne01_RotNeck(BH_PWORK* epw, int neck_no, BH_PWORK* ply, int ply_neck_no)
{
	NJS_POINT3 pos;
	NJS_CNK_OBJECT* obj;
	O_WORK* trg_owk;   
	int rot;

    if (!(epw->flg & 0x80))
    {
        rot = epw->ay;
    } 
    else
    {
        rot = *(int *)(epw->lkwkp + 0x20);
    }
    
    trg_owk = &ply->mlwP->owP[ply_neck_no];
    obj = &epw->mlwP->objP[neck_no];
    pos.x = trg_owk->mtx[12];
    pos.y = trg_owk->mtx[13];
    pos.z = trg_owk->mtx[14];
    obj->ang[1] = bhEne01_SideRotNeck(epw, neck_no, &pos, obj->ang[1], 9102, rot);
}

// 100% matching!
int bhEne01_SideRotNeck(BH_PWORK* epw, int neck_no, NJS_VECTOR* trg, int neck_ry, int neck_ry_max, int ang)
{
    O_WORK* owk;
    int rot;

    // not present in DWARF
    int ret;

    owk = &epw->mlwP->owP[neck_no];
    rot = (NitenDir_ck(owk->mtx[12], owk->mtx[14], trg->x, trg->z) - ang) & 0xFFFF;

    if ((unsigned short)((rot - neck_ry) + 910) < 1820)
    {
        if ((unsigned short)(rot + neck_ry_max) <= (neck_ry_max + neck_ry_max))
        {
            neck_ry = rot;
        }
        return neck_ry;
    }

    if (rot == 0)
    {
        if (neck_ry > 32768) 
        {
            return (unsigned short)(neck_ry + 910);
        }
        return (unsigned short)(neck_ry - 910);
    }

    if ((unsigned short)(rot - neck_ry) < 32768)
    {
        ret = (unsigned short)(neck_ry + 910);
        if ((unsigned short)(ret - neck_ry_max) < (65536 - (neck_ry_max + neck_ry_max)))
        {
            ret = neck_ry_max;
        }
        return ret;
    }

    ret = (unsigned short)(neck_ry - 910);
    if ((unsigned short)(ret + neck_ry_max) > (neck_ry_max + neck_ry_max))
    {
        ret = 65536 - neck_ry_max;
    }
    return ret;
}

// 100% matching!
int bhSearchPlayer2(BH_PWORK* epw, NJS_VECTOR* pp, int pp_r, int r)
{
	float px;
	float py;
	float pz;    
	int ay;
    int ret;

    px = epw->px;
    py = epw->py;
    pz = epw->pz;
    ay = epw->ay;
    epw->px = pp->x;
    epw->py = pp->y;
    epw->pz = pp->z;
    epw->ay = pp_r;
    ret = bhSearchPlayer(epw, r);
    epw->px = px;
    epw->py = py;
    epw->pz = pz;
    epw->ay = ay;
    return ret;
}
