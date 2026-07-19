#include "../../../ps2/veronica/prog/en13sub.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/subpl.h"

typedef void (*Mode0_proc)(BH_PWORK*);
typedef void (*MoveMode2_proc)(BH_PWORK*);

Mode0_proc bhEne13B_Mode0[6] =
{
    bhEne13B_Init,
    bhEne13B_Move,
    bhEne13B_Nage,
    bhEne13B_Damage,
    bhEne13B_Die,
    bhEne_Event
};

MoveMode2_proc bhEne13B_MoveMode2[2] =
{
    bhEne13B_MV00,
    bhEne13B_MV01
};
/*(*bhEne13B_BrainType)(BH_PWORK*)[1]; - unused*/

// 100% matching!
void bhEne13B(BH_PWORK* epw)
{
	int i;
    O_WORK* owk;

    bhEne13B_Mode0[epw->mode0](epw);

    if ((((BH_PWORK*)epw->lkwkp)->stflg & 0x1000000))
    {
        int i;

        epw->stflg |= 0x1000000;

        for (i = 0; i < epw->mlwP->obj_num; i++)
        {
            EXP0_ATR(i)->flg = 0;
        }
    }

	owk = epw->mlwP->owP;

    for (i = 0; i < epw->mlwP->obj_num; i++, owk++)
    {
        *EXP0_P3(i) = *(NJS_POINT3*)&owk->mtx[12];
    }

    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);

    bhCalcModel(epw);

    bhEne13B_SetHittab(epw);
}

// 100% matching!
void bhEne13B_Init(BH_PWORK* epw)
{
	int i;

    epw->flg |= 0x8018;
    epw->flg &= ~0x6;

    epw->flg2 |= 0x1;
    epw->flg2 |= 0x10;

    epw->mdflg |= 0x20;

    epw->ar = 5.0f;
    epw->ah = 1.0f;

    epw->car = 3.0f;

    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;

    epw->hokan_rate  = 65536;
    epw->hokan_count = 0;

    epw->mtn_no  = 4;
    epw->mtn_md  = 0;
    epw->mtn_add = 0;

    epw->frm_no = 0;

    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);

    bhCalcModel(epw);

    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(520, 8);

        for (i = 0; i < epw->mlwP->obj_num; i++)
        {
            EXP0_ATR(i) = &sys->mwalp[sys->mwal_n];

            sys->mwal_n++;

            EXP0_ATR(i)->flg = 0;

            EXP0_ATR(i)->type = 3;

            EXP0_ATR(i)->w = 2.0f;
            EXP0_ATR(i)->h = 1.0f;
            EXP0_ATR(i)->d = 0;

            EXP0_ATR(i)->attr = 0;

            EXP0_ATR(i)->px = epw->mlwP->owP->mtx[12];
            EXP0_ATR(i)->py = epw->mlwP->owP->mtx[13];
            EXP0_ATR(i)->pz = epw->mlwP->owP->mtx[14];
        }
    }
}

// 100% matching!
void bhEne13B_Move(BH_PWORK* epw)
{
	bhEne13B_MoveMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne13B_MV00()
{

}

/*// 
// Start address: 0x1dd080
void bhEne13B_MV01(BH_PWORK* epw)
{
	_anon22 p1;
	BH_PWORK** ep;
	int num;
	int j;
	int i;
	_anon4* owk;
	int mtn_no[6];
	// Line 289, Address: 0x1dd080, Func Offset: 0
	// Line 290, Address: 0x1dd09c, Func Offset: 0x1c
	// Line 289, Address: 0x1dd0a0, Func Offset: 0x20
	// Line 290, Address: 0x1dd0a8, Func Offset: 0x28
	// Line 298, Address: 0x1dd0b4, Func Offset: 0x34
	// Line 290, Address: 0x1dd0b8, Func Offset: 0x38
	// Line 298, Address: 0x1dd0c4, Func Offset: 0x44
	// Line 300, Address: 0x1dd0e0, Func Offset: 0x60
	// Line 305, Address: 0x1dd0e4, Func Offset: 0x64
	// Line 302, Address: 0x1dd0e8, Func Offset: 0x68
	// Line 305, Address: 0x1dd0ec, Func Offset: 0x6c
	// Line 308, Address: 0x1dd0f0, Func Offset: 0x70
	// Line 300, Address: 0x1dd0f4, Func Offset: 0x74
	// Line 301, Address: 0x1dd104, Func Offset: 0x84
	// Line 302, Address: 0x1dd108, Func Offset: 0x88
	// Line 303, Address: 0x1dd10c, Func Offset: 0x8c
	// Line 308, Address: 0x1dd110, Func Offset: 0x90
	// Line 304, Address: 0x1dd114, Func Offset: 0x94
	// Line 305, Address: 0x1dd118, Func Offset: 0x98
	// Line 308, Address: 0x1dd120, Func Offset: 0xa0
	// Line 310, Address: 0x1dd128, Func Offset: 0xa8
	// Line 311, Address: 0x1dd130, Func Offset: 0xb0
	// Line 314, Address: 0x1dd138, Func Offset: 0xb8
	// Line 317, Address: 0x1dd190, Func Offset: 0x110
	// Line 321, Address: 0x1dd1a4, Func Offset: 0x124
	// Line 323, Address: 0x1dd1c0, Func Offset: 0x140
	// Line 328, Address: 0x1dd218, Func Offset: 0x198
	// Line 331, Address: 0x1dd234, Func Offset: 0x1b4
	// Line 333, Address: 0x1dd264, Func Offset: 0x1e4
	// Line 334, Address: 0x1dd278, Func Offset: 0x1f8
	// Line 337, Address: 0x1dd288, Func Offset: 0x208
	// Line 339, Address: 0x1dd290, Func Offset: 0x210
	// Line 340, Address: 0x1dd2a4, Func Offset: 0x224
	// Line 343, Address: 0x1dd2b4, Func Offset: 0x234
	// Line 345, Address: 0x1dd2bc, Func Offset: 0x23c
	// Line 346, Address: 0x1dd2d0, Func Offset: 0x250
	// Line 349, Address: 0x1dd2e0, Func Offset: 0x260
	// Line 351, Address: 0x1dd2e8, Func Offset: 0x268
	// Line 352, Address: 0x1dd2f8, Func Offset: 0x278
	// Line 353, Address: 0x1dd308, Func Offset: 0x288
	// Line 355, Address: 0x1dd30c, Func Offset: 0x28c
	// Line 356, Address: 0x1dd31c, Func Offset: 0x29c
	// Line 357, Address: 0x1dd328, Func Offset: 0x2a8
	// Line 356, Address: 0x1dd32c, Func Offset: 0x2ac
	// Line 357, Address: 0x1dd334, Func Offset: 0x2b4
	// Line 359, Address: 0x1dd338, Func Offset: 0x2b8
	// Line 360, Address: 0x1dd348, Func Offset: 0x2c8
	// Line 363, Address: 0x1dd358, Func Offset: 0x2d8
	// Line 365, Address: 0x1dd360, Func Offset: 0x2e0
	// Line 366, Address: 0x1dd370, Func Offset: 0x2f0
	// Line 367, Address: 0x1dd380, Func Offset: 0x300
	// Line 369, Address: 0x1dd384, Func Offset: 0x304
	// Line 370, Address: 0x1dd394, Func Offset: 0x314
	// Line 371, Address: 0x1dd3a0, Func Offset: 0x320
	// Line 370, Address: 0x1dd3a4, Func Offset: 0x324
	// Line 371, Address: 0x1dd3ac, Func Offset: 0x32c
	// Line 373, Address: 0x1dd3b0, Func Offset: 0x330
	// Line 374, Address: 0x1dd3c0, Func Offset: 0x340
	// Line 377, Address: 0x1dd3d0, Func Offset: 0x350
	// Line 379, Address: 0x1dd3d8, Func Offset: 0x358
	// Line 380, Address: 0x1dd3e8, Func Offset: 0x368
	// Line 381, Address: 0x1dd3f8, Func Offset: 0x378
	// Line 383, Address: 0x1dd3fc, Func Offset: 0x37c
	// Line 384, Address: 0x1dd40c, Func Offset: 0x38c
	// Line 385, Address: 0x1dd418, Func Offset: 0x398
	// Line 384, Address: 0x1dd41c, Func Offset: 0x39c
	// Line 385, Address: 0x1dd424, Func Offset: 0x3a4
	// Line 387, Address: 0x1dd428, Func Offset: 0x3a8
	// Line 388, Address: 0x1dd438, Func Offset: 0x3b8
	// Line 389, Address: 0x1dd448, Func Offset: 0x3c8
	// Line 395, Address: 0x1dd44c, Func Offset: 0x3cc
	// Line 396, Address: 0x1dd458, Func Offset: 0x3d8
	// Line 397, Address: 0x1dd470, Func Offset: 0x3f0
	// Line 396, Address: 0x1dd474, Func Offset: 0x3f4
	// Line 397, Address: 0x1dd478, Func Offset: 0x3f8
	// Line 402, Address: 0x1dd498, Func Offset: 0x418
	// Line 403, Address: 0x1dd4d4, Func Offset: 0x454
	// Line 409, Address: 0x1dd4ec, Func Offset: 0x46c
	// Line 410, Address: 0x1dd4f0, Func Offset: 0x470
	// Line 411, Address: 0x1dd4f4, Func Offset: 0x474
	// Line 417, Address: 0x1dd4f8, Func Offset: 0x478
	// Line 409, Address: 0x1dd4fc, Func Offset: 0x47c
	// Line 422, Address: 0x1dd500, Func Offset: 0x480
	// Line 409, Address: 0x1dd504, Func Offset: 0x484
	// Line 410, Address: 0x1dd50c, Func Offset: 0x48c
	// Line 411, Address: 0x1dd51c, Func Offset: 0x49c
	// Line 417, Address: 0x1dd52c, Func Offset: 0x4ac
	// Line 414, Address: 0x1dd530, Func Offset: 0x4b0
	// Line 417, Address: 0x1dd534, Func Offset: 0x4b4
	// Line 414, Address: 0x1dd53c, Func Offset: 0x4bc
	// Line 417, Address: 0x1dd540, Func Offset: 0x4c0
	// Line 418, Address: 0x1dd544, Func Offset: 0x4c4
	// Line 414, Address: 0x1dd548, Func Offset: 0x4c8
	// Line 417, Address: 0x1dd54c, Func Offset: 0x4cc
	// Line 414, Address: 0x1dd550, Func Offset: 0x4d0
	// Line 415, Address: 0x1dd554, Func Offset: 0x4d4
	// Line 417, Address: 0x1dd558, Func Offset: 0x4d8
	// Line 418, Address: 0x1dd560, Func Offset: 0x4e0
	// Line 419, Address: 0x1dd570, Func Offset: 0x4f0
	// Line 418, Address: 0x1dd574, Func Offset: 0x4f4
	// Line 419, Address: 0x1dd57c, Func Offset: 0x4fc
	// Line 422, Address: 0x1dd58c, Func Offset: 0x50c
	// Line 419, Address: 0x1dd590, Func Offset: 0x510
	// Line 422, Address: 0x1dd598, Func Offset: 0x518
	// Line 424, Address: 0x1dd5f0, Func Offset: 0x570
	// Line 425, Address: 0x1dd600, Func Offset: 0x580
	// Line 424, Address: 0x1dd604, Func Offset: 0x584
	// Line 425, Address: 0x1dd60c, Func Offset: 0x58c
	// Line 426, Address: 0x1dd618, Func Offset: 0x598
	// Line 425, Address: 0x1dd61c, Func Offset: 0x59c
	// Line 426, Address: 0x1dd624, Func Offset: 0x5a4
	// Line 431, Address: 0x1dd638, Func Offset: 0x5b8
	// Line 432, Address: 0x1dd648, Func Offset: 0x5c8
	// Line 433, Address: 0x1dd658, Func Offset: 0x5d8
	// Line 434, Address: 0x1dd660, Func Offset: 0x5e0
	// Line 435, Address: 0x1dd674, Func Offset: 0x5f4
	// Line 438, Address: 0x1dd678, Func Offset: 0x5f8
	// Line 440, Address: 0x1dd68c, Func Offset: 0x60c
	// Line 441, Address: 0x1dd698, Func Offset: 0x618
	// Line 443, Address: 0x1dd6a0, Func Offset: 0x620
	// Line 440, Address: 0x1dd6a4, Func Offset: 0x624
	// Line 441, Address: 0x1dd6ac, Func Offset: 0x62c
	// Line 443, Address: 0x1dd6b4, Func Offset: 0x634
	// Line 441, Address: 0x1dd6b8, Func Offset: 0x638
	// Line 443, Address: 0x1dd6c0, Func Offset: 0x640
	// Line 444, Address: 0x1dd6c8, Func Offset: 0x648
	// Line 445, Address: 0x1dd6d4, Func Offset: 0x654
	// Line 446, Address: 0x1dd6e8, Func Offset: 0x668
	// Line 447, Address: 0x1dd70c, Func Offset: 0x68c
	// Line 446, Address: 0x1dd710, Func Offset: 0x690
	// Line 447, Address: 0x1dd714, Func Offset: 0x694
	// Line 448, Address: 0x1dd71c, Func Offset: 0x69c
	// Line 449, Address: 0x1dd724, Func Offset: 0x6a4
	// Line 450, Address: 0x1dd744, Func Offset: 0x6c4
	// Line 452, Address: 0x1dd750, Func Offset: 0x6d0
	// Line 453, Address: 0x1dd758, Func Offset: 0x6d8
	// Line 455, Address: 0x1dd760, Func Offset: 0x6e0
	// Line 456, Address: 0x1dd76c, Func Offset: 0x6ec
	// Line 458, Address: 0x1dd770, Func Offset: 0x6f0
	// Line 455, Address: 0x1dd774, Func Offset: 0x6f4
	// Line 456, Address: 0x1dd77c, Func Offset: 0x6fc
	// Line 458, Address: 0x1dd784, Func Offset: 0x704
	// Line 456, Address: 0x1dd788, Func Offset: 0x708
	// Line 458, Address: 0x1dd790, Func Offset: 0x710
	// Line 459, Address: 0x1dd798, Func Offset: 0x718
	// Line 460, Address: 0x1dd7a4, Func Offset: 0x724
	// Line 461, Address: 0x1dd7b8, Func Offset: 0x738
	// Line 462, Address: 0x1dd7dc, Func Offset: 0x75c
	// Line 461, Address: 0x1dd7e0, Func Offset: 0x760
	// Line 462, Address: 0x1dd7e4, Func Offset: 0x764
	// Line 463, Address: 0x1dd7ec, Func Offset: 0x76c
	// Line 464, Address: 0x1dd7f4, Func Offset: 0x774
	// Line 465, Address: 0x1dd814, Func Offset: 0x794
	// Line 467, Address: 0x1dd820, Func Offset: 0x7a0
	// Line 468, Address: 0x1dd82c, Func Offset: 0x7ac
	// Line 471, Address: 0x1dd830, Func Offset: 0x7b0
	// Line 474, Address: 0x1dd838, Func Offset: 0x7b8
	// Line 476, Address: 0x1dd83c, Func Offset: 0x7bc
	// Line 479, Address: 0x1dd840, Func Offset: 0x7c0
	// Line 480, Address: 0x1dd850, Func Offset: 0x7d0
	// Line 481, Address: 0x1dd858, Func Offset: 0x7d8
	// Line 482, Address: 0x1dd86c, Func Offset: 0x7ec
	// Line 483, Address: 0x1dd884, Func Offset: 0x804
	// Line 484, Address: 0x1dd888, Func Offset: 0x808
	// Line 483, Address: 0x1dd88c, Func Offset: 0x80c
	// Line 484, Address: 0x1dd898, Func Offset: 0x818
	// Line 487, Address: 0x1dd8a0, Func Offset: 0x820
	// Line 488, Address: 0x1dd8b8, Func Offset: 0x838
	// Line 487, Address: 0x1dd8bc, Func Offset: 0x83c
	// Line 488, Address: 0x1dd8c4, Func Offset: 0x844
	// Line 489, Address: 0x1dd8cc, Func Offset: 0x84c
	// Line 491, Address: 0x1dd8d0, Func Offset: 0x850
	// Line 492, Address: 0x1dd8dc, Func Offset: 0x85c
	// Line 493, Address: 0x1dd8e0, Func Offset: 0x860
	// Line 494, Address: 0x1dd8e4, Func Offset: 0x864
	// Line 495, Address: 0x1dd8e8, Func Offset: 0x868
	// Line 498, Address: 0x1dd8ec, Func Offset: 0x86c
	// Func End, Address: 0x1dd914, Func Offset: 0x894
}*/

// 100% matching!
void bhEne13B_Nage()
{

}

// 100% matching!
void bhEne13B_Damage()
{

}

// 100% matching!
void bhEne13B_Die(BH_PWORK* epw)
{
	int i;

    epw->stflg |= 0x1000000;
    epw->flg   |= 0x2;

    for (i = 0; i < epw->mlwP->obj_num; i++)
    {
        EXP0_ATR(i)->flg = 0;
    }

    epw->flg &= ~0x80000;
}

// 100% matching!
void bhEne13B_SetHittab(BH_PWORK* epw)
{
	int i;
    O_WORK* owk;

    if ((epw->flg & 0x80000))
    {
        EXP0_I(516)++;

        if (EXP0_I(516) > 15)
        {
            EXP0_I(516) = 15;
        }

        owk = epw->mlwP->owP;

        for (i = 0; i < EXP0_I(516); i++, owk++)
        {
            EXP0_ATR(i)->flg = 1;

            EXP0_ATR(i)->px = owk->mtx[12];
            EXP0_ATR(i)->py = owk->mtx[13];
            EXP0_ATR(i)->pz = owk->mtx[14];
        }
    }
    else
    {
        for (i = 0; i < epw->mlwP->obj_num; i++)
        {
            EXP0_ATR(i)->flg = 0;
        }

        EXP0_I(516) = 0;
    }
}
