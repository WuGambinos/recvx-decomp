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

// 100% matching!
void bhEne13_BR00(BH_PWORK* epw) 
{
    BH_PWORK* ep; 
    int i, j;        
    float dist;   
    
    if (epw->hp < 0)
    {
        return;
    }

    dist = njSqrt(((epw->px - plp->px) * (epw->px - plp->px)) + ((epw->pz - plp->pz) * (epw->pz - plp->pz)));

    if (EXP0_I(964) != 0)
    {
        EXP0_I(964)--;
    }

    if (EXP0_I(968) != 0)
    {
        EXP0_I(968)--;
    }

    if (EXP0_I(972) != 0)
    {
        EXP0_I(972)--;
    }

    if ((EXP0_I(972) == 0) && (dist > 40.0f))
    {
        epw->mode1 = 0;
        epw->mode2 = 2;
        epw->mode3 = 0;

        if (dist > 60.0f)
        {
            EXP0_I(972) = 10;
        }
        else
        {
            EXP0_I(972) = 45;
        }
        
        return;
    }

    if ((dist < 60.0f) && (EXP0_I(968) == 0) && ((((*(BH_PWORK**)&epw->exp0[8])->mode2  != 4) && ((*(BH_PWORK**)&epw->exp0[8])->mode2 != 5)) && (((*(BH_PWORK**)&epw->exp0[12])->mode2 != 4) && ((*(BH_PWORK**)&epw->exp0[12])->mode2 != 5)) && (((*(BH_PWORK**)&epw->exp0[16])->mode2 != 4) && ((*(BH_PWORK**)&epw->exp0[16])->mode2 != 5))))
    {
        j = bhEne13_SelectTentacle(epw);

        if ((*(BH_PWORK**)(&epw->exp0[8] + (4 * j)))->mode2 == 0)
        {
            EXP0_I(128) = j;

            if (njRandom() < 0.4f)
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
            }
            
            return;
        }
    }

    if (EXP0_I(964) == 0)
    {
        j = 3.0f * njRandom();

        EXP0_I(128) = -1;

        for (i = 0; i < 3; i++)
        {
            if ((*(BH_PWORK**)(&epw->exp0[8] + (4 * j)))->mode2 == 0)
            {
                EXP0_I(128) = j;
                break;
            }

            if (++j > 2)
            {
                j = 0;
            }
        }

        if (EXP0_I(128) != -1)
        {
            for (i = 0; i < EXP0_I(108); i++)
            {
                ep = *(BH_PWORK**)(&epw->exp0[44] + (4 * i));

                if ((ep->mode0 == 1) && (ep->mode2 == 0))
                {
                    epw->mode1 = 0;
                    epw->mode2 = 1;
                    epw->mode3 = 0;

                    EXP0_I(964) = 15;
                    break;
                }
            }
        }
    }
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

// 100% matching!
void bhEne13_Damage(BH_PWORK* epw)
{
    int dam;    
    int i;      
    int max_dam; 
    
    if ((((*(BH_PWORK**)&epw->exp0[20])->flg & 0x4)) || (((*(BH_PWORK**)&epw->exp0[24])->flg & 0x4)) || (((*(BH_PWORK**)&epw->exp0[28])->flg & 0x4)) || (((*(BH_PWORK**)&epw->exp0[32])->flg & 0x4)) || (((*(BH_PWORK**)&epw->exp0[36])->flg & 0x4)) || (((*(BH_PWORK**)&epw->exp0[40])->flg & 0x4)) || ((*(BH_PWORK**)&epw->exp0[112] != NULL) && ((*(BH_PWORK**)&epw->exp0[112])->type == 0) && (((*(BH_PWORK**)&epw->exp0[112])->flg & 0x4))))
    {
        max_dam = 0;

        for (i = 0; i < 6; i++)
        {
            if (((*(BH_PWORK**)(&epw->exp0[20] + (4 * i)))->flg & 0x4))
            {
                (*(BH_PWORK**)(&epw->exp0[20] + (4 * i)))->flg &= ~0x4;

                dam = bhEne18_HitMark(*(BH_PWORK**)(&epw->exp0[20] + (4 * i)));

                if (max_dam < dam)
                {
                    max_dam = dam;
                }
            }
        }

        if (((*(BH_PWORK**)&epw->exp0[112])->type == 0) && (((*(BH_PWORK**)&epw->exp0[112])->flg & 0x4)))
        {
            (*(BH_PWORK**)&epw->exp0[112])->flg &= ~0x4;

            dam = bhEne14_HitMark(*(BH_PWORK**)&epw->exp0[112]);

            if (max_dam < dam)
            {
                max_dam = dam;
            }
        }

        epw->hp -= max_dam;
    }

    bhEne13_DamageMode2[epw->mode2](epw);
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

// 100% matching!
void bhEne13_InitDamage(BH_PWORK* epw) 
{
    int dam, dam0, dam1, dam2, max_dam;    
    int i;      
    int wep_no;  
    int dflg, flg;   
    
    dam0 = dam1 = dam2 = max_dam = 0;

    for (i = 0; i < 6; i++)
    {
        if (((*(BH_PWORK**)(&epw->exp0[20] + (4 * i)))->flg & 0x4))
        {
            (*(BH_PWORK**)(&epw->exp0[20] + (4 * i)))->flg &= ~0x4;

            dam = bhEne18_HitMark(*(BH_PWORK**)(&epw->exp0[20] + (4 * i)));

            if (max_dam < dam)
            {
                max_dam = dam;

                wep_no = (*(BH_PWORK**)(&epw->exp0[20] + (4 * i)))->wpnr_no;
                
                dflg = (*(BH_PWORK**)(&epw->exp0[20] + (4 * i)))->flg2 & 0x4;
            }
        }
    }

    if (((*(BH_PWORK**)&epw->exp0[112])->type == 0) && (((*(BH_PWORK**)&epw->exp0[112])->flg & 0x4)))
    {
        (*(BH_PWORK**)&epw->exp0[112])->flg &= ~0x4;

        dam = bhEne14_HitMark(*(BH_PWORK**)&epw->exp0[112]);

        if (max_dam < dam)
        {
            max_dam = dam;

            wep_no = (*(BH_PWORK**)&epw->exp0[112])->wpnr_no;
            
            dflg = (*(BH_PWORK**)(&epw->exp0[20] + (4 * i)))->flg2 & 0x4;
        }
    }

    if ((max_dam != 0) || (dam0 != 0) || (dam1 != 0) || (dam2 != 0))
    {
        flg = 0;

        switch (wep_no) 
        {
        case 15:
        case 16:
        case 17:
            if (dflg == 0) 
            {
                break;
            }
        default:
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8961);
            break;
        }
        
        if (epw->hp > 600)
        {
            epw->hp -= max_dam;

            if (epw->hp < 600)
            {
                flg = 1;
            }
        }
        else if (epw->hp > 400)
        {
            epw->hp -= max_dam;

            if (epw->hp < 400)
            {
                flg = 1;
            }
        }
        else if (epw->hp > 200)
        {
            epw->hp -= max_dam;

            if (epw->hp < 200)
            {
                flg = 1;
            }
        }
        else
        {
            epw->hp -= max_dam;

            if (epw->hp < 0)
            {
                flg = 1;
            }
        }

        if (flg != 0)
        {
            epw->mode0 = 3;
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;

            if ((*(BH_PWORK**)&epw->exp0[112])->type == 0)
            {
                if (epw->hp < 0)
                {
                    (*(BH_PWORK**)&epw->exp0[112])->mode0 = 3;
                    (*(BH_PWORK**)&epw->exp0[112])->mode1 = 0;
                    (*(BH_PWORK**)&epw->exp0[112])->mode2 = 1;
                    (*(BH_PWORK**)&epw->exp0[112])->mode3 = 0;
                }
                else
                {
                    (*(BH_PWORK**)&epw->exp0[112])->mode0 = 3;
                    (*(BH_PWORK**)&epw->exp0[112])->mode1 = 0;
                    (*(BH_PWORK**)&epw->exp0[112])->mode2 = 0;
                    (*(BH_PWORK**)&epw->exp0[112])->mode3 = 0;
                }
            }
        }
    }
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
