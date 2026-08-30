#include "../../../ps2/veronica/prog/en01sub.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/en01.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/weapon.h"
#include "../../../ps2/veronica/prog/zonzon.h"

void (*bhEne01Parent_Mode0[2])(BH_PWORK*) =
{
	bhEne01Parent_Init,
	bhEne01Parent_Move
};
void (*bhEne01Arm_Mode0[4])(BH_PWORK*) =
{
	bhEne01Arm_Init,
	bhEne01Arm_Move,
	NULL,
	bhEne01Arm_Damage
};
void (*bhEne01Arm_DamageMode[2])(BH_PWORK*) =
{
	bhEne01Arm_DG00,
	bhEne01Arm_DG01
};
void (*bhEne01Leg_Mode0[4])(BH_PWORK*) =
{
	bhEne01Leg_Init,
	bhEne01Leg_Move,
	NULL,
	bhEne01Leg_Damage
};
void (*bhEne01Leg_DamageMode[1])(BH_PWORK*) =
{
	bhEne01Leg_DG00
};
void (*bhEne01Head_Mode0[4])(BH_PWORK*) =
{
	bhEne01Head_Init,
	bhEne01Head_Move,
	NULL,
	bhEne01Head_Damage
};
void (*bhEne01Head_DamageMode[1])(BH_PWORK*) =
{
	bhEne01Head_DG00
};
void (*bhEne01Cap_Mode0[4])(BH_PWORK*) = 
{
	bhEne01Cap_Init,
	bhEne01Cap_Move,
	NULL,
	bhEne01Cap_Damage
};
void (*bhEne01Cap_DamageMode[2])(BH_PWORK*) =
{
	bhEne01Cap_DG00,
	bhEne01Cap_DG01
};
void (*bhEne01Worm_Mode0[4])(BH_PWORK*) = 
{
	bhEne01Worm_Init,
	bhEne01Worm_Move,
	NULL,
	NULL
};
void (*bhEne01Worm_MoveMode[3])(BH_PWORK*) =
{
	bhEne01Worm_MV00,
	bhEne01Worm_MV01,
	bhEne01Worm_MV02
};
void (*bhEne01Bom_Mode0[2])(BH_PWORK*) = 
{
	bhEne01Bom_Init,
	bhEne01Bom_Move
};
void (*bhEne01Scope_Mode0[2])(BH_PWORK*) =
{
	bhEne01Scope_Init,
	bhEne01Scope_Move
};

// 100% matching!
void bhEne01Parent(BH_PWORK* epw)
{
	bhEne01Parent_Mode0[epw->mode0](epw);
}

// 100% matching!
void bhEne01Parent_Init(BH_PWORK* epw)
{
	epw->stflg = 0;

    epw->flg |= 0x8000;

    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
}

// 100% matching!
void bhEne01Parent_Move()
{
	bhEne01Parent_NearestCheck();
	bhEne01Parent_NoKaidanCheck();
}

// 100% matching!
void bhEne01Parent_NearestCheck() 
{
    BH_PWORK* ep, *epp;  
    float dist;    
    int i;         
    
    ep  = ene;
    epp = NULL;
    
    dist = 0;

    for (i = 0; i < sys->ewk_n; i++, ep++) 
    {
        if (((ep->id == 1) && ((ep->flg & 0x1)) && (ep->type != 10)) && (ep->exp0 != NULL) && ((!(ep->stflg & 0x1000000)) && ((!(ep->flg & 0x2)) && (!(ep->flg & 0x80))))) 
        {
            EP_EXP0_I(68) &= ~0x2;
            
            if ((dist > EP_EXP0_F(84)) || (epp == NULL)) 
            {
                dist = EP_EXP0_F(84);
                
                epp = ep;
            }
        }
    }

    if (epp != NULL) 
    {
        ep = epp; 
        
        EP_EXP0_I(68) |= 0x2;
    }
}

// 100% matching!
void bhEne01Parent_NoKaidanCheck() 
{
    static STG_WORK ene_stg_tbl[2] = 
	{
		{  0, 6, 2, 2 },
		{ -1, 0, 0, 0 }
	};
    STG_WORK* stg_p;    
    BH_PWORK* ep_p[10]; 
    BH_PWORK* ep;       
    int i;              
    int n, no;             

    ep = ene;
    
    stg_p = ene_stg_tbl;

    for (i = 0; i < 0xFF; i++, stg_p++) 
    {
        if (stg_p->stg_no == -1) 
        {
            return;
        }
        
        if ((sys->stg_no == stg_p->stg_no) || (sys->rom_no == stg_p->rom_no)) 
        {
            break;
        }
    }

    i = 0;
    n = 0;

    for (no = 0; i < sys->ewk_n; i++, ep++) 
    {
        if (((ep->id == 1) && ((ep->flg & 0x1)) && (ep->type != 10)) && (ep->exp0 != NULL) && ((!(ep->stflg & 0x1000000)) && ((!(ep->flg & 0x2)) && (!(ep->flg & 0x80)))))
        {
            ep->flg &= ~0x200000;
            
            if (ep->flr_no == stg_p->flr_no) 
            {
                n++;
            } 
            else 
            {
                ep_p[no++] = ep; 
            }
        }
    }

    if (n >= stg_p->ene_max)
    {
        for (i = 0; i < no; i++) 
        {
            ep_p[i]->flg |= 0x200000;
        }
    }
}

// 100% matching!
void bhEne01Arm(BH_PWORK* epw)
{
	bhEne01Arm_Mode0[epw->mode0](epw);
}

// 100% matching!
void bhEne01Arm_Init(BH_PWORK* epw) 
{
    epw->stflg = 0;
    
    epw->flg |= 0x8000;
    
    if (epw->exp0 == NULL) 
    {
        epw->exp0 = bhEne_CallocWork(112, 8);
    }
    
    EXP0_I(0) = 0;
    EXP0_I(4) = 0;
    EXP0_I(8) = 2;
    
    EXP0_I(20) = 0;
    
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0; 
    epw->mode3 = 0;
}

// 100% matching!
void bhEne01Arm_Move(BH_PWORK* epw)
{
	bhEne01Arm_MV00();
}

// 100% matching!
void bhEne01Arm_MV00()
{

}

// 100% matching!
void bhEne01Arm_Damage(BH_PWORK* epw)
{
	bhEne01Arm_DamageMode[epw->mode2](epw);
}

// 100% matching!
void bhEne01Arm_DG00(BH_PWORK* epw) 
{
    NJS_CNK_OBJECT* obj; 
    O_WORK* owk;         
    BH_PWORK* epp;      
    NJS_POINT3 ps, pd;      
    int i;              

    epp = (BH_PWORK*)epw->lkwkp;
    
    obj = (NJS_CNK_OBJECT*)EXP0_I(0) + 1;
    
    owk = (O_WORK*)EXP0_I(4);

    switch (epw->mode3)
    {
    case 0:
        epw->ct0 = 0;
        
        epw->mode3++;
    case 1:
        if ((epw->ct0 % 8) == 0) 
        {
            pd.x = 0;
            pd.y = 0;
            pd.z = 0;
            
            epp->djnt_no = EXP0_I(12);
            bhEne_SetBlood2(epp, 1, &pd, 0);
            
            epp->djnt_no = epw->ct3;
            bhEne_SetBlood2(epp, 1, (NJS_POINT3*)&epw->xn, 0);
        }

        owk->mtx[12] += epw->dvx / 10.0f;
        owk->mtx[13] -= 0.1f * epw->ct0;
        owk->mtx[14] += epw->dvz / 10.0f;

        for (i = 0; i < (EXP0_I(8) - 1); i++) 
        {
            njSetMatrix(&owk[1].mtx, &owk[0].mtx);
            
            njTranslate(&owk[1].mtx, obj->pos[0], obj->pos[1], obj->pos[2]);
            njRotateXYZ(&owk[1].mtx, obj->ang[0], obj->ang[1], obj->ang[2]);
            
            owk++;
            obj++;
        }

        epw->ct0++;

        owk = (O_WORK*)EXP0_I(4) + (EXP0_I(8) - 1);

        ps.x = epw->py;
        ps.y = 0;
        ps.z = 0;
        
        njCalcPoint(&owk->mtx, &ps, &pd);

        if (pd.y < rom->grand[epw->flr_no + 2]) 
        {
            njSetMatrix((NJS_MATRIX*)&epw->exp0[48], &owk->mtx);
            
            njTranslate((NJS_MATRIX*)&epw->exp0[48], epw->py, 0, 0);
            
            EXP0_F(100) = rom->grand[epw->flr_no + 2];
            
            epw->ct0 = 0;
            
            epw->mode3++;
        }
        
        break;
    case 2:
        owk = (O_WORK*)EXP0_I(4) + (EXP0_I(8) - 1);
        
        EXP0_F(100) += 0.2f - (0.08f * epw->ct0);
        
        epw->ct0++;
        
        if (EXP0_F(100) < rom->grand[epw->flr_no + 2]) 
        {
            EXP0_F(100) = rom->grand[epw->flr_no + 2];
        }

        njRotateZ((NJS_MATRIX*)&epw->exp0[48], epw->az);
        njRotateZ(&owk[0].mtx,                 epw->az);
        
        epw->az += epw->ay;

        ps.x = -epw->py;
        ps.y = 0;
        ps.z = 0;
        
        njCalcPoint((NJS_MATRIX*)&epw->exp0[48], &ps, &pd);

        owk[0].mtx[12] = pd.x;
        owk[0].mtx[14] = pd.z;
        owk[0].mtx[13] = pd.y;

        obj = (NJS_CNK_OBJECT*)EXP0_I(0) + (EXP0_I(8) - 1);

        for (i = 0; i < (EXP0_I(8) - 1); i++) 
        {
            njSetMatrix(&owk[-1].mtx, &owk[0].mtx);
            
            njRotateXYZ(&owk[-1].mtx, -obj->ang[0], -obj->ang[1], -obj->ang[2]);
            njTranslate(&owk[-1].mtx, -obj->pos[0], -obj->pos[1], -obj->pos[2]);
            
            owk--;
            obj--;
        }

        if (((O_WORK*)EXP0_I(4))[1].mtx[13] < (rom->grand[epw->flr_no + 2] + 1.0f)) 
        {
            epw->ct0 = 0;
            
            epw->mode3++;
        }
        
        break;
    case 3:
        if (owk[0].mtx[13] > -4.0f) 
        {
            owk[0].mtx[13] -= 500.0f;
            
            owk->flg |= 0x100;
            
            epw->ct0++;

            for (i = 0; i < (EXP0_I(8) - 1); i++) 
            {
                njSetMatrix(&owk[1].mtx, &owk[0].mtx);
                
                njTranslate(&owk[1].mtx, obj->pos[0], obj->pos[1], obj->pos[2]);
                njRotateXYZ(&owk[1].mtx, obj->ang[0], obj->ang[1], obj->ang[2]);
                
                owk++;
                obj++;
            }
            
            epw->mode3++;
        }
        
        break;
    case 4:
        break;
    }
}

// 
// Start address: 0x18c590
void bhEne01Arm_DG01(BH_PWORK* epw)
{
	int i;
	NJS_POINT3 pd;
	O_WORK* owk;
	NJS_CNK_OBJECT* obj;
	BH_PWORK* epp;
	// Line 679, Address: 0x18c590, Func Offset: 0
	// Line 688, Address: 0x18c5b0, Func Offset: 0x20
	// Line 680, Address: 0x18c5b4, Func Offset: 0x24
	// Line 688, Address: 0x18c5b8, Func Offset: 0x28
	// Line 691, Address: 0x18c5e0, Func Offset: 0x50
	// Line 692, Address: 0x18c5e8, Func Offset: 0x58
	// Line 691, Address: 0x18c5f0, Func Offset: 0x60
	// Line 692, Address: 0x18c5fc, Func Offset: 0x6c
	// Line 693, Address: 0x18c604, Func Offset: 0x74
	// Line 695, Address: 0x18c610, Func Offset: 0x80
	// Line 696, Address: 0x18c628, Func Offset: 0x98
	// Line 697, Address: 0x18c63c, Func Offset: 0xac
	// Line 699, Address: 0x18c650, Func Offset: 0xc0
	// Line 700, Address: 0x18c658, Func Offset: 0xc8
	// Line 701, Address: 0x18c660, Func Offset: 0xd0
	// Line 702, Address: 0x18c668, Func Offset: 0xd8
	// Line 726, Address: 0x18c670, Func Offset: 0xe0
	// Line 727, Address: 0x18c698, Func Offset: 0x108
	// Line 728, Address: 0x18c6a4, Func Offset: 0x114
	// Line 729, Address: 0x18c6a8, Func Offset: 0x118
	// Line 730, Address: 0x18c6ac, Func Offset: 0x11c
	// Line 733, Address: 0x18c6b8, Func Offset: 0x128
	// Line 735, Address: 0x18c6d8, Func Offset: 0x148
	// Line 736, Address: 0x18c6dc, Func Offset: 0x14c
	// Line 737, Address: 0x18c6e0, Func Offset: 0x150
	// Line 738, Address: 0x18c6e4, Func Offset: 0x154
	// Line 739, Address: 0x18c6e8, Func Offset: 0x158
	// Line 738, Address: 0x18c6f4, Func Offset: 0x164
	// Line 739, Address: 0x18c6f8, Func Offset: 0x168
	// Line 741, Address: 0x18c704, Func Offset: 0x174
	// Line 742, Address: 0x18c708, Func Offset: 0x178
	// Line 741, Address: 0x18c710, Func Offset: 0x180
	// Line 742, Address: 0x18c714, Func Offset: 0x184
	// Line 745, Address: 0x18c720, Func Offset: 0x190
	// Line 746, Address: 0x18c728, Func Offset: 0x198
	// Line 745, Address: 0x18c730, Func Offset: 0x1a0
	// Line 746, Address: 0x18c73c, Func Offset: 0x1ac
	// Line 747, Address: 0x18c744, Func Offset: 0x1b4
	// Line 749, Address: 0x18c764, Func Offset: 0x1d4
	// Line 750, Address: 0x18c768, Func Offset: 0x1d8
	// Line 749, Address: 0x18c770, Func Offset: 0x1e0
	// Line 750, Address: 0x18c78c, Func Offset: 0x1fc
	// Line 751, Address: 0x18c794, Func Offset: 0x204
	// Line 754, Address: 0x18c798, Func Offset: 0x208
	// Line 751, Address: 0x18c79c, Func Offset: 0x20c
	// Line 753, Address: 0x18c7a4, Func Offset: 0x214
	// Line 754, Address: 0x18c7b0, Func Offset: 0x220
	// Line 756, Address: 0x18c7c0, Func Offset: 0x230
	// Line 757, Address: 0x18c7d0, Func Offset: 0x240
	// Line 760, Address: 0x18c7d8, Func Offset: 0x248
	// Line 761, Address: 0x18c7dc, Func Offset: 0x24c
	// Line 764, Address: 0x18c7e8, Func Offset: 0x258
	// Line 765, Address: 0x18c7ec, Func Offset: 0x25c
	// Line 764, Address: 0x18c7f0, Func Offset: 0x260
	// Line 765, Address: 0x18c810, Func Offset: 0x280
	// Line 767, Address: 0x18c818, Func Offset: 0x288
	// Line 768, Address: 0x18c824, Func Offset: 0x294
	// Line 769, Address: 0x18c844, Func Offset: 0x2b4
	// Line 770, Address: 0x18c864, Func Offset: 0x2d4
	// Line 771, Address: 0x18c868, Func Offset: 0x2d8
	// Line 772, Address: 0x18c86c, Func Offset: 0x2dc
	// Line 773, Address: 0x18c888, Func Offset: 0x2f8
	// Line 776, Address: 0x18c890, Func Offset: 0x300
	// Line 778, Address: 0x18c8b0, Func Offset: 0x320
	// Line 779, Address: 0x18c8b4, Func Offset: 0x324
	// Line 780, Address: 0x18c8b8, Func Offset: 0x328
	// Line 781, Address: 0x18c8bc, Func Offset: 0x32c
	// Line 782, Address: 0x18c8c0, Func Offset: 0x330
	// Line 781, Address: 0x18c8cc, Func Offset: 0x33c
	// Line 782, Address: 0x18c8d0, Func Offset: 0x340
	// Line 784, Address: 0x18c8dc, Func Offset: 0x34c
	// Line 785, Address: 0x18c8e0, Func Offset: 0x350
	// Line 784, Address: 0x18c8e8, Func Offset: 0x358
	// Line 785, Address: 0x18c8ec, Func Offset: 0x35c
	// Line 788, Address: 0x18c8f8, Func Offset: 0x368
	// Line 789, Address: 0x18c8fc, Func Offset: 0x36c
	// Line 792, Address: 0x18c90c, Func Offset: 0x37c
	// Line 788, Address: 0x18c910, Func Offset: 0x380
	// Line 789, Address: 0x18c914, Func Offset: 0x384
	// Line 792, Address: 0x18c918, Func Offset: 0x388
	// Line 789, Address: 0x18c91c, Func Offset: 0x38c
	// Line 792, Address: 0x18c92c, Func Offset: 0x39c
	// Line 794, Address: 0x18c95c, Func Offset: 0x3cc
	// Line 795, Address: 0x18c960, Func Offset: 0x3d0
	// Line 796, Address: 0x18c964, Func Offset: 0x3d4
	// Line 799, Address: 0x18c970, Func Offset: 0x3e0
	// Line 800, Address: 0x18c974, Func Offset: 0x3e4
	// Line 799, Address: 0x18c978, Func Offset: 0x3e8
	// Line 800, Address: 0x18c97c, Func Offset: 0x3ec
	// Line 802, Address: 0x18c984, Func Offset: 0x3f4
	// Line 803, Address: 0x18c990, Func Offset: 0x400
	// Line 804, Address: 0x18c9a4, Func Offset: 0x414
	// Line 805, Address: 0x18c9b8, Func Offset: 0x428
	// Line 806, Address: 0x18c9bc, Func Offset: 0x42c
	// Line 807, Address: 0x18c9c0, Func Offset: 0x430
	// Line 808, Address: 0x18c9e0, Func Offset: 0x450
	// Line 810, Address: 0x18c9e8, Func Offset: 0x458
	// Line 814, Address: 0x18c9f0, Func Offset: 0x460
	// Line 813, Address: 0x18c9f4, Func Offset: 0x464
	// Line 814, Address: 0x18c9f8, Func Offset: 0x468
	// Line 815, Address: 0x18ca04, Func Offset: 0x474
	// Line 814, Address: 0x18ca08, Func Offset: 0x478
	// Line 813, Address: 0x18ca0c, Func Offset: 0x47c
	// Line 814, Address: 0x18ca10, Func Offset: 0x480
	// Line 815, Address: 0x18ca1c, Func Offset: 0x48c
	// Line 814, Address: 0x18ca20, Func Offset: 0x490
	// Line 815, Address: 0x18ca28, Func Offset: 0x498
	// Line 814, Address: 0x18ca2c, Func Offset: 0x49c
	// Line 815, Address: 0x18ca38, Func Offset: 0x4a8
	// Line 817, Address: 0x18ca64, Func Offset: 0x4d4
	// Line 819, Address: 0x18ca68, Func Offset: 0x4d8
	// Line 821, Address: 0x18ca6c, Func Offset: 0x4dc
	// Line 819, Address: 0x18ca78, Func Offset: 0x4e8
	// Line 821, Address: 0x18ca7c, Func Offset: 0x4ec
	// Line 822, Address: 0x18ca84, Func Offset: 0x4f4
	// Line 825, Address: 0x18ca9c, Func Offset: 0x50c
	// Line 828, Address: 0x18caac, Func Offset: 0x51c
	// Line 825, Address: 0x18cab0, Func Offset: 0x520
	// Line 827, Address: 0x18cacc, Func Offset: 0x53c
	// Line 828, Address: 0x18cad4, Func Offset: 0x544
	// Line 830, Address: 0x18cadc, Func Offset: 0x54c
	// Line 831, Address: 0x18cafc, Func Offset: 0x56c
	// Line 832, Address: 0x18cb10, Func Offset: 0x580
	// Line 833, Address: 0x18cb24, Func Offset: 0x594
	// Line 834, Address: 0x18cb2c, Func Offset: 0x59c
	// Line 837, Address: 0x18cb48, Func Offset: 0x5b8
	// Line 840, Address: 0x18cb84, Func Offset: 0x5f4
	// Line 842, Address: 0x18cb88, Func Offset: 0x5f8
	// Line 840, Address: 0x18cb8c, Func Offset: 0x5fc
	// Line 841, Address: 0x18cba4, Func Offset: 0x614
	// Line 843, Address: 0x18cbb0, Func Offset: 0x620
	// Line 846, Address: 0x18cbb8, Func Offset: 0x628
	// Line 847, Address: 0x18cbc8, Func Offset: 0x638
	// Line 848, Address: 0x18cbd8, Func Offset: 0x648
	// Line 850, Address: 0x18cbe8, Func Offset: 0x658
	// Line 853, Address: 0x18cbf0, Func Offset: 0x660
	// Line 858, Address: 0x18cbf4, Func Offset: 0x664
	// Line 855, Address: 0x18cbf8, Func Offset: 0x668
	// Line 858, Address: 0x18cbfc, Func Offset: 0x66c
	// Line 854, Address: 0x18cc00, Func Offset: 0x670
	// Line 853, Address: 0x18cc04, Func Offset: 0x674
	// Line 855, Address: 0x18cc08, Func Offset: 0x678
	// Line 858, Address: 0x18cc10, Func Offset: 0x680
	// Line 854, Address: 0x18cc14, Func Offset: 0x684
	// Line 855, Address: 0x18cc18, Func Offset: 0x688
	// Line 856, Address: 0x18cc20, Func Offset: 0x690
	// Line 858, Address: 0x18cc28, Func Offset: 0x698
	// Line 859, Address: 0x18cc38, Func Offset: 0x6a8
	// Line 861, Address: 0x18cc40, Func Offset: 0x6b0
	// Line 862, Address: 0x18cc60, Func Offset: 0x6d0
	// Line 863, Address: 0x18cc74, Func Offset: 0x6e4
	// Line 864, Address: 0x18cc88, Func Offset: 0x6f8
	// Line 865, Address: 0x18cc90, Func Offset: 0x700
	// Line 867, Address: 0x18ccb0, Func Offset: 0x720
	// Line 870, Address: 0x18ccec, Func Offset: 0x75c
	// Line 871, Address: 0x18cd08, Func Offset: 0x778
	// Line 873, Address: 0x18cd14, Func Offset: 0x784
	// Line 876, Address: 0x18cd1c, Func Offset: 0x78c
	// Line 877, Address: 0x18cd2c, Func Offset: 0x79c
	// Line 878, Address: 0x18cd3c, Func Offset: 0x7ac
	// Line 880, Address: 0x18cd4c, Func Offset: 0x7bc
	// Line 884, Address: 0x18cd54, Func Offset: 0x7c4
	// Line 883, Address: 0x18cd58, Func Offset: 0x7c8
	// Line 884, Address: 0x18cd5c, Func Offset: 0x7cc
	// Line 883, Address: 0x18cd70, Func Offset: 0x7e0
	// Line 884, Address: 0x18cd74, Func Offset: 0x7e4
	// Line 885, Address: 0x18cd80, Func Offset: 0x7f0
	// Line 884, Address: 0x18cd84, Func Offset: 0x7f4
	// Line 885, Address: 0x18cd8c, Func Offset: 0x7fc
	// Line 884, Address: 0x18cd90, Func Offset: 0x800
	// Line 885, Address: 0x18cd98, Func Offset: 0x808
	// Line 887, Address: 0x18cda8, Func Offset: 0x818
	// Line 888, Address: 0x18cdc0, Func Offset: 0x830
	// Line 889, Address: 0x18cdcc, Func Offset: 0x83c
	// Line 891, Address: 0x18cdd8, Func Offset: 0x848
	// Line 894, Address: 0x18cddc, Func Offset: 0x84c
	// Line 891, Address: 0x18cde0, Func Offset: 0x850
	// Line 893, Address: 0x18cde8, Func Offset: 0x858
	// Line 894, Address: 0x18cdf0, Func Offset: 0x860
	// Line 896, Address: 0x18cdf8, Func Offset: 0x868
	// Line 897, Address: 0x18ce04, Func Offset: 0x874
	// Line 898, Address: 0x18ce18, Func Offset: 0x888
	// Line 899, Address: 0x18ce2c, Func Offset: 0x89c
	// Line 900, Address: 0x18ce30, Func Offset: 0x8a0
	// Line 901, Address: 0x18ce34, Func Offset: 0x8a4
	// Line 908, Address: 0x18ce50, Func Offset: 0x8c0
	// Line 909, Address: 0x18ce6c, Func Offset: 0x8dc
	// Func End, Address: 0x18ce90, Func Offset: 0x900
	scePrintf("bhEne01Arm_DG01 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne01Leg(BH_PWORK* epw)
{
	bhEne01Leg_Mode0[epw->mode0](epw);
}

// 100% matching!
void bhEne01Leg_Init(BH_PWORK* epw) 
{
    epw->stflg = 0;
    
    epw->flg |= 0x8000;
    
    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(112, 8);
    }
    
    EXP0_I(0) = 0;
    EXP0_I(4) = 0;
    EXP0_I(8) = 2;
    
    EXP0_I(20) = 0;
    
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
}

// 100% matching!
void bhEne01Leg_Move(BH_PWORK* epw)
{
	bhEne01Leg_MV00();
}

// 100% matching!
void bhEne01Leg_MV00()
{

}

// 100% matching!
void bhEne01Leg_Damage(BH_PWORK* epw)
{
	bhEne01Leg_DamageMode[epw->mode2](epw);
}

// 99.89% matching
void bhEne01Leg_DG00(BH_PWORK* epw)
{
    ATR_WORK* hp;        
    NJS_CNK_OBJECT* obj; 
    O_WORK* owk;        
    BH_PWORK* epp;    
    NJS_POINT3 pd;      

    epp = (BH_PWORK*)epw->lkwkp;

    switch (epw->mode3) 
    {
    case 0:
        epw->ct0 = 0;
        
        obj = (NJS_CNK_OBJECT*)EXP0_I(0);
        
        obj[0].ang[0] = obj[0].ang[1] = obj[0].ang[2] = 0;
        obj[1].ang[0] = obj[1].ang[1] = obj[1].ang[2] = 0;

        owk = (O_WORK*)EXP0_I(4) + 1;
        
        njSetMatrix((NJS_MATRIX*)&epw->exp0[48], &owk->mtx);
        
        njTranslate((NJS_MATRIX*)&epw->exp0[48], 0, -1.0f, -2.2f);

        epw->mode3++;
    case 1:
        if ((epw->ct0 % 8) == 0) 
        {
            pd.x = 0;
            pd.y = 0;
            pd.z = 0;
            
            epp->djnt_no = EXP0_I(12);
            bhEne_SetBlood2(epp, 1, &pd, 0);
        }
        
        epw->ct0++;

        owk = (O_WORK*)EXP0_I(4);
        
        pd.x = owk[0].mtx[12];
        pd.y = owk[0].mtx[13] - 1.0f;
        pd.z = owk[0].mtx[14];
        
        hp = bhCheckWallType(&pd, epw->flg, 1.0f, 1.0f);

        if ((hp == NULL) || ((hp != NULL) && (hp->type != 7)))
        {
            owk = (O_WORK*)EXP0_I(4) + 1;
            
            njRotateXYZ((NJS_MATRIX*)&epw->exp0[48], 0, 0, epw->ax);
            njRotateXYZ(&owk[0].mtx,                 0, 0, epw->ax);
            
            epw->ax += epw->wax;
        }

        owk = (O_WORK*)EXP0_I(4);
        
        if (((hp != NULL) && (hp->type == 7)) || (owk[1].mtx[13] > owk[0].mtx[13]))
        {
            owk->mtx[13] += -100.0f;
            
            obj = (NJS_CNK_OBJECT*)EXP0_I(0) + 1;

            njSetMatrix(&owk[1].mtx, &owk[0].mtx);
            
            njTranslate(&owk[1].mtx, obj->pos[0], obj->pos[1], obj->pos[2]);
            njRotateXYZ(&owk[1].mtx, obj->ang[0], obj->ang[1], obj->ang[2]);

            epw->mode3++;
            break;
        }

        obj = (NJS_CNK_OBJECT*)EXP0_I(0) + 1;
        
        owk = (O_WORK*)EXP0_I(4) + 1;

        njSetMatrix(&owk[-1].mtx, &owk[0].mtx);
        
        njRotateXYZ(&owk[-1].mtx, -obj->ang[0], -obj->ang[1], -obj->ang[2]);
        njTranslate(&owk[-1].mtx, -obj->pos[0], -obj->pos[1], -obj->pos[2]);
        break;
    case 2:
        break;
    }
}

// 100% matching!
void bhEne01Head(BH_PWORK* epw)
{
	bhEne01Head_Mode0[epw->mode0](epw);
}

// 100% matching!
void bhEne01Head_Init(BH_PWORK* epw) 
{
    epw->stflg = 0;
    
    epw->flg |= 0x8000;
    
    if (epw->exp0 == NULL) 
    {
        epw->exp0 = bhEne_CallocWork(32, 8);
    }
    
    EXP0_I(0) = 0;
    EXP0_I(4) = 0;
    EXP0_I(8) = 0;
    
    EXP0_I(20) = 0;
    
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
}

// 100% matching!
void bhEne01Head_Move(BH_PWORK* epw)
{
	bhEne01Head_MV00();
}

// 100% matching!
void bhEne01Head_MV00()
{
	
}

// 100% matching!
void bhEne01Head_Damage(BH_PWORK* epw)
{
	bhEne01Head_DamageMode[epw->mode2](epw);
}

// 99.97% matching
void bhEne01Head_DG00(BH_PWORK* epw) 
{
    ATR_WORK* hp;   
    BH_PWORK* ep;  
    O_WORK* owk;  
    NJS_POINT3 ps, pd; 
    NJS_POINT3 dv, dv2;  
    int i;      
    int tex_id; // not from DWARF

    ep = (BH_PWORK*)epw->lkwkp;
    
    owk = (O_WORK*)EXP0_I(4);

    switch (epw->mode3) 
    {
    case 0:
        epw->px = 2.0f;
        
        epw->ct0 = 0;
        epw->ct1 = 0;
        epw->ct2 = 0;
        
        epw->ax = 4096;
        epw->az = 7424;
        
        epw->mode3++;
    case 1:
        if ((epw->ct0++ % 4) == 0)
        {
            ps.x = 0;
            ps.y = 0;
            ps.z = 0;
            
            ep->djnt_no = 11;
            
            ps.y = 1.0f;

            dv2.x = 0;
            dv2.y = 0;
            dv2.z = 0;
            
            tex_id = bhEne01_ChgTextID(ep, 6);
            
            bhEne_SetBlood3(ep, 11, &ps, &dv2, 1, tex_id, 2, 0);

            njUnitMatrix(NULL);
            
            njRotateX(NULL, -13312);

            dv2.x = 0;
            dv2.y = 0;
            dv2.z = -1.0f;
            
            njCalcVector(NULL, &dv2, &dv);

            njUnitMatrix(NULL);
            
            for (i = 0; i < 4; i++) 
            {
                njCalcVector(NULL, &dv, &dv2);
                
                tex_id = bhEne01_ChgTextID(ep, 6);
                
                bhEne_SetBlood3(ep, 11, &ps, &dv2, 1, tex_id, 5, i);
                
                njRotateY(NULL, 16384);
            }
        }

        ps.x =  epw->px * njCos(epw->az);
        ps.y = (epw->px * njSin(epw->az)) - (0.2f * epw->ct1);
        
        epw->ct1++;

        njRotateX(&owk->mtx, epw->ax);         
        
        owk->mtx[12] -= ps.x * njSin(epw->ay);
        owk->mtx[13] += ps.y;
        owk->mtx[14] -= ps.x * njCos(epw->ay);

        pd.x = owk->mtx[12];
        pd.y = owk->mtx[13] - 1.0;
        pd.z = owk->mtx[14];

        if ((((sys->st_flg & 0x40)) && (!(epw->stflg & 0x100000))) && (bhCheckWater((NJS_POINT3*)&owk->mtx[12]) != NULL))
        {
            epw->stflg |= 0x100000;
            
            bhEne01_SePlay(ep, (NJS_POINT3*)&owk->mtx[12], 4871);
            
            bhSetWaterSplash2(epw, (NJS_POINT3*)&owk->mtx[12], 1, 1.1f, 1.1f, 1.1f);
        }

        if ((hp = bhCheckWallRefAngle(&pd, 0, 1.5f, 2.0f, &epw->ay)) != NULL)
        {
            owk->mtx[12] = pd.x;
            owk->mtx[14] = pd.z;
            
            bhEne01_SePlay(ep, (NJS_POINT3*)&owk->mtx[12], 4870);

            if (epw->ct2 < 2) 
            {
                if (hp->type == 7) 
                {
                    owk->mtx[13] = 1.0 + pd.y;

                    ps.x = 0.7 * (epw->px * njCos(epw->az));
                    ps.y = 0.6 * (epw->px * njSin(epw->az));

                    epw->px = njSqrt((ps.x * ps.x) + (ps.y * ps.y));
                    
                    epw->az = 10430.381f * acosf(ps.x / epw->px);
                    
                    epw->ct1 = 0;
                    
                    epw->ax /= 2;
                }
                
                epw->ct2++;
            } 
            else
            {
                owk->mtx[13] -= 500.0f;
                
                owk->flg |= 0x100;
                
                epw->mode3++;
            }

            if (owk->mtx[13] < -10.0f) 
            {
                epw->mode3++;
            }
        }
    case 2:
        break;
    }
}

// 100% matching!
void bhEne01Cap(BH_PWORK* epw) 
{
    if ((((O_WRK*)epw->lkwkp)->stflg & 0x1000000)) 
    {
        epw->stflg |=  0x1000000;
    } 
	else 
    {
        epw->stflg &= ~0x1000000;
    }
    
    bhEne01Cap_Mode0[epw->mode0](epw);
    
    bhCalcModel(epw);
}

// 100% matching!
void bhEne01Cap_Init(BH_PWORK* epw)
{
    epw->stflg = 0;
    
    epw->flg |= 0x8000;
    
    if (epw->exp0 == NULL) 
    {
        epw->exp0 = bhEne_CallocWork(112, 8);
    }
    
    if (!(epw->flg & 0x80)) 
    {
        epw->flg |= 0x80;
        
        epw->px = 0;
        epw->py = 0;
        epw->pz = 0;
        
        epw->ax = 0;
        epw->ay = 0;
        epw->az = 0;
    }
    
    EXP0_I(0) = 0;
    EXP0_I(4) = 0;
    EXP0_I(8) = 0;
    
    EXP0_I(20) = 0;
    
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
}

// 100% matching!
void bhEne01Cap_Move(BH_PWORK* epw)
{
	bhEne01Cap_MV00();
}

// 100% matching!
void bhEne01Cap_MV00()
{

}

// 100% matching!
void bhEne01Cap_Damage(BH_PWORK* epw)
{
	bhEne01Cap_DamageMode[epw->mode2](epw);
}

// 99.91% matching
void bhEne01Cap_DG00(BH_PWORK* epw) 
{
    NJS_POINT3 p[3] = 
	{
		{ 0.0f, -1.200000048f, -1.350000024f },
		{ 0.0f,          0.0f,          0.0f },
		{ 0.0f, -1.200000048f,          1.0f }
	};
    NJS_POINT3 pp[3]; 
    ATR_WORK* hp;    
    O_WORK* owk;     
    float heavy;    
    float wk0, wk1;        
    int ay;          
    int i;            

    switch (epw->mode3)
    {
    case 0:
        owk = epw->mlwP->owP;
        
        if ((((sys->st_flg & 0x40)) && (!(epw->stflg & 0x100000))) && (bhCheckWater((NJS_POINT3*)&owk->mtx[12]) != NULL)) 
        {
            epw->stflg |= 0x100000;
        }
        
        epw->ct0 = 0;
        epw->ct1 = 0;
        
        epw->mode3++;
    case 1:
        owk = epw->mlwP->owP;
        
        wk0 =  epw->dpx * njCos(epw->waz);
        wk1 = (epw->dpx * njSin(epw->waz)) - (0.08f * epw->ct1);

        owk->mtx[12] -= wk0 * njSin(epw->way);
        owk->mtx[13] += wk1;
        owk->mtx[14] -= wk0 * njCos(epw->way);
        
        epw->ct1++;

        for (i = 0; i < 3; i++)
        {
            njCalcPoint(&owk->mtx, &p[i], &pp[i]);
        }

        heavy = pp[epw->waxp].y;

        if ((heavy > pp[0].y) || (heavy > pp[1].y) || (heavy > pp[2].y)) 
        {
            njRotateX(&owk->mtx, epw->wax);
        }

        njTranslate(&owk->mtx, 0, -0.6f, 0);

        pp[0].x = owk->mtx[12];
        pp[0].y = owk->mtx[13] - 0.6f;
        pp[0].z = owk->mtx[14];
        
        ay = epw->way;

        if (bhCheckWallRefAngle(pp, 0x400, 1.0f, 1.2f, &ay) != NULL) 
        {
            if ((owk->mtx[13] - 0.6f) != pp[0].y)
            {
                if (epw->ct0 == 0)
                {
                    wk0 = (epw->dpx * njCos(epw->waz)) * 0.4;
                    wk1 = (epw->dpx * njSin(epw->waz)) * 0.6;
                    
                    epw->dpx = njSqrt((wk0 * wk0) + (wk1 * wk1));
                    
                    epw->waz = 10430.381f * acosf(wk0 / epw->dpx);
                    
                    epw->ct1 = 0;
                    epw->ct0++;
                } 
                else 
                {
                    epw->mode3++;
                }
            }
            
            owk->mtx[12] = pp[0].x;
            owk->mtx[13] = pp[0].y + 0.6f;
            owk->mtx[14] = pp[0].z;
        }

        njTranslate(&owk->mtx, 0, 0.6f, 0);

        if ((((sys->st_flg & 0x40)) && (!(epw->stflg & 0x100000))) && (bhCheckWater((NJS_POINT3*)&owk->mtx[12]) != NULL)) 
        {
            epw->stflg |= 0x100000;
            
            bhSetWaterSplash2(epw, (NJS_POINT3*)&owk->mtx[12], 1, 1.1f, 1.1f, 1.1f);
        }
        
        break;
    case 2:
        break;
    }
}

// 100% matching!
void bhEne01Cap_DG01(BH_PWORK* epw) 
{
    ATR_WORK* hp;  
    O_WORK* owk;  
    NJS_POINT3 ps, pd; 
    int ay;        
    float grand_h;

    switch (epw->mode3) 
    {
    case 0:
        epw->dpx = 0.16f;
        
        epw->ct0 = 0;
        epw->ct1 = 0;
        epw->ct2 = 0;
        
        epw->wax = 4096;
        epw->waz = 12288;
        
        epw->ax = 32768;
        
        njSetMatrix((NJS_MATRIX*)&epw->exp0[48], &epw->mlwP->owP->mtx);

        njTranslate((NJS_MATRIX*)&epw->exp0[48], 0.0f, -1.2f, -1.35f);
        
        epw->waz = 0;
        
        epw->mode3++;
    case 1:
        owk = epw->mlwP->owP;
        
        if (owk->mtx[13] > EXP0_F(100)) 
        {
            njRotateX((NJS_MATRIX*)&epw->exp0[48], -1536);
            njRotateX(&owk->mtx,                   -1536);
        }
        else 
        {
            epw->ct0 = 0;
            
            epw->mode3++;
            break;
        }
        
        ay = epw->ay;
        
        if ((hp = bhCheckWallRefAngle(&pd, 1024, 2.0f, 2.0f, &ay)) != NULL) 
        {
            if ((hp->type == 0) && (hp->type == 2) && (hp->type == 4)) 
            {
                EXP0_F(96)  = pd.x;
                EXP0_F(104) = pd.z;
            } 
            else if (hp->type == 6)
            {
                njRotateX((NJS_MATRIX*)&epw->exp0[48], -1536);
                njRotateX(&owk->mtx,                   -1536);
            }
        }
        
        ps.x = 0;
        ps.y = 1.2f;
        ps.z = 1.35f;
        
        njCalcPoint((NJS_MATRIX*)&epw->exp0[48], &ps, &pd);
        
        owk->mtx[12] = pd.x;
        owk->mtx[14] = pd.z;
        
        grand_h = bhGetGroundPosition((NJS_POINT3*)&owk->mtx[12]);
        
        owk->mtx[13] = pd.y;
        
        if (owk->mtx[13] < (grand_h + 0.2)) 
        {
            owk->mtx[13] = grand_h + 0.4;
            
            epw->mode3++;
        }
        
        break;
    case 2:
        if (++epw->ct0 > 3) 
        {
            epw->mode3++;
            
            epw->ct0 = 0;
            break;
        }
        
        njRotateX(&epw->mlwP->owP->mtx, -1536);
        break;
    case 3:
        break;
    }
}

// 100% matching!
void bhEne01Worm(BH_PWORK* epw) 
{
    NJS_CNK_OBJECT* obj;

    bhEne01Worm_Mode0[epw->mode0](epw);
    
    bhSetMotion(epw, (int)epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    
    if (epw->mtn_no == 159) 
    {
        obj = epw->mlwP->objP;
        
        obj->pos[0] = 0;
        obj->pos[2] = 0;
    }
    
    if (!(epw->mdflg & 0x4)) 
    {
        bhCalcModel(epw);
    }
}

// 100% matching!
void bhEne01Worm_Init(BH_PWORK* epw) 
{
    epw->stflg = 0;
    
    epw->flg |=  0x8000;
    epw->flg &= ~0x100000;
    
    epw->hokan_rate  = 0;
    epw->hokan_count = 0;
    
    epw->frm_no = 0;
    
    epw->mtn_add = 65536;
    epw->mtn_no  = 168;
    epw->mtn_tp  = NULL;
    epw->mtn_md  = 0;
    
    if (epw->exp0 == NULL) 
    {
        epw->exp0 = bhEne_CallocWork(112, 8);
    }
    
    if (!(epw->flg & 0x80))
    {
        epw->flg   |= 0x80;
        epw->mdflg |= 0x1;
        
        epw->px = 0;
        epw->py = 0;
        epw->pz = 0;
        
        epw->ax = 0;
        epw->ay = 0;
        epw->az = 0;
    } 
    else if (epw->lkwkp != epw->exp1) 
    {
        epw->mdflg |= 0x1;
        
        epw->lkwkp = epw->exp1;
        
        epw->lox = 0;
        epw->loy = 1.0f;
        epw->loz = 0;
    }
    
    epw->flg &= ~0x2;
    
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
}

// 100% matching!
void bhEne01Worm_Move(BH_PWORK* epw)
{
	bhEne01Worm_MoveMode[epw->mode2](epw);
}

// 100% matching!
void bhEne01Worm_MV00()
{

}

// 100% matching!
void bhEne01Worm_MV01(BH_PWORK* epw) 
{
    NJS_CNK_OBJECT* obj; 
    O_WORK* owk;         
    NJS_POINT3 pos;      

    switch (epw->mode3) 
    {                                     
    case 0:                                                 
        epw->flg   &= ~0x80;
        epw->mdflg &= ~0x1;
        
        if (epw->mode1 == 0) 
        {
            bhEne_ChgMtn(epw, 154, 0, 0);
        } 
        else if (epw->mode1 == 1) 
        {
            bhEne_ChgMtn(epw, 155, 0, 0);
        } 
        else if (epw->mode1 == 2) 
        {
            bhEne_ChgMtn(epw, 156, 0, 0);
        } 
        else 
        {
            bhEne_ChgMtn(epw, 157, 0, 0);
        }
        
        epw->ay = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
        
        bhEne01_SePlay((BH_PWORK*)epw->exp1, (NJS_POINT3*)&epw->mlwP->owP->mtx[12], 74560);
        
        epw->mode3++;
    case 1:                                                 
        ikou(epw, (NJS_POINT3*)&plp->px, 1024);
        
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
        {
            owk = epw->mlwP->owP;
            
            epw->px = owk->mtx[12];
            epw->py = owk->mtx[13];
            epw->pz = owk->mtx[14];
            
            bhEne_ChgMtn(epw, 158, 0, 0);
            
            epw->spd = 3.0f;
            
            bhAddSpeed(epw, 0);
            
            epw->mode3++;
        }
        
        break;
    case 2:                                                 
        pos.x = epw->px;
        pos.y = plp->py;
        pos.z = epw->pz;
        
        if (njDistanceP2P((NJS_POINT3*)&plp->px, &pos) < 5.0f) 
        {
            bhEne_ChgMtn(epw, 159, 0, 0);
            
            epw->mdflg |= 0x4;
            epw->flg   |= 0x80;
            
            epw->lkwkp = (unsigned char*)plp;
            epw->lkono = 0;
            
            epw->lox = 0;
            epw->loy = 0;
            epw->loz = 1.870168f;
            
            epw->ax = 0;
            epw->ay = 0;
            epw->az = 0;
            
            epw->mode3++;
            
            plp->mtn_no = 42;
            plp->frm_no = 0;
            
            plp->hokan_count = 5;
            plp->hokan_rate  = 49152;
            
            plp->mtn_add = 65536;
            plp->mtn_md  = 0;
            
            plp->flg &= ~0x40000;
            
            plp->mode0 = 4;
            plp->mode1 = 0;
            plp->mode2 = 0;
            plp->mode3 = 0;
            break;
        }
        
        ikou(epw, (NJS_POINT3*)&plp->px, 1024);
        
        epw->spd = 3.0f;
        
        bhAddSpeed(epw, 0);
        break;
    case 3:                                                 
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
        {
            bhEne01_SePlay((BH_PWORK*)epw->exp1, (NJS_POINT3*)&epw->mlwP->owP->mtx[12], 16851777);
            
            epw->mdflg &= ~0x4;
            epw->flg   &= ~0x80;
            
            pos.x = 0;
            pos.y = 0;
            pos.z = 1.599416f;
            
            njCalcPoint(plp->mtx, &pos, (NJS_POINT3*)&epw->px);
            
            epw->ay = plp->ay;
            
            bhEne_ChgMtn(epw, 167, 0, 0);
            
            epw->mode3++;
            
            plp->flg |= 0x4;
            
            plp->mnwP = epw->mnwP;
            
            plp->frm_no = 0;
            
            plp->hokan_count = 0;
            plp->hokan_rate  = 52428;
            
            plp->mtn_add = 65536;
            plp->mtn_md  = 0;
            plp->mtn_no  = En01_PlyMtn_OffsetTbl[sys->ply_id] + 20;
            
            plp->mode0 = 4;
            plp->mode1 = 0;
            plp->mode2 = 0;
            plp->mode3 = 0;
        }
        
        break;
    case 4:
        if ((epw->frm_no / 65536) == 19) 
        {
            pos.x =  0;
            pos.y = -0.8f;
            pos.z =  0;
            
            epw->djnt_no = 1;
            
            bhEne_SetBlood2(epw, 6, &pos, plp->ay + 32768);
            
            bhEne01_SePlay((BH_PWORK*)epw->exp1, (NJS_POINT3*)&epw->mlwP->owP->mtx[12], 16786242);
        }
        
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            bhEne_ChgMtn(epw, 168, 0, 0);
            
            epw->mdflg |= 0x4;
            epw->flg   |= 0x80;
            
            epw->lkono = 3;
            
            epw->lox = 0;
            epw->loy = 1.035046f;
            epw->loz = 1.870168f;
            
            epw->ay = 0;
            
            pos.x =  0.06567f;
            pos.y =  0;
            pos.z = -3.911583f;
            
            njCalcPoint(plp->mtx, &pos, (NJS_POINT3*)&plp->px);
            
            PEXP0_F(72) = plp->px;
            PEXP0_F(80) = plp->pz;
            
            obj = plp->mlwP->objP;
            
            obj->pos[0] = obj->pos[2] = 0;
            
            sys->pad_on &= ~0xF;
            
            plp->flg &= ~0x10000;
            plp->flg |=  0x8;
            
            plp->stflg &= ~0x10000;
            
            plp->at_flg = 0;
            
            plp->mnwP = plp->mnwPb;
            
            *(int*)&plp->mode0 = 1;
            
            plp->flg &= ~0x4;
            
            plp->hp -= 10;
            
            if (plp->hp <= 0) 
            {
                plp->hp = 1;
            }
            
            epw->mode1 = 0;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        
        break;
    }
}

// 100% matching!
void bhEne01Worm_MV02(BH_PWORK* epw)
{
    NJS_POINT3 pos;
    int frm;

    switch (epw->mode3)
    {
    case 0:
        epw->ct0 = 90;
        epw->ct1 = 0;
        epw->ct2 = 60;
        
        epw->mode3++;
    case 1:
        epw->ct2 -= bhEne_LeverCheck();
        
        if (((epw->ct1 >= 4) || (epw->ct2 < 0)) && ((((!(plp->flg & 0x4)) && (!(plp->flg & 0x2))) && (!(plp->stflg & 0x80000000))) && (plp->hp >= 0)))
        {
            epw->mdflg &= ~0x4;
            epw->flg   &= ~0x80;
            
            bhEne_ChgMtn(epw, 164, 0, 0);
            
            pos.x = pos.y = 0;
            pos.z = 1.599416f;
            
            njCalcPoint(plp->mtx, &pos, (NJS_POINT3*)&epw->px);
            
            epw->ay = plp->ay;
            
            plp->flg |=  0x4;
            plp->flg &= ~0x40000;
            
            plp->mnwP = epw->mnwP;
            
            plp->frm_no = 0;
            
            plp->hokan_count = 0;
            plp->hokan_rate  = 49152;
            
            plp->mtn_add = 65536;
            plp->mtn_md  = 0;
            plp->mtn_no  = En01_PlyMtn_OffsetTbl[sys->ply_id] + 22;
            
            epw->mode3 = 3;
            
            plp->mode0 = 4;
            plp->mode1 = 0;
            plp->mode2 = 0;
            plp->mode3 = 0;
            break;
        }
        
        if ((--epw->ct0 < 0) && (((((!(plp->flg & 0x4)) && (!(plp->flg & 0x2))) && (!(plp->stflg & 0x80000000))) && (plp->hp >= 0))))
        {
            bhEne_ChgMtn(epw, 163, 0, 0);
            
            epw->mdflg |= 0x4;
            epw->flg   |= 0x80;
            
            epw->lkono = 3;
            
            epw->lox = 0.0f;
            epw->loy = 1.035046f;
            epw->loz = 1.870168f;
            
            epw->ay = 0;
            
            epw->mode3++;
            
            plp->flg |=  0x4;
            plp->flg &= ~0x40000;
            
            plp->mnwP = epw->mnwP;
            
            plp->frm_no = 0;
            
            plp->hokan_count = 5;
            plp->hokan_rate  = 49152;
            
            plp->mtn_add = 65536;
            plp->mtn_md  = 0;
            plp->mtn_no  = En01_PlyMtn_OffsetTbl[sys->ply_id] + 21;
            
            plp->hp -= 10;
            
            if (plp->hp <= 0)
            {
                plp->hp = 1;
            }
            
            plp->mode0 = 4;
            plp->mode1 = 0;
            plp->mode2 = 0;
            plp->mode3 = 0;
        }
        
        break;
    case 2:
        if ((epw->frm_no / 65536) == 1) 
        {
            pos.x = 0;
            pos.y = -0.8f;
            pos.z = 0;
            
            epw->djnt_no = 1;

            bhEne_SetBlood2(epw, 6, &pos, plp->ay + 32768);
            
            bhEne01_SePlay((BH_PWORK*)epw->exp1, (NJS_POINT3*)&epw->mlwP->owP->mtx[12], 16786242);
        }
        
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            bhEne_ChgMtn(epw, 168, 0, 0);
            
            epw->mdflg |= 0x4;
            epw->flg   |= 0x80;
            
            epw->lkono = 3;
            
            epw->lox = 0;
            epw->loy = 1.035046f;
            epw->loz = 1.870168f;
            
            epw->ct0 = 90;
            
            epw->mode3 = 1;
            
            epw->ay = 0;
            
            sys->pad_on &= ~0xF;
            
            plp->flg &= ~0x10000;
            plp->flg |=  0x8;
            
            plp->stflg &= ~0x10000;
            
            plp->at_flg = 0;
            
            plp->mnwP = plp->mnwPb;
            
            *(int*)&plp->mode0 = 1;
            
            plp->flg &= ~0x4;
            
            epw->ct1++;
        }
        
        break;
    case 3:
        frm = epw->frm_no / 65536;
        
        if (frm == 36)
        {
            epw->lkwkp = epw->exp1;
            
            bhEne01_ExpWormEffect(epw);
            
            bhEne01_SePlay((BH_PWORK*)epw->exp1, (NJS_POINT3*)&epw->mlwP->owP->mtx[12], 9027);
        }
        
        if (frm == 40)
        {
            epw->mdflg |= 0x1;
        }
        
        if ((plp->frm_no / 65536) == (plp->mnwP[plp->mtn_no].frm_num - 1))
        {
            epw->mtn_add = 0;
            
            epw->flg |=  0x2;
            epw->flg &= ~0x100000;
            
            epw->mode3++;
            
            sys->pad_on &= ~0xF;
            
            plp->flg &= ~0x10000;
            plp->flg |=  0x8;
            
            plp->stflg &= ~0x10000;
            
            plp->at_flg = 0;
            
            plp->mnwP = plp->mnwPb;
            
            *(int*)&plp->mode0 = 1;
            
            plp->flg &= ~0x4;
        }
        
        break;
    case 4:
        break;
    }
}

// 100% matching!
void bhEne01Bom(BH_PWORK* epw)
{
    BH_PWORK* ep;
    O_WORK* owk;
    NJS_POINT3 pos;
   
    ep = (BH_PWORK*)epw->lkwkp;
    
    if ((ep->stflg & 0x1000000)) 
    {
        epw->stflg |=  0x1000000;
    } 
    else 
    {
        epw->stflg &= ~0x1000000;
    }
    
    if ((ep->flg & 0x2)) 
    {
        epw->flg &= ~0x20;
    }
    
    bhEne01Bom_Mode0[epw->mode0](epw);
    
    if ((epw->flg & 0x4)) 
    {
        epw->flg &= ~0x4;
    }
    
    bhCalcModel(epw);
    
    owk = epw->mlwP->owP;
    
    pos.x = 0;
    pos.y = 1.0f;
    pos.z = 0;
    
    njCalcPoint(&owk->mtx, &pos, (NJS_POINT3*)&epw->watr.c1);
    
    pos.y = -1.0f;
    
    njCalcPoint(&owk->mtx, &pos, (NJS_POINT3*)&epw->watr.c2);
    
    epw->watr.r = 2.0f;
}

CPCL Ene01BomCapColTab[3] = 
{
	{ 0, 0, 14 },
	{ 0, 0, 0  },
	{ 0, 0, 0  }
};

// 100% matching!
void bhEne01Bom_Init(BH_PWORK* epw) 
{
    BH_PWORK* ep;
    int i;
    
    ep = (BH_PWORK*)epw->lkwkp;
    
    epw->ar = 3.0f;
    epw->ah = 3.0f;
    
    epw->aw = 0;
    epw->ad = 0;
    
    epw->car = 3.0f;
    epw->cah = 3.0f;
    
    epw->stflg = 0;
    
    epw->hp = 1;
    
    for (i = 0; i < 64; i++) 
    {
        epw->dam[i] = 0;
    } 
    
    epw->flg |= 0x8020;
    
    epw->cpcl = Ene01BomCapColTab;
    
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
    
    if (ep->type == 13) 
    {
        epw->mdflg &= ~0x1;
    }
    else 
    {
        epw->mdflg |= 0x1;
        
        epw->flg &= ~0x20;
    }
}

// 100% matching!
void bhEne01Bom_Move(BH_PWORK* epw)
{
    BH_PWORK* ep = (BH_PWORK*)epw->lkwkp;
    NJS_POINT3 pos = { 0.0f, 0.0f, 2.0f }, pos2;
    
    switch (epw->mode3)
    {                             
    case 0:
        if (((epw->flg & 0x4)) && (((epw->wpnr_no != 2) && (epw->wpnr_no != 10)) && ((epw->wpnr_no != 17) || ((epw->flg2 & 0x4)))))
        {
			njCalcPoint(&epw->mlwP->owP->mtx, &pos, &pos2);
			
			if (pos2.y < rom->grand[epw->flr_no + 2]) 
			{
				pos2.y = 1.0f + rom->grand[epw->flr_no + 2];
			}
			
			bhSetExplosion(&pos2);
			
			bhEne01_SePlay(ep, &pos2, 4936);
			
			epw->mdflg |= 0x1;
			
			epw->flg &= ~0x20;
			
			epw->mode3++;
        }
    case 1:
        break;
    }
}

// 100% matching!
void bhEne01Scope(BH_PWORK* epw) 
{
    if ((((O_WRK*)epw->lkwkp)->stflg & 0x1000000)) 
    {
        epw->stflg |=  0x1000000;
    } 
    else 
    {
        epw->stflg &= ~0x1000000;
    }
    
    bhEne01Scope_Mode0[epw->mode0](epw);
    
    bhCalcModel(epw);
    
    bhEne01Scope_Effect(epw); 
}

// 100% matching!
void bhEne01Scope_Init(BH_PWORK* epw)
{
    if (((O_WRK*)epw->lkwkp)->type == 14) 
    {
        epw->mdflg &= ~0x1;
    } 
    else 
    {
        epw->mdflg |=  0x1;
    }
    
    epw->stflg = 0;
    
    epw->flg |= 0x8000;
    
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
}

// 100% matching!
void bhEne01Scope_Move()
{
	
}

// 100% matching!
void bhEne01Scope_Effect(BH_PWORK* epw) 
{
	static NJS_POINT3 scope_ofs[2] = 
	{
		{  0.3f, -0.5f, -1.1f },
		{ -0.3f, -0.5f, -1.1f }
	};
    BH_PWORK* ep;
    int i;
    int eno;
    
    ep = (BH_PWORK*)epw->lkwkp;
    
    if (((epw->mdflg & 0x1)) || ((ep->flg & 0x2))) 
    {
        return;
    }
    
    sys->ef.id   = 355;
    sys->ef.type = 0;
    
    sys->ef.flg = 1;
    
    sys->ef.sx = 0.18f;
    sys->ef.sy = 0.18f;
    sys->ef.sz = 0.18f;
    
    sys->ef.mdlver = 0;
    
    for (i = 0; i < 2; i++) 
    {
        njCalcPoint(epw->mtx, &scope_ofs[i], (NJS_POINT3*)&sys->ef.px);
        
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        
        if ((eno != -1) || (eno < 512)) 
        {
            eff[eno].ax = 10430.381f * atan2f(epw->mtx[0][6], epw->mtx[0][10]);
            eff[eno].ay = 10430.381f * asinf(-epw->mtx[0][2]);
            eff[eno].az = 10430.381f * atan2f(epw->mtx[0][1], epw->mtx[0][0]);
            
            eff[eno].ct3 = 0;
            
            eff[eno].exp0 = (unsigned char*)ep;
        }
    }
}
