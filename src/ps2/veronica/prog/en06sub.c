#include "../../../ps2/veronica/prog/en06sub.h"
#include "../../../ps2/veronica/prog/en03.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"

typedef void (*Mode0_proc)(BH_PWORK*);
typedef void (*MoveMode2_proc)(BH_PWORK*);

Mode0_proc bhEne06s_Mode0[3] =
{
    bhEne06s_Init,
    bhEne06s_Move,
    bhEne06s_Dummy
};
MoveMode2_proc bhEne06s_MoveMode2[2] =
{
    bhEne06s_MV00,
    bhEne06s_MV01
};

static NJS_POINT3 CollisionOffset[4][3] =
{
    { { 0.0f, 0.0f, 0.0f }, {  5.0f, -0.5f, -2.5f }, {  3.5f, -0.5f, 1.5f } },
    { { 0.0f, 0.0f, 0.0f }, { -5.0f, -0.5f, -2.5f }, { -3.5f, -0.5f, 1.5f } },
    { { 0.0f, 0.0f, 0.0f }, {  3.0f, -0.5f,  2.0f }, {  0.5f, -0.3f, 5.0f } },
    { { 0.0f, 0.0f, 0.0f }, { -3.0f, -0.5f,  2.0f }, { -0.5f, -0.3f, 5.0f } }
};

// 100% matching!
void bhEne06s(BH_PWORK* epw)
{
    bhEne06s_Mode0[epw->mode0](epw);

    if ((epw->flg & 0x10))
    {
        if (epw->lkono < 4)
        {
            bhEne06s_WallCheck(epw);
        }
        else
        {
            bhEne06s_FloorCollision(epw);
            bhEne03_Collision(epw);
        }
    }
}

// 100% matching!
void bhEne06s_Init(BH_PWORK* epw)
{
    epw->flg &= ~0x10;

    epw->ar = 0.5f;
    epw->ah = 0.3f;

    epw->car = 0.5f;
    epw->cah = 0.3f;

    epw->mode0 = 2;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;

    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(68, 8);
    }
}

// 100% matching!
void bhEne06s_Move(BH_PWORK* epw)
{
    bhEne06s_MoveMode2[epw->mode2](epw);
}

// 
// Start address: 0x1bf3e0
void bhEne06s_MV00(BH_PWORK* epw)
{
	int ang;
	float out;
	//_anon8 ov;
	//_anon8 vd;
	//_anon8 v;
	// Line 172, Address: 0x1bf3e0, Func Offset: 0
	// Line 173, Address: 0x1bf3f8, Func Offset: 0x18
	// Line 175, Address: 0x1bf424, Func Offset: 0x44
	// Line 176, Address: 0x1bf434, Func Offset: 0x54
	// Line 177, Address: 0x1bf444, Func Offset: 0x64
	// Line 180, Address: 0x1bf450, Func Offset: 0x70
	// Line 181, Address: 0x1bf488, Func Offset: 0xa8
	// Line 182, Address: 0x1bf4c4, Func Offset: 0xe4
	// Line 187, Address: 0x1bf4e4, Func Offset: 0x104
	// Line 182, Address: 0x1bf4e8, Func Offset: 0x108
	// Line 184, Address: 0x1bf500, Func Offset: 0x120
	// Line 186, Address: 0x1bf510, Func Offset: 0x130
	// Line 187, Address: 0x1bf51c, Func Offset: 0x13c
	// Line 188, Address: 0x1bf520, Func Offset: 0x140
	// Line 190, Address: 0x1bf52c, Func Offset: 0x14c
	// Line 191, Address: 0x1bf540, Func Offset: 0x160
	// Line 192, Address: 0x1bf55c, Func Offset: 0x17c
	// Line 193, Address: 0x1bf570, Func Offset: 0x190
	// Line 194, Address: 0x1bf584, Func Offset: 0x1a4
	// Line 195, Address: 0x1bf594, Func Offset: 0x1b4
	// Line 196, Address: 0x1bf59c, Func Offset: 0x1bc
	// Line 199, Address: 0x1bf5a8, Func Offset: 0x1c8
	// Line 200, Address: 0x1bf5b4, Func Offset: 0x1d4
	// Line 201, Address: 0x1bf5c0, Func Offset: 0x1e0
	// Line 202, Address: 0x1bf5c8, Func Offset: 0x1e8
	// Line 205, Address: 0x1bf5d0, Func Offset: 0x1f0
	// Line 210, Address: 0x1bf5dc, Func Offset: 0x1fc
	// Line 213, Address: 0x1bf5e0, Func Offset: 0x200
	// Line 210, Address: 0x1bf5e4, Func Offset: 0x204
	// Line 211, Address: 0x1bf5ec, Func Offset: 0x20c
	// Line 212, Address: 0x1bf5f8, Func Offset: 0x218
	// Line 213, Address: 0x1bf604, Func Offset: 0x224
	// Line 214, Address: 0x1bf610, Func Offset: 0x230
	// Line 215, Address: 0x1bf62c, Func Offset: 0x24c
	// Line 216, Address: 0x1bf644, Func Offset: 0x264
	// Line 217, Address: 0x1bf650, Func Offset: 0x270
	// Line 219, Address: 0x1bf65c, Func Offset: 0x27c
	// Line 220, Address: 0x1bf66c, Func Offset: 0x28c
	// Line 223, Address: 0x1bf678, Func Offset: 0x298
	// Line 224, Address: 0x1bf680, Func Offset: 0x2a0
	// Line 225, Address: 0x1bf6a0, Func Offset: 0x2c0
	// Line 226, Address: 0x1bf6c0, Func Offset: 0x2e0
	// Line 227, Address: 0x1bf6cc, Func Offset: 0x2ec
	// Line 228, Address: 0x1bf6d4, Func Offset: 0x2f4
	// Line 229, Address: 0x1bf6e0, Func Offset: 0x300
	// Line 230, Address: 0x1bf6e8, Func Offset: 0x308
	// Line 229, Address: 0x1bf6ec, Func Offset: 0x30c
	// Line 230, Address: 0x1bf6f4, Func Offset: 0x314
	// Line 232, Address: 0x1bf6f8, Func Offset: 0x318
	// Line 234, Address: 0x1bf704, Func Offset: 0x324
	// Line 235, Address: 0x1bf710, Func Offset: 0x330
	// Line 236, Address: 0x1bf71c, Func Offset: 0x33c
	// Line 238, Address: 0x1bf728, Func Offset: 0x348
	// Func End, Address: 0x1bf740, Func Offset: 0x360
}

// 
// Start address: 0x1bf740
void bhEne06s_MV01(BH_PWORK* epw)
{
	int ang;
	float out;
	//_anon8 ov;
	//_anon8 vd;
	//_anon8 avec;
	// Line 248, Address: 0x1bf740, Func Offset: 0
	// Line 251, Address: 0x1bf754, Func Offset: 0x14
	// Line 253, Address: 0x1bf784, Func Offset: 0x44
	// Line 254, Address: 0x1bf794, Func Offset: 0x54
	// Line 255, Address: 0x1bf7a4, Func Offset: 0x64
	// Line 258, Address: 0x1bf7b0, Func Offset: 0x70
	// Line 259, Address: 0x1bf7e8, Func Offset: 0xa8
	// Line 260, Address: 0x1bf824, Func Offset: 0xe4
	// Line 266, Address: 0x1bf840, Func Offset: 0x100
	// Line 260, Address: 0x1bf844, Func Offset: 0x104
	// Line 266, Address: 0x1bf848, Func Offset: 0x108
	// Line 260, Address: 0x1bf84c, Func Offset: 0x10c
	// Line 266, Address: 0x1bf85c, Func Offset: 0x11c
	// Line 260, Address: 0x1bf860, Func Offset: 0x120
	// Line 262, Address: 0x1bf868, Func Offset: 0x128
	// Line 263, Address: 0x1bf878, Func Offset: 0x138
	// Line 266, Address: 0x1bf884, Func Offset: 0x144
	// Line 268, Address: 0x1bf8a8, Func Offset: 0x168
	// Line 270, Address: 0x1bf8b4, Func Offset: 0x174
	// Line 272, Address: 0x1bf8c8, Func Offset: 0x188
	// Line 271, Address: 0x1bf8cc, Func Offset: 0x18c
	// Line 274, Address: 0x1bf8d0, Func Offset: 0x190
	// Line 272, Address: 0x1bf8d4, Func Offset: 0x194
	// Line 274, Address: 0x1bf8d8, Func Offset: 0x198
	// Line 275, Address: 0x1bf8e0, Func Offset: 0x1a0
	// Line 276, Address: 0x1bf8f0, Func Offset: 0x1b0
	// Line 277, Address: 0x1bf90c, Func Offset: 0x1cc
	// Line 280, Address: 0x1bf920, Func Offset: 0x1e0
	// Line 281, Address: 0x1bf92c, Func Offset: 0x1ec
	// Line 282, Address: 0x1bf938, Func Offset: 0x1f8
	// Line 284, Address: 0x1bf944, Func Offset: 0x204
	// Line 286, Address: 0x1bf968, Func Offset: 0x228
	// Line 287, Address: 0x1bf97c, Func Offset: 0x23c
	// Line 288, Address: 0x1bf990, Func Offset: 0x250
	// Line 289, Address: 0x1bf9a0, Func Offset: 0x260
	// Line 290, Address: 0x1bf9a8, Func Offset: 0x268
	// Line 291, Address: 0x1bf9ac, Func Offset: 0x26c
	// Line 290, Address: 0x1bf9b0, Func Offset: 0x270
	// Line 291, Address: 0x1bf9b8, Func Offset: 0x278
	// Line 294, Address: 0x1bf9bc, Func Offset: 0x27c
	// Line 295, Address: 0x1bf9c8, Func Offset: 0x288
	// Line 296, Address: 0x1bf9d4, Func Offset: 0x294
	// Line 297, Address: 0x1bf9dc, Func Offset: 0x29c
	// Line 301, Address: 0x1bf9e4, Func Offset: 0x2a4
	// Line 306, Address: 0x1bf9f0, Func Offset: 0x2b0
	// Line 307, Address: 0x1bfa14, Func Offset: 0x2d4
	// Line 308, Address: 0x1bfa24, Func Offset: 0x2e4
	// Line 309, Address: 0x1bfa40, Func Offset: 0x300
	// Line 310, Address: 0x1bfa58, Func Offset: 0x318
	// Line 311, Address: 0x1bfa64, Func Offset: 0x324
	// Line 313, Address: 0x1bfa70, Func Offset: 0x330
	// Line 314, Address: 0x1bfa7c, Func Offset: 0x33c
	// Line 315, Address: 0x1bfa90, Func Offset: 0x350
	// Line 318, Address: 0x1bfa9c, Func Offset: 0x35c
	// Line 319, Address: 0x1bfac4, Func Offset: 0x384
	// Line 320, Address: 0x1bfae4, Func Offset: 0x3a4
	// Line 321, Address: 0x1bfaec, Func Offset: 0x3ac
	// Line 322, Address: 0x1bfb0c, Func Offset: 0x3cc
	// Line 323, Address: 0x1bfb18, Func Offset: 0x3d8
	// Line 324, Address: 0x1bfb20, Func Offset: 0x3e0
	// Line 331, Address: 0x1bfb48, Func Offset: 0x408
	// Line 332, Address: 0x1bfb54, Func Offset: 0x414
	// Line 333, Address: 0x1bfb60, Func Offset: 0x420
	// Line 335, Address: 0x1bfb6c, Func Offset: 0x42c
	// Line 336, Address: 0x1bfb74, Func Offset: 0x434
	// Line 338, Address: 0x1bfb7c, Func Offset: 0x43c
	// Line 339, Address: 0x1bfb80, Func Offset: 0x440
	// Line 342, Address: 0x1bfb90, Func Offset: 0x450
	// Line 343, Address: 0x1bfb9c, Func Offset: 0x45c
	// Line 344, Address: 0x1bfba8, Func Offset: 0x468
	// Line 346, Address: 0x1bfbb4, Func Offset: 0x474
	// Func End, Address: 0x1bfbcc, Func Offset: 0x48c
}

// 100% matching!
void bhEne06s_Dummy()
{

}

// 100% matching!
void bhEne06s_FloorCollision(BH_PWORK* epw)
{
    ATR_WORK* hp;

    if ((EXP0_US(0) & 0x1))
    {
        hp = bhCollisionCheckLine((NJS_POINT3*)&epw->pxb, (NJS_POINT3*)&epw->px);

        if (hp != NULL)
        {
            bhGetHitCollisionNormal((NJS_POINT3*)&epw->exp0[16]);
            
			njUnitVector((NJS_VECTOR*)&epw->exp0[16]);

            if (EXP0_F(20) > 0)
            {
                EXP0_US(0) &= ~0x1;
            }

            if (EXP0_F(20) < 0)
            {
                EXP0_F(8) = 0;
            }

            if (EXP0_F(20) == 0)
            {
                EXP0_F(4)  = 0;
                EXP0_F(12) = 0;
            }
        }

        epw->mtx[0][12] = epw->px;
        epw->mtx[0][13] = epw->py;
        epw->mtx[0][14] = epw->pz;
    }
}

// 
// Start address: 0x1bfcd0
void bhEne06s_WallCheck(BH_PWORK* epw)
{
	//_anon9* hp;
	int i;
	//_anon8 vec;
	// Line 404, Address: 0x1bfcd0, Func Offset: 0
	// Line 409, Address: 0x1bfce4, Func Offset: 0x14
	// Line 411, Address: 0x1bfcf8, Func Offset: 0x28
	// Line 412, Address: 0x1bfd00, Func Offset: 0x30
	// Line 413, Address: 0x1bfd2c, Func Offset: 0x5c
	// Line 414, Address: 0x1bfd38, Func Offset: 0x68
	// Line 415, Address: 0x1bfd4c, Func Offset: 0x7c
	// Line 416, Address: 0x1bfd54, Func Offset: 0x84
	// Line 417, Address: 0x1bfd60, Func Offset: 0x90
	// Line 418, Address: 0x1bfd6c, Func Offset: 0x9c
	// Line 419, Address: 0x1bfd88, Func Offset: 0xb8
	// Line 422, Address: 0x1bfd94, Func Offset: 0xc4
	// Line 423, Address: 0x1bfd9c, Func Offset: 0xcc
	// Line 424, Address: 0x1bfda0, Func Offset: 0xd0
	// Line 426, Address: 0x1bfdbc, Func Offset: 0xec
	// Line 428, Address: 0x1bfdc0, Func Offset: 0xf0
	// Line 430, Address: 0x1bfddc, Func Offset: 0x10c
	// Line 431, Address: 0x1bfde0, Func Offset: 0x110
	// Line 434, Address: 0x1bfde8, Func Offset: 0x118
	// Line 439, Address: 0x1bfdf4, Func Offset: 0x124
	// Line 440, Address: 0x1bfe00, Func Offset: 0x130
	// Line 443, Address: 0x1bfe10, Func Offset: 0x140
	// Line 448, Address: 0x1bfe18, Func Offset: 0x148
	// Line 443, Address: 0x1bfe24, Func Offset: 0x154
	// Line 444, Address: 0x1bfe28, Func Offset: 0x158
	// Line 445, Address: 0x1bfe34, Func Offset: 0x164
	// Line 448, Address: 0x1bfe40, Func Offset: 0x170
	// Line 449, Address: 0x1bfe64, Func Offset: 0x194
	// Func End, Address: 0x1bfe7c, Func Offset: 0x1ac
}
