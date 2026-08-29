#include "../../../ps2/veronica/prog/en01b.h"
#include "../../../ps2/veronica/prog/en01.h"
#include "../../../ps2/veronica/prog/zonzon.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/rutchk.h"
#include "../../../ps2/veronica/prog/main.h"

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

// 
// Start address: 0x18abc0
void bhEne01_DG05B(BH_PWORK* epw)
{
	int frm;
	NJS_POINT3 ps;
	O_WORK* owk;
	BH_PWORK* epp;
	// Line 663, Address: 0x18abc0, Func Offset: 0
	// Line 670, Address: 0x18abd4, Func Offset: 0x14
	// Line 664, Address: 0x18abd8, Func Offset: 0x18
	// Line 670, Address: 0x18abdc, Func Offset: 0x1c
	// Line 673, Address: 0x18ac04, Func Offset: 0x44
	// Line 677, Address: 0x18ac18, Func Offset: 0x58
	// Line 673, Address: 0x18ac1c, Func Offset: 0x5c
	// Line 677, Address: 0x18ac20, Func Offset: 0x60
	// Line 673, Address: 0x18ac28, Func Offset: 0x68
	// Line 677, Address: 0x18ac30, Func Offset: 0x70
	// Line 673, Address: 0x18ac40, Func Offset: 0x80
	// Line 677, Address: 0x18ac44, Func Offset: 0x84
	// Line 678, Address: 0x18ac4c, Func Offset: 0x8c
	// Line 681, Address: 0x18ac6c, Func Offset: 0xac
	// Line 682, Address: 0x18ac74, Func Offset: 0xb4
	// Line 691, Address: 0x18ac78, Func Offset: 0xb8
	// Line 681, Address: 0x18ac7c, Func Offset: 0xbc
	// Line 682, Address: 0x18ac84, Func Offset: 0xc4
	// Line 693, Address: 0x18ac88, Func Offset: 0xc8
	// Line 682, Address: 0x18ac8c, Func Offset: 0xcc
	// Line 683, Address: 0x18ac94, Func Offset: 0xd4
	// Line 685, Address: 0x18aca0, Func Offset: 0xe0
	// Line 686, Address: 0x18aca8, Func Offset: 0xe8
	// Line 687, Address: 0x18acb0, Func Offset: 0xf0
	// Line 688, Address: 0x18acb8, Func Offset: 0xf8
	// Line 689, Address: 0x18acc0, Func Offset: 0x100
	// Line 691, Address: 0x18acc8, Func Offset: 0x108
	// Line 692, Address: 0x18acd0, Func Offset: 0x110
	// Line 693, Address: 0x18acdc, Func Offset: 0x11c
	// Line 694, Address: 0x18acec, Func Offset: 0x12c
	// Line 695, Address: 0x18acfc, Func Offset: 0x13c
	// Line 698, Address: 0x18ad08, Func Offset: 0x148
	// Line 701, Address: 0x18ad0c, Func Offset: 0x14c
	// Line 698, Address: 0x18ad10, Func Offset: 0x150
	// Line 701, Address: 0x18ad14, Func Offset: 0x154
	// Line 704, Address: 0x18ad28, Func Offset: 0x168
	// Line 707, Address: 0x18ad40, Func Offset: 0x180
	// Line 709, Address: 0x18ad68, Func Offset: 0x1a8
	// Line 712, Address: 0x18ad88, Func Offset: 0x1c8
	// Line 713, Address: 0x18ad8c, Func Offset: 0x1cc
	// Line 709, Address: 0x18ad90, Func Offset: 0x1d0
	// Line 713, Address: 0x18ada0, Func Offset: 0x1e0
	// Line 709, Address: 0x18adac, Func Offset: 0x1ec
	// Line 710, Address: 0x18adc0, Func Offset: 0x200
	// Line 711, Address: 0x18adc4, Func Offset: 0x204
	// Line 713, Address: 0x18adc8, Func Offset: 0x208
	// Line 714, Address: 0x18add0, Func Offset: 0x210
	// Line 715, Address: 0x18add4, Func Offset: 0x214
	// Line 714, Address: 0x18add8, Func Offset: 0x218
	// Line 715, Address: 0x18addc, Func Offset: 0x21c
	// Line 718, Address: 0x18ade8, Func Offset: 0x228
	// Line 720, Address: 0x18ae10, Func Offset: 0x250
	// Line 724, Address: 0x18ae14, Func Offset: 0x254
	// Line 720, Address: 0x18ae24, Func Offset: 0x264
	// Line 721, Address: 0x18ae28, Func Offset: 0x268
	// Line 722, Address: 0x18ae30, Func Offset: 0x270
	// Line 724, Address: 0x18ae34, Func Offset: 0x274
	// Line 725, Address: 0x18ae48, Func Offset: 0x288
	// Line 724, Address: 0x18ae4c, Func Offset: 0x28c
	// Line 725, Address: 0x18ae58, Func Offset: 0x298
	// Line 726, Address: 0x18ae5c, Func Offset: 0x29c
	// Line 728, Address: 0x18ae64, Func Offset: 0x2a4
	// Line 731, Address: 0x18ae6c, Func Offset: 0x2ac
	// Line 733, Address: 0x18ae7c, Func Offset: 0x2bc
	// Line 735, Address: 0x18ae88, Func Offset: 0x2c8
	// Line 736, Address: 0x18ae90, Func Offset: 0x2d0
	// Line 737, Address: 0x18ae94, Func Offset: 0x2d4
	// Line 739, Address: 0x18ae98, Func Offset: 0x2d8
	// Line 742, Address: 0x18aea0, Func Offset: 0x2e0
	// Line 743, Address: 0x18aea8, Func Offset: 0x2e8
	// Line 744, Address: 0x18aeac, Func Offset: 0x2ec
	// Line 745, Address: 0x18aeb4, Func Offset: 0x2f4
	// Line 746, Address: 0x18aeb8, Func Offset: 0x2f8
	// Line 748, Address: 0x18aebc, Func Offset: 0x2fc
	// Line 749, Address: 0x18aed0, Func Offset: 0x310
	// Line 752, Address: 0x18aee0, Func Offset: 0x320
	// Line 757, Address: 0x18aeec, Func Offset: 0x32c
	// Func End, Address: 0x18af04, Func Offset: 0x344
	scePrintf("bhEne01_DG05B - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x18af10
void bhEne01_DG09B(BH_PWORK* epw)
{
	NJS_POINT3 ps = { 0 };
	int frm;
	//NJS_POINT3 ps;
	O_WORK* owk;
	BH_PWORK* epp;
	// Line 777, Address: 0x18af10, Func Offset: 0
	// Line 784, Address: 0x18af24, Func Offset: 0x14
	// Line 778, Address: 0x18af28, Func Offset: 0x18
	// Line 784, Address: 0x18af2c, Func Offset: 0x1c
	// Line 791, Address: 0x18af54, Func Offset: 0x44
	// Line 792, Address: 0x18af70, Func Offset: 0x60
	// Line 795, Address: 0x18af90, Func Offset: 0x80
	// Line 796, Address: 0x18af98, Func Offset: 0x88
	// Line 804, Address: 0x18af9c, Func Offset: 0x8c
	// Line 795, Address: 0x18afa0, Func Offset: 0x90
	// Line 796, Address: 0x18afa8, Func Offset: 0x98
	// Line 806, Address: 0x18afac, Func Offset: 0x9c
	// Line 810, Address: 0x18afb0, Func Offset: 0xa0
	// Line 812, Address: 0x18afb4, Func Offset: 0xa4
	// Line 796, Address: 0x18afb8, Func Offset: 0xa8
	// Line 797, Address: 0x18afc0, Func Offset: 0xb0
	// Line 813, Address: 0x18afc4, Func Offset: 0xb4
	// Line 797, Address: 0x18afd0, Func Offset: 0xc0
	// Line 799, Address: 0x18afd8, Func Offset: 0xc8
	// Line 813, Address: 0x18afdc, Func Offset: 0xcc
	// Line 799, Address: 0x18afe0, Func Offset: 0xd0
	// Line 800, Address: 0x18afe4, Func Offset: 0xd4
	// Line 801, Address: 0x18afec, Func Offset: 0xdc
	// Line 802, Address: 0x18aff4, Func Offset: 0xe4
	// Line 804, Address: 0x18affc, Func Offset: 0xec
	// Line 805, Address: 0x18b004, Func Offset: 0xf4
	// Line 806, Address: 0x18b010, Func Offset: 0x100
	// Line 807, Address: 0x18b020, Func Offset: 0x110
	// Line 809, Address: 0x18b030, Func Offset: 0x120
	// Line 810, Address: 0x18b034, Func Offset: 0x124
	// Line 811, Address: 0x18b038, Func Offset: 0x128
	// Line 813, Address: 0x18b03c, Func Offset: 0x12c
	// Line 814, Address: 0x18b044, Func Offset: 0x134
	// Line 817, Address: 0x18b050, Func Offset: 0x140
	// Line 819, Address: 0x18b054, Func Offset: 0x144
	// Line 817, Address: 0x18b058, Func Offset: 0x148
	// Line 819, Address: 0x18b05c, Func Offset: 0x14c
	// Line 821, Address: 0x18b064, Func Offset: 0x154
	// Line 823, Address: 0x18b080, Func Offset: 0x170
	// Line 824, Address: 0x18b08c, Func Offset: 0x17c
	// Line 825, Address: 0x18b09c, Func Offset: 0x18c
	// Line 826, Address: 0x18b0a8, Func Offset: 0x198
	// Line 825, Address: 0x18b0ac, Func Offset: 0x19c
	// Line 826, Address: 0x18b0b0, Func Offset: 0x1a0
	// Line 827, Address: 0x18b0b4, Func Offset: 0x1a4
	// Line 828, Address: 0x18b0d0, Func Offset: 0x1c0
	// Line 831, Address: 0x18b0ec, Func Offset: 0x1dc
	// Line 836, Address: 0x18b150, Func Offset: 0x240
	// Line 838, Address: 0x18b170, Func Offset: 0x260
	// Line 841, Address: 0x18b190, Func Offset: 0x280
	// Line 842, Address: 0x18b194, Func Offset: 0x284
	// Line 838, Address: 0x18b198, Func Offset: 0x288
	// Line 842, Address: 0x18b1a8, Func Offset: 0x298
	// Line 838, Address: 0x18b1b4, Func Offset: 0x2a4
	// Line 839, Address: 0x18b1c8, Func Offset: 0x2b8
	// Line 840, Address: 0x18b1cc, Func Offset: 0x2bc
	// Line 842, Address: 0x18b1d0, Func Offset: 0x2c0
	// Line 843, Address: 0x18b1d8, Func Offset: 0x2c8
	// Line 844, Address: 0x18b1dc, Func Offset: 0x2cc
	// Line 843, Address: 0x18b1e0, Func Offset: 0x2d0
	// Line 844, Address: 0x18b1e4, Func Offset: 0x2d4
	// Line 846, Address: 0x18b1f0, Func Offset: 0x2e0
	// Line 849, Address: 0x18b1f8, Func Offset: 0x2e8
	// Line 851, Address: 0x18b214, Func Offset: 0x304
	// Line 854, Address: 0x18b234, Func Offset: 0x324
	// Line 855, Address: 0x18b238, Func Offset: 0x328
	// Line 851, Address: 0x18b23c, Func Offset: 0x32c
	// Line 855, Address: 0x18b24c, Func Offset: 0x33c
	// Line 851, Address: 0x18b258, Func Offset: 0x348
	// Line 852, Address: 0x18b26c, Func Offset: 0x35c
	// Line 853, Address: 0x18b270, Func Offset: 0x360
	// Line 855, Address: 0x18b274, Func Offset: 0x364
	// Line 856, Address: 0x18b27c, Func Offset: 0x36c
	// Line 857, Address: 0x18b280, Func Offset: 0x370
	// Line 856, Address: 0x18b284, Func Offset: 0x374
	// Line 857, Address: 0x18b288, Func Offset: 0x378
	// Line 864, Address: 0x18b298, Func Offset: 0x388
	// Line 866, Address: 0x18b2c0, Func Offset: 0x3b0
	// Line 870, Address: 0x18b2c4, Func Offset: 0x3b4
	// Line 866, Address: 0x18b2c8, Func Offset: 0x3b8
	// Line 867, Address: 0x18b2cc, Func Offset: 0x3bc
	// Line 868, Address: 0x18b2d4, Func Offset: 0x3c4
	// Line 870, Address: 0x18b2dc, Func Offset: 0x3cc
	// Line 872, Address: 0x18b2e8, Func Offset: 0x3d8
	// Line 873, Address: 0x18b308, Func Offset: 0x3f8
	// Line 872, Address: 0x18b30c, Func Offset: 0x3fc
	// Line 874, Address: 0x18b318, Func Offset: 0x408
	// Line 877, Address: 0x18b320, Func Offset: 0x410
	// Line 879, Address: 0x18b34c, Func Offset: 0x43c
	// Line 880, Address: 0x18b354, Func Offset: 0x444
	// Line 882, Address: 0x18b35c, Func Offset: 0x44c
	// Line 885, Address: 0x18b364, Func Offset: 0x454
	// Line 887, Address: 0x18b374, Func Offset: 0x464
	// Line 889, Address: 0x18b380, Func Offset: 0x470
	// Line 890, Address: 0x18b388, Func Offset: 0x478
	// Line 891, Address: 0x18b38c, Func Offset: 0x47c
	// Line 893, Address: 0x18b390, Func Offset: 0x480
	// Line 896, Address: 0x18b398, Func Offset: 0x488
	// Line 897, Address: 0x18b3a0, Func Offset: 0x490
	// Line 898, Address: 0x18b3a4, Func Offset: 0x494
	// Line 899, Address: 0x18b3ac, Func Offset: 0x49c
	// Line 900, Address: 0x18b3b0, Func Offset: 0x4a0
	// Line 902, Address: 0x18b3b4, Func Offset: 0x4a4
	// Line 903, Address: 0x18b3c8, Func Offset: 0x4b8
	// Line 906, Address: 0x18b3d8, Func Offset: 0x4c8
	// Line 911, Address: 0x18b3e4, Func Offset: 0x4d4
	// Func End, Address: 0x18b3fc, Func Offset: 0x4ec
	scePrintf("bhEne01_DG09B - UNIMPLEMENTED!\n");
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

// 
// Start address: 0x18b630
void bhEne01_DD02B(BH_PWORK* epw)
{
	NJS_LINE line;
	NJS_POINT3 pd;
	NJS_POINT3 ps;
	O_WORK* owk;
	// Line 1034, Address: 0x18b630, Func Offset: 0
	// Line 1039, Address: 0x18b640, Func Offset: 0x10
	// Line 1042, Address: 0x18b684, Func Offset: 0x54
	// Line 1043, Address: 0x18b688, Func Offset: 0x58
	// Line 1047, Address: 0x18b68c, Func Offset: 0x5c
	// Line 1042, Address: 0x18b690, Func Offset: 0x60
	// Line 1043, Address: 0x18b698, Func Offset: 0x68
	// Line 1047, Address: 0x18b6a4, Func Offset: 0x74
	// Line 1049, Address: 0x18b6b4, Func Offset: 0x84
	// Line 1052, Address: 0x18b6b8, Func Offset: 0x88
	// Line 1053, Address: 0x18b6bc, Func Offset: 0x8c
	// Line 1049, Address: 0x18b6c4, Func Offset: 0x94
	// Line 1050, Address: 0x18b6cc, Func Offset: 0x9c
	// Line 1051, Address: 0x18b6d0, Func Offset: 0xa0
	// Line 1053, Address: 0x18b6d4, Func Offset: 0xa4
	// Line 1054, Address: 0x18b6e0, Func Offset: 0xb0
	// Line 1055, Address: 0x18b6e4, Func Offset: 0xb4
	// Line 1054, Address: 0x18b6f0, Func Offset: 0xc0
	// Line 1055, Address: 0x18b6f4, Func Offset: 0xc4
	// Line 1059, Address: 0x18b704, Func Offset: 0xd4
	// Line 1061, Address: 0x18b72c, Func Offset: 0xfc
	// Line 1065, Address: 0x18b730, Func Offset: 0x100
	// Line 1069, Address: 0x18b738, Func Offset: 0x108
	// Line 1061, Address: 0x18b740, Func Offset: 0x110
	// Line 1062, Address: 0x18b744, Func Offset: 0x114
	// Line 1063, Address: 0x18b74c, Func Offset: 0x11c
	// Line 1064, Address: 0x18b754, Func Offset: 0x124
	// Line 1065, Address: 0x18b758, Func Offset: 0x128
	// Line 1069, Address: 0x18b75c, Func Offset: 0x12c
	// Line 1070, Address: 0x18b764, Func Offset: 0x134
	// Line 1072, Address: 0x18b774, Func Offset: 0x144
	// Line 1073, Address: 0x18b78c, Func Offset: 0x15c
	// Line 1074, Address: 0x18b790, Func Offset: 0x160
	// Line 1075, Address: 0x18b7ac, Func Offset: 0x17c
	// Line 1074, Address: 0x18b7b0, Func Offset: 0x180
	// Line 1076, Address: 0x18b7b8, Func Offset: 0x188
	// Line 1078, Address: 0x18b7c0, Func Offset: 0x190
	// Line 1081, Address: 0x18b7c8, Func Offset: 0x198
	// Line 1084, Address: 0x18b7d0, Func Offset: 0x1a0
	// Line 1086, Address: 0x18b7e0, Func Offset: 0x1b0
	// Line 1087, Address: 0x18b7e8, Func Offset: 0x1b8
	// Line 1088, Address: 0x18b7ec, Func Offset: 0x1bc
	// Line 1090, Address: 0x18b7f4, Func Offset: 0x1c4
	// Line 1093, Address: 0x18b7fc, Func Offset: 0x1cc
	// Line 1094, Address: 0x18b838, Func Offset: 0x208
	// Line 1096, Address: 0x18b844, Func Offset: 0x214
	// Line 1098, Address: 0x18b85c, Func Offset: 0x22c
	// Line 1099, Address: 0x18b89c, Func Offset: 0x26c
	// Line 1100, Address: 0x18b8a0, Func Offset: 0x270
	// Line 1101, Address: 0x18b8a8, Func Offset: 0x278
	// Line 1103, Address: 0x18b8b0, Func Offset: 0x280
	// Line 1106, Address: 0x18b8b8, Func Offset: 0x288
	// Line 1107, Address: 0x18b90c, Func Offset: 0x2dc
	// Line 1109, Address: 0x18b918, Func Offset: 0x2e8
	// Line 1111, Address: 0x18b930, Func Offset: 0x300
	// Line 1113, Address: 0x18b984, Func Offset: 0x354
	// Line 1114, Address: 0x18b9c8, Func Offset: 0x398
	// Line 1115, Address: 0x18b9cc, Func Offset: 0x39c
	// Line 1119, Address: 0x18b9d4, Func Offset: 0x3a4
	// Func End, Address: 0x18b9e8, Func Offset: 0x3b8
	scePrintf("bhEne01_DD02B - UNIMPLEMENTED!\n");
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
