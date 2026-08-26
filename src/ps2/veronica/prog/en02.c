#include "../../../ps2/veronica/prog/en02.h"
#include "../../../ps2/veronica/prog/en02sub.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

// ENEMY: Gulp Worm 

typedef void (*bhEne02_Mode0_proc)(BH_PWORK*);
typedef void (*bhEne02_MoveMode2_proc)(BH_PWORK*);
typedef void (*bhEne02_DamageMode2_proc)(BH_PWORK*);
typedef void (*bhEne02_DeadMode2_proc)(BH_PWORK*);

NJS_POINT3 cler_042[20] =
{
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, -0.620734f, -2.12481f },
    { 0.0f, -0.627121f, -2.187942f },
    { 0.0f, -0.648964f, -2.072721f },
    { 0.0f, -0.671436f, -1.780175f },
    { 0.0f, -0.646234f, -1.310607f },
    { 0.0f, -0.563992f, -1.028731f },
    { 0.0f, -0.424708f, -1.016538f },
    { 0.0f, -0.229293f, -1.00816f },
    { 0.0f, -0.10395f, -1.003594f },
    { 0.0f, -0.157576f, -1.00284f },
    { 0.0f, -0.246373f, -1.005897f },
    { 0.0f, -0.241412f, -1.01277f },
    { 0.0f, -0.120057f, -0.80743f },
    { 0.0f, 0.200556f, -0.420704f },
    { 0.0f, 0.254786f, -0.267502f },
    { 0.0f, -0.013909f, -0.218467f },
    { 0.0f, -0.188876f, -0.169968f },
    { 0.0f, -0.146966f, -0.121239f },
    { 0.0f, 0.000819f, -0.072285f },
};
NJS_POINT3 cler_043[20] = 
{
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, -1.059124f, 1.89403f },
    { 0.0f, -0.917969f, 1.896158f },
    { 0.0f, -1.156633f, 1.890566f },
    { 0.0f, -1.079631f, 1.877255f },
    { 0.0f, -0.934274f, 1.856224f },
    { 0.0f, -1.023546f, 1.827473f },
    { 0.0f, -0.843379f, 1.791f },
    { 0.0f, -0.393773f, 1.458952f },
    { 0.0f, 0.140793f, 0.900272f },
    { 0.0f, 0.333097f, 0.492113f },
    { 0.0f, 0.261335f, 0.234747f },
    { 0.0f, -0.059474f, 0.128166f },
    { 0.0f, -0.363428f, 0.172373f },
    { 0.0f, -0.411375f, 0.339531f },
    { 0.0f, -0.195706f, 0.408201f },
    { 0.0f, 0.063265f, 0.416121f },
    { 0.0f, 0.033204f, 0.387409f },
    { 0.0f, -0.255225f, 0.322071f },
    { 0.0f, -0.10127f, 0.220104f },
};
NJS_POINT3 cler_045[51] = 
{
    { 0.0f, 0.0f, 0.0f },
    { 0.000189f, 0.000204f, 0.024727f },
    { 0.000135f, 0.001824f, 0.016388f },
    { -0.000572f, 0.005267f, 0.00716f },
    { -0.001929f, 0.010533f, -0.00296f },
    { -0.003937f, 0.017619f, -0.013968f },
    { -0.006596f, 0.026527f, -0.025865f },
    { -0.009906f, 0.037258f, -0.038655f },
    { -0.013868f, 0.049811f, -0.052331f },
    { -0.018479f, 0.064185f, -0.066901f },
    { -0.023743f, 0.08038f, -0.082355f },
    { -0.029657f, 0.098399f, -0.098705f },
    { -0.041943f, 0.11824f, -0.115941f },
    { -0.057238f, 0.1399f, -0.134067f },
    { -0.068146f, 0.163384f, -0.156576f },
    { -0.074665f, 0.167295f, -0.18035f },
    { -0.076794f, 0.171939f, -0.20034f },
    { -0.074535f, 0.208866f, -0.216551f },
    { -0.067887f, 0.276337f, -0.228973f },
    { -0.056851f, 0.260755f, -0.237616f },
    { -0.041424f, 0.234464f, -0.242475f },
    { -0.021611f, 0.277857f, -0.243551f },
    { -0.002011f, 0.3249f, -0.240845f },
    { 0.013014f, 0.328456f, -0.234354f },
    { 0.025889f, 0.330988f, -0.224081f },
    { 0.036616f, 0.332499f, -0.210024f },
    { 0.045193f, 0.332987f, -0.20052f },
    { 0.051621f, 0.332453f, -0.194435f },
    { 0.055899f, 0.330896f, -0.182867f },
    { 0.058027f, 0.328317f, -0.165821f },
    { 0.058007f, 0.324714f, -0.143297f },
    { 0.055747f, 0.320091f, -0.11529f },
    { 0.050819f, 0.314443f, -0.081804f },
    { 0.045415f, 0.307774f, -0.042839f },
    { 0.04005f, 0.300082f, -0.014368f },
    { 0.034724f, 0.291368f, -0.000868f },
    { 0.029436f, 0.281631f, 0.011396f },
    { 0.024189f, 0.270871f, 0.022425f },
    { 0.01898f, 0.259089f, 0.032219f },
    { 0.013811f, 0.246286f, 0.040773f },
    { 0.008681f, 0.232458f, 0.048096f },
    { 0.005656f, 0.217609f, 0.05418f },
    { 0.004759f, 0.201737f, 0.059031f },
    { 0.003938f, 0.184843f, 0.062643f },
    { 0.003193f, 0.166926f, 0.065021f },
    { 0.002523f, 0.147986f, 0.066162f },
    { 0.001927f, 0.128025f, 0.066069f },
    { 0.001409f, 0.107041f, 0.064739f },
    { 0.000964f, 0.085033f, 0.062174f },
    { 0.000595f, 0.062004f, 0.058371f },
    { 0.000302f, 0.037952f, 0.053335f },
};
NJS_POINT3 cher_060[20] = 
{
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, -0.779553f, -1.461983f },
    { 0.0f, -0.750942f, -1.447103f },
    { 0.0f, -0.722287f, -1.429072f },
    { 0.0f, -0.69359f, -1.407892f },
    { 0.0f, -0.66485f, -1.383564f },
    { 0.0f, -0.636068f, -1.356088f },
    { 0.0f, -0.607241f, -1.32546f },
    { 0.0f, -0.578373f, -1.291683f },
    { 0.0f, -0.549461f, -1.254758f },
    { 0.0f, -0.520506f, -1.214684f },
    { 0.0f, -0.491509f, -1.171461f },
    { 0.0f, -0.46247f, -1.125088f },
    { 6.6e-05f, -0.141891f, -0.954111f },
    { 0.000155f, 0.204556f, -0.689911f },
    { 0.000176f, 0.152544f, -0.469623f },
    { 0.000132f, -0.059541f, -0.293259f },
    { 2.2e-05f, -0.114551f, -0.160811f },
    { -0.000154f, -0.092301f, -0.072282f },
    { -0.000397f, 0.00721f, -0.02767f },
};
NJS_POINT3 cher_061[20] = 
{
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, -1.023485f, 2.016719f },
    { 0.0f, -0.981441f, 1.855077f },
    { 0.0f, -0.939375f, 1.720633f },
    { 0.0f, -0.897289f, 1.613388f },
    { 0.0f, -0.855185f, 1.533343f },
    { 0.0f, -0.813058f, 1.480495f },
    { 0.0f, -0.770913f, 1.454845f },
    { 0.0f, -0.728744f, 1.456395f },
    { 0.0f, -0.187407f, 0.956171f },
    { 0.0f, 0.120347f, 0.575286f },
    { 0.0f, -0.240101f, 0.703337f },
    { 0.0f, -0.361943f, 0.67611f },
    { 0.0f, -0.22268f, 0.611448f },
    { 0.0f, -0.045971f, 0.493896f },
    { 0.0f, -0.01742f, 0.348406f },
    { 0.0f, -0.032555f, 0.270178f },
    { 0.0f, -0.017353f, 0.242271f },
    { 0.0f, 0.010803f, 0.188967f },
    { 0.0f, 0.010113f, 0.110258f },
};
NJS_POINT3 cher_063[50] = 
{
    { 0.0f, 0.0f, 0.0f },
    { 0.01499f, 0.00029f, 0.030832f },
    { 0.02403f, -6e-06f, 0.01372f },
    { 0.032291f, -0.000251f, -0.000155f },
    { 0.039773f, -0.000453f, -0.010793f },
    { 0.046473f, -0.000606f, -0.018191f },
    { 0.052396f, -0.00071f, -0.022354f },
    { 0.057539f, -0.00077f, -0.023277f },
    { 0.061901f, -0.000781f, -0.020964f },
    { 0.065484f, -0.000745f, -0.027778f },
    { 0.068289f, -0.000661f, -0.049477f },
    { 0.070312f, -0.000531f, -0.076561f },
    { 0.071556f, -0.000354f, -0.109041f },
    { 0.072021f, -0.000128f, -0.146906f },
    { 0.07833f, 0.048734f, -0.172268f },
    { 0.08752f, 0.138106f, -0.185469f },
    { 0.091485f, 0.215344f, -0.204576f },
    { 0.090229f, 0.280442f, -0.229593f },
    { 0.083749f, 0.333404f, -0.26059f },
    { 0.072044f, 0.374224f, -0.299078f },
    { 0.055118f, 0.402911f, -0.329302f },
    { 0.032967f, 0.419457f, -0.344871f },
    { 0.009256f, 0.423868f, -0.345787f },
    { 0.00267f, 0.416138f, -0.332049f },
    { -0.001042f, 0.396297f, -0.303657f },
    { -0.004824f, 0.40255f, -0.263276f },
    { -0.008673f, 0.434275f, -0.225015f },
    { -0.012591f, 0.458427f, -0.190285f },
    { -0.016576f, 0.475005f, -0.158771f },
    { -0.02063f, 0.484011f, -0.130475f },
    { -0.024752f, 0.48544f, -0.105394f },
    { -0.028942f, 0.479296f, -0.083534f },
    { -0.0332f, 0.465578f, -0.064892f },
    { -0.037526f, 0.444289f, -0.049465f },
    { -0.041921f, 0.415421f, -0.037258f },
    { -0.046382f, 0.378981f, -0.028269f },
    { -0.050913f, 0.334968f, -0.022497f },
    { -0.055513f, 0.283382f, -0.019942f },
    { -0.060178f, 0.224219f, -0.020607f },
    { -0.063639f, 0.184548f, -0.003177f },
    { -0.065679f, 0.169313f, 0.030195f },
    { -0.067461f, 0.153923f, 0.057129f },
    { -0.068989f, 0.138379f, 0.077625f },
    { -0.070259f, 0.122677f, 0.091685f },
    { -0.071275f, 0.106824f, 0.0993f },
    { -0.072033f, 0.090814f, 0.100481f },
    { -0.072537f, 0.074649f, 0.095221f },
    { -0.072784f, 0.05833f, 0.083524f },
    { -0.072775f, 0.041857f, 0.065386f },
    { -0.072509f, 0.025227f, 0.040813f },
};

static EGG_WORK child = 
{ 
	0x8001, 31, 0 
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
    { {  1,  1,  0 }, { 1, 1, 0 }, 0 },
    { {  1,  1,  1 }, { 0, 0, 0 }, 0 },
    { {  2,  1,  0 }, { 1, 0, 0 }, 0 },
    { {  0,  0,  0 }, { 0, 0, 0 }, 0 },
    { {  1,  1,  0 }, { 0, 0, 0 }, 0 },
    { {  1,  1,  0 }, { 1, 1, 1 }, 1 },
    { { -1, -1, -1 }, { 0, 0, 0 }, 2 },
    { { -1, -1, -1 }, { 0, 0, 0 }, 1 },
    { { -1, -1, -1 }, { 0, 0, 0 }, 0 },
    { {  2,  2,  2 }, { 1, 1, 1 }, 0 },
    { {  1,  1,  1 }, { 0, 0, 0 }, 1 },
    { {  2,  2,  2 }, { 1, 1, 1 }, 1 }
};
static COMBWEP_WORK CombWepTbl[21] = 
{
    {   0, {  0,  0,  0 },  0, 0 },
    {   0, {  0,  0,  0 },  0, 0 },
    {  40, { 10, 10, 10 }, 20, 0 },
    {  50, { 15, 10,  8 }, 60, 0 },
    {  50, { 15, 10,  8 }, 60, 0 },
    {  50, { 15, 10,  8 }, 60, 0 },
    {  50, { 15, 10,  8 }, 60, 0 },
    {  50, { 15, 10,  8 }, 60, 0 },
    { 250, { 10, 10, 10 }, 30, 0 },
    {   0, { 10, 10, 10 }, 60, 0 },
    {  30, { 10, 10, 10 }, 60, 0 },
    {   0, { 10, 10, 10 }, 60, 0 },
    { 120, { 10, 10, 10 }, 30, 0 },
    {   0, { 10, 10, 10 }, 60, 0 },
    {   0, { 10, 10, 10 }, 60, 0 },
    {   0, { 10, 10, 10 }, 60, 0 },
    {  15, {  1,  1,  1 },  5, 0 },
    {   0, { 10, 10, 10 }, 60, 0 },
    {   0, { 10, 10, 10 }, 60, 0 },
    {   0, { 10, 10, 10 }, 60, 0 },
	{   0, { 10, 10, 10 }, 60, 0 }
};
static COMBJOINT_WORK CombJointTbl[24];
static BLOOD_TBL BloodTbl[24];
// SD_01
// SD_03
// SD_11
// SD_14
// SD_16
// SD_17
// P0_42
// P0_43
// SandEffectTbl
static CPCL CapColTab[13];

bhEne02_Mode0_proc bhEne02_Mode0[6] =
{
    bhEne02_Init,
    bhEne02_Move,
    bhEne02_Nage,
    bhEne02_Damage,
    bhEne02_Die,
    bhEne_Event
};
bhEne02_MoveMode2_proc bhEne02_MoveMode2[6] =
{
    bhEne02_MV00,
    bhEne02_MV00,
    bhEne02_MV02,
    bhEne02_MV03,
    bhEne02_MV04,
    bhEne02_MV05
};
bhEne02_DamageMode2_proc bhEne02_DamageMode2[2] =
{
    bhEne02_DG00,
    bhEne02_DG01
};
bhEne02_DeadMode2_proc bhEne02_DeadMode2[2] =
{
    bhEne02_DD00,
    bhEne02_DD01
};

// 
// Start address: 0x18f830
void bhEne02(BH_PWORK* epw)
{
	// Line 738, Address: 0x18f830, Func Offset: 0
	// Line 740, Address: 0x18f840, Func Offset: 0x10
	// Line 743, Address: 0x18f860, Func Offset: 0x30
	// Line 744, Address: 0x18f874, Func Offset: 0x44
	// Line 748, Address: 0x18f87c, Func Offset: 0x4c
	// Line 751, Address: 0x18f890, Func Offset: 0x60
	// Line 754, Address: 0x18f898, Func Offset: 0x68
	// Line 757, Address: 0x18f8a0, Func Offset: 0x70
	// Line 759, Address: 0x18f8b4, Func Offset: 0x84
	// Line 760, Address: 0x18f8bc, Func Offset: 0x8c
	// Line 764, Address: 0x18f8e0, Func Offset: 0xb0
	// Line 767, Address: 0x18f8f8, Func Offset: 0xc8
	// Line 770, Address: 0x18f900, Func Offset: 0xd0
	// Line 773, Address: 0x18f908, Func Offset: 0xd8
	// Line 774, Address: 0x18f910, Func Offset: 0xe0
	// Func End, Address: 0x18f920, Func Offset: 0xf0
	scePrintf("bhEne02 - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x18f920
void bhEne02_Init(BH_PWORK* epw)
{
	int i;
	// Line 784, Address: 0x18f920, Func Offset: 0
	// Line 788, Address: 0x18f934, Func Offset: 0x14
	// Line 789, Address: 0x18f940, Func Offset: 0x20
	// Line 790, Address: 0x18f948, Func Offset: 0x28
	// Line 788, Address: 0x18f94c, Func Offset: 0x2c
	// Line 789, Address: 0x18f954, Func Offset: 0x34
	// Line 792, Address: 0x18f958, Func Offset: 0x38
	// Line 793, Address: 0x18f95c, Func Offset: 0x3c
	// Line 796, Address: 0x18f964, Func Offset: 0x44
	// Line 789, Address: 0x18f96c, Func Offset: 0x4c
	// Line 790, Address: 0x18f974, Func Offset: 0x54
	// Line 791, Address: 0x18f980, Func Offset: 0x60
	// Line 792, Address: 0x18f98c, Func Offset: 0x6c
	// Line 793, Address: 0x18f990, Func Offset: 0x70
	// Line 794, Address: 0x18f994, Func Offset: 0x74
	// Line 795, Address: 0x18f998, Func Offset: 0x78
	// Line 796, Address: 0x18f99c, Func Offset: 0x7c
	// Line 799, Address: 0x18f9bc, Func Offset: 0x9c
	// Line 800, Address: 0x18f9c4, Func Offset: 0xa4
	// Line 801, Address: 0x18f9c8, Func Offset: 0xa8
	// Line 802, Address: 0x18f9cc, Func Offset: 0xac
	// Line 805, Address: 0x18f9d0, Func Offset: 0xb0
	// Line 808, Address: 0x18f9dc, Func Offset: 0xbc
	// Line 809, Address: 0x18f9e8, Func Offset: 0xc8
	// Line 812, Address: 0x18f9f8, Func Offset: 0xd8
	// Line 819, Address: 0x18fa14, Func Offset: 0xf4
	// Line 815, Address: 0x18fa18, Func Offset: 0xf8
	// Line 819, Address: 0x18fa1c, Func Offset: 0xfc
	// Line 812, Address: 0x18fa20, Func Offset: 0x100
	// Line 813, Address: 0x18fa24, Func Offset: 0x104
	// Line 819, Address: 0x18fa28, Func Offset: 0x108
	// Line 813, Address: 0x18fa2c, Func Offset: 0x10c
	// Line 814, Address: 0x18fa34, Func Offset: 0x114
	// Line 815, Address: 0x18fa40, Func Offset: 0x120
	// Line 816, Address: 0x18fa4c, Func Offset: 0x12c
	// Line 817, Address: 0x18fa5c, Func Offset: 0x13c
	// Line 819, Address: 0x18fa6c, Func Offset: 0x14c
	// Line 820, Address: 0x18fa7c, Func Offset: 0x15c
	// Line 822, Address: 0x18fa80, Func Offset: 0x160
	// Line 824, Address: 0x18fa84, Func Offset: 0x164
	// Line 819, Address: 0x18fa88, Func Offset: 0x168
	// Line 820, Address: 0x18fa8c, Func Offset: 0x16c
	// Line 821, Address: 0x18fa9c, Func Offset: 0x17c
	// Line 822, Address: 0x18faa8, Func Offset: 0x188
	// Line 826, Address: 0x18fab4, Func Offset: 0x194
	// Line 827, Address: 0x18fad0, Func Offset: 0x1b0
	// Line 830, Address: 0x18fad4, Func Offset: 0x1b4
	// Line 829, Address: 0x18fad8, Func Offset: 0x1b8
	// Line 826, Address: 0x18fadc, Func Offset: 0x1bc
	// Line 827, Address: 0x18fae4, Func Offset: 0x1c4
	// Line 830, Address: 0x18fae8, Func Offset: 0x1c8
	// Line 827, Address: 0x18faec, Func Offset: 0x1cc
	// Line 828, Address: 0x18faf8, Func Offset: 0x1d8
	// Line 829, Address: 0x18fb08, Func Offset: 0x1e8
	// Line 830, Address: 0x18fb18, Func Offset: 0x1f8
	// Line 833, Address: 0x18fb20, Func Offset: 0x200
	// Line 836, Address: 0x18fb30, Func Offset: 0x210
	// Line 839, Address: 0x18fb3c, Func Offset: 0x21c
	// Line 840, Address: 0x18fb40, Func Offset: 0x220
	// Line 836, Address: 0x18fb44, Func Offset: 0x224
	// Line 837, Address: 0x18fb70, Func Offset: 0x250
	// Line 838, Address: 0x18fb94, Func Offset: 0x274
	// Line 839, Address: 0x18fba0, Func Offset: 0x280
	// Line 840, Address: 0x18fbac, Func Offset: 0x28c
	// Line 841, Address: 0x18fbb8, Func Offset: 0x298
	// Line 842, Address: 0x18fbc4, Func Offset: 0x2a4
	// Line 843, Address: 0x18fbd0, Func Offset: 0x2b0
	// Line 847, Address: 0x18fbdc, Func Offset: 0x2bc
	// Line 851, Address: 0x18fbe4, Func Offset: 0x2c4
	// Line 854, Address: 0x18fbe8, Func Offset: 0x2c8
	// Line 847, Address: 0x18fbec, Func Offset: 0x2cc
	// Line 848, Address: 0x18fbf0, Func Offset: 0x2d0
	// Line 855, Address: 0x18fbf4, Func Offset: 0x2d4
	// Line 856, Address: 0x18fbf8, Func Offset: 0x2d8
	// Line 857, Address: 0x18fbfc, Func Offset: 0x2dc
	// Line 848, Address: 0x18fc00, Func Offset: 0x2e0
	// Line 851, Address: 0x18fc04, Func Offset: 0x2e4
	// Line 858, Address: 0x18fc08, Func Offset: 0x2e8
	// Line 859, Address: 0x18fc0c, Func Offset: 0x2ec
	// Line 860, Address: 0x18fc10, Func Offset: 0x2f0
	// Line 851, Address: 0x18fc14, Func Offset: 0x2f4
	// Line 854, Address: 0x18fc18, Func Offset: 0x2f8
	// Line 855, Address: 0x18fc1c, Func Offset: 0x2fc
	// Line 856, Address: 0x18fc20, Func Offset: 0x300
	// Line 857, Address: 0x18fc24, Func Offset: 0x304
	// Line 858, Address: 0x18fc28, Func Offset: 0x308
	// Line 859, Address: 0x18fc2c, Func Offset: 0x30c
	// Line 860, Address: 0x18fc30, Func Offset: 0x310
	// Line 861, Address: 0x18fc34, Func Offset: 0x314
	// Line 862, Address: 0x18fc38, Func Offset: 0x318
	// Line 866, Address: 0x18fc40, Func Offset: 0x320
	// Line 869, Address: 0x18fc48, Func Offset: 0x328
	// Line 862, Address: 0x18fc4c, Func Offset: 0x32c
	// Line 865, Address: 0x18fc54, Func Offset: 0x334
	// Line 866, Address: 0x18fc58, Func Offset: 0x338
	// Line 869, Address: 0x18fc5c, Func Offset: 0x33c
	// Line 872, Address: 0x18fc60, Func Offset: 0x340
	// Line 877, Address: 0x18fc68, Func Offset: 0x348
	// Line 866, Address: 0x18fc6c, Func Offset: 0x34c
	// Line 869, Address: 0x18fc74, Func Offset: 0x354
	// Line 875, Address: 0x18fc78, Func Offset: 0x358
	// Line 876, Address: 0x18fc80, Func Offset: 0x360
	// Line 869, Address: 0x18fc84, Func Offset: 0x364
	// Line 872, Address: 0x18fc8c, Func Offset: 0x36c
	// Line 875, Address: 0x18fc90, Func Offset: 0x370
	// Line 877, Address: 0x18fc94, Func Offset: 0x374
	// Line 875, Address: 0x18fc98, Func Offset: 0x378
	// Line 876, Address: 0x18fc9c, Func Offset: 0x37c
	// Line 875, Address: 0x18fca0, Func Offset: 0x380
	// Line 876, Address: 0x18fca8, Func Offset: 0x388
	// Line 877, Address: 0x18fcb0, Func Offset: 0x390
	// Line 876, Address: 0x18fcb4, Func Offset: 0x394
	// Line 877, Address: 0x18fcbc, Func Offset: 0x39c
	// Line 878, Address: 0x18fccc, Func Offset: 0x3ac
	// Func End, Address: 0x18fce4, Func Offset: 0x3c4
}*/

// 100% matching!
void bhEne02_Brain(BH_PWORK* epw)
{
	bhEne02_BR00(epw);
}

// 
// Start address: 0x18fd00
void bhEne02_BR00(BH_PWORK* epw)
{
	int i;
	NJS_POINT3 pos;
	NJS_POINT3 vec;
	// Line 900, Address: 0x18fd00, Func Offset: 0
	// Line 906, Address: 0x18fd18, Func Offset: 0x18
	// Line 908, Address: 0x18fd2c, Func Offset: 0x2c
	// Line 911, Address: 0x18fd44, Func Offset: 0x44
	// Line 918, Address: 0x18fd4c, Func Offset: 0x4c
	// Line 919, Address: 0x18fd5c, Func Offset: 0x5c
	// Line 920, Address: 0x18fd60, Func Offset: 0x60
	// Line 921, Address: 0x18fd64, Func Offset: 0x64
	// Line 919, Address: 0x18fd68, Func Offset: 0x68
	// Line 920, Address: 0x18fd6c, Func Offset: 0x6c
	// Line 921, Address: 0x18fd74, Func Offset: 0x74
	// Line 922, Address: 0x18fd7c, Func Offset: 0x7c
	// Line 923, Address: 0x18fd98, Func Offset: 0x98
	// Line 924, Address: 0x18fd9c, Func Offset: 0x9c
	// Line 927, Address: 0x18fdac, Func Offset: 0xac
	// Line 924, Address: 0x18fdb0, Func Offset: 0xb0
	// Line 932, Address: 0x18fdb8, Func Offset: 0xb8
	// Line 933, Address: 0x18fddc, Func Offset: 0xdc
	// Line 934, Address: 0x18fde4, Func Offset: 0xe4
	// Line 937, Address: 0x18fdf4, Func Offset: 0xf4
	// Line 938, Address: 0x18fe24, Func Offset: 0x124
	// Line 940, Address: 0x18fe44, Func Offset: 0x144
	// Line 938, Address: 0x18fe48, Func Offset: 0x148
	// Line 940, Address: 0x18fe58, Func Offset: 0x158
	// Line 941, Address: 0x18fe7c, Func Offset: 0x17c
	// Line 942, Address: 0x18fe80, Func Offset: 0x180
	// Line 943, Address: 0x18fe84, Func Offset: 0x184
	// Line 945, Address: 0x18fe88, Func Offset: 0x188
	// Line 946, Address: 0x18fea0, Func Offset: 0x1a0
	// Line 947, Address: 0x18fee4, Func Offset: 0x1e4
	// Line 948, Address: 0x18feec, Func Offset: 0x1ec
	// Line 951, Address: 0x18ff30, Func Offset: 0x230
	// Line 958, Address: 0x18ff38, Func Offset: 0x238
	// Line 959, Address: 0x18ff3c, Func Offset: 0x23c
	// Line 960, Address: 0x18ff40, Func Offset: 0x240
	// Line 958, Address: 0x18ff44, Func Offset: 0x244
	// Line 959, Address: 0x18ff48, Func Offset: 0x248
	// Line 960, Address: 0x18ff50, Func Offset: 0x250
	// Line 961, Address: 0x18ff58, Func Offset: 0x258
	// Line 962, Address: 0x18ff74, Func Offset: 0x274
	// Line 963, Address: 0x18ff78, Func Offset: 0x278
	// Line 966, Address: 0x18ff88, Func Offset: 0x288
	// Line 963, Address: 0x18ff8c, Func Offset: 0x28c
	// Line 971, Address: 0x18ff94, Func Offset: 0x294
	// Line 972, Address: 0x18ffb8, Func Offset: 0x2b8
	// Line 973, Address: 0x18ffc0, Func Offset: 0x2c0
	// Line 976, Address: 0x18ffd0, Func Offset: 0x2d0
	// Line 977, Address: 0x190000, Func Offset: 0x300
	// Line 979, Address: 0x190020, Func Offset: 0x320
	// Line 977, Address: 0x190024, Func Offset: 0x324
	// Line 979, Address: 0x190034, Func Offset: 0x334
	// Line 981, Address: 0x190058, Func Offset: 0x358
	// Line 982, Address: 0x19005c, Func Offset: 0x35c
	// Line 983, Address: 0x190060, Func Offset: 0x360
	// Line 985, Address: 0x190064, Func Offset: 0x364
	// Line 989, Address: 0x190084, Func Offset: 0x384
	// Func End, Address: 0x1900a0, Func Offset: 0x3a0
	scePrintf("bhEne02_BR00 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne02_Move(BH_PWORK* epw)
{
	if (epw->mode1 == 1)
	{
		bhEne02_Brain(epw);
	}

	bhEne02_MoveMode2[epw->mode2](epw);

	if (((epw->flg & 0x4)) && (!(epw->flg & 0x2)))
	{
		epw->flg &= ~0x4;

		bhEne02_DamageInit(epw);
	}
}

/*// 
// Start address: 0x190130
void bhEne02_MV00(BH_PWORK* epw)
{
	float pz;
	float px;
	// Line 1022, Address: 0x190130, Func Offset: 0
	// Line 1025, Address: 0x190140, Func Offset: 0x10
	// Line 1027, Address: 0x190160, Func Offset: 0x30
	// Line 1028, Address: 0x19016c, Func Offset: 0x3c
	// Line 1029, Address: 0x190170, Func Offset: 0x40
	// Line 1027, Address: 0x190174, Func Offset: 0x44
	// Line 1028, Address: 0x190180, Func Offset: 0x50
	// Line 1029, Address: 0x19018c, Func Offset: 0x5c
	// Line 1030, Address: 0x190198, Func Offset: 0x68
	// Line 1031, Address: 0x1901a4, Func Offset: 0x74
	// Line 1032, Address: 0x1901a8, Func Offset: 0x78
	// Line 1034, Address: 0x1901ac, Func Offset: 0x7c
	// Line 1036, Address: 0x1901f0, Func Offset: 0xc0
	// Line 1037, Address: 0x190234, Func Offset: 0x104
	// Line 1038, Address: 0x19023c, Func Offset: 0x10c
	// Line 1039, Address: 0x19024c, Func Offset: 0x11c
	// Line 1041, Address: 0x190258, Func Offset: 0x128
	// Line 1042, Address: 0x190268, Func Offset: 0x138
	// Line 1043, Address: 0x190280, Func Offset: 0x150
	// Line 1044, Address: 0x19029c, Func Offset: 0x16c
	// Line 1045, Address: 0x1902a4, Func Offset: 0x174
	// Line 1046, Address: 0x1902bc, Func Offset: 0x18c
	// Line 1050, Address: 0x1902dc, Func Offset: 0x1ac
	// Line 1051, Address: 0x1902f4, Func Offset: 0x1c4
	// Line 1050, Address: 0x1902f8, Func Offset: 0x1c8
	// Line 1051, Address: 0x190308, Func Offset: 0x1d8
	// Line 1054, Address: 0x190314, Func Offset: 0x1e4
	// Line 1051, Address: 0x190318, Func Offset: 0x1e8
	// Line 1054, Address: 0x190328, Func Offset: 0x1f8
	// Line 1055, Address: 0x190344, Func Offset: 0x214
	// Line 1057, Address: 0x19036c, Func Offset: 0x23c
	// Line 1058, Address: 0x19037c, Func Offset: 0x24c
	// Line 1062, Address: 0x190384, Func Offset: 0x254
	// Line 1063, Address: 0x190394, Func Offset: 0x264
	// Line 1064, Address: 0x190398, Func Offset: 0x268
	// Line 1063, Address: 0x19039c, Func Offset: 0x26c
	// Line 1064, Address: 0x1903a4, Func Offset: 0x274
	// Line 1068, Address: 0x1903a8, Func Offset: 0x278
	// Line 1069, Address: 0x1903b8, Func Offset: 0x288
	// Line 1070, Address: 0x1903d8, Func Offset: 0x2a8
	// Line 1071, Address: 0x1903f8, Func Offset: 0x2c8
	// Line 1072, Address: 0x190408, Func Offset: 0x2d8
	// Line 1073, Address: 0x190428, Func Offset: 0x2f8
	// Line 1074, Address: 0x190444, Func Offset: 0x314
	// Line 1078, Address: 0x190488, Func Offset: 0x358
	// Line 1079, Address: 0x1904b0, Func Offset: 0x380
	// Line 1080, Address: 0x1904c8, Func Offset: 0x398
	// Line 1082, Address: 0x1904d0, Func Offset: 0x3a0
	// Line 1085, Address: 0x1904e4, Func Offset: 0x3b4
	// Func End, Address: 0x1904f8, Func Offset: 0x3c8
}

// 
// Start address: 0x190500
void bhEne02_MV02(BH_PWORK* epw)
{
	float dist;
	_anon42 ln;
	NJS_POINT3 pos;
	int i;
	_anon1* owk;
	NJS_POINT3 pos;
	NJS_POINT3 trg_pos[2];
	// Line 1095, Address: 0x190500, Func Offset: 0
	// Line 1096, Address: 0x190510, Func Offset: 0x10
	// Line 1095, Address: 0x190518, Func Offset: 0x18
	// Line 1096, Address: 0x19051c, Func Offset: 0x1c
	// Line 1102, Address: 0x190530, Func Offset: 0x30
	// Line 1104, Address: 0x190574, Func Offset: 0x74
	// Line 1107, Address: 0x19057c, Func Offset: 0x7c
	// Line 1108, Address: 0x190584, Func Offset: 0x84
	// Line 1106, Address: 0x19058c, Func Offset: 0x8c
	// Line 1104, Address: 0x190590, Func Offset: 0x90
	// Line 1110, Address: 0x190594, Func Offset: 0x94
	// Line 1112, Address: 0x190598, Func Offset: 0x98
	// Line 1116, Address: 0x19059c, Func Offset: 0x9c
	// Line 1104, Address: 0x1905a0, Func Offset: 0xa0
	// Line 1105, Address: 0x1905a8, Func Offset: 0xa8
	// Line 1106, Address: 0x1905b4, Func Offset: 0xb4
	// Line 1107, Address: 0x1905c0, Func Offset: 0xc0
	// Line 1108, Address: 0x1905cc, Func Offset: 0xcc
	// Line 1109, Address: 0x1905d8, Func Offset: 0xd8
	// Line 1110, Address: 0x1905e4, Func Offset: 0xe4
	// Line 1111, Address: 0x1905e8, Func Offset: 0xe8
	// Line 1112, Address: 0x1905ec, Func Offset: 0xec
	// Line 1113, Address: 0x1905f0, Func Offset: 0xf0
	// Line 1116, Address: 0x1905f8, Func Offset: 0xf8
	// Line 1117, Address: 0x190600, Func Offset: 0x100
	// Line 1119, Address: 0x190608, Func Offset: 0x108
	// Line 1121, Address: 0x190618, Func Offset: 0x118
	// Line 1122, Address: 0x190624, Func Offset: 0x124
	// Line 1125, Address: 0x190630, Func Offset: 0x130
	// Line 1126, Address: 0x19063c, Func Offset: 0x13c
	// Line 1127, Address: 0x190644, Func Offset: 0x144
	// Line 1130, Address: 0x190648, Func Offset: 0x148
	// Line 1127, Address: 0x19064c, Func Offset: 0x14c
	// Line 1130, Address: 0x190654, Func Offset: 0x154
	// Line 1138, Address: 0x190678, Func Offset: 0x178
	// Line 1140, Address: 0x190698, Func Offset: 0x198
	// Line 1141, Address: 0x1906a8, Func Offset: 0x1a8
	// Line 1142, Address: 0x1906ac, Func Offset: 0x1ac
	// Line 1140, Address: 0x1906b0, Func Offset: 0x1b0
	// Line 1141, Address: 0x1906b4, Func Offset: 0x1b4
	// Line 1143, Address: 0x1906b8, Func Offset: 0x1b8
	// Line 1145, Address: 0x1906bc, Func Offset: 0x1bc
	// Line 1140, Address: 0x1906c0, Func Offset: 0x1c0
	// Line 1141, Address: 0x1906c8, Func Offset: 0x1c8
	// Line 1142, Address: 0x1906d0, Func Offset: 0x1d0
	// Line 1141, Address: 0x1906d4, Func Offset: 0x1d4
	// Line 1142, Address: 0x1906dc, Func Offset: 0x1dc
	// Line 1143, Address: 0x1906e4, Func Offset: 0x1e4
	// Line 1142, Address: 0x1906e8, Func Offset: 0x1e8
	// Line 1143, Address: 0x1906f0, Func Offset: 0x1f0
	// Line 1145, Address: 0x1906f8, Func Offset: 0x1f8
	// Line 1146, Address: 0x190704, Func Offset: 0x204
	// Line 1147, Address: 0x190710, Func Offset: 0x210
	// Line 1148, Address: 0x19071c, Func Offset: 0x21c
	// Line 1149, Address: 0x19072c, Func Offset: 0x22c
	// Line 1148, Address: 0x190730, Func Offset: 0x230
	// Line 1149, Address: 0x190738, Func Offset: 0x238
	// Line 1150, Address: 0x190744, Func Offset: 0x244
	// Line 1149, Address: 0x190748, Func Offset: 0x248
	// Line 1150, Address: 0x190750, Func Offset: 0x250
	// Line 1151, Address: 0x19075c, Func Offset: 0x25c
	// Line 1150, Address: 0x190760, Func Offset: 0x260
	// Line 1151, Address: 0x190768, Func Offset: 0x268
	// Line 1152, Address: 0x190778, Func Offset: 0x278
	// Line 1153, Address: 0x190788, Func Offset: 0x288
	// Line 1154, Address: 0x19079c, Func Offset: 0x29c
	// Line 1155, Address: 0x1907a4, Func Offset: 0x2a4
	// Line 1156, Address: 0x1907b0, Func Offset: 0x2b0
	// Line 1160, Address: 0x1907c0, Func Offset: 0x2c0
	// Line 1163, Address: 0x1907c8, Func Offset: 0x2c8
	// Line 1164, Address: 0x1907cc, Func Offset: 0x2cc
	// Line 1167, Address: 0x1907d0, Func Offset: 0x2d0
	// Line 1160, Address: 0x1907d4, Func Offset: 0x2d4
	// Line 1163, Address: 0x1907e0, Func Offset: 0x2e0
	// Line 1167, Address: 0x1907e4, Func Offset: 0x2e4
	// Line 1168, Address: 0x1907ec, Func Offset: 0x2ec
	// Line 1169, Address: 0x1907f8, Func Offset: 0x2f8
	// Line 1170, Address: 0x190824, Func Offset: 0x324
	// Line 1174, Address: 0x190834, Func Offset: 0x334
	// Line 1177, Address: 0x190838, Func Offset: 0x338
	// Line 1170, Address: 0x19083c, Func Offset: 0x33c
	// Line 1177, Address: 0x190840, Func Offset: 0x340
	// Line 1171, Address: 0x190844, Func Offset: 0x344
	// Line 1170, Address: 0x190848, Func Offset: 0x348
	// Line 1171, Address: 0x19084c, Func Offset: 0x34c
	// Line 1177, Address: 0x190858, Func Offset: 0x358
	// Line 1171, Address: 0x19085c, Func Offset: 0x35c
	// Line 1177, Address: 0x190860, Func Offset: 0x360
	// Line 1171, Address: 0x190864, Func Offset: 0x364
	// Line 1174, Address: 0x190868, Func Offset: 0x368
	// Line 1177, Address: 0x19086c, Func Offset: 0x36c
	// Line 1179, Address: 0x190878, Func Offset: 0x378
	// Line 1185, Address: 0x190884, Func Offset: 0x384
	// Line 1186, Address: 0x190898, Func Offset: 0x398
	// Line 1187, Address: 0x1908a4, Func Offset: 0x3a4
	// Line 1188, Address: 0x1908ac, Func Offset: 0x3ac
	// Line 1191, Address: 0x1908b8, Func Offset: 0x3b8
	// Line 1194, Address: 0x1908c0, Func Offset: 0x3c0
	// Line 1195, Address: 0x1908cc, Func Offset: 0x3cc
	// Line 1196, Address: 0x1908d0, Func Offset: 0x3d0
	// Line 1198, Address: 0x1908d4, Func Offset: 0x3d4
	// Line 1197, Address: 0x1908d8, Func Offset: 0x3d8
	// Line 1198, Address: 0x1908dc, Func Offset: 0x3dc
	// Line 1199, Address: 0x1908e0, Func Offset: 0x3e0
	// Line 1200, Address: 0x1908e4, Func Offset: 0x3e4
	// Line 1204, Address: 0x1908f4, Func Offset: 0x3f4
	// Line 1205, Address: 0x190908, Func Offset: 0x408
	// Line 1206, Address: 0x190918, Func Offset: 0x418
	// Line 1210, Address: 0x190924, Func Offset: 0x424
	// Line 1215, Address: 0x190950, Func Offset: 0x450
	// Line 1216, Address: 0x190954, Func Offset: 0x454
	// Line 1215, Address: 0x190958, Func Offset: 0x458
	// Line 1217, Address: 0x190960, Func Offset: 0x460
	// Line 1222, Address: 0x19098c, Func Offset: 0x48c
	// Line 1224, Address: 0x1909a4, Func Offset: 0x4a4
	// Line 1225, Address: 0x1909b8, Func Offset: 0x4b8
	// Line 1224, Address: 0x1909bc, Func Offset: 0x4bc
	// Line 1225, Address: 0x1909c4, Func Offset: 0x4c4
	// Line 1228, Address: 0x1909cc, Func Offset: 0x4cc
	// Line 1225, Address: 0x1909d0, Func Offset: 0x4d0
	// Line 1228, Address: 0x1909d4, Func Offset: 0x4d4
	// Line 1230, Address: 0x1909dc, Func Offset: 0x4dc
	// Line 1232, Address: 0x1909e4, Func Offset: 0x4e4
	// Line 1230, Address: 0x1909ec, Func Offset: 0x4ec
	// Line 1232, Address: 0x1909f0, Func Offset: 0x4f0
	// Line 1230, Address: 0x1909f4, Func Offset: 0x4f4
	// Line 1232, Address: 0x1909fc, Func Offset: 0x4fc
	// Line 1233, Address: 0x190a0c, Func Offset: 0x50c
	// Line 1235, Address: 0x190a14, Func Offset: 0x514
	// Line 1236, Address: 0x190a20, Func Offset: 0x520
	// Line 1235, Address: 0x190a24, Func Offset: 0x524
	// Line 1236, Address: 0x190a2c, Func Offset: 0x52c
	// Line 1245, Address: 0x190a44, Func Offset: 0x544
	// Line 1246, Address: 0x190a4c, Func Offset: 0x54c
	// Line 1247, Address: 0x190a54, Func Offset: 0x554
	// Line 1248, Address: 0x190a5c, Func Offset: 0x55c
	// Line 1249, Address: 0x190a6c, Func Offset: 0x56c
	// Line 1250, Address: 0x190a70, Func Offset: 0x570
	// Line 1252, Address: 0x190a78, Func Offset: 0x578
	// Line 1250, Address: 0x190a80, Func Offset: 0x580
	// Line 1252, Address: 0x190a84, Func Offset: 0x584
	// Line 1253, Address: 0x190a98, Func Offset: 0x598
	// Line 1254, Address: 0x190aa4, Func Offset: 0x5a4
	// Line 1255, Address: 0x190ac0, Func Offset: 0x5c0
	// Line 1256, Address: 0x190ae0, Func Offset: 0x5e0
	// Line 1257, Address: 0x190ae8, Func Offset: 0x5e8
	// Line 1258, Address: 0x190b04, Func Offset: 0x604
	// Line 1259, Address: 0x190b28, Func Offset: 0x628
	// Line 1260, Address: 0x190b48, Func Offset: 0x648
	// Line 1261, Address: 0x190b50, Func Offset: 0x650
	// Line 1264, Address: 0x190b70, Func Offset: 0x670
	// Line 1265, Address: 0x190b80, Func Offset: 0x680
	// Line 1264, Address: 0x190b84, Func Offset: 0x684
	// Line 1265, Address: 0x190b8c, Func Offset: 0x68c
	// Line 1266, Address: 0x190b98, Func Offset: 0x698
	// Line 1265, Address: 0x190b9c, Func Offset: 0x69c
	// Line 1266, Address: 0x190ba4, Func Offset: 0x6a4
	// Line 1269, Address: 0x190bb0, Func Offset: 0x6b0
	// Line 1266, Address: 0x190bb4, Func Offset: 0x6b4
	// Line 1269, Address: 0x190bbc, Func Offset: 0x6bc
	// Line 1270, Address: 0x190bcc, Func Offset: 0x6cc
	// Line 1271, Address: 0x190bd8, Func Offset: 0x6d8
	// Line 1272, Address: 0x190be0, Func Offset: 0x6e0
	// Line 1270, Address: 0x190be4, Func Offset: 0x6e4
	// Line 1271, Address: 0x190bec, Func Offset: 0x6ec
	// Line 1272, Address: 0x190bf4, Func Offset: 0x6f4
	// Line 1271, Address: 0x190bf8, Func Offset: 0x6f8
	// Line 1272, Address: 0x190c00, Func Offset: 0x700
	// Line 1273, Address: 0x190c08, Func Offset: 0x708
	// Line 1274, Address: 0x190c14, Func Offset: 0x714
	// Line 1275, Address: 0x190c20, Func Offset: 0x720
	// Line 1276, Address: 0x190c34, Func Offset: 0x734
	// Line 1277, Address: 0x190c58, Func Offset: 0x758
	// Line 1276, Address: 0x190c5c, Func Offset: 0x75c
	// Line 1277, Address: 0x190c60, Func Offset: 0x760
	// Line 1278, Address: 0x190c68, Func Offset: 0x768
	// Line 1279, Address: 0x190c70, Func Offset: 0x770
	// Line 1280, Address: 0x190c8c, Func Offset: 0x78c
	// Line 1279, Address: 0x190c90, Func Offset: 0x790
	// Line 1280, Address: 0x190c94, Func Offset: 0x794
	// Line 1282, Address: 0x190c9c, Func Offset: 0x79c
	// Line 1283, Address: 0x190ca4, Func Offset: 0x7a4
	// Line 1284, Address: 0x190cb0, Func Offset: 0x7b0
	// Line 1285, Address: 0x190cb4, Func Offset: 0x7b4
	// Line 1283, Address: 0x190cb8, Func Offset: 0x7b8
	// Line 1284, Address: 0x190cc0, Func Offset: 0x7c0
	// Line 1285, Address: 0x190cc8, Func Offset: 0x7c8
	// Line 1284, Address: 0x190ccc, Func Offset: 0x7cc
	// Line 1285, Address: 0x190cd4, Func Offset: 0x7d4
	// Line 1286, Address: 0x190cdc, Func Offset: 0x7dc
	// Line 1287, Address: 0x190ce8, Func Offset: 0x7e8
	// Line 1288, Address: 0x190cf4, Func Offset: 0x7f4
	// Line 1289, Address: 0x190d08, Func Offset: 0x808
	// Line 1290, Address: 0x190d2c, Func Offset: 0x82c
	// Line 1289, Address: 0x190d30, Func Offset: 0x830
	// Line 1290, Address: 0x190d34, Func Offset: 0x834
	// Line 1291, Address: 0x190d3c, Func Offset: 0x83c
	// Line 1292, Address: 0x190d44, Func Offset: 0x844
	// Line 1293, Address: 0x190d64, Func Offset: 0x864
	// Line 1299, Address: 0x190d6c, Func Offset: 0x86c
	// Line 1301, Address: 0x190d74, Func Offset: 0x874
	// Line 1302, Address: 0x190d84, Func Offset: 0x884
	// Line 1305, Address: 0x190d88, Func Offset: 0x888
	// Line 1306, Address: 0x190d9c, Func Offset: 0x89c
	// Line 1309, Address: 0x190dac, Func Offset: 0x8ac
	// Line 1314, Address: 0x190db4, Func Offset: 0x8b4
	// Line 1315, Address: 0x190dc0, Func Offset: 0x8c0
	// Line 1316, Address: 0x190dd8, Func Offset: 0x8d8
	// Line 1315, Address: 0x190ddc, Func Offset: 0x8dc
	// Line 1316, Address: 0x190dec, Func Offset: 0x8ec
	// Line 1317, Address: 0x190e00, Func Offset: 0x900
	// Line 1316, Address: 0x190e04, Func Offset: 0x904
	// Line 1317, Address: 0x190e14, Func Offset: 0x914
	// Line 1318, Address: 0x190e50, Func Offset: 0x950
	// Line 1320, Address: 0x190e5c, Func Offset: 0x95c
	// Line 1321, Address: 0x190e68, Func Offset: 0x968
	// Line 1323, Address: 0x190e70, Func Offset: 0x970
	// Line 1324, Address: 0x190e88, Func Offset: 0x988
	// Line 1328, Address: 0x190e94, Func Offset: 0x994
	// Line 1329, Address: 0x190ebc, Func Offset: 0x9bc
	// Line 1331, Address: 0x190ed8, Func Offset: 0x9d8
	// Line 1335, Address: 0x190ee4, Func Offset: 0x9e4
	// Line 1336, Address: 0x190f04, Func Offset: 0xa04
	// Line 1337, Address: 0x190f08, Func Offset: 0xa08
	// Line 1336, Address: 0x190f0c, Func Offset: 0xa0c
	// Line 1337, Address: 0x190f10, Func Offset: 0xa10
	// Line 1336, Address: 0x190f14, Func Offset: 0xa14
	// Line 1337, Address: 0x190f1c, Func Offset: 0xa1c
	// Line 1338, Address: 0x190f20, Func Offset: 0xa20
	// Line 1339, Address: 0x190f34, Func Offset: 0xa34
	// Line 1340, Address: 0x190f38, Func Offset: 0xa38
	// Line 1339, Address: 0x190f3c, Func Offset: 0xa3c
	// Line 1340, Address: 0x190f40, Func Offset: 0xa40
	// Line 1339, Address: 0x190f44, Func Offset: 0xa44
	// Line 1340, Address: 0x190f4c, Func Offset: 0xa4c
	// Line 1341, Address: 0x190f50, Func Offset: 0xa50
	// Line 1342, Address: 0x190f58, Func Offset: 0xa58
	// Line 1349, Address: 0x190f6c, Func Offset: 0xa6c
	// Func End, Address: 0x190f84, Func Offset: 0xa84
}

// 
// Start address: 0x190f90
void bhEne02_MV03(BH_PWORK* epw)
{
	float dist;
	NJS_POINT3 vec;
	_anon42 ln;
	NJS_POINT3 pos;
	int tim[16][2];
	_anon1* owk;
	int i;
	NJS_POINT3 pos;
	// Line 1359, Address: 0x190f90, Func Offset: 0
	// Line 1363, Address: 0x190fa8, Func Offset: 0x18
	// Line 1359, Address: 0x190fb8, Func Offset: 0x28
	// Line 1363, Address: 0x190fc0, Func Offset: 0x30
	// Line 1368, Address: 0x190fe0, Func Offset: 0x50
	// Line 1370, Address: 0x19100c, Func Offset: 0x7c
	// Line 1373, Address: 0x191014, Func Offset: 0x84
	// Line 1375, Address: 0x191018, Func Offset: 0x88
	// Line 1378, Address: 0x19101c, Func Offset: 0x8c
	// Line 1370, Address: 0x191020, Func Offset: 0x90
	// Line 1378, Address: 0x191024, Func Offset: 0x94
	// Line 1370, Address: 0x191028, Func Offset: 0x98
	// Line 1373, Address: 0x191030, Func Offset: 0xa0
	// Line 1374, Address: 0x19103c, Func Offset: 0xac
	// Line 1378, Address: 0x191048, Func Offset: 0xb8
	// Line 1380, Address: 0x191050, Func Offset: 0xc0
	// Line 1381, Address: 0x191058, Func Offset: 0xc8
	// Line 1384, Address: 0x191060, Func Offset: 0xd0
	// Line 1385, Address: 0x191070, Func Offset: 0xe0
	// Line 1387, Address: 0x191078, Func Offset: 0xe8
	// Line 1389, Address: 0x191080, Func Offset: 0xf0
	// Line 1390, Address: 0x19108c, Func Offset: 0xfc
	// Line 1391, Address: 0x191094, Func Offset: 0x104
	// Line 1389, Address: 0x191098, Func Offset: 0x108
	// Line 1390, Address: 0x1910a0, Func Offset: 0x110
	// Line 1393, Address: 0x1910a4, Func Offset: 0x114
	// Line 1395, Address: 0x1910a8, Func Offset: 0x118
	// Line 1390, Address: 0x1910ac, Func Offset: 0x11c
	// Line 1391, Address: 0x1910b4, Func Offset: 0x124
	// Line 1392, Address: 0x1910b8, Func Offset: 0x128
	// Line 1393, Address: 0x1910bc, Func Offset: 0x12c
	// Line 1394, Address: 0x1910c0, Func Offset: 0x130
	// Line 1395, Address: 0x1910cc, Func Offset: 0x13c
	// Line 1396, Address: 0x1910d8, Func Offset: 0x148
	// Line 1397, Address: 0x1910e0, Func Offset: 0x150
	// Line 1400, Address: 0x1910e8, Func Offset: 0x158
	// Line 1401, Address: 0x1910f8, Func Offset: 0x168
	// Line 1402, Address: 0x191108, Func Offset: 0x178
	// Line 1405, Address: 0x191114, Func Offset: 0x184
	// Line 1406, Address: 0x191120, Func Offset: 0x190
	// Line 1408, Address: 0x191124, Func Offset: 0x194
	// Line 1406, Address: 0x191128, Func Offset: 0x198
	// Line 1408, Address: 0x191130, Func Offset: 0x1a0
	// Line 1409, Address: 0x191134, Func Offset: 0x1a4
	// Line 1411, Address: 0x191140, Func Offset: 0x1b0
	// Line 1412, Address: 0x191170, Func Offset: 0x1e0
	// Line 1415, Address: 0x191198, Func Offset: 0x208
	// Line 1412, Address: 0x19119c, Func Offset: 0x20c
	// Line 1415, Address: 0x1911a8, Func Offset: 0x218
	// Line 1416, Address: 0x1911cc, Func Offset: 0x23c
	// Line 1417, Address: 0x191214, Func Offset: 0x284
	// Line 1418, Address: 0x19121c, Func Offset: 0x28c
	// Line 1422, Address: 0x191268, Func Offset: 0x2d8
	// Line 1423, Address: 0x191280, Func Offset: 0x2f0
	// Line 1424, Address: 0x191290, Func Offset: 0x300
	// Line 1425, Address: 0x19129c, Func Offset: 0x30c
	// Line 1424, Address: 0x1912a0, Func Offset: 0x310
	// Line 1425, Address: 0x1912a4, Func Offset: 0x314
	// Line 1429, Address: 0x1912a8, Func Offset: 0x318
	// Line 1431, Address: 0x1912d4, Func Offset: 0x344
	// Line 1432, Address: 0x1912d8, Func Offset: 0x348
	// Line 1431, Address: 0x1912dc, Func Offset: 0x34c
	// Line 1437, Address: 0x1912e4, Func Offset: 0x354
	// Line 1438, Address: 0x191304, Func Offset: 0x374
	// Line 1440, Address: 0x191314, Func Offset: 0x384
	// Line 1438, Address: 0x191318, Func Offset: 0x388
	// Line 1439, Address: 0x19131c, Func Offset: 0x38c
	// Line 1438, Address: 0x191320, Func Offset: 0x390
	// Line 1439, Address: 0x191328, Func Offset: 0x398
	// Line 1440, Address: 0x191330, Func Offset: 0x3a0
	// Line 1439, Address: 0x191334, Func Offset: 0x3a4
	// Line 1440, Address: 0x19133c, Func Offset: 0x3ac
	// Line 1441, Address: 0x191344, Func Offset: 0x3b4
	// Line 1442, Address: 0x191350, Func Offset: 0x3c0
	// Line 1445, Address: 0x19135c, Func Offset: 0x3cc
	// Line 1446, Address: 0x191368, Func Offset: 0x3d8
	// Line 1445, Address: 0x19136c, Func Offset: 0x3dc
	// Line 1446, Address: 0x191374, Func Offset: 0x3e4
	// Line 1447, Address: 0x191388, Func Offset: 0x3f8
	// Line 1456, Address: 0x19138c, Func Offset: 0x3fc
	// Line 1457, Address: 0x1913a4, Func Offset: 0x414
	// Line 1456, Address: 0x1913a8, Func Offset: 0x418
	// Line 1457, Address: 0x1913b0, Func Offset: 0x420
	// Line 1458, Address: 0x1913b8, Func Offset: 0x428
	// Line 1459, Address: 0x1913dc, Func Offset: 0x44c
	// Line 1460, Address: 0x1913f0, Func Offset: 0x460
	// Line 1461, Address: 0x1913f4, Func Offset: 0x464
	// Line 1463, Address: 0x191408, Func Offset: 0x478
	// Line 1464, Address: 0x191420, Func Offset: 0x490
	// Line 1465, Address: 0x19142c, Func Offset: 0x49c
	// Line 1466, Address: 0x191448, Func Offset: 0x4b8
	// Line 1467, Address: 0x19145c, Func Offset: 0x4cc
	// Line 1468, Address: 0x191464, Func Offset: 0x4d4
	// Line 1469, Address: 0x191474, Func Offset: 0x4e4
	// Line 1470, Address: 0x19147c, Func Offset: 0x4ec
	// Line 1471, Address: 0x191494, Func Offset: 0x504
	// Line 1472, Address: 0x19149c, Func Offset: 0x50c
	// Line 1473, Address: 0x1914ac, Func Offset: 0x51c
	// Line 1474, Address: 0x1914c0, Func Offset: 0x530
	// Line 1475, Address: 0x1914c8, Func Offset: 0x538
	// Line 1476, Address: 0x1914d0, Func Offset: 0x540
	// Line 1480, Address: 0x1914d8, Func Offset: 0x548
	// Line 1481, Address: 0x1914e8, Func Offset: 0x558
	// Line 1480, Address: 0x1914ec, Func Offset: 0x55c
	// Line 1481, Address: 0x1914f4, Func Offset: 0x564
	// Line 1482, Address: 0x191500, Func Offset: 0x570
	// Line 1481, Address: 0x191504, Func Offset: 0x574
	// Line 1482, Address: 0x19150c, Func Offset: 0x57c
	// Line 1485, Address: 0x191518, Func Offset: 0x588
	// Line 1482, Address: 0x19151c, Func Offset: 0x58c
	// Line 1485, Address: 0x191524, Func Offset: 0x594
	// Line 1486, Address: 0x191534, Func Offset: 0x5a4
	// Line 1487, Address: 0x191544, Func Offset: 0x5b4
	// Line 1488, Address: 0x191568, Func Offset: 0x5d8
	// Line 1489, Address: 0x191570, Func Offset: 0x5e0
	// Line 1490, Address: 0x19157c, Func Offset: 0x5ec
	// Line 1495, Address: 0x191598, Func Offset: 0x608
	// Line 1497, Address: 0x1915a0, Func Offset: 0x610
	// Line 1501, Address: 0x1915b0, Func Offset: 0x620
	// Line 1502, Address: 0x1915cc, Func Offset: 0x63c
	// Line 1503, Address: 0x1915dc, Func Offset: 0x64c
	// Line 1504, Address: 0x1915f0, Func Offset: 0x660
	// Line 1505, Address: 0x1915fc, Func Offset: 0x66c
	// Line 1506, Address: 0x191604, Func Offset: 0x674
	// Line 1508, Address: 0x191610, Func Offset: 0x680
	// Line 1509, Address: 0x191618, Func Offset: 0x688
	// Line 1511, Address: 0x191628, Func Offset: 0x698
	// Line 1514, Address: 0x191630, Func Offset: 0x6a0
	// Line 1515, Address: 0x191640, Func Offset: 0x6b0
	// Line 1516, Address: 0x191644, Func Offset: 0x6b4
	// Line 1515, Address: 0x191648, Func Offset: 0x6b8
	// Line 1517, Address: 0x191650, Func Offset: 0x6c0
	// Line 1518, Address: 0x191670, Func Offset: 0x6e0
	// Line 1521, Address: 0x191678, Func Offset: 0x6e8
	// Line 1522, Address: 0x19167c, Func Offset: 0x6ec
	// Line 1521, Address: 0x191680, Func Offset: 0x6f0
	// Line 1522, Address: 0x191684, Func Offset: 0x6f4
	// Line 1525, Address: 0x191688, Func Offset: 0x6f8
	// Line 1521, Address: 0x19168c, Func Offset: 0x6fc
	// Line 1522, Address: 0x191694, Func Offset: 0x704
	// Line 1525, Address: 0x191698, Func Offset: 0x708
	// Line 1527, Address: 0x1916a8, Func Offset: 0x718
	// Line 1528, Address: 0x1916b0, Func Offset: 0x720
	// Line 1530, Address: 0x1916b8, Func Offset: 0x728
	// Line 1533, Address: 0x1916c8, Func Offset: 0x738
	// Line 1534, Address: 0x1916d4, Func Offset: 0x744
	// Line 1536, Address: 0x1916e4, Func Offset: 0x754
	// Line 1537, Address: 0x1916ec, Func Offset: 0x75c
	// Line 1538, Address: 0x19171c, Func Offset: 0x78c
	// Line 1543, Address: 0x191728, Func Offset: 0x798
	// Line 1545, Address: 0x191744, Func Offset: 0x7b4
	// Line 1546, Address: 0x191774, Func Offset: 0x7e4
	// Line 1549, Address: 0x191794, Func Offset: 0x804
	// Line 1546, Address: 0x191798, Func Offset: 0x808
	// Line 1549, Address: 0x1917a8, Func Offset: 0x818
	// Line 1550, Address: 0x1917cc, Func Offset: 0x83c
	// Line 1553, Address: 0x1917d0, Func Offset: 0x840
	// Line 1555, Address: 0x1917e0, Func Offset: 0x850
	// Line 1556, Address: 0x1917e8, Func Offset: 0x858
	// Line 1559, Address: 0x1917ec, Func Offset: 0x85c
	// Func End, Address: 0x19180c, Func Offset: 0x87c
}

// 
// Start address: 0x191810
void bhEne02_MV04(BH_PWORK* epw)
{
	float dist;
	NJS_POINT3 vec;
	_anon42 ln;
	NJS_POINT3 pos;
	int i;
	_anon1* owk;
	// Line 1569, Address: 0x191810, Func Offset: 0
	// Line 1570, Address: 0x191828, Func Offset: 0x18
	// Line 1572, Address: 0x191848, Func Offset: 0x38
	// Line 1574, Address: 0x19184c, Func Offset: 0x3c
	// Line 1576, Address: 0x191850, Func Offset: 0x40
	// Line 1572, Address: 0x191854, Func Offset: 0x44
	// Line 1574, Address: 0x19185c, Func Offset: 0x4c
	// Line 1575, Address: 0x191860, Func Offset: 0x50
	// Line 1576, Address: 0x191864, Func Offset: 0x54
	// Line 1577, Address: 0x191868, Func Offset: 0x58
	// Line 1578, Address: 0x19186c, Func Offset: 0x5c
	// Line 1579, Address: 0x191890, Func Offset: 0x80
	// Line 1582, Address: 0x19189c, Func Offset: 0x8c
	// Line 1583, Address: 0x1918b0, Func Offset: 0xa0
	// Line 1587, Address: 0x1918b8, Func Offset: 0xa8
	// Line 1583, Address: 0x1918bc, Func Offset: 0xac
	// Line 1584, Address: 0x1918c4, Func Offset: 0xb4
	// Line 1587, Address: 0x1918d0, Func Offset: 0xc0
	// Line 1590, Address: 0x1918dc, Func Offset: 0xcc
	// Line 1591, Address: 0x1918ec, Func Offset: 0xdc
	// Line 1592, Address: 0x1918f0, Func Offset: 0xe0
	// Line 1593, Address: 0x1918f4, Func Offset: 0xe4
	// Line 1594, Address: 0x1918f8, Func Offset: 0xe8
	// Line 1596, Address: 0x1918fc, Func Offset: 0xec
	// Line 1597, Address: 0x19191c, Func Offset: 0x10c
	// Line 1601, Address: 0x19193c, Func Offset: 0x12c
	// Line 1602, Address: 0x191950, Func Offset: 0x140
	// Line 1606, Address: 0x191964, Func Offset: 0x154
	// Line 1610, Address: 0x191990, Func Offset: 0x180
	// Line 1611, Address: 0x191994, Func Offset: 0x184
	// Line 1610, Address: 0x191998, Func Offset: 0x188
	// Line 1612, Address: 0x1919a0, Func Offset: 0x190
	// Line 1617, Address: 0x1919cc, Func Offset: 0x1bc
	// Line 1619, Address: 0x1919e4, Func Offset: 0x1d4
	// Line 1621, Address: 0x1919f0, Func Offset: 0x1e0
	// Line 1623, Address: 0x1919f8, Func Offset: 0x1e8
	// Line 1621, Address: 0x191a00, Func Offset: 0x1f0
	// Line 1623, Address: 0x191a04, Func Offset: 0x1f4
	// Line 1621, Address: 0x191a08, Func Offset: 0x1f8
	// Line 1623, Address: 0x191a10, Func Offset: 0x200
	// Line 1624, Address: 0x191a20, Func Offset: 0x210
	// Line 1626, Address: 0x191a28, Func Offset: 0x218
	// Line 1627, Address: 0x191a34, Func Offset: 0x224
	// Line 1626, Address: 0x191a38, Func Offset: 0x228
	// Line 1627, Address: 0x191a40, Func Offset: 0x230
	// Line 1637, Address: 0x191a58, Func Offset: 0x248
	// Line 1638, Address: 0x191a60, Func Offset: 0x250
	// Line 1639, Address: 0x191a68, Func Offset: 0x258
	// Line 1640, Address: 0x191a70, Func Offset: 0x260
	// Line 1641, Address: 0x191a80, Func Offset: 0x270
	// Line 1642, Address: 0x191a84, Func Offset: 0x274
	// Line 1644, Address: 0x191a8c, Func Offset: 0x27c
	// Line 1642, Address: 0x191a94, Func Offset: 0x284
	// Line 1644, Address: 0x191a98, Func Offset: 0x288
	// Line 1645, Address: 0x191aac, Func Offset: 0x29c
	// Line 1646, Address: 0x191ab8, Func Offset: 0x2a8
	// Line 1647, Address: 0x191ad4, Func Offset: 0x2c4
	// Line 1648, Address: 0x191af4, Func Offset: 0x2e4
	// Line 1649, Address: 0x191afc, Func Offset: 0x2ec
	// Line 1650, Address: 0x191b18, Func Offset: 0x308
	// Line 1651, Address: 0x191b20, Func Offset: 0x310
	// Line 1652, Address: 0x191b38, Func Offset: 0x328
	// Line 1653, Address: 0x191b40, Func Offset: 0x330
	// Line 1654, Address: 0x191b50, Func Offset: 0x340
	// Line 1655, Address: 0x191b64, Func Offset: 0x354
	// Line 1656, Address: 0x191b6c, Func Offset: 0x35c
	// Line 1657, Address: 0x191b74, Func Offset: 0x364
	// Line 1661, Address: 0x191b7c, Func Offset: 0x36c
	// Line 1662, Address: 0x191b8c, Func Offset: 0x37c
	// Line 1661, Address: 0x191b90, Func Offset: 0x380
	// Line 1662, Address: 0x191b98, Func Offset: 0x388
	// Line 1663, Address: 0x191ba4, Func Offset: 0x394
	// Line 1662, Address: 0x191ba8, Func Offset: 0x398
	// Line 1663, Address: 0x191bb0, Func Offset: 0x3a0
	// Line 1666, Address: 0x191bbc, Func Offset: 0x3ac
	// Line 1663, Address: 0x191bc0, Func Offset: 0x3b0
	// Line 1666, Address: 0x191bc8, Func Offset: 0x3b8
	// Line 1667, Address: 0x191bd8, Func Offset: 0x3c8
	// Line 1668, Address: 0x191be4, Func Offset: 0x3d4
	// Line 1669, Address: 0x191bec, Func Offset: 0x3dc
	// Line 1667, Address: 0x191bf0, Func Offset: 0x3e0
	// Line 1668, Address: 0x191bf8, Func Offset: 0x3e8
	// Line 1669, Address: 0x191c00, Func Offset: 0x3f0
	// Line 1668, Address: 0x191c04, Func Offset: 0x3f4
	// Line 1669, Address: 0x191c0c, Func Offset: 0x3fc
	// Line 1670, Address: 0x191c14, Func Offset: 0x404
	// Line 1671, Address: 0x191c20, Func Offset: 0x410
	// Line 1672, Address: 0x191c2c, Func Offset: 0x41c
	// Line 1673, Address: 0x191c40, Func Offset: 0x430
	// Line 1674, Address: 0x191c64, Func Offset: 0x454
	// Line 1673, Address: 0x191c68, Func Offset: 0x458
	// Line 1674, Address: 0x191c6c, Func Offset: 0x45c
	// Line 1675, Address: 0x191c74, Func Offset: 0x464
	// Line 1676, Address: 0x191c7c, Func Offset: 0x46c
	// Line 1677, Address: 0x191c98, Func Offset: 0x488
	// Line 1676, Address: 0x191c9c, Func Offset: 0x48c
	// Line 1677, Address: 0x191ca0, Func Offset: 0x490
	// Line 1679, Address: 0x191ca8, Func Offset: 0x498
	// Line 1680, Address: 0x191cb0, Func Offset: 0x4a0
	// Line 1681, Address: 0x191cbc, Func Offset: 0x4ac
	// Line 1682, Address: 0x191cc0, Func Offset: 0x4b0
	// Line 1680, Address: 0x191cc4, Func Offset: 0x4b4
	// Line 1681, Address: 0x191ccc, Func Offset: 0x4bc
	// Line 1682, Address: 0x191cd4, Func Offset: 0x4c4
	// Line 1681, Address: 0x191cd8, Func Offset: 0x4c8
	// Line 1682, Address: 0x191ce0, Func Offset: 0x4d0
	// Line 1683, Address: 0x191ce8, Func Offset: 0x4d8
	// Line 1684, Address: 0x191cf4, Func Offset: 0x4e4
	// Line 1685, Address: 0x191d00, Func Offset: 0x4f0
	// Line 1686, Address: 0x191d14, Func Offset: 0x504
	// Line 1687, Address: 0x191d38, Func Offset: 0x528
	// Line 1686, Address: 0x191d3c, Func Offset: 0x52c
	// Line 1687, Address: 0x191d40, Func Offset: 0x530
	// Line 1688, Address: 0x191d48, Func Offset: 0x538
	// Line 1689, Address: 0x191d50, Func Offset: 0x540
	// Line 1690, Address: 0x191d70, Func Offset: 0x560
	// Line 1696, Address: 0x191d78, Func Offset: 0x568
	// Line 1698, Address: 0x191d80, Func Offset: 0x570
	// Line 1702, Address: 0x191d90, Func Offset: 0x580
	// Line 1703, Address: 0x191da4, Func Offset: 0x594
	// Line 1704, Address: 0x191db4, Func Offset: 0x5a4
	// Line 1705, Address: 0x191dc8, Func Offset: 0x5b8
	// Line 1706, Address: 0x191dd4, Func Offset: 0x5c4
	// Line 1707, Address: 0x191ddc, Func Offset: 0x5cc
	// Line 1712, Address: 0x191dec, Func Offset: 0x5dc
	// Func End, Address: 0x191e04, Func Offset: 0x5f4
}

// 
// Start address: 0x191e10
void bhEne02_MV05(BH_PWORK* epw)
{
	// Line 1722, Address: 0x191e10, Func Offset: 0
	// Line 1723, Address: 0x191e20, Func Offset: 0x10
	// Line 1725, Address: 0x191e40, Func Offset: 0x30
	// Line 1726, Address: 0x191e48, Func Offset: 0x38
	// Line 1727, Address: 0x191e9c, Func Offset: 0x8c
	// Line 1728, Address: 0x191ea0, Func Offset: 0x90
	// Line 1729, Address: 0x191ea8, Func Offset: 0x98
	// Line 1730, Address: 0x191ecc, Func Offset: 0xbc
	// Line 1732, Address: 0x191ed8, Func Offset: 0xc8
	// Line 1733, Address: 0x191ee8, Func Offset: 0xd8
	// Line 1735, Address: 0x191ef0, Func Offset: 0xe0
	// Line 1734, Address: 0x191ef4, Func Offset: 0xe4
	// Line 1735, Address: 0x191ef8, Func Offset: 0xe8
	// Line 1736, Address: 0x191efc, Func Offset: 0xec
	// Line 1740, Address: 0x191f00, Func Offset: 0xf0
	// Func End, Address: 0x191f10, Func Offset: 0x100
}*/

// 100% matching!
void bhEne02_Nage()
{

}

/*// 
// Start address: 0x191f20
void bhEne02_Damage(BH_PWORK* epw)
{
	// Line 1794, Address: 0x191f20, Func Offset: 0
	// Line 1795, Address: 0x191f2c, Func Offset: 0xc
	// Line 1796, Address: 0x191f3c, Func Offset: 0x1c
	// Line 1799, Address: 0x191f48, Func Offset: 0x28
	// Line 1802, Address: 0x191f5c, Func Offset: 0x3c
	// Line 1803, Address: 0x191f7c, Func Offset: 0x5c
	// Line 1806, Address: 0x191f8c, Func Offset: 0x6c
	// Line 1809, Address: 0x191f94, Func Offset: 0x74
	// Line 1806, Address: 0x191f98, Func Offset: 0x78
	// Line 1809, Address: 0x191fa0, Func Offset: 0x80
	// Line 1814, Address: 0x191fbc, Func Offset: 0x9c
	// Line 1818, Address: 0x191fc8, Func Offset: 0xa8
	// Line 1819, Address: 0x191fdc, Func Offset: 0xbc
	// Line 1822, Address: 0x191fe8, Func Offset: 0xc8
	// Line 1823, Address: 0x191ff0, Func Offset: 0xd0
	// Line 1824, Address: 0x191ff8, Func Offset: 0xd8
	// Line 1823, Address: 0x191ffc, Func Offset: 0xdc
	// Line 1824, Address: 0x192004, Func Offset: 0xe4
	// Line 1825, Address: 0x192008, Func Offset: 0xe8
	// Line 1826, Address: 0x19200c, Func Offset: 0xec
	// Line 1827, Address: 0x192010, Func Offset: 0xf0
	// Line 1829, Address: 0x19201c, Func Offset: 0xfc
	// Line 1830, Address: 0x192024, Func Offset: 0x104
	// Line 1833, Address: 0x19202c, Func Offset: 0x10c
	// Line 1834, Address: 0x192034, Func Offset: 0x114
	// Line 1839, Address: 0x19203c, Func Offset: 0x11c
	// Line 1840, Address: 0x19205c, Func Offset: 0x13c
	// Func End, Address: 0x19206c, Func Offset: 0x14c
}*/

// 100% matching!
void bhEne02_DG00()
{

}

/*// 
// Start address: 0x192080
void bhEne02_DG01(BH_PWORK* epw)
{
	// Line 1862, Address: 0x192080, Func Offset: 0
	// Line 1864, Address: 0x1920a0, Func Offset: 0x20
	// Line 1865, Address: 0x1920a8, Func Offset: 0x28
	// Line 1867, Address: 0x1920ac, Func Offset: 0x2c
	// Line 1864, Address: 0x1920b0, Func Offset: 0x30
	// Line 1865, Address: 0x1920b8, Func Offset: 0x38
	// Line 1866, Address: 0x1920bc, Func Offset: 0x3c
	// Line 1867, Address: 0x1920c0, Func Offset: 0x40
	// Line 1868, Address: 0x1920c4, Func Offset: 0x44
	// Line 1869, Address: 0x1920c8, Func Offset: 0x48
	// Line 1870, Address: 0x1920ec, Func Offset: 0x6c
	// Line 1871, Address: 0x1920f4, Func Offset: 0x74
	// Line 1873, Address: 0x1920fc, Func Offset: 0x7c
	// Line 1874, Address: 0x19210c, Func Offset: 0x8c
	// Line 1876, Address: 0x192110, Func Offset: 0x90
	// Line 1875, Address: 0x192114, Func Offset: 0x94
	// Line 1876, Address: 0x192118, Func Offset: 0x98
	// Line 1877, Address: 0x19211c, Func Offset: 0x9c
	// Line 1879, Address: 0x192120, Func Offset: 0xa0
	// Line 1880, Address: 0x192130, Func Offset: 0xb0
	// Line 1884, Address: 0x19213c, Func Offset: 0xbc
	// Func End, Address: 0x192144, Func Offset: 0xc4
}*/

// 100% matching!
void bhEne02_Die(BH_PWORK* epw)
{
	bhEne02_DeadMode2[epw->mode2](epw);
}

/*// 
// Start address: 0x192170
void bhEne02_DD00(BH_PWORK* epw)
{
	int i;
	_anon1* owk;
	_anon1* owk;
	NJS_POINT3 pos;
	BH_PWORK dmy_ene;
	// Line 1906, Address: 0x192170, Func Offset: 0
	// Line 1910, Address: 0x192188, Func Offset: 0x18
	// Line 1912, Address: 0x1921a8, Func Offset: 0x38
	// Line 1913, Address: 0x1921ac, Func Offset: 0x3c
	// Line 1914, Address: 0x1921b0, Func Offset: 0x40
	// Line 1916, Address: 0x1921b4, Func Offset: 0x44
	// Line 1912, Address: 0x1921b8, Func Offset: 0x48
	// Line 1913, Address: 0x1921c0, Func Offset: 0x50
	// Line 1914, Address: 0x1921cc, Func Offset: 0x5c
	// Line 1915, Address: 0x1921d0, Func Offset: 0x60
	// Line 1916, Address: 0x1921d4, Func Offset: 0x64
	// Line 1917, Address: 0x1921d8, Func Offset: 0x68
	// Line 1918, Address: 0x1921dc, Func Offset: 0x6c
	// Line 1919, Address: 0x192200, Func Offset: 0x90
	// Line 1920, Address: 0x192204, Func Offset: 0x94
	// Line 1922, Address: 0x192208, Func Offset: 0x98
	// Line 1923, Address: 0x192210, Func Offset: 0xa0
	// Line 1925, Address: 0x192218, Func Offset: 0xa8
	// Line 1926, Address: 0x192228, Func Offset: 0xb8
	// Line 1927, Address: 0x19222c, Func Offset: 0xbc
	// Line 1928, Address: 0x19223c, Func Offset: 0xcc
	// Line 1932, Address: 0x192248, Func Offset: 0xd8
	// Line 1933, Address: 0x19225c, Func Offset: 0xec
	// Line 1934, Address: 0x192260, Func Offset: 0xf0
	// Line 1933, Address: 0x192264, Func Offset: 0xf4
	// Line 1934, Address: 0x192268, Func Offset: 0xf8
	// Line 1935, Address: 0x19226c, Func Offset: 0xfc
	// Line 1937, Address: 0x192284, Func Offset: 0x114
	// Line 1938, Address: 0x1922a4, Func Offset: 0x134
	// Line 1939, Address: 0x1922ac, Func Offset: 0x13c
	// Line 1940, Address: 0x1922c8, Func Offset: 0x158
	// Line 1942, Address: 0x1922d0, Func Offset: 0x160
	// Line 1943, Address: 0x1922f4, Func Offset: 0x184
	// Line 1944, Address: 0x1922fc, Func Offset: 0x18c
	// Line 1946, Address: 0x192320, Func Offset: 0x1b0
	// Line 1949, Address: 0x192328, Func Offset: 0x1b8
	// Line 1950, Address: 0x19232c, Func Offset: 0x1bc
	// Line 1951, Address: 0x192330, Func Offset: 0x1c0
	// Line 1946, Address: 0x192334, Func Offset: 0x1c4
	// Line 1947, Address: 0x192338, Func Offset: 0x1c8
	// Line 1948, Address: 0x19233c, Func Offset: 0x1cc
	// Line 1953, Address: 0x192340, Func Offset: 0x1d0
	// Line 1947, Address: 0x192344, Func Offset: 0x1d4
	// Line 1948, Address: 0x192348, Func Offset: 0x1d8
	// Line 1949, Address: 0x19234c, Func Offset: 0x1dc
	// Line 1950, Address: 0x192350, Func Offset: 0x1e0
	// Line 1951, Address: 0x192354, Func Offset: 0x1e4
	// Line 1953, Address: 0x19235c, Func Offset: 0x1ec
	// Line 1958, Address: 0x192364, Func Offset: 0x1f4
	// Line 1959, Address: 0x192374, Func Offset: 0x204
	// Line 1960, Address: 0x192380, Func Offset: 0x210
	// Line 1961, Address: 0x192388, Func Offset: 0x218
	// Line 1962, Address: 0x192398, Func Offset: 0x228
	// Line 1963, Address: 0x1923a8, Func Offset: 0x238
	// Line 1964, Address: 0x1923c0, Func Offset: 0x250
	// Line 1965, Address: 0x1923ec, Func Offset: 0x27c
	// Line 1966, Address: 0x1923f0, Func Offset: 0x280
	// Line 1965, Address: 0x1923f4, Func Offset: 0x284
	// Line 1966, Address: 0x1923fc, Func Offset: 0x28c
	// Line 1968, Address: 0x192400, Func Offset: 0x290
	// Line 1969, Address: 0x19242c, Func Offset: 0x2bc
	// Line 1970, Address: 0x192430, Func Offset: 0x2c0
	// Line 1969, Address: 0x192434, Func Offset: 0x2c4
	// Line 1972, Address: 0x19243c, Func Offset: 0x2cc
	// Line 1973, Address: 0x192444, Func Offset: 0x2d4
	// Line 1974, Address: 0x192470, Func Offset: 0x300
	// Line 1975, Address: 0x192474, Func Offset: 0x304
	// Line 1974, Address: 0x192478, Func Offset: 0x308
	// Line 1975, Address: 0x192480, Func Offset: 0x310
	// Line 1977, Address: 0x192484, Func Offset: 0x314
	// Line 1978, Address: 0x1924b0, Func Offset: 0x340
	// Line 1979, Address: 0x1924b4, Func Offset: 0x344
	// Line 1978, Address: 0x1924b8, Func Offset: 0x348
	// Line 1979, Address: 0x1924c0, Func Offset: 0x350
	// Line 1986, Address: 0x1924c4, Func Offset: 0x354
	// Line 1989, Address: 0x1924dc, Func Offset: 0x36c
	// Line 1990, Address: 0x1924e0, Func Offset: 0x370
	// Line 1989, Address: 0x1924e8, Func Offset: 0x378
	// Line 1990, Address: 0x1924ec, Func Offset: 0x37c
	// Line 1991, Address: 0x1924f4, Func Offset: 0x384
	// Line 1992, Address: 0x192504, Func Offset: 0x394
	// Line 1993, Address: 0x192514, Func Offset: 0x3a4
	// Line 1997, Address: 0x192524, Func Offset: 0x3b4
	// Line 2001, Address: 0x19254c, Func Offset: 0x3dc
	// Line 2005, Address: 0x192554, Func Offset: 0x3e4
	// Line 2006, Address: 0x192558, Func Offset: 0x3e8
	// Line 2001, Address: 0x19255c, Func Offset: 0x3ec
	// Line 2004, Address: 0x192560, Func Offset: 0x3f0
	// Line 2006, Address: 0x192564, Func Offset: 0x3f4
	// Line 2005, Address: 0x192568, Func Offset: 0x3f8
	// Line 2007, Address: 0x19256c, Func Offset: 0x3fc
	// Line 2008, Address: 0x192578, Func Offset: 0x408
	// Line 2009, Address: 0x192584, Func Offset: 0x414
	// Line 2010, Address: 0x192594, Func Offset: 0x424
	// Line 2015, Address: 0x192598, Func Offset: 0x428
	// Line 2010, Address: 0x1925a0, Func Offset: 0x430
	// Line 2011, Address: 0x1925a4, Func Offset: 0x434
	// Line 2012, Address: 0x1925ac, Func Offset: 0x43c
	// Line 2015, Address: 0x1925b0, Func Offset: 0x440
	// Line 2017, Address: 0x1925b8, Func Offset: 0x448
	// Line 2018, Address: 0x1925e8, Func Offset: 0x478
	// Line 2020, Address: 0x1925f8, Func Offset: 0x488
	// Line 2018, Address: 0x1925fc, Func Offset: 0x48c
	// Line 2019, Address: 0x192600, Func Offset: 0x490
	// Line 2018, Address: 0x192604, Func Offset: 0x494
	// Line 2019, Address: 0x19260c, Func Offset: 0x49c
	// Line 2020, Address: 0x192614, Func Offset: 0x4a4
	// Line 2019, Address: 0x192618, Func Offset: 0x4a8
	// Line 2020, Address: 0x192620, Func Offset: 0x4b0
	// Line 2021, Address: 0x192628, Func Offset: 0x4b8
	// Line 2022, Address: 0x192634, Func Offset: 0x4c4
	// Line 2025, Address: 0x192640, Func Offset: 0x4d0
	// Line 2026, Address: 0x19264c, Func Offset: 0x4dc
	// Line 2025, Address: 0x192650, Func Offset: 0x4e0
	// Line 2026, Address: 0x192658, Func Offset: 0x4e8
	// Line 2029, Address: 0x192670, Func Offset: 0x500
	// Line 2030, Address: 0x192680, Func Offset: 0x510
	// Line 2029, Address: 0x192684, Func Offset: 0x514
	// Line 2030, Address: 0x19268c, Func Offset: 0x51c
	// Line 2031, Address: 0x192698, Func Offset: 0x528
	// Line 2030, Address: 0x19269c, Func Offset: 0x52c
	// Line 2031, Address: 0x1926a4, Func Offset: 0x534
	// Line 2033, Address: 0x1926b0, Func Offset: 0x540
	// Line 2031, Address: 0x1926b4, Func Offset: 0x544
	// Line 2033, Address: 0x1926bc, Func Offset: 0x54c
	// Line 2034, Address: 0x1926cc, Func Offset: 0x55c
	// Line 2035, Address: 0x1926dc, Func Offset: 0x56c
	// Line 2036, Address: 0x192700, Func Offset: 0x590
	// Line 2037, Address: 0x192708, Func Offset: 0x598
	// Line 2038, Address: 0x192714, Func Offset: 0x5a4
	// Line 2043, Address: 0x192730, Func Offset: 0x5c0
	// Line 2048, Address: 0x192738, Func Offset: 0x5c8
	// Line 2053, Address: 0x1927bc, Func Offset: 0x64c
	// Line 2058, Address: 0x1927d4, Func Offset: 0x664
	// Line 2059, Address: 0x1927d8, Func Offset: 0x668
	// Line 2058, Address: 0x1927dc, Func Offset: 0x66c
	// Line 2064, Address: 0x1927e4, Func Offset: 0x674
	// Line 2065, Address: 0x192804, Func Offset: 0x694
	// Line 2067, Address: 0x192814, Func Offset: 0x6a4
	// Line 2065, Address: 0x192818, Func Offset: 0x6a8
	// Line 2066, Address: 0x19281c, Func Offset: 0x6ac
	// Line 2065, Address: 0x192820, Func Offset: 0x6b0
	// Line 2066, Address: 0x192828, Func Offset: 0x6b8
	// Line 2067, Address: 0x192830, Func Offset: 0x6c0
	// Line 2066, Address: 0x192834, Func Offset: 0x6c4
	// Line 2067, Address: 0x19283c, Func Offset: 0x6cc
	// Line 2068, Address: 0x192844, Func Offset: 0x6d4
	// Line 2069, Address: 0x192850, Func Offset: 0x6e0
	// Line 2072, Address: 0x19285c, Func Offset: 0x6ec
	// Line 2073, Address: 0x192868, Func Offset: 0x6f8
	// Line 2072, Address: 0x19286c, Func Offset: 0x6fc
	// Line 2073, Address: 0x192874, Func Offset: 0x704
	// Line 2076, Address: 0x19288c, Func Offset: 0x71c
	// Line 2077, Address: 0x1928a4, Func Offset: 0x734
	// Line 2076, Address: 0x1928a8, Func Offset: 0x738
	// Line 2077, Address: 0x1928b0, Func Offset: 0x740
	// Line 2078, Address: 0x1928b8, Func Offset: 0x748
	// Line 2080, Address: 0x1928d4, Func Offset: 0x764
	// Line 2078, Address: 0x1928d8, Func Offset: 0x768
	// Line 2080, Address: 0x1928e0, Func Offset: 0x770
	// Line 2081, Address: 0x1928ec, Func Offset: 0x77c
	// Line 2080, Address: 0x1928f0, Func Offset: 0x780
	// Line 2081, Address: 0x1928f8, Func Offset: 0x788
	// Line 2082, Address: 0x192904, Func Offset: 0x794
	// Line 2081, Address: 0x192908, Func Offset: 0x798
	// Line 2082, Address: 0x192910, Func Offset: 0x7a0
	// Line 2084, Address: 0x19291c, Func Offset: 0x7ac
	// Line 2082, Address: 0x192920, Func Offset: 0x7b0
	// Line 2084, Address: 0x192928, Func Offset: 0x7b8
	// Line 2085, Address: 0x192938, Func Offset: 0x7c8
	// Line 2086, Address: 0x192948, Func Offset: 0x7d8
	// Line 2087, Address: 0x19296c, Func Offset: 0x7fc
	// Line 2088, Address: 0x192974, Func Offset: 0x804
	// Line 2089, Address: 0x192980, Func Offset: 0x810
	// Line 2094, Address: 0x19299c, Func Offset: 0x82c
	// Line 2096, Address: 0x1929a4, Func Offset: 0x834
	// Line 2098, Address: 0x1929b4, Func Offset: 0x844
	// Line 2101, Address: 0x1929b8, Func Offset: 0x848
	// Line 2102, Address: 0x1929d0, Func Offset: 0x860
	// Line 2103, Address: 0x1929d8, Func Offset: 0x868
	// Line 2102, Address: 0x1929e4, Func Offset: 0x874
	// Line 2103, Address: 0x1929e8, Func Offset: 0x878
	// Line 2104, Address: 0x1929f4, Func Offset: 0x884
	// Line 2105, Address: 0x192a00, Func Offset: 0x890
	// Line 2108, Address: 0x192a0c, Func Offset: 0x89c
	// Line 2109, Address: 0x192a24, Func Offset: 0x8b4
	// Line 2110, Address: 0x192a34, Func Offset: 0x8c4
	// Line 2114, Address: 0x192a40, Func Offset: 0x8d0
	// Line 2115, Address: 0x192a50, Func Offset: 0x8e0
	// Line 2116, Address: 0x192a60, Func Offset: 0x8f0
	// Line 2120, Address: 0x192a6c, Func Offset: 0x8fc
	// Line 2122, Address: 0x192a94, Func Offset: 0x924
	// Line 2123, Address: 0x192a9c, Func Offset: 0x92c
	// Line 2122, Address: 0x192aa0, Func Offset: 0x930
	// Line 2123, Address: 0x192aa8, Func Offset: 0x938
	// Line 2124, Address: 0x192ab8, Func Offset: 0x948
	// Line 2125, Address: 0x192ac4, Func Offset: 0x954
	// Line 2126, Address: 0x192acc, Func Offset: 0x95c
	// Line 2128, Address: 0x192ad8, Func Offset: 0x968
	// Line 2130, Address: 0x192b04, Func Offset: 0x994
	// Line 2131, Address: 0x192b08, Func Offset: 0x998
	// Line 2130, Address: 0x192b0c, Func Offset: 0x99c
	// Line 2131, Address: 0x192b10, Func Offset: 0x9a0
	// Line 2130, Address: 0x192b14, Func Offset: 0x9a4
	// Line 2131, Address: 0x192b1c, Func Offset: 0x9ac
	// Line 2132, Address: 0x192b20, Func Offset: 0x9b0
	// Line 2134, Address: 0x192b4c, Func Offset: 0x9dc
	// Line 2135, Address: 0x192b50, Func Offset: 0x9e0
	// Line 2134, Address: 0x192b54, Func Offset: 0x9e4
	// Line 2135, Address: 0x192b58, Func Offset: 0x9e8
	// Line 2134, Address: 0x192b5c, Func Offset: 0x9ec
	// Line 2135, Address: 0x192b64, Func Offset: 0x9f4
	// Line 2136, Address: 0x192b68, Func Offset: 0x9f8
	// Line 2138, Address: 0x192b94, Func Offset: 0xa24
	// Line 2139, Address: 0x192b9c, Func Offset: 0xa2c
	// Line 2138, Address: 0x192ba0, Func Offset: 0xa30
	// Line 2139, Address: 0x192ba8, Func Offset: 0xa38
	// Line 2140, Address: 0x192bac, Func Offset: 0xa3c
	// Line 2141, Address: 0x192bb4, Func Offset: 0xa44
	// Line 2145, Address: 0x192bc8, Func Offset: 0xa58
	// Func End, Address: 0x192be0, Func Offset: 0xa70
}

// 
// Start address: 0x192be0
void bhEne02_DD01(BH_PWORK* epw)
{
	// Line 2156, Address: 0x192be0, Func Offset: 0
	// Line 2158, Address: 0x192c00, Func Offset: 0x20
	// Line 2159, Address: 0x192c08, Func Offset: 0x28
	// Line 2161, Address: 0x192c0c, Func Offset: 0x2c
	// Line 2158, Address: 0x192c10, Func Offset: 0x30
	// Line 2159, Address: 0x192c18, Func Offset: 0x38
	// Line 2160, Address: 0x192c1c, Func Offset: 0x3c
	// Line 2161, Address: 0x192c20, Func Offset: 0x40
	// Line 2162, Address: 0x192c24, Func Offset: 0x44
	// Line 2163, Address: 0x192c28, Func Offset: 0x48
	// Line 2166, Address: 0x192c30, Func Offset: 0x50
	// Line 2163, Address: 0x192c34, Func Offset: 0x54
	// Line 2166, Address: 0x192c50, Func Offset: 0x70
	// Line 2167, Address: 0x192c5c, Func Offset: 0x7c
	// Line 2169, Address: 0x192c68, Func Offset: 0x88
	// Line 2170, Address: 0x192c70, Func Offset: 0x90
	// Line 2172, Address: 0x192c78, Func Offset: 0x98
	// Line 2173, Address: 0x192c88, Func Offset: 0xa8
	// Line 2174, Address: 0x192c8c, Func Offset: 0xac
	// Line 2178, Address: 0x192c98, Func Offset: 0xb8
	// Line 2179, Address: 0x192cac, Func Offset: 0xcc
	// Line 2180, Address: 0x192cb4, Func Offset: 0xd4
	// Line 2179, Address: 0x192cb8, Func Offset: 0xd8
	// Line 2180, Address: 0x192cc0, Func Offset: 0xe0
	// Line 2181, Address: 0x192cc4, Func Offset: 0xe4
	// Line 2182, Address: 0x192cd8, Func Offset: 0xf8
	// Line 2183, Address: 0x192cdc, Func Offset: 0xfc
	// Line 2182, Address: 0x192ce0, Func Offset: 0x100
	// Line 2183, Address: 0x192ce4, Func Offset: 0x104
	// Line 2182, Address: 0x192ce8, Func Offset: 0x108
	// Line 2183, Address: 0x192cf0, Func Offset: 0x110
	// Line 2184, Address: 0x192cf4, Func Offset: 0x114
	// Line 2185, Address: 0x192cfc, Func Offset: 0x11c
	// Line 2189, Address: 0x192d10, Func Offset: 0x130
	// Func End, Address: 0x192d18, Func Offset: 0x138
}*/

// 100% matching!
void bhEne02_SetSandEffect(BH_PWORK* epw, NJS_POINT3* pos, int type)
{
	bhEne02_SetSandEffectMain((epw->type == 0) ? 0 : 1, pos, type);
}

// 100% matching!
void bhEne02_SetSandEffectEV(int eno, int type1, int type2)
{
	bhEne02_SetSandEffectMain(type1, (NJS_POINT3*)&ene[eno].px, type2);
}

// 
// Start address: 0x192d70
void bhEne02_SetSandEffectMain(int type0, NJS_POINT3* pos, int type)
{
	float r;
	int ang;
	NJS_POINT3 wp;
	int i;
	// Line 2233, Address: 0x192d70, Func Offset: 0
	// Line 2239, Address: 0x192d94, Func Offset: 0x24
	// Line 2233, Address: 0x192d98, Func Offset: 0x28
	// Line 2239, Address: 0x192da0, Func Offset: 0x30
	// Line 2242, Address: 0x192dc4, Func Offset: 0x54
	// Line 2243, Address: 0x192dc8, Func Offset: 0x58
	// Line 2244, Address: 0x192e04, Func Offset: 0x94
	// Line 2245, Address: 0x192e20, Func Offset: 0xb0
	// Line 2244, Address: 0x192e24, Func Offset: 0xb4
	// Line 2245, Address: 0x192e3c, Func Offset: 0xcc
	// Line 2246, Address: 0x192e50, Func Offset: 0xe0
	// Line 2247, Address: 0x192e6c, Func Offset: 0xfc
	// Line 2246, Address: 0x192e70, Func Offset: 0x100
	// Line 2247, Address: 0x192e88, Func Offset: 0x118
	// Line 2248, Address: 0x192e94, Func Offset: 0x124
	// Line 2247, Address: 0x192ea0, Func Offset: 0x130
	// Line 2248, Address: 0x192ea4, Func Offset: 0x134
	// Line 2247, Address: 0x192eb4, Func Offset: 0x144
	// Line 2248, Address: 0x192eb8, Func Offset: 0x148
	// Line 2249, Address: 0x192ec0, Func Offset: 0x150
	// Line 2250, Address: 0x192ed0, Func Offset: 0x160
	// Line 2251, Address: 0x192edc, Func Offset: 0x16c
	// Line 2252, Address: 0x192ee8, Func Offset: 0x178
	// Line 2254, Address: 0x192ef0, Func Offset: 0x180
	// Line 2255, Address: 0x192ef4, Func Offset: 0x184
	// Line 2256, Address: 0x192f30, Func Offset: 0x1c0
	// Line 2257, Address: 0x192f4c, Func Offset: 0x1dc
	// Line 2256, Address: 0x192f50, Func Offset: 0x1e0
	// Line 2257, Address: 0x192f68, Func Offset: 0x1f8
	// Line 2258, Address: 0x192f7c, Func Offset: 0x20c
	// Line 2259, Address: 0x192f9c, Func Offset: 0x22c
	// Line 2258, Address: 0x192fa0, Func Offset: 0x230
	// Line 2259, Address: 0x192fb8, Func Offset: 0x248
	// Line 2260, Address: 0x192fd0, Func Offset: 0x260
	// Line 2261, Address: 0x19302c, Func Offset: 0x2bc
	// Line 2262, Address: 0x19303c, Func Offset: 0x2cc
	// Line 2263, Address: 0x193040, Func Offset: 0x2d0
	// Line 2264, Address: 0x19307c, Func Offset: 0x30c
	// Line 2265, Address: 0x193098, Func Offset: 0x328
	// Line 2264, Address: 0x19309c, Func Offset: 0x32c
	// Line 2265, Address: 0x1930b4, Func Offset: 0x344
	// Line 2266, Address: 0x1930c8, Func Offset: 0x358
	// Line 2267, Address: 0x1930e8, Func Offset: 0x378
	// Line 2266, Address: 0x1930ec, Func Offset: 0x37c
	// Line 2267, Address: 0x193110, Func Offset: 0x3a0
	// Line 2268, Address: 0x19311c, Func Offset: 0x3ac
	// Line 2267, Address: 0x193128, Func Offset: 0x3b8
	// Line 2268, Address: 0x19312c, Func Offset: 0x3bc
	// Line 2267, Address: 0x19313c, Func Offset: 0x3cc
	// Line 2268, Address: 0x193140, Func Offset: 0x3d0
	// Line 2269, Address: 0x193148, Func Offset: 0x3d8
	// Line 2270, Address: 0x193154, Func Offset: 0x3e4
	// Line 2271, Address: 0x193160, Func Offset: 0x3f0
	// Line 2272, Address: 0x19316c, Func Offset: 0x3fc
	// Line 2273, Address: 0x19317c, Func Offset: 0x40c
	// Line 2275, Address: 0x193184, Func Offset: 0x414
	// Line 2276, Address: 0x193188, Func Offset: 0x418
	// Line 2277, Address: 0x1931c4, Func Offset: 0x454
	// Line 2278, Address: 0x1931e0, Func Offset: 0x470
	// Line 2277, Address: 0x1931e4, Func Offset: 0x474
	// Line 2278, Address: 0x1931fc, Func Offset: 0x48c
	// Line 2279, Address: 0x193210, Func Offset: 0x4a0
	// Line 2280, Address: 0x19322c, Func Offset: 0x4bc
	// Line 2279, Address: 0x193230, Func Offset: 0x4c0
	// Line 2280, Address: 0x193244, Func Offset: 0x4d4
	// Line 2281, Address: 0x19325c, Func Offset: 0x4ec
	// Line 2282, Address: 0x1932b8, Func Offset: 0x548
	// Line 2283, Address: 0x1932c8, Func Offset: 0x558
	// Line 2284, Address: 0x1932cc, Func Offset: 0x55c
	// Line 2285, Address: 0x193308, Func Offset: 0x598
	// Line 2286, Address: 0x193324, Func Offset: 0x5b4
	// Line 2285, Address: 0x193328, Func Offset: 0x5b8
	// Line 2286, Address: 0x193340, Func Offset: 0x5d0
	// Line 2287, Address: 0x193354, Func Offset: 0x5e4
	// Line 2288, Address: 0x193374, Func Offset: 0x604
	// Line 2287, Address: 0x193378, Func Offset: 0x608
	// Line 2288, Address: 0x19339c, Func Offset: 0x62c
	// Line 2289, Address: 0x1933a8, Func Offset: 0x638
	// Line 2288, Address: 0x1933b4, Func Offset: 0x644
	// Line 2289, Address: 0x1933b8, Func Offset: 0x648
	// Line 2288, Address: 0x1933c8, Func Offset: 0x658
	// Line 2289, Address: 0x1933cc, Func Offset: 0x65c
	// Line 2290, Address: 0x1933d4, Func Offset: 0x664
	// Line 2291, Address: 0x1933e0, Func Offset: 0x670
	// Line 2292, Address: 0x1933ec, Func Offset: 0x67c
	// Line 2293, Address: 0x1933f8, Func Offset: 0x688
	// Line 2294, Address: 0x193408, Func Offset: 0x698
	// Line 2296, Address: 0x193410, Func Offset: 0x6a0
	// Line 2297, Address: 0x193414, Func Offset: 0x6a4
	// Line 2298, Address: 0x193450, Func Offset: 0x6e0
	// Line 2299, Address: 0x19346c, Func Offset: 0x6fc
	// Line 2298, Address: 0x193470, Func Offset: 0x700
	// Line 2299, Address: 0x193488, Func Offset: 0x718
	// Line 2300, Address: 0x19349c, Func Offset: 0x72c
	// Line 2301, Address: 0x1934bc, Func Offset: 0x74c
	// Line 2300, Address: 0x1934c0, Func Offset: 0x750
	// Line 2301, Address: 0x1934e4, Func Offset: 0x774
	// Line 2302, Address: 0x1934f0, Func Offset: 0x780
	// Line 2301, Address: 0x1934fc, Func Offset: 0x78c
	// Line 2302, Address: 0x193500, Func Offset: 0x790
	// Line 2301, Address: 0x193510, Func Offset: 0x7a0
	// Line 2302, Address: 0x193514, Func Offset: 0x7a4
	// Line 2303, Address: 0x19351c, Func Offset: 0x7ac
	// Line 2304, Address: 0x19352c, Func Offset: 0x7bc
	// Line 2306, Address: 0x193534, Func Offset: 0x7c4
	// Line 2307, Address: 0x193538, Func Offset: 0x7c8
	// Line 2308, Address: 0x193574, Func Offset: 0x804
	// Line 2309, Address: 0x193590, Func Offset: 0x820
	// Line 2308, Address: 0x193594, Func Offset: 0x824
	// Line 2309, Address: 0x1935ac, Func Offset: 0x83c
	// Line 2310, Address: 0x1935c0, Func Offset: 0x850
	// Line 2311, Address: 0x1935e0, Func Offset: 0x870
	// Line 2310, Address: 0x1935e4, Func Offset: 0x874
	// Line 2311, Address: 0x193608, Func Offset: 0x898
	// Line 2312, Address: 0x193614, Func Offset: 0x8a4
	// Line 2311, Address: 0x193620, Func Offset: 0x8b0
	// Line 2312, Address: 0x193624, Func Offset: 0x8b4
	// Line 2311, Address: 0x193634, Func Offset: 0x8c4
	// Line 2312, Address: 0x193638, Func Offset: 0x8c8
	// Line 2313, Address: 0x193640, Func Offset: 0x8d0
	// Line 2314, Address: 0x193650, Func Offset: 0x8e0
	// Line 2316, Address: 0x193658, Func Offset: 0x8e8
	// Line 2317, Address: 0x19365c, Func Offset: 0x8ec
	// Line 2318, Address: 0x193698, Func Offset: 0x928
	// Line 2319, Address: 0x1936b4, Func Offset: 0x944
	// Line 2318, Address: 0x1936b8, Func Offset: 0x948
	// Line 2319, Address: 0x1936d0, Func Offset: 0x960
	// Line 2320, Address: 0x1936e4, Func Offset: 0x974
	// Line 2321, Address: 0x193700, Func Offset: 0x990
	// Line 2320, Address: 0x193704, Func Offset: 0x994
	// Line 2321, Address: 0x193718, Func Offset: 0x9a8
	// Line 2322, Address: 0x193730, Func Offset: 0x9c0
	// Line 2323, Address: 0x19378c, Func Offset: 0xa1c
	// Line 2324, Address: 0x19379c, Func Offset: 0xa2c
	// Line 2325, Address: 0x1937a0, Func Offset: 0xa30
	// Line 2326, Address: 0x1937dc, Func Offset: 0xa6c
	// Line 2327, Address: 0x1937f8, Func Offset: 0xa88
	// Line 2326, Address: 0x1937fc, Func Offset: 0xa8c
	// Line 2327, Address: 0x193814, Func Offset: 0xaa4
	// Line 2328, Address: 0x193828, Func Offset: 0xab8
	// Line 2329, Address: 0x193848, Func Offset: 0xad8
	// Line 2328, Address: 0x19384c, Func Offset: 0xadc
	// Line 2329, Address: 0x193870, Func Offset: 0xb00
	// Line 2330, Address: 0x19387c, Func Offset: 0xb0c
	// Line 2329, Address: 0x193888, Func Offset: 0xb18
	// Line 2330, Address: 0x19388c, Func Offset: 0xb1c
	// Line 2329, Address: 0x19389c, Func Offset: 0xb2c
	// Line 2330, Address: 0x1938a0, Func Offset: 0xb30
	// Line 2331, Address: 0x1938a8, Func Offset: 0xb38
	// Line 2332, Address: 0x1938b8, Func Offset: 0xb48
	// Line 2334, Address: 0x1938c0, Func Offset: 0xb50
	// Line 2335, Address: 0x1938c4, Func Offset: 0xb54
	// Line 2336, Address: 0x193900, Func Offset: 0xb90
	// Line 2337, Address: 0x19391c, Func Offset: 0xbac
	// Line 2336, Address: 0x193920, Func Offset: 0xbb0
	// Line 2337, Address: 0x193938, Func Offset: 0xbc8
	// Line 2338, Address: 0x19394c, Func Offset: 0xbdc
	// Line 2339, Address: 0x19396c, Func Offset: 0xbfc
	// Line 2338, Address: 0x193970, Func Offset: 0xc00
	// Line 2339, Address: 0x193988, Func Offset: 0xc18
	// Line 2340, Address: 0x193994, Func Offset: 0xc24
	// Line 2339, Address: 0x19399c, Func Offset: 0xc2c
	// Line 2340, Address: 0x1939a4, Func Offset: 0xc34
	// Line 2339, Address: 0x1939b0, Func Offset: 0xc40
	// Line 2340, Address: 0x1939b4, Func Offset: 0xc44
	// Line 2341, Address: 0x1939c4, Func Offset: 0xc54
	// Line 2342, Address: 0x1939d4, Func Offset: 0xc64
	// Line 2343, Address: 0x1939d8, Func Offset: 0xc68
	// Line 2344, Address: 0x193a14, Func Offset: 0xca4
	// Line 2345, Address: 0x193a30, Func Offset: 0xcc0
	// Line 2344, Address: 0x193a34, Func Offset: 0xcc4
	// Line 2345, Address: 0x193a4c, Func Offset: 0xcdc
	// Line 2346, Address: 0x193a60, Func Offset: 0xcf0
	// Line 2347, Address: 0x193a7c, Func Offset: 0xd0c
	// Line 2346, Address: 0x193a80, Func Offset: 0xd10
	// Line 2347, Address: 0x193a98, Func Offset: 0xd28
	// Line 2348, Address: 0x193aa4, Func Offset: 0xd34
	// Line 2347, Address: 0x193ab0, Func Offset: 0xd40
	// Line 2348, Address: 0x193ab4, Func Offset: 0xd44
	// Line 2347, Address: 0x193ac4, Func Offset: 0xd54
	// Line 2348, Address: 0x193ac8, Func Offset: 0xd58
	// Line 2349, Address: 0x193ad0, Func Offset: 0xd60
	// Line 2350, Address: 0x193ae0, Func Offset: 0xd70
	// Line 2352, Address: 0x193ae8, Func Offset: 0xd78
	// Line 2353, Address: 0x193aec, Func Offset: 0xd7c
	// Line 2354, Address: 0x193b30, Func Offset: 0xdc0
	// Line 2355, Address: 0x193b60, Func Offset: 0xdf0
	// Line 2356, Address: 0x193ba8, Func Offset: 0xe38
	// Line 2357, Address: 0x193c04, Func Offset: 0xe94
	// Line 2358, Address: 0x193c14, Func Offset: 0xea4
	// Line 2359, Address: 0x193c18, Func Offset: 0xea8
	// Line 2360, Address: 0x193c5c, Func Offset: 0xeec
	// Line 2361, Address: 0x193ca0, Func Offset: 0xf30
	// Line 2362, Address: 0x193cbc, Func Offset: 0xf4c
	// Line 2361, Address: 0x193cc0, Func Offset: 0xf50
	// Line 2362, Address: 0x193cc4, Func Offset: 0xf54
	// Line 2361, Address: 0x193ccc, Func Offset: 0xf5c
	// Line 2362, Address: 0x193cdc, Func Offset: 0xf6c
	// Line 2361, Address: 0x193ce8, Func Offset: 0xf78
	// Line 2362, Address: 0x193cf4, Func Offset: 0xf84
	// Line 2361, Address: 0x193cf8, Func Offset: 0xf88
	// Line 2362, Address: 0x193cfc, Func Offset: 0xf8c
	// Line 2363, Address: 0x193d04, Func Offset: 0xf94
	// Line 2364, Address: 0x193d24, Func Offset: 0xfb4
	// Line 2365, Address: 0x193d30, Func Offset: 0xfc0
	// Line 2366, Address: 0x193d3c, Func Offset: 0xfcc
	// Line 2367, Address: 0x193d48, Func Offset: 0xfd8
	// Line 2368, Address: 0x193d58, Func Offset: 0xfe8
	// Line 2370, Address: 0x193d60, Func Offset: 0xff0
	// Line 2371, Address: 0x193d64, Func Offset: 0xff4
	// Line 2372, Address: 0x193da0, Func Offset: 0x1030
	// Line 2373, Address: 0x193dbc, Func Offset: 0x104c
	// Line 2372, Address: 0x193dc0, Func Offset: 0x1050
	// Line 2373, Address: 0x193dd8, Func Offset: 0x1068
	// Line 2374, Address: 0x193dec, Func Offset: 0x107c
	// Line 2375, Address: 0x193e08, Func Offset: 0x1098
	// Line 2374, Address: 0x193e0c, Func Offset: 0x109c
	// Line 2375, Address: 0x193e20, Func Offset: 0x10b0
	// Line 2376, Address: 0x193e38, Func Offset: 0x10c8
	// Line 2377, Address: 0x193e94, Func Offset: 0x1124
	// Line 2378, Address: 0x193ea4, Func Offset: 0x1134
	// Line 2379, Address: 0x193ea8, Func Offset: 0x1138
	// Line 2380, Address: 0x193ee4, Func Offset: 0x1174
	// Line 2381, Address: 0x193f04, Func Offset: 0x1194
	// Line 2380, Address: 0x193f08, Func Offset: 0x1198
	// Line 2381, Address: 0x193f20, Func Offset: 0x11b0
	// Line 2382, Address: 0x193f34, Func Offset: 0x11c4
	// Line 2383, Address: 0x193f54, Func Offset: 0x11e4
	// Line 2382, Address: 0x193f58, Func Offset: 0x11e8
	// Line 2383, Address: 0x193f7c, Func Offset: 0x120c
	// Line 2384, Address: 0x193f88, Func Offset: 0x1218
	// Line 2383, Address: 0x193f94, Func Offset: 0x1224
	// Line 2384, Address: 0x193f98, Func Offset: 0x1228
	// Line 2383, Address: 0x193fa8, Func Offset: 0x1238
	// Line 2384, Address: 0x193fac, Func Offset: 0x123c
	// Line 2385, Address: 0x193fb4, Func Offset: 0x1244
	// Line 2386, Address: 0x193fc0, Func Offset: 0x1250
	// Line 2387, Address: 0x193fcc, Func Offset: 0x125c
	// Line 2388, Address: 0x193fd8, Func Offset: 0x1268
	// Line 2391, Address: 0x193fe8, Func Offset: 0x1278
	// Func End, Address: 0x194010, Func Offset: 0x12a0
	scePrintf("bhEne02_SetSandEffectMain - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x194010
void bhEne02_SetSandSpr(int type0, NJS_POINT3* pos, int type, int flip, float size, int ang)
{
	int eno;
	// Line 2406, Address: 0x194010, Func Offset: 0
	// Line 2413, Address: 0x194020, Func Offset: 0x10
	// Line 2415, Address: 0x194030, Func Offset: 0x20
	// Line 2413, Address: 0x194034, Func Offset: 0x24
	// Line 2414, Address: 0x194040, Func Offset: 0x30
	// Line 2424, Address: 0x194048, Func Offset: 0x38
	// Line 2414, Address: 0x19404c, Func Offset: 0x3c
	// Line 2415, Address: 0x194058, Func Offset: 0x48
	// Line 2416, Address: 0x19406c, Func Offset: 0x5c
	// Line 2417, Address: 0x194084, Func Offset: 0x74
	// Line 2418, Address: 0x19409c, Func Offset: 0x8c
	// Line 2419, Address: 0x1940b4, Func Offset: 0xa4
	// Line 2420, Address: 0x1940c8, Func Offset: 0xb8
	// Line 2421, Address: 0x1940dc, Func Offset: 0xcc
	// Line 2422, Address: 0x1940f0, Func Offset: 0xe0
	// Line 2424, Address: 0x194100, Func Offset: 0xf0
	// Line 2425, Address: 0x194134, Func Offset: 0x124
	// Line 2427, Address: 0x19416c, Func Offset: 0x15c
	// Line 2428, Address: 0x194190, Func Offset: 0x180
	// Line 2427, Address: 0x194194, Func Offset: 0x184
	// Line 2428, Address: 0x194198, Func Offset: 0x188
	// Line 2430, Address: 0x1941a0, Func Offset: 0x190
	// Line 2431, Address: 0x1941b4, Func Offset: 0x1a4
	// Line 2430, Address: 0x1941b8, Func Offset: 0x1a8
	// Line 2431, Address: 0x1941dc, Func Offset: 0x1cc
	// Line 2432, Address: 0x194200, Func Offset: 0x1f0
	// Line 2434, Address: 0x194258, Func Offset: 0x248
	// Func End, Address: 0x19426c, Func Offset: 0x25c
}

// 
// Start address: 0x194270
void bhEne02_SandEffect(BH_PWORK* epw)
{
	int i;
	NJS_POINT3 ofp;
	unsigned int fno;
	_anon11* wp;
	_anon8* we;
	// Line 2444, Address: 0x194270, Func Offset: 0
	// Line 2447, Address: 0x194294, Func Offset: 0x24
	// Line 2446, Address: 0x19429c, Func Offset: 0x2c
	// Line 2451, Address: 0x1942a4, Func Offset: 0x34
	// Line 2452, Address: 0x1942ac, Func Offset: 0x3c
	// Line 2453, Address: 0x1942b8, Func Offset: 0x48
	// Line 2454, Address: 0x1942bc, Func Offset: 0x4c
	// Line 2455, Address: 0x1942c4, Func Offset: 0x54
	// Line 2456, Address: 0x1942d0, Func Offset: 0x60
	// Line 2457, Address: 0x1942d4, Func Offset: 0x64
	// Line 2458, Address: 0x1942d8, Func Offset: 0x68
	// Line 2459, Address: 0x1942dc, Func Offset: 0x6c
	// Line 2456, Address: 0x1942e0, Func Offset: 0x70
	// Line 2457, Address: 0x1942e4, Func Offset: 0x74
	// Line 2458, Address: 0x1942ec, Func Offset: 0x7c
	// Line 2459, Address: 0x1942f0, Func Offset: 0x80
	// Line 2460, Address: 0x1942f8, Func Offset: 0x88
	// Line 2461, Address: 0x194304, Func Offset: 0x94
	// Line 2462, Address: 0x194314, Func Offset: 0xa4
	// Line 2465, Address: 0x19431c, Func Offset: 0xac
	// Line 2462, Address: 0x194320, Func Offset: 0xb0
	// Line 2463, Address: 0x194328, Func Offset: 0xb8
	// Line 2464, Address: 0x194338, Func Offset: 0xc8
	// Line 2465, Address: 0x194348, Func Offset: 0xd8
	// Line 2466, Address: 0x194354, Func Offset: 0xe4
	// Line 2467, Address: 0x194358, Func Offset: 0xe8
	// Line 2468, Address: 0x19435c, Func Offset: 0xec
	// Line 2470, Address: 0x194370, Func Offset: 0x100
	// Line 2471, Address: 0x194374, Func Offset: 0x104
	// Line 2472, Address: 0x194388, Func Offset: 0x118
	// Func End, Address: 0x1943b0, Func Offset: 0x140
}

// 
// Start address: 0x1943b0
void bhEne02_SandEffectP(BH_PWORK* epw)
{
	int j;
	int i;
	NJS_POINT3 pos;
	NJS_POINT3 ofp;
	unsigned int fno;
	_anon11* wp;
	_anon8* we;
	// Line 2482, Address: 0x1943b0, Func Offset: 0
	// Line 2484, Address: 0x1943d4, Func Offset: 0x24
	// Line 2482, Address: 0x1943d8, Func Offset: 0x28
	// Line 2484, Address: 0x1943e0, Func Offset: 0x30
	// Line 2490, Address: 0x1943e4, Func Offset: 0x34
	// Line 2485, Address: 0x1943e8, Func Offset: 0x38
	// Line 2490, Address: 0x1943f0, Func Offset: 0x40
	// Line 2485, Address: 0x1943f8, Func Offset: 0x48
	// Line 2492, Address: 0x194400, Func Offset: 0x50
	// Line 2493, Address: 0x194408, Func Offset: 0x58
	// Line 2494, Address: 0x19441c, Func Offset: 0x6c
	// Line 2495, Address: 0x194420, Func Offset: 0x70
	// Line 2496, Address: 0x194428, Func Offset: 0x78
	// Line 2497, Address: 0x194438, Func Offset: 0x88
	// Line 2498, Address: 0x19443c, Func Offset: 0x8c
	// Line 2499, Address: 0x194440, Func Offset: 0x90
	// Line 2500, Address: 0x194444, Func Offset: 0x94
	// Line 2497, Address: 0x194448, Func Offset: 0x98
	// Line 2498, Address: 0x19444c, Func Offset: 0x9c
	// Line 2499, Address: 0x194454, Func Offset: 0xa4
	// Line 2500, Address: 0x194458, Func Offset: 0xa8
	// Line 2501, Address: 0x194460, Func Offset: 0xb0
	// Line 2502, Address: 0x194474, Func Offset: 0xc4
	// Line 2503, Address: 0x194484, Func Offset: 0xd4
	// Line 2504, Address: 0x19449c, Func Offset: 0xec
	// Line 2505, Address: 0x1944ac, Func Offset: 0xfc
	// Line 2507, Address: 0x1944bc, Func Offset: 0x10c
	// Line 2509, Address: 0x1944d0, Func Offset: 0x120
	// Line 2510, Address: 0x1944d8, Func Offset: 0x128
	// Line 2511, Address: 0x19451c, Func Offset: 0x16c
	// Line 2512, Address: 0x194564, Func Offset: 0x1b4
	// Line 2513, Address: 0x194580, Func Offset: 0x1d0
	// Line 2512, Address: 0x194584, Func Offset: 0x1d4
	// Line 2513, Address: 0x19459c, Func Offset: 0x1ec
	// Line 2512, Address: 0x1945b0, Func Offset: 0x200
	// Line 2513, Address: 0x1945bc, Func Offset: 0x20c
	// Line 2512, Address: 0x1945c0, Func Offset: 0x210
	// Line 2513, Address: 0x1945c4, Func Offset: 0x214
	// Line 2514, Address: 0x1945cc, Func Offset: 0x21c
	// Line 2515, Address: 0x1945dc, Func Offset: 0x22c
	// Line 2516, Address: 0x1945e0, Func Offset: 0x230
	// Line 2517, Address: 0x194624, Func Offset: 0x274
	// Line 2518, Address: 0x194668, Func Offset: 0x2b8
	// Line 2519, Address: 0x194688, Func Offset: 0x2d8
	// Line 2518, Address: 0x194690, Func Offset: 0x2e0
	// Line 2519, Address: 0x1946a0, Func Offset: 0x2f0
	// Line 2518, Address: 0x1946ac, Func Offset: 0x2fc
	// Line 2519, Address: 0x1946c0, Func Offset: 0x310
	// Line 2520, Address: 0x1946c8, Func Offset: 0x318
	// Line 2524, Address: 0x1946d8, Func Offset: 0x328
	// Line 2525, Address: 0x1946dc, Func Offset: 0x32c
	// Line 2527, Address: 0x1946f0, Func Offset: 0x340
	// Line 2528, Address: 0x1946f4, Func Offset: 0x344
	// Line 2529, Address: 0x194708, Func Offset: 0x358
	// Func End, Address: 0x194738, Func Offset: 0x388
}

// 
// Start address: 0x194740
void bhEne02_PlayerControl(BH_PWORK* epw)
{
	NJS_POINT3* trans[3][3];
	int mtn[8][3];
	// Line 2539, Address: 0x194740, Func Offset: 0
	// Line 2540, Address: 0x194744, Func Offset: 0x4
	// Line 2539, Address: 0x194748, Func Offset: 0x8
	// Line 2540, Address: 0x19474c, Func Offset: 0xc
	// Line 2539, Address: 0x194750, Func Offset: 0x10
	// Line 2540, Address: 0x194754, Func Offset: 0x14
	// Line 2545, Address: 0x19476c, Func Offset: 0x2c
	// Line 2540, Address: 0x194774, Func Offset: 0x34
	// Line 2545, Address: 0x19478c, Func Offset: 0x4c
	// Line 2551, Address: 0x194790, Func Offset: 0x50
	// Line 2540, Address: 0x194798, Func Offset: 0x58
	// Line 2545, Address: 0x1947a0, Func Offset: 0x60
	// Line 2551, Address: 0x1947b8, Func Offset: 0x78
	// Line 2552, Address: 0x1947c8, Func Offset: 0x88
	// Line 2555, Address: 0x1947e8, Func Offset: 0xa8
	// Line 2557, Address: 0x194814, Func Offset: 0xd4
	// Line 2558, Address: 0x194820, Func Offset: 0xe0
	// Line 2557, Address: 0x194824, Func Offset: 0xe4
	// Line 2558, Address: 0x19482c, Func Offset: 0xec
	// Line 2559, Address: 0x194834, Func Offset: 0xf4
	// Line 2558, Address: 0x194838, Func Offset: 0xf8
	// Line 2559, Address: 0x194840, Func Offset: 0x100
	// Line 2561, Address: 0x194848, Func Offset: 0x108
	// Line 2559, Address: 0x19484c, Func Offset: 0x10c
	// Line 2561, Address: 0x194850, Func Offset: 0x110
	// Line 2562, Address: 0x194860, Func Offset: 0x120
	// Line 2563, Address: 0x194878, Func Offset: 0x138
	// Line 2564, Address: 0x194880, Func Offset: 0x140
	// Line 2566, Address: 0x19489c, Func Offset: 0x15c
	// Line 2567, Address: 0x1948a4, Func Offset: 0x164
	// Line 2568, Address: 0x1948a8, Func Offset: 0x168
	// Line 2569, Address: 0x1948ac, Func Offset: 0x16c
	// Line 2572, Address: 0x1948b0, Func Offset: 0x170
	// Line 2566, Address: 0x1948b4, Func Offset: 0x174
	// Line 2567, Address: 0x1948b8, Func Offset: 0x178
	// Line 2575, Address: 0x1948c0, Func Offset: 0x180
	// Line 2567, Address: 0x1948c4, Func Offset: 0x184
	// Line 2568, Address: 0x1948c8, Func Offset: 0x188
	// Line 2569, Address: 0x1948d4, Func Offset: 0x194
	// Line 2570, Address: 0x1948e0, Func Offset: 0x1a0
	// Line 2572, Address: 0x1948ec, Func Offset: 0x1ac
	// Line 2570, Address: 0x1948f0, Func Offset: 0x1b0
	// Line 2572, Address: 0x1948f8, Func Offset: 0x1b8
	// Line 2575, Address: 0x1948fc, Func Offset: 0x1bc
	// Line 2577, Address: 0x194904, Func Offset: 0x1c4
	// Line 2579, Address: 0x194910, Func Offset: 0x1d0
	// Line 2581, Address: 0x194918, Func Offset: 0x1d8
	// Line 2582, Address: 0x194920, Func Offset: 0x1e0
	// Line 2584, Address: 0x194950, Func Offset: 0x210
	// Line 2587, Address: 0x194978, Func Offset: 0x238
	// Line 2588, Address: 0x19498c, Func Offset: 0x24c
	// Line 2589, Address: 0x1949b8, Func Offset: 0x278
	// Line 2588, Address: 0x1949bc, Func Offset: 0x27c
	// Line 2589, Address: 0x1949c4, Func Offset: 0x284
	// Line 2592, Address: 0x1949d4, Func Offset: 0x294
	// Line 2593, Address: 0x1949e8, Func Offset: 0x2a8
	// Line 2594, Address: 0x1949f4, Func Offset: 0x2b4
	// Line 2595, Address: 0x1949fc, Func Offset: 0x2bc
	// Line 2594, Address: 0x194a00, Func Offset: 0x2c0
	// Line 2595, Address: 0x194a04, Func Offset: 0x2c4
	// Line 2594, Address: 0x194a08, Func Offset: 0x2c8
	// Line 2595, Address: 0x194a18, Func Offset: 0x2d8
	// Line 2596, Address: 0x194a24, Func Offset: 0x2e4
	// Line 2597, Address: 0x194a2c, Func Offset: 0x2ec
	// Line 2599, Address: 0x194a48, Func Offset: 0x308
	// Line 2601, Address: 0x194a58, Func Offset: 0x318
	// Line 2603, Address: 0x194a60, Func Offset: 0x320
	// Line 2605, Address: 0x194a68, Func Offset: 0x328
	// Line 2606, Address: 0x194a7c, Func Offset: 0x33c
	// Line 2608, Address: 0x194a90, Func Offset: 0x350
	// Line 2609, Address: 0x194aa4, Func Offset: 0x364
	// Line 2610, Address: 0x194ac0, Func Offset: 0x380
	// Line 2612, Address: 0x194acc, Func Offset: 0x38c
	// Line 2614, Address: 0x194af8, Func Offset: 0x3b8
	// Line 2618, Address: 0x194b10, Func Offset: 0x3d0
	// Line 2620, Address: 0x194b24, Func Offset: 0x3e4
	// Line 2621, Address: 0x194b28, Func Offset: 0x3e8
	// Line 2622, Address: 0x194b34, Func Offset: 0x3f4
	// Line 2620, Address: 0x194b38, Func Offset: 0x3f8
	// Line 2621, Address: 0x194b3c, Func Offset: 0x3fc
	// Line 2625, Address: 0x194b40, Func Offset: 0x400
	// Line 2626, Address: 0x194b44, Func Offset: 0x404
	// Line 2621, Address: 0x194b48, Func Offset: 0x408
	// Line 2622, Address: 0x194b4c, Func Offset: 0x40c
	// Line 2621, Address: 0x194b50, Func Offset: 0x410
	// Line 2622, Address: 0x194b58, Func Offset: 0x418
	// Line 2623, Address: 0x194b60, Func Offset: 0x420
	// Line 2622, Address: 0x194b64, Func Offset: 0x424
	// Line 2623, Address: 0x194b6c, Func Offset: 0x42c
	// Line 2624, Address: 0x194b74, Func Offset: 0x434
	// Line 2623, Address: 0x194b78, Func Offset: 0x438
	// Line 2624, Address: 0x194b80, Func Offset: 0x440
	// Line 2625, Address: 0x194b88, Func Offset: 0x448
	// Line 2626, Address: 0x194b94, Func Offset: 0x454
	// Line 2625, Address: 0x194b98, Func Offset: 0x458
	// Line 2626, Address: 0x194ba0, Func Offset: 0x460
	// Line 2632, Address: 0x194ba8, Func Offset: 0x468
	// Line 2634, Address: 0x194bb4, Func Offset: 0x474
	// Line 2635, Address: 0x194bc8, Func Offset: 0x488
	// Line 2636, Address: 0x194bdc, Func Offset: 0x49c
	// Line 2639, Address: 0x194c14, Func Offset: 0x4d4
	// Line 2641, Address: 0x194c34, Func Offset: 0x4f4
	// Line 2642, Address: 0x194c40, Func Offset: 0x500
	// Line 2641, Address: 0x194c44, Func Offset: 0x504
	// Line 2642, Address: 0x194c4c, Func Offset: 0x50c
	// Line 2644, Address: 0x194c54, Func Offset: 0x514
	// Line 2642, Address: 0x194c58, Func Offset: 0x518
	// Line 2644, Address: 0x194c5c, Func Offset: 0x51c
	// Line 2645, Address: 0x194c6c, Func Offset: 0x52c
	// Line 2646, Address: 0x194c84, Func Offset: 0x544
	// Line 2647, Address: 0x194c8c, Func Offset: 0x54c
	// Line 2649, Address: 0x194ca8, Func Offset: 0x568
	// Line 2650, Address: 0x194cb0, Func Offset: 0x570
	// Line 2651, Address: 0x194cb4, Func Offset: 0x574
	// Line 2652, Address: 0x194cb8, Func Offset: 0x578
	// Line 2657, Address: 0x194cbc, Func Offset: 0x57c
	// Line 2649, Address: 0x194cc0, Func Offset: 0x580
	// Line 2650, Address: 0x194cc4, Func Offset: 0x584
	// Line 2651, Address: 0x194cd0, Func Offset: 0x590
	// Line 2652, Address: 0x194cdc, Func Offset: 0x59c
	// Line 2653, Address: 0x194ce8, Func Offset: 0x5a8
	// Line 2654, Address: 0x194cf8, Func Offset: 0x5b8
	// Line 2653, Address: 0x194cfc, Func Offset: 0x5bc
	// Line 2654, Address: 0x194d18, Func Offset: 0x5d8
	// Line 2657, Address: 0x194d24, Func Offset: 0x5e4
	// Line 2659, Address: 0x194d2c, Func Offset: 0x5ec
	// Line 2660, Address: 0x194d38, Func Offset: 0x5f8
	// Line 2662, Address: 0x194d40, Func Offset: 0x600
	// Line 2663, Address: 0x194d50, Func Offset: 0x610
	// Line 2665, Address: 0x194d5c, Func Offset: 0x61c
	// Line 2669, Address: 0x194d6c, Func Offset: 0x62c
	// Line 2672, Address: 0x194d74, Func Offset: 0x634
	// Line 2674, Address: 0x194dac, Func Offset: 0x66c
	// Line 2675, Address: 0x194db8, Func Offset: 0x678
	// Line 2674, Address: 0x194dbc, Func Offset: 0x67c
	// Line 2675, Address: 0x194dc4, Func Offset: 0x684
	// Line 2676, Address: 0x194dcc, Func Offset: 0x68c
	// Line 2675, Address: 0x194dd0, Func Offset: 0x690
	// Line 2676, Address: 0x194dd8, Func Offset: 0x698
	// Line 2678, Address: 0x194de0, Func Offset: 0x6a0
	// Line 2676, Address: 0x194de4, Func Offset: 0x6a4
	// Line 2678, Address: 0x194de8, Func Offset: 0x6a8
	// Line 2679, Address: 0x194df8, Func Offset: 0x6b8
	// Line 2680, Address: 0x194e10, Func Offset: 0x6d0
	// Line 2681, Address: 0x194e18, Func Offset: 0x6d8
	// Line 2683, Address: 0x194e34, Func Offset: 0x6f4
	// Line 2684, Address: 0x194e3c, Func Offset: 0x6fc
	// Line 2685, Address: 0x194e40, Func Offset: 0x700
	// Line 2686, Address: 0x194e44, Func Offset: 0x704
	// Line 2689, Address: 0x194e48, Func Offset: 0x708
	// Line 2683, Address: 0x194e4c, Func Offset: 0x70c
	// Line 2684, Address: 0x194e50, Func Offset: 0x710
	// Line 2692, Address: 0x194e58, Func Offset: 0x718
	// Line 2684, Address: 0x194e5c, Func Offset: 0x71c
	// Line 2685, Address: 0x194e60, Func Offset: 0x720
	// Line 2686, Address: 0x194e6c, Func Offset: 0x72c
	// Line 2687, Address: 0x194e78, Func Offset: 0x738
	// Line 2689, Address: 0x194e84, Func Offset: 0x744
	// Line 2687, Address: 0x194e88, Func Offset: 0x748
	// Line 2689, Address: 0x194e90, Func Offset: 0x750
	// Line 2692, Address: 0x194e94, Func Offset: 0x754
	// Line 2694, Address: 0x194e9c, Func Offset: 0x75c
	// Line 2696, Address: 0x194ea8, Func Offset: 0x768
	// Line 2698, Address: 0x194eb0, Func Offset: 0x770
	// Line 2699, Address: 0x194eb8, Func Offset: 0x778
	// Line 2701, Address: 0x194ee8, Func Offset: 0x7a8
	// Line 2704, Address: 0x194f10, Func Offset: 0x7d0
	// Line 2705, Address: 0x194f24, Func Offset: 0x7e4
	// Line 2706, Address: 0x194f50, Func Offset: 0x810
	// Line 2705, Address: 0x194f54, Func Offset: 0x814
	// Line 2706, Address: 0x194f5c, Func Offset: 0x81c
	// Line 2709, Address: 0x194f6c, Func Offset: 0x82c
	// Line 2710, Address: 0x194f80, Func Offset: 0x840
	// Line 2711, Address: 0x194f90, Func Offset: 0x850
	// Line 2712, Address: 0x194fa8, Func Offset: 0x868
	// Line 2713, Address: 0x194fb0, Func Offset: 0x870
	// Line 2715, Address: 0x194fcc, Func Offset: 0x88c
	// Line 2716, Address: 0x194fdc, Func Offset: 0x89c
	// Line 2715, Address: 0x194fe0, Func Offset: 0x8a0
	// Line 2716, Address: 0x194ffc, Func Offset: 0x8bc
	// Line 2718, Address: 0x195008, Func Offset: 0x8c8
	// Line 2720, Address: 0x195010, Func Offset: 0x8d0
	// Line 2721, Address: 0x195020, Func Offset: 0x8e0
	// Line 2722, Address: 0x195028, Func Offset: 0x8e8
	// Line 2721, Address: 0x19502c, Func Offset: 0x8ec
	// Line 2722, Address: 0x195030, Func Offset: 0x8f0
	// Line 2723, Address: 0x19503c, Func Offset: 0x8fc
	// Line 2725, Address: 0x19504c, Func Offset: 0x90c
	// Line 2727, Address: 0x195054, Func Offset: 0x914
	// Line 2729, Address: 0x195064, Func Offset: 0x924
	// Line 2735, Address: 0x195078, Func Offset: 0x938
	// Line 2737, Address: 0x195084, Func Offset: 0x944
	// Line 2739, Address: 0x19509c, Func Offset: 0x95c
	// Func End, Address: 0x1950ac, Func Offset: 0x96c
}*/

// 
// Start address: 0x1950b0
void bhEne02_DamageInit(BH_PWORK* epw)
{
	// Line 2751, Address: 0x1950b0, Func Offset: 0
	// Line 2749, Address: 0x1950b4, Func Offset: 0x4
	// Line 2751, Address: 0x1950b8, Func Offset: 0x8
	// Line 2749, Address: 0x1950bc, Func Offset: 0xc
	// Line 2751, Address: 0x1950c0, Func Offset: 0x10
	// Line 2749, Address: 0x1950c4, Func Offset: 0x14
	// Line 2751, Address: 0x1950c8, Func Offset: 0x18
	// Line 2754, Address: 0x1950d4, Func Offset: 0x24
	// Line 2755, Address: 0x1950f4, Func Offset: 0x44
	// Line 2759, Address: 0x195104, Func Offset: 0x54
	// Line 2762, Address: 0x19510c, Func Offset: 0x5c
	// Line 2759, Address: 0x195110, Func Offset: 0x60
	// Line 2762, Address: 0x195118, Func Offset: 0x68
	// Line 2767, Address: 0x195134, Func Offset: 0x84
	// Line 2770, Address: 0x195140, Func Offset: 0x90
	// Line 2775, Address: 0x195154, Func Offset: 0xa4
	// Line 2777, Address: 0x195160, Func Offset: 0xb0
	// Line 2778, Address: 0x195168, Func Offset: 0xb8
	// Line 2779, Address: 0x195170, Func Offset: 0xc0
	// Line 2778, Address: 0x195174, Func Offset: 0xc4
	// Line 2779, Address: 0x19517c, Func Offset: 0xcc
	// Line 2780, Address: 0x195180, Func Offset: 0xd0
	// Line 2781, Address: 0x195184, Func Offset: 0xd4
	// Line 2782, Address: 0x195188, Func Offset: 0xd8
	// Line 2784, Address: 0x195194, Func Offset: 0xe4
	// Line 2785, Address: 0x19519c, Func Offset: 0xec
	// Line 2789, Address: 0x1951a4, Func Offset: 0xf4
	// Line 2790, Address: 0x1951b4, Func Offset: 0x104
	// Line 2791, Address: 0x1951b8, Func Offset: 0x108
	// Line 2790, Address: 0x1951bc, Func Offset: 0x10c
	// Line 2791, Address: 0x1951cc, Func Offset: 0x11c
	// Line 2793, Address: 0x1951dc, Func Offset: 0x12c
	// Line 2795, Address: 0x1951e4, Func Offset: 0x134
	// Line 2796, Address: 0x1951f4, Func Offset: 0x144
	// Line 2798, Address: 0x1951fc, Func Offset: 0x14c
	// Line 2797, Address: 0x195200, Func Offset: 0x150
	// Line 2798, Address: 0x195204, Func Offset: 0x154
	// Line 2799, Address: 0x195208, Func Offset: 0x158
	// Line 2802, Address: 0x19520c, Func Offset: 0x15c
	// Func End, Address: 0x19521c, Func Offset: 0x16c
	scePrintf("bhEne02_DamageInit - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x195220
void bhEne02_SetSandParticle(NJS_POINT3* pos, int type)
{
	float vy[6];
	int col[6];
	int eno;
	_anon0* op;
	// Line 2813, Address: 0x195220, Func Offset: 0
	// Line 2816, Address: 0x195224, Func Offset: 0x4
	// Line 2813, Address: 0x195228, Func Offset: 0x8
	// Line 2816, Address: 0x195230, Func Offset: 0x10
	// Line 2825, Address: 0x195240, Func Offset: 0x20
	// Line 2817, Address: 0x195244, Func Offset: 0x24
	// Line 2816, Address: 0x19524c, Func Offset: 0x2c
	// Line 2817, Address: 0x195254, Func Offset: 0x34
	// Line 2823, Address: 0x195260, Func Offset: 0x40
	// Line 2824, Address: 0x195268, Func Offset: 0x48
	// Line 2817, Address: 0x19526c, Func Offset: 0x4c
	// Line 2823, Address: 0x195274, Func Offset: 0x54
	// Line 2825, Address: 0x195278, Func Offset: 0x58
	// Line 2831, Address: 0x19527c, Func Offset: 0x5c
	// Line 2823, Address: 0x195288, Func Offset: 0x68
	// Line 2824, Address: 0x195294, Func Offset: 0x74
	// Line 2825, Address: 0x1952a8, Func Offset: 0x88
	// Line 2826, Address: 0x1952c0, Func Offset: 0xa0
	// Line 2827, Address: 0x1952d8, Func Offset: 0xb8
	// Line 2828, Address: 0x1952f0, Func Offset: 0xd0
	// Line 2831, Address: 0x195308, Func Offset: 0xe8
	// Line 2832, Address: 0x195320, Func Offset: 0x100
	// Line 2833, Address: 0x195328, Func Offset: 0x108
	// Line 2837, Address: 0x195348, Func Offset: 0x128
	// Line 2836, Address: 0x19534c, Func Offset: 0x12c
	// Line 2837, Address: 0x195350, Func Offset: 0x130
	// Line 2840, Address: 0x195354, Func Offset: 0x134
	// Line 2844, Address: 0x195358, Func Offset: 0x138
	// Line 2845, Address: 0x19535c, Func Offset: 0x13c
	// Line 2837, Address: 0x19536c, Func Offset: 0x14c
	// Line 2838, Address: 0x195370, Func Offset: 0x150
	// Line 2840, Address: 0x195374, Func Offset: 0x154
	// Line 2841, Address: 0x195378, Func Offset: 0x158
	// Line 2842, Address: 0x19537c, Func Offset: 0x15c
	// Line 2845, Address: 0x195380, Func Offset: 0x160
	// Line 2844, Address: 0x195384, Func Offset: 0x164
	// Line 2845, Address: 0x195388, Func Offset: 0x168
	// Line 2846, Address: 0x19538c, Func Offset: 0x16c
	// Line 2847, Address: 0x195390, Func Offset: 0x170
	// Func End, Address: 0x1953a0, Func Offset: 0x180
}

// 
// Start address: 0x1953a0
void bhEne02_CheckWall(BH_PWORK* epw)
{
	float ar;
	float dz;
	float dx;
	// Line 2857, Address: 0x1953a0, Func Offset: 0
	// Line 2860, Address: 0x1953b8, Func Offset: 0x18
	// Line 2861, Address: 0x1953c8, Func Offset: 0x28
	// Line 2864, Address: 0x1953d8, Func Offset: 0x38
	// Line 2865, Address: 0x1953e8, Func Offset: 0x48
	// Line 2867, Address: 0x1953fc, Func Offset: 0x5c
	// Line 2865, Address: 0x195400, Func Offset: 0x60
	// Line 2870, Address: 0x195404, Func Offset: 0x64
	// Line 2872, Address: 0x195408, Func Offset: 0x68
	// Line 2868, Address: 0x19540c, Func Offset: 0x6c
	// Line 2869, Address: 0x195418, Func Offset: 0x78
	// Line 2872, Address: 0x195424, Func Offset: 0x84
	// Line 2877, Address: 0x19542c, Func Offset: 0x8c
	// Line 2882, Address: 0x195430, Func Offset: 0x90
	// Line 2877, Address: 0x195434, Func Offset: 0x94
	// Line 2878, Address: 0x19543c, Func Offset: 0x9c
	// Line 2882, Address: 0x195448, Func Offset: 0xa8
	// Line 2888, Address: 0x195450, Func Offset: 0xb0
	// Func End, Address: 0x19546c, Func Offset: 0xcc
}

// 
// Start address: 0x195470
void bhEne02_CameraControl(BH_PWORK* epw)
{
	// Line 2898, Address: 0x195470, Func Offset: 0
	// Line 2901, Address: 0x195484, Func Offset: 0x14
	// Line 2902, Address: 0x195494, Func Offset: 0x24
	// Line 2903, Address: 0x1954a8, Func Offset: 0x38
	// Line 2904, Address: 0x1954ec, Func Offset: 0x7c
	// Line 2905, Address: 0x195530, Func Offset: 0xc0
	// Line 2906, Address: 0x195570, Func Offset: 0x100
	// Line 2907, Address: 0x195578, Func Offset: 0x108
	// Line 2908, Address: 0x19559c, Func Offset: 0x12c
	// Line 2909, Address: 0x1955dc, Func Offset: 0x16c
	// Line 2910, Address: 0x195620, Func Offset: 0x1b0
	// Line 2911, Address: 0x195640, Func Offset: 0x1d0
	// Line 2910, Address: 0x195644, Func Offset: 0x1d4
	// Line 2911, Address: 0x195648, Func Offset: 0x1d8
	// Line 2910, Address: 0x19564c, Func Offset: 0x1dc
	// Line 2911, Address: 0x19566c, Func Offset: 0x1fc
	// Line 2912, Address: 0x19567c, Func Offset: 0x20c
	// Line 2913, Address: 0x195684, Func Offset: 0x214
	// Line 2918, Address: 0x19569c, Func Offset: 0x22c
	// Func End, Address: 0x1956b0, Func Offset: 0x240
}

// 
// Start address: 0x1956b0
void bhEne02_WarpCheck(BH_PWORK* epw)
{
	int ang;
	_anon21* hp;
	// Line 2928, Address: 0x1956b0, Func Offset: 0
	// Line 2933, Address: 0x1956c0, Func Offset: 0x10
	// Line 2934, Address: 0x1956dc, Func Offset: 0x2c
	// Line 2935, Address: 0x195708, Func Offset: 0x58
	// Line 2936, Address: 0x19570c, Func Offset: 0x5c
	// Line 2938, Address: 0x195718, Func Offset: 0x68
	// Line 2939, Address: 0x195740, Func Offset: 0x90
	// Line 2938, Address: 0x195744, Func Offset: 0x94
	// Line 2939, Address: 0x19574c, Func Offset: 0x9c
	// Line 2940, Address: 0x195770, Func Offset: 0xc0
	// Line 2939, Address: 0x195774, Func Offset: 0xc4
	// Line 2940, Address: 0x19577c, Func Offset: 0xcc
	// Line 2941, Address: 0x19578c, Func Offset: 0xdc
	// Line 2942, Address: 0x1957a0, Func Offset: 0xf0
	// Line 2944, Address: 0x1957b8, Func Offset: 0x108
	// Line 2945, Address: 0x1957d4, Func Offset: 0x124
	// Line 2944, Address: 0x1957d8, Func Offset: 0x128
	// Line 2945, Address: 0x1957e0, Func Offset: 0x130
	// Line 2946, Address: 0x1957fc, Func Offset: 0x14c
	// Line 2945, Address: 0x195804, Func Offset: 0x154
	// Line 2948, Address: 0x195810, Func Offset: 0x160
	// Line 2949, Address: 0x195818, Func Offset: 0x168
	// Line 2951, Address: 0x195820, Func Offset: 0x170
	// Func End, Address: 0x195834, Func Offset: 0x184
}*/

// 100% matching!
void bhEne02_FallingRock(BH_PWORK* epw)
{
	int i;
	int num;
	float dx, dy, dz; // not from DWARF below

	num = (int)(4.0f * (-rand() / -2147483648.0f)) + 12;

	dx = epw->px - (30.0f * njSin(epw->ay));
	dy = epw->py + 60.0f;
	dz = epw->pz - (30.0f * njCos(epw->ay));

	for (i = 0; i < 16; i++)
	{
		if ((*(BH_PWORK**)((epw->exp0 + 48) + (i * 4)))->mode2 == 0)
		{
			(*(BH_PWORK**)((epw->exp0 + 48) + (i * 4)))->mode2 = 3;
			(*(BH_PWORK**)((epw->exp0 + 48) + (i * 4)))->mode3 = 0;

			(*(BH_PWORK**)((epw->exp0 + 48) + (i * 4)))->px = (dx + (80.0f * (-rand() / -2147483648.0f))) - 40.0f;
			(*(BH_PWORK**)((epw->exp0 + 48) + (i * 4)))->py = dy;
			(*(BH_PWORK**)((epw->exp0 + 48) + (i * 4)))->pz = (dz + (80.0f * (-rand() / -2147483648.0f))) - 40.0f;

			(*(BH_PWORK**)((epw->exp0 + 48) + (i * 4)))->mlwP = &epw->mdl[(int)(3.0f * (-rand() / -2147483648.0f)) + 1];

			if (--num == 0)
			{
				break;
			}
		}
	}
}

// 100% matching!
void bhEne02_CallSE(BH_PWORK* epw)
{
	int fno;

	if (epw->mnwP != epw->mnwPb)
	{
		return;
	}

	fno = epw->frm_no / 65536;

	switch (epw->mtn_no)
	{
	case 1:
		if (fno == 7)
		{
			bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 70403);
		}

		break;
	case 2:
		if (fno == 6)
		{
			bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 16847622);
		}

		if (fno == 22)
		{
			bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 70405);
		}

		if (fno == 52)
		{
			bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 70405);
		}

		break;
	case 3:
		if (fno == 23)
		{
			bhEne_CallEffectSE((NJS_POINT3*)&epw->px, 70404);
		}

		break;
	case 6:
		if (fno == 1)
		{
			bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 16782088);
		}

		break;
	case 8:
		if (fno == 1)
		{
			bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 16782089);
		}

		if ((fno == 86) || (fno == 117))
		{
			bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 4874);
		}

		break;
	case 11:
		if (fno == 1)
		{
			bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 16847627);
		}

		if (fno == 167)
		{
			bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 4874);
		}

		if (fno == 263)
		{
			bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 70421);
		}

		if (fno == 284)
		{
			bhEne_CallEffectSE((NJS_POINT3*)&epw->px, 70421);
		}

		if (fno == 320)
		{
			bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 70404);
		}

		break;
	case 14:
		if (fno == 1)
		{
			bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 70403);
		}

		break;
	case 16:
		if (fno == 9)
		{
			bhEne_CallEffectSE((NJS_POINT3*)&epw->px, 70404);
		}

		break;
	case 17:
		if (fno == 1)
		{
			bhEne_CallEffectSE((NJS_POINT3*)&epw->px, 70412);
		}

		if (fno == 97)
		{
			bhEne_CallEffectSE((NJS_POINT3*)&epw->px, 70413);
		}

		break;
	}
}

// 
// Start address: 0x195d70
void bhEne02_HitMark(BH_PWORK* epw)
{
	int i;
	int range;
	//_anon39* blp;
	NJS_POINT3 ofp;
	// Line 3067, Address: 0x195d70, Func Offset: 0
	// Line 3073, Address: 0x195d90, Func Offset: 0x20
	// Line 3074, Address: 0x195d94, Func Offset: 0x24
	// Line 3073, Address: 0x195d9c, Func Offset: 0x2c
	// Line 3070, Address: 0x195da4, Func Offset: 0x34
	// Line 3073, Address: 0x195da8, Func Offset: 0x38
	// Line 3074, Address: 0x195db8, Func Offset: 0x48
	// Line 3075, Address: 0x195dbc, Func Offset: 0x4c
	// Line 3076, Address: 0x195dcc, Func Offset: 0x5c
	// Line 3077, Address: 0x195ddc, Func Offset: 0x6c
	// Line 3078, Address: 0x195e04, Func Offset: 0x94
	// Line 3079, Address: 0x195e0c, Func Offset: 0x9c
	// Line 3080, Address: 0x195e4c, Func Offset: 0xdc
	// Line 3081, Address: 0x195e74, Func Offset: 0x104
	// Line 3082, Address: 0x195e90, Func Offset: 0x120
	// Line 3081, Address: 0x195e94, Func Offset: 0x124
	// Line 3082, Address: 0x195eb8, Func Offset: 0x148
	// Line 3083, Address: 0x195ec0, Func Offset: 0x150
	// Line 3084, Address: 0x195edc, Func Offset: 0x16c
	// Line 3083, Address: 0x195ee8, Func Offset: 0x178
	// Line 3084, Address: 0x195ef8, Func Offset: 0x188
	// Line 3083, Address: 0x195efc, Func Offset: 0x18c
	// Line 3084, Address: 0x195f10, Func Offset: 0x1a0
	// Line 3086, Address: 0x195f34, Func Offset: 0x1c4
	// Line 3096, Address: 0x195f64, Func Offset: 0x1f4
	// Line 3097, Address: 0x195f94, Func Offset: 0x224
	// Line 3099, Address: 0x195f9c, Func Offset: 0x22c
	// Line 3104, Address: 0x195fcc, Func Offset: 0x25c
	// Line 3105, Address: 0x195ff4, Func Offset: 0x284
	// Line 3109, Address: 0x196008, Func Offset: 0x298
	// Line 3110, Address: 0x19603c, Func Offset: 0x2cc
	// Line 3111, Address: 0x196040, Func Offset: 0x2d0
	// Line 3112, Address: 0x196048, Func Offset: 0x2d8
	// Line 3113, Address: 0x196088, Func Offset: 0x318
	// Line 3114, Address: 0x1960b0, Func Offset: 0x340
	// Line 3115, Address: 0x1960cc, Func Offset: 0x35c
	// Line 3114, Address: 0x1960d0, Func Offset: 0x360
	// Line 3115, Address: 0x1960f4, Func Offset: 0x384
	// Line 3116, Address: 0x1960fc, Func Offset: 0x38c
	// Line 3117, Address: 0x196138, Func Offset: 0x3c8
	// Line 3118, Address: 0x1961c0, Func Offset: 0x450
	// Line 3121, Address: 0x1961d0, Func Offset: 0x460
	// Line 3122, Address: 0x1961f8, Func Offset: 0x488
	// Line 3123, Address: 0x196200, Func Offset: 0x490
	// Line 3124, Address: 0x196240, Func Offset: 0x4d0
	// Line 3125, Address: 0x196268, Func Offset: 0x4f8
	// Line 3126, Address: 0x196284, Func Offset: 0x514
	// Line 3125, Address: 0x196288, Func Offset: 0x518
	// Line 3126, Address: 0x1962ac, Func Offset: 0x53c
	// Line 3127, Address: 0x1962b4, Func Offset: 0x544
	// Line 3128, Address: 0x1962d0, Func Offset: 0x560
	// Line 3127, Address: 0x1962d4, Func Offset: 0x564
	// Line 3128, Address: 0x1962f8, Func Offset: 0x588
	// Line 3130, Address: 0x196304, Func Offset: 0x594
	// Func End, Address: 0x196328, Func Offset: 0x5b8
	scePrintf("bhEne02_HitMark - UNIMPLEMENTED!\n");
}
