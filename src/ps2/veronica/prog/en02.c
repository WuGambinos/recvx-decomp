#include "../../../ps2/veronica/prog/en02.h"
#include "../../../ps2/veronica/prog/en02sub.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
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
static COMBJOINT_WORK CombJointTbl[24] = 
{
    { 0,  0 },
    { 0, 30 },
    { 0,  0 },
    { 0,  0 },
    { 0,  0 },
    { 0,  0 },
    { 0,  0 },
    { 0,  0 },
    { 0,  0 },
    { 0,  0 },
    { 0,  0 },
    { 0, 20 },
    { 0, 20 },
    { 0, 20 },
    { 0, 20 },
    { 0, 20 },
    { 0, 20 },
    { 0, 20 },
    { 0, 20 },
    { 0, 20 },
    { 0, 20 },
    { 0, 20 },
    { 0, 20 },
    { 0, 20 }
};
static BLOOD_TBL BloodTbl[24] = 
{
    { 0, { 0.0f, 0.0f,  0.0f }, 0.0f, 0.0f, 0.0f },
    { 0, { 0.0f, 6.0f,  0.0f }, 5.0f, 0.0f, 5.0f },
    { 0, { 0.0f, 6.0f,  0.0f }, 5.0f, 0.0f, 5.0f },
    { 0, { 0.0f, 6.0f,  0.0f }, 5.0f, 0.0f, 5.0f },
    { 0, { 0.0f, 6.0f,  0.0f }, 5.0f, 0.0f, 5.0f },
    { 0, { 0.0f, 6.0f,  0.0f }, 5.0f, 0.0f, 5.0f },
    { 0, { 0.0f, 6.0f,  0.0f }, 5.0f, 0.0f, 5.0f },
    { 0, { 0.0f, 6.0f,  0.0f }, 5.0f, 0.0f, 5.0f },
    { 0, { 0.0f, 6.0f,  0.0f }, 5.0f, 0.0f, 5.0f },
    { 0, { 0.0f, 6.0f,  0.0f }, 5.0f, 0.0f, 5.0f },
    { 0, { 0.0f, 6.0f,  0.0f }, 5.0f, 0.0f, 5.0f },
    { 1, { 0.0f, 6.0f,  0.0f }, 5.0f, 0.0f, 5.0f },
    { 1, { 0.0f, 4.0f, -3.0f }, 5.0f, 0.0f, 5.0f },
    { 1, { 0.0f, 0.0f, -3.0f }, 2.0f, 3.0f, 2.0f },
    { 1, { 0.0f, 0.0f, -3.0f }, 2.0f, 3.0f, 2.0f },
    { 1, { 0.0f, 0.0f, -3.0f }, 2.0f, 3.0f, 2.0f },
    { 1, { 0.0f, 0.0f, -3.0f }, 2.0f, 3.0f, 2.0f },
    { 1, { 0.0f, 0.0f, -3.0f }, 2.0f, 3.0f, 2.0f },
    { 1, { 0.0f, 0.0f, -3.0f }, 2.0f, 3.0f, 2.0f },
    { 1, { 0.0f, 0.0f, -3.0f }, 2.0f, 3.0f, 2.0f },
    { 1, { 0.0f, 0.0f, -3.0f }, 2.0f, 3.0f, 2.0f },
    { 1, { 0.0f, 0.0f, -3.0f }, 2.0f, 3.0f, 2.0f },
    { 1, { 0.0f, 0.0f, -3.0f }, 2.0f, 3.0f, 2.0f },
    { 1, { 0.0f, 0.0f, -3.0f }, 2.0f, 3.0f, 2.0f }
};
static EN02_WE_WORK SD_01[38] = 
{
    { 0, 0.0f, 0.0f, -33.0f, 2 },
    { 1, 7.0f, 0.0f, -31.0f, 2 },
    { 1, 8.0f, 0.0f, -27.0f, 2 },
    { 1, -7.0f, 0.0f, -33.0f, 2 },
    { 2, 7.0f, 0.0f, -30.0f, 2 },
    { 2, 8.0f, 0.0f, -25.0f, 2 },
    { 2, -7.0f, 0.0f, -33.0f, 2 },
    { 3, 7.0f, 0.0f, -36.0f, 2 },
    { 3, 8.0f, 0.0f, -30.0f, 2 },
    { 3, -7.0f, 0.0f, -30.0f, 2 },
    { 4, 7.0f, 0.0f, -30.0f, 2 },
    { 4, 8.0f, 0.0f, -23.0f, 2 },
    { 4, -8.0f, 0.0f, -30.0f, 2 },
    { 5, -6.0f, 0.0f, -20.0f, 2 },
    { 6, -8.0f, 0.0f, -19.0f, 3 },
    { 7, 4.0f, 0.0f, -18.0f, 2 },
    { 8, 6.0f, 0.0f, -16.0f, 3 },
    { 9, -6.0f, 0.0f, -15.0f, 2 },
    { 10, -4.0f, 0.0f, -14.0f, 3 },
    { 11, 5.0f, 0.0f, -13.0f, 2 },
    { 13, 7.0f, 0.0f, 3.0f, 3 },
    { 14, 8.0f, 0.0f, -5.0f, 3 },
    { 15, -7.0f, 0.0f, -3.0f, 3 },
    { 16, -8.0f, 0.0f, -1.0f, 3 },
    { 17, 0.0f, 0.0f, 3.0f, 3 },
    { 18, 7.0f, 0.0f, -6.0f, 3 },
    { 19, 8.0f, 0.0f, -0.0f, 3 },
    { 20, -7.0f, 0.0f, 4.0f, 3 },
    { 21, -8.0f, 0.0f, -4.0f, 1 },
    { 22, 0.0f, 0.0f, -2.0f, 1 },
    { 23, 7.0f, 0.0f, -0.0f, 1 },
    { 18, -2.0f, 15.0f, -23.0f, 5 },
    { 19, 3.0f, 16.0f, -19.0f, 5 },
    { 20, -4.0f, 17.0f, -18.0f, 5 },
    { 21, 3.0f, 18.0f, -16.0f, 5 },
    { 22, -2.0f, 19.0f, -14.0f, 5 },
    { 23, 4.0f, 20.0f, -12.0f, 5 },
    { 24, -1.0f, 21.0f, -10.0f, 5 }
}; 
static EN02_WE_WORK SD_03[54] = 
{
    { 0x15,  0.0f, 0.0f,   2.0f, 2 },
    { 0x17,  2.0f, 0.0f,  -4.0f, 2 },
    { 0x18, -2.0f, 0.0f,   2.0f, 1 },
    { 0x1A, -4.0f, 0.0f,   2.0f, 2 },
    { 0x1C,  0.0f, 0.0f,  -3.0f, 1 },
    { 0x1E,  0.0f, 0.0f,  -2.0f, 2 },
    { 0x1F,  2.0f, 0.0f,   0.0f, 1 },
    { 0x21, -2.0f, 0.0f,  -5.0f, 2 },
    { 0x22,  4.0f, 0.0f,   3.0f, 2 },
    { 0x24, -4.0f, 0.0f,  -2.0f, 2 },
    { 0x25,  0.0f, 0.0f,   1.0f, 2 },
    { 0x27,  1.0f, 0.0f,  -2.0f, 2 },
    { 0x2A,  0.0f, 0.0f,   2.0f, 2 },
    { 0x2C, -1.0f, 0.0f,   2.0f, 2 },
    { 0x2D,  2.0f, 0.0f,  -3.0f, 2 },
    { 0x2E,  1.0f, 0.0f,  -5.0f, 2 },
    { 0x30,  0.0f, 0.0f,  -2.0f, 2 },
    { 0x18, -3.0f, 0.0f,  -8.0f, 3 },
    { 0x1C,  3.0f, 0.0f, -12.0f, 3 },
    { 0x1E, -3.0f, 0.0f, -14.0f, 3 },
    { 0x20,  3.0f, 0.0f, -18.0f, 3 },
    { 0x24, -3.0f, 0.0f, -22.0f, 3 },
    { 0x28,  3.0f, 0.0f, -26.0f, 3 },
    { 0x2B,  0.0f, 0.0f, -30.0f, 3 },
    { 0x18,  2.5f, 0.0f, -32.0f, 9 }, 
    { 0x1A,  2.5f, 0.0f, -38.0f, 9 },
    { 0x1C,  2.5f, 0.0f, -32.0f, 9 },
    { 0x1E,  2.5f, 0.0f, -38.0f, 9 },
    { 0x20,  2.5f, 0.0f, -32.0f, 9 },
    { 0x22,  2.5f, 0.0f, -38.0f, 9 },
    { 0x24,  2.5f, 0.0f, -32.0f, 9 },
    { 0x26,  2.5f, 0.0f, -38.0f, 9 },
    { 0x28,  2.5f, 0.0f, -32.0f, 9 },
    { 0x2A,  2.5f, 0.0f, -38.0f, 9 },
    { 0x2C,  2.5f, 0.0f, -32.0f, 9 },
    { 0x2E,  2.5f, 0.0f, -38.0f, 9 },
    { 0x2F,  2.5f, 0.0f, -32.0f, 9 },
    { 0x31,  2.5f, 0.0f, -38.0f, 9 },
    { 0x32,  2.5f, 0.0f, -32.0f, 9 },
    { 0x34,  2.5f, 0.0f, -38.0f, 9 },
    { 0x36,  2.5f, 0.0f, -32.0f, 9 },
    { 0x38,  2.5f, 0.0f, -38.0f, 9 },
    { 0x39,  2.5f, 0.0f, -32.0f, 9 },
    { 0x3C,  2.5f, 0.0f, -38.0f, 9 },
    { 0x3D,  2.5f, 0.0f, -32.0f, 9 },
    { 0x3E,  2.5f, 0.0f, -38.0f, 9 },
    { 0x3E,  2.5f, 0.0f, -32.0f, 9 },
    { 0x3F,  2.5f, 0.0f, -38.0f, 9 },
    { 0x40,  2.5f, 0.0f, -32.0f, 9 },
    { 0x41,  2.5f, 0.0f, -38.0f, 9 },
    { 0x42,  2.5f, 0.0f, -32.0f, 9 },
    { 0x43,  2.5f, 0.0f, -38.0f, 9 },
    { 0x44,  2.5f, 0.0f, -32.0f, 9 },
    { 0x45,  2.5f, 0.0f, -38.0f, 9 }
};
static EN02_WE_WORK SD_11[113] = 
{
    { 0x0104, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0105, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0106, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0107, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0108, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0109, 0.0f, 0.0f, 0.0f, 9 },
    { 0x010A, 0.0f, 0.0f, 0.0f, 9 },
    { 0x010B, 0.0f, 0.0f, 0.0f, 9 },
    { 0x010C, 0.0f, 0.0f, 0.0f, 9 },
    { 0x010D, 0.0f, 0.0f, 0.0f, 9 },
    { 0x010E, 0.0f, 0.0f, 0.0f, 9 },
    { 0x010F, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0110, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0111, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0112, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0113, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0114, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0115, 0.0f, 0.0f, 0.0f, 9 },
    { 0x011B, 0.0f, 0.0f, 0.0f, 9 },
    { 0x011C, 0.0f, 0.0f, 0.0f, 9 },
    { 0x011D, 0.0f, 0.0f, 0.0f, 9 },
    { 0x011E, 0.0f, 0.0f, 0.0f, 9 },
    { 0x011F, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0120, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0121, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0122, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0123, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0124, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0125, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0126, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0127, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0128, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0129, 0.0f, 0.0f, 0.0f, 9 },
    { 0x012A, 0.0f, 0.0f, 0.0f, 9 },
    { 0x012B, 0.0f, 0.0f, 0.0f, 9 },
    { 0x012C, 0.0f, 0.0f, 0.0f, 9 },
    { 0x012D, 0.0f, 0.0f, 0.0f, 9 },
    { 0x012E, 0.0f, 0.0f, 0.0f, 9 },
    { 0x012F, 0.0f, 0.0f, 0.0f, 9 },
    { 0x013C, 0.0f, 0.0f, 0.0f, 9 },
    { 0x013D, 0.0f, 0.0f, 0.0f, 9 },
    { 0x013E, 0.0f, 0.0f, 0.0f, 9 },
    { 0x013F, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0140, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0141, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0142, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0143, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0144, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0145, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0146, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0147, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0148, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0149, 0.0f, 0.0f, 0.0f, 9 },
    { 0x014A, 0.0f, 0.0f, 0.0f, 9 },
    { 0x014B, 0.0f, 0.0f, 0.0f, 9 },
    { 0x014C, 0.0f, 0.0f, 0.0f, 9 },
    { 0x014D, 0.0f, 0.0f, 0.0f, 9 },
    { 0x014E, 0.0f, 0.0f, 0.0f, 9 },
    { 0x014F, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0150, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0151, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0152, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0153, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0154, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0155, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0156, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0157, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0158, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0159, 0.0f, 0.0f, 0.0f, 9 },
    { 0x015A, 0.0f, 0.0f, 0.0f, 9 },
    { 0x015B, 0.0f, 0.0f, 0.0f, 9 },
    { 0x015C, 0.0f, 0.0f, 0.0f, 9 },
    { 0x015D, 0.0f, 0.0f, 0.0f, 9 },
    { 0x015E, 0.0f, 0.0f, 0.0f, 9 },
    { 0x015F, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0160, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0161, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0162, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0163, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0164, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0165, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0166, 0.0f, 0.0f, 0.0f, 9 },
    { 0x0167, 0.0f, 0.0f, 0.0f, 9 },
    { 0x00A7, -10.0f, 0.0f, -15.0f, 5 },
    { 0x00A7, -10.0f, 0.0f, -15.0f, 5 },
    { 0x00A7, -10.0f, 0.0f, -15.0f, 5 },
    { 0x00A8, -8.0f, 0.0f, -18.0f, 5 },
    { 0x00A8, -8.0f, 0.0f, -18.0f, 5 },
    { 0x00A8, -8.0f, 0.0f, -18.0f, 5 },
    { 0x00A9, -5.0f, 0.0f, -20.0f, 5 },
    { 0x00A9, -5.0f, 0.0f, -20.0f, 5 },
    { 0x00A9, -5.0f, 0.0f, -20.0f, 5 },
    { 0x00AA, -3.0f, 0.0f, -20.0f, 5 },
    { 0x00AA, -3.0f, 0.0f, -20.0f, 5 },
    { 0x00AA, -3.0f, 0.0f, -20.0f, 5 },
    { 0x00AB, 0.0f, 0.0f, -20.0f, 5 },
    { 0x00AB, 0.0f, 0.0f, -20.0f, 5 },
    { 0x00AB, 0.0f, 0.0f, -20.0f, 5 },
    { 0x00AC, 5.0f, 0.0f, -20.0f, 5 },
    { 0x00AC, 5.0f, 0.0f, -20.0f, 5 },
    { 0x00AC, 5.0f, 0.0f, -20.0f, 5 },
    { 0x00AD, 10.0f, 0.0f, -15.0f, 5 },
    { 0x00AD, 10.0f, 0.0f, -15.0f, 5 },
    { 0x00AD, 10.0f, 0.0f, -15.0f, 5 },
    { 0x00AE, 15.0f, 0.0f, -10.0f, 5 },
    { 0x00AE, 15.0f, 0.0f, -10.0f, 5 },
    { 0x00AE, 15.0f, 0.0f, -10.0f, 5 },
    { 0x00AF, 17.0f, 0.0f, -5.0f, 5 },
    { 0x00AF, 17.0f, 0.0f, -5.0f, 5 },
    { 0x00AF, 17.0f, 0.0f, -5.0f, 5 },
    { 0x00B0, 16.0f, 0.0f, 0.0f, 5 },
    { 0x00B0, 16.0f, 0.0f, 0.0f, 5 },
    { 0x00B0, 16.0f, 0.0f, 0.0f, 5 }
};
static EN02_WE_WORK SD_14[8] = 
{
    { 0, -1.0f, 0.0f,  1.0f, 0 },
    { 1,  3.0f, 0.0f, -2.0f, 0 },
    { 2, -3.0f, 0.0f, -1.0f, 0 },
    { 3,  2.0f, 0.0f,  2.0f, 0 },
    { 4, -3.0f, 0.0f, -3.0f, 0 },
    { 5,  3.0f, 0.0f, -2.0f, 0 },
    { 6, -1.0f, 0.0f,  3.0f, 0 },
    { 7,  3.0f, 0.0f, -1.0f, 0 }
};
static EN02_WE_WORK SD_16[47] =
{
    {  0, 0.0f, 0.0f,  -5.0f, 2 },
    {  2, 0.0f, 0.0f,  -5.0f, 2 },
    {  4, 0.0f, 0.0f,  -5.0f, 2 },
    {  6, 0.0f, 0.0f,  -5.0f, 2 },
    {  7, 0.0f, 0.0f,  -5.0f, 2 },
    {  9, 0.0f, 0.0f,  -5.0f, 2 },
    { 11, 0.0f, 0.0f,  -5.0f, 2 },
    { 12, 0.0f, 0.0f,  -5.0f, 2 },
    { 15, 0.0f, 0.0f,  -5.0f, 2 },
    { 17, 0.0f, 0.0f,  -5.0f, 2 },
    { 18, 0.0f, 0.0f,  -5.0f, 2 },
    { 20, 0.0f, 0.0f,  -5.0f, 2 },
    { 23, 0.0f, 0.0f,  -5.0f, 2 },
    { 25, 0.0f, 0.0f,  -5.0f, 2 },
    { 27, 0.0f, 0.0f,  -5.0f, 2 },
    { 30, 0.0f, 0.0f,  -5.0f, 2 },
    { 32, 0.0f, 0.0f,  -5.0f, 2 },
    { 33, 0.0f, 0.0f,  -5.0f, 2 },
    { 35, 0.0f, 0.0f,  -5.0f, 2 },
    {  8, 0.0f, 0.0f, -30.0f, 9 },
    { 10, 0.0f, 0.0f, -30.0f, 9 },
    { 11, 0.0f, 0.0f, -30.0f, 9 },
    { 13, 0.0f, 0.0f, -30.0f, 9 },
    { 15, 0.0f, 0.0f, -30.0f, 9 },
    { 18, 0.0f, 0.0f, -30.0f, 9 },
    { 19, 0.0f, 0.0f, -30.0f, 9 },
    { 21, 0.0f, 0.0f, -30.0f, 9 },
    { 23, 0.0f, 0.0f, -30.0f, 9 },
    { 24, 0.0f, 0.0f, -30.0f, 9 },
    { 27, 0.0f, 0.0f, -30.0f, 9 },
    { 28, 0.0f, 0.0f, -30.0f, 9 },
    { 29, 0.0f, 0.0f, -30.0f, 9 },
    { 30, 0.0f, 0.0f, -30.0f, 9 },
    { 31, 0.0f, 0.0f, -30.0f, 9 },
    { 33, 0.0f, 0.0f, -30.0f, 9 },
    { 35, 0.0f, 0.0f, -30.0f, 9 },
    { 38, 0.0f, 0.0f, -30.0f, 9 },
    { 39, 0.0f, 0.0f, -30.0f, 9 },
    { 41, 0.0f, 0.0f, -30.0f, 9 },
    { 43, 0.0f, 0.0f, -30.0f, 9 },
    { 44, 0.0f, 0.0f, -30.0f, 9 },
    { 47, 0.0f, 0.0f, -30.0f, 9 },
    { 48, 0.0f, 0.0f, -30.0f, 9 },
    { 49, 0.0f, 0.0f, -30.0f, 9 },
    { 50, 0.0f, 0.0f, -30.0f, 9 },
    { 51, 0.0f, 0.0f, -30.0f, 9 },
    { 52, 0.0f, 0.0f, -30.0f, 9 }
};
static EN02_WE_WORK SD_17[37] = 
{
    {  1, -3.0f, 0.0f,  -2.0f, 2 },
    {  2, -3.0f, 0.0f,  -1.0f, 2 },
    {  4,  3.0f, 0.0f,   -0.0f, 2 },
    {  5,  3.0f, 0.0f,  -9.0f, 2 },
    {  6,  3.0f, 0.0f,   -0.0f, 2 },
    {  7,  3.0f, 0.0f,  -1.0f, 2 },
    { 35, -3.0f, 0.0f,  -2.0f, 3 },
    { 37, -3.0f, 0.0f,  -2.0f, 3 },
    { 39,  3.0f, 0.0f,  -4.0f, 3 },
    { 41,  3.0f, 0.0f,  -1.0f, 3 },
    { 43,  3.0f, 0.0f,  -5.0f, 3 },
    { 45,  3.0f, 0.0f,  -6.0f, 3 },
    { 47,  3.0f, 0.0f,  -2.0f, 3 },
    { 49,  3.0f, 0.0f, -12.0f, 3 },
    { 51,  3.0f, 0.0f, -11.0f, 3 },
    { 53,  3.0f, 0.0f, -18.0f, 3 },
    { 55,  3.0f, 0.0f, -11.0f, 3 },
    { 57,  3.0f, 0.0f, -15.0f, 3 },
    { 59,  3.0f, 0.0f, -18.0f, 3 },
    { 61,  3.0f, 0.0f, -15.0f, 3 },
    { 63,  3.0f, 0.0f, -15.0f, 3 },
    { 65,  3.0f, 0.0f, -18.0f, 3 },
    { 67,  3.0f, 0.0f, -11.0f, 3 },
    { 69,  3.0f, 0.0f, -15.0f, 3 },
    { 71,  3.0f, 0.0f, -15.0f, 3 },
    { 73,  3.0f, 0.0f, -11.0f, 3 },
    { 75,  3.0f, 0.0f, -15.0f, 3 },
    { 77,  3.0f, 0.0f, -18.0f, 3 },
    { 79,  3.0f, 0.0f, -15.0f, 3 },
    { 81,  3.0f, 0.0f, -11.0f, 3 },
    { 83,  3.0f, 0.0f, -18.0f, 3 },
    { 85,  3.0f, 0.0f, -15.0f, 3 },
    { 87,  3.0f, 0.0f, -18.0f, 3 },
    { 89,  3.0f, 0.0f, -15.0f, 3 },
    { 90,  3.0f, 0.0f, -11.0f, 3 },
    { 91,  3.0f, 0.0f, -18.0f, 3 },
    { 92,  3.0f, 0.0f, -15.0f, 3 }
};
static EN02_WE_WORK P0_42[3] = 
{
    { 8, -3.0f, 0.0f, -2.0f, 0 },
    { 8, -3.0f, 0.0f, -6.0f, 0 },
    { 9,  3.0f, 0.0f, -6.0f, 0 }
};
static EN02_WE_WORK P0_43[2] = 
{
    {  6, 0.0f, 0.0f, 0.0f, 0 },
    { 13, 0.0f, 0.0f, 0.0f, 0 }
};
static EN02_SANDEFFECTTBL_WORK SandEffectTbl[9] = 
{
    {  1, SD_01,  38 },
    {  3, SD_03,  54 },
    { 11, SD_11, 113 },
    { 14, SD_14,   8 },
    { 16, SD_16,  47 },
    { 17, SD_17,  37 },
    { 21, P0_42,   3 },
    { 22, P0_43,   2 },
    { -1,  NULL,   0 }
};
static CPCL CapColTab[13] = 
{
    {   1,   2,  55 },
    {   2,   3,  55 },
    {   3,   4,  55 },
    {   4,   5,  55 },
    {   5,   6,  55 },
    {   6,   7,  55 },
    {   7,   8,  55 },
    {   8,   9,  55 },
    {   9,  10,  55 },
    {  10,  11,  55 },
    {  11,  11,  55 },
    {   0,   0, -40 },
    {   0,   0,   0 }
};

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

// 100% matching!
void bhEne02(BH_PWORK* epw)
{
    bhEne02_Mode0[epw->mode0](epw);
    
    if (!(epw->flg & 0x100000)) 
    {
        bhEne02_SandEffect(epw);
    }
    
    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    
    bhEne02_CheckWall(epw);
    
    bhCalcModel(epw);
    
    if ((epw->flg & 0x100000)) 
    {
        epw->car = 0;
    } 
    else 
    {
        epw->car += (EXP0_F(120) - epw->car) / 16.0f;
    }
    
    bhEne_SetWeponAtr(epw, 11, 3, 10.0f);
    
    bhEne02_PlayerControl(epw);
    bhEne02_CameraControl(epw);
    
    bhEne02_CallSE(epw);
}

// 100% matching!
void bhEne02_Init(BH_PWORK* epw)
{
	int i;

	epw->flg |= 0x100018;

	epw->flg &= ~0x400000;
	epw->flg &= ~0x6;

	epw->flg2 |= 0x1;

	epw->ar = 15.0f;
	epw->ah = 10.0f;

	epw->car = 10.0f;
	epw->cah = 10.0f;

	epw->hp = (sys->gm_mode != 2) ? 300 : 200;

	epw->mode0 = 1;
	epw->mode1 = 0;
	epw->mode2 = 0;
	epw->mode3 = 0;

	epw->mtn_md |= 0x20;

	if (epw->exp0 == NULL)
	{
		epw->exp0 = bhEne_CallocWork(144, 8);

		*(BH_PWORK**)(epw->exp0 + 40) = bhSetEnemy(&child, rom->ene_n);

		(*(BH_PWORK**)(epw->exp0 + 40))->type = 0;

		(*(BH_PWORK**)(epw->exp0 + 40))->lkwkp = (unsigned char*)epw;
		(*(BH_PWORK**)(epw->exp0 + 40))->mlwP  = &epw->mdl[5];

		(*(BH_PWORK**)(epw->exp0 + 40))->obj_a = epw->mdl[5].objP;
		(*(BH_PWORK**)(epw->exp0 + 40))->obj_b = epw->mdl[6].objP;

		*(BH_PWORK**)(epw->exp0 + 44) = bhSetEnemy(&child, rom->ene_n);

		(*(BH_PWORK**)(epw->exp0 + 44))->type = 1;

		(*(BH_PWORK**)(epw->exp0 + 44))->lkwkp = (unsigned char*)epw;
		(*(BH_PWORK**)(epw->exp0 + 44))->mlwP  = &epw->mdl[4];

		for (i = 0; i < 16; i++)
		{
			*(BH_PWORK**)((epw->exp0 + 48) + (i * 4)) = bhSetEnemy(&child, rom->ene_n);

			(*(BH_PWORK**)((epw->exp0 + 48) + (i * 4)))->type = 2;

			(*(BH_PWORK**)((epw->exp0 + 48) + (i * 4)))->lkwkp = (unsigned char*)epw;
			(*(BH_PWORK**)((epw->exp0 + 48) + (i * 4)))->mlwP  = &epw->mdl[1];
		}

		bhEne_SetCallFunc(bhEne02sub, 31);

		*(ATR_WORK**)(epw->exp0 + 124) = &sys->mwalp[sys->mwal_n];
		
		sys->mwal_n++;

		(*(ATR_WORK**)(epw->exp0 + 124))->flg = 0;

		(*(ATR_WORK**)(epw->exp0 + 124))->type = 3;

		(*(ATR_WORK**)(epw->exp0 + 124))->w = 10.0f;
		(*(ATR_WORK**)(epw->exp0 + 124))->h = 0;
		(*(ATR_WORK**)(epw->exp0 + 124))->d = 0;

		(*(ATR_WORK**)(epw->exp0 + 124))->attr = 0;
	}

	EXP0_I(112) = 1;
	EXP0_I(116) = 0;

	EXP0_F(120) = 10.0f;

	epw->clp_jno[0] = 11;
	epw->clp_jno[1] = 9;
	epw->clp_jno[2] = 7;
	epw->clp_jno[3] = 5;
	epw->clp_jno[4] = 4;
	epw->clp_jno[5] = 3;
	epw->clp_jno[6] = 2;
	epw->clp_jno[7] = 1;

	epw->mdflg &= ~0x20;

	epw->lok_jno = 11;

	epw->flg &= ~0x8000;
	epw->flg &= ~0x80000;

	epw->cpcl = CapColTab;

	plp->mdflg &= ~0x1;

	plp->stflg &= ~0x8;
	plp->stflg &= ~0x1000000;
}

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

// 100% matching!
void bhEne02_MV00(BH_PWORK* epw) 
{    
    float px, pz;
    
    switch (epw->mode3)
    {                           
    case 0:
        sys->rm_flg &= ~0x1;
        
        epw->flg &= ~0x60;
        
        epw->flg |= 0x180000;
        epw->flg |= 0x8000;
        
        epw->mtn_no = 1;
        epw->frm_no = 0;
        
        epw->mtn_add = 0;
        
        epw->ct0 = (int)(30.0f * (-rand() / -2147483648.0f)) + 40;
        epw->ct1 = 0;
        epw->ct2 = (int)(20.0f * (-rand() / -2147483648.0f)) + 60;
        
        epw->axp = 5461;
        
        EXP0_F(36) = 0.3f;
        
        epw->mode3++;
    case 1:
        if (EXP0_I(112) == 0)
        {
            px = epw->px - (40.0f * njSin(epw->ay));
            pz = epw->pz - (40.0f * njCos(epw->ay));
        } 
        else
        {
            px = epw->px - (5.0f * njSin(epw->ay));
            pz = epw->pz - (5.0f * njCos(epw->ay));
        }
        
        epw->px += (plp->px - px) / 16.0f;
        epw->pz += (plp->pz - pz) / 16.0f;
        
        epw->ayp = bhArcTan2(px - plp->px, pz - plp->pz);
        
        epw->ay += ((short)(epw->axp + (epw->ayp - epw->ay))) / 16;
        
        if (epw->ct0-- == 0)
        {
            epw->mode1 = 1;
        }
        
        if (epw->ct1-- == 0)
        {
            epw->axp = -epw->axp;
            
            epw->ct1 = 8;
        }
        
        if (epw->ct2-- == 0)
        {
            epw->px -= 40.0f * njSin(epw->ay);
            epw->pz -= 40.0f * njCos(epw->ay);
            
            epw->ay = epw->ayp + 32768;
            
            epw->px += 40.0f * njSin(epw->ay);
            epw->pz += 40.0f * njCos(epw->ay);
            
            epw->ct2 = (int)(20.0f * (-rand() / -2147483648.0f)) + 20;
        }
        
        if (ChechPlayEnemySe(sys->enow, 70400) == 0) 
        {
            bhEne_CallSE_EX(epw, (NJS_POINT3*)&epw->px, 70400, 60);
        }
        else 
        {
            bhEne_SetSEPan(epw, (NJS_POINT3*)&epw->px, 70400);
        }
        
        break;
    }
}

// 
// Start address: 0x190500
void bhEne02_MV02(BH_PWORK* epw)
{
	float dist;
	//_anon42 ln;
	//NJS_POINT3 pos;
	int i;
	//_anon1* owk;
	NJS_POINT3 pos;
	NJS_POINT3 trg_pos[2] = 
	{
		{ 0.0f, 0.0f, -10.18284797668457f  },
   		{ 0.0f, 0.0f, -10.064862251281738f }
	};
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

#pragma divbyzerocheck on 

// 99.97% matching
void bhEne02_MV03(BH_PWORK* epw) 
{
    NJS_POINT3 pos;   
    int i;           
    O_WORK* owk;      
    int tim[2][16] = 
	{
		{ 26, 46, 56, 26, 46, 56, 46, 46, 56, 46, 46, 56, 56, 56, 56, 26 },
		{  0, 46,  0, 26,  0, 26,  0, 46,  0, 46,  0, 26,  0,  0, 26, 26 }
	};

    switch (epw->mode3) 
    {
    case 0:
        sys->rm_flg |= 0x1;
        
        (*(BH_PWORK**)&epw->exp0[44])->mode2 = 4;
        (*(BH_PWORK**)&epw->exp0[44])->mode3 = 0;
        
        epw->ct0 = 35;
        
        StartVibrationEx(1, 12);
        
        epw->mode3++;
        break;
    case 1:
        if (epw->ct0-- == 0) 
        {
            epw->mode3++;
            break;
        }
    default:
        break;
    case 2:
        epw->flg &= ~0x100000;
        epw->flg &= ~0x8000;
        
        epw->mtn_no = 1;
        epw->frm_no = 0;
        
        epw->mtn_add = 65536;
        
        epw->flg |= 0x20;
        epw->flg |= 0x400000;
        
        epw->mode3++;
        break;
    case 3:
        if (epw->frm_no == 983040)
        {
            (*(BH_PWORK**)&epw->exp0[40])->mode2 = 1;
            (*(BH_PWORK**)&epw->exp0[40])->mode3 = 0;
        }

        if (epw->frm_no == 0)
        {
            epw->flg |= 0x40;
            
            epw->mtn_no = 2;
            
            epw->mode3++;

            pos.x = (epw->px - (30.0f * njSin(epw->ay))) - plp->px;
            pos.z = (epw->pz - (30.0f * njCos(epw->ay))) - plp->pz;
            pos.y = 0;

            if (njScalor(&pos) < 30.0f) 
            {
                epw->ct0 = tim[0][(int)(16.0f * (-rand() / -2147483648.0f))];
            } 
            else 
            {
                epw->ct0 = tim[1][(int)(16.0f * (-rand() / -2147483648.0f))];
            }

            pos.x = epw->px - plp->px;
            pos.z = epw->pz - plp->pz;
            
            epw->ayp = bhArcTan2(pos.x, pos.z);
            
            epw->ct1 = 16;
        }

        if (((epw->frm_no / 65536) < 10) && (!(plp->flg & 0x4))) 
        {
            NJS_POINT3 pos; 
            NJS_LINE ln;    
            NJS_VECTOR vec; 
            float dist;     
            
            owk = &epw->mlwP->owP[3];
            
            for (i = 0; i < 9; i++, owk++) 
            {
                if (bhEne_AttackHitCheck(plp, (NJS_POINT3*)&owk->mtx[12], 12.0f)) 
                {
                    plp->flg   |= 0x10004;
                    plp->stflg |= 0x10000;
                    
                    plp->mode0 = 4;
                    plp->mode1 = 0;
                    plp->mode3 = 0;
                    
                    plp->hp -= 10;
                    
                    if (plp->hp < 0) 
                    {
                        plp->hp = 0;
                    }
    
                    ln.px = epw->px - (5.0f * njCos(epw->ay));
                    ln.py = epw->py;
                    ln.pz = epw->pz + (5.0f * njSin(epw->ay));
                    
                    ln.vx = -njSin(epw->ay);
                    ln.vy = 0;
                    ln.vz = -njCos(epw->ay);
                    
                    njDistanceP2L((NJS_POINT3*)&plp->px, &ln, &pos);
    
                    if (njDistanceP2P((NJS_POINT3*)&epw->px, &pos) > 30.0f) 
                    {
                        pos.x = ln.px + (30.0f * ln.vx);
                        pos.y = epw->py;
                        pos.z = ln.pz + (30.0f * ln.vz);
                    } 
                    else 
                    {
                        vec.x = epw->px - plp->px;
                        vec.y = epw->py;
                        vec.z = epw->pz - plp->pz;
                        
                        if (bhEne_DirCheck(epw->ay, &vec) != 0) 
                        {
                            pos.x = ln.px;
                            pos.y = ln.py;
                            pos.z = ln.pz;
                        }
                    }
                    
                    plp->dvx = pos.x - plp->px;
                    plp->dvy = pos.y - plp->py;
                    plp->dvz = pos.z - plp->pz;
    
                    if (bhEne_DGDirCheck(plp) != 0) 
                    {
                        plp->mode2 = 1;
                        
                        plp->ayp = bhArcTan2(-plp->dvx, -plp->dvz);
                    } 
                    else 
                    {
                        plp->mode2 = 0;
                        
                        plp->ayp = bhArcTan2(plp->dvx, plp->dvz);
                    }
                    
                    break;
                }
            }
        }

        if (((epw->frm_no / 65536) > 0) && ((epw->frm_no / 65536) < 15))
        {
            epw->flg |= 0x80000;
            
            if ((epw->frm_no / 65536) < 5) 
            {
                EXP0_F(36) = 2.2f; 
            } 
            else
            {
                EXP0_F(36) = 0.6f;
            }
            
            break;
        }
        
        epw->flg &= ~0x80000;
        break;
    case 4:
        if (epw->type == 1) 
        {
            owk = &epw->mlwP->owP[7];
            
            for (i = 0; i < 5; i++, owk++)
            {
                if (bhCheckWallType((NJS_POINT3*)&owk->mtx[12], 0, 15.0f, 15.0f) != NULL)
                {
                    bhEne02_FallingRock(epw);
                    
                    epw->flg |= 0x80000;
                    
                    EXP0_F(36) = 2.2f;
                    
                    bhEne_CallEffectSE((NJS_POINT3*)&epw->px, 70418);
                    
                    epw->mode3++;
                    break;
                }
            }
        }
    case 5:
        if (epw->ct1 > 0) 
        {
            if ((epw->stflg & 0x1)) 
            {
                epw->ct1 = 0;
            } 
            else
            {
                epw->ay += (short)(epw->ayp - epw->ay) / epw->ct1;
                
                epw->ct1--;
            }
        }

        if ((epw->frm_no == 1703936) || (epw->frm_no == 3014656)) 
        {
            pos.x = (epw->px - (30.0f * njSin(epw->ay))) - plp->px;
            pos.z = (epw->pz - (30.0f * njCos(epw->ay))) - plp->pz;
            pos.y = 0;
            
            if (njScalor(&pos) > 30.0f) 
            {
                epw->ct0 = 0;
            }
        }

        if (epw->ct0-- == 0) 
        {
            epw->mode2 = 4;
            epw->mode3 = 0;
        }
        
        break;
    }
}

#pragma divbyzerocheck off

// 100% matching!
void bhEne02_MV04(BH_PWORK* epw) 
{
    O_WORK* owk;   
    int i;         
    NJS_POINT3 pos; 
    NJS_LINE ln;    
    NJS_VECTOR vec; 
    float dist;     

    switch (epw->mode3) 
    {
    case 0:
        epw->flg |= 0x60;
        
        epw->mtn_no = 3;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 0;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        
        epw->mode3++;
    case 1:
        if ((epw->frm_no / 65536) == 20) 
        {
            (*(BH_PWORK**)&epw->exp0[40])->mode2 = 2;
            (*(BH_PWORK**)&epw->exp0[40])->mode3 = 0;
            
            epw->flg &= ~0x40;
        }

        if (epw->ct0-- == 0) 
        {
            epw->mode1 = 0;
            epw->mode2 = 0;
            epw->mode3 = 0;
            
            epw->mtn_add = 0;
            
            epw->px -= 40.0f * njSin(epw->ay);
            epw->pz -= 40.0f * njCos(epw->ay);
        }

        if ((epw->frm_no / 65536) == 14) 
        {
            epw->flg &= ~0x400000;
        }

        if (((epw->frm_no / 65536) > 14) && (!(plp->flg & 0x4))) 
        {
            owk = epw->mlwP->owP + 1;
            
            for (i = 0; i < 11; i++, owk++)
            {
                if (((owk->mtx[13] - 6.0f) >= plp->py) && (bhEne_AttackHitCheck(plp, (NJS_POINT3*)&owk->mtx[12], 12.0f))) 
                {
                    if (i > 9) 
                    {
                        plp->hp -= 30;
                        
                        bhEne_SetBloodEffectBurst(plp, 3, plp->djnt_no, NULL, 0);
                    } 
                    else 
                    {
                        plp->hp -= 10;
                        
                        if (plp->hp < 0) 
                        {
                            plp->hp = 0;
                        }
                    }

                    ln.px = epw->px;
                    ln.py = epw->py;
                    ln.pz = epw->pz;
                    
                    ln.vx = -njSin(epw->ay);
                    ln.vy = 0;
                    ln.vz = -njCos(epw->ay);
                    
                    njDistanceP2L((NJS_POINT3*)&plp->px, &ln, &pos);

                    if (njDistanceP2P((NJS_POINT3*)&epw->px, &pos) > 30.0f) 
                    {
                        pos.x = epw->px - (30.0f * njSin(epw->ay));
                        pos.y = epw->py;

                        dist = epw->pz - (30.0f * njCos(epw->ay));
                        
                        pos.z = dist;
                    }
                    else  
                    {
                        vec.x = epw->px - plp->px;
                        vec.y = epw->py;
                        vec.z = epw->pz - plp->pz;
                        
                        if (bhEne_DirCheck(epw->ay, &vec) != 0) 
                        {
                            pos.x = epw->px;
                            pos.y = epw->py;
                            
                            dist = epw->pz;
                            
                            pos.z = dist;
                        }
                    }

                    plp->dvx = pos.x - plp->px;
                    plp->dvy = pos.y - plp->py;
                    plp->dvz = pos.z - plp->pz;

                    if (plp->hp < 0) 
                    {
                        plp->flg   |= 0x10004;
                        plp->stflg |= 0x50000;
                        
                        plp->mode0 = 6;
                        plp->mode1 = 0;
                        plp->mode3 = 0;
                        
                        if (bhEne_DGDirCheck(plp) != 0) 
                        {
                            plp->ayp = bhArcTan2(-plp->dvx, -plp->dvz);
                            
                            plp->mode2 = 3;
                        } 
                        else 
                        {
                            plp->ayp = bhArcTan2(plp->dvx, plp->dvz);
                            
                            plp->mode2 = 2;
                        }
                    } 
                    else 
                    {
                        plp->flg   |= 0x10004;
                        plp->stflg |= 0x10000;
                        
                        plp->mode0 = 4;
                        plp->mode1 = 0;
                        plp->mode3 = 0;
                        
                        if (bhEne_DGDirCheck(plp) != 0) 
                        {
                            plp->ayp = bhArcTan2(-plp->dvx, -plp->dvz);
                            
                            plp->mode2 = 1;
                        } 
                        else 
                        {
                            plp->ayp = bhArcTan2(plp->dvx, plp->dvz);
                            
                            plp->mode2 = 0;
                        }
                    }
                    
                    break;
                }
            }
        }

        if ((epw->frm_no / 65536) > 21) 
        {
            epw->flg |= 0x80000;
            
            if ((epw->frm_no / 65536) < 30) 
            {
                EXP0_F(36) = 2.2f; 
            } 
            else 
            {
                EXP0_F(36) = 1.2f; 
            }
        }
        
        break;
    }
}

// 100% matching!
void bhEne02_MV05(BH_PWORK* epw)
{
    switch (epw->mode3) 
    {                           
    case 0:
        epw->flg |= 0x60;

        epw->mtn_no = ((-rand() / -2147483648.0f) > 0.5f) ? 4 : 5;
        epw->frm_no = 0;
        
        epw->mtn_add = 65536;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        
        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0) 
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 4;
            epw->mode3 = 0;
        }
        
        break;
    }
}

// 100% matching!
void bhEne02_Nage()
{

}

// 100% matching!
void bhEne02_Damage(BH_PWORK* epw)
{
	if ((epw->flg & 0x4))
	{
		epw->flg &= ~0x4;

		bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl);

		if ((epw->wpnr_no == 16) && (!(epw->flg2 & 0x4)) && (epw->comb_pnt != 1))
		{
			goto label;
		}

		epw->hp -= epw->total_dam;

		if ((epw->wpnr_no == 17) && (!(epw->flg2 & 0x4)))
		{
			goto label;
		}

		bhEne02_HitMark(epw);
	}

	if (((epw->flg & 0x400000)) && (epw->hp < 0))
	{
		epw->flg |=  0x2;
		epw->flg &= ~0x20;

		epw->mode0 = 4;
		epw->mode1 = 0;
		epw->mode3 = 0;

		if (epw->type == 0)
		{
			epw->mode2 = 0;
		}
		else
		{
			epw->mode2 = 1;
		}

		bhEne02_Die(epw);
		return;
	}

label:
	bhEne02_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne02_DG00()
{

}

// 100% matching!
void bhEne02_DG01(BH_PWORK* epw)
{
	switch (epw->mode3)
	{
	case 0:
		epw->flg &= ~0x10;

		epw->mtn_no = 6;
		epw->frm_no = 0;

		epw->hokan_count = 20;
		epw->hokan_rate  = 0;

		epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;

		epw->mode3++;
		break;
	case 1:
		if (epw->ct0-- == 0)
		{
			epw->mode0 = 1;
			epw->mode1 = 0;
			epw->mode2 = 4;
			epw->mode3 = 0;

			epw->flg &= ~0x4;
			epw->flg |=  0x10;
		}

		break;
	}
}

// 100% matching!
void bhEne02_Die(BH_PWORK* epw)
{
	bhEne02_DeadMode2[epw->mode2](epw);
}

// 
// Start address: 0x192170
void bhEne02_DD00(BH_PWORK* epw)
{
	int i;
	//_anon1* owk;
	//_anon1* owk;
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

// 100% matching!
void bhEne02_DD01(BH_PWORK* epw) 
{
    switch (epw->mode3)
    {                   
    case 0:
        epw->flg &= ~0x10;
        
        epw->mtn_no = 8;
        epw->frm_no = 0;
        
        epw->hokan_count = 20;
        epw->hokan_rate  = 0;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
        
        (*(BH_PWORK**)(epw->exp0 + 40))->mode2 = 2;
        (*(BH_PWORK**)(epw->exp0 + 40))->mode3 = 0;
        
        epw->mode3++;
        break;
    case 1:
        if (epw->ct0-- == 0) 
        {
            epw->mtn_add = 0;
            
            epw->mode3++;
        }
        
        if ((epw->frm_no / 65536) == 86)
        {
            epw->flg |= 0x80000;
            
            EXP0_F(36) = 5.0f;
            break;
        }
        
        if ((epw->frm_no / 65536) == 117) 
        {
            epw->flg |= 0x80000;
            
            EXP0_F(36) = 4.2f;
            break;
        }
        
        epw->flg &= ~0x80000;
        break;
    }
}

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

// 100% matching!
void bhEne02_SetSandSpr(int type0, NJS_POINT3* pos, int type, int flip, float size, int ang)
{
	int eno;

	sys->ef.id   = 253;
	sys->ef.type = type;

	sys->ef.flg = 1;

	sys->ef.px = pos->x;
	sys->ef.py = pos->y;
	sys->ef.pz = pos->z;

	sys->ef.sx = size;
	sys->ef.sy = size;
	sys->ef.sz = size;

	sys->ef.mdlver = type0;

	if ((flip & 0x1))
	{
		sys->ef.sx *= -1.0f;
	}

	if ((flip & 0x2))
	{
		sys->ef.sz *= -1.0f;
	}

	eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);

	if (eno == -1)
	{
		return;
	}

	eff[eno].xn = -njSin(ang) * 0.5f;
	eff[eno].zn = -njCos(ang) * 0.5f;
	eff[eno].yn = 0.3f + (0.6f * (-rand() / -2147483648.0f));
}

// 100% matching!
void bhEne02_SandEffect(BH_PWORK* epw) 
{
    EN02_WE_WORK* we;            
    EN02_SANDEFFECTTBL_WORK* wp;
    unsigned int fno;            
    NJS_POINT3 ofp;             
    int i;                      

    wp = SandEffectTbl;
    
    fno = epw->frm_no / 65536;
    
    for ( ; wp->mtn_no != -1; wp++)  
    {
        if (epw->mtn_no == wp->mtn_no) 
        {
            we = wp->we;
            
            for (i = 0; i < wp->num; i++) 
            {
                if (we->frm_no == fno) 
                {
                    ofp.x = we->ofx;
                    ofp.y = we->ofy;
                    ofp.z = we->ofz;
                    
                    njUnitMatrix(NULL);
                    
                    njRotateY(NULL, epw->ay);
                    
                    njCalcVector(NULL, &ofp, &ofp);
                    
                    ofp.x += epw->px;
                    ofp.y += epw->py;
                    ofp.z += epw->pz;
                    
                    bhEne02_SetSandEffect(epw, &ofp, we->size);
                }
                
                we++;
            }
        }
    }
}

// 100% matching!
void bhEne02_SandEffectP(BH_PWORK* epw) 
{
    EN02_WE_WORK* we;            
    EN02_SANDEFFECTTBL_WORK* wp; 
    unsigned int fno;           
    NJS_POINT3 ofp, pos;              
    int i, j;                      
    int type; // not from DWARF

    wp = SandEffectTbl;
    
    type = (epw->type != 0) ? 1 : 0;
    
    fno = plp->frm_no / 65536;
    
    for ( ; wp->mtn_no != -1; wp++) 
    {
        if (plp->mtn_no == wp->mtn_no) 
        {
            we = wp->we;
            
            for (i = 0; i < wp->num; i++) 
            {
                if (we->frm_no == fno)
                {
                    ofp.x = we->ofx;
                    ofp.y = we->ofy;
                    ofp.z = we->ofz;
                    
                    njUnitMatrix(NULL);
                    
                    njRotateY(NULL, plp->ay);
                    
                    njCalcVector(NULL, &ofp, &ofp);
                    
                    ofp.x += plp->px;
                    ofp.y += plp->py;
                    ofp.z += plp->pz;
                    
                    switch (we->size)  
                    {
                    case 0:
                        for (j = 0; j < 2; j++) 
                        {
                            pos.x = (ofp.x + (4.0f * (-rand() / -2147483648.0f))) - 2.0f;
                            pos.y = (ofp.y + (4.0f * (-rand() / -2147483648.0f))) - 2.0f;
                            pos.z = (ofp.z + (4.0f * (-rand() / -2147483648.0f))) - 2.0f;
                            
                            bhEne02_SetSandSpr(type, &pos, 0, 0, 1.0f, 0);
                        }
                            
                        for (j = 0; j < 2; j++) 
                        {
                            pos.x = (ofp.x + (2.0f * (-rand() / -2147483648.0f))) - 1.0f;
                            pos.y = (ofp.y + (2.0f * (-rand() / -2147483648.0f))) - 1.0f;
                            pos.z = (ofp.z + (2.0f * (-rand() / -2147483648.0f))) - 1.0f;
                            
                            bhEne02_SetSandSpr(type, &pos, 1, 0, 1.0f, 0);
                        }
                            
                        break;
                    } 
                }
                
                we++;
            }
        }
    }
}

#pragma divbyzerocheck on 

// 100% matching!
void bhEne02_PlayerControl(BH_PWORK* epw)
{
	int mtn[3][8] = 
	{
		{ 21, 22, 23, 24, 25, 26, 28, 27 },
		{ 29, 30, 31, 32, 33, 34, 36, 35 },
		{ 29, 30, 31, 32, 33, 34, 36, 35 }
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

				plp->ct0 = 8;

				bhEne_CallPlayerVoice(2);

				StartVibrationEx(1, 11);
				break;
			case 1:
				if (plp->mode2 == 0)
				{
					bhEne_AddNullTransDir(plp, plp->ayp, trans[sys->ply_id][0]);
				}
				else
				{
					bhEne_AddNullTransDir(plp, plp->ayp, trans[sys->ply_id][1]);
				}

				if (plp->ct0 != 0)
				{
					plp->ay += (short)(plp->ayp - plp->ay) / plp->ct0;

					plp->ct0--;
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

		bhEne02_SandEffectP(epw);

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
				plp->flg &= ~0x40000;

				plp->mnwP = epw->mnwP;

				if (plp->mode2 != 0)
				{
					plp->mtn_no = mtn[sys->ply_id][4];
				}
				else
				{
					plp->mtn_no = mtn[sys->ply_id][5];
				}

				plp->frm_no = 0;

				plp->hokan_count = 3;
				plp->hokan_rate  = 32768;

				plp->mtn_add = 65536;

				plp->ct0 = plp->mnwP[plp->mtn_no].frm_num - 2;

				plp->mode3++;

				bhEne_CallPlayerVoice(2);

				StartVibrationEx(1, 11);
				break;
			case 1:
				if (plp->ct0-- == 0)
				{
					plp->mtn_add = 0;

					plp->flg |= 0x2;
				}

				break;
			}

			break;
		case 2:
		case 3:
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

				plp->ct0 = 8;

				bhEne_CallPlayerVoice(1);

				StartVibrationEx(1, 11);
				break;
			case 1:
				if (plp->mode2 == 2)
				{
					bhEne_AddNullTransDir(plp, plp->ayp, trans[sys->ply_id][0]);
				}
				else
				{
					bhEne_AddNullTransDir(plp, plp->ayp, trans[sys->ply_id][1]);
				}

				if (plp->ct0 != 0)
				{
					plp->ay += (short)(plp->ayp - plp->ay) / plp->ct0;

					plp->ct0--;
				}

				if (plp->frm_no == 0)
				{
					if (plp->mode2 == 2)
					{
						plp->mtn_no = mtn[sys->ply_id][6];
					}
					else
					{
						plp->mtn_no = mtn[sys->ply_id][7];
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

		bhEne02_SandEffectP(epw);

		plp->flg |= 0x200000;
	}
}

#pragma divbyzerocheck off 

// 100% matching!
void bhEne02_DamageInit(BH_PWORK* epw) 
{
    bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl);
    
    if ((epw->wpnr_no != 16) || ((epw->flg2 & 0x4)) || (epw->comb_pnt == 1)) 
    {
        epw->hp -= epw->total_dam;
        
        if ((epw->wpnr_no != 17) || ((epw->flg2 & 0x4))) 
        {
            bhEne02_HitMark(epw);
            
            if ((epw->flg & 0x400000)) 
            {
                if (epw->hp < 0) 
                {
                    epw->flg |= 0x2;
                    
                    epw->flg &= ~0x20;
                    
                    epw->mode0 = 4;
                    epw->mode1 = 0;
                    epw->mode3 = 0;
                    
                    if (epw->type == 0) 
                    {
                        epw->mode2 = 0;
                    } 
                    else 
                    {
                        epw->mode2 = 1;
                    }
                    
                    if (epw->type == 1)
                    {
                        (*(BH_PWORK**)&epw->exp0[40])->mdflg |= 0x1;
                        
                        (*(BH_PWORK**)&epw->exp0[40])->flg &= ~0x48;
                    }
                }
                else if (epw->total_dam > 50)
                {
                    epw->mode0 = 3;
                    epw->mode1 = 0;
                    epw->mode2 = 1;
                    epw->mode3 = 0;
                }
            } 
        }
    }
}

// 100% matching!
void bhEne02_SetSandParticle(NJS_POINT3* pos, int type)
{
	O_WRK* op;
	int eno;
	int col[6] = 
	{ 
		0, 1, 2, 0, 1, 2 
	};
	float vy[6] = 
	{ 
		2.0f, 2.0f, 1.0f, 1.0f, 1.0f, 0.5f 
	};
	
	sys->ef.id = 254;

	sys->ef.flg = 1;

	sys->ef.type = col[type];

	sys->ef.px = pos->x;
	sys->ef.py = pos->y;
	sys->ef.pz = pos->z;

	eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);

	if (eno < 0)
	{
		return;
	}

	op = &eff[eno];

	op->xn = 0;
	op->yn = vy[type];
	op->zn = 0;

	op->sx = 8.0f;
	op->sy = 8.0f;
	op->sz = 8.0f;

	op->sxb = 1.0f;
	op->syb = 0.6f * vy[type];
	op->szb = 1.0f;
}

// 100% matching!
void bhEne02_CheckWall(BH_PWORK* epw)
{
	float dx, dz;
	float ar;

	if ((epw->flg & 0x10))
	{
		epw->stflg &= ~0x1;

		dx = -40.0f * njSin(epw->ay);
		dz = -40.0f * njCos(epw->ay);
		
		ar = epw->ar;

		epw->px += dx;
		epw->pz += dz;

		epw->ar = 5.0f;

		bhCheckWall(epw);

		epw->px -= dx;
		epw->pz -= dz;

		epw->ar = ar;

		bhCheckWall(epw);
	}
}

// 100% matching!
void bhEne02_CameraControl(BH_PWORK* epw)
{
	if (epw->mode0 == 5)
	{
		return;
	}

	if ((epw->flg & 0x80000))
	{
		cam.ofx = (EXP0_F(36) * (-rand() / -2147483648.0f)) - (EXP0_F(36) / 2.0f);
		cam.ofy = (EXP0_F(36) * (-rand() / -2147483648.0f)) - (EXP0_F(36) / 2.0f);
		cam.ofz = (EXP0_F(36) * (-rand() / -2147483648.0f)) - (EXP0_F(36) / 2.0f);
	}
	else if (EXP0_F(36) > 0.01f)
	{
		cam.ofx = (EXP0_F(36) * (-rand() / -2147483648.0f)) - (EXP0_F(36) / 2.0f);
		cam.ofy = (EXP0_F(36) * (-rand() / -2147483648.0f)) - (EXP0_F(36) / 2.0f);
		cam.ofz = (EXP0_F(36) * (-rand() / -2147483648.0f)) - (EXP0_F(36) / 2.0f);

		EXP0_F(36) *= 0.9f;
	}
	else
	{
		cam.ofx = cam.ofy = cam.ofz = 0;
	}
}

// 100% matching!
void bhEne02_WarpCheck(BH_PWORK* epw)
{
	ATR_WORK* hp;
	int ang;

	hp = bhCheckFloorEnemy(epw->flr_no, plp->px, plp->pz);

	if (((hp != NULL) && (hp != *(ATR_WORK**)(epw->exp0 + 116))) && (hp->prm0 == 2))
	{
		*(ATR_WORK**)(epw->exp0 + 116) = hp;

		if (hp->prm1 == 0)
		{
			epw->px = plp->px - (40.0f * njSin(plp->ay));
			epw->pz = plp->pz - (40.0f * njCos(plp->ay));

			epw->ay = plp->ay + 32768;
		}
		else if (hp->prm1 == 1)
		{
			ang = hp->prm2 * 1820;

			epw->px = plp->px - (40.0f * njSin(ang));
			epw->pz = plp->pz - (40.0f * njCos(ang));

			epw->ay = ang + 32768;
		}
	}
	else
	{
		EXP0_I(116) = 0;
	}
}

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

// 100% matching!
void bhEne02_HitMark(BH_PWORK* epw) 
{
    NJS_POINT3 ofp; 
    BLOOD_TBL* blp; 
    int range;     
    int i;         
    
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
        ofp.x += (blp->rx * (-rand() / -2147483648.0f)) - (blp->rx / 2.0f);

        ofp.y = ((epw->comb_flg & 0x8)) ? blp->ofp.y : -blp->ofp.y;
        ofp.y += (blp->ry * (-rand() / -2147483648.0f)) - (blp->ry / 2.0f);

        ofp.z = blp->ofp.z;
        ofp.z += (blp->rz * (-rand() / -2147483648.0f)) - (blp->rz / 2.0f);

        bhEne_SetBloodEffectBurst(epw, DmgReact[epw->wpnr_no].type[range], epw->djnt_no, &ofp, 0);

        switch (epw->wpnr_no) 
        {
        case 10:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
            bhEne_SetBloodEffectBurst(epw, DmgReact[epw->wpnr_no].type[range], epw->djnt_no, (NJS_POINT3*)&epw->dpx, 1);
            break;
        default:
            bhEne_SetBloodEffectBurst(epw, DmgReact[epw->wpnr_no].type[range], epw->djnt_no, &ofp, 0);
            break;
        }

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
            ofp.x += (blp->rx * (-rand() / -2147483648.0f)) - (blp->rx / 2.0f);

            ofp.y = ((epw->comb_flg & 0x8)) ? blp->ofp.y : -blp->ofp.y;
            ofp.y += (blp->ry * (-rand() / -2147483648.0f)) - (blp->ry / 2.0f);

            ofp.z = blp->ofp.z;
            ofp.z += (blp->rz * (-rand() / -2147483648.0f)) - (blp->rz / 2.0f);

            bhEne_SetFireEffect(epw, epw->djnt_no, &ofp, 1.0f + (-rand() / -2147483648.0f), (int)(40.0f * (-rand() / -2147483648.0f)) + 20);
        }
    }

    if ((DmgReact[epw->wpnr_no].exef & 0x2))
    {
        ofp.x = blp->ofp.x;
        ofp.x += (blp->rx * (-rand() / -2147483648.0f)) - (blp->rx / 2.0f);

        ofp.y = ((epw->comb_flg & 0x8)) ? blp->ofp.y : -blp->ofp.y;
        ofp.y += (blp->ry * (-rand() / -2147483648.0f)) - (blp->ry / 2.0f);

        ofp.z = blp->ofp.z;
        ofp.z += (blp->rz * (-rand() / -2147483648.0f)) - (blp->rz / 2.0f);

        bhEne_SetAcidEffect(epw, epw->djnt_no, &ofp, 2.0f);
    }
}
