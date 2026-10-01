#include "../../../ps2/veronica/prog/en13.h"
#include "../../../ps2/veronica/prog/en13sub.h"
#include "../../../ps2/veronica/prog/en02.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

// ENEMY: Second Form Alexia 

static EGG_WORK ene18 = 
{
    0x8081, 18, 0, 0, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, { 0, 0, 0, 0 } 
};
static EGG_WORK ene13B = 
{
    0x8081, 31, 0, 0, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, { 0, 0, 0, 0 } 
};
void (*bhEne13_Mode0[6])(BH_PWORK*) = 
{
	bhEne13_Init,
	bhEne13_Move,
	bhEne13_Nage,
	bhEne13_Damage,
	bhEne13_Die,
	bhEne_Event
};       
void (*bhEne13_BrainType[2])(BH_PWORK*) = 
{
	bhEne13_BR00,
	bhEne13_BR01
};   
void (*bhEne13_MoveMode2[4])(BH_PWORK*) = 
{
	bhEne13_MV00,
	bhEne13_MV01,
	bhEne13_MV02,
	bhEne13_MV03
};   
void (*bhEne13_DamageMode2[1])(BH_PWORK*) = 
{
	bhEne13_DG00
}; 

// 100% matching!
void bhEne13(BH_PWORK* epw) 
{
    bhEne13_Mode0[epw->mode0](epw);
    
    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    
    bhCalcModel(epw);
    
    bhEne13_CameraControl(epw);
    bhEne13_PlayerControl(epw);
}

// 100% matching!
void bhEne13_Init(BH_PWORK* epw)
{
    BH_PWORK* ep;
    int i;

    epw->flg   |=  0x8018;
    epw->flg   &= ~0x6;
    
    epw->flg2  |=  0x1;
    
    epw->mdflg |=  0x20;
    
    epw->ar = 5.0f;
    epw->ah = 1.0f;
    
    epw->car = 3.0f;
    
    epw->hp = (sys->gm_mode != 2) ? 700 : 400;
    
    epw->mode0 = 1;
    epw->mode1 = 1;
    epw->mode2 = 0;
    epw->mode3 = 0;
    
    epw->hokan_rate  = 65536;
    epw->hokan_count = 0;
    
    epw->mtn_no  = 0;
    epw->mtn_md  = 0;
    epw->mtn_add = 65536;
    
    epw->frm_no = 0;
    
    if (epw->exp0 == NULL) 
    {
        epw->exp0 = bhEne_CallocWork(992, 8);

        *(BH_PWORK**)&epw->exp0[8] = bhSetEnemy(&ene18, rom->ene_n);
        
        (*(BH_PWORK**)&epw->exp0[8])->type = 1;
        
        (*(BH_PWORK**)&epw->exp0[8])->lkwkp = (unsigned char*)epw;
        (*(BH_PWORK**)&epw->exp0[8])->lkono = 0;
        
        (*(BH_PWORK**)&epw->exp0[8])->lox = 0;
        (*(BH_PWORK**)&epw->exp0[8])->loy = 0;
        (*(BH_PWORK**)&epw->exp0[8])->loz = 0;
        
        (*(BH_PWORK**)&epw->exp0[8])->mlwP = &epw->mdl[1];

        *(BH_PWORK**)&epw->exp0[12] = bhSetEnemy(&ene18, rom->ene_n);
        
        (*(BH_PWORK**)&epw->exp0[12])->type = 2;
        
        (*(BH_PWORK**)&epw->exp0[12])->lkwkp = (unsigned char*)epw;
        (*(BH_PWORK**)&epw->exp0[12])->lkono = 0;
        
        (*(BH_PWORK**)&epw->exp0[12])->lox = 0;
        (*(BH_PWORK**)&epw->exp0[12])->loy = 0;
        (*(BH_PWORK**)&epw->exp0[12])->loz = 0;
        
        (*(BH_PWORK**)&epw->exp0[12])->mlwP = &epw->mdl[4];

        *(BH_PWORK**)&epw->exp0[16] = bhSetEnemy(&ene18, rom->ene_n);
        
        (*(BH_PWORK**)&epw->exp0[16])->type = 3;
        
        (*(BH_PWORK**)&epw->exp0[16])->lkwkp = (unsigned char*)epw;
        (*(BH_PWORK**)&epw->exp0[16])->lkono = 0;
        
        (*(BH_PWORK**)&epw->exp0[16])->lox = 0;
        (*(BH_PWORK**)&epw->exp0[16])->loy = 0;
        (*(BH_PWORK**)&epw->exp0[16])->loz = 0;
        
        (*(BH_PWORK**)&epw->exp0[16])->mlwP = &epw->mdl[7];

        *(BH_PWORK**)&epw->exp0[4] = bhSetEnemy(&ene18, rom->ene_n);
        
        (*(BH_PWORK**)&epw->exp0[4])->type = 0;
        
        (*(BH_PWORK**)&epw->exp0[4])->lkwkp = (unsigned char*)epw;
        (*(BH_PWORK**)&epw->exp0[4])->lkono = 0;
        
        (*(BH_PWORK**)&epw->exp0[4])->lox = 0;
        (*(BH_PWORK**)&epw->exp0[4])->loy = 0;
        (*(BH_PWORK**)&epw->exp0[4])->loz = 0;
        
        (*(BH_PWORK**)&epw->exp0[4])->mlwP = &epw->mdl[10];

        *(NJS_CNK_OBJECT**)&epw->exp0[92]  = (*(BH_PWORK**)&epw->exp0[4])->mlwP->objP;
        *(NJS_CNK_OBJECT**)&epw->exp0[96]  = (*(BH_PWORK**)&epw->exp0[8])->mlwP->objP;
        *(NJS_CNK_OBJECT**)&epw->exp0[100] = (*(BH_PWORK**)&epw->exp0[12])->mlwP->objP;
        *(NJS_CNK_OBJECT**)&epw->exp0[104] = (*(BH_PWORK**)&epw->exp0[16])->mlwP->objP;

        for (i = 0; i < 6; i++)
        {
            ((BH_PWORK**)epw->exp0)[i + 5] = bhSetEnemy(&ene18, rom->ene_n);
            
            ((BH_PWORK**)epw->exp0)[i + 5]->type = i + 4;
            
            ((BH_PWORK**)epw->exp0)[i + 5]->lkwkp = (unsigned char*)epw;
            ((BH_PWORK**)epw->exp0)[i + 5]->lkono = 0;
            
            ((BH_PWORK**)epw->exp0)[i + 5]->lox = 0;
            ((BH_PWORK**)epw->exp0)[i + 5]->loy = 0;
            ((BH_PWORK**)epw->exp0)[i + 5]->loz = 0;
            
            ((BH_PWORK**)epw->exp0)[i + 5]->mlwP = &epw->mdl[10];
        }

        *(BH_PWORK**)&epw->exp0[976] = bhSetEnemy(&ene13B, rom->ene_n);

        (*(BH_PWORK**)&epw->exp0[976])->type = 0;
        
        (*(BH_PWORK**)&epw->exp0[976])->lkwkp = (unsigned char*)epw;
        (*(BH_PWORK**)&epw->exp0[976])->lkono = 0;
        
        (*(BH_PWORK**)&epw->exp0[976])->lox = 0;
        (*(BH_PWORK**)&epw->exp0[976])->loy = 0;
        (*(BH_PWORK**)&epw->exp0[976])->loz = 0;
        
        (*(BH_PWORK**)&epw->exp0[976])->mlwP = &epw->mdl[13];
        
        (*(BH_PWORK**)&epw->exp0[976])->skp[0] = epw->skp[13];
        
        (*(BH_PWORK**)&epw->exp0[976])->mdl_no = 0;
        
        (*(BH_PWORK**)&epw->exp0[976])->mnwP  = epw->mnwP;
        (*(BH_PWORK**)&epw->exp0[976])->mnwPb = epw->mnwPb;
        
        bhEne_SetCallFunc(bhEne13B, 31);
        
        EXP0_I(932) = 0;
        EXP0_I(936) = bhEne13_StoreObject(                        epw, (NJS_POINT3*)&epw->exp0[132], (NJS_VECTOR**)&epw->exp0[732], EXP0_I(932));
        EXP0_I(940) = bhEne13_StoreObject( *(BH_PWORK**)&epw->exp0[4], (NJS_POINT3*)&epw->exp0[132], (NJS_VECTOR**)&epw->exp0[732], EXP0_I(936));
        EXP0_I(944) = bhEne13_StoreObject( *(BH_PWORK**)&epw->exp0[8], (NJS_POINT3*)&epw->exp0[132], (NJS_VECTOR**)&epw->exp0[732], EXP0_I(940));
        EXP0_I(948) = bhEne13_StoreObject(*(BH_PWORK**)&epw->exp0[12], (NJS_POINT3*)&epw->exp0[132], (NJS_VECTOR**)&epw->exp0[732], EXP0_I(944));
        
        bhEne13_StoreObject(*(BH_PWORK**)&epw->exp0[16], (NJS_POINT3*)&epw->exp0[132], (NJS_VECTOR**)&epw->exp0[732], EXP0_I(948));
    }

    (*(BH_PWORK**)&epw->exp0[4])->mlwP->objP  = *(NJS_CNK_OBJECT**)&epw->exp0[92];
    (*(BH_PWORK**)&epw->exp0[8])->mlwP->objP  = *(NJS_CNK_OBJECT**)&epw->exp0[96];
    (*(BH_PWORK**)&epw->exp0[12])->mlwP->objP = *(NJS_CNK_OBJECT**)&epw->exp0[100];
    (*(BH_PWORK**)&epw->exp0[16])->mlwP->objP = *(NJS_CNK_OBJECT**)&epw->exp0[104];

    bhEne13_RestoreObject(                        epw, (NJS_POINT3*)&epw->exp0[132], (NJS_VECTOR**)&epw->exp0[732], EXP0_I(932));
    bhEne13_RestoreObject( *(BH_PWORK**)&epw->exp0[4], (NJS_POINT3*)&epw->exp0[132], (NJS_VECTOR**)&epw->exp0[732], EXP0_I(936));
    bhEne13_RestoreObject( *(BH_PWORK**)&epw->exp0[8], (NJS_POINT3*)&epw->exp0[132], (NJS_VECTOR**)&epw->exp0[732], EXP0_I(940));
    bhEne13_RestoreObject(*(BH_PWORK**)&epw->exp0[12], (NJS_POINT3*)&epw->exp0[132], (NJS_VECTOR**)&epw->exp0[732], EXP0_I(944));
    bhEne13_RestoreObject(*(BH_PWORK**)&epw->exp0[16], (NJS_POINT3*)&epw->exp0[132], (NJS_VECTOR**)&epw->exp0[732], EXP0_I(948));
    
    EXP0_I(108) = 0;

    ep = ene;
    
    for (i = 0; i < sys->ewk_n; i++, ep++)
    {
        if (((ep->flg & 0x1)) && (ep->id == 30))
        {
            *((BH_PWORK**)epw->exp0 + (EXP0_I(108) + 11)) = ep;
            
            EXP0_I(108)++;
            
            ep->lkwkp = (unsigned char*)epw;
        }
        
        if (((ep->flg & 0x1)) && (ep->id == 14)) 
        {
            *(BH_PWORK**)&epw->exp0[112] = ep;
            
            ep->lkwkp = (unsigned char*)epw;
        }
    }
    
    EXP0_I(964) = 15;
    EXP0_I(968) = 30;
    EXP0_I(972) = 45;
    
    EXP0_I(116) = EXP0_I(120) = EXP0_I(124) = 100;
}

// 100% matching!
void bhEne13_Brain(BH_PWORK* epw)
{
    bhEne13_BrainType[epw->type](epw);
}

// 
// Start address: 0x1daad0
void bhEne13_BR00(BH_PWORK* epw)
{
	float dist;
	int j;
	int i;
	BH_PWORK* ep;
	// Line 405, Address: 0x1daad0, Func Offset: 0
	// Line 411, Address: 0x1daadc, Func Offset: 0xc
	// Line 414, Address: 0x1daae8, Func Offset: 0x18
	// Line 417, Address: 0x1dab14, Func Offset: 0x44
	// Line 418, Address: 0x1dab34, Func Offset: 0x64
	// Line 419, Address: 0x1dab54, Func Offset: 0x84
	// Line 422, Address: 0x1dab74, Func Offset: 0xa4
	// Line 424, Address: 0x1daba0, Func Offset: 0xd0
	// Line 423, Address: 0x1daba4, Func Offset: 0xd4
	// Line 424, Address: 0x1daba8, Func Offset: 0xd8
	// Line 428, Address: 0x1dabac, Func Offset: 0xdc
	// Line 429, Address: 0x1dabc8, Func Offset: 0xf8
	// Line 430, Address: 0x1dabd0, Func Offset: 0x100
	// Line 431, Address: 0x1dabd8, Func Offset: 0x108
	// Line 433, Address: 0x1dabe4, Func Offset: 0x114
	// Line 437, Address: 0x1dabec, Func Offset: 0x11c
	// Line 438, Address: 0x1dac08, Func Offset: 0x138
	// Line 444, Address: 0x1dac64, Func Offset: 0x194
	// Line 445, Address: 0x1dac6c, Func Offset: 0x19c
	// Line 447, Address: 0x1dac88, Func Offset: 0x1b8
	// Line 449, Address: 0x1dacd0, Func Offset: 0x200
	// Line 450, Address: 0x1dacd8, Func Offset: 0x208
	// Line 452, Address: 0x1dace0, Func Offset: 0x210
	// Line 455, Address: 0x1dacf0, Func Offset: 0x220
	// Line 454, Address: 0x1dacf4, Func Offset: 0x224
	// Line 455, Address: 0x1dacf8, Func Offset: 0x228
	// Line 456, Address: 0x1dacfc, Func Offset: 0x22c
	// Line 457, Address: 0x1dad00, Func Offset: 0x230
	// Line 459, Address: 0x1dad0c, Func Offset: 0x23c
	// Line 460, Address: 0x1dad20, Func Offset: 0x250
	// Line 461, Address: 0x1dad28, Func Offset: 0x258
	// Line 462, Address: 0x1dad30, Func Offset: 0x260
	// Line 464, Address: 0x1dad34, Func Offset: 0x264
	// Line 470, Address: 0x1dad3c, Func Offset: 0x26c
	// Line 472, Address: 0x1dad4c, Func Offset: 0x27c
	// Line 473, Address: 0x1dad88, Func Offset: 0x2b8
	// Line 472, Address: 0x1dad90, Func Offset: 0x2c0
	// Line 474, Address: 0x1dad94, Func Offset: 0x2c4
	// Line 473, Address: 0x1dad98, Func Offset: 0x2c8
	// Line 475, Address: 0x1dad9c, Func Offset: 0x2cc
	// Line 477, Address: 0x1dadb8, Func Offset: 0x2e8
	// Line 479, Address: 0x1dadc0, Func Offset: 0x2f0
	// Line 480, Address: 0x1dadc4, Func Offset: 0x2f4
	// Line 481, Address: 0x1dadd8, Func Offset: 0x308
	// Line 482, Address: 0x1dade8, Func Offset: 0x318
	// Line 483, Address: 0x1dadfc, Func Offset: 0x32c
	// Line 484, Address: 0x1dae10, Func Offset: 0x340
	// Line 485, Address: 0x1dae18, Func Offset: 0x348
	// Line 487, Address: 0x1dae30, Func Offset: 0x360
	// Line 488, Address: 0x1dae34, Func Offset: 0x364
	// Line 489, Address: 0x1dae38, Func Offset: 0x368
	// Line 491, Address: 0x1dae3c, Func Offset: 0x36c
	// Line 492, Address: 0x1dae44, Func Offset: 0x374
	// Line 494, Address: 0x1dae50, Func Offset: 0x380
	// Line 496, Address: 0x1dae64, Func Offset: 0x394
	// Line 497, Address: 0x1dae68, Func Offset: 0x398
	// Func End, Address: 0x1dae78, Func Offset: 0x3a8
	scePrintf("bhEne13_BR00 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne13_BR01(BH_PWORK* epw) 
{
    int j;
    float dist;

    if (epw->hp < 0) 
    {
        return;
    }

    dist = njSqrt(((epw->px - plp->px) * (epw->px - plp->px)) + ((epw->pz - plp->pz) * (epw->pz - plp->pz)));

    if (EXP0_I(968) != 0)
    {
        EXP0_I(968)--;
    }
    
    if (EXP0_I(972) != 0)
    {
        EXP0_I(972)--;
    }
    
    if ((EXP0_I(972) == 0) && (dist > 60.0f))
    {
        epw->mode1 = 0;
        epw->mode2 = 2;
        epw->mode3 = 0;
        
        EXP0_I(972) = 45;
        return;
    }
    
    if ((EXP0_I(968) == 0) && (((*(BH_PWORK**)(&epw->exp0[8]))->mode2 != 4) && ((*(BH_PWORK**)(&epw->exp0[8]))->mode2 != 5) && ((*(BH_PWORK**)(&epw->exp0[12]))->mode2 != 4) && ((*(BH_PWORK**)(&epw->exp0[12]))->mode2 != 5) && ((*(BH_PWORK**)(&epw->exp0[16]))->mode2 != 4) && ((*(BH_PWORK**)(&epw->exp0[16]))->mode2 != 5)))
    {
        j = bhEne13_SelectTentacle(epw);
        
        if ((*(BH_PWORK**)(&epw->exp0[8] + (4 * j)))->mode2 == 0) 
        {
            EXP0_I(128) = j;

            if (njRandom() > 0.7f)
            {
                EXP0_I(984) = EXP0_I(128);
            }
            else 
            {
                EXP0_I(984) = EXP0_I(128) + 3;
            }
            
            epw->mode1 = 0;
            epw->mode2 = 3;
            epw->mode3 = 0;
    
            EXP0_I(968) = 30;
            
            if (EXP0_I(964) != 0)
            {
                EXP0_I(964)--;
            }
            else
            {
                epw->type = 0;
                return;
            }
        }
    }
}

// 100% matching!
void bhEne13_Move(BH_PWORK* epw)
{
    if (epw->mode1 == 1) 
    {
        bhEne13_Brain(epw);
    }
    
    bhEne13_MoveMode2[epw->mode2](epw);
    
    if (((((*(BH_PWORK**)&epw->exp0[20])->flg & 0x4)) || (((*(BH_PWORK**)&epw->exp0[24])->flg & 0x4)) || (((*(BH_PWORK**)&epw->exp0[28])->flg & 0x4)) || (((*(BH_PWORK**)&epw->exp0[32])->flg & 0x4)) || (((*(BH_PWORK**)&epw->exp0[36])->flg & 0x4)) || (((*(BH_PWORK**)&epw->exp0[40])->flg & 0x4))) || ((*(BH_PWORK**)&epw->exp0[112] != NULL) && ((*(BH_PWORK**)&epw->exp0[112])->type == 0) && (((*(BH_PWORK**)&epw->exp0[112])->flg & 0x4)))) 
    {
        bhEne13_InitDamage(epw);
    }
}

// 100% matching!
void bhEne13_MV00(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 0;
        epw->frm_no = 0;
        
        epw->hokan_count = 8;
        epw->hokan_rate  = 45875;
        
        epw->mode3++;
        break;
    }
}

// 100% matching!
void bhEne13_MV01(BH_PWORK* epw)
{
    BH_PWORK* ep;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 1;
        epw->frm_no = 0;
        
        epw->hokan_count = 8;
        epw->hokan_rate  = 45875;
        
        if ((*(BH_PWORK**)&epw->exp0[112])->type == 0)
        {
            (*(BH_PWORK**)&epw->exp0[112])->mode2 = 1;
            (*(BH_PWORK**)&epw->exp0[112])->mode3 = 0;
        }
        
        epw->ct0 = 10;
        
        epw->mode3++;
        break;
    case 1:
        if (epw->frm_no == 0) 
        {
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        
        if (epw->ct0-- == 0)
        {
            ep = *(BH_PWORK**)&epw->exp0[8] + EXP0_I(128);
            
            ep->mode2 = 2;
            ep->mode3 = 0;
        }
        
        break;
    }
}

// 100% matching!
void bhEne13_MV02(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 2;
        epw->frm_no = 0;
        
        epw->hokan_count = 8;
        epw->hokan_rate  = 45875;
        
        if ((*(BH_PWORK**)&epw->exp0[112])->type == 0)
        { 
            (*(BH_PWORK**)&epw->exp0[112])->mode2 = 2;
            (*(BH_PWORK**)&epw->exp0[112])->mode3 = 0; 
        }
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        
        epw->mode3++;
        break;
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        
        break;
    }
}

// 100% matching!
void bhEne13_MV03(BH_PWORK* epw) 
{
    BH_PWORK* ep;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 1;
        epw->frm_no = 0;
        
        epw->hokan_count = 8;
        epw->hokan_rate  = 45875;
        
        if ((*(BH_PWORK**)&epw->exp0[112])->type == 0)
        {
            (*(BH_PWORK**)&epw->exp0[112])->mode2 = 1;
            (*(BH_PWORK**)&epw->exp0[112])->mode3 = 0;
        }
        
        epw->ct0 = 10;
        
        epw->mode3++;
        break;
    case 1:
        if (epw->frm_no == 0) 
        {
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }
        
        if (epw->ct0-- == 0)
        {
            ep = *(BH_PWORK**)&epw->exp0[8] + EXP0_I(128);
            
            ep->mode3 = 0;
            
            if (EXP0_I(984) >= 3)
            {
                ep->mode2 = 4;
            }
            else
            {
                ep->mode2 = 5;
            }
        }
        
        break;
    }
}

// 100% matching!
void bhEne13_Nage()
{

}

// 
// Start address: 0x1db480
void bhEne13_Damage(BH_PWORK* epw)
{
	int max_dam;
	int i;
	int dam;
	// Line 764, Address: 0x1db480, Func Offset: 0
	// Line 768, Address: 0x1db498, Func Offset: 0x18
	// Line 776, Address: 0x1db53c, Func Offset: 0xbc
	// Line 779, Address: 0x1db540, Func Offset: 0xc0
	// Line 780, Address: 0x1db548, Func Offset: 0xc8
	// Line 781, Address: 0x1db564, Func Offset: 0xe4
	// Line 787, Address: 0x1db570, Func Offset: 0xf0
	// Line 788, Address: 0x1db580, Func Offset: 0x100
	// Line 789, Address: 0x1db58c, Func Offset: 0x10c
	// Line 792, Address: 0x1db590, Func Offset: 0x110
	// Line 794, Address: 0x1db5a0, Func Offset: 0x120
	// Line 795, Address: 0x1db5c4, Func Offset: 0x144
	// Line 796, Address: 0x1db5d0, Func Offset: 0x150
	// Line 797, Address: 0x1db5dc, Func Offset: 0x15c
	// Line 798, Address: 0x1db5e8, Func Offset: 0x168
	// Line 806, Address: 0x1db5ec, Func Offset: 0x16c
	// Line 809, Address: 0x1db5f8, Func Offset: 0x178
	// Line 810, Address: 0x1db618, Func Offset: 0x198
	// Func End, Address: 0x1db634, Func Offset: 0x1b4
	scePrintf("bhEne13_Damage - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne13_DG00(BH_PWORK* epw)
{
    switch (epw->mode3)
    { 
    case 0:
        epw->mtn_no = 3;
        epw->frm_no = 0;
        
        epw->hokan_count = 8;
        epw->hokan_rate  = 45875;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        
        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0) 
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
            
            epw->flg &= ~0x4;
        }
        
        if ((epw->frm_no == 3932160) && (epw->hp < 0))
        {
            epw->flg |= 0x2;
        }
    }
}

// 100% matching!
void bhEne13_Die(BH_PWORK* epw)
{
    int i;

    switch (epw->mode3) 
    {
    case 0:
        (*(unsigned char**)&epw->exp0[976])[12] = 4;
        (*(unsigned char**)&epw->exp0[976])[13] = 0;
        (*(unsigned char**)&epw->exp0[976])[14] = 0;
        (*(unsigned char**)&epw->exp0[976])[15] = 0;

        for (i = 0; i < 4; i++)
        {
            ((unsigned char**)epw->exp0)[1 + i][12] = 4;
            ((unsigned char**)epw->exp0)[1 + i][13] = 0;
            ((unsigned char**)epw->exp0)[1 + i][14] = 0;
            ((unsigned char**)epw->exp0)[1 + i][15] = 0;
        }

        for (i = 0; i < 6; i++) 
        {
            ((unsigned char**)epw->exp0)[5 + i][12] = 4;
            ((unsigned char**)epw->exp0)[5 + i][13] = 0;
            ((unsigned char**)epw->exp0)[5 + i][14] = 0;
            ((unsigned char**)epw->exp0)[5 + i][15] = 0;
        }

        epw->mode3++;
        break;
    case 1:
        epw->spd = 0.97f + (epw->mode2 / 50.0f);
        
        bhEne13_Finish(epw);
        break;
    }
}

// 
// Start address: 0x1db8a0
void bhEne13_InitDamage(BH_PWORK* epw)
{
	int flg;
	int dflg;
	int wep_no;
	int i;
	int max_dam;
	int dam2;
	int dam1;
	int dam0;
	int dam;
	// Line 897, Address: 0x1db8a0, Func Offset: 0
	// Line 901, Address: 0x1db8d0, Func Offset: 0x30
	// Line 904, Address: 0x1db8e0, Func Offset: 0x40
	// Line 905, Address: 0x1db8e8, Func Offset: 0x48
	// Line 906, Address: 0x1db904, Func Offset: 0x64
	// Line 914, Address: 0x1db910, Func Offset: 0x70
	// Line 915, Address: 0x1db920, Func Offset: 0x80
	// Line 917, Address: 0x1db92c, Func Offset: 0x8c
	// Line 916, Address: 0x1db930, Func Offset: 0x90
	// Line 917, Address: 0x1db934, Func Offset: 0x94
	// Line 918, Address: 0x1db940, Func Offset: 0xa0
	// Line 921, Address: 0x1db948, Func Offset: 0xa8
	// Line 923, Address: 0x1db958, Func Offset: 0xb8
	// Line 924, Address: 0x1db97c, Func Offset: 0xdc
	// Line 925, Address: 0x1db988, Func Offset: 0xe8
	// Line 926, Address: 0x1db994, Func Offset: 0xf4
	// Line 928, Address: 0x1db9a0, Func Offset: 0x100
	// Line 929, Address: 0x1db9a4, Func Offset: 0x104
	// Line 927, Address: 0x1db9a8, Func Offset: 0x108
	// Line 929, Address: 0x1db9ac, Func Offset: 0x10c
	// Line 928, Address: 0x1db9b4, Func Offset: 0x114
	// Line 929, Address: 0x1db9b8, Func Offset: 0x118
	// Line 928, Address: 0x1db9bc, Func Offset: 0x11c
	// Line 929, Address: 0x1db9c0, Func Offset: 0x120
	// Line 933, Address: 0x1db9c4, Func Offset: 0x124
	// Line 937, Address: 0x1db9e4, Func Offset: 0x144
	// Line 941, Address: 0x1dba10, Func Offset: 0x170
	// Line 943, Address: 0x1dba18, Func Offset: 0x178
	// Line 981, Address: 0x1dba28, Func Offset: 0x188
	// Line 982, Address: 0x1dba38, Func Offset: 0x198
	// Line 983, Address: 0x1dba40, Func Offset: 0x1a0
	// Line 986, Address: 0x1dba50, Func Offset: 0x1b0
	// Line 987, Address: 0x1dba64, Func Offset: 0x1c4
	// Line 988, Address: 0x1dba6c, Func Offset: 0x1cc
	// Line 991, Address: 0x1dba7c, Func Offset: 0x1dc
	// Line 992, Address: 0x1dba90, Func Offset: 0x1f0
	// Line 993, Address: 0x1dba98, Func Offset: 0x1f8
	// Line 996, Address: 0x1dbaa8, Func Offset: 0x208
	// Line 997, Address: 0x1dbab0, Func Offset: 0x210
	// Line 998, Address: 0x1dbab8, Func Offset: 0x218
	// Line 999, Address: 0x1dbac4, Func Offset: 0x224
	// Line 1004, Address: 0x1dbac8, Func Offset: 0x228
	// Line 1005, Address: 0x1dbad0, Func Offset: 0x230
	// Line 1006, Address: 0x1dbad8, Func Offset: 0x238
	// Line 1007, Address: 0x1dbadc, Func Offset: 0x23c
	// Line 1008, Address: 0x1dbae0, Func Offset: 0x240
	// Line 1011, Address: 0x1dbae4, Func Offset: 0x244
	// Line 1012, Address: 0x1dbaf8, Func Offset: 0x258
	// Line 1014, Address: 0x1dbb04, Func Offset: 0x264
	// Line 1015, Address: 0x1dbb08, Func Offset: 0x268
	// Line 1016, Address: 0x1dbb0c, Func Offset: 0x26c
	// Line 1015, Address: 0x1dbb10, Func Offset: 0x270
	// Line 1016, Address: 0x1dbb18, Func Offset: 0x278
	// Line 1017, Address: 0x1dbb24, Func Offset: 0x284
	// Line 1018, Address: 0x1dbb2c, Func Offset: 0x28c
	// Line 1020, Address: 0x1dbb34, Func Offset: 0x294
	// Line 1021, Address: 0x1dbb38, Func Offset: 0x298
	// Line 1022, Address: 0x1dbb44, Func Offset: 0x2a4
	// Line 1023, Address: 0x1dbb50, Func Offset: 0x2b0
	// Line 1028, Address: 0x1dbb5c, Func Offset: 0x2bc
	// Func End, Address: 0x1dbb8c, Func Offset: 0x2ec
	scePrintf("bhEne13_InitDamage - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne13_Finish(BH_PWORK* epw) 
{
    NJS_CNK_OBJECT* pObj; 
    int ono, obj_n;             
    int i;               

    for (i = 0; i < 4; i++)
    {
        pObj  = (*(BH_PWORK**)(&epw->exp0[4] + (4 * i)))->mlwP->objP;
        obj_n = (*(BH_PWORK**)(&epw->exp0[4] + (4 * i)))->mlwP->obj_num;

        for (ono = 0; ono < obj_n; ono++, pObj++)
        {
            pObj->pos[1] *= epw->spd;

            bhEne13_ScaleModel(pObj, 1.0f, epw->spd, 1.0f);
        }
    }

    pObj  = epw->mlwP->objP;
    obj_n = epw->mlwP->obj_num;

    for (ono = 0; ono < obj_n; ono++, pObj++)
    {
        if ((ono == 1) || (ono == 4) || (ono == 7) || (ono == 11) || (ono == 15) || (ono == 19))
        {
            pObj->pos[1] *= epw->spd;
        }
        else
        {
            pObj->pos[0] *= epw->spd;
            pObj->pos[1] *= epw->spd;
            pObj->pos[2] *= epw->spd;
        }

        bhEne13_ScaleModel(pObj, epw->spd, epw->spd, epw->spd);
    }
}

// 100% matching!
void bhEne13_ScaleModel(NJS_CNK_OBJECT* pObj, float sx, float sy, float sz)
{
	int nVtx;
	int i; 
 	NJS_POINT4* p; 
	HDR_PS* pHdr; 
   
    if (pObj->model != NULL)
    {
        pHdr = (HDR_PS*)pObj->model->vlist;
        
        nVtx = pHdr->usIndexMax;
        
        p = (NJS_POINT4*)&pHdr[1];
    
        for (i = 0; i < nVtx; i++)
        {
            p[0].x *= sx;
            p[0].y *= sy;
            p[0].z *= sz;
            
            p[1].x *= sx;
            p[1].y *= sy;
            p[1].z *= sz;
            
            p += 2;
        }
    }
}

// 100% matching!
int bhEne13_StoreObject(BH_PWORK* epw, NJS_POINT3* pos, NJS_VECTOR** v, int no)
{
	NJS_CNK_OBJECT* pObj;
	int ono, obj_n; 
	int i; 
	NJS_CNK_MODEL* pModel;
 	int nVtx;
	NJS_POINT4* ps, *pd; 
	HDR_PS* pHdr; 

    pObj = epw->mlwP->objP;
    
    obj_n = epw->mlwP->obj_num;

    for (ono = 0; ono < obj_n; ono++, pObj++, no++)
    {
        pos[no].x = pObj->pos[0];
        pos[no].y = pObj->pos[1];
        pos[no].z = pObj->pos[2];

        pModel = pObj->model;
        
        if (pModel != NULL)
        {
            pHdr = (HDR_PS*)pModel->vlist;
            
            nVtx = pHdr->usIndexMax;
            
            v[no] = bhEne_CallocWork(nVtx * 32, 64);
            
            pd = (NJS_POINT4*)v[no];
            ps = (NJS_POINT4*)&pHdr[1];

            for (i = 0; i < nVtx; i++)
            {
                pd[0].x = ps[0].x;
                pd[0].y = ps[0].y;
                pd[0].z = ps[0].z;
                
                pd[1].x = ps[1].x;
                pd[1].y = ps[1].y;
                pd[1].z = ps[1].z;
                
                ps += 2;
                pd += 2;
            }
        }
    }
    
    return no;
}

// 100% matching!
int bhEne13_RestoreObject(BH_PWORK* epw, NJS_POINT3* pos, NJS_VECTOR** v, int no)
{
	NJS_CNK_OBJECT* pObj; 
	int ono, obj_n;
	int i; 
	NJS_CNK_MODEL* pModel;
	int nVtx; 
	NJS_POINT4* ps, *pd;
	HDR_PS* pHdr;

    pObj = epw->mlwP->objP;
    
    obj_n = epw->mlwP->obj_num;

    for (ono = 0; ono < obj_n; ono++, pObj++, no++)
    {
        pObj->pos[0] = pos[no].x;
        pObj->pos[1] = pos[no].y;
        pObj->pos[2] = pos[no].z;

        pModel = pObj->model;
        
        if (pModel != NULL)
        {
            pHdr = (HDR_PS*)pModel->vlist;
            
            ps = (NJS_POINT4*)v[no];
            
            nVtx = pHdr->usIndexMax;
            
            pd = (NJS_POINT4*)&pHdr[1];

            for (i = 0; i < nVtx; i++)
            {
                pd[0].x = ps[0].x;
                pd[0].y = ps[0].y;
                pd[0].z = ps[0].z;
                
                pd[1].x = ps[1].x;
                pd[1].y = ps[1].y;
                pd[1].z = ps[1].z;
                
                ps += 2;
                pd += 2;
            }
        }
    }
    
    return no;
}

// 100% matching!
void bhEne13_PutAttacker(BH_PWORK* epw, int no)
{
    BH_PWORK* ep;       
	int i;           
	NJS_POINT3 wp;     
	NJS_POINT3 pos[3] =
	{
		{   0.0f,   0.0f, -25.0f },
		{ -20.0f,   0.0f, -13.0f },
		{  20.0f,   0.0f, -13.0f }
	};
	int ang[3] = { 0, 8192, 0xFFFFE000 }; 
    
    for (i = 0; i < EXP0_I(108); i++)
    {
        ep = *(BH_PWORK**)(&epw->exp0[44] + (4 * i));

        if ((ep->mode0 == 1) && (ep->mode2 == 0))
        {
            ep->mode1 = 0;
            ep->mode2 = 6;
            ep->mode3 = 0;

            njUnitMatrix(NULL);
            
            njRotateY(NULL, epw->ay);
            njCalcVector(NULL, &pos[no], &wp);

            ep->px = ep->pxb = epw->px + wp.x;
            ep->py = ep->pyb = epw->py + wp.y;
            ep->pz = ep->pzb = epw->pz + wp.z;

            ep->ay = epw->ay + ang[no];

            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74507);
            break;
        }
    }
}

// 100% matching!
void bhEne13_Tentacle(BH_PWORK* epw, int no)
{
    (*(unsigned char**)&epw->exp0[976])[12] = 1;
    (*(unsigned char**)&epw->exp0[976])[13] = 0;
    (*(unsigned char**)&epw->exp0[976])[14] = 1;
    (*(unsigned char**)&epw->exp0[976])[15] = 0;
    
    (*(unsigned short**)&epw->exp0[976])[3] = no;
}

// 100% matching!
int bhEne13_GetHatchNo(BH_PWORK* epw)
{
    return EXP0_I(128);
}

// 100% matching!
int bhEne13_GetTentaNo(BH_PWORK* epw)
{
    return EXP0_I(984);
}

// 100% matching!
BH_PWORK** bhEne13_GetChild(BH_PWORK* epw, int* num)
{
    *num = EXP0_I(108);
    
    return (BH_PWORK**)&epw->exp0[44];
}

// 100% matching!
void bhEne13_CameraControl(BH_PWORK* epw)
{
    if (epw->mode0 != 5)
    {
        if ((epw->flg & 0x80000))
        {
            cam.ofx = (EXP0_F(980) * njRandom()) - (EXP0_F(980) / 2.0f);
            cam.ofy = (EXP0_F(980) * njRandom()) - (EXP0_F(980) / 2.0f);
            cam.ofz = (EXP0_F(980) * njRandom()) - (EXP0_F(980) / 2.0f);
        }
        else if (EXP0_F(980) > 0.01f)
        {
            cam.ofx = (EXP0_F(980) * njRandom()) - (EXP0_F(980) / 2.0f);
            cam.ofy = (EXP0_F(980) * njRandom()) - (EXP0_F(980) / 2.0f);
            cam.ofz = (EXP0_F(980) * njRandom()) - (EXP0_F(980) / 2.0f);
            
            EXP0_F(980) *= 0.9f;
        }
        else
        {
            cam.ofx = cam.ofy = cam.ofz = 0;
        }
    }
}

// 100% matching!
void bhEne13_SetCamera(BH_PWORK* epw, float f)
{
    EXP0_F(980) = f;
}

// 100% matching!
int bhEne13_SelectTentacle(BH_PWORK* epw)
{
    int ang;

    ang = (short)(bhArcTan2(epw->px - plp->px, epw->pz - plp->pz) - epw->ay);
	
    if (njRandom() < 0.9f)
    {
        if (ang > NJM_DEG_ANG(30.0f))
        {
            return 1;
        }
        else if (ang < -NJM_DEG_ANG(30.0f))
        {
            return 2;
        }
    }

    return 0;
}

// 
// Start address: 0x1dc510
void bhEne13_PlayerControl(BH_PWORK* epw)
{
	// already inversed DWARF order
	int mtn[3][8] = 
	{
		{ 10, 11, 12, 13, 15, 14,  0,  0 },
		{ 16, 17, 18, 19, 21, 20,  0,  0 },
		{ 16, 17, 18, 19, 21, 20,  0,  0 } 
	};
	NJS_POINT3* trans[3][3] = 
	{
		{ cler_042, cler_043, cler_045 },
		{ cher_060, cher_061, cher_063 },
		{ cher_060, cher_061, cher_063 }
	};
	// Line 1503, Address: 0x1dc510, Func Offset: 0
	// Line 1504, Address: 0x1dc514, Func Offset: 0x4
	// Line 1503, Address: 0x1dc51c, Func Offset: 0xc
	// Line 1504, Address: 0x1dc520, Func Offset: 0x10
	// Line 1509, Address: 0x1dc534, Func Offset: 0x24
	// Line 1504, Address: 0x1dc53c, Func Offset: 0x2c
	// Line 1509, Address: 0x1dc554, Func Offset: 0x44
	// Line 1515, Address: 0x1dc558, Func Offset: 0x48
	// Line 1504, Address: 0x1dc560, Func Offset: 0x50
	// Line 1509, Address: 0x1dc568, Func Offset: 0x58
	// Line 1515, Address: 0x1dc580, Func Offset: 0x70
	// Line 1516, Address: 0x1dc590, Func Offset: 0x80
	// Line 1519, Address: 0x1dc5b0, Func Offset: 0xa0
	// Line 1521, Address: 0x1dc5dc, Func Offset: 0xcc
	// Line 1522, Address: 0x1dc5e8, Func Offset: 0xd8
	// Line 1521, Address: 0x1dc5ec, Func Offset: 0xdc
	// Line 1522, Address: 0x1dc5f4, Func Offset: 0xe4
	// Line 1523, Address: 0x1dc5fc, Func Offset: 0xec
	// Line 1522, Address: 0x1dc600, Func Offset: 0xf0
	// Line 1523, Address: 0x1dc608, Func Offset: 0xf8
	// Line 1525, Address: 0x1dc610, Func Offset: 0x100
	// Line 1523, Address: 0x1dc614, Func Offset: 0x104
	// Line 1525, Address: 0x1dc618, Func Offset: 0x108
	// Line 1526, Address: 0x1dc628, Func Offset: 0x118
	// Line 1527, Address: 0x1dc640, Func Offset: 0x130
	// Line 1528, Address: 0x1dc648, Func Offset: 0x138
	// Line 1530, Address: 0x1dc664, Func Offset: 0x154
	// Line 1531, Address: 0x1dc66c, Func Offset: 0x15c
	// Line 1532, Address: 0x1dc670, Func Offset: 0x160
	// Line 1533, Address: 0x1dc674, Func Offset: 0x164
	// Line 1536, Address: 0x1dc678, Func Offset: 0x168
	// Line 1530, Address: 0x1dc67c, Func Offset: 0x16c
	// Line 1531, Address: 0x1dc680, Func Offset: 0x170
	// Line 1539, Address: 0x1dc688, Func Offset: 0x178
	// Line 1531, Address: 0x1dc68c, Func Offset: 0x17c
	// Line 1532, Address: 0x1dc690, Func Offset: 0x180
	// Line 1533, Address: 0x1dc69c, Func Offset: 0x18c
	// Line 1534, Address: 0x1dc6a8, Func Offset: 0x198
	// Line 1536, Address: 0x1dc6b4, Func Offset: 0x1a4
	// Line 1534, Address: 0x1dc6b8, Func Offset: 0x1a8
	// Line 1536, Address: 0x1dc6c0, Func Offset: 0x1b0
	// Line 1539, Address: 0x1dc6c4, Func Offset: 0x1b4
	// Line 1541, Address: 0x1dc6cc, Func Offset: 0x1bc
	// Line 1543, Address: 0x1dc6d8, Func Offset: 0x1c8
	// Line 1545, Address: 0x1dc6e0, Func Offset: 0x1d0
	// Line 1546, Address: 0x1dc6e8, Func Offset: 0x1d8
	// Line 1548, Address: 0x1dc71c, Func Offset: 0x20c
	// Line 1551, Address: 0x1dc748, Func Offset: 0x238
	// Line 1552, Address: 0x1dc75c, Func Offset: 0x24c
	// Line 1553, Address: 0x1dc788, Func Offset: 0x278
	// Line 1552, Address: 0x1dc78c, Func Offset: 0x27c
	// Line 1553, Address: 0x1dc794, Func Offset: 0x284
	// Line 1556, Address: 0x1dc7a4, Func Offset: 0x294
	// Line 1557, Address: 0x1dc7b8, Func Offset: 0x2a8
	// Line 1558, Address: 0x1dc7c4, Func Offset: 0x2b4
	// Line 1559, Address: 0x1dc7cc, Func Offset: 0x2bc
	// Line 1558, Address: 0x1dc7d0, Func Offset: 0x2c0
	// Line 1559, Address: 0x1dc7d4, Func Offset: 0x2c4
	// Line 1558, Address: 0x1dc7d8, Func Offset: 0x2c8
	// Line 1559, Address: 0x1dc7e8, Func Offset: 0x2d8
	// Line 1560, Address: 0x1dc7f4, Func Offset: 0x2e4
	// Line 1561, Address: 0x1dc7fc, Func Offset: 0x2ec
	// Line 1563, Address: 0x1dc818, Func Offset: 0x308
	// Line 1565, Address: 0x1dc828, Func Offset: 0x318
	// Line 1567, Address: 0x1dc830, Func Offset: 0x320
	// Line 1569, Address: 0x1dc838, Func Offset: 0x328
	// Line 1570, Address: 0x1dc84c, Func Offset: 0x33c
	// Line 1572, Address: 0x1dc860, Func Offset: 0x350
	// Line 1573, Address: 0x1dc874, Func Offset: 0x364
	// Line 1574, Address: 0x1dc890, Func Offset: 0x380
	// Line 1576, Address: 0x1dc89c, Func Offset: 0x38c
	// Line 1578, Address: 0x1dc8c8, Func Offset: 0x3b8
	// Line 1582, Address: 0x1dc8e4, Func Offset: 0x3d4
	// Line 1584, Address: 0x1dc8f8, Func Offset: 0x3e8
	// Line 1585, Address: 0x1dc8fc, Func Offset: 0x3ec
	// Line 1586, Address: 0x1dc908, Func Offset: 0x3f8
	// Line 1584, Address: 0x1dc90c, Func Offset: 0x3fc
	// Line 1585, Address: 0x1dc910, Func Offset: 0x400
	// Line 1589, Address: 0x1dc914, Func Offset: 0x404
	// Line 1590, Address: 0x1dc918, Func Offset: 0x408
	// Line 1585, Address: 0x1dc91c, Func Offset: 0x40c
	// Line 1586, Address: 0x1dc920, Func Offset: 0x410
	// Line 1585, Address: 0x1dc924, Func Offset: 0x414
	// Line 1586, Address: 0x1dc92c, Func Offset: 0x41c
	// Line 1587, Address: 0x1dc934, Func Offset: 0x424
	// Line 1586, Address: 0x1dc938, Func Offset: 0x428
	// Line 1587, Address: 0x1dc940, Func Offset: 0x430
	// Line 1588, Address: 0x1dc948, Func Offset: 0x438
	// Line 1587, Address: 0x1dc94c, Func Offset: 0x43c
	// Line 1588, Address: 0x1dc954, Func Offset: 0x444
	// Line 1589, Address: 0x1dc95c, Func Offset: 0x44c
	// Line 1590, Address: 0x1dc968, Func Offset: 0x458
	// Line 1589, Address: 0x1dc96c, Func Offset: 0x45c
	// Line 1590, Address: 0x1dc974, Func Offset: 0x464
	// Line 1596, Address: 0x1dc97c, Func Offset: 0x46c
	// Line 1597, Address: 0x1dc990, Func Offset: 0x480
	// Line 1598, Address: 0x1dc9a4, Func Offset: 0x494
	// Line 1601, Address: 0x1dc9c4, Func Offset: 0x4b4
	// Line 1603, Address: 0x1dc9fc, Func Offset: 0x4ec
	// Line 1604, Address: 0x1dca08, Func Offset: 0x4f8
	// Line 1603, Address: 0x1dca0c, Func Offset: 0x4fc
	// Line 1604, Address: 0x1dca14, Func Offset: 0x504
	// Line 1605, Address: 0x1dca1c, Func Offset: 0x50c
	// Line 1604, Address: 0x1dca20, Func Offset: 0x510
	// Line 1605, Address: 0x1dca28, Func Offset: 0x518
	// Line 1607, Address: 0x1dca30, Func Offset: 0x520
	// Line 1605, Address: 0x1dca34, Func Offset: 0x524
	// Line 1607, Address: 0x1dca38, Func Offset: 0x528
	// Line 1608, Address: 0x1dca48, Func Offset: 0x538
	// Line 1609, Address: 0x1dca60, Func Offset: 0x550
	// Line 1610, Address: 0x1dca68, Func Offset: 0x558
	// Line 1612, Address: 0x1dca84, Func Offset: 0x574
	// Line 1613, Address: 0x1dca8c, Func Offset: 0x57c
	// Line 1614, Address: 0x1dca90, Func Offset: 0x580
	// Line 1615, Address: 0x1dca94, Func Offset: 0x584
	// Line 1618, Address: 0x1dca98, Func Offset: 0x588
	// Line 1612, Address: 0x1dca9c, Func Offset: 0x58c
	// Line 1613, Address: 0x1dcaa0, Func Offset: 0x590
	// Line 1621, Address: 0x1dcaa8, Func Offset: 0x598
	// Line 1613, Address: 0x1dcaac, Func Offset: 0x59c
	// Line 1614, Address: 0x1dcab0, Func Offset: 0x5a0
	// Line 1615, Address: 0x1dcabc, Func Offset: 0x5ac
	// Line 1616, Address: 0x1dcac8, Func Offset: 0x5b8
	// Line 1618, Address: 0x1dcad4, Func Offset: 0x5c4
	// Line 1616, Address: 0x1dcad8, Func Offset: 0x5c8
	// Line 1618, Address: 0x1dcae0, Func Offset: 0x5d0
	// Line 1621, Address: 0x1dcae4, Func Offset: 0x5d4
	// Line 1623, Address: 0x1dcaec, Func Offset: 0x5dc
	// Line 1625, Address: 0x1dcaf8, Func Offset: 0x5e8
	// Line 1627, Address: 0x1dcb00, Func Offset: 0x5f0
	// Line 1628, Address: 0x1dcb08, Func Offset: 0x5f8
	// Line 1630, Address: 0x1dcb3c, Func Offset: 0x62c
	// Line 1633, Address: 0x1dcb68, Func Offset: 0x658
	// Line 1634, Address: 0x1dcb7c, Func Offset: 0x66c
	// Line 1635, Address: 0x1dcba8, Func Offset: 0x698
	// Line 1634, Address: 0x1dcbac, Func Offset: 0x69c
	// Line 1635, Address: 0x1dcbb4, Func Offset: 0x6a4
	// Line 1638, Address: 0x1dcbc4, Func Offset: 0x6b4
	// Line 1639, Address: 0x1dcbd8, Func Offset: 0x6c8
	// Line 1640, Address: 0x1dcbe8, Func Offset: 0x6d8
	// Line 1641, Address: 0x1dcc00, Func Offset: 0x6f0
	// Line 1642, Address: 0x1dcc08, Func Offset: 0x6f8
	// Line 1644, Address: 0x1dcc24, Func Offset: 0x714
	// Line 1645, Address: 0x1dcc34, Func Offset: 0x724
	// Line 1644, Address: 0x1dcc38, Func Offset: 0x728
	// Line 1645, Address: 0x1dcc54, Func Offset: 0x744
	// Line 1647, Address: 0x1dcc60, Func Offset: 0x750
	// Line 1649, Address: 0x1dcc68, Func Offset: 0x758
	// Line 1650, Address: 0x1dcc78, Func Offset: 0x768
	// Line 1651, Address: 0x1dcc80, Func Offset: 0x770
	// Line 1650, Address: 0x1dcc84, Func Offset: 0x774
	// Line 1651, Address: 0x1dcc88, Func Offset: 0x778
	// Line 1652, Address: 0x1dcc94, Func Offset: 0x784
	// Line 1654, Address: 0x1dcca4, Func Offset: 0x794
	// Line 1656, Address: 0x1dccac, Func Offset: 0x79c
	// Line 1658, Address: 0x1dccbc, Func Offset: 0x7ac
	// Line 1664, Address: 0x1dccd0, Func Offset: 0x7c0
	// Line 1666, Address: 0x1dcce8, Func Offset: 0x7d8
	// Func End, Address: 0x1dccf4, Func Offset: 0x7e4
	scePrintf("bhEne13_PlayerControl - UNIMPLEMENTED!\n");
}
