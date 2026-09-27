#include "../../../ps2/veronica/prog/en23.h"
#include "../../../ps2/veronica/prog/en02.h"
#include "../../../ps2/veronica/prog/en03.h"
#include "../../../ps2/veronica/prog/en03sub.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

// ENEMY: Giant Black Widow 

NJS_POINT3 spl_051[80] = 
{
    { 0.0f,          0.0f,          0.0f },
    { 0.0f, -0.043997999f,          0.0f },
    { 0.0f, -0.123427004f,          0.0f },
    { 0.0f, -0.190007001f,          0.0f },
    { 0.0f, -0.243738994f,          0.0f },
    { 0.0f,    -0.284621f,          0.0f },
    { 0.0f, -0.312653005f,          0.0f },
    { 0.0f,  -0.32783699f,          0.0f },
    { 0.0f, -0.330172986f,          0.0f },
    { 0.0f, -0.319656014f,          0.0f },
    { 0.0f,  -0.29629299f,          0.0f },
    { 0.0f, -0.260078996f,          0.0f },
    { 0.0f, -0.211016998f,          0.0f },
    { 0.0f, -0.149105996f,          0.0f },
    { 0.0f, -0.074346997f,          0.0f },
    { 0.0f,     0.005778f, -0.015845001f },
    { 0.0f,  0.078883998f,     -0.04712f },
    { 0.0f,  0.145785004f,    -0.078342f },
    { 0.0f,  0.205887005f, -0.110159002f },
    { 0.0f,  0.258619994f, -0.143058002f },
    { 0.0f,  0.303436011f, -0.177352995f },
    { 0.0f,  0.339814991f, -0.213191003f },
    { 0.0f,  0.367247999f, -0.250535011f },
    { 0.0f,  0.385280997f, -0.289187998f },
    { 0.0f,  0.393503994f, -0.328774989f },
    { 0.0f,  0.391586989f, -0.368777007f },
    { 0.0f,  0.379301012f,  -0.40853101f },
    { 0.0f,  0.356534988f, -0.447259992f },
    { 0.0f,      0.32332f, -0.484091014f },
    { 0.0f,   0.27985099f, -0.518110991f },
    { 0.0f,  0.226494998f,  -0.54836601f },
    { 0.0f,  0.163798004f, -0.573920012f },
    { 0.0f,  0.092472002f, -0.593909025f },
    { 0.0f,     0.013408f, -0.607558012f },
    { 0.0f,    -0.072349f,  -0.61423099f },
    { 0.0f, -0.163657993f, -0.613456011f },
    { 0.0f, -0.259267986f, -0.604954004f },
    { 0.0f, -0.357311994f, -0.588689029f },
    { 0.0f, -0.446521997f, -0.564808011f },
    { 0.0f, -0.527827024f, -0.533720016f },
    { 0.0f,    -0.602651f, -0.496035993f },
    { 0.0f, -0.669950008f, -0.452576011f },
    { 0.0f, -0.728837013f, -0.404316008f },
    { 0.0f, -0.778612971f, -0.352382988f },
    { 0.0f, -0.818789005f, -0.297989011f },
    { 0.0f, -0.849110007f, -0.242401004f },
    { 0.0f, -0.869520009f, -0.186892003f },
    { 0.0f, -0.880186021f, -0.132695004f },
    { 0.0f, -0.881483018f,    -0.080978f },
    { 0.0f, -0.873930991f,    -0.032785f },
    { 0.0f,  -0.85819602f,     0.010963f },
    { 0.0f, -0.835048974f,     0.049513f },
    { 0.0f, -0.805310011f,     0.082278f },
    { 0.0f, -0.769832015f,     0.108834f },
    { 0.0f, -0.729451001f,     0.128943f },
    { 0.0f, -0.684931993f,     0.142512f },
    { 0.0f, -0.636990011f,     0.149603f },
    { 0.0f, -0.586210012f,     0.150407f },
    { 0.0f, -0.533039987f,     0.145226f },
    { 0.0f, -0.477804005f,     0.134455f },
    { 0.0f, -0.420648992f,     0.118571f },
    { 0.0f, -0.361571997f,     0.098123f },
    { 0.0f, -0.300401002f,     0.073717f },
    { 0.0f, -0.236799002f,     0.046018f },
    { 0.0f, -0.170291007f,      0.01577f },
    { 0.0f, -0.104172997f,     0.000002f },
    { 0.0f, -0.042123001f,     0.000003f },
    { 0.0f,     0.011841f,     0.000005f },
    { 0.0f,  0.057665002f,     0.000004f },
    { 0.0f,      0.09535f,     0.000005f },
    { 0.0f,  0.124898002f,     0.000006f },
    { 0.0f,  0.146304995f,     0.000006f },
    { 0.0f,  0.159574002f,     0.000006f },
    { 0.0f,  0.164702997f,     0.000007f },
    { 0.0f,  0.161695004f,     0.000006f },
    { 0.0f,  0.150545999f,     0.000004f },
    { 0.0f,  0.131259993f,     0.000005f },
    { 0.0f,  0.103832997f,     0.000002f },
    { 0.0f,     0.068269f,     0.000003f },
    { 0.0f,     0.024565f,     0.000001f }
};
NJS_POINT3 spl_052[21] = 
{
    {          0.0f,          0.0f,       0.0f },
    {  0.323074013f,   1.16421604f, -0.000003f },
    {  0.862697005f,   1.27816403f, -0.000003f },
    {   1.17025101f,   1.04479098f, -0.000004f },
    {     1.121099f,  0.545728981f, -0.000004f },
    {  0.680630982f,     0.022164f, -0.000004f },
    {     0.010563f, -0.280977994f, -0.000005f },
    { -0.589628994f, -0.296923995f, -0.000004f },
    { -0.868438005f, -0.179964006f, -0.000004f },
    { -0.754297972f, -0.167448997f, -0.000004f },
    { -0.488382012f, -0.711363971f, -0.000004f },
    { -0.407911003f,    -1.540488f, -0.000004f },
    { -0.329908013f,  -2.07722092f, -0.000004f },
    {    -0.255604f,  -2.31096101f, -0.000003f },
    { -0.188733995f,  -2.23500705f, -0.000004f },
    { -0.131156996f,  -1.84400296f, -0.000003f },
    { -0.083714001f,  -1.29996598f, -0.000002f },
    {    -0.046722f, -0.543478012f, -0.000002f },
    {    -0.020282f,  0.497803003f, -0.000002f },
    {    -0.004415f,  0.938849986f, -0.000001f },
    {     0.000878f,  0.506936014f,       0.0f }
};

static char joint_tree[5][6] = 
{
    {  0, -1,  0,  0,  0,  0 },
    {  0,  1,  4,  5,  6, -1 },
    {  0,  1, 13, 14, 15, -1 },
    {  0,  1, 25, 26, 27, -1 },
    {  0,  1, 28, 29, 30, -1 }
};
static unsigned char flip_tree[37] = 
{
     0,  1, 23, 24, 25, 26, 27, 22,
     8, 10,  9, 12, 11, 28, 29, 30,
    31, 32, 33, 34, 35, 36,  7,  2,
     3,  4,  5,  6, 13, 14, 15, 16,
    17, 18, 19, 20, 21
};
static char SdwTab[6] = 
{
    1, 27, 36, 6, 21, -1
};
static ETTY_WORK ene23_child = 
{
    0x1, 31, 0, 0, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, { 0, 0, 0, 0 }
};
static char BrokenParts[2][2] = { { 28, 31 }, { 13, 16 } };
static BP_WORK BloodParam = 
{
    { 0.0f, 0.1f, 0.0f }, 0, 0.0f, 0.2f, { 0.5f, 0.1f, 0.6f, 0.3f, 0.5f }, { 0, 3, 6, 9, 12 }
};
static BLOOD_TBL BloodTbl[37] = 
{
    { 1, {  0.0f,  0.0f,  0.0f }, 0.0f, 0.0f, 0.0f },
    { 0, {  0.0f,  3.0f, -5.0f }, 3.0f, 0.0f, 4.0f },
    { 1, {  0.0f,  3.0f,  5.0f }, 3.0f, 2.0f, 5.0f },
    { 1, {  0.0f,  3.0f,  5.0f }, 3.0f, 2.0f, 5.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 1, {  0.0f,  3.0f,  5.0f }, 3.0f, 2.0f, 5.0f },
    { 1, {  0.0f,  5.0f,  8.0f }, 4.0f, 3.0f, 6.0f },
    { 1, {  0.0f,  5.0f, -8.0f }, 4.0f, 3.0f, 6.0f },
    { 1, {  0.0f,  5.0f, -8.0f }, 4.0f, 3.0f, 6.0f },
    { 1, {  0.0f,  5.0f, -8.0f }, 4.0f, 3.0f, 6.0f },
    { 1, {  0.0f,  5.0f, -8.0f }, 4.0f, 3.0f, 6.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },   
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, { -3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 1, {  0.0f,  3.0f,  5.0f }, 3.0f, 2.0f, 5.0f },
    { 1, {  0.0f,  3.0f,  5.0f }, 3.0f, 2.0f, 5.0f },
    { 1, {  0.0f,  3.0f,  5.0f }, 3.0f, 2.0f, 5.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f },
    { 0, {  3.0f,  1.0f,  0.0f }, 3.0f, 0.0f, 1.0f }
};
static CPCL CapColTabA[25] = 
{
    {    1,    1,   32 },
    {    0,    0,  -40 },
    {    1,    1,   30 },
    {    0,    0,  -75 },
    {    1,    1,   25 },
    {    0,    0, -100 },
    {    8,    8,   75 },
    {    0,   30,   65 },
    {    4,    5,    6 },
    {    5,    6,    6 },
    {   25,   26,    6 },
    {   26,   27,    6 },
    {   13,   14,    6 },
    {   14,   15,    6 },
    {   28,   29,    6 },
    {   29,   30,    6 },
    {   16,   17,    6 },
    {   17,   18,    6 },
    {   31,   32,    6 },
    {   32,   33,    6 },
    {   19,   20,    6 },
    {   20,   21,    6 },
    {   34,   35,    6 },
    {   35,   36,    6 },
    {    0,    0,    0 }
};
static CPCL CapColTabB[23] = 
{
    {    1,    1,   32 },
    {    0,    0,  -40 },
    {    1,    1,   30 },
    {    0,    0,  -75 },
    {    1,    1,   25 },
    {    0,    0, -100 },
    {    4,    5,    6 },
    {    5,    6,    6 },
    {   25,   26,    6 },
    {   26,   27,    6 },
    {   13,   14,    6 },
    {   14,   15,    6 },
    {   28,   29,    6 },
    {   29,   30,    6 },
    {   16,   17,    6 },
    {   17,   18,    6 },
    {   31,   32,    6 },
    {   32,   33,    6 },
    {   19,   20,    6 },
    {   20,   21,    6 },
    {   34,   35,    6 },
    {   35,   36,    6 },
    {    0,    0,    0 }
};
static DMG_REACT DmgReact[21] = 
{
    { {  0,  1,  0 }, { 0, 0, 0 }, 0 },
    { {  0,  1,  0 }, { 0, 0, 0 }, 0 },
    { {  0,  0,  0 }, { 0, 0, 0 }, 0 },
    { {  1,  1,  0 }, { 0, 0, 0 }, 0 },
    { {  1,  1,  0 }, { 0, 0, 0 }, 0 },
    { {  1,  1,  0 }, { 0, 0, 0 }, 0 },
    { {  1,  1,  0 }, { 0, 0, 0 }, 0 },
    { {  1,  1,  0 }, { 0, 0, 0 }, 0 },
    { {  0,  0,  0 }, { 0, 0, 0 }, 0 },
    { {  1,  1,  0 }, { 0, 0, 0 }, 0 },
    { {  0,  0,  0 }, { 0, 0, 0 }, 0 },
    { {  2,  1,  0 }, { 1, 0, 0 }, 0 },
    { {  0,  0,  0 }, { 0, 0, 0 }, 0 },
    { {  1,  1,  0 }, { 0, 0, 0 }, 0 },
    { {  2,  1,  0 }, { 1, 1, 1 }, 1 },
    { { -1, -1, -1 }, { 0, 0, 0 }, 2 },
    { { -1, -1, -1 }, { 0, 0, 0 }, 1 },
    { { -1, -1, -1 }, { 0, 0, 0 }, 0 },
    { {  2,  2,  2 }, { 1, 1, 1 }, 5 },
    { {  2,  2,  2 }, { 0, 0, 0 }, 1 },
    { {  2,  2,  2 }, { 1, 1, 1 }, 5 }
};
static COMBWEP_WORK CombWepTbl[21] = 
{
    {  0, {  0,  0,  0 },  0,  0 },
    {  0, {  0,  0,  0 },  0,  0 },
    {  4, {  1,  0,  0 }, 30, 20 },
    { 10, {  4,  3,  1 }, 20, 10 },
    { 10, {  4,  3,  1 }, 20, 10 },
    { 10, {  4,  3,  1 }, 10,  0 },
    {  0, {  0,  0,  0 }, 25,  0 },
    {  0, {  0,  0,  0 }, 25,  0 },
    { 25, {  5,  3,  1 },  5,  0 },
    {  0, {  0,  0,  0 },  0,  0 },
    {  0, {  0,  0,  0 }, 10,  0 },
    {  0, {  0,  0,  0 }, 30,  0 },
    { 25, {  5,  4,  2 }, 10,  0 },
    {  0, {  0,  0,  0 }, 60,  0 },
    {  0, {  0,  0,  0 },  0,  0 },
    {  0, {  0,  0,  0 },  0,  0 },
    { 15, {  1,  1,  1 },  0,  0 },
    {  0, {  0,  0,  0 },  0,  0 },
    {  0, {  0,  0,  0 },  0,  0 },
    {  0, {  0,  0,  0 },  0,  0 },
    {  0, {  0,  0,  0 },  0,  0 }
};
static COMBJOINT_WORK CombJointTbl[37] = { 0 };

void (*bhEne23_Mode0[6])(BH_PWORK*) = 
{
	bhEne23_Init,
	bhEne23_Move,
	bhEne23_Nage,
	bhEne23_Damage,
	bhEne23_Die,
	bhEne_Event
};
void (*bhEne23_BrainType[2])(BH_PWORK*) = 
{
	bhEne23_BR00,
	bhEne23_BR01
};
void (*bhEne23_MoveMode2[13])(BH_PWORK*) = 
{
	bhEne23_MV00,
	bhEne23_MV01,
	bhEne23_MV02,
	bhEne23_MV03,
	bhEne23_MV04,
	bhEne23_MV05,
	bhEne23_MV06,
	bhEne23_MV07,
	bhEne23_MV08,
	bhEne23_MV09,
	bhEne23_MV10,
	bhEne23_MV11,
	bhEne23_MV12
};
void (*bhEne23_NageMode2[1])(BH_PWORK*) = 
{
	bhEne23_NG00
};
void (*bhEne23_DamageMode2[8])(BH_PWORK*) = 
{
	bhEne23_DG00,
	bhEne23_DG01,
	bhEne23_DG02,
	bhEne23_DG03,
	bhEne23_DG04,
	bhEne23_DG05,
	bhEne23_DG06,
	bhEne23_DG07
};
void (*bhEne23_DeadMode2[4])(BH_PWORK*) = 
{
	bhEne23_DD00,
	bhEne23_DD01,
	bhEne23_DD02,
	bhEne23_DD03
};
/* unused below */
/*ETTY_WORK ene24;
NJS_POINT3 spl_016[20];
NJS_POINT3 spl_023[25];*/

// 100% matching!
void bhEne23(BH_PWORK* epw)
{
    NJS_POINT3 pos;   
    unsigned int flg;

    epw->flg &= ~0x100;

    bhEne23_Mode0[epw->mode0](epw);
    
    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);

    bhEne23_CallSE(epw);
    
    if ((epw->flg & 0x800000)) 
    {
        bhEne03_GetPartsPos(epw, joint_tree[0], &pos);
        
        epw->aox = pos.x - epw->px;
        epw->aoy = pos.y - epw->py;
        epw->aoz = pos.z - epw->pz;
        
        if (!(epw->flg & 0x1000000)) 
        {
            epw->aoy = 0;
        }
    }
    else 
    {
        epw->aox = 0;
        epw->aoy = 0;
        epw->aoz = 0;
    }
    
    if (!(epw->flg & 0x400000)) 
    {
        bhCheckPlayer(epw);
    }

    if (!(epw->flg & 0x4000000)) 
    {
        bhEne23_CollisionLine(epw);
    }
 
    if ((epw->flg & 0x10)) 
    {
        bhEne23_CollisionWalls(epw);
    }
    
    njUnitMatrix(epw->mtx);
    
    njTranslate(epw->mtx, epw->px, epw->py, epw->pz);
    
    njMultiMatrix(epw->mtx, (NJS_MATRIX*)epw->exp0);
    
    if (epw->mnwP != epw->mnwPb) 
    {
        flg = epw->flg;
        
        epw->flg &= ~0x1000;
        
        bhCalcModel(epw);
        
        epw->flg = flg;
        
        epw->mdflg &= ~0x4;
    } 
    else 
    {
        epw->mdflg |=  0x4;
    }
    
    if ((epw->type & 0x1)) 
    {
        bhEne_SetWeponAtr(epw, 22, 1,  8.0f);
    }
    else
    {
        bhEne_SetWeponAtr(epw, 22, 12, 8.0f);
    }

    bhEne23_Shape(epw);
    
    bhEne23_PlayerControl(epw);
}

// 99.44% matching
void bhEne23_Init(BH_PWORK* epw)
{
    BH_PWORK** epw2, *ep;    
    O_WORK* owk;         
    int i;              
    NJS_POINT3 p;
    int sdw;

    epw->flg |=  0x1078;
    epw->flg &= ~0x6;

    epw->mdflg |= 0x4;

    epw->ar = 14.0f;
    epw->ah = 20.0f;
    
    epw->car = 15.0f;
    epw->cah = 8.0f;

    epw->hokan_rate  = 65536;
    epw->hokan_count = 0;

    epw->mtn_no  = 0;
    epw->mtn_md  = 0;
    epw->mtn_add = 65536;

    epw->frm_no = 0;

    epw->mtn_tp = (unsigned char*)flip_tree;

    bhCalcModel(epw);

    epw->mode0 = 1;
    epw->mode1 = 1;
    epw->mode2 = 1;     
    epw->mode3 = 0;

    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(304, 8);  

        epw2 = (BH_PWORK**)&EXP0_C(248);      

        for (i = 0; i < 2; i++)               
        {
            *epw2 = bhSetEnemy(&ene23_child, rom->ene_n);

            (*epw2)->type = 1;                 

            (*epw2)->lkwkp = (unsigned char*)epw;
            (*epw2)->lkono = i;                 

            (*epw2)->lox = 0;
            (*epw2)->loy = 0;
            (*epw2)->loz = 0;

            (*epw2)->mdflg |= 0x1;

            ((unsigned char*)epw->exp0)[i + 256] = BrokenParts[i][(int)(2.0f * (-rand() / -2147483648.0f))];

            owk = &epw->mlwP->owP[((unsigned char*)epw->exp0)[i + 256]];

            (*epw2)->mtx = &owk->mtx;

            (*epw2++)->exp1 = (unsigned char*)owk;
        }

        bhEne_SetCallFunc(bhEne03s, 31);
    }

    EXP0_F(108) = 14.0f;
    EXP0_I(272) = (int)(30.0f * (-rand() / -2147483648.0f)) + 30;
    EXP0_F(280) = 10.4f;

    if ((epw->type & 0x1))
    {
        epw->hp = ((sys->gm_mode != 2) ? 250 : 160) - ((sys->gm_mode != 2) ? 100 : 50);
    }
    else
    {
        epw->hp     = (sys->gm_mode != 2) ? 250 : 160;
        EXP0_I(276) = (sys->gm_mode != 2) ? 100 : 50;
    }

    EXP0_I(268) = 0;

    ep = ene;

    for (i = 0; i < sys->ewk_n; i++, ep++)
    {
        if (((ep->flg & 0x1)) && (ep->id == 24))
        {
            ((BH_PWORK**)epw->exp0)[32 + EXP0_I(268)] = ep;
            
            EXP0_I(268)++;

            ep->lkwkp = (unsigned char*)epw;
            ep->lkono = 0;

            ep->lox = 0;
            ep->loy = 0;
            ep->loz = 0;

            ep->mlwP = &epw->mdl[2];
        }
    }

    for (i = 0; i < 8; i++)
    {
        ((char*)epw->exp0)[258 + i] = 0;  
    }

    njUnitMatrix((NJS_MATRIX*)epw->exp0);
    
    njRotateY((NJS_MATRIX*)epw->exp0, epw->ay);

    epw->flg &= ~0x4000000; 

    if ((epw->type & 0x2))
    {
        p.x = epw->px;
        p.y = epw->py + 999.0f;
        p.z = epw->pz;

        if (bhCollisionCheckLine((NJS_POINT3*)&epw->px, &p) != NULL)
        {
            EXP0_C(105) = 1;

            bhEne03_MakeMatrix(epw);

            epw->py = p.y;

            epw->flg |= 0x4000000;
        }

        epw->type &= ~0x2;
    }

    if (!(epw->flg & 0x4000000))
    {
        EXP0_C(105) = 0;
        
        epw->flg |= 0x4000000;
    }

    epw->pxb = epw->px;
    epw->pyb = epw->py;
    epw->pzb = epw->pz;

    *(ATR_WORK**)&EXP0_I(96) = bhEne03_GetWall(epw);

    epw->clp_jno[0] = 1;
    epw->clp_jno[1] = 10;
    epw->clp_jno[2] = 27;
    epw->clp_jno[3] = 36;
    epw->clp_jno[4] = 6;
    epw->clp_jno[5] = 21;
    epw->clp_jno[6] = 24;
    epw->clp_jno[7] = 3;

    epw->mdflg &= ~0x20;

    if (!(epw->flg & 0x800))
    {
        sdw = bhSetShadow(SdwTab, (unsigned char*)epw, 0, 16.0f, 18.0f, 18.0f);

        eff[sdw].id = 258;

        epw->flg |= 0x800;
    }

    epw->stflg &= ~0x8;

    if ((epw->type & 0x4))
    {
        epw->type &= ~0x4;

        epw->flg &= ~0x60;    
        epw->flg |=  0x8000000; 

        epw->stflg |= 0x8;

        epw->ar = 13.0f;       
    }
    else
    {
        epw->flg &= ~0x8000000; 
    }

    if ((epw->type & 0x1))
    {
        epw->cpcl = CapColTabB;
    }
    else
    {
        epw->cpcl = CapColTabA;
    }

    bhEne03_HideParts(epw, 1, 0);

    if ((epw->type & 0x1))
    {
        bhEne03_HideParts(epw, 8, 1);
    }
    
    bhEne03_SetModelFlg(epw, -4, 0);

    sys->rm_flg &= ~0x1;

    if (!(epw->type & 0x1))
    {
        epw->mlwP = epw->mdl;

        epw->obj_a = epw->mdl[0].objP;
        epw->obj_b = epw->mdl[1].objP;

        epw->mdflg |= 0x2;

        epw->shp_ct = 0;
    }
}

// 100% matching!
void bhEne23_Brain(BH_PWORK* epw)
{
	bhEne23_BrainType[epw->type](epw);
}

// 100% matching!
void bhEne23_BR00(BH_PWORK* epw)
{
	EXP0_F(64) = njSqrt(((epw->px - plp->px) * (epw->px - plp->px)) + ((epw->pz - plp->pz) * (epw->pz - plp->pz)));

    bhEne23_SearchPlayer(epw, 8192);

    if ((epw->flg & 0x8000000))
    {
        return;
    }

    if (EXP0_I(272) != 0)
    {
        EXP0_I(272)--;
    }

    if (EXP0_C(105) == 0)
    {
        if ((epw->flr_no != plp->flr_no) && (!(plp->stflg & 0x20)))
        {
            epw->mode1 = 0;
            epw->mode2 = 2;
            epw->mode3 = 0;
            return;
        }

        if (((plp->stflg & 0x80000000)) || ((epw->flg & 0x4)))
        {
            return;
        }

        if (EXP0_I(272) != 0)
        {
            return;
        }

        if ((EXP0_F(64) < 30.0f) && (bhEne23_SearchPlayer(epw, 5461) != 0) && (fabsf(epw->py - plp->py) < 5.0f))
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 10;
            epw->mode3 = 0;
            
            EXP0_I(272) = (int)(20.0f * (-rand() / -2147483648.0f)) + 10;
            return;
        }

        if ((EXP0_F(64) > 35.0f) && (bhEne23_SearchPlayer(epw, 5461) != 0))
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 9;
            epw->mode3 = 0;
            
            EXP0_I(272) = (int)(20.0f * (-rand() / -2147483648.0f)) + 10;
        }
    }
    else if (EXP0_C(105) == 1)
    {
        if ((plp->flr_no == 0) && (!(plp->stflg & 0x20)))
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 3;
            epw->mode3 = 0;
            return;
        }

        if (EXP0_I(272) != 0)
        {
            return;
        }

        if ((EXP0_F(64) < 28.0f) && (fabsf(plp->py - epw->py) < 45.0f) && (bhEne23_SearchPlayer(epw, 3640) != 0))
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 10;
            epw->mode3 = 0;
            
            EXP0_I(272) = (int)(20.0f * (-rand() / -2147483648.0f)) + 40;
            return;
        }

        if ((EXP0_F(64) < 35.0f) && (bhEne23_SearchPlayer(epw, 10922) != 0))
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 9;
            epw->mode3 = 0;
            
            EXP0_I(272) = (int)(20.0f * (-rand() / -2147483648.0f)) + 20;
        }
    }
}

// 100% matching!
void bhEne23_BR01(BH_PWORK* epw)
{
    EXP0_F(64) = njSqrt(((epw->px - plp->px) * (epw->px - plp->px)) + ((epw->pz - plp->pz) * (epw->pz - plp->pz)));

    bhEne23_SearchPlayer(epw, 8192);

    if ((!(epw->flg & 0x8000000)) && (EXP0_I(272) != 0))
    {
        EXP0_I(272)--;
    }

    if (EXP0_C(105) == 0)
    {
        if ((epw->flr_no != plp->flr_no) && (!(plp->stflg & 0x20)))
        {
            epw->mode1 = 0;
            epw->mode2 = 2;
            epw->mode3 = 0;
            return;
        }

        if (((plp->stflg & 0x80000000)) || ((epw->flg & 0x4)))
        {
            return;
        }

        if (EXP0_I(272) != 0)
        {
            return;
        }

        if ((EXP0_F(64) < 30.0f) && (bhEne23_SearchPlayer(epw, 3640) != 0) && (fabsf(epw->py - plp->py) < 5.0f))
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 10;
            epw->mode3 = 0;
            
            EXP0_I(272) = (int)(20.0f * (-rand() / -2147483648.0f)) + 10;
        }
    }
    else if (EXP0_C(105) == 1)
    {
        if ((plp->flr_no == 0) && (!(plp->stflg & 0x20)))
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 3;
            epw->mode3 = 0;
            return;
        }

        if (EXP0_I(272) != 0)
        {
            return;
        }

        if ((EXP0_F(64) < 28.0f) && (fabsf(plp->py - epw->py) < 45.0f) && (bhEne23_SearchPlayer(epw, 3640) != 0))
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 10;
            epw->mode3 = 0;
            
            EXP0_I(272) = (int)(20.0f * (-rand() / -2147483648.0f)) + 40;
        }
    }
}

// 100% matching!
void bhEne23_Move(BH_PWORK* epw)
{
	if (epw->mode1 == 1)
    {
        bhEne23_Brain(epw);
    }

    if (epw->mode0 == 1)
    {
        bhEne23_MoveMode2[epw->mode2](epw);
    }

	if (((epw->flg & 0x4)) && (!(epw->flg & 0x2)))
    {
        bhEne23_DamageInit(epw);
    }
}

// 
// Start address: 0x200fb0
void bhEne23_MV00(BH_PWORK* epw)
{
	float dist;
	int mtn[2] = { 0, 53 };
	int mno;
	// Line 1054, Address: 0x200fb0, Func Offset: 0
	// Line 1055, Address: 0x200fb4, Func Offset: 0x4
	// Line 1054, Address: 0x200fb8, Func Offset: 0x8
	// Line 1055, Address: 0x200fc0, Func Offset: 0x10
	// Line 1058, Address: 0x200fd4, Func Offset: 0x24
	// Line 1061, Address: 0x200ff4, Func Offset: 0x44
	// Line 1062, Address: 0x200ff8, Func Offset: 0x48
	// Line 1061, Address: 0x200ffc, Func Offset: 0x4c
	// Line 1062, Address: 0x201008, Func Offset: 0x58
	// Line 1063, Address: 0x201010, Func Offset: 0x60
	// Line 1065, Address: 0x201014, Func Offset: 0x64
	// Line 1064, Address: 0x201018, Func Offset: 0x68
	// Line 1065, Address: 0x20101c, Func Offset: 0x6c
	// Line 1066, Address: 0x201020, Func Offset: 0x70
	// Line 1068, Address: 0x201028, Func Offset: 0x78
	// Line 1070, Address: 0x201030, Func Offset: 0x80
	// Line 1073, Address: 0x20103c, Func Offset: 0x8c
	// Line 1074, Address: 0x201080, Func Offset: 0xd0
	// Line 1077, Address: 0x20108c, Func Offset: 0xdc
	// Line 1079, Address: 0x201094, Func Offset: 0xe4
	// Line 1080, Address: 0x2010a0, Func Offset: 0xf0
	// Line 1081, Address: 0x2010a4, Func Offset: 0xf4
	// Line 1083, Address: 0x2010ac, Func Offset: 0xfc
	// Line 1084, Address: 0x2010d8, Func Offset: 0x128
	// Line 1085, Address: 0x2010f8, Func Offset: 0x148
	// Line 1086, Address: 0x201114, Func Offset: 0x164
	// Line 1087, Address: 0x201140, Func Offset: 0x190
	// Line 1088, Address: 0x201148, Func Offset: 0x198
	// Line 1089, Address: 0x20114c, Func Offset: 0x19c
	// Line 1094, Address: 0x201150, Func Offset: 0x1a0
	// Func End, Address: 0x201160, Func Offset: 0x1b0
}

// 
// Start address: 0x201160
void bhEne23_MV01(BH_PWORK* epw)
{
	// already reversed DWARF order
	NJS_POINT3 pos;
	int mno;
	int mtn[2] = { 2, 22 };
	float dist;
	float spd[2] = { 0.7f, 1.0f };
	NJS_POINT3 dp;
	NJS_POINT3 sp;
	// Line 1104, Address: 0x201160, Func Offset: 0
	// Line 1106, Address: 0x201164, Func Offset: 0x4
	// Line 1104, Address: 0x201168, Func Offset: 0x8
	// Line 1106, Address: 0x201170, Func Offset: 0x10
	// Line 1107, Address: 0x20117c, Func Offset: 0x1c
	// Line 1106, Address: 0x20118c, Func Offset: 0x2c
	// Line 1107, Address: 0x201190, Func Offset: 0x30
	// Line 1109, Address: 0x201198, Func Offset: 0x38
	// Line 1112, Address: 0x2011b8, Func Offset: 0x58
	// Line 1113, Address: 0x2011bc, Func Offset: 0x5c
	// Line 1112, Address: 0x2011c0, Func Offset: 0x60
	// Line 1113, Address: 0x2011cc, Func Offset: 0x6c
	// Line 1114, Address: 0x2011d4, Func Offset: 0x74
	// Line 1116, Address: 0x2011d8, Func Offset: 0x78
	// Line 1115, Address: 0x2011dc, Func Offset: 0x7c
	// Line 1116, Address: 0x2011e0, Func Offset: 0x80
	// Line 1117, Address: 0x2011e4, Func Offset: 0x84
	// Line 1119, Address: 0x2011ec, Func Offset: 0x8c
	// Line 1120, Address: 0x2011fc, Func Offset: 0x9c
	// Line 1121, Address: 0x201204, Func Offset: 0xa4
	// Line 1124, Address: 0x201214, Func Offset: 0xb4
	// Line 1126, Address: 0x20121c, Func Offset: 0xbc
	// Line 1128, Address: 0x201228, Func Offset: 0xc8
	// Line 1129, Address: 0x201264, Func Offset: 0x104
	// Line 1130, Address: 0x2012b8, Func Offset: 0x158
	// Line 1132, Address: 0x2012cc, Func Offset: 0x16c
	// Line 1133, Address: 0x2012dc, Func Offset: 0x17c
	// Line 1134, Address: 0x2012e0, Func Offset: 0x180
	// Line 1135, Address: 0x2012e8, Func Offset: 0x188
	// Line 1139, Address: 0x2012f0, Func Offset: 0x190
	// Line 1140, Address: 0x201304, Func Offset: 0x1a4
	// Line 1142, Address: 0x20130c, Func Offset: 0x1ac
	// Line 1141, Address: 0x201310, Func Offset: 0x1b0
	// Line 1142, Address: 0x201314, Func Offset: 0x1b4
	// Line 1143, Address: 0x201318, Func Offset: 0x1b8
	// Line 1144, Address: 0x201320, Func Offset: 0x1c0
	// Line 1148, Address: 0x20132c, Func Offset: 0x1cc
	// Line 1149, Address: 0x201370, Func Offset: 0x210
	// Line 1152, Address: 0x20137c, Func Offset: 0x21c
	// Line 1155, Address: 0x201388, Func Offset: 0x228
	// Line 1157, Address: 0x20138c, Func Offset: 0x22c
	// Line 1155, Address: 0x201390, Func Offset: 0x230
	// Line 1157, Address: 0x201394, Func Offset: 0x234
	// Line 1161, Address: 0x2013a4, Func Offset: 0x244
	// Line 1164, Address: 0x2013a8, Func Offset: 0x248
	// Line 1169, Address: 0x2013b0, Func Offset: 0x250
	// Line 1161, Address: 0x2013b8, Func Offset: 0x258
	// Line 1162, Address: 0x2013bc, Func Offset: 0x25c
	// Line 1163, Address: 0x2013c0, Func Offset: 0x260
	// Line 1169, Address: 0x2013c4, Func Offset: 0x264
	// Line 1163, Address: 0x2013c8, Func Offset: 0x268
	// Line 1164, Address: 0x2013cc, Func Offset: 0x26c
	// Line 1165, Address: 0x2013d4, Func Offset: 0x274
	// Line 1166, Address: 0x2013d8, Func Offset: 0x278
	// Line 1169, Address: 0x2013dc, Func Offset: 0x27c
	// Line 1170, Address: 0x2013f4, Func Offset: 0x294
	// Line 1171, Address: 0x201414, Func Offset: 0x2b4
	// Line 1172, Address: 0x20142c, Func Offset: 0x2cc
	// Line 1174, Address: 0x201434, Func Offset: 0x2d4
	// Line 1175, Address: 0x201440, Func Offset: 0x2e0
	// Line 1174, Address: 0x201444, Func Offset: 0x2e4
	// Line 1175, Address: 0x201448, Func Offset: 0x2e8
	// Line 1179, Address: 0x201454, Func Offset: 0x2f4
	// Line 1180, Address: 0x201464, Func Offset: 0x304
	// Line 1182, Address: 0x20146c, Func Offset: 0x30c
	// Line 1183, Address: 0x201494, Func Offset: 0x334
	// Line 1184, Address: 0x2014b4, Func Offset: 0x354
	// Line 1185, Address: 0x2014cc, Func Offset: 0x36c
	// Line 1187, Address: 0x2014d4, Func Offset: 0x374
	// Line 1188, Address: 0x2014e0, Func Offset: 0x380
	// Line 1187, Address: 0x2014e4, Func Offset: 0x384
	// Line 1188, Address: 0x2014e8, Func Offset: 0x388
	// Line 1192, Address: 0x2014f4, Func Offset: 0x394
	// Line 1194, Address: 0x201518, Func Offset: 0x3b8
	// Line 1195, Address: 0x201534, Func Offset: 0x3d4
	// Line 1196, Address: 0x201544, Func Offset: 0x3e4
	// Line 1197, Address: 0x20154c, Func Offset: 0x3ec
	// Line 1201, Address: 0x201560, Func Offset: 0x400
	// Line 1208, Address: 0x20156c, Func Offset: 0x40c
	// Line 1209, Address: 0x201578, Func Offset: 0x418
	// Line 1210, Address: 0x20157c, Func Offset: 0x41c
	// Line 1211, Address: 0x201584, Func Offset: 0x424
	// Line 1214, Address: 0x20158c, Func Offset: 0x42c
	// Line 1215, Address: 0x2015b8, Func Offset: 0x458
	// Line 1216, Address: 0x2015d8, Func Offset: 0x478
	// Line 1217, Address: 0x2015f4, Func Offset: 0x494
	// Line 1218, Address: 0x201620, Func Offset: 0x4c0
	// Line 1219, Address: 0x201628, Func Offset: 0x4c8
	// Line 1220, Address: 0x20162c, Func Offset: 0x4cc
	// Line 1224, Address: 0x201630, Func Offset: 0x4d0
	// Func End, Address: 0x201640, Func Offset: 0x4e0
}

// 
// Start address: 0x201640
void bhEne23_MV02(BH_PWORK* epw)
{
	// already reversed DWARF order
	int mno;
	int mtn[2] = { 2, 22 };
	float spd[2] = { 0.7f, 1.0f };
	ATR_WORK* fp;
	int i;
	int flr_n;
	float min;
	float dist;
	float dx;
	float dz;
	int fno;
	// Line 1234, Address: 0x201640, Func Offset: 0
	// Line 1235, Address: 0x201644, Func Offset: 0x4
	// Line 1234, Address: 0x201648, Func Offset: 0x8
	// Line 1235, Address: 0x201650, Func Offset: 0x10
	// Line 1236, Address: 0x20165c, Func Offset: 0x1c
	// Line 1235, Address: 0x20166c, Func Offset: 0x2c
	// Line 1236, Address: 0x201670, Func Offset: 0x30
	// Line 1238, Address: 0x201678, Func Offset: 0x38
	// Line 1241, Address: 0x201698, Func Offset: 0x58
	// Line 1242, Address: 0x20169c, Func Offset: 0x5c
	// Line 1241, Address: 0x2016a0, Func Offset: 0x60
	// Line 1242, Address: 0x2016ac, Func Offset: 0x6c
	// Line 1243, Address: 0x2016b4, Func Offset: 0x74
	// Line 1245, Address: 0x2016b8, Func Offset: 0x78
	// Line 1244, Address: 0x2016bc, Func Offset: 0x7c
	// Line 1245, Address: 0x2016c0, Func Offset: 0x80
	// Line 1246, Address: 0x2016c4, Func Offset: 0x84
	// Line 1248, Address: 0x2016cc, Func Offset: 0x8c
	// Line 1249, Address: 0x2016dc, Func Offset: 0x9c
	// Line 1250, Address: 0x2016e4, Func Offset: 0xa4
	// Line 1253, Address: 0x2016f4, Func Offset: 0xb4
	// Line 1255, Address: 0x2016fc, Func Offset: 0xbc
	// Line 1257, Address: 0x201708, Func Offset: 0xc8
	// Line 1258, Address: 0x201748, Func Offset: 0x108
	// Line 1259, Address: 0x20179c, Func Offset: 0x15c
	// Line 1265, Address: 0x2017a0, Func Offset: 0x160
	// Line 1267, Address: 0x2017ac, Func Offset: 0x16c
	// Line 1259, Address: 0x2017b0, Func Offset: 0x170
	// Line 1267, Address: 0x2017c0, Func Offset: 0x180
	// Line 1268, Address: 0x2017e0, Func Offset: 0x1a0
	// Line 1272, Address: 0x2017f0, Func Offset: 0x1b0
	// Line 1271, Address: 0x2017f4, Func Offset: 0x1b4
	// Line 1272, Address: 0x2017f8, Func Offset: 0x1b8
	// Line 1271, Address: 0x2017fc, Func Offset: 0x1bc
	// Line 1270, Address: 0x201800, Func Offset: 0x1c0
	// Line 1271, Address: 0x20184c, Func Offset: 0x20c
	// Line 1272, Address: 0x201884, Func Offset: 0x244
	// Line 1273, Address: 0x201888, Func Offset: 0x248
	// Line 1272, Address: 0x20188c, Func Offset: 0x24c
	// Line 1273, Address: 0x201890, Func Offset: 0x250
	// Line 1272, Address: 0x201894, Func Offset: 0x254
	// Line 1273, Address: 0x201898, Func Offset: 0x258
	// Line 1272, Address: 0x20189c, Func Offset: 0x25c
	// Line 1273, Address: 0x2018a0, Func Offset: 0x260
	// Line 1272, Address: 0x2018a4, Func Offset: 0x264
	// Line 1273, Address: 0x2018a8, Func Offset: 0x268
	// Line 1272, Address: 0x2018ac, Func Offset: 0x26c
	// Line 1273, Address: 0x2018b0, Func Offset: 0x270
	// Line 1274, Address: 0x2018b4, Func Offset: 0x274
	// Line 1275, Address: 0x2018bc, Func Offset: 0x27c
	// Line 1277, Address: 0x2018cc, Func Offset: 0x28c
	// Line 1276, Address: 0x2018d0, Func Offset: 0x290
	// Line 1277, Address: 0x2018d4, Func Offset: 0x294
	// Line 1278, Address: 0x2018d8, Func Offset: 0x298
	// Line 1279, Address: 0x2018e4, Func Offset: 0x2a4
	// Line 1281, Address: 0x2018fc, Func Offset: 0x2bc
	// Line 1282, Address: 0x201900, Func Offset: 0x2c0
	// Line 1284, Address: 0x201910, Func Offset: 0x2d0
	// Line 1286, Address: 0x20191c, Func Offset: 0x2dc
	// Line 1291, Address: 0x201928, Func Offset: 0x2e8
	// Line 1293, Address: 0x201930, Func Offset: 0x2f0
	// Line 1294, Address: 0x201944, Func Offset: 0x304
	// Line 1295, Address: 0x201954, Func Offset: 0x314
	// Line 1296, Address: 0x20195c, Func Offset: 0x31c
	// Line 1298, Address: 0x201974, Func Offset: 0x334
	// Line 1300, Address: 0x201984, Func Offset: 0x344
	// Line 1299, Address: 0x201988, Func Offset: 0x348
	// Line 1300, Address: 0x20198c, Func Offset: 0x34c
	// Line 1302, Address: 0x201990, Func Offset: 0x350
	// Line 1307, Address: 0x201998, Func Offset: 0x358
	// Line 1309, Address: 0x2019b8, Func Offset: 0x378
	// Line 1310, Address: 0x2019c4, Func Offset: 0x384
	// Line 1314, Address: 0x2019d0, Func Offset: 0x390
	// Line 1315, Address: 0x2019e4, Func Offset: 0x3a4
	// Line 1322, Address: 0x2019f0, Func Offset: 0x3b0
	// Line 1323, Address: 0x2019fc, Func Offset: 0x3bc
	// Line 1326, Address: 0x201a04, Func Offset: 0x3c4
	// Line 1327, Address: 0x201a1c, Func Offset: 0x3dc
	// Line 1328, Address: 0x201a20, Func Offset: 0x3e0
	// Line 1331, Address: 0x201a24, Func Offset: 0x3e4
	// Line 1332, Address: 0x201a2c, Func Offset: 0x3ec
	// Line 1335, Address: 0x201a34, Func Offset: 0x3f4
	// Func End, Address: 0x201a44, Func Offset: 0x404
}

// 
// Start address: 0x201a50
void bhEne23_MV03(BH_PWORK* epw)
{
	// already reversed DWARF order
	int mno;
	int mtn[2] = { 2, 22 };
	float spd[2] = { 0.7f, 1.0f };
	ATR_WORK* fp;
	int i;
	int flr_n;
	float min;
	float dist;
	float dx;
	float dz;
	NJS_POINT3 p1;
	NJS_POINT3 p2;
	// Line 1345, Address: 0x201a50, Func Offset: 0
	// Line 1346, Address: 0x201a54, Func Offset: 0x4
	// Line 1345, Address: 0x201a58, Func Offset: 0x8
	// Line 1346, Address: 0x201a60, Func Offset: 0x10
	// Line 1347, Address: 0x201a6c, Func Offset: 0x1c
	// Line 1346, Address: 0x201a7c, Func Offset: 0x2c
	// Line 1347, Address: 0x201a80, Func Offset: 0x30
	// Line 1349, Address: 0x201a88, Func Offset: 0x38
	// Line 1352, Address: 0x201aa8, Func Offset: 0x58
	// Line 1353, Address: 0x201aac, Func Offset: 0x5c
	// Line 1352, Address: 0x201ab0, Func Offset: 0x60
	// Line 1353, Address: 0x201abc, Func Offset: 0x6c
	// Line 1354, Address: 0x201ac4, Func Offset: 0x74
	// Line 1356, Address: 0x201ac8, Func Offset: 0x78
	// Line 1355, Address: 0x201acc, Func Offset: 0x7c
	// Line 1356, Address: 0x201ad0, Func Offset: 0x80
	// Line 1357, Address: 0x201ad4, Func Offset: 0x84
	// Line 1359, Address: 0x201adc, Func Offset: 0x8c
	// Line 1360, Address: 0x201aec, Func Offset: 0x9c
	// Line 1361, Address: 0x201af4, Func Offset: 0xa4
	// Line 1364, Address: 0x201b04, Func Offset: 0xb4
	// Line 1366, Address: 0x201b0c, Func Offset: 0xbc
	// Line 1368, Address: 0x201b18, Func Offset: 0xc8
	// Line 1369, Address: 0x201b58, Func Offset: 0x108
	// Line 1370, Address: 0x201bac, Func Offset: 0x15c
	// Line 1376, Address: 0x201bb0, Func Offset: 0x160
	// Line 1378, Address: 0x201bbc, Func Offset: 0x16c
	// Line 1370, Address: 0x201bc0, Func Offset: 0x170
	// Line 1378, Address: 0x201bd0, Func Offset: 0x180
	// Line 1379, Address: 0x201bf0, Func Offset: 0x1a0
	// Line 1383, Address: 0x201c00, Func Offset: 0x1b0
	// Line 1382, Address: 0x201c04, Func Offset: 0x1b4
	// Line 1383, Address: 0x201c08, Func Offset: 0x1b8
	// Line 1382, Address: 0x201c0c, Func Offset: 0x1bc
	// Line 1381, Address: 0x201c14, Func Offset: 0x1c4
	// Line 1382, Address: 0x201c60, Func Offset: 0x210
	// Line 1383, Address: 0x201c94, Func Offset: 0x244
	// Line 1384, Address: 0x201c98, Func Offset: 0x248
	// Line 1383, Address: 0x201c9c, Func Offset: 0x24c
	// Line 1384, Address: 0x201ca0, Func Offset: 0x250
	// Line 1383, Address: 0x201ca4, Func Offset: 0x254
	// Line 1384, Address: 0x201ca8, Func Offset: 0x258
	// Line 1383, Address: 0x201cac, Func Offset: 0x25c
	// Line 1384, Address: 0x201cb0, Func Offset: 0x260
	// Line 1383, Address: 0x201cb4, Func Offset: 0x264
	// Line 1384, Address: 0x201cb8, Func Offset: 0x268
	// Line 1383, Address: 0x201cbc, Func Offset: 0x26c
	// Line 1384, Address: 0x201cc0, Func Offset: 0x270
	// Line 1385, Address: 0x201cc4, Func Offset: 0x274
	// Line 1386, Address: 0x201ccc, Func Offset: 0x27c
	// Line 1388, Address: 0x201cdc, Func Offset: 0x28c
	// Line 1387, Address: 0x201ce0, Func Offset: 0x290
	// Line 1388, Address: 0x201ce4, Func Offset: 0x294
	// Line 1389, Address: 0x201ce8, Func Offset: 0x298
	// Line 1390, Address: 0x201d00, Func Offset: 0x2b0
	// Line 1393, Address: 0x201d18, Func Offset: 0x2c8
	// Line 1395, Address: 0x201d28, Func Offset: 0x2d8
	// Line 1397, Address: 0x201d34, Func Offset: 0x2e4
	// Line 1403, Address: 0x201d40, Func Offset: 0x2f0
	// Line 1404, Address: 0x201d44, Func Offset: 0x2f4
	// Line 1410, Address: 0x201d4c, Func Offset: 0x2fc
	// Line 1403, Address: 0x201d54, Func Offset: 0x304
	// Line 1404, Address: 0x201d58, Func Offset: 0x308
	// Line 1410, Address: 0x201d5c, Func Offset: 0x30c
	// Line 1404, Address: 0x201d60, Func Offset: 0x310
	// Line 1405, Address: 0x201d64, Func Offset: 0x314
	// Line 1406, Address: 0x201d6c, Func Offset: 0x31c
	// Line 1407, Address: 0x201d78, Func Offset: 0x328
	// Line 1408, Address: 0x201d84, Func Offset: 0x334
	// Line 1410, Address: 0x201d8c, Func Offset: 0x33c
	// Line 1412, Address: 0x201da4, Func Offset: 0x354
	// Line 1413, Address: 0x201db0, Func Offset: 0x360
	// Line 1418, Address: 0x201dbc, Func Offset: 0x36c
	// Line 1419, Address: 0x201dd0, Func Offset: 0x380
	// Line 1427, Address: 0x201ddc, Func Offset: 0x38c
	// Line 1428, Address: 0x201dec, Func Offset: 0x39c
	// Line 1430, Address: 0x201df4, Func Offset: 0x3a4
	// Line 1429, Address: 0x201df8, Func Offset: 0x3a8
	// Line 1430, Address: 0x201dfc, Func Offset: 0x3ac
	// Line 1431, Address: 0x201e00, Func Offset: 0x3b0
	// Line 1434, Address: 0x201e04, Func Offset: 0x3b4
	// Line 1435, Address: 0x201e10, Func Offset: 0x3c0
	// Line 1438, Address: 0x201e18, Func Offset: 0x3c8
	// Line 1439, Address: 0x201e2c, Func Offset: 0x3dc
	// Line 1440, Address: 0x201e30, Func Offset: 0x3e0
	// Line 1443, Address: 0x201e34, Func Offset: 0x3e4
	// Line 1444, Address: 0x201e3c, Func Offset: 0x3ec
	// Line 1447, Address: 0x201e44, Func Offset: 0x3f4
	// Func End, Address: 0x201e54, Func Offset: 0x404
}

// 100% matching!
void bhEne23_MV04()
{

}

// 
// Start address: 0x201e70
void bhEne23_MV05(BH_PWORK* epw)
{
	int mtn[2] = { 3, 24 };
	// Line 1468, Address: 0x201e70, Func Offset: 0
	// Line 1469, Address: 0x201e74, Func Offset: 0x4
	// Line 1468, Address: 0x201e78, Func Offset: 0x8
	// Line 1469, Address: 0x201e80, Func Offset: 0x10
	// Line 1471, Address: 0x201e90, Func Offset: 0x20
	// Line 1473, Address: 0x201eb0, Func Offset: 0x40
	// Line 1476, Address: 0x201ec0, Func Offset: 0x50
	// Line 1477, Address: 0x201ed4, Func Offset: 0x64
	// Line 1478, Address: 0x201ef0, Func Offset: 0x80
	// Line 1479, Address: 0x201ef8, Func Offset: 0x88
	// Line 1480, Address: 0x201f18, Func Offset: 0xa8
	// Line 1483, Address: 0x201f24, Func Offset: 0xb4
	// Line 1482, Address: 0x201f28, Func Offset: 0xb8
	// Line 1483, Address: 0x201f2c, Func Offset: 0xbc
	// Line 1484, Address: 0x201f30, Func Offset: 0xc0
	// Line 1485, Address: 0x201f38, Func Offset: 0xc8
	// Line 1488, Address: 0x201f40, Func Offset: 0xd0
	// Line 1489, Address: 0x201f48, Func Offset: 0xd8
	// Line 1490, Address: 0x201f4c, Func Offset: 0xdc
	// Line 1494, Address: 0x201f50, Func Offset: 0xe0
	// Line 1488, Address: 0x201f54, Func Offset: 0xe4
	// Line 1489, Address: 0x201f5c, Func Offset: 0xec
	// Line 1490, Address: 0x201f68, Func Offset: 0xf8
	// Line 1491, Address: 0x201f74, Func Offset: 0x104
	// Line 1494, Address: 0x201f80, Func Offset: 0x110
	// Line 1496, Address: 0x201f8c, Func Offset: 0x11c
	// Line 1497, Address: 0x201fac, Func Offset: 0x13c
	// Line 1498, Address: 0x201fb4, Func Offset: 0x144
	// Line 1500, Address: 0x201fbc, Func Offset: 0x14c
	// Line 1501, Address: 0x201fc8, Func Offset: 0x158
	// Line 1503, Address: 0x201fd8, Func Offset: 0x168
	// Line 1506, Address: 0x201fec, Func Offset: 0x17c
	// Line 1507, Address: 0x201ff4, Func Offset: 0x184
	// Line 1509, Address: 0x202000, Func Offset: 0x190
	// Line 1511, Address: 0x20200c, Func Offset: 0x19c
	// Line 1509, Address: 0x202010, Func Offset: 0x1a0
	// Line 1511, Address: 0x202018, Func Offset: 0x1a8
	// Line 1512, Address: 0x20201c, Func Offset: 0x1ac
	// Line 1513, Address: 0x202020, Func Offset: 0x1b0
	// Line 1516, Address: 0x202024, Func Offset: 0x1b4
	// Line 1517, Address: 0x202030, Func Offset: 0x1c0
	// Line 1519, Address: 0x202038, Func Offset: 0x1c8
	// Line 1518, Address: 0x20203c, Func Offset: 0x1cc
	// Line 1519, Address: 0x202040, Func Offset: 0x1d0
	// Line 1520, Address: 0x202044, Func Offset: 0x1d4
	// Line 1521, Address: 0x20204c, Func Offset: 0x1dc
	// Line 1522, Address: 0x202054, Func Offset: 0x1e4
	// Line 1524, Address: 0x20205c, Func Offset: 0x1ec
	// Line 1523, Address: 0x202060, Func Offset: 0x1f0
	// Line 1524, Address: 0x202064, Func Offset: 0x1f4
	// Line 1525, Address: 0x202068, Func Offset: 0x1f8
	// Line 1527, Address: 0x202070, Func Offset: 0x200
	// Line 1530, Address: 0x202078, Func Offset: 0x208
	// Line 1531, Address: 0x20207c, Func Offset: 0x20c
	// Line 1535, Address: 0x202084, Func Offset: 0x214
	// Line 1534, Address: 0x202088, Func Offset: 0x218
	// Line 1535, Address: 0x20208c, Func Offset: 0x21c
	// Line 1530, Address: 0x202090, Func Offset: 0x220
	// Line 1531, Address: 0x202098, Func Offset: 0x228
	// Line 1538, Address: 0x20209c, Func Offset: 0x22c
	// Line 1531, Address: 0x2020a0, Func Offset: 0x230
	// Line 1534, Address: 0x2020a8, Func Offset: 0x238
	// Line 1535, Address: 0x2020b4, Func Offset: 0x244
	// Line 1538, Address: 0x2020bc, Func Offset: 0x24c
	// Line 1541, Address: 0x2020c8, Func Offset: 0x258
	// Line 1538, Address: 0x2020cc, Func Offset: 0x25c
	// Line 1541, Address: 0x2020d0, Func Offset: 0x260
	// Line 1545, Address: 0x2020d8, Func Offset: 0x268
	// Func End, Address: 0x2020e8, Func Offset: 0x278
}

// 
// Start address: 0x2020f0
void bhEne23_MV06(BH_PWORK* epw)
{
	int mtn[2] = { 2, 22 };
	int mno;
	// Line 1555, Address: 0x2020f0, Func Offset: 0
	// Line 1556, Address: 0x2020f4, Func Offset: 0x4
	// Line 1555, Address: 0x2020f8, Func Offset: 0x8
	// Line 1556, Address: 0x202100, Func Offset: 0x10
	// Line 1558, Address: 0x202114, Func Offset: 0x24
	// Line 1561, Address: 0x202134, Func Offset: 0x44
	// Line 1562, Address: 0x202138, Func Offset: 0x48
	// Line 1561, Address: 0x20213c, Func Offset: 0x4c
	// Line 1562, Address: 0x202148, Func Offset: 0x58
	// Line 1563, Address: 0x202150, Func Offset: 0x60
	// Line 1565, Address: 0x202154, Func Offset: 0x64
	// Line 1564, Address: 0x202158, Func Offset: 0x68
	// Line 1565, Address: 0x20215c, Func Offset: 0x6c
	// Line 1566, Address: 0x202160, Func Offset: 0x70
	// Line 1568, Address: 0x202168, Func Offset: 0x78
	// Line 1570, Address: 0x202170, Func Offset: 0x80
	// Line 1572, Address: 0x202174, Func Offset: 0x84
	// Line 1568, Address: 0x202178, Func Offset: 0x88
	// Line 1570, Address: 0x202180, Func Offset: 0x90
	// Line 1571, Address: 0x202184, Func Offset: 0x94
	// Line 1572, Address: 0x2021a8, Func Offset: 0xb8
	// Line 1573, Address: 0x2021ac, Func Offset: 0xbc
	// Line 1575, Address: 0x2021b8, Func Offset: 0xc8
	// Line 1579, Address: 0x2021c4, Func Offset: 0xd4
	// Line 1581, Address: 0x2021dc, Func Offset: 0xec
	// Line 1584, Address: 0x202210, Func Offset: 0x120
	// Line 1585, Address: 0x202230, Func Offset: 0x140
	// Line 1587, Address: 0x202250, Func Offset: 0x160
	// Line 1588, Address: 0x202258, Func Offset: 0x168
	// Line 1590, Address: 0x202260, Func Offset: 0x170
	// Line 1589, Address: 0x202264, Func Offset: 0x174
	// Line 1590, Address: 0x202268, Func Offset: 0x178
	// Line 1591, Address: 0x20226c, Func Offset: 0x17c
	// Line 1595, Address: 0x202270, Func Offset: 0x180
	// Func End, Address: 0x202280, Func Offset: 0x190
}

// 100% matching!
void bhEne23_MV07()
{

}

// 100% matching!
void bhEne23_MV08()
{

}

// 
// Start address: 0x2022a0
void bhEne23_MV09(BH_PWORK* epw)
{
	// Line 1627, Address: 0x2022a0, Func Offset: 0
	// Line 1628, Address: 0x2022a8, Func Offset: 0x8
	// Line 1630, Address: 0x2022c8, Func Offset: 0x28
	// Line 1632, Address: 0x2022d0, Func Offset: 0x30
	// Line 1631, Address: 0x2022d4, Func Offset: 0x34
	// Line 1632, Address: 0x2022d8, Func Offset: 0x38
	// Line 1633, Address: 0x2022dc, Func Offset: 0x3c
	// Line 1634, Address: 0x2022e4, Func Offset: 0x44
	// Line 1636, Address: 0x2022ec, Func Offset: 0x4c
	// Line 1638, Address: 0x2022fc, Func Offset: 0x5c
	// Line 1639, Address: 0x202320, Func Offset: 0x80
	// Line 1641, Address: 0x20232c, Func Offset: 0x8c
	// Line 1642, Address: 0x20233c, Func Offset: 0x9c
	// Line 1643, Address: 0x202344, Func Offset: 0xa4
	// Line 1644, Address: 0x202348, Func Offset: 0xa8
	// Line 1645, Address: 0x20234c, Func Offset: 0xac
	// Line 1649, Address: 0x202350, Func Offset: 0xb0
	// Line 1650, Address: 0x202378, Func Offset: 0xd8
	// Line 1655, Address: 0x202380, Func Offset: 0xe0
	// Func End, Address: 0x20238c, Func Offset: 0xec
}

// 
// Start address: 0x202390
void bhEne23_MV10(BH_PWORK* epw)
{
	int mtn[2][2] = { { 10, 12 }, { 27, 28 } };
	NJS_POINT3 pos;
	// Line 1665, Address: 0x202390, Func Offset: 0
	// Line 1667, Address: 0x20239c, Func Offset: 0xc
	// Line 1665, Address: 0x2023a0, Func Offset: 0x10
	// Line 1667, Address: 0x2023a4, Func Offset: 0x14
	// Line 1665, Address: 0x2023a8, Func Offset: 0x18
	// Line 1667, Address: 0x2023ac, Func Offset: 0x1c
	// Line 1672, Address: 0x2023bc, Func Offset: 0x2c
	// Line 1674, Address: 0x2023dc, Func Offset: 0x4c
	// Line 1675, Address: 0x2023ec, Func Offset: 0x5c
	// Line 1676, Address: 0x2023fc, Func Offset: 0x6c
	// Line 1677, Address: 0x202404, Func Offset: 0x74
	// Line 1680, Address: 0x202418, Func Offset: 0x88
	// Line 1679, Address: 0x20241c, Func Offset: 0x8c
	// Line 1680, Address: 0x202420, Func Offset: 0x90
	// Line 1681, Address: 0x202424, Func Offset: 0x94
	// Line 1682, Address: 0x20242c, Func Offset: 0x9c
	// Line 1684, Address: 0x202434, Func Offset: 0xa4
	// Line 1686, Address: 0x202448, Func Offset: 0xb8
	// Line 1687, Address: 0x20246c, Func Offset: 0xdc
	// Line 1689, Address: 0x202478, Func Offset: 0xe8
	// Line 1690, Address: 0x202488, Func Offset: 0xf8
	// Line 1692, Address: 0x202494, Func Offset: 0x104
	// Line 1693, Address: 0x20249c, Func Offset: 0x10c
	// Line 1694, Address: 0x2024a0, Func Offset: 0x110
	// Line 1696, Address: 0x2024a4, Func Offset: 0x114
	// Line 1698, Address: 0x2024ac, Func Offset: 0x11c
	// Line 1699, Address: 0x2024b0, Func Offset: 0x120
	// Line 1700, Address: 0x2024b4, Func Offset: 0x124
	// Line 1701, Address: 0x2024b8, Func Offset: 0x128
	// Line 1708, Address: 0x2024bc, Func Offset: 0x12c
	// Line 1711, Address: 0x2024c0, Func Offset: 0x130
	// Line 1708, Address: 0x2024c4, Func Offset: 0x134
	// Line 1711, Address: 0x2024c8, Func Offset: 0x138
	// Line 1714, Address: 0x2024f8, Func Offset: 0x168
	// Line 1716, Address: 0x202500, Func Offset: 0x170
	// Line 1719, Address: 0x202564, Func Offset: 0x1d4
	// Line 1720, Address: 0x202568, Func Offset: 0x1d8
	// Line 1719, Address: 0x20256c, Func Offset: 0x1dc
	// Line 1721, Address: 0x202570, Func Offset: 0x1e0
	// Line 1720, Address: 0x202574, Func Offset: 0x1e4
	// Line 1721, Address: 0x202578, Func Offset: 0x1e8
	// Line 1722, Address: 0x20257c, Func Offset: 0x1ec
	// Line 1723, Address: 0x202594, Func Offset: 0x204
	// Line 1729, Address: 0x2025b4, Func Offset: 0x224
	// Line 1730, Address: 0x2025c8, Func Offset: 0x238
	// Line 1740, Address: 0x2025e8, Func Offset: 0x258
	// Line 1737, Address: 0x2025ec, Func Offset: 0x25c
	// Line 1740, Address: 0x2025f0, Func Offset: 0x260
	// Line 1730, Address: 0x2025f4, Func Offset: 0x264
	// Line 1737, Address: 0x2025fc, Func Offset: 0x26c
	// Line 1738, Address: 0x202600, Func Offset: 0x270
	// Line 1739, Address: 0x202604, Func Offset: 0x274
	// Line 1740, Address: 0x202608, Func Offset: 0x278
	// Line 1741, Address: 0x202618, Func Offset: 0x288
	// Line 1747, Address: 0x202638, Func Offset: 0x2a8
	// Line 1741, Address: 0x202644, Func Offset: 0x2b4
	// Line 1747, Address: 0x202648, Func Offset: 0x2b8
	// Line 1748, Address: 0x202654, Func Offset: 0x2c4
	// Line 1754, Address: 0x20267c, Func Offset: 0x2ec
	// Line 1756, Address: 0x202688, Func Offset: 0x2f8
	// Line 1759, Address: 0x20268c, Func Offset: 0x2fc
	// Line 1756, Address: 0x202694, Func Offset: 0x304
	// Line 1759, Address: 0x2026a0, Func Offset: 0x310
	// Line 1761, Address: 0x2026ac, Func Offset: 0x31c
	// Line 1762, Address: 0x2026c8, Func Offset: 0x338
	// Line 1765, Address: 0x2026d4, Func Offset: 0x344
	// Line 1766, Address: 0x2026e4, Func Offset: 0x354
	// Line 1765, Address: 0x2026e8, Func Offset: 0x358
	// Line 1766, Address: 0x2026f0, Func Offset: 0x360
	// Line 1768, Address: 0x2026f8, Func Offset: 0x368
	// Line 1766, Address: 0x2026fc, Func Offset: 0x36c
	// Line 1768, Address: 0x202704, Func Offset: 0x374
	// Line 1769, Address: 0x202714, Func Offset: 0x384
	// Line 1770, Address: 0x20272c, Func Offset: 0x39c
	// Line 1772, Address: 0x20273c, Func Offset: 0x3ac
	// Line 1773, Address: 0x202748, Func Offset: 0x3b8
	// Line 1772, Address: 0x20274c, Func Offset: 0x3bc
	// Line 1773, Address: 0x202750, Func Offset: 0x3c0
	// Line 1774, Address: 0x20275c, Func Offset: 0x3cc
	// Line 1775, Address: 0x202768, Func Offset: 0x3d8
	// Line 1776, Address: 0x202794, Func Offset: 0x404
	// Line 1777, Address: 0x20279c, Func Offset: 0x40c
	// Line 1778, Address: 0x2027a4, Func Offset: 0x414
	// Line 1780, Address: 0x2027ac, Func Offset: 0x41c
	// Line 1782, Address: 0x2027b4, Func Offset: 0x424
	// Line 1783, Address: 0x2027c0, Func Offset: 0x430
	// Line 1784, Address: 0x2027cc, Func Offset: 0x43c
	// Line 1785, Address: 0x2027d8, Func Offset: 0x448
	// Line 1786, Address: 0x202804, Func Offset: 0x474
	// Line 1787, Address: 0x20280c, Func Offset: 0x47c
	// Line 1788, Address: 0x202814, Func Offset: 0x484
	// Line 1794, Address: 0x202820, Func Offset: 0x490
	// Func End, Address: 0x202838, Func Offset: 0x4a8
}

// 
// Start address: 0x202840
void bhEne23_MV11(BH_PWORK* epw)
{
	NJS_POINT3 trans;
	int mtn[2][2] = { { 37, 0 }, { 42, 53 } };
	// Line 1804, Address: 0x202840, Func Offset: 0
	// Line 1805, Address: 0x202844, Func Offset: 0x4
	// Line 1804, Address: 0x202848, Func Offset: 0x8
	// Line 1805, Address: 0x202850, Func Offset: 0x10
	// Line 1810, Address: 0x20285c, Func Offset: 0x1c
	// Line 1805, Address: 0x202860, Func Offset: 0x20
	// Line 1810, Address: 0x202864, Func Offset: 0x24
	// Line 1812, Address: 0x202880, Func Offset: 0x40
	// Line 1814, Address: 0x202884, Func Offset: 0x44
	// Line 1817, Address: 0x202888, Func Offset: 0x48
	// Line 1820, Address: 0x20288c, Func Offset: 0x4c
	// Line 1821, Address: 0x202890, Func Offset: 0x50
	// Line 1812, Address: 0x202894, Func Offset: 0x54
	// Line 1813, Address: 0x2028a4, Func Offset: 0x64
	// Line 1814, Address: 0x2028a8, Func Offset: 0x68
	// Line 1817, Address: 0x2028ac, Func Offset: 0x6c
	// Line 1821, Address: 0x2028b0, Func Offset: 0x70
	// Line 1822, Address: 0x2028b4, Func Offset: 0x74
	// Line 1817, Address: 0x2028b8, Func Offset: 0x78
	// Line 1818, Address: 0x2028bc, Func Offset: 0x7c
	// Line 1820, Address: 0x2028c0, Func Offset: 0x80
	// Line 1821, Address: 0x2028cc, Func Offset: 0x8c
	// Line 1822, Address: 0x2028d8, Func Offset: 0x98
	// Line 1824, Address: 0x2028e4, Func Offset: 0xa4
	// Line 1825, Address: 0x2028ec, Func Offset: 0xac
	// Line 1827, Address: 0x2028f4, Func Offset: 0xb4
	// Line 1828, Address: 0x202900, Func Offset: 0xc0
	// Line 1829, Address: 0x202904, Func Offset: 0xc4
	// Line 1833, Address: 0x202908, Func Offset: 0xc8
	// Line 1830, Address: 0x20290c, Func Offset: 0xcc
	// Line 1833, Address: 0x202910, Func Offset: 0xd0
	// Line 1835, Address: 0x202920, Func Offset: 0xe0
	// Line 1836, Address: 0x202934, Func Offset: 0xf4
	// Line 1843, Address: 0x202938, Func Offset: 0xf8
	// Line 1844, Address: 0x202964, Func Offset: 0x124
	// Line 1847, Address: 0x202970, Func Offset: 0x130
	// Line 1848, Address: 0x202978, Func Offset: 0x138
	// Line 1849, Address: 0x202988, Func Offset: 0x148
	// Line 1851, Address: 0x202994, Func Offset: 0x154
	// Line 1854, Address: 0x2029a0, Func Offset: 0x160
	// Line 1857, Address: 0x2029a4, Func Offset: 0x164
	// Line 1858, Address: 0x2029ac, Func Offset: 0x16c
	// Line 1854, Address: 0x2029b0, Func Offset: 0x170
	// Line 1857, Address: 0x2029b4, Func Offset: 0x174
	// Line 1858, Address: 0x2029bc, Func Offset: 0x17c
	// Line 1861, Address: 0x2029c8, Func Offset: 0x188
	// Line 1863, Address: 0x2029cc, Func Offset: 0x18c
	// Line 1858, Address: 0x2029d0, Func Offset: 0x190
	// Line 1859, Address: 0x2029d4, Func Offset: 0x194
	// Line 1860, Address: 0x2029e4, Func Offset: 0x1a4
	// Line 1861, Address: 0x2029f0, Func Offset: 0x1b0
	// Line 1863, Address: 0x2029fc, Func Offset: 0x1bc
	// Line 1867, Address: 0x202a08, Func Offset: 0x1c8
	// Func End, Address: 0x202a18, Func Offset: 0x1d8
}

// 
// Start address: 0x202a20
void bhEne23_MV12(BH_PWORK* epw)
{
	NJS_POINT3 trans;
	int mtn[2] = { 0, 53 };
	// Line 1877, Address: 0x202a20, Func Offset: 0
	// Line 1878, Address: 0x202a24, Func Offset: 0x4
	// Line 1877, Address: 0x202a28, Func Offset: 0x8
	// Line 1878, Address: 0x202a30, Func Offset: 0x10
	// Line 1882, Address: 0x202a3c, Func Offset: 0x1c
	// Line 1878, Address: 0x202a44, Func Offset: 0x24
	// Line 1881, Address: 0x202a48, Func Offset: 0x28
	// Line 1883, Address: 0x202a4c, Func Offset: 0x2c
	// Line 1884, Address: 0x202a54, Func Offset: 0x34
	// Line 1886, Address: 0x202a58, Func Offset: 0x38
	// Line 1881, Address: 0x202a5c, Func Offset: 0x3c
	// Line 1882, Address: 0x202a64, Func Offset: 0x44
	// Line 1883, Address: 0x202a70, Func Offset: 0x50
	// Line 1884, Address: 0x202a7c, Func Offset: 0x5c
	// Line 1885, Address: 0x202a88, Func Offset: 0x68
	// Line 1886, Address: 0x202a94, Func Offset: 0x74
	// Line 1889, Address: 0x202aa0, Func Offset: 0x80
	// Line 1890, Address: 0x202aa8, Func Offset: 0x88
	// Line 1893, Address: 0x202abc, Func Offset: 0x9c
	// Line 1898, Address: 0x202ac0, Func Offset: 0xa0
	// Line 1899, Address: 0x202ac4, Func Offset: 0xa4
	// Line 1893, Address: 0x202ac8, Func Offset: 0xa8
	// Line 1896, Address: 0x202ad0, Func Offset: 0xb0
	// Line 1897, Address: 0x202ae4, Func Offset: 0xc4
	// Line 1898, Address: 0x202ae8, Func Offset: 0xc8
	// Line 1899, Address: 0x202aec, Func Offset: 0xcc
	// Line 1907, Address: 0x202af8, Func Offset: 0xd8
	// Line 1908, Address: 0x202b24, Func Offset: 0x104
	// Line 1910, Address: 0x202b30, Func Offset: 0x110
	// Line 1918, Address: 0x202b34, Func Offset: 0x114
	// Line 1910, Address: 0x202b3c, Func Offset: 0x11c
	// Line 1911, Address: 0x202b40, Func Offset: 0x120
	// Line 1912, Address: 0x202b48, Func Offset: 0x128
	// Line 1918, Address: 0x202b50, Func Offset: 0x130
	// Line 1919, Address: 0x202b6c, Func Offset: 0x14c
	// Line 1920, Address: 0x202b70, Func Offset: 0x150
	// Line 1921, Address: 0x202b78, Func Offset: 0x158
	// Line 1926, Address: 0x202b84, Func Offset: 0x164
	// Line 1929, Address: 0x202b8c, Func Offset: 0x16c
	// Line 1932, Address: 0x202b98, Func Offset: 0x178
	// Line 1929, Address: 0x202b9c, Func Offset: 0x17c
	// Line 1932, Address: 0x202ba0, Func Offset: 0x180
	// Line 1933, Address: 0x202ba4, Func Offset: 0x184
	// Line 1934, Address: 0x202ba8, Func Offset: 0x188
	// Line 1935, Address: 0x202bac, Func Offset: 0x18c
	// Line 1938, Address: 0x202bb0, Func Offset: 0x190
	// Line 1939, Address: 0x202bc0, Func Offset: 0x1a0
	// Line 1940, Address: 0x202bc8, Func Offset: 0x1a8
	// Line 1941, Address: 0x202bd0, Func Offset: 0x1b0
	// Line 1943, Address: 0x202bd4, Func Offset: 0x1b4
	// Line 1940, Address: 0x202bd8, Func Offset: 0x1b8
	// Line 1941, Address: 0x202be0, Func Offset: 0x1c0
	// Line 1942, Address: 0x202bec, Func Offset: 0x1cc
	// Line 1944, Address: 0x202bf8, Func Offset: 0x1d8
	// Line 1945, Address: 0x202c00, Func Offset: 0x1e0
	// Line 1949, Address: 0x202c14, Func Offset: 0x1f4
	// Line 1950, Address: 0x202c24, Func Offset: 0x204
	// Line 1951, Address: 0x202c2c, Func Offset: 0x20c
	// Line 1952, Address: 0x202c34, Func Offset: 0x214
	// Line 1956, Address: 0x202c40, Func Offset: 0x220
	// Line 1957, Address: 0x202c50, Func Offset: 0x230
	// Line 1958, Address: 0x202c60, Func Offset: 0x240
	// Line 1960, Address: 0x202c70, Func Offset: 0x250
	// Func End, Address: 0x202c80, Func Offset: 0x260
}

// 100% matching!
void bhEne23_Nage(BH_PWORK* epw)
{
	bhEne23_NageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne23_NG00()
{

}

// 100% matching!
void bhEne23_Damage(BH_PWORK* epw)
{
    if ((epw->flg & 0x4))
    {
        epw->flg &= ~0x4;
        
        epw->comb_flg &= ~0xC;

        if (bhEne03_DGDirCheck(epw) != 0) 
        {
            epw->comb_flg |= 0x8;
        } 
        else 
        {
            epw->comb_flg |= 0x4;
        }

        bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl);
        
        if ((epw->wpnr_no != 16) || ((epw->flg2 & 0x4)) || (epw->comb_pnt == 1)) 
        {
            if (epw->total_dam != 0) 
            {
                if (epw->type == 0) 
                {
                    if ((epw->comb_flg & 0x8)) 
                    {
                        EXP0_I(276) -= epw->total_dam;
        
                        epw->hp -= epw->total_dam;
                    } 
                    else 
                    {
                        epw->hp -= epw->total_dam;
                    }
                } 
                else
                {
                    epw->hp -= epw->total_dam;
                }
            }
        
            if ((epw->wpnr_no != 17) || ((epw->flg2 & 0x4))) 
            {
                bhEne23_HitMark(epw);
            } 
        }
    }
    
    bhEne23_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne23_DG00()
{

}

// 
// Start address: 0x202e30
void bhEne23_DG01(BH_PWORK* epw)
{
	int mtn[2][2] = { { 14, 18 }, { 29, 33 } };
	// Line 2059, Address: 0x202e30, Func Offset: 0
	// Line 2060, Address: 0x202e38, Func Offset: 0x8
	// Line 2059, Address: 0x202e3c, Func Offset: 0xc
	// Line 2060, Address: 0x202e44, Func Offset: 0x14
	// Line 2065, Address: 0x202e54, Func Offset: 0x24
	// Line 2067, Address: 0x202e74, Func Offset: 0x44
	// Line 2068, Address: 0x202e84, Func Offset: 0x54
	// Line 2069, Address: 0x202e9c, Func Offset: 0x6c
	// Line 2070, Address: 0x202ea4, Func Offset: 0x74
	// Line 2073, Address: 0x202ec0, Func Offset: 0x90
	// Line 2072, Address: 0x202ec4, Func Offset: 0x94
	// Line 2073, Address: 0x202ec8, Func Offset: 0x98
	// Line 2074, Address: 0x202ecc, Func Offset: 0x9c
	// Line 2075, Address: 0x202ed4, Func Offset: 0xa4
	// Line 2077, Address: 0x202edc, Func Offset: 0xac
	// Line 2079, Address: 0x202eec, Func Offset: 0xbc
	// Line 2080, Address: 0x202f10, Func Offset: 0xe0
	// Line 2082, Address: 0x202f1c, Func Offset: 0xec
	// Line 2083, Address: 0x202f2c, Func Offset: 0xfc
	// Line 2084, Address: 0x202f34, Func Offset: 0x104
	// Line 2085, Address: 0x202f38, Func Offset: 0x108
	// Line 2086, Address: 0x202f3c, Func Offset: 0x10c
	// Line 2087, Address: 0x202f40, Func Offset: 0x110
	// Line 2090, Address: 0x202f50, Func Offset: 0x120
	// Line 2091, Address: 0x202f60, Func Offset: 0x130
	// Line 2097, Address: 0x202f78, Func Offset: 0x148
	// Line 2098, Address: 0x202f80, Func Offset: 0x150
	// Func End, Address: 0x202f94, Func Offset: 0x164
}

// 100% matching!
void bhEne23_DG02()
{

}

// 
// Start address: 0x202fb0
void bhEne23_DG03(BH_PWORK* epw)
{
	int mtn[2] = { 16, 31 };
	// Line 2119, Address: 0x202fb0, Func Offset: 0
	// Line 2120, Address: 0x202fb8, Func Offset: 0x8
	// Line 2119, Address: 0x202fbc, Func Offset: 0xc
	// Line 2120, Address: 0x202fc4, Func Offset: 0x14
	// Line 2122, Address: 0x202fd4, Func Offset: 0x24
	// Line 2124, Address: 0x202ff4, Func Offset: 0x44
	// Line 2126, Address: 0x203008, Func Offset: 0x58
	// Line 2127, Address: 0x20300c, Func Offset: 0x5c
	// Line 2128, Address: 0x203010, Func Offset: 0x60
	// Line 2130, Address: 0x203014, Func Offset: 0x64
	// Line 2124, Address: 0x203018, Func Offset: 0x68
	// Line 2125, Address: 0x203020, Func Offset: 0x70
	// Line 2126, Address: 0x203024, Func Offset: 0x74
	// Line 2127, Address: 0x203028, Func Offset: 0x78
	// Line 2128, Address: 0x20302c, Func Offset: 0x7c
	// Line 2130, Address: 0x203030, Func Offset: 0x80
	// Line 2132, Address: 0x20303c, Func Offset: 0x8c
	// Line 2133, Address: 0x203060, Func Offset: 0xb0
	// Line 2135, Address: 0x20306c, Func Offset: 0xbc
	// Line 2136, Address: 0x20307c, Func Offset: 0xcc
	// Line 2137, Address: 0x203084, Func Offset: 0xd4
	// Line 2138, Address: 0x203088, Func Offset: 0xd8
	// Line 2139, Address: 0x20308c, Func Offset: 0xdc
	// Line 2140, Address: 0x203090, Func Offset: 0xe0
	// Line 2143, Address: 0x2030a0, Func Offset: 0xf0
	// Line 2144, Address: 0x2030b0, Func Offset: 0x100
	// Line 2150, Address: 0x2030c8, Func Offset: 0x118
	// Line 2151, Address: 0x2030d0, Func Offset: 0x120
	// Func End, Address: 0x2030e4, Func Offset: 0x134
}

// 
// Start address: 0x2030f0
void bhEne23_DG04(BH_PWORK* epw)
{
	O_WORK* owk;
	NJS_POINT3 pos;
	int i;
	// Line 2161, Address: 0x2030f0, Func Offset: 0
	// Line 2166, Address: 0x20310c, Func Offset: 0x1c
	// Line 2168, Address: 0x20312c, Func Offset: 0x3c
	// Line 2170, Address: 0x203134, Func Offset: 0x44
	// Line 2169, Address: 0x203138, Func Offset: 0x48
	// Line 2170, Address: 0x20313c, Func Offset: 0x4c
	// Line 2171, Address: 0x203140, Func Offset: 0x50
	// Line 2172, Address: 0x203148, Func Offset: 0x58
	// Line 2174, Address: 0x203150, Func Offset: 0x60
	// Line 2181, Address: 0x203158, Func Offset: 0x68
	// Line 2174, Address: 0x20315c, Func Offset: 0x6c
	// Line 2176, Address: 0x203164, Func Offset: 0x74
	// Line 2177, Address: 0x203188, Func Offset: 0x98
	// Line 2178, Address: 0x20318c, Func Offset: 0x9c
	// Line 2181, Address: 0x203194, Func Offset: 0xa4
	// Line 2182, Address: 0x20319c, Func Offset: 0xac
	// Line 2183, Address: 0x2031a8, Func Offset: 0xb8
	// Line 2184, Address: 0x2031b4, Func Offset: 0xc4
	// Line 2187, Address: 0x2031bc, Func Offset: 0xcc
	// Line 2191, Address: 0x2031c0, Func Offset: 0xd0
	// Line 2189, Address: 0x2031c4, Func Offset: 0xd4
	// Line 2187, Address: 0x2031cc, Func Offset: 0xdc
	// Line 2190, Address: 0x2031d0, Func Offset: 0xe0
	// Line 2191, Address: 0x2031d8, Func Offset: 0xe8
	// Line 2187, Address: 0x2031dc, Func Offset: 0xec
	// Line 2188, Address: 0x2031e0, Func Offset: 0xf0
	// Line 2189, Address: 0x2031e4, Func Offset: 0xf4
	// Line 2191, Address: 0x2031e8, Func Offset: 0xf8
	// Line 2192, Address: 0x2031f4, Func Offset: 0x104
	// Line 2193, Address: 0x20320c, Func Offset: 0x11c
	// Line 2196, Address: 0x203224, Func Offset: 0x134
	// Line 2197, Address: 0x203238, Func Offset: 0x148
	// Line 2198, Address: 0x20324c, Func Offset: 0x15c
	// Line 2201, Address: 0x203260, Func Offset: 0x170
	// Line 2202, Address: 0x203264, Func Offset: 0x174
	// Line 2203, Address: 0x20326c, Func Offset: 0x17c
	// Line 2204, Address: 0x2032ac, Func Offset: 0x1bc
	// Line 2205, Address: 0x2032f0, Func Offset: 0x200
	// Line 2206, Address: 0x203314, Func Offset: 0x224
	// Line 2205, Address: 0x203318, Func Offset: 0x228
	// Line 2206, Address: 0x203328, Func Offset: 0x238
	// Line 2205, Address: 0x203330, Func Offset: 0x240
	// Line 2206, Address: 0x203348, Func Offset: 0x258
	// Line 2207, Address: 0x203350, Func Offset: 0x260
	// Line 2208, Address: 0x203368, Func Offset: 0x278
	// Line 2209, Address: 0x203380, Func Offset: 0x290
	// Line 2212, Address: 0x203390, Func Offset: 0x2a0
	// Line 2215, Address: 0x203398, Func Offset: 0x2a8
	// Line 2218, Address: 0x2033a0, Func Offset: 0x2b0
	// Line 2215, Address: 0x2033b0, Func Offset: 0x2c0
	// Line 2218, Address: 0x2033b8, Func Offset: 0x2c8
	// Line 2220, Address: 0x2033c0, Func Offset: 0x2d0
	// Line 2222, Address: 0x2033cc, Func Offset: 0x2dc
	// Line 2223, Address: 0x2033d4, Func Offset: 0x2e4
	// Line 2224, Address: 0x203414, Func Offset: 0x324
	// Line 2225, Address: 0x20345c, Func Offset: 0x36c
	// Line 2226, Address: 0x203494, Func Offset: 0x3a4
	// Line 2225, Address: 0x2034a0, Func Offset: 0x3b0
	// Line 2226, Address: 0x2034b8, Func Offset: 0x3c8
	// Line 2227, Address: 0x2034c0, Func Offset: 0x3d0
	// Line 2229, Address: 0x2034d8, Func Offset: 0x3e8
	// Line 2230, Address: 0x203518, Func Offset: 0x428
	// Line 2231, Address: 0x20355c, Func Offset: 0x46c
	// Line 2232, Address: 0x203578, Func Offset: 0x488
	// Line 2231, Address: 0x20357c, Func Offset: 0x48c
	// Line 2232, Address: 0x203580, Func Offset: 0x490
	// Line 2231, Address: 0x203584, Func Offset: 0x494
	// Line 2232, Address: 0x203594, Func Offset: 0x4a4
	// Line 2231, Address: 0x203598, Func Offset: 0x4a8
	// Line 2232, Address: 0x2035ac, Func Offset: 0x4bc
	// Line 2233, Address: 0x2035b4, Func Offset: 0x4c4
	// Line 2235, Address: 0x2035cc, Func Offset: 0x4dc
	// Line 2236, Address: 0x2035d0, Func Offset: 0x4e0
	// Line 2237, Address: 0x2035d8, Func Offset: 0x4e8
	// Line 2240, Address: 0x2035e0, Func Offset: 0x4f0
	// Line 2241, Address: 0x2035f0, Func Offset: 0x500
	// Line 2242, Address: 0x2035f8, Func Offset: 0x508
	// Line 2243, Address: 0x2035fc, Func Offset: 0x50c
	// Line 2244, Address: 0x203600, Func Offset: 0x510
	// Line 2245, Address: 0x203604, Func Offset: 0x514
	// Line 2248, Address: 0x203614, Func Offset: 0x524
	// Line 2249, Address: 0x203624, Func Offset: 0x534
	// Line 2255, Address: 0x20363c, Func Offset: 0x54c
	// Line 2256, Address: 0x203644, Func Offset: 0x554
	// Func End, Address: 0x203664, Func Offset: 0x574
}

// 100% matching!
void bhEne23_DG05()
{

}

// 
// Start address: 0x203680
void bhEne23_DG06(BH_PWORK* epw)
{
	// already reversed order from DWARF
	int mtn[2][2] = { { 40, 51 }, { 45, 52 } };
	NJS_POINT3* trans[2] = { spl_051, spl_052 };
	NJS_MKEY_A_MOD* mkaP;
	//NJS_MKEY_A_MOD* mkaP;
	//NJS_POINT3 trans;
	NJS_VECTOR v;
	NJS_VECTOR ov;
	float out;
	int ang;
	//NJS_MKEY_A_MOD* mkaP;
	// Line 2277, Address: 0x203680, Func Offset: 0
	// Line 2278, Address: 0x20368c, Func Offset: 0xc
	// Line 2277, Address: 0x203694, Func Offset: 0x14
	// Line 2278, Address: 0x203698, Func Offset: 0x18
	// Line 2282, Address: 0x2036a0, Func Offset: 0x20
	// Line 2278, Address: 0x2036ac, Func Offset: 0x2c
	// Line 2282, Address: 0x2036b0, Func Offset: 0x30
	// Line 2284, Address: 0x2036b8, Func Offset: 0x38
	// Line 2287, Address: 0x2036f0, Func Offset: 0x70
	// Line 2292, Address: 0x203700, Func Offset: 0x80
	// Line 2294, Address: 0x203704, Func Offset: 0x84
	// Line 2292, Address: 0x203708, Func Offset: 0x88
	// Line 2293, Address: 0x20370c, Func Offset: 0x8c
	// Line 2292, Address: 0x203710, Func Offset: 0x90
	// Line 2294, Address: 0x203724, Func Offset: 0xa4
	// Line 2292, Address: 0x203728, Func Offset: 0xa8
	// Line 2293, Address: 0x20372c, Func Offset: 0xac
	// Line 2294, Address: 0x20373c, Func Offset: 0xbc
	// Line 2295, Address: 0x203744, Func Offset: 0xc4
	// Line 2296, Address: 0x203760, Func Offset: 0xe0
	// Line 2297, Address: 0x203768, Func Offset: 0xe8
	// Line 2302, Address: 0x20377c, Func Offset: 0xfc
	// Line 2303, Address: 0x203790, Func Offset: 0x110
	// Line 2304, Address: 0x2037a8, Func Offset: 0x128
	// Line 2305, Address: 0x2037b0, Func Offset: 0x130
	// Line 2306, Address: 0x2037bc, Func Offset: 0x13c
	// Line 2307, Address: 0x2037c4, Func Offset: 0x144
	// Line 2308, Address: 0x2037cc, Func Offset: 0x14c
	// Line 2309, Address: 0x2037d4, Func Offset: 0x154
	// Line 2313, Address: 0x2037dc, Func Offset: 0x15c
	// Line 2316, Address: 0x2037e8, Func Offset: 0x168
	// Line 2322, Address: 0x2037ec, Func Offset: 0x16c
	// Line 2323, Address: 0x2037f0, Func Offset: 0x170
	// Line 2324, Address: 0x2037f4, Func Offset: 0x174
	// Line 2316, Address: 0x2037f8, Func Offset: 0x178
	// Line 2319, Address: 0x203800, Func Offset: 0x180
	// Line 2320, Address: 0x203814, Func Offset: 0x194
	// Line 2321, Address: 0x203818, Func Offset: 0x198
	// Line 2322, Address: 0x20381c, Func Offset: 0x19c
	// Line 2323, Address: 0x203828, Func Offset: 0x1a8
	// Line 2324, Address: 0x20382c, Func Offset: 0x1ac
	// Line 2330, Address: 0x203830, Func Offset: 0x1b0
	// Line 2331, Address: 0x203834, Func Offset: 0x1b4
	// Line 2330, Address: 0x203838, Func Offset: 0x1b8
	// Line 2331, Address: 0x203844, Func Offset: 0x1c4
	// Line 2330, Address: 0x203848, Func Offset: 0x1c8
	// Line 2331, Address: 0x203858, Func Offset: 0x1d8
	// Line 2332, Address: 0x203860, Func Offset: 0x1e0
	// Line 2333, Address: 0x203870, Func Offset: 0x1f0
	// Line 2342, Address: 0x203880, Func Offset: 0x200
	// Line 2343, Address: 0x2038ac, Func Offset: 0x22c
	// Line 2347, Address: 0x2038b8, Func Offset: 0x238
	// Line 2348, Address: 0x2038c4, Func Offset: 0x244
	// Line 2347, Address: 0x2038c8, Func Offset: 0x248
	// Line 2348, Address: 0x2038d0, Func Offset: 0x250
	// Line 2350, Address: 0x2038e0, Func Offset: 0x260
	// Line 2354, Address: 0x2038ec, Func Offset: 0x26c
	// Line 2355, Address: 0x2038f0, Func Offset: 0x270
	// Line 2356, Address: 0x2038f8, Func Offset: 0x278
	// Line 2357, Address: 0x203900, Func Offset: 0x280
	// Line 2354, Address: 0x203904, Func Offset: 0x284
	// Line 2355, Address: 0x20390c, Func Offset: 0x28c
	// Line 2357, Address: 0x203910, Func Offset: 0x290
	// Line 2360, Address: 0x203914, Func Offset: 0x294
	// Line 2361, Address: 0x203918, Func Offset: 0x298
	// Line 2363, Address: 0x20391c, Func Offset: 0x29c
	// Line 2365, Address: 0x203920, Func Offset: 0x2a0
	// Line 2355, Address: 0x203924, Func Offset: 0x2a4
	// Line 2356, Address: 0x20392c, Func Offset: 0x2ac
	// Line 2357, Address: 0x203938, Func Offset: 0x2b8
	// Line 2360, Address: 0x203944, Func Offset: 0x2c4
	// Line 2361, Address: 0x20394c, Func Offset: 0x2cc
	// Line 2363, Address: 0x203950, Func Offset: 0x2d0
	// Line 2365, Address: 0x20395c, Func Offset: 0x2dc
	// Line 2366, Address: 0x203960, Func Offset: 0x2e0
	// Line 2369, Address: 0x20396c, Func Offset: 0x2ec
	// Line 2374, Address: 0x203978, Func Offset: 0x2f8
	// Line 2375, Address: 0x20397c, Func Offset: 0x2fc
	// Line 2376, Address: 0x203984, Func Offset: 0x304
	// Line 2377, Address: 0x203988, Func Offset: 0x308
	// Line 2378, Address: 0x2039a0, Func Offset: 0x320
	// Line 2379, Address: 0x2039b8, Func Offset: 0x338
	// Line 2381, Address: 0x2039c0, Func Offset: 0x340
	// Line 2382, Address: 0x2039c8, Func Offset: 0x348
	// Line 2383, Address: 0x2039e4, Func Offset: 0x364
	// Line 2384, Address: 0x203a00, Func Offset: 0x380
	// Line 2386, Address: 0x203a08, Func Offset: 0x388
	// Line 2387, Address: 0x203a28, Func Offset: 0x3a8
	// Line 2388, Address: 0x203a34, Func Offset: 0x3b4
	// Line 2389, Address: 0x203a3c, Func Offset: 0x3bc
	// Line 2391, Address: 0x203a44, Func Offset: 0x3c4
	// Line 2392, Address: 0x203a50, Func Offset: 0x3d0
	// Line 2393, Address: 0x203a70, Func Offset: 0x3f0
	// Line 2394, Address: 0x203a7c, Func Offset: 0x3fc
	// Line 2396, Address: 0x203a84, Func Offset: 0x404
	// Line 2400, Address: 0x203a90, Func Offset: 0x410
	// Line 2401, Address: 0x203aa4, Func Offset: 0x424
	// Line 2402, Address: 0x203aa8, Func Offset: 0x428
	// Line 2405, Address: 0x203ab4, Func Offset: 0x434
	// Line 2406, Address: 0x203abc, Func Offset: 0x43c
	// Line 2409, Address: 0x203ac0, Func Offset: 0x440
	// Line 2413, Address: 0x203ac8, Func Offset: 0x448
	// Line 2409, Address: 0x203acc, Func Offset: 0x44c
	// Line 2411, Address: 0x203ad4, Func Offset: 0x454
	// Line 2413, Address: 0x203af8, Func Offset: 0x478
	// Line 2414, Address: 0x203b04, Func Offset: 0x484
	// Line 2415, Address: 0x203b0c, Func Offset: 0x48c
	// Line 2417, Address: 0x203b14, Func Offset: 0x494
	// Line 2420, Address: 0x203b18, Func Offset: 0x498
	// Line 2417, Address: 0x203b20, Func Offset: 0x4a0
	// Line 2420, Address: 0x203b24, Func Offset: 0x4a4
	// Line 2417, Address: 0x203b28, Func Offset: 0x4a8
	// Line 2418, Address: 0x203b34, Func Offset: 0x4b4
	// Line 2419, Address: 0x203b48, Func Offset: 0x4c8
	// Line 2420, Address: 0x203b5c, Func Offset: 0x4dc
	// Line 2422, Address: 0x203b68, Func Offset: 0x4e8
	// Line 2424, Address: 0x203b70, Func Offset: 0x4f0
	// Line 2426, Address: 0x203b80, Func Offset: 0x500
	// Line 2427, Address: 0x203b94, Func Offset: 0x514
	// Line 2428, Address: 0x203b98, Func Offset: 0x518
	// Line 2429, Address: 0x203bbc, Func Offset: 0x53c
	// Line 2432, Address: 0x203bc8, Func Offset: 0x548
	// Line 2433, Address: 0x203bd8, Func Offset: 0x558
	// Line 2438, Address: 0x203be4, Func Offset: 0x564
	// Line 2439, Address: 0x203be8, Func Offset: 0x568
	// Line 2438, Address: 0x203bec, Func Offset: 0x56c
	// Line 2439, Address: 0x203bf8, Func Offset: 0x578
	// Line 2438, Address: 0x203bfc, Func Offset: 0x57c
	// Line 2439, Address: 0x203c0c, Func Offset: 0x58c
	// Line 2440, Address: 0x203c14, Func Offset: 0x594
	// Line 2441, Address: 0x203c24, Func Offset: 0x5a4
	// Line 2445, Address: 0x203c30, Func Offset: 0x5b0
	// Line 2447, Address: 0x203c38, Func Offset: 0x5b8
	// Line 2448, Address: 0x203c4c, Func Offset: 0x5cc
	// Line 2449, Address: 0x203c5c, Func Offset: 0x5dc
	// Line 2450, Address: 0x203c64, Func Offset: 0x5e4
	// Line 2451, Address: 0x203c68, Func Offset: 0x5e8
	// Line 2452, Address: 0x203c6c, Func Offset: 0x5ec
	// Line 2453, Address: 0x203c70, Func Offset: 0x5f0
	// Line 2456, Address: 0x203c78, Func Offset: 0x5f8
	// Line 2453, Address: 0x203c7c, Func Offset: 0x5fc
	// Line 2456, Address: 0x203c84, Func Offset: 0x604
	// Line 2459, Address: 0x203c88, Func Offset: 0x608
	// Line 2460, Address: 0x203c98, Func Offset: 0x618
	// Line 2466, Address: 0x203cb0, Func Offset: 0x630
	// Line 2467, Address: 0x203cb8, Func Offset: 0x638
	// Func End, Address: 0x203ccc, Func Offset: 0x64c
}

// 
// Start address: 0x203cd0
void bhEne23_DG07(BH_PWORK* epw)
{
	int ang;
	float out;
	NJS_VECTOR ov;
	NJS_VECTOR v;
	NJS_POINT3 trans;
	//NJS_MKEY_A_MOD* mkaP;
	NJS_MKEY_A_MOD* mkaP;
	int mtn[2] = { 54, 55 };
	// Line 2477, Address: 0x203cd0, Func Offset: 0
	// Line 2478, Address: 0x203cdc, Func Offset: 0xc
	// Line 2477, Address: 0x203ce4, Func Offset: 0x14
	// Line 2478, Address: 0x203ce8, Func Offset: 0x18
	// Line 2480, Address: 0x203cf4, Func Offset: 0x24
	// Line 2483, Address: 0x203d20, Func Offset: 0x50
	// Line 2488, Address: 0x203d30, Func Offset: 0x60
	// Line 2490, Address: 0x203d34, Func Offset: 0x64
	// Line 2488, Address: 0x203d38, Func Offset: 0x68
	// Line 2489, Address: 0x203d3c, Func Offset: 0x6c
	// Line 2488, Address: 0x203d40, Func Offset: 0x70
	// Line 2490, Address: 0x203d54, Func Offset: 0x84
	// Line 2488, Address: 0x203d58, Func Offset: 0x88
	// Line 2489, Address: 0x203d5c, Func Offset: 0x8c
	// Line 2490, Address: 0x203d6c, Func Offset: 0x9c
	// Line 2491, Address: 0x203d74, Func Offset: 0xa4
	// Line 2492, Address: 0x203d90, Func Offset: 0xc0
	// Line 2493, Address: 0x203d98, Func Offset: 0xc8
	// Line 2498, Address: 0x203dac, Func Offset: 0xdc
	// Line 2510, Address: 0x203db8, Func Offset: 0xe8
	// Line 2511, Address: 0x203dbc, Func Offset: 0xec
	// Line 2498, Address: 0x203dc0, Func Offset: 0xf0
	// Line 2512, Address: 0x203dc4, Func Offset: 0xf4
	// Line 2498, Address: 0x203dc8, Func Offset: 0xf8
	// Line 2500, Address: 0x203dd0, Func Offset: 0x100
	// Line 2501, Address: 0x203dd8, Func Offset: 0x108
	// Line 2504, Address: 0x203de8, Func Offset: 0x118
	// Line 2507, Address: 0x203df4, Func Offset: 0x124
	// Line 2508, Address: 0x203e08, Func Offset: 0x138
	// Line 2509, Address: 0x203e0c, Func Offset: 0x13c
	// Line 2510, Address: 0x203e10, Func Offset: 0x140
	// Line 2511, Address: 0x203e1c, Func Offset: 0x14c
	// Line 2512, Address: 0x203e20, Func Offset: 0x150
	// Line 2518, Address: 0x203e24, Func Offset: 0x154
	// Line 2519, Address: 0x203e28, Func Offset: 0x158
	// Line 2518, Address: 0x203e2c, Func Offset: 0x15c
	// Line 2519, Address: 0x203e38, Func Offset: 0x168
	// Line 2518, Address: 0x203e3c, Func Offset: 0x16c
	// Line 2519, Address: 0x203e4c, Func Offset: 0x17c
	// Line 2520, Address: 0x203e54, Func Offset: 0x184
	// Line 2521, Address: 0x203e64, Func Offset: 0x194
	// Line 2530, Address: 0x203e74, Func Offset: 0x1a4
	// Line 2531, Address: 0x203ea0, Func Offset: 0x1d0
	// Line 2535, Address: 0x203eac, Func Offset: 0x1dc
	// Line 2539, Address: 0x203eb8, Func Offset: 0x1e8
	// Line 2540, Address: 0x203ec0, Func Offset: 0x1f0
	// Line 2535, Address: 0x203ec4, Func Offset: 0x1f4
	// Line 2538, Address: 0x203ecc, Func Offset: 0x1fc
	// Line 2540, Address: 0x203ed0, Func Offset: 0x200
	// Line 2541, Address: 0x203ed4, Func Offset: 0x204
	// Line 2544, Address: 0x203edc, Func Offset: 0x20c
	// Line 2547, Address: 0x203ee0, Func Offset: 0x210
	// Line 2538, Address: 0x203ee4, Func Offset: 0x214
	// Line 2539, Address: 0x203eec, Func Offset: 0x21c
	// Line 2549, Address: 0x203ef0, Func Offset: 0x220
	// Line 2539, Address: 0x203ef4, Func Offset: 0x224
	// Line 2540, Address: 0x203efc, Func Offset: 0x22c
	// Line 2541, Address: 0x203f08, Func Offset: 0x238
	// Line 2544, Address: 0x203f14, Func Offset: 0x244
	// Line 2545, Address: 0x203f1c, Func Offset: 0x24c
	// Line 2547, Address: 0x203f20, Func Offset: 0x250
	// Line 2549, Address: 0x203f2c, Func Offset: 0x25c
	// Line 2550, Address: 0x203f30, Func Offset: 0x260
	// Line 2553, Address: 0x203f3c, Func Offset: 0x26c
	// Line 2558, Address: 0x203f48, Func Offset: 0x278
	// Line 2559, Address: 0x203f4c, Func Offset: 0x27c
	// Line 2560, Address: 0x203f54, Func Offset: 0x284
	// Line 2561, Address: 0x203f58, Func Offset: 0x288
	// Line 2562, Address: 0x203f70, Func Offset: 0x2a0
	// Line 2563, Address: 0x203f88, Func Offset: 0x2b8
	// Line 2566, Address: 0x203f90, Func Offset: 0x2c0
	// Line 2567, Address: 0x203f98, Func Offset: 0x2c8
	// Line 2568, Address: 0x203fb4, Func Offset: 0x2e4
	// Line 2569, Address: 0x203fd4, Func Offset: 0x304
	// Line 2570, Address: 0x203fe0, Func Offset: 0x310
	// Line 2571, Address: 0x203fe8, Func Offset: 0x318
	// Line 2573, Address: 0x203ff0, Func Offset: 0x320
	// Line 2574, Address: 0x203ffc, Func Offset: 0x32c
	// Line 2575, Address: 0x20401c, Func Offset: 0x34c
	// Line 2576, Address: 0x204028, Func Offset: 0x358
	// Line 2578, Address: 0x204030, Func Offset: 0x360
	// Line 2582, Address: 0x20403c, Func Offset: 0x36c
	// Line 2583, Address: 0x204050, Func Offset: 0x380
	// Line 2584, Address: 0x204054, Func Offset: 0x384
	// Line 2587, Address: 0x204060, Func Offset: 0x390
	// Line 2588, Address: 0x204068, Func Offset: 0x398
	// Line 2591, Address: 0x20406c, Func Offset: 0x39c
	// Line 2595, Address: 0x204074, Func Offset: 0x3a4
	// Line 2591, Address: 0x204078, Func Offset: 0x3a8
	// Line 2593, Address: 0x204080, Func Offset: 0x3b0
	// Line 2595, Address: 0x2040a4, Func Offset: 0x3d4
	// Line 2597, Address: 0x2040b0, Func Offset: 0x3e0
	// Line 2598, Address: 0x2040b8, Func Offset: 0x3e8
	// Line 2600, Address: 0x2040c0, Func Offset: 0x3f0
	// Line 2603, Address: 0x2040c4, Func Offset: 0x3f4
	// Line 2600, Address: 0x2040cc, Func Offset: 0x3fc
	// Line 2603, Address: 0x2040d0, Func Offset: 0x400
	// Line 2600, Address: 0x2040d4, Func Offset: 0x404
	// Line 2601, Address: 0x2040e0, Func Offset: 0x410
	// Line 2602, Address: 0x2040f4, Func Offset: 0x424
	// Line 2603, Address: 0x204108, Func Offset: 0x438
	// Line 2605, Address: 0x204114, Func Offset: 0x444
	// Line 2607, Address: 0x20411c, Func Offset: 0x44c
	// Line 2608, Address: 0x20412c, Func Offset: 0x45c
	// Line 2609, Address: 0x204134, Func Offset: 0x464
	// Line 2610, Address: 0x204138, Func Offset: 0x468
	// Line 2611, Address: 0x20413c, Func Offset: 0x46c
	// Line 2612, Address: 0x204140, Func Offset: 0x470
	// Line 2615, Address: 0x204148, Func Offset: 0x478
	// Line 2612, Address: 0x20414c, Func Offset: 0x47c
	// Line 2615, Address: 0x204154, Func Offset: 0x484
	// Line 2618, Address: 0x204158, Func Offset: 0x488
	// Line 2619, Address: 0x204168, Func Offset: 0x498
	// Line 2625, Address: 0x204180, Func Offset: 0x4b0
	// Line 2626, Address: 0x204188, Func Offset: 0x4b8
	// Func End, Address: 0x20419c, Func Offset: 0x4cc
}

// 100% matching!
void bhEne23_Die(BH_PWORK* epw)
{
	bhEne23_DeadMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne23_DD00(BH_PWORK* epw)
{
    int mtn[2] = { 48, 50 }; 
    
    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = mtn[epw->type];
        epw->frm_no = 0;

        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;

        epw->mtn_add = 65536;

        epw->flg |= 0x10000000;

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;

        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mtn_add = 0;

            epw->mode3++;

            epw->flg  &= ~0x8;
            epw->flg2 |=  0x1;

            epw->ay = bhArcTan2(-EXP0_F(8), EXP0_F(0));

            bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
        }

        break;
    }

    EXP0_I(280) = 0;
}

#pragma divbyzerocheck on 

// 99.82% matching
void bhEne23_DD01(BH_PWORK* epw) 
{
    int mtn[2][2] = { { 40, 47 }, { 45, 49 } }; 
    
    switch (epw->mode3)
    {
    case 0:
    {
        NJS_MKEY_A_MOD* mkaP;
        
        bhEne03_GetPartsPos(epw, joint_tree[0], (NJS_POINT3*)&epw->px);

        mkaP  = epw->mnwP[epw->mtn_no].md2P->p[1];
        mkaP += epw->frm_no / 65536;

        if ((epw->mtn_md & 0x2))
        {
            njRotateXYZ((NJS_MATRIX*)epw->exp0, *mkaP->key++, -*mkaP->key++, -*mkaP->key++);
        }
        else
        {
            njRotateXYZ((NJS_MATRIX*)epw->exp0, *mkaP->key++, *mkaP->key++, *mkaP->key++);
        }

        if ((epw->flg & 0x400000))
        {
            EXP0_F(84) = 3.0f * EXP0_F(16);
            EXP0_F(88) = 0;
            EXP0_F(92) = 3.0f * EXP0_F(24);
        }
        else
        {
            EXP0_F(84) = 0;
            EXP0_F(88) = 0;
            EXP0_F(92) = 0;
        }

        njRotateX((NJS_MATRIX*)epw->exp0, 32768);

        epw->mtn_md |= 0x100;

        epw->mtn_no = mtn[epw->type][0];
        epw->frm_no = 0;
        
        epw->mtn_add = 0;
        
        epw->mtn_md &= ~0x2;

        epw->hokan_count = 30;
        epw->hokan_rate  = 45875;

        {
        NJS_MKEY_A_MOD* mkaP; 
        NJS_POINT3 trans;     

        mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];

        epw->mlwP->objP->ang[0] = *mkaP->key++;
        epw->mlwP->objP->ang[1] = *mkaP->key++;
        epw->mlwP->objP->ang[2] = *mkaP->key++;

        njCalcVector((NJS_MATRIX*)epw->exp0, epw->mnwP[epw->mtn_no].md2P->p[0], &trans);
        njSubVector((NJS_VECTOR*)&epw->px, &trans);

        epw->flg &= ~0x4000000;

        if ((epw->flg & 0x400000))
        {
            EXP0_I(96) = EXP0_I(100);
        }

        epw->flg |=  0x30;
            
        epw->flg &= ~0x400000;
        epw->flg &= ~0x180000;
        epw->flg &= ~0x1800000;

        EXP0_F(108) = 14.0f;
        epw->ar     = 14.0f;

        epw->flg |= 0x10000000;

        epw->ct0 = 8;

        epw->mode3++;
        }
    }
    case 1:
    {
        NJS_VECTOR v, ov; 
        float out;     
        int ang;      

        if (epw->ct0 > 0)
        {
            v.x = 0;
            v.y = 1.0f;
            v.z = 0;
            
            out = njOuterProduct((NJS_VECTOR*)&EXP0_I(16), &v, &ov);

            if (out > 0)
            {
                njUnitVector(&ov);
                njUnitMatrix(NULL);

                ang = (int)(10430.381f * asinf(out)) / epw->ct0;

                njRotate(NULL, &ov, ang);
                
                njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);
                
                njGetMatrix((NJS_MATRIX*)epw->exp0);
            }
            else
            {
                njUnitMatrix(NULL);

                njRotateX(NULL, 32768 / epw->ct0);
                
                njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);
                
                njGetMatrix((NJS_MATRIX*)epw->exp0);
            }

            epw->ct0--;
        }

        if ((epw->flg & 0x4000000))
        {
            EXP0_C(105) = 0;

            bhEne03_MakeMatrix(epw);

            epw->mtn_add = 65536;
            
            epw->frm_no = 65536;

            epw->mtn_md &= ~0x100;

            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;

            epw->mode3++;
        }
        else
        {
            epw->px += EXP0_F(84);
            epw->py += EXP0_F(88);
            epw->pz += EXP0_F(92);

            EXP0_F(88) -= 0.6f;
        }

        break;
    }
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->mtn_no = mtn[epw->type][1];
            epw->frm_no = 0;

            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;

            epw->mode3++;
        }

        break;
    case 3:
        if (epw->ct0-- == 0)
        {
            epw->frm_no = 65536.0f * (epw->mnwP[epw->mtn_no].frm_num - 1);

            epw->hokan_count = 0;
            
            epw->mtn_add = 0;

            epw->flg &= ~0x40;

            epw->mode3++;

            epw->flg  &= ~0x8;
            epw->flg2 |=  0x1;

            epw->ay = bhArcTan2(-EXP0_F(8), EXP0_F(0));

            bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
        }

        break;
    }

    EXP0_I(280) = 0;
}

#pragma divbyzerocheck off

// 100% matching!
void bhEne23_DD02()
{
	
}

// 
// Start address: 0x204910
void bhEne23_DD03(BH_PWORK* epw)
{
	int ang;
	float out;
	NJS_VECTOR ov;
	NJS_VECTOR v;
	NJS_POINT3 trans;
	//NJS_MKEY_A_MOD* mkaP;
	NJS_MKEY_A_MOD* mkaP;
	int mtn[2][2] = { { 54, 48 }, { 55, 50 } };
	// Line 2883, Address: 0x204910, Func Offset: 0
	// Line 2884, Address: 0x20491c, Func Offset: 0xc
	// Line 2883, Address: 0x204924, Func Offset: 0x14
	// Line 2884, Address: 0x204928, Func Offset: 0x18
	// Line 2889, Address: 0x204934, Func Offset: 0x24
	// Line 2892, Address: 0x20496c, Func Offset: 0x5c
	// Line 2897, Address: 0x20497c, Func Offset: 0x6c
	// Line 2899, Address: 0x204980, Func Offset: 0x70
	// Line 2897, Address: 0x204984, Func Offset: 0x74
	// Line 2898, Address: 0x204988, Func Offset: 0x78
	// Line 2897, Address: 0x20498c, Func Offset: 0x7c
	// Line 2899, Address: 0x2049a0, Func Offset: 0x90
	// Line 2897, Address: 0x2049a4, Func Offset: 0x94
	// Line 2898, Address: 0x2049a8, Func Offset: 0x98
	// Line 2899, Address: 0x2049b8, Func Offset: 0xa8
	// Line 2900, Address: 0x2049c0, Func Offset: 0xb0
	// Line 2901, Address: 0x2049dc, Func Offset: 0xcc
	// Line 2902, Address: 0x2049e4, Func Offset: 0xd4
	// Line 2907, Address: 0x2049f8, Func Offset: 0xe8
	// Line 2918, Address: 0x204a04, Func Offset: 0xf4
	// Line 2919, Address: 0x204a08, Func Offset: 0xf8
	// Line 2907, Address: 0x204a0c, Func Offset: 0xfc
	// Line 2920, Address: 0x204a10, Func Offset: 0x100
	// Line 2907, Address: 0x204a14, Func Offset: 0x104
	// Line 2908, Address: 0x204a1c, Func Offset: 0x10c
	// Line 2909, Address: 0x204a2c, Func Offset: 0x11c
	// Line 2912, Address: 0x204a3c, Func Offset: 0x12c
	// Line 2915, Address: 0x204a48, Func Offset: 0x138
	// Line 2916, Address: 0x204a5c, Func Offset: 0x14c
	// Line 2917, Address: 0x204a60, Func Offset: 0x150
	// Line 2918, Address: 0x204a64, Func Offset: 0x154
	// Line 2919, Address: 0x204a70, Func Offset: 0x160
	// Line 2920, Address: 0x204a74, Func Offset: 0x164
	// Line 2926, Address: 0x204a78, Func Offset: 0x168
	// Line 2927, Address: 0x204a7c, Func Offset: 0x16c
	// Line 2926, Address: 0x204a80, Func Offset: 0x170
	// Line 2927, Address: 0x204a8c, Func Offset: 0x17c
	// Line 2926, Address: 0x204a90, Func Offset: 0x180
	// Line 2927, Address: 0x204aa0, Func Offset: 0x190
	// Line 2928, Address: 0x204aa8, Func Offset: 0x198
	// Line 2929, Address: 0x204ab8, Func Offset: 0x1a8
	// Line 2938, Address: 0x204ac8, Func Offset: 0x1b8
	// Line 2939, Address: 0x204af4, Func Offset: 0x1e4
	// Line 2943, Address: 0x204b00, Func Offset: 0x1f0
	// Line 2948, Address: 0x204b0c, Func Offset: 0x1fc
	// Line 2949, Address: 0x204b14, Func Offset: 0x204
	// Line 2943, Address: 0x204b18, Func Offset: 0x208
	// Line 2947, Address: 0x204b20, Func Offset: 0x210
	// Line 2949, Address: 0x204b24, Func Offset: 0x214
	// Line 2950, Address: 0x204b28, Func Offset: 0x218
	// Line 2953, Address: 0x204b30, Func Offset: 0x220
	// Line 2956, Address: 0x204b34, Func Offset: 0x224
	// Line 2947, Address: 0x204b38, Func Offset: 0x228
	// Line 2948, Address: 0x204b40, Func Offset: 0x230
	// Line 2958, Address: 0x204b44, Func Offset: 0x234
	// Line 2948, Address: 0x204b48, Func Offset: 0x238
	// Line 2949, Address: 0x204b50, Func Offset: 0x240
	// Line 2950, Address: 0x204b5c, Func Offset: 0x24c
	// Line 2953, Address: 0x204b68, Func Offset: 0x258
	// Line 2954, Address: 0x204b70, Func Offset: 0x260
	// Line 2956, Address: 0x204b74, Func Offset: 0x264
	// Line 2958, Address: 0x204b80, Func Offset: 0x270
	// Line 2959, Address: 0x204b84, Func Offset: 0x274
	// Line 2962, Address: 0x204b90, Func Offset: 0x280
	// Line 2967, Address: 0x204b9c, Func Offset: 0x28c
	// Line 2968, Address: 0x204ba0, Func Offset: 0x290
	// Line 2969, Address: 0x204ba8, Func Offset: 0x298
	// Line 2970, Address: 0x204bac, Func Offset: 0x29c
	// Line 2971, Address: 0x204bc4, Func Offset: 0x2b4
	// Line 2972, Address: 0x204bdc, Func Offset: 0x2cc
	// Line 2975, Address: 0x204be4, Func Offset: 0x2d4
	// Line 2976, Address: 0x204bec, Func Offset: 0x2dc
	// Line 2977, Address: 0x204c08, Func Offset: 0x2f8
	// Line 2978, Address: 0x204c28, Func Offset: 0x318
	// Line 2979, Address: 0x204c34, Func Offset: 0x324
	// Line 2980, Address: 0x204c3c, Func Offset: 0x32c
	// Line 2982, Address: 0x204c44, Func Offset: 0x334
	// Line 2983, Address: 0x204c50, Func Offset: 0x340
	// Line 2984, Address: 0x204c70, Func Offset: 0x360
	// Line 2985, Address: 0x204c7c, Func Offset: 0x36c
	// Line 2987, Address: 0x204c84, Func Offset: 0x374
	// Line 2991, Address: 0x204c90, Func Offset: 0x380
	// Line 2992, Address: 0x204ca4, Func Offset: 0x394
	// Line 2993, Address: 0x204ca8, Func Offset: 0x398
	// Line 2996, Address: 0x204cb4, Func Offset: 0x3a4
	// Line 2997, Address: 0x204cbc, Func Offset: 0x3ac
	// Line 3000, Address: 0x204cc0, Func Offset: 0x3b0
	// Line 3002, Address: 0x204cd0, Func Offset: 0x3c0
	// Line 3003, Address: 0x204cf4, Func Offset: 0x3e4
	// Line 3004, Address: 0x204cfc, Func Offset: 0x3ec
	// Line 3006, Address: 0x204d04, Func Offset: 0x3f4
	// Line 3009, Address: 0x204d08, Func Offset: 0x3f8
	// Line 3006, Address: 0x204d10, Func Offset: 0x400
	// Line 3009, Address: 0x204d14, Func Offset: 0x404
	// Line 3006, Address: 0x204d18, Func Offset: 0x408
	// Line 3007, Address: 0x204d24, Func Offset: 0x414
	// Line 3008, Address: 0x204d38, Func Offset: 0x428
	// Line 3009, Address: 0x204d4c, Func Offset: 0x43c
	// Line 3011, Address: 0x204d58, Func Offset: 0x448
	// Line 3013, Address: 0x204d60, Func Offset: 0x450
	// Line 3015, Address: 0x204d70, Func Offset: 0x460
	// Line 3018, Address: 0x204d74, Func Offset: 0x464
	// Line 3015, Address: 0x204d78, Func Offset: 0x468
	// Line 3016, Address: 0x204d88, Func Offset: 0x478
	// Line 3017, Address: 0x204d8c, Func Offset: 0x47c
	// Line 3018, Address: 0x204d90, Func Offset: 0x480
	// Line 3020, Address: 0x204d94, Func Offset: 0x484
	// Line 3021, Address: 0x204db8, Func Offset: 0x4a8
	// Line 3023, Address: 0x204dc0, Func Offset: 0x4b0
	// Line 3025, Address: 0x204dc8, Func Offset: 0x4b8
	// Line 3026, Address: 0x204dd8, Func Offset: 0x4c8
	// Line 3027, Address: 0x204e3c, Func Offset: 0x52c
	// Line 3028, Address: 0x204e40, Func Offset: 0x530
	// Line 3029, Address: 0x204e44, Func Offset: 0x534
	// Line 3032, Address: 0x204e4c, Func Offset: 0x53c
	// Line 3029, Address: 0x204e50, Func Offset: 0x540
	// Line 3030, Address: 0x204e58, Func Offset: 0x548
	// Line 3032, Address: 0x204e64, Func Offset: 0x554
	// Line 3033, Address: 0x204e70, Func Offset: 0x560
	// Line 3036, Address: 0x204e7c, Func Offset: 0x56c
	// Line 3037, Address: 0x204e94, Func Offset: 0x584
	// Line 3043, Address: 0x204eac, Func Offset: 0x59c
	// Line 3044, Address: 0x204eb4, Func Offset: 0x5a4
	// Func End, Address: 0x204ec8, Func Offset: 0x5b8
}

// 100% matching!
void bhEne23_CollisionWalls(BH_PWORK* epw)
{
    NJS_POINT3 body, trans;      
    float ar, ah;            
    NJS_MKEY_A_MOD* mkaP;
    NJS_CNK_OBJECT* objP; 
    float px, py, pz; // not from DWARF
    float dx, dz;     // not from DWARF
    NJS_MATRIX* mtxP; // not from DWARF

    px = epw->px;
    py = epw->py;
    pz = epw->pz;

    body.x = 0;
    body.y = epw->ar;
    body.z = 0;

    njSetMatrix(NULL, (NJS_MATRIX*)epw->exp0);

    if ((epw->flg & 0x100000)) 
    {
        mkaP  = (NJS_MKEY_A_MOD*)epw->mnwP[epw->mtn_no].md2P->p[1];
        mkaP += epw->frm_no / 65536;
        
        njRotateXYZ(NULL, *mkaP->key++, *mkaP->key++, *mkaP->key++);
    }

    njCalcVector(NULL, &body, &body);

    if ((epw->flg & 0x10000000)) 
    {
        objP = epw->mlwP->objP;
        
        trans.x = objP->pos[0];
        trans.y = objP->pos[1];
        trans.z = objP->pos[2];
    
        if (!(epw->flg & 0x80000)) 
        {
            trans.y = 0;
        }
    
        njCalcVector((NJS_MATRIX*)epw->exp0, &trans, &trans);
    
        epw->px += trans.x;
        epw->py += trans.y;
        epw->pz += trans.z;
    } 
    else 
    {
        trans.x = 0;
        trans.y = 0;
        trans.z = 0;
    }

    if (((epw->flg & 0x4000000)) && (EXP0_C(105) == 0)) 
    {
        mtxP = (NJS_MATRIX*)epw->exp0;
    
        dx = mtxP[0][8]  * -((float*)mtxP)[70];
        dz = mtxP[0][10] * -((float*)mtxP)[70];
        
        epw->px += dx;
        epw->py += 5.0f;
        epw->pz += dz;
    
        ar = epw->ar;
        ah = epw->ah;
        
        epw->ah = 20.0f;
        epw->ar = 12.0f;
    
        bhCheckWall(epw);
    
        epw->px -= dx;
        epw->py -= 5.0f;
        epw->pz -= dz;
    
        epw->ar = ar;
        epw->ah = ah;
    
        EXP0_F(280) += (10.4f - EXP0_F(280)) / 16.0f;
    }
    
    if (!(epw->flg & 0x4000000)) 
    {
        epw->px += body.x;
        epw->py += body.y;
        epw->pz += body.z;

        bhEne03_Collision2(epw, (ATR_WORK*)EXP0_I(96));

        epw->px -= body.x;
        epw->py -= body.y;
        epw->pz -= body.z;
    } 
    else 
    {
        if ((EXP0_C(105) == 0) || ((epw->flg & 0x8000000))) 
        {
            epw->px += body.x;
            epw->py += body.y;
            epw->pz += body.z;
    
            bhEne03_Collision(epw);
    
            epw->px -= body.x;
            epw->py -= body.y;
            epw->pz -= body.z;
        } 
        else 
        {
            bhEne03_Collision2(epw, (ATR_WORK*)EXP0_I(96));
        }
    }

    epw->px -= trans.x;
    epw->py -= trans.y;
    epw->pz -= trans.z;

    if ((epw->flg & 0x4000000)) 
    {
        epw->py = py;
    }

    if (!(epw->flg & 0x8000000)) 
    {
        epw->ar += (EXP0_F(108) - epw->ar) / 8.0f;
    }
}

// 100% matching!
void bhEne23_CollisionLine(BH_PWORK* epw)
{
	NJS_VECTOR n;
	ATR_WORK* hp;

    hp = bhCollisionCheckLine2((NJS_POINT3*)&epw->pxb, (NJS_POINT3*)&epw->px, 17408, -1);

    if ((hp != NULL) && ((hp->type == 7) && (!(epw->flg & 0x4000000))))
    {        
		bhGetHitCollisionNormal(&n);

		if (n.y > 0)
		{
			epw->flg |= 0x4000000;

			*(ATR_WORK**)&EXP0_I(96) = bhEne03_GetWall(epw);
		}
    }
}

// 100% matching!
int bhEne23_CheckClimbWall(BH_PWORK* epw, int flg)
{
    ATR_WORK* hp;          
    NJS_POINT3 pos, pos2;       
    int ang, ang2;             
    int i;               
    int root;              
    int mtn[2] = { 3, 24 }; 
	NJS_MKEY* mkfP;        

    if (EXP0_C(105) != 0)
    {
        return 0;
    }

    epw->ay = bhArcTan2(-EXP0_F(8), EXP0_F(0));

    if (epw->way > 910)
    {
        ang = (short)((epw->ay + 16384) & ~0x3FFF);
    }
    else if (epw->way < -910)
    {
        ang = (short)(epw->ay & ~0x3FFF);
    }
    else
    {
        ang = (short)((epw->ay + 8192) & ~0x3FFF);
    }

    ang2 = (short)(ang - epw->ay);

    if ((ang2 < -5461) || (ang2 > 5461))
    {
        return 0;
    }

    pos.x = epw->px - (27.0f * njSin(ang));
    pos.z = epw->pz - (27.0f * njCos(ang));

    hp = bhCheckFloorEnemy(epw->flr_no, pos.x, pos.z);

    if (((hp != NULL) && (hp->prm0 == 23) && (hp->prm1 < 4)) && (ang == (short)((-(hp->prm1 & 0x3)) * 16384)))
    {
        *(ATR_WORK**)&EXP0_I(260) = hp;
    
        epw->xn = epw->px;
        epw->yn = epw->py;
        epw->zn = epw->pz;
    
        switch (hp->prm1)
        {
        case 0:
            epw->zn = (hp->pz + hp->d) + 22.4f;
            break;
        case 1:
            epw->xn = hp->px - 22.4f;
            break;
        case 2:
            epw->zn = hp->pz - 22.4f;
            break;
        case 3:
            epw->xn = (hp->px + hp->w) + 22.4f;
            break;
        }
    
        root = 2.0f * (-rand() / -2147483648.0f);
    
        for (i = 0; i < 2; i++)
        {
            mkfP  = epw->mnwP[root + mtn[epw->type]].md2P->p[0];
            mkfP += epw->mnwP[root + mtn[epw->type]].frm_num - 1;
            
            njUnitMatrix(NULL);
            
            njRotateY(NULL, ang);
    
            pos = *(NJS_POINT3*)&mkfP->key[0];
            
            pos.x *= flg;
    
            njCalcVector(NULL, &pos, &pos);
            
            njAddVector(&pos, (NJS_POINT3*)&epw->xn);
    
            pos.y -= 23.0f;
    
            if (bhCheckWallType(&pos, 0, 18.199999f, 20.0f) == NULL)
            {
                pos2.x = pos.x;
                pos2.y = pos.y + 999.0f;
                pos2.z = pos.z;
    
                *(ATR_WORK**)&EXP0_I(100) = bhCollisionCheckLine(&pos, &pos2);
    
                return root + 1;
            }
    
            if (++root > 1)
            {
                root = 0;
            }
        }
    }

    return 0;
}

// 99.75% matching
int bhEne23_CheckDiving(BH_PWORK* epw) 
{
    NJS_MKEY* mkfP;
    NJS_POINT3 pos;
    float dist;    

    if (plp->flr_no != 0) 
    {
        return 0;
    }

    if ((epw->flg & 0x8000000)) 
    {
        return 0;
    }

    mkfP  = (NJS_MKEY*)epw->mnwP[37].md2P->p[0];
    mkfP += epw->mnwP[37].frm_num - 1;

    njCalcVector((NJS_MATRIX*)epw->exp0, (NJS_POINT3*)mkfP, &pos);

    pos.x += epw->px;
    pos.z += epw->pz;
    
    pos.y = plp->py;

    if (bhCheckWallType(&pos, 0, 14.0f, 20.0f) != NULL) 
    {
        return 0;
    }

    dist = njSqrt(((pos.x - plp->px) * (pos.x - plp->px)) + ((pos.z - plp->pz) * (pos.z - plp->pz)));

    if (dist < 15.0f) 
    {
        return 0;
    }

    return 1;
}

// 100% matching!
void bhEne23_DamageInit(BH_PWORK* epw)
{
	int flg;

    epw->flg &= ~0x4;

    bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl);

    epw->comb_flg &= ~0xC;

    if (bhEne03_DGDirCheck(epw) != 0)
    {
        epw->comb_flg |= 0x8;
    }
    else
    {
        epw->comb_flg |= 0x4;
    }

    if ((epw->wpnr_no != 16) || ((epw->flg2 & 0x4)) || (epw->comb_pnt == 1))
    {
        if (epw->total_dam != 0)
        {
            if (epw->type == 0)
            {
                if ((epw->comb_flg & 0x8))
                {
                    EXP0_I(276) -= epw->total_dam;
                }
                else
                {
                    if ((EXP0_C(105) == 0) && (!(plp->at_flg & 0x8)))
                    {
                        EXP0_I(276) -= epw->total_dam;
                    }

                    epw->hp -= epw->total_dam;
                }
            }
            else
            {
                epw->hp -= epw->total_dam;
            }
        }

        if ((epw->wpnr_no == 17) && (!(epw->flg2 & 0x4)))
        {
            return;
        }

        bhEne23_HitMark(epw);

        if ((EXP0_C(105) == 0) && (!(epw->flg & 0x400000)) && (epw->total_dam > 50) && ((-rand() / -2147483648.0f) < 0.3f))
        {
            bhEne23_LegBreak(epw);
        }

        if (epw->hp < 0)
        {
            epw->mode0 = 4;
            epw->mode1 = 0;
            epw->mode3 = 0;

            switch (EXP0_C(105)) 
            {
            case 0:
                epw->mode2 = 0;
                break;
            case 1:
                epw->mode2 = 1;
                break;
            }

            if ((epw->flg & 0x400000))
            {
                if (epw->mlwP->owP->mtx[5] < 0)
                {
                    epw->mode2 = 1;
                }
                else
                {
                    epw->mode2 = 3;
                }
            }

            epw->flg |=  0x2;
            epw->flg &= ~0x20;
            return;
        }

        flg = 0;

        if (((epw->flg & 0x400000)) && ((epw->total_dam < 40) || ((-rand() / -2147483648.0f) > 0.5f)))
        {
            return;
        }

        if ((epw->type == 0) && (EXP0_I(276) < 0))
        {
            switch (epw->wpnr_no)
            {
            case 8:
            case 9:
            case 12:
                if (epw->comb_pnt > 5)
                {
                    flg = 1;
                    
                    epw->mode2 = 4;
                }
                
                break;
            case 5:
            case 6:
            case 10:
            case 11:
            case 13:
            case 14:
            case 15:
            case 16:
            case 20:
                flg = 1;
                
                epw->mode2 = 4;
                break;
            }
        }

        if (flg == 0)
        {
            if (epw->total_dam > 40)
            {
                epw->mode2 = 3;
            }
            else
            {
                if (epw->total_dam <= 20)
                {
                    return;
                }

                epw->mode2 = 1;
            }
        }

        if ((EXP0_C(105) == 1) && ((-rand() / -2147483648.0f) > 0.5f))
        {
            epw->mode2 = 6;
        }

        if ((epw->flg & 0x400000))
        {
            if (epw->mlwP->owP->mtx[5] < 0)
            {
                epw->mode2 = 6;
            }
            else
            {
                epw->mode2 = 7;
            }
        }

        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode3 = 0;
    }
}

// 100% matching!
void bhEne23_LegBreak(BH_PWORK* epw) 
{
    int i;
    O_WORK* owk;

    i = (int)(2.0f * (-rand() / -2147483648.0f));  

    if (((unsigned char*)epw->exp0)[i + 258] == 0)   
    {
        ((unsigned char*)epw->exp0)[i + 258] = 1;

        owk = &epw->mlwP->owP[((unsigned char*)epw->exp0)[i + 256]];

        owk[0].flg |= 0x3;
        owk[1].flg |= 0x2;
        owk[2].flg |= 0x2;

        ((BH_PWORK**)epw->exp0)[62 + i]->mode0 = 1;
        ((BH_PWORK**)epw->exp0)[62 + i]->mode2 = 0;
        ((BH_PWORK**)epw->exp0)[62 + i]->mode3 = 0;

        epw->mdflg |= 0x20;

        bhEne_SetBloodstain(epw, 0, ((unsigned char*)epw->exp0)[i + 256], NULL);

        bhEne_SetMinceEffect(epw, 2, 3);
        bhEne_SetMinceEffect(epw, 3, 2);
    }
}

// 100% matching!
void bhEne23_InitChild(BH_PWORK* epw)
{
    int i;          
    BH_PWORK** epw2; 
    int ang;         
    NJS_VECTOR v;    
	float spd;      
    float px, py, pz; // not from DWARF

    epw2 = (BH_PWORK**)&EXP0_C(128);

    for (i = 0; i < EXP0_I(268); i++, epw2++)
    {
        if (((((BH_PWORK**)epw->exp0)[32 + i]->flg & 0x1)) && (((BH_PWORK**)epw->exp0)[32 + i]->id == 24))
        {
            (*epw2)->mode0 = 1;
            (*epw2)->mode1 = 1;
            (*epw2)->mode2 = 5;
            (*epw2)->mode3 = 0;

            (*epw2)->mdflg &= ~0x1;

            ang = 65536.0f * (-rand() / -2147483648.0f);

            spd = 0.5f + (1.2f * (-rand() / -2147483648.0f));

            (*epw2)->ay = ang;

            (*epw2)->xn = spd * -njSin(ang);
            (*epw2)->yn = 0.5f + (1.5f * (-rand() / -2147483648.0f));
            (*epw2)->zn = spd * -njCos(ang);

            v.x = 0;
            v.y = 5.0f + (10.0f * (-rand() / -2147483648.0f));
            v.z = 10.0f;

            njCalcVector((NJS_MATRIX*)epw->exp0, &v, &v);

            px = epw->px + v.x;
            py = epw->py + v.y;
            pz = epw->pz + v.z;

            spd = 3.0f + (3.0f * (-rand() / -2147483648.0f));

            (*epw2)->px = (*epw2)->pxb = px - (spd * njSin(ang));
            (*epw2)->py = (*epw2)->pyb = py;
            (*epw2)->pz = (*epw2)->pzb = pz - (spd * njCos(ang));
        }
    }
}

// 100% matching!
void bhEne23_PlayerControl(BH_PWORK* epw)
{
	int mtn[3][8] = 
	{
		{ 60, 61, 62, 63, 65, 64, 0, 0 },
		{ 66, 67, 68, 69, 71, 70, 0, 0 },
		{ 66, 67, 68, 69, 71, 70, 0, 0 }
	};
	NJS_POINT3* trans[3][3] = 
	{
		{ cler_042, cler_043, cler_045 },
  	    { cher_060, cher_061, cher_063 },
  	    { cher_060, cher_061, cher_063 }  
	}; 

    if (plp->mode0 == 4) 
    {
        switch (plp->mode2) 
        {
        case 0:
        case 1:
            switch (plp->mode3) 
            {                          
            case 0:                                 
                plp->flg  &= ~0x40000;
                plp->flg2 |=  0x1;
                
                plp->mnwP = epw->mnwP;
                
                if (plp->mode2 == 0)
                {
                    plp->mtn_no = mtn[sys->ply_id][0];
                }
                else
                {
                    plp->mtn_no = mtn[sys->ply_id][1];
                }
                
                plp->frm_no = 0;
                
                plp->hokan_count = 3;
                plp->hokan_rate  = 32768;
                
                plp->mtn_add = 65536;
                
                plp->mode3++;
                
                bhEne_CallPlayerVoice(2);
                
                StartVibrationEx(1, 11);
                break;
            case 1:                                 
                if (plp->mode2 == 0)
                {
                    bhEne_AddNullTrans(plp, trans[sys->ply_id][0]);
                }
                else
                {
                    bhEne_AddNullTrans(plp, trans[sys->ply_id][1]);
                }
                
                if (plp->frm_no == 0) 
                {
                    if (plp->mode2 == 0)
                    {
                        plp->mtn_no = mtn[sys->ply_id][2];
                        
                        plp->flg |= 0xC0000;
                    } 
                    else 
                    {
                        plp->mtn_no = mtn[sys->ply_id][3];
                    }
                    
                    plp->mode3++;
                }
                
                break;
            case 2:                                 
                if (plp->mode2 == 0)
                {
                    if ((plp->frm_no / 65536) == 19)
                    {
                        plp->flg &= ~0x80000;
                    }
                    
                    if ((sys->ply_id == 0) && ((plp->frm_no / 65536) == 41))
                    {
                        plp->flg |= 0x80000;
                    }
                }
                else
                {
                    if (plp->mtn_no == mtn[sys->ply_id][3])
                    {
                        bhEne_AddNullTrans(plp, trans[sys->ply_id][2]);
                    }
                }
                
                if (plp->frm_no == 0) 
                {
                    plp->mnwP = plp->mnwPb;
                    
                    plp->flg  &= ~0x10004;
                    plp->flg2 &= ~0x1;
                    
                    plp->flg |= 0x8;
                    
                    plp->at_flg = 0;
                    
                    plp->stflg &= ~0x10000;
                    
                    *(int*)&plp->mode0 = 1;
                }
                
                break;
            }

            break;
        }
        
        plp->flg |= 0x200000;
    }
    else if (plp->mode0 == 6) 
    {
        switch (plp->mode2) 
        {
        case 0:
        case 1:
            switch (plp->mode3) 
            {                       
            case 0:                                 
                plp->flg  &= ~0x40000;
                plp->flg2 |=  0x1;
                
                plp->mnwP = epw->mnwP;
                
                if (plp->mode2 == 2) 
                {
                    plp->mtn_no = mtn[sys->ply_id][0];
                } 
                else
                {
                    plp->mtn_no = mtn[sys->ply_id][1];
                }
                
                plp->frm_no = 0;
                
                plp->hokan_count = 3;
                plp->hokan_rate  = 32768;
                
                plp->mtn_add = 65536;
                
                plp->mode3++;
                
                bhEne_CallPlayerVoice(1);
                
                StartVibrationEx(1, 11);
                break;
            case 1:                                 
                if (plp->mode2 == 2)
                {
                    bhEne_AddNullTrans(plp, trans[sys->ply_id][0]);
                }
                else
                {
                    bhEne_AddNullTrans(plp, trans[sys->ply_id][1]);
                }
                
                if (plp->frm_no == 0) 
                {
                    if (plp->mode2 == 2)
                    {
                        plp->mtn_no = mtn[sys->ply_id][4];
                    }
                    else 
                    {
                        plp->mtn_no = mtn[sys->ply_id][5];
                    }
                    
                    plp->ct0 = plp->mnwP[plp->mtn_no].frm_num - 2;
                    
                    plp->mode3++;
                }
                
                break;
            case 2:                                 
                if (plp->ct0-- == 0) 
                {
                    plp->mtn_add = 0;
                    
                    plp->ct0 = 45;
                    
                    plp->mode3++;
                }
                
                break;
            case 3:
                if (plp->ct0-- == 0)
                {
                    plp->flg |= 0x2;
                }
                
                break;
            }

            break;
        }
        
        plp->flg |= 0x200000;
    }
}

// 99.96% matching
void bhEne23_Acid(BH_PWORK* epw)
{
    int eno;   
    int i;      
    O_WORK* owk; 
    float dt;    
    NJS_POINT3 pos1, pos2; // not from DWARF

    owk = epw->mlwP->owP; 
    
    pos1.x = owk[7].mtx[12];
    pos1.y = owk[7].mtx[13];
    pos1.z = owk[7].mtx[14]; 
    
    pos1.x = (pos1.x + owk[22].mtx[12]) / 2.0f; 
    pos1.y = (pos1.y + owk[22].mtx[13]) / 2.0f;
    pos1.z = (pos1.z + owk[22].mtx[14]) / 2.0f; 

    if (EXP0_C(105) == 0) 
    {
        pos2.x = -3.5f * EXP0_F(32);
        pos2.y = 0; 
        pos2.z = -3.5f * EXP0_F(40); 
    } 
    else 
    { 
        pos2.x = -4.5f * EXP0_F(32); 
        pos2.y = 1.0f; 
        pos2.z = -4.5f * EXP0_F(40);
    }

    sys->ef.id   = 256;
    sys->ef.type = 2;
    
    sys->ef.flg = 1;
    
    sys->ef.px = pos1.x;
    sys->ef.py = pos1.y;
    sys->ef.pz = pos1.z;
    
    for (i = 0; i < 2; i++) 
    {
        dt = 1.5f + (-rand() / -2.1474836E9f);
        
        sys->ef.sx = dt;
        sys->ef.sy = dt;
        sys->ef.sz = dt;
        
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        
        if (eno != -1) 
        {
            eff[eno].stflg |= 0x20; 
            
            eff[eno].txp[0] = epw->mdl[6].texP; 
            eff[eno].tex_id = 1; 

            eff[eno].xn = pos2.x; 
            eff[eno].yn = pos2.y; 
            eff[eno].zn = pos2.z;
            
            njUnitMatrix(NULL);
            
            njRotateY(NULL, (1820.0f * (-rand() / -2.1474836E9f)) - 910.0f);
            njRotateX(NULL,  1820.0f * (-rand() / -2.1474836E9f));
            
            njCalcVector(NULL, (NJS_VECTOR*)&eff[eno].xn, (NJS_VECTOR*)&eff[eno].xn);
            
            dt = -rand() / -2.1474836E9f;
            
            eff[eno].px += dt * eff[eno].xn;
            eff[eno].py += dt * eff[eno].yn;
            eff[eno].pz += dt * eff[eno].zn;
        }
    }
}

// 100% matching!
unsigned int bhEne23_SearchPlayer(BH_PWORK* epw, int ang)
{
	NJS_POINT3 dist;

    dist.x = epw->px - plp->px;
    dist.y = epw->py - plp->py;
    dist.z = epw->pz - plp->pz;
    
    njSetMatrix(NULL, (NJS_MATRIX*)epw->exp0);
    
    njInvertMatrix(NULL);
    
    njCalcPoint(NULL, &dist, &dist);
    
    EXP0_I(68) = bhArcTan2(dist.x, dist.z);
    
	return (abs(EXP0_I(68)) < ang) ? 1 : 0;
}

// 100% matching!
void bhEne23_Shape(BH_PWORK* epw) 
{
    if ((epw->mdflg & 0x2)) 
    {
        if (epw->type != 0)
        {
            epw->mdflg &= ~0x2;
        }
        
        if ((epw->flg & 0x2)) 
        {
            EXP0_I(284) += 91;
        } 
        else 
        {
            EXP0_I(284) += 1456;
        }
        
        epw->shp_ct = 500.0f + (500.0f * njSin(EXP0_I(284)));
    }
}

// 100% matching!
void bhEne23_CallSE(BH_PWORK* epw)
{
    int fno;

    if (epw->mnwP == epw->mnwPb) 
    {
        fno = epw->frm_no / 65536;
        
        switch (epw->mtn_no) 
        {                    
        case 2:
            if ((fno == 0) || (fno == 9) || (fno == 14) || (fno == 23)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
            }
            
            break;
        case 22:
            if ((fno == 0) || (fno == 6)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
            }       
            
            break;
        case 3:  
        case 4:
        case 24:
        case 25:          
            fno %= 34;
            
            if ((fno == 0) || (fno == 9) || (fno == 14) || (fno == 23)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
            }
            
            break;
        case 11:
            if ((fno == 29) || (fno == 44)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74503);
            }      
            
            break;
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
            if (fno == 0) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px,  8976);
            }     
            
            break;
        case 37:
            if (fno == 13) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74510);
            }    
            
            break;
        case 42:
            if (fno == 20) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74510);
            }     
            
            break;
        case 40:
        case 45:
        case 54:
        case 55:
            if (fno == 1) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74510);
            }      
            
            break;
        case 48:            
        case 50:
            if (fno == 26) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px,  8978);
            }           
            
            break;
        }
    }
}

// 100% matching!
void bhEne23_HitMark(BH_PWORK* epw)
{
	NJS_POINT3 ofp;
	BLOOD_TBL* blp;
	int i;          
    int range;      

    blp = &BloodTbl[epw->djnt_no];
    
    range = 0;
    
    if ((epw->comb_flg & 0x10)) 
    {
        range = 0;
    }
    
    if ((epw->comb_flg & 0x20)) 
    {
        range = 1;
    }
    
    if ((epw->comb_flg & 0x40)) 
    {
        range = 2;
    }
    
    if (DmgReact[epw->wpnr_no].type[range] >= 0) 
    {
        ofp.x = blp->ofp.x;
        ofp.y = blp->ofp.y;
        ofp.z = blp->ofp.z;
        
        ofp.x += (blp->rx * (-rand() / -2.1474836E9f)) - (blp->rx / 2.0f);
        ofp.y += (blp->ry * (-rand() / -2.1474836E9f)) - (blp->ry / 2.0f);
        ofp.z += (blp->rz * (-rand() / -2.1474836E9f)) - (blp->rz / 2.0f);
        
        bhEne_SetBloodEffectBurst(epw, DmgReact[epw->wpnr_no].type[range], epw->djnt_no, &ofp, 0);
        
        if (DmgReact[epw->wpnr_no].bloodstain[range] != 0) 
        {
            bhEne_SetBloodstain(epw, 0, epw->djnt_no, &ofp);
        }
    }
    
    if (((DmgReact[epw->wpnr_no].exef & 0x1)) && (blp->flg == 0)) 
    {
        for (i = 0; i < 4; i++) 
        {
            ofp.x = blp->ofp.x;
            ofp.y = blp->ofp.y;
            ofp.z = blp->ofp.z;
            
            ofp.x += (blp->rx * (-rand() / -2.1474836E9f)) - (blp->rx / 2.0f);
            ofp.y += (blp->ry * (-rand() / -2.1474836E9f)) - (blp->ry / 2.0f);
            ofp.z += (blp->rz * (-rand() / -2.1474836E9f)) - (blp->rz / 2.0f);
            
            bhEne_SetFireEffect(epw, epw->djnt_no, &ofp, 0.5f + (0.5f * (-rand() / -2.1474836E9f)), (int)(40.0f * (-rand() / -2.1474836E9f)) + 20);
        } 
    }
    
    if (((DmgReact[epw->wpnr_no].exef & 0x2)) && (blp->flg == 0)) 
    {
        ofp.x = blp->ofp.x;
        ofp.y = blp->ofp.y;
        ofp.z = blp->ofp.z;
        
        ofp.x += (blp->rx * (-rand() / -2.1474836E9f)) - (blp->rx / 2.0f);
        ofp.y += (blp->ry * (-rand() / -2.1474836E9f)) - (blp->ry / 2.0f);
        ofp.z += (blp->rz * (-rand() / -2.1474836E9f)) - (blp->rz / 2.0f);
        
        bhEne_SetAcidEffect(epw, epw->djnt_no, &ofp, 2.0f);
    }
    
    if ((DmgReact[epw->wpnr_no].exef & 0x4)) 
    {
        npSetAllMatColor(epw->mlwP->objP, epw->mlwP->obj_num, 0xFF201010);
    }
}
