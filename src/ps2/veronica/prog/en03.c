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
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

// ENEMY: Black Widow 

NJS_POINT3 spm_016[45] =
{
    { 0.0f,             0.0f,           0.0f },
    { 0.0f,    -0.218743995f,           0.0f },
    { 0.0f,     -0.26177001f,           0.0f },
    { 0.0f,    -0.283394009f,           0.0f },
    { 0.0f,    -0.283618003f,           0.0f },
    { 0.0f,    -0.262441009f,           0.0f },
    { 0.0f,    -0.219705999f,           0.0f },
    { 0.0f,     0.537151992f, -0.0567060001f },
    { 0.0f,     0.950820029f, -0.0633549988f },
    { 0.0f,     0.462606013f, -0.0712549984f },
    { 0.0f,     0.289056987f, -0.0788789988f },
    { 0.0f,     0.259640008f, -0.0861949995f },
    { 0.0f,     0.227210999f, -0.0931779966f },
    { 0.0f,     0.180557996f, -0.0997989997f },
    { 0.0f,     0.126130998f,  -0.106032997f },
    { 0.0f,     0.128854007f,  -0.111854002f },
    { 0.0f,     0.181151003f,  -0.117241003f },
    { 0.0f,     0.132466003f,  -0.122172996f },
    { 0.0f,    0.0634640008f,  -0.126628995f },
    { 0.0f,    0.0191810001f,  -0.130595997f },
    { 0.0f, -0.000353999989f,  -0.134051993f },
    { 0.0f,   0.00609100005f,  -0.136989996f },
    { 0.0f,    0.0735360011f,  -0.139393002f },
    { 0.0f,    0.0920139998f,  -0.141257003f },
    { 0.0f,    0.0102890003f,  -0.142570004f },
    { 0.0f,   -0.0898019969f,  -0.143329993f },
    { 0.0f,    -0.125242993f,  -0.206928998f },
    { 0.0f,    -0.160959005f,  -0.470672011f },
    { 0.0f,    -0.197161004f,  -0.469761014f },
    { 0.0f,    -0.233820006f,  -0.468297005f },
    { 0.0f,    -0.291278005f,   -0.46628499f },
    { 0.0f,    -0.333431005f,  -0.463735998f },
    { 0.0f,    -0.308402002f,  -0.460655004f },
    { 0.0f,     -0.25276199f,  -0.457060993f },
    { 0.0f,    -0.226135999f,  -0.452955991f },
    { 0.0f,    -0.215074003f,   -0.44837001f },
    { 0.0f,    -0.266965002f,  -0.501981974f },
    { 0.0f,    -0.387537003f,  -0.263983011f },
    { 0.0f,    -0.568105996f,  -0.222800002f },
    { 0.0f,    -0.956220984f,  -0.176549003f },
    { 0.0f,     -1.12237203f,  -0.126333997f },
    { 0.0f,    -0.834299982f, -0.0733570009f },
    { 0.0f,    -0.609296978f, -0.0188759994f },
    { 0.0f,    -0.450051993f,  0.0358089991f },
    { 0.0f,    -0.356626987f,  0.0893910006f }
};
NJS_POINT3 spm_023[25] = 
{
    { 0.0f,           0.0f,             0.0f },
    { 0.0f,   0.224094003f,    -0.125722006f },
    { 0.0f,   0.981598973f,    -0.273948997f },
    { 0.0f,    2.12025094f,    -0.204677001f },
    { 0.0f,    2.59201503f,     0.103661999f },
    { 0.0f,    1.87202299f,     0.563848972f },
    { 0.0f,   0.737565994f,     0.995473027f },
    { 0.0f, 0.00721199997f,        1.204216f },
    { 0.0f,  -0.587921977f,      1.12663901f },
    { 0.0f,  -0.884258986f,     0.848743975f },
    { 0.0f,  -0.827269971f,     0.509276986f },
    { 0.0f,  -0.459913999f,     0.189154997f },
    { 0.0f,     -0.119617f,    0.0278840009f },
    { 0.0f, -0.0057359999f,    0.0189759992f },
    { 0.0f,  0.0569400005f,    0.0112309996f },
    { 0.0f,  0.0684129968f,   0.00464700023f },
    { 0.0f,   0.185518995f, -0.000774000015f },
    { 0.0f,   0.156975999f,  -0.00503499992f },
    { 0.0f, -0.0356190018f,  -0.00813299976f },
    { 0.0f, -0.0849379972f,   -0.0100689996f },
    { 0.0f,  -0.101379998f,   -0.0108430004f },
    { 0.0f, -0.0849379972f,   -0.0104569998f },
    { 0.0f, -0.0356200002f,   -0.0089069996f },
    { 0.0f,           0.0f,  -0.00619600015f },
    { 0.0f,           0.0f,       -0.002324f }
};
NJS_POINT3 spm_026[16] = 
{
    { 0.0f,           0.0f,          0.0f },
    { 0.0f,    0.30459401f,  -1.17761803f },
    { 0.0f,   0.844596028f,  -1.61228299f },
    { 0.0f,    1.18923604f,    -2.095191f },
    { 0.0f,    1.14049196f,  -2.58198094f },
    { 0.0f,   0.903213024f,  -2.77993989f },
    { 0.0f, -0.0704019964f,  -1.82634902f },
    { 0.0f,     -0.180464f, -0.808885992f },
    { 0.0f,   0.594169021f, -0.379321009f },
    { 0.0f,  -0.137284994f, -0.686769009f },
    { 0.0f,   0.586520016f,  -2.03712106f },
    { 0.0f,   -1.14873302f,  -2.89061999f },
    { 0.0f,   -1.01687205f,  -3.97540689f },
    { 0.0f,   -1.09641302f,  -3.57847905f },
    { 0.0f,   -1.72937405f, -0.468986988f },
    { 0.0f,  -0.183275998f, -0.220272005f }
};
NJS_POINT3 spm_028[13] = 
{
    { 0.0f,           0.0f,          0.0f },
    { 0.0f,  -0.151141003f, 0.0439810008f },
    { 0.0f,     -0.316551f, 0.0733029991f },
    { 0.0f,  -0.276656002f, 0.0146599999f },
    { 0.0f, -0.0314540006f, -0.131944001f },
    { 0.0f,   0.250993013f,  -0.27502501f },
    { 0.0f,      0.392113f, -0.341735989f },
    { 0.0f,   0.470683008f, -0.387134999f },
    { 0.0f,   0.486701995f, -0.411226004f },
    { 0.0f,   0.440171003f, -0.414005011f },
    { 0.0f,   0.331088006f, -0.395476013f },
    { 0.0f,   0.159455001f, -0.355636001f },
    { 0.0f, -0.0862509981f, -0.348071992f }
};
NJS_POINT3 spm_029[20] = 
{
    { 0.0f,           0.0f,           0.0f },
    { 0.0f,  -0.393936992f,  -0.350028008f },
    { 0.0f,  -0.526373029f,  -0.362201005f },
    { 0.0f,  -0.617738008f,  -0.370819002f },
    { 0.0f,  -0.668031991f,  -0.375883013f },
    { 0.0f,  -0.677253008f,  -0.377393007f },
    { 0.0f,  -0.645403981f,  -0.375348002f },
    { 0.0f,   -0.57248199f,  -0.369747996f },
    { 0.0f,  -0.458487004f,  -0.360596001f },
    { 0.0f,  -0.303422004f,  -0.347887009f },
    { 0.0f,  -0.148374006f,  -0.331624001f },
    { 0.0f, -0.0359250009f,  -0.311807007f },
    { 0.0f,  0.0537150018f,  -0.288435996f },
    { 0.0f,   0.120548002f,  -0.261510015f },
    { 0.0f,   0.164574996f,  -0.231029004f },
    { 0.0f,   0.185794994f,  -0.196994007f },
    { 0.0f,   0.184208006f,  -0.159407005f },
    { 0.0f,      0.159814f,  -0.118261002f },
    { 0.0f,   0.112613998f, -0.0735640004f },
    { 0.0f,  0.0426059999f, -0.0253110006f }
};
NJS_POINT3 spmh_026[16] = 
{
    { 0.0f,          0.0f,          0.0f },
    { 0.0f,  0.203879997f,   1.05717099f },
    { 0.0f,  0.607263982f,   1.96484005f },
    { 0.0f,  0.976207018f,   1.15935194f },
    { 0.0f,     1.159971f,   2.03937006f },
    { 0.0f,  0.946618974f,   3.05633402f },
    { 0.0f,  0.392645001f,   2.22015095f },
    { 0.0f,  0.428660005f,   1.87996101f },
    { 0.0f, -0.874442995f,  0.907414019f },
    { 0.0f,  0.206529006f,     1.272668f },
    { 0.0f,  0.258655995f,   1.68754995f },
    { 0.0f, -0.430880994f,   3.26340199f },
    { 0.0f,  -1.18263304f,    -1.137707f },
    { 0.0f,  -1.22665501f, -0.229169995f },
    { 0.0f,  -1.02153397f,  0.262127012f },
    { 0.0f, -0.444285005f, -0.108080998f }
};
NJS_POINT3 spmh_013[10] = 
{
    { 0.0f,           0.0f,          0.0f },
    { 0.0f,  -0.242614999f, -0.224384993f },
    { 0.0f,  -0.404422998f, -0.304396003f },
    { 0.0f, -0.0810950026f, -0.374191999f },
    { 0.0f,    0.72736901f, -0.433775991f },
    { 0.0f,    1.38212895f, -0.483148009f },
    { 0.0f,    1.51324797f, -0.522302985f },
    { 0.0f,    1.57458794f, -0.530400991f },
    { 0.0f,    1.56615698f, -0.546994984f },
    { 0.0f,    1.48794401f, -0.618399024f }
};
NJS_POINT3 spmh_015[30] = 
{
    { 0.0f,           0.0f,           0.0f },
    { 0.0f,    1.12219799f,  -0.925270021f },
    { 0.0f,   0.860957026f,   -1.11558104f },
    { 0.0f,   0.615898013f,      -1.17758f },
    { 0.0f,   0.389692008f,   -1.01981294f },
    { 0.0f,   0.125657007f,  -0.875569999f },
    { 0.0f,      -0.19438f,  -0.744898021f },
    { 0.0f,  -0.510737002f,  -0.627790987f },
    { 0.0f,  -0.775402009f,  -0.524253011f },
    { 0.0f,  -0.988370001f,  -0.434282988f },
    { 0.0f,   -1.14964795f,  -0.357879996f },
    { 0.0f,   -1.25923097f,  -0.295046002f },
    { 0.0f,   -1.31712306f,  -0.245778993f },
    { 0.0f,   -1.32331705f,  -0.210078999f },
    { 0.0f,   -3.11279607f,  -0.187948003f },
    { 0.0f,   -2.46084905f,  -0.163435996f },
    { 0.0f,   0.801108003f,  -0.129717007f },
    { 0.0f,   0.968285978f,  -0.099326998f },
    { 0.0f,   0.263590008f, -0.0722640008f },
    { 0.0f,   0.144869998f, -0.0485250019f },
    { 0.0f,  0.0444109999f, -0.0281119999f },
    { 0.0f, -0.0377870016f, -0.0110309999f },
    { 0.0f,  -0.101727001f, 0.00272800005f },
    { 0.0f,  -0.147406995f,  0.0131569998f },
    { 0.0f,  -0.174825996f,  0.0202600006f },
    { 0.0f,  -0.183984995f,      0.024038f },
    { 0.0f,  -0.174886003f,  0.0244859997f },
    { 0.0f,  -0.147525996f,  0.0216090009f },
    { 0.0f,  -0.101906002f,  0.0154050002f },
    { 0.0f, -0.0380269997f,  0.0058749998f }
};

static int ENE03_HITPOINT[4][16] = 
{
    { 130, 130, 130, 130, 130, 150, 150, 150, 150, 150, 150, 180, 180, 180, 180, 180 },
    {  50,  50,  50,  50,  50,  70,  70,  70,  70,  70,  70,  90,  90,  90,  90,  90 },
    {  90,  90,  90,  90,  90, 110, 110, 110, 130, 130, 130, 130, 130, 150, 150, 150 },
    {  30,  30,  30,  30,  30,  50,  50,  50,  60,  60,  60,  60,  60,  70,  70,  70 }
};
static char spider_tree[5][6] = 
{
    {  0, -1,  0,  0,  0,  0 },
    {  0,  1,  7,  8,  9, -1 },
    {  0,  1, 25, 26, 27, -1 },
    {  0,  1, 10, 11, 12, -1 },
    {  0,  1, 28, 29, 30, -1 }
};
static char SdwTab[6] = 
{
    1, 12, 30, 9, 27, -1
};
static char flip_tree[37] = 
{
     0,  1,  2,  5,  6,  3,  4, 10,
    11, 12,  7,  8,  9, 16, 17, 18,
    13, 14, 15, 22, 23, 24, 19, 20,
    21, 28, 29, 30, 25, 26, 27, 33,
    34, 31, 32, 36, 35
};
static ETTY_WORK ene03_child = 
{
    0x8001, 31, 0, 0, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, { 0, 0, 0, 0 }
};
static char BrokenParts[8] = 
{
    10, 16, 22, 28, 7, 13, 19, 25
};
static ETTY_WORK ene24 =
{
    0x8001, 24, 0, 0, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, { 0, 0, 0, 0 }
};
static ETTY_WORK ene03_leader = 
{
    0x4008001, 3, 0, 0, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, { 0, 0, 0, 0 }
};
static BP_WORK BloodParam = 
{
    { 0.0f, 0.1f, 0.0f }, 0, 0.0f, 0.07f, { 0.4f, 0.1f, 0.4f, 0.3f, 0.2f }, { 0, 3, 6, 9, 12 }
};
static BLOOD_TBL BloodTbl[37] = 
{
    { 1, {  0.0f, 0.0f,  0.0f }, 0.0f, 0.0f, 0.0f },
    { 1, {  0.0f, 3.0f,  0.0f }, 2.0f, 0.0f, 2.0f },
    { 1, {  0.0f, 6.0f,  8.0f }, 3.0f, 0.0f, 4.0f },
    { 1, {  0.0f, 6.0f, -8.0f }, 6.0f, 3.0f, 8.0f },
    { 1, {  0.0f, 6.0f, -8.0f }, 6.0f, 3.0f, 8.0f },
    { 1, {  0.0f, 6.0f, -8.0f }, 6.0f, 3.0f, 8.0f },
    { 1, {  0.0f, 6.0f, -8.0f }, 6.0f, 3.0f, 8.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, { -1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 0, {  1.0f, 0.0f,  0.0f }, 1.0f, 0.0f, 0.0f },
    { 1, {  0.0f, 0.0f,  0.0f }, 0.0f, 0.0f, 0.0f },
    { 1, {  0.0f, 0.0f,  0.0f }, 0.0f, 0.0f, 0.0f },
    { 1, {  0.0f, 0.0f,  0.0f }, 0.0f, 0.0f, 0.0f },
    { 1, {  0.0f, 0.0f,  0.0f }, 0.0f, 0.0f, 0.0f },
    { 1, {  0.0f, 0.0f,  0.0f }, 0.0f, 0.0f, 0.0f },
    { 1, {  0.0f, 0.0f,  0.0f }, 0.0f, 0.0f, 0.0f }
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
    {  0, { 0, 0, 0 },  0,  0 },
    {  0, { 0, 0, 0 },  0,  0 },
    {  4, { 1, 0, 0 }, 30, 20 },
    { 10, { 4, 3, 1 }, 20, 10 },
    { 10, { 4, 3, 1 }, 20, 10 },
    { 10, { 4, 3, 1 }, 10,  0 },
    {  0, { 0, 0, 0 }, 25,  0 },
    {  0, { 0, 0, 0 }, 25,  0 },
    { 25, { 5, 3, 1 },  5,  0 },
    {  0, { 0, 0, 0 }, 60,  0 },
    {  0, { 0, 0, 0 }, 10,  0 },
    {  0, { 0, 0, 0 }, 30,  0 },
    { 25, { 5, 4, 2 }, 10,  0 },
    {  0, { 0, 0, 0 }, 60,  0 },
    {  0, { 0, 0, 0 },  0,  0 },
    {  0, { 0, 0, 0 },  0,  0 },
    { 15, { 1, 1, 1 },  5,  0 },
    {  0, { 0, 0, 0 },  0,  0 },
    {  0, { 0, 0, 0 },  0,  0 },
    {  0, { 0, 0, 0 },  0,  0 },
    {  0, { 0, 0, 0 },  0,  0 }
};
static COMBJOINT_WORK CombJointTbl[37] = { 0 };
static CPCL CapColTabA[23] = 
{
    {  1,  1,  16 },
    {  0,  0, -20 },
    {  1,  1,  11 },
    {  0,  0, -38 },
    {  2,  2,  30 },
    {  0, 15,  20 },
    {  7,  8,   3 },
    {  8,  9,   3 },
    { 10, 11,   3 },
    { 11, 12,   3 },
    { 13, 14,   3 },
    { 14, 15,   3 },
    { 16, 17,   3 },
    { 17, 18,   3 },
    { 19, 20,   3 },
    { 20, 21,   3 },
    { 22, 23,   3 },
    { 23, 24,   3 },
    { 25, 26,   3 },
    { 26, 27,   3 },
    { 28, 29,   3 },
    { 29, 30,   3 },
    {  0,  0,   0 }
};
static CPCL CapColTabB[21] = 
{
    {  1,  1,  16 },
    {  0,  0, -20 },
    {  1,  1,  11 },
    {  0,  0, -38 },
    {  7,  8,   3 },
    {  8,  9,   3 },
    { 10, 11,   3 },
    { 11, 12,   3 },
    { 13, 14,   3 },
    { 14, 15,   3 },
    { 16, 17,   3 },
    { 17, 18,   3 },
    { 19, 20,   3 },
    { 20, 21,   3 },
    { 22, 23,   3 },
    { 23, 24,   3 },
    { 25, 26,   3 },
    { 26, 27,   3 },
    { 28, 29,   3 },
    { 29, 30,   3 },
    {  0,  0,   0 }
};

void (*bhEne03_Mode0[6])(BH_PWORK*) = 
{
	bhEne03_Init,
	bhEne03_Move,
	bhEne03_Nage,
	bhEne03_Damage,
	bhEne03_Die,
	bhEne_Event
};
void (*bhEne03_BrainType[3])(BH_PWORK*) = 
{
	bhEne03_BR00,
	bhEne03_BR01,
	bhEne03_BR02
};
void (*bhEne03_MoveMode2[20])(BH_PWORK*) = 
{
	bhEne03_MV00,
	bhEne03_MV01,
	bhEne03_MV02,
	bhEne03_MV03,
	bhEne03_MV04,
	bhEne03_MV05,
	bhEne03_MV06,
	bhEne03_MV07,
	bhEne03_MV08,
	bhEne03_MV09,
	bhEne03_MV10,
	bhEne03_MV11,
	bhEne03_MV12,
	bhEne03_MV13,
	bhEne03_MV14,
	bhEne03_MV15,
	bhEne03_MV16,
	bhEne03_MV17,
	bhEne03_MV18,
	bhEne03_MV19
};
void (*bhEne03_NageMode2[2])(BH_PWORK*) = 
{
	bhEne03_NG00,
	bhEne03_NG01
};
void (*bhEne03_DamageMode2[13])(BH_PWORK*) = 
{
	bhEne03_DG00,
	bhEne03_DG01,
	bhEne03_DG02,
	bhEne03_DG03,
	bhEne03_DG04,
	bhEne03_DG05,
	bhEne03_DG06,
	bhEne03_DG07,
	bhEne03_DG08,
	bhEne03_DG09,
	bhEne03_DG10,
	bhEne03_DG11,
	bhEne03_DG12
};
void (*bhEne03_DeadMode2[6])(BH_PWORK*) = 
{
	bhEne03_DD00,
	bhEne03_DD01,
	bhEne03_DD02,
	bhEne03_DD03,
	bhEne03_DD04,
	bhEne03_DD05
};

// 100% matching!
void bhEne03(BH_PWORK* epw)
{
    NJS_POINT3 pos;   
    unsigned int flg;
    float px, py, pz; // not from DWARF

    if ((epw->flg & 0x4000000)) 
    {
        if ((EPW_EXP1_I(0) & 0x4))
        {
            bhEne03_PlayerControl(epw);
        }
        
        if (EPW_EXP1_I(8) != 0)
        {
            EPW_EXP1_I(8)--;
        }
    }
    else 
    {
        bhEne03_Mode0[epw->mode0](epw);
        
        bhEne03_CallSE(epw);
        
        bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
        
        px = epw->px;
        py = epw->py;
        pz = epw->pz;
        
        if ((epw->flg & 0x100000)) 
        {
            bhEne03_GetPartsPos(epw, spider_tree[0], &pos);
            
            epw->aox = pos.x - epw->px;
            epw->aoy = pos.y - epw->py;
            epw->aoz = pos.z - epw->pz;
            
            if (!(epw->flg & 0x200000)) 
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
        
        switch (EXP0_C(105))
        {
        case 0:
            epw->car = 6.0f;
            epw->cah = 6.0f;
            break;
        case 1:
            epw->car = 6.0f;
            epw->cah = 6.0f;
            
            epw->aoy -= 6.0f;
            break;
        default:
            epw->car = 6.0f;
            epw->cah = 12.0f;
            
            epw->aoy -= 6.0f;
            break;
        }
        
        if ((epw->flg & 0x8)) 
        {
            bhCheckPlayer(epw);
            
            bhEne_CheckEnemiesBall(epw);
        }
        
        if ((ATR_WORK*)EXP0_I(96) != NULL)
        {
            switch (EXP0_C(105))
            {
            case 0:           
            case 1:           
                epw->py = py;
                break;
            case 2:           
            case 4:           
                epw->px = px;
                break;
            case 3:           
            case 5:           
                epw->pz = pz;
                break;
            }
        }
        
        if ((ATR_WORK*)EXP0_I(96) == NULL)
        {
            bhEne03_CollisionLine(epw);
            
            if (((epw->flg & 0x10)) && (bhEne03_CollisionWalls(epw) != 0)) 
            {
                bhEne03_CollisionLine(epw);
            }
        }
        else if ((epw->flg & 0x10)) 
        {
            bhEne03_CollisionWalls(epw);
            bhEne03_CollisionLine2(epw);
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
            bhEne_SetWeponAtr(epw, 35, 1, 5.0f);
        }
        else
        {
            bhEne_SetWeponAtr(epw, 35, 6, 5.0f);
            return;
        }
    }
}

// 100% matching!
void bhEne03_Init(BH_PWORK* epw)
{
    BH_PWORK** epw2, *ep, *ep_leader;    
    O_WORK* owk;         
    int i;              

    epw->flg |=  0x1078;
    epw->flg &= ~0x8006;
    
    epw->flg = (unsigned short)epw->flg;
    
    epw->mdflg |= 0x4;
    
    epw->ar = 6.0f;
    epw->ah = 6.0f;
    
    epw->car = 6.0f;
    epw->cah = 6.0f;
    
    epw->aox = 0;
    epw->aoy = 0;
    epw->aoz = 0;
    
    epw->hokan_rate  = 65536;
    epw->hokan_count = 0;
    
    epw->mtn_no  = 0;
    epw->mtn_md  = 0;
    epw->mtn_add = 65536;
    
    epw->frm_no = 0;
    
    epw->mtn_tp = (unsigned char*)flip_tree;
    epw->mtn_md &= ~0x2;
    
    bhCalcModel(epw);
    
    epw->mode0 = 1;
    epw->mode1 = 1;
    epw->mode2 = 0;
    epw->mode3 = 0;

    if (epw->exp0 == NULL) 
    {
        epw->exp0 = bhEne_CallocWork(240, 8);
        
        ep = ene;
        
        for (i = 0; i < sys->ewk_n; i++, ep++) 
        {
            if (((ep->flg & 0x1)) && (ep->id == 3)) 
            {
                if (ep->exp1 != NULL)
                {
                    epw->exp1 = ep->exp1;
                } 
                else 
                {
                    epw->exp1 = bhEne_CallocWork(12, 8);
                }
                
                if (ep->exp2 != NULL) 
                {
                    epw->exp2 = ep->exp2;
                } 
                else 
                {
                    ep_leader = bhSetEnemy(&ene03_leader, rom->ene_n);
                    
                    epw->exp2 = (unsigned char*)ep_leader;
                    
                    ep_leader->mdflg |= 0x1;
                    ep_leader->mdflg |= 0x20;
                    
                    ep_leader->exp1 = epw->exp1;
                    
                    ep_leader->mnwP = epw->mnwP;
                }
                
                break;
            }
        }

        epw2 = (BH_PWORK**)&EXP0_C(128); 
        
        for (i = 0; i < 8; i++) 
        {
            *epw2 = bhSetEnemy(&ene03_child, rom->ene_n);
            
            (*epw2)->type = 0;
            
            (*epw2)->lkwkp = (unsigned char*)epw;
            (*epw2)->lkono = i >= 4;
            
            (*epw2)->lox = 0;
            (*epw2)->loy = 0;
            (*epw2)->loz = 0;
            
            (*epw2)->mdflg |= 0x1;
            (*epw2)->mdflg |= 0x20;
            
            owk = &epw->mlwP->owP[BrokenParts[i]];
            
            (*epw2)->mtx = &owk->mtx;
            
            (*epw2++)->exp1 = (unsigned char*)owk;
        }

        bhEne_SetCallFunc(bhEne03s, 31);
        
        epw2 = (BH_PWORK**)&EXP0_C(168);
        
        for (i = 0; i < 15; i++) 
        {
            *epw2 = bhSetEnemy(&ene24, rom->ene_n);
            
            (*epw2)->lkwkp = (unsigned char*)epw;
            (*epw2)->lkono = 0;
            
            (*epw2)->lox = 0;
            (*epw2)->loy = 0;
            (*epw2)->loz = 0;
            
            (*epw2++)->mlwP = &epw->mdl[1];
        }
    }

    EXP0_C(104) = 0;
    
    EXP0_F(64) = 999.0f;
    
    EXP0_I(68) = 0;
    EXP0_I(72) = 0;
    EXP0_I(76) = 0;
    EXP0_I(80) = 0;
    
    EXP0_I(228) = (rand() % 90) + 60;
    EXP0_I(232) = 0;

    i = rand() % 16;
    
    if (sys->gm_mode != 2) 
    {
        epw->hp     = ENE03_HITPOINT[0][i];
        EXP0_I(124) = ENE03_HITPOINT[1][i];
    } 
    else 
    {
        epw->hp     = ENE03_HITPOINT[2][i];
        EXP0_I(124) = ENE03_HITPOINT[3][i];
    }

    for (i = 0; i < 8; i++) 
    {
        ((char*)epw->exp0)[i + 160] = 0;
    }
    
    {
    int i;      
    NJS_POINT3 p; 
	int sdw;      

    epw2 = (BH_PWORK**)&EXP0_C(168);
        
    for (i = 0; i < 15; i++) 
    {
        (*epw2++)->mdflg |= 0x1;
    }

    EPW_EXP1_I(0) = 0;
    EPW_EXP1_I(8) = (rand() % 30) + 60;
        
    njUnitMatrix((NJS_MATRIX*)epw->exp0);
        
    njRotateY((NJS_MATRIX*)epw->exp0, epw->ay);

    *(ATR_WORK**)&EXP0_I(96) = NULL;
        
    if ((epw->type & 0x2))
    {
        p.x = epw->px;
        p.y = epw->py + 999.0f;
        p.z = epw->pz;
        
        if ((*(ATR_WORK**)&EXP0_I(96) = bhCollisionCheckLine((NJS_POINT3*)&epw->px, &p)) != NULL) 
        {
            EXP0_C(105) = 1;
            
            bhEne03_MakeMatrix(epw); 
            
            epw->py = p.y;
        }
        
        epw->type &= ~0x2;
    }
    
    if ((ATR_WORK*)EXP0_I(96) == NULL) 
    {
        EXP0_C(105) = 0;
        
        *(ATR_WORK**)&EXP0_I(96) = bhEne03_GetWall(epw);
    }

    epw->pxb = epw->px;
    epw->pyb = epw->py;
    epw->pzb = epw->pz;
        
    epw->clp_jno[0] = 1;
    epw->clp_jno[1] = 5;
    epw->clp_jno[2] = 12;
    epw->clp_jno[3] = 30;
    epw->clp_jno[4] = 9;
    epw->clp_jno[5] = 27;
    epw->clp_jno[6] = 32;
    epw->clp_jno[7] = 34;
        
    epw->mdflg &= ~0x20;

    if (!(epw->flg & 0x800))
    {
        sdw = bhSetShadow(SdwTab, (unsigned char*)epw, 0, 8.0f, 8.0f, 9.0f);
        
        eff[sdw].id = 258;
        
        epw->flg |= 0x800;
    }
        
    epw->stflg &= ~0x8;

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
        bhEne03_HideParts(epw, 2, 1);
    }
        
    bhEne03_SetModelFlg(epw, -4, 0);

    if ((epw->type & 0x4)) 
    {
        epw->type &= ~0x4;
        
        epw->flg   |= 0x2000000;
        epw->stflg |= 0x8;
        
        epw->flg &= ~0x28;
    }
    }
}

// 100% matching!
void bhEne03_Brain(BH_PWORK* epw)
{
	if ((epw->flg & 0x2000000))
    {
        bhEne03_BrainType[2](epw);
    }
    else 
	{
		bhEne03_BrainType[epw->type](epw);
	}
}

// 100% matching!
void bhEne03_BR00(BH_PWORK* epw)
{
	float dist;

    EXP0_F(64) = njDistanceP2P((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px);
    
    bhEne03_SearchPlayer(epw, 21845);
    
    if ((EXP0_UC(104) == 0) && (epw->mode2 != 4) && (EXP0_F(64) < 20.0f)) 
    {
        epw->mode0 = 1;
        epw->mode1 = 0;
        epw->mode2 = 4;
        epw->mode3 = 0;
    }
    
    if (plp->hp >= 0) 
    {
        if (EXP0_C(105) == 0)
        { 
            if ((EXP0_UC(104) == 1) && (EXP0_F(64) > 12.0f) && (epw->mode2 != 3))
            {
                epw->mode0 = 1;
                epw->mode2 = 3;
                epw->mode3 = 0;
            }
            
            if (((plp->stflg & 0x80000000)) || (((plp->flg & 0x4)) || ((epw->flg & 0x4))))
            {
                return;
            }
            
            if ((bhEne_CheckEventAtr(plp->flr_no, plp->px, plp->pz, 3, 0, 0) == NULL) && (EPW_EXP1_I(8) == 0))
            {
                if ((EXP0_F(64) < 20.0f) && (abs(EXP0_I(68)) < 5461) && (fabsf(epw->py - plp->py) < 0.01f)) 
                {
                    epw->mode1 = 0;
                    epw->mode2 = 19;
                    epw->mode3 = 0;
                    
                    EPW_EXP1_I(8) = (rand() % 30) + 60;
                    return;
                }
            }
            
            if (EXP0_I(228) == 0) 
            {
                if ((EXP0_F(64) < 25.0f) && (abs(EXP0_I(68)) < 3640)) 
                {
                    epw->mode0 = 1;
                    epw->mode1 = 0;
                    epw->mode2 = 9;
                    epw->mode3 = 0;
                    
                    EXP0_I(228) = (rand() % 90) + 60;
                }
            } 
            else 
            {
                EXP0_I(228)--;
            }
        }
        else if (EXP0_C(105) == 1)
        {
            dist = njSqrt(((plp->px - epw->px) * (plp->px - epw->px)) + ((plp->pz - epw->pz) * (plp->pz - epw->pz)));
            
            if ((epw->py > plp->py) && (dist < 40.0f) && (abs(EXP0_I(68)) > 16384) && (bhEne03_DiveSpace(epw) != 0)) 
            {
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 11;
                epw->mode3 = 0;
            }
            
            if (EXP0_I(228) == 0) 
            {
                if ((epw->py > plp->py) && (dist < 25.0f) && (abs(EXP0_I(68)) < 3640))
                {
                    epw->mode0 = 1;
                    epw->mode1 = 0;
                    epw->mode2 = 9;
                    epw->mode3 = 0;
                    
                    EXP0_I(228) = (rand() % 90) + 60;
                }
            } 
            else 
            {
                EXP0_I(228)--;
            }
        }
        else
        {
            dist = njSqrt(((plp->px - epw->px) * (plp->px - epw->px)) + ((plp->pz - epw->pz) * (plp->pz - epw->pz)));
            
            if ((EXP0_UC(104) == 1) && (EXP0_F(64) > 12.0f) && (epw->mode2 != 3)) 
            {
                epw->mode0 = 1;
                epw->mode2 = 3;
                epw->mode3 = 0;
            }
        }
    }
}

// 100% matching!
void bhEne03_BR01(BH_PWORK* epw) 
{
    float dx, dy, dz; 
    
    dx = epw->px - plp->px;
    dy = epw->py - plp->py;
    dz = epw->pz - plp->pz;

    switch (EXP0_C(105)) 
    {
    case 0:
    case 1:
        EXP0_F(64) = njSqrt((dx * dx) + (dz * dz));
        break;
    case 2:
    case 4:
        EXP0_F(64) = njSqrt((dy * dy) + (dz * dz));
        break;
    case 3:
    case 5:
        EXP0_F(64) = njSqrt((dx * dx) + (dy * dy));
        break;
    }

    bhEne03_SearchPlayer(epw, 21845);

    if (plp->hp >= 0) 
    {
        if (EXP0_UC(104) == 1) 
        {
            if ((EXP0_F(64) > 12.0f) && (epw->mode2 != 3)) 
            {
                epw->mode0 = 1;
                epw->mode2 = 3;
                epw->mode3 = 0;
            }
            
            if ((epw->mode2 != 4) && (EXP0_F(64) < 20.0f) && (abs(EXP0_I(68)) > 3640)) 
            {
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 4;
                epw->mode3 = 0;
            }
        }
        
        if (EXP0_C(105) == 0) 
        {
            if ((EXP0_UC(104) == 1) && (EXP0_F(64) > 20.0f) && (bhEne03_CheckJumpSpace(epw) != 0)) 
            {
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 14;
                epw->mode3 = 0;
            }
            
            if ((((plp->stflg & 0x80000000)) || ((plp->flg & 0x4))) || ((epw->flg & 0x4))) 
            {
                return;
            }
            
            if (bhEne_CheckEventAtr(plp->flr_no, plp->px, plp->pz, 3, 0, 0) != NULL) 
            {
                if (EXP0_I(228) == 0) 
                {
                    if ((EXP0_F(64) < 25.0f) && (abs(EXP0_I(68)) < 3640)) 
                    {
                        epw->mode0 = 1;
                        epw->mode1 = 0;
                        epw->mode2 = 9;
                        epw->mode3 = 0;
                        
                        EXP0_I(228) = 20;
                    }
                } 
                else 
                {
                    EXP0_I(228)--;
                }
            }
            else if (EPW_EXP1_I(8) == 0) 
            {
                if ((EXP0_F(64) < 30.0f) && ((abs(EXP0_I(68)) <= 7280) && (fabsf(epw->py - plp->py) < 0.01f))) 
                {
                    epw->mode1 = 0;
                    epw->mode2 = 19;
                    epw->mode3 = 0;
                    
                    EPW_EXP1_I(8) = (rand() % 30) + 60;
                }
            }
        } 
        else if (EXP0_C(105) == 1)
        {
            if ((epw->py > plp->py) && (EXP0_F(64) < 40.0f) && (bhEne03_DiveSpace(epw) != 0)) 
            {
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 11;
                epw->mode3 = 0;
            }
        } 
        else if ((EXP0_UC(104) == 1) && (EXP0_F(36) > 0) && (bhEne03_CheckJumpSpace(epw) != 0)) 
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 15;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne03_BR02(BH_PWORK* epw)
{
    EXP0_F(64) = njDistanceP2P((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px);

    bhEne03_SearchPlayer(epw, 21845);

    EXP0_C(104) = 1;

    if (EXP0_I(228) == 0)
    {
        if ((EXP0_F(64) < 25.0f) && (abs(EXP0_I(68)) < 3640))
        {
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 10;
            epw->mode3 = 0;

            EXP0_I(228) = (rand() % 90) + 60;
        }
    }
    else
    {
        EXP0_I(228)--;
    }
}

// 100% matching!
void bhEne03_Move(BH_PWORK* epw)
{
    if (epw->mode1 == 1)
    {
        bhEne03_Brain(epw);
    }

    if (((epw->flg & 0x4)) && (!(epw->flg & 0x2)))
    {
        bhEne03_DamageInit(epw);
    }

    if (epw->mode0 == 1)
    {
        bhEne03_MoveMode2[epw->mode2](epw);
    }
}

// 
// Start address: 0x197ea0
void bhEne03_MV00(BH_PWORK* epw)
{
	static unsigned char action_table[2][6] = 
	{
		{ 1,  1,  2, 2, 0, 0 },
		{ 1, 17, 17, 2, 0, 0 }
	};
	// Line 1416, Address: 0x197ea0, Func Offset: 0
	// Line 1430, Address: 0x197eb0, Func Offset: 0x10
	// Line 1433, Address: 0x197ed0, Func Offset: 0x30
	// Line 1434, Address: 0x197edc, Func Offset: 0x3c
	// Line 1435, Address: 0x197ee8, Func Offset: 0x48
	// Line 1437, Address: 0x197eec, Func Offset: 0x4c
	// Line 1436, Address: 0x197ef0, Func Offset: 0x50
	// Line 1437, Address: 0x197ef4, Func Offset: 0x54
	// Line 1438, Address: 0x197ef8, Func Offset: 0x58
	// Line 1440, Address: 0x197efc, Func Offset: 0x5c
	// Line 1441, Address: 0x197f04, Func Offset: 0x64
	// Line 1442, Address: 0x197f14, Func Offset: 0x74
	// Line 1444, Address: 0x197f18, Func Offset: 0x78
	// Line 1443, Address: 0x197f1c, Func Offset: 0x7c
	// Line 1444, Address: 0x197f20, Func Offset: 0x80
	// Line 1445, Address: 0x197f24, Func Offset: 0x84
	// Line 1450, Address: 0x197f2c, Func Offset: 0x8c
	// Line 1451, Address: 0x197f50, Func Offset: 0xb0
	// Line 1453, Address: 0x197f5c, Func Offset: 0xbc
	// Line 1454, Address: 0x197f6c, Func Offset: 0xcc
	// Line 1455, Address: 0x197f70, Func Offset: 0xd0
	// Line 1456, Address: 0x197fb4, Func Offset: 0x114
	// Line 1460, Address: 0x197fb8, Func Offset: 0x118
	// Func End, Address: 0x197fc8, Func Offset: 0x128
}

// 
// Start address: 0x197fd0
void bhEne03_MV01(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	// Line 1470, Address: 0x197fd0, Func Offset: 0
	// Line 1473, Address: 0x197fe0, Func Offset: 0x10
	// Line 1476, Address: 0x198000, Func Offset: 0x30
	// Line 1477, Address: 0x19800c, Func Offset: 0x3c
	// Line 1478, Address: 0x198018, Func Offset: 0x48
	// Line 1480, Address: 0x198030, Func Offset: 0x60
	// Line 1482, Address: 0x198034, Func Offset: 0x64
	// Line 1483, Address: 0x19803c, Func Offset: 0x6c
	// Line 1484, Address: 0x198044, Func Offset: 0x74
	// Line 1486, Address: 0x198048, Func Offset: 0x78
	// Line 1487, Address: 0x198050, Func Offset: 0x80
	// Line 1488, Address: 0x198060, Func Offset: 0x90
	// Line 1490, Address: 0x198064, Func Offset: 0x94
	// Line 1489, Address: 0x198068, Func Offset: 0x98
	// Line 1490, Address: 0x19806c, Func Offset: 0x9c
	// Line 1491, Address: 0x198070, Func Offset: 0xa0
	// Line 1495, Address: 0x198078, Func Offset: 0xa8
	// Line 1496, Address: 0x198094, Func Offset: 0xc4
	// Line 1495, Address: 0x198098, Func Offset: 0xc8
	// Line 1496, Address: 0x19809c, Func Offset: 0xcc
	// Line 1497, Address: 0x1980ac, Func Offset: 0xdc
	// Line 1498, Address: 0x1980bc, Func Offset: 0xec
	// Line 1499, Address: 0x1980c4, Func Offset: 0xf4
	// Line 1501, Address: 0x198118, Func Offset: 0x148
	// Line 1502, Address: 0x198124, Func Offset: 0x154
	// Line 1504, Address: 0x198130, Func Offset: 0x160
	// Line 1506, Address: 0x19813c, Func Offset: 0x16c
	// Line 1508, Address: 0x198150, Func Offset: 0x180
	// Line 1510, Address: 0x198160, Func Offset: 0x190
	// Line 1509, Address: 0x198164, Func Offset: 0x194
	// Line 1510, Address: 0x198168, Func Offset: 0x198
	// Line 1512, Address: 0x19816c, Func Offset: 0x19c
	// Line 1515, Address: 0x198174, Func Offset: 0x1a4
	// Line 1517, Address: 0x198188, Func Offset: 0x1b8
	// Line 1516, Address: 0x19818c, Func Offset: 0x1bc
	// Line 1517, Address: 0x198190, Func Offset: 0x1c0
	// Line 1519, Address: 0x198194, Func Offset: 0x1c4
	// Line 1522, Address: 0x19819c, Func Offset: 0x1cc
	// Line 1526, Address: 0x1981a8, Func Offset: 0x1d8
	// Line 1529, Address: 0x1981b4, Func Offset: 0x1e4
	// Line 1530, Address: 0x1981dc, Func Offset: 0x20c
	// Line 1531, Address: 0x1981e8, Func Offset: 0x218
	// Line 1532, Address: 0x1981f0, Func Offset: 0x220
	// Line 1534, Address: 0x1981f8, Func Offset: 0x228
	// Line 1535, Address: 0x198208, Func Offset: 0x238
	// Line 1534, Address: 0x19820c, Func Offset: 0x23c
	// Line 1535, Address: 0x198210, Func Offset: 0x240
	// Line 1538, Address: 0x198220, Func Offset: 0x250
	// Line 1539, Address: 0x198234, Func Offset: 0x264
	// Line 1540, Address: 0x198248, Func Offset: 0x278
	// Line 1543, Address: 0x198254, Func Offset: 0x284
	// Line 1544, Address: 0x198264, Func Offset: 0x294
	// Line 1545, Address: 0x19826c, Func Offset: 0x29c
	// Line 1546, Address: 0x198270, Func Offset: 0x2a0
	// Line 1554, Address: 0x198274, Func Offset: 0x2a4
	// Func End, Address: 0x198284, Func Offset: 0x2b4
}

// 100% matching!
void bhEne03_MV02(BH_PWORK* epw)
{
	int dir;
	
    dir = (rand() % 63) & 1;

    switch (epw->mode3)                              
    {
    case 0:
        if (epw->mtn_no != (dir + 6))
        {
            epw->mtn_no = dir + 6;
            epw->frm_no = 0;

            epw->hokan_count = 10;
            epw->hokan_rate  = 32768;
        }

        epw->ct0 = rand() % 63;

        epw->ayp = ((dir != 0) ? 1 : -1) * 819;

        epw->mode3++;
    case 1:
        njRotateY((NJS_MATRIX*)epw->exp0, epw->ayp);

        if (epw->ct0-- == 0)
        {
            epw->mode1 = 0;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }

        break;
    }
}

// 
// Start address: 0x198380
void bhEne03_MV03(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	// Line 1600, Address: 0x198380, Func Offset: 0
	// Line 1603, Address: 0x198390, Func Offset: 0x10
	// Line 1605, Address: 0x1983b0, Func Offset: 0x30
	// Line 1607, Address: 0x1983bc, Func Offset: 0x3c
	// Line 1608, Address: 0x1983cc, Func Offset: 0x4c
	// Line 1610, Address: 0x1983d0, Func Offset: 0x50
	// Line 1609, Address: 0x1983d4, Func Offset: 0x54
	// Line 1610, Address: 0x1983d8, Func Offset: 0x58
	// Line 1611, Address: 0x1983dc, Func Offset: 0x5c
	// Line 1612, Address: 0x1983e4, Func Offset: 0x64
	// Line 1615, Address: 0x1983f0, Func Offset: 0x70
	// Line 1616, Address: 0x198410, Func Offset: 0x90
	// Line 1618, Address: 0x198418, Func Offset: 0x98
	// Line 1619, Address: 0x198428, Func Offset: 0xa8
	// Line 1621, Address: 0x19842c, Func Offset: 0xac
	// Line 1620, Address: 0x198430, Func Offset: 0xb0
	// Line 1621, Address: 0x198434, Func Offset: 0xb4
	// Line 1622, Address: 0x198438, Func Offset: 0xb8
	// Line 1623, Address: 0x198440, Func Offset: 0xc0
	// Line 1626, Address: 0x19844c, Func Offset: 0xcc
	// Line 1628, Address: 0x198470, Func Offset: 0xf0
	// Line 1629, Address: 0x198488, Func Offset: 0x108
	// Line 1631, Address: 0x198494, Func Offset: 0x114
	// Line 1633, Address: 0x1984a0, Func Offset: 0x120
	// Line 1635, Address: 0x1984b4, Func Offset: 0x134
	// Line 1637, Address: 0x1984c4, Func Offset: 0x144
	// Line 1636, Address: 0x1984c8, Func Offset: 0x148
	// Line 1637, Address: 0x1984cc, Func Offset: 0x14c
	// Line 1639, Address: 0x1984d0, Func Offset: 0x150
	// Line 1642, Address: 0x1984d8, Func Offset: 0x158
	// Line 1644, Address: 0x1984e8, Func Offset: 0x168
	// Line 1643, Address: 0x1984ec, Func Offset: 0x16c
	// Line 1644, Address: 0x1984f0, Func Offset: 0x170
	// Line 1646, Address: 0x1984f4, Func Offset: 0x174
	// Line 1649, Address: 0x1984fc, Func Offset: 0x17c
	// Line 1653, Address: 0x198508, Func Offset: 0x188
	// Line 1654, Address: 0x198530, Func Offset: 0x1b0
	// Line 1657, Address: 0x198538, Func Offset: 0x1b8
	// Line 1654, Address: 0x198540, Func Offset: 0x1c0
	// Line 1655, Address: 0x198544, Func Offset: 0x1c4
	// Line 1657, Address: 0x198550, Func Offset: 0x1d0
	// Line 1658, Address: 0x198560, Func Offset: 0x1e0
	// Line 1659, Address: 0x19856c, Func Offset: 0x1ec
	// Line 1661, Address: 0x198574, Func Offset: 0x1f4
	// Line 1662, Address: 0x198580, Func Offset: 0x200
	// Line 1661, Address: 0x198584, Func Offset: 0x204
	// Line 1662, Address: 0x198588, Func Offset: 0x208
	// Line 1664, Address: 0x198598, Func Offset: 0x218
	// Line 1666, Address: 0x1985ac, Func Offset: 0x22c
	// Line 1667, Address: 0x1985c4, Func Offset: 0x244
	// Line 1677, Address: 0x1985d0, Func Offset: 0x250
	// Line 1678, Address: 0x1985e0, Func Offset: 0x260
	// Line 1679, Address: 0x1985e8, Func Offset: 0x268
	// Line 1680, Address: 0x1985ec, Func Offset: 0x26c
	// Line 1695, Address: 0x1985f0, Func Offset: 0x270
	// Func End, Address: 0x198600, Func Offset: 0x280
}

// 100% matching!
void bhEne03_MV04(BH_PWORK* epw)
{
	int wang;
	
    switch (epw->mode3)                         
    {
    case 0:
		wang = bhEne03_DirTarget(epw, (NJS_POINT3*)&plp->px, 32768) < 0;

        epw->mtn_no = wang + 6;
        epw->frm_no = 0;

        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;

        epw->ct0 = rand() % 31;

        epw->mode3++;
    case 1:
        epw->ayp = bhEne03_DirTarget(epw, (NJS_POINT3*)&plp->px, 819);

        njRotateY((NJS_MATRIX*)epw->exp0, epw->ayp);

        if ((epw->ct0-- == 0) || (abs(epw->ayp) < 273))
        {
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;
        }

        break;
    }
}

// 
// Start address: 0x198700
void bhEne03_MV05(BH_PWORK* epw)
{
	// Line 1740, Address: 0x198700, Func Offset: 0
	// Line 1743, Address: 0x198710, Func Offset: 0x10
	// Line 1746, Address: 0x198730, Func Offset: 0x30
	// Line 1747, Address: 0x19873c, Func Offset: 0x3c
	// Line 1748, Address: 0x198740, Func Offset: 0x40
	// Line 1749, Address: 0x198748, Func Offset: 0x48
	// Line 1752, Address: 0x198750, Func Offset: 0x50
	// Line 1751, Address: 0x198754, Func Offset: 0x54
	// Line 1752, Address: 0x198758, Func Offset: 0x58
	// Line 1753, Address: 0x19875c, Func Offset: 0x5c
	// Line 1756, Address: 0x198764, Func Offset: 0x64
	// Line 1757, Address: 0x19876c, Func Offset: 0x6c
	// Line 1760, Address: 0x198770, Func Offset: 0x70
	// Line 1756, Address: 0x198774, Func Offset: 0x74
	// Line 1757, Address: 0x19877c, Func Offset: 0x7c
	// Line 1760, Address: 0x198788, Func Offset: 0x88
	// Line 1763, Address: 0x198794, Func Offset: 0x94
	// Line 1765, Address: 0x1987a0, Func Offset: 0xa0
	// Line 1766, Address: 0x1987c0, Func Offset: 0xc0
	// Line 1768, Address: 0x1987cc, Func Offset: 0xcc
	// Line 1770, Address: 0x1987dc, Func Offset: 0xdc
	// Line 1771, Address: 0x1987f0, Func Offset: 0xf0
	// Line 1773, Address: 0x1987fc, Func Offset: 0xfc
	// Line 1775, Address: 0x19882c, Func Offset: 0x12c
	// Line 1783, Address: 0x19883c, Func Offset: 0x13c
	// Line 1784, Address: 0x198870, Func Offset: 0x170
	// Line 1785, Address: 0x198878, Func Offset: 0x178
	// Line 1787, Address: 0x19887c, Func Offset: 0x17c
	// Line 1789, Address: 0x198884, Func Offset: 0x184
	// Line 1790, Address: 0x198894, Func Offset: 0x194
	// Line 1791, Address: 0x198898, Func Offset: 0x198
	// Line 1792, Address: 0x1988a0, Func Offset: 0x1a0
	// Line 1794, Address: 0x1988ac, Func Offset: 0x1ac
	// Line 1796, Address: 0x1988b4, Func Offset: 0x1b4
	// Line 1797, Address: 0x1988c4, Func Offset: 0x1c4
	// Line 1799, Address: 0x1988cc, Func Offset: 0x1cc
	// Line 1800, Address: 0x1988d4, Func Offset: 0x1d4
	// Line 1802, Address: 0x1988dc, Func Offset: 0x1dc
	// Line 1803, Address: 0x1988e4, Func Offset: 0x1e4
	// Line 1805, Address: 0x1988ec, Func Offset: 0x1ec
	// Line 1810, Address: 0x198900, Func Offset: 0x200
	// Line 1811, Address: 0x198904, Func Offset: 0x204
	// Line 1810, Address: 0x198908, Func Offset: 0x208
	// Line 1811, Address: 0x19890c, Func Offset: 0x20c
	// Line 1813, Address: 0x198914, Func Offset: 0x214
	// Line 1814, Address: 0x198920, Func Offset: 0x220
	// Line 1816, Address: 0x198928, Func Offset: 0x228
	// Line 1813, Address: 0x19892c, Func Offset: 0x22c
	// Line 1814, Address: 0x198934, Func Offset: 0x234
	// Line 1823, Address: 0x198938, Func Offset: 0x238
	// Line 1822, Address: 0x19893c, Func Offset: 0x23c
	// Line 1823, Address: 0x198940, Func Offset: 0x240
	// Line 1824, Address: 0x198944, Func Offset: 0x244
	// Line 1814, Address: 0x198948, Func Offset: 0x248
	// Line 1816, Address: 0x198950, Func Offset: 0x250
	// Line 1817, Address: 0x198954, Func Offset: 0x254
	// Line 1818, Address: 0x198958, Func Offset: 0x258
	// Line 1821, Address: 0x19895c, Func Offset: 0x25c
	// Line 1822, Address: 0x198960, Func Offset: 0x260
	// Line 1824, Address: 0x198964, Func Offset: 0x264
	// Line 1827, Address: 0x19896c, Func Offset: 0x26c
	// Line 1829, Address: 0x198970, Func Offset: 0x270
	// Line 1828, Address: 0x198974, Func Offset: 0x274
	// Line 1829, Address: 0x198978, Func Offset: 0x278
	// Line 1827, Address: 0x19897c, Func Offset: 0x27c
	// Line 1828, Address: 0x198984, Func Offset: 0x284
	// Line 1829, Address: 0x198994, Func Offset: 0x294
	// Line 1832, Address: 0x1989a0, Func Offset: 0x2a0
	// Line 1835, Address: 0x1989ac, Func Offset: 0x2ac
	// Line 1836, Address: 0x1989bc, Func Offset: 0x2bc
	// Line 1837, Address: 0x1989c8, Func Offset: 0x2c8
	// Line 1838, Address: 0x1989d0, Func Offset: 0x2d0
	// Line 1842, Address: 0x1989dc, Func Offset: 0x2dc
	// Line 1846, Address: 0x1989e8, Func Offset: 0x2e8
	// Func End, Address: 0x1989f8, Func Offset: 0x2f8
}

// 
// Start address: 0x198a00
void bhEne03_MV06(BH_PWORK* epw)
{
	float out;
	NJS_VECTOR ov;
	// Line 1856, Address: 0x198a00, Func Offset: 0
	// Line 1857, Address: 0x198a10, Func Offset: 0x10
	// Line 1859, Address: 0x198a30, Func Offset: 0x30
	// Line 1860, Address: 0x198a34, Func Offset: 0x34
	// Line 1859, Address: 0x198a38, Func Offset: 0x38
	// Line 1860, Address: 0x198a44, Func Offset: 0x44
	// Line 1862, Address: 0x198a50, Func Offset: 0x50
	// Line 1864, Address: 0x198a5c, Func Offset: 0x5c
	// Line 1866, Address: 0x198a60, Func Offset: 0x60
	// Line 1865, Address: 0x198a64, Func Offset: 0x64
	// Line 1866, Address: 0x198a68, Func Offset: 0x68
	// Line 1867, Address: 0x198a6c, Func Offset: 0x6c
	// Line 1870, Address: 0x198a74, Func Offset: 0x74
	// Line 1871, Address: 0x198a7c, Func Offset: 0x7c
	// Line 1874, Address: 0x198a88, Func Offset: 0x88
	// Line 1879, Address: 0x198a94, Func Offset: 0x94
	// Line 1880, Address: 0x198aa8, Func Offset: 0xa8
	// Line 1879, Address: 0x198ab0, Func Offset: 0xb0
	// Line 1880, Address: 0x198ab4, Func Offset: 0xb4
	// Line 1881, Address: 0x198ad4, Func Offset: 0xd4
	// Line 1882, Address: 0x198b04, Func Offset: 0x104
	// Line 1883, Address: 0x198b0c, Func Offset: 0x10c
	// Line 1885, Address: 0x198b48, Func Offset: 0x148
	// Line 1888, Address: 0x198b54, Func Offset: 0x154
	// Line 1889, Address: 0x198b78, Func Offset: 0x178
	// Line 1890, Address: 0x198b9c, Func Offset: 0x19c
	// Line 1892, Address: 0x198bc0, Func Offset: 0x1c0
	// Line 1893, Address: 0x198bc8, Func Offset: 0x1c8
	// Line 1895, Address: 0x198bd0, Func Offset: 0x1d0
	// Line 1894, Address: 0x198bd4, Func Offset: 0x1d4
	// Line 1895, Address: 0x198bd8, Func Offset: 0x1d8
	// Line 1896, Address: 0x198bdc, Func Offset: 0x1dc
	// Line 1899, Address: 0x198be0, Func Offset: 0x1e0
	// Line 1901, Address: 0x198c00, Func Offset: 0x200
	// Line 1906, Address: 0x198c08, Func Offset: 0x208
	// Func End, Address: 0x198c1c, Func Offset: 0x21c
}

// 
// Start address: 0x198c20
void bhEne03_MV07(BH_PWORK* epw)
{
	// Line 1916, Address: 0x198c20, Func Offset: 0
	// Line 1919, Address: 0x198c30, Func Offset: 0x10
	// Line 1922, Address: 0x198c50, Func Offset: 0x30
	// Line 1923, Address: 0x198c5c, Func Offset: 0x3c
	// Line 1924, Address: 0x198c60, Func Offset: 0x40
	// Line 1925, Address: 0x198c68, Func Offset: 0x48
	// Line 1928, Address: 0x198c70, Func Offset: 0x50
	// Line 1927, Address: 0x198c74, Func Offset: 0x54
	// Line 1928, Address: 0x198c78, Func Offset: 0x58
	// Line 1929, Address: 0x198c7c, Func Offset: 0x5c
	// Line 1932, Address: 0x198c84, Func Offset: 0x64
	// Line 1933, Address: 0x198c8c, Func Offset: 0x6c
	// Line 1934, Address: 0x198c90, Func Offset: 0x70
	// Line 1932, Address: 0x198c94, Func Offset: 0x74
	// Line 1933, Address: 0x198c9c, Func Offset: 0x7c
	// Line 1934, Address: 0x198ca8, Func Offset: 0x88
	// Line 1937, Address: 0x198cb4, Func Offset: 0x94
	// Line 1939, Address: 0x198cc0, Func Offset: 0xa0
	// Line 1940, Address: 0x198ce0, Func Offset: 0xc0
	// Line 1942, Address: 0x198cec, Func Offset: 0xcc
	// Line 1944, Address: 0x198cfc, Func Offset: 0xdc
	// Line 1945, Address: 0x198d10, Func Offset: 0xf0
	// Line 1948, Address: 0x198d1c, Func Offset: 0xfc
	// Line 1950, Address: 0x198d4c, Func Offset: 0x12c
	// Line 1958, Address: 0x198d5c, Func Offset: 0x13c
	// Line 1959, Address: 0x198d90, Func Offset: 0x170
	// Line 1960, Address: 0x198d98, Func Offset: 0x178
	// Line 1962, Address: 0x198d9c, Func Offset: 0x17c
	// Line 1964, Address: 0x198da4, Func Offset: 0x184
	// Line 1965, Address: 0x198db4, Func Offset: 0x194
	// Line 1966, Address: 0x198db8, Func Offset: 0x198
	// Line 1967, Address: 0x198dc0, Func Offset: 0x1a0
	// Line 1969, Address: 0x198dcc, Func Offset: 0x1ac
	// Line 1971, Address: 0x198dd4, Func Offset: 0x1b4
	// Line 1972, Address: 0x198de4, Func Offset: 0x1c4
	// Line 1974, Address: 0x198dec, Func Offset: 0x1cc
	// Line 1975, Address: 0x198df4, Func Offset: 0x1d4
	// Line 1977, Address: 0x198dfc, Func Offset: 0x1dc
	// Line 1978, Address: 0x198e04, Func Offset: 0x1e4
	// Line 1980, Address: 0x198e0c, Func Offset: 0x1ec
	// Line 1985, Address: 0x198e20, Func Offset: 0x200
	// Line 1991, Address: 0x198e24, Func Offset: 0x204
	// Line 1985, Address: 0x198e28, Func Offset: 0x208
	// Line 1986, Address: 0x198e2c, Func Offset: 0x20c
	// Line 1987, Address: 0x198e34, Func Offset: 0x214
	// Line 1990, Address: 0x198e3c, Func Offset: 0x21c
	// Line 1991, Address: 0x198e44, Func Offset: 0x224
	// Line 1993, Address: 0x198e4c, Func Offset: 0x22c
	// Line 1994, Address: 0x198e58, Func Offset: 0x238
	// Line 1996, Address: 0x198e60, Func Offset: 0x240
	// Line 1993, Address: 0x198e64, Func Offset: 0x244
	// Line 1994, Address: 0x198e6c, Func Offset: 0x24c
	// Line 2003, Address: 0x198e70, Func Offset: 0x250
	// Line 2002, Address: 0x198e74, Func Offset: 0x254
	// Line 2003, Address: 0x198e78, Func Offset: 0x258
	// Line 2004, Address: 0x198e7c, Func Offset: 0x25c
	// Line 1994, Address: 0x198e80, Func Offset: 0x260
	// Line 1996, Address: 0x198e88, Func Offset: 0x268
	// Line 1997, Address: 0x198e8c, Func Offset: 0x26c
	// Line 1998, Address: 0x198e90, Func Offset: 0x270
	// Line 2001, Address: 0x198e94, Func Offset: 0x274
	// Line 2002, Address: 0x198e98, Func Offset: 0x278
	// Line 2004, Address: 0x198e9c, Func Offset: 0x27c
	// Line 2007, Address: 0x198ea4, Func Offset: 0x284
	// Line 2009, Address: 0x198ea8, Func Offset: 0x288
	// Line 2008, Address: 0x198eac, Func Offset: 0x28c
	// Line 2009, Address: 0x198eb0, Func Offset: 0x290
	// Line 2007, Address: 0x198eb4, Func Offset: 0x294
	// Line 2008, Address: 0x198ebc, Func Offset: 0x29c
	// Line 2009, Address: 0x198ecc, Func Offset: 0x2ac
	// Line 2012, Address: 0x198ed8, Func Offset: 0x2b8
	// Line 2015, Address: 0x198ee4, Func Offset: 0x2c4
	// Line 2016, Address: 0x198ef4, Func Offset: 0x2d4
	// Line 2017, Address: 0x198f00, Func Offset: 0x2e0
	// Line 2018, Address: 0x198f08, Func Offset: 0x2e8
	// Line 2022, Address: 0x198f14, Func Offset: 0x2f4
	// Line 2026, Address: 0x198f20, Func Offset: 0x300
	// Func End, Address: 0x198f30, Func Offset: 0x310
}

// 
// Start address: 0x198f30
void bhEne03_MV08(BH_PWORK* epw)
{
	float out;
	NJS_VECTOR ov;
	NJS_VECTOR vd;
	// Line 2036, Address: 0x198f30, Func Offset: 0
	// Line 2037, Address: 0x198f40, Func Offset: 0x10
	// Line 2039, Address: 0x198f60, Func Offset: 0x30
	// Line 2040, Address: 0x198f64, Func Offset: 0x34
	// Line 2039, Address: 0x198f68, Func Offset: 0x38
	// Line 2040, Address: 0x198f74, Func Offset: 0x44
	// Line 2042, Address: 0x198f80, Func Offset: 0x50
	// Line 2044, Address: 0x198f8c, Func Offset: 0x5c
	// Line 2046, Address: 0x198f90, Func Offset: 0x60
	// Line 2045, Address: 0x198f94, Func Offset: 0x64
	// Line 2046, Address: 0x198f98, Func Offset: 0x68
	// Line 2047, Address: 0x198f9c, Func Offset: 0x6c
	// Line 2051, Address: 0x198fa4, Func Offset: 0x74
	// Line 2052, Address: 0x198fac, Func Offset: 0x7c
	// Line 2054, Address: 0x198fb8, Func Offset: 0x88
	// Line 2059, Address: 0x198fc4, Func Offset: 0x94
	// Line 2062, Address: 0x198fc8, Func Offset: 0x98
	// Line 2059, Address: 0x198fd0, Func Offset: 0xa0
	// Line 2060, Address: 0x198fdc, Func Offset: 0xac
	// Line 2061, Address: 0x198fec, Func Offset: 0xbc
	// Line 2062, Address: 0x198ffc, Func Offset: 0xcc
	// Line 2063, Address: 0x199008, Func Offset: 0xd8
	// Line 2062, Address: 0x199010, Func Offset: 0xe0
	// Line 2063, Address: 0x199014, Func Offset: 0xe4
	// Line 2064, Address: 0x199034, Func Offset: 0x104
	// Line 2065, Address: 0x199064, Func Offset: 0x134
	// Line 2066, Address: 0x19906c, Func Offset: 0x13c
	// Line 2068, Address: 0x1990a8, Func Offset: 0x178
	// Line 2071, Address: 0x1990b4, Func Offset: 0x184
	// Line 2072, Address: 0x1990d8, Func Offset: 0x1a8
	// Line 2073, Address: 0x1990fc, Func Offset: 0x1cc
	// Line 2075, Address: 0x199120, Func Offset: 0x1f0
	// Line 2076, Address: 0x199128, Func Offset: 0x1f8
	// Line 2078, Address: 0x199130, Func Offset: 0x200
	// Line 2077, Address: 0x199134, Func Offset: 0x204
	// Line 2078, Address: 0x199138, Func Offset: 0x208
	// Line 2079, Address: 0x19913c, Func Offset: 0x20c
	// Line 2083, Address: 0x199140, Func Offset: 0x210
	// Func End, Address: 0x199154, Func Offset: 0x224
}

// 
// Start address: 0x199160
void bhEne03_MV09(BH_PWORK* epw)
{
	// Line 2093, Address: 0x199160, Func Offset: 0
	// Line 2094, Address: 0x199168, Func Offset: 0x8
	// Line 2096, Address: 0x199188, Func Offset: 0x28
	// Line 2097, Address: 0x199194, Func Offset: 0x34
	// Line 2098, Address: 0x199198, Func Offset: 0x38
	// Line 2099, Address: 0x1991a0, Func Offset: 0x40
	// Line 2102, Address: 0x1991a8, Func Offset: 0x48
	// Line 2101, Address: 0x1991ac, Func Offset: 0x4c
	// Line 2102, Address: 0x1991b0, Func Offset: 0x50
	// Line 2103, Address: 0x1991b4, Func Offset: 0x54
	// Line 2105, Address: 0x1991bc, Func Offset: 0x5c
	// Line 2106, Address: 0x1991e0, Func Offset: 0x80
	// Line 2108, Address: 0x1991ec, Func Offset: 0x8c
	// Line 2109, Address: 0x1991fc, Func Offset: 0x9c
	// Line 2110, Address: 0x199208, Func Offset: 0xa8
	// Line 2111, Address: 0x199210, Func Offset: 0xb0
	// Line 2112, Address: 0x199214, Func Offset: 0xb4
	// Line 2114, Address: 0x19921c, Func Offset: 0xbc
	// Line 2115, Address: 0x199224, Func Offset: 0xc4
	// Line 2116, Address: 0x19922c, Func Offset: 0xcc
	// Line 2117, Address: 0x199230, Func Offset: 0xd0
	// Line 2118, Address: 0x199234, Func Offset: 0xd4
	// Line 2123, Address: 0x199238, Func Offset: 0xd8
	// Line 2124, Address: 0x199244, Func Offset: 0xe4
	// Line 2125, Address: 0x19926c, Func Offset: 0x10c
	// Line 2127, Address: 0x199274, Func Offset: 0x114
	// Line 2128, Address: 0x19927c, Func Offset: 0x11c
	// Line 2131, Address: 0x1992ec, Func Offset: 0x18c
	// Line 2137, Address: 0x1992f8, Func Offset: 0x198
	// Func End, Address: 0x199304, Func Offset: 0x1a4
}

// 100% matching!
void bhEne03_MV10(BH_PWORK* epw)
{
    switch (epw->mode3)                             
    {
    case 0:
        epw->mtn_no = 12;
        epw->frm_no = 0;

        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;

        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }

        if ((epw->frm_no >= 3407872) && (epw->frm_no <= 3604480))
        {
            bhEne03_Acid(epw, 1);
        }

        break;
    }
}

// 
// Start address: 0x1993f0
void bhEne03_MV11(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	// Line 2182, Address: 0x1993f0, Func Offset: 0
	// Line 2183, Address: 0x199400, Func Offset: 0x10
	// Line 2186, Address: 0x199438, Func Offset: 0x48
	// Line 2188, Address: 0x199440, Func Offset: 0x50
	// Line 2187, Address: 0x199444, Func Offset: 0x54
	// Line 2188, Address: 0x199448, Func Offset: 0x58
	// Line 2189, Address: 0x19944c, Func Offset: 0x5c
	// Line 2190, Address: 0x199454, Func Offset: 0x64
	// Line 2194, Address: 0x19945c, Func Offset: 0x6c
	// Line 2197, Address: 0x199460, Func Offset: 0x70
	// Line 2201, Address: 0x199464, Func Offset: 0x74
	// Line 2190, Address: 0x199468, Func Offset: 0x78
	// Line 2193, Address: 0x199484, Func Offset: 0x94
	// Line 2194, Address: 0x19948c, Func Offset: 0x9c
	// Line 2195, Address: 0x199494, Func Offset: 0xa4
	// Line 2197, Address: 0x19949c, Func Offset: 0xac
	// Line 2198, Address: 0x1994a8, Func Offset: 0xb8
	// Line 2201, Address: 0x1994b8, Func Offset: 0xc8
	// Line 2203, Address: 0x1994c4, Func Offset: 0xd4
	// Line 2204, Address: 0x1994cc, Func Offset: 0xdc
	// Line 2206, Address: 0x1994d8, Func Offset: 0xe8
	// Line 2210, Address: 0x1994e8, Func Offset: 0xf8
	// Line 2211, Address: 0x1994fc, Func Offset: 0x10c
	// Line 2216, Address: 0x199500, Func Offset: 0x110
	// Line 2211, Address: 0x199504, Func Offset: 0x114
	// Line 2212, Address: 0x199508, Func Offset: 0x118
	// Line 2213, Address: 0x199510, Func Offset: 0x120
	// Line 2216, Address: 0x199518, Func Offset: 0x128
	// Line 2217, Address: 0x19951c, Func Offset: 0x12c
	// Line 2218, Address: 0x199520, Func Offset: 0x130
	// Line 2219, Address: 0x199524, Func Offset: 0x134
	// Line 2221, Address: 0x199530, Func Offset: 0x140
	// Line 2222, Address: 0x199538, Func Offset: 0x148
	// Line 2223, Address: 0x199544, Func Offset: 0x154
	// Line 2226, Address: 0x19954c, Func Offset: 0x15c
	// Line 2228, Address: 0x199554, Func Offset: 0x164
	// Line 2231, Address: 0x19955c, Func Offset: 0x16c
	// Line 2232, Address: 0x19956c, Func Offset: 0x17c
	// Line 2234, Address: 0x199578, Func Offset: 0x188
	// Line 2236, Address: 0x19957c, Func Offset: 0x18c
	// Line 2232, Address: 0x199580, Func Offset: 0x190
	// Line 2234, Address: 0x199588, Func Offset: 0x198
	// Line 2235, Address: 0x19958c, Func Offset: 0x19c
	// Line 2236, Address: 0x199590, Func Offset: 0x1a0
	// Line 2237, Address: 0x199594, Func Offset: 0x1a4
	// Line 2238, Address: 0x19959c, Func Offset: 0x1ac
	// Line 2242, Address: 0x1995a0, Func Offset: 0x1b0
	// Line 2238, Address: 0x1995a4, Func Offset: 0x1b4
	// Line 2239, Address: 0x1995ac, Func Offset: 0x1bc
	// Line 2242, Address: 0x1995d0, Func Offset: 0x1e0
	// Line 2243, Address: 0x1995e4, Func Offset: 0x1f4
	// Line 2244, Address: 0x1995e8, Func Offset: 0x1f8
	// Line 2252, Address: 0x1995f0, Func Offset: 0x200
	// Line 2254, Address: 0x199624, Func Offset: 0x234
	// Line 2256, Address: 0x19962c, Func Offset: 0x23c
	// Line 2257, Address: 0x199634, Func Offset: 0x244
	// Line 2256, Address: 0x199644, Func Offset: 0x254
	// Line 2257, Address: 0x19964c, Func Offset: 0x25c
	// Line 2259, Address: 0x199658, Func Offset: 0x268
	// Line 2261, Address: 0x199660, Func Offset: 0x270
	// Line 2262, Address: 0x199670, Func Offset: 0x280
	// Line 2267, Address: 0x199678, Func Offset: 0x288
	// Line 2262, Address: 0x19967c, Func Offset: 0x28c
	// Line 2264, Address: 0x199688, Func Offset: 0x298
	// Line 2265, Address: 0x19968c, Func Offset: 0x29c
	// Line 2267, Address: 0x199690, Func Offset: 0x2a0
	// Line 2268, Address: 0x199694, Func Offset: 0x2a4
	// Line 2269, Address: 0x199698, Func Offset: 0x2a8
	// Line 2271, Address: 0x19969c, Func Offset: 0x2ac
	// Line 2274, Address: 0x1996a8, Func Offset: 0x2b8
	// Func End, Address: 0x1996b8, Func Offset: 0x2c8
}

// 100% matching!
void bhEne03_MV12()
{

}

// 100% matching!
void bhEne03_MV13()
{

}

// 
// Start address: 0x1996e0
void bhEne03_MV14(BH_PWORK* epw)
{
	NJS_VECTOR v = { 0.0f, 3.0f, -1.3f };
	// not really sure what is going on here, according to DWARF there is just one instance of the v variable, but...
	{
	NJS_VECTOR v /* not from DWARF */ = { 0.0f, 0.8f, 0.0f };
	}
	// Line 2330, Address: 0x1996e0, Func Offset: 0
	// Line 2332, Address: 0x1996e4, Func Offset: 0x4
	// Line 2330, Address: 0x1996e8, Func Offset: 0x8
	// Line 2332, Address: 0x1996f0, Func Offset: 0x10
	// Line 2334, Address: 0x199708, Func Offset: 0x28
	// Line 2337, Address: 0x199734, Func Offset: 0x54
	// Line 2339, Address: 0x19973c, Func Offset: 0x5c
	// Line 2338, Address: 0x199740, Func Offset: 0x60
	// Line 2339, Address: 0x199744, Func Offset: 0x64
	// Line 2340, Address: 0x199748, Func Offset: 0x68
	// Line 2341, Address: 0x199750, Func Offset: 0x70
	// Line 2342, Address: 0x199774, Func Offset: 0x94
	// Line 2344, Address: 0x199780, Func Offset: 0xa0
	// Line 2347, Address: 0x199784, Func Offset: 0xa4
	// Line 2344, Address: 0x199788, Func Offset: 0xa8
	// Line 2347, Address: 0x199790, Func Offset: 0xb0
	// Line 2348, Address: 0x1997a0, Func Offset: 0xc0
	// Line 2350, Address: 0x1997b0, Func Offset: 0xd0
	// Line 2351, Address: 0x1997b8, Func Offset: 0xd8
	// Line 2353, Address: 0x1997c0, Func Offset: 0xe0
	// Line 2356, Address: 0x1997c8, Func Offset: 0xe8
	// Line 2357, Address: 0x1997d8, Func Offset: 0xf8
	// Line 2358, Address: 0x1997dc, Func Offset: 0xfc
	// Line 2362, Address: 0x1997e8, Func Offset: 0x108
	// Line 2363, Address: 0x199804, Func Offset: 0x124
	// Line 2365, Address: 0x19980c, Func Offset: 0x12c
	// Line 2364, Address: 0x199810, Func Offset: 0x130
	// Line 2365, Address: 0x199814, Func Offset: 0x134
	// Line 2366, Address: 0x199818, Func Offset: 0x138
	// Line 2367, Address: 0x199820, Func Offset: 0x140
	// Line 2368, Address: 0x199824, Func Offset: 0x144
	// Line 2372, Address: 0x199830, Func Offset: 0x150
	// Line 2373, Address: 0x199840, Func Offset: 0x160
	// Line 2374, Address: 0x199844, Func Offset: 0x164
	// Line 2376, Address: 0x19984c, Func Offset: 0x16c
	// Line 2378, Address: 0x199854, Func Offset: 0x174
	// Line 2377, Address: 0x199858, Func Offset: 0x178
	// Line 2378, Address: 0x19985c, Func Offset: 0x17c
	// Line 2379, Address: 0x199860, Func Offset: 0x180
	// Line 2380, Address: 0x199868, Func Offset: 0x188
	// Line 2383, Address: 0x199870, Func Offset: 0x190
	// Line 2384, Address: 0x199888, Func Offset: 0x1a8
	// Line 2385, Address: 0x19988c, Func Offset: 0x1ac
	// Line 2393, Address: 0x199894, Func Offset: 0x1b4
	// Line 2396, Address: 0x1998cc, Func Offset: 0x1ec
	// Line 2397, Address: 0x1998d4, Func Offset: 0x1f4
	// Line 2396, Address: 0x1998d8, Func Offset: 0x1f8
	// Line 2398, Address: 0x1998f4, Func Offset: 0x214
	// Line 2400, Address: 0x1998fc, Func Offset: 0x21c
	// Line 2403, Address: 0x199904, Func Offset: 0x224
	// Line 2400, Address: 0x199914, Func Offset: 0x234
	// Line 2401, Address: 0x19991c, Func Offset: 0x23c
	// Line 2402, Address: 0x199930, Func Offset: 0x250
	// Line 2403, Address: 0x199944, Func Offset: 0x264
	// Line 2405, Address: 0x199950, Func Offset: 0x270
	// Line 2408, Address: 0x199958, Func Offset: 0x278
	// Line 2409, Address: 0x199968, Func Offset: 0x288
	// Line 2410, Address: 0x199970, Func Offset: 0x290
	// Line 2411, Address: 0x199978, Func Offset: 0x298
	// Line 2414, Address: 0x19997c, Func Offset: 0x29c
	// Func End, Address: 0x19998c, Func Offset: 0x2ac
}

// 
// Start address: 0x199990
void bhEne03_MV15(BH_PWORK* epw)
{
	float out;
	NJS_VECTOR ov;
	NJS_VECTOR vwork;
	// Line 2424, Address: 0x199990, Func Offset: 0
	// Line 2425, Address: 0x19999c, Func Offset: 0xc
	// Line 2424, Address: 0x1999a4, Func Offset: 0x14
	// Line 2425, Address: 0x1999a8, Func Offset: 0x18
	// Line 2427, Address: 0x1999c0, Func Offset: 0x30
	// Line 2430, Address: 0x199a04, Func Offset: 0x74
	// Line 2432, Address: 0x199a0c, Func Offset: 0x7c
	// Line 2431, Address: 0x199a10, Func Offset: 0x80
	// Line 2432, Address: 0x199a14, Func Offset: 0x84
	// Line 2433, Address: 0x199a18, Func Offset: 0x88
	// Line 2434, Address: 0x199a20, Func Offset: 0x90
	// Line 2435, Address: 0x199a44, Func Offset: 0xb4
	// Line 2438, Address: 0x199a50, Func Offset: 0xc0
	// Line 2440, Address: 0x199a64, Func Offset: 0xd4
	// Line 2441, Address: 0x199a74, Func Offset: 0xe4
	// Line 2445, Address: 0x199a78, Func Offset: 0xe8
	// Line 2441, Address: 0x199a7c, Func Offset: 0xec
	// Line 2444, Address: 0x199a80, Func Offset: 0xf0
	// Line 2445, Address: 0x199a88, Func Offset: 0xf8
	// Line 2446, Address: 0x199a90, Func Offset: 0x100
	// Line 2448, Address: 0x199a98, Func Offset: 0x108
	// Line 2450, Address: 0x199aa0, Func Offset: 0x110
	// Line 2453, Address: 0x199aa8, Func Offset: 0x118
	// Line 2454, Address: 0x199ab8, Func Offset: 0x128
	// Line 2456, Address: 0x199ac0, Func Offset: 0x130
	// Line 2455, Address: 0x199ac4, Func Offset: 0x134
	// Line 2456, Address: 0x199ac8, Func Offset: 0x138
	// Line 2457, Address: 0x199acc, Func Offset: 0x13c
	// Line 2458, Address: 0x199ad4, Func Offset: 0x144
	// Line 2467, Address: 0x199ae0, Func Offset: 0x150
	// Line 2468, Address: 0x199af8, Func Offset: 0x168
	// Line 2469, Address: 0x199b10, Func Offset: 0x180
	// Line 2472, Address: 0x199b18, Func Offset: 0x188
	// Line 2473, Address: 0x199b20, Func Offset: 0x190
	// Line 2474, Address: 0x199b4c, Func Offset: 0x1bc
	// Line 2475, Address: 0x199b58, Func Offset: 0x1c8
	// Line 2480, Address: 0x199b60, Func Offset: 0x1d0
	// Line 2481, Address: 0x199b70, Func Offset: 0x1e0
	// Line 2482, Address: 0x199b74, Func Offset: 0x1e4
	// Line 2484, Address: 0x199b7c, Func Offset: 0x1ec
	// Line 2486, Address: 0x199b84, Func Offset: 0x1f4
	// Line 2485, Address: 0x199b88, Func Offset: 0x1f8
	// Line 2486, Address: 0x199b8c, Func Offset: 0x1fc
	// Line 2487, Address: 0x199b90, Func Offset: 0x200
	// Line 2488, Address: 0x199b98, Func Offset: 0x208
	// Line 2491, Address: 0x199ba0, Func Offset: 0x210
	// Line 2492, Address: 0x199bb8, Func Offset: 0x228
	// Line 2493, Address: 0x199bbc, Func Offset: 0x22c
	// Line 2501, Address: 0x199bc4, Func Offset: 0x234
	// Line 2504, Address: 0x199bfc, Func Offset: 0x26c
	// Line 2505, Address: 0x199c04, Func Offset: 0x274
	// Line 2504, Address: 0x199c08, Func Offset: 0x278
	// Line 2506, Address: 0x199c24, Func Offset: 0x294
	// Line 2508, Address: 0x199c2c, Func Offset: 0x29c
	// Line 2511, Address: 0x199c34, Func Offset: 0x2a4
	// Line 2508, Address: 0x199c44, Func Offset: 0x2b4
	// Line 2509, Address: 0x199c4c, Func Offset: 0x2bc
	// Line 2510, Address: 0x199c60, Func Offset: 0x2d0
	// Line 2511, Address: 0x199c74, Func Offset: 0x2e4
	// Line 2513, Address: 0x199c80, Func Offset: 0x2f0
	// Line 2516, Address: 0x199c88, Func Offset: 0x2f8
	// Line 2517, Address: 0x199c98, Func Offset: 0x308
	// Line 2518, Address: 0x199ca0, Func Offset: 0x310
	// Line 2519, Address: 0x199ca8, Func Offset: 0x318
	// Line 2521, Address: 0x199cac, Func Offset: 0x31c
	// Line 2524, Address: 0x199cbc, Func Offset: 0x32c
	// Func End, Address: 0x199cd0, Func Offset: 0x340
}

// 
// Start address: 0x199cd0
void bhEne03_MV16(BH_PWORK* epw)
{
	// Line 2534, Address: 0x199cd0, Func Offset: 0
	// Line 2535, Address: 0x199cdc, Func Offset: 0xc
	// Line 2538, Address: 0x199cfc, Func Offset: 0x2c
	// Line 2540, Address: 0x199d04, Func Offset: 0x34
	// Line 2539, Address: 0x199d08, Func Offset: 0x38
	// Line 2540, Address: 0x199d0c, Func Offset: 0x3c
	// Line 2541, Address: 0x199d10, Func Offset: 0x40
	// Line 2544, Address: 0x199d18, Func Offset: 0x48
	// Line 2545, Address: 0x199d1c, Func Offset: 0x4c
	// Line 2549, Address: 0x199d20, Func Offset: 0x50
	// Line 2544, Address: 0x199d24, Func Offset: 0x54
	// Line 2545, Address: 0x199d28, Func Offset: 0x58
	// Line 2546, Address: 0x199d30, Func Offset: 0x60
	// Line 2548, Address: 0x199d38, Func Offset: 0x68
	// Line 2549, Address: 0x199d5c, Func Offset: 0x8c
	// Line 2550, Address: 0x199d60, Func Offset: 0x90
	// Line 2551, Address: 0x199d68, Func Offset: 0x98
	// Line 2553, Address: 0x199d74, Func Offset: 0xa4
	// Line 2555, Address: 0x199d84, Func Offset: 0xb4
	// Line 2556, Address: 0x199d88, Func Offset: 0xb8
	// Line 2560, Address: 0x199dec, Func Offset: 0x11c
	// Line 2561, Address: 0x199df8, Func Offset: 0x128
	// Line 2562, Address: 0x199e00, Func Offset: 0x130
	// Line 2566, Address: 0x199e0c, Func Offset: 0x13c
	// Line 2567, Address: 0x199e1c, Func Offset: 0x14c
	// Line 2568, Address: 0x199e20, Func Offset: 0x150
	// Line 2569, Address: 0x199e28, Func Offset: 0x158
	// Line 2570, Address: 0x199e30, Func Offset: 0x160
	// Line 2571, Address: 0x199e34, Func Offset: 0x164
	// Line 2573, Address: 0x199e38, Func Offset: 0x168
	// Line 2575, Address: 0x199e40, Func Offset: 0x170
	// Line 2576, Address: 0x199e4c, Func Offset: 0x17c
	// Line 2578, Address: 0x199e54, Func Offset: 0x184
	// Line 2579, Address: 0x199e5c, Func Offset: 0x18c
	// Line 2578, Address: 0x199e6c, Func Offset: 0x19c
	// Line 2579, Address: 0x199e74, Func Offset: 0x1a4
	// Line 2583, Address: 0x199e84, Func Offset: 0x1b4
	// Func End, Address: 0x199e94, Func Offset: 0x1c4
}

// 
// Start address: 0x199ea0
void bhEne03_MV17(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	// Line 2593, Address: 0x199ea0, Func Offset: 0
	// Line 2596, Address: 0x199eb0, Func Offset: 0x10
	// Line 2599, Address: 0x199ed0, Func Offset: 0x30
	// Line 2601, Address: 0x199ed8, Func Offset: 0x38
	// Line 2600, Address: 0x199edc, Func Offset: 0x3c
	// Line 2601, Address: 0x199ee0, Func Offset: 0x40
	// Line 2602, Address: 0x199ee4, Func Offset: 0x44
	// Line 2603, Address: 0x199ee8, Func Offset: 0x48
	// Line 2605, Address: 0x199f04, Func Offset: 0x64
	// Line 2603, Address: 0x199f0c, Func Offset: 0x6c
	// Line 2604, Address: 0x199f10, Func Offset: 0x70
	// Line 2606, Address: 0x199f14, Func Offset: 0x74
	// Line 2604, Address: 0x199f18, Func Offset: 0x78
	// Line 2605, Address: 0x199f20, Func Offset: 0x80
	// Line 2606, Address: 0x199f24, Func Offset: 0x84
	// Line 2607, Address: 0x199f34, Func Offset: 0x94
	// Line 2608, Address: 0x199f44, Func Offset: 0xa4
	// Line 2609, Address: 0x199f4c, Func Offset: 0xac
	// Line 2612, Address: 0x199fa0, Func Offset: 0x100
	// Line 2615, Address: 0x199fac, Func Offset: 0x10c
	// Line 2617, Address: 0x199fbc, Func Offset: 0x11c
	// Line 2616, Address: 0x199fc0, Func Offset: 0x120
	// Line 2617, Address: 0x199fc4, Func Offset: 0x124
	// Line 2619, Address: 0x199fc8, Func Offset: 0x128
	// Line 2622, Address: 0x199fd0, Func Offset: 0x130
	// Line 2624, Address: 0x199fe4, Func Offset: 0x144
	// Line 2623, Address: 0x199fe8, Func Offset: 0x148
	// Line 2624, Address: 0x199fec, Func Offset: 0x14c
	// Line 2626, Address: 0x199ff0, Func Offset: 0x150
	// Line 2630, Address: 0x199ff8, Func Offset: 0x158
	// Line 2631, Address: 0x19a020, Func Offset: 0x180
	// Line 2632, Address: 0x19a02c, Func Offset: 0x18c
	// Line 2633, Address: 0x19a034, Func Offset: 0x194
	// Line 2635, Address: 0x19a03c, Func Offset: 0x19c
	// Line 2636, Address: 0x19a04c, Func Offset: 0x1ac
	// Line 2635, Address: 0x19a050, Func Offset: 0x1b0
	// Line 2636, Address: 0x19a054, Func Offset: 0x1b4
	// Line 2640, Address: 0x19a064, Func Offset: 0x1c4
	// Line 2642, Address: 0x19a078, Func Offset: 0x1d8
	// Line 2643, Address: 0x19a08c, Func Offset: 0x1ec
	// Line 2644, Address: 0x19a0a0, Func Offset: 0x200
	// Line 2648, Address: 0x19a0ac, Func Offset: 0x20c
	// Line 2650, Address: 0x19a0bc, Func Offset: 0x21c
	// Line 2649, Address: 0x19a0c0, Func Offset: 0x220
	// Line 2650, Address: 0x19a0c4, Func Offset: 0x224
	// Line 2651, Address: 0x19a0c8, Func Offset: 0x228
	// Line 2654, Address: 0x19a0cc, Func Offset: 0x22c
	// Func End, Address: 0x19a0dc, Func Offset: 0x23c
}

// 
// Start address: 0x19a0e0
void bhEne03_MV18(BH_PWORK* epw)
{
	float out;
	NJS_VECTOR ov;
	NJS_VECTOR v;
	// Line 2664, Address: 0x19a0e0, Func Offset: 0
	// Line 2665, Address: 0x19a0f4, Func Offset: 0x14
	// Line 2668, Address: 0x19a138, Func Offset: 0x58
	// Line 2670, Address: 0x19a140, Func Offset: 0x60
	// Line 2669, Address: 0x19a144, Func Offset: 0x64
	// Line 2670, Address: 0x19a148, Func Offset: 0x68
	// Line 2671, Address: 0x19a14c, Func Offset: 0x6c
	// Line 2672, Address: 0x19a154, Func Offset: 0x74
	// Line 2673, Address: 0x19a160, Func Offset: 0x80
	// Line 2674, Address: 0x19a168, Func Offset: 0x88
	// Line 2677, Address: 0x19a170, Func Offset: 0x90
	// Line 2680, Address: 0x19a184, Func Offset: 0xa4
	// Line 2681, Address: 0x19a188, Func Offset: 0xa8
	// Line 2682, Address: 0x19a190, Func Offset: 0xb0
	// Line 2683, Address: 0x19a19c, Func Offset: 0xbc
	// Line 2687, Address: 0x19a1ac, Func Offset: 0xcc
	// Line 2689, Address: 0x19a1bc, Func Offset: 0xdc
	// Line 2690, Address: 0x19a1c4, Func Offset: 0xe4
	// Line 2692, Address: 0x19a1cc, Func Offset: 0xec
	// Line 2695, Address: 0x19a1d4, Func Offset: 0xf4
	// Line 2696, Address: 0x19a1e0, Func Offset: 0x100
	// Line 2697, Address: 0x19a1e8, Func Offset: 0x108
	// Line 2698, Address: 0x19a1f0, Func Offset: 0x110
	// Line 2699, Address: 0x19a1f8, Func Offset: 0x118
	// Line 2700, Address: 0x19a200, Func Offset: 0x120
	// Line 2702, Address: 0x19a208, Func Offset: 0x128
	// Line 2710, Address: 0x19a210, Func Offset: 0x130
	// Line 2711, Address: 0x19a228, Func Offset: 0x148
	// Line 2712, Address: 0x19a240, Func Offset: 0x160
	// Line 2715, Address: 0x19a248, Func Offset: 0x168
	// Line 2716, Address: 0x19a250, Func Offset: 0x170
	// Line 2717, Address: 0x19a27c, Func Offset: 0x19c
	// Line 2718, Address: 0x19a288, Func Offset: 0x1a8
	// Line 2723, Address: 0x19a290, Func Offset: 0x1b0
	// Line 2724, Address: 0x19a2a0, Func Offset: 0x1c0
	// Line 2727, Address: 0x19a2a4, Func Offset: 0x1c4
	// Line 2724, Address: 0x19a2a8, Func Offset: 0x1c8
	// Line 2725, Address: 0x19a2b0, Func Offset: 0x1d0
	// Line 2727, Address: 0x19a2b8, Func Offset: 0x1d8
	// Line 2729, Address: 0x19a2c0, Func Offset: 0x1e0
	// Line 2731, Address: 0x19a2c8, Func Offset: 0x1e8
	// Line 2730, Address: 0x19a2cc, Func Offset: 0x1ec
	// Line 2731, Address: 0x19a2d0, Func Offset: 0x1f0
	// Line 2732, Address: 0x19a2d4, Func Offset: 0x1f4
	// Line 2733, Address: 0x19a2dc, Func Offset: 0x1fc
	// Line 2734, Address: 0x19a2e4, Func Offset: 0x204
	// Line 2735, Address: 0x19a2ec, Func Offset: 0x20c
	// Line 2734, Address: 0x19a2f0, Func Offset: 0x210
	// Line 2736, Address: 0x19a30c, Func Offset: 0x22c
	// Line 2738, Address: 0x19a314, Func Offset: 0x234
	// Line 2741, Address: 0x19a318, Func Offset: 0x238
	// Line 2738, Address: 0x19a320, Func Offset: 0x240
	// Line 2741, Address: 0x19a324, Func Offset: 0x244
	// Line 2738, Address: 0x19a328, Func Offset: 0x248
	// Line 2739, Address: 0x19a334, Func Offset: 0x254
	// Line 2740, Address: 0x19a348, Func Offset: 0x268
	// Line 2741, Address: 0x19a35c, Func Offset: 0x27c
	// Line 2743, Address: 0x19a368, Func Offset: 0x288
	// Line 2746, Address: 0x19a370, Func Offset: 0x290
	// Line 2748, Address: 0x19a380, Func Offset: 0x2a0
	// Line 2750, Address: 0x19a384, Func Offset: 0x2a4
	// Line 2749, Address: 0x19a38c, Func Offset: 0x2ac
	// Line 2752, Address: 0x19a390, Func Offset: 0x2b0
	// Line 2748, Address: 0x19a394, Func Offset: 0x2b4
	// Line 2749, Address: 0x19a39c, Func Offset: 0x2bc
	// Line 2753, Address: 0x19a3a0, Func Offset: 0x2c0
	// Line 2757, Address: 0x19a3a4, Func Offset: 0x2c4
	// Line 2749, Address: 0x19a3a8, Func Offset: 0x2c8
	// Line 2750, Address: 0x19a3b4, Func Offset: 0x2d4
	// Line 2752, Address: 0x19a3c0, Func Offset: 0x2e0
	// Line 2753, Address: 0x19a3c4, Func Offset: 0x2e4
	// Line 2754, Address: 0x19a3c8, Func Offset: 0x2e8
	// Line 2757, Address: 0x19a3cc, Func Offset: 0x2ec
	// Line 2760, Address: 0x19a3d4, Func Offset: 0x2f4
	// Func End, Address: 0x19a3e8, Func Offset: 0x308
}

// 
// Start address: 0x19a3f0
void bhEne03_MV19(BH_PWORK* epw)
{
	NJS_POINT3 p2;
	NJS_POINT3 p1;
	float dist;
	// Line 2770, Address: 0x19a3f0, Func Offset: 0
	// Line 2771, Address: 0x19a400, Func Offset: 0x10
	// Line 2774, Address: 0x19a42c, Func Offset: 0x3c
	// Line 2775, Address: 0x19a438, Func Offset: 0x48
	// Line 2776, Address: 0x19a43c, Func Offset: 0x4c
	// Line 2777, Address: 0x19a444, Func Offset: 0x54
	// Line 2780, Address: 0x19a44c, Func Offset: 0x5c
	// Line 2779, Address: 0x19a450, Func Offset: 0x60
	// Line 2780, Address: 0x19a454, Func Offset: 0x64
	// Line 2781, Address: 0x19a458, Func Offset: 0x68
	// Line 2782, Address: 0x19a460, Func Offset: 0x70
	// Line 2785, Address: 0x19a468, Func Offset: 0x78
	// Line 2786, Address: 0x19a474, Func Offset: 0x84
	// Line 2787, Address: 0x19a47c, Func Offset: 0x8c
	// Line 2789, Address: 0x19a484, Func Offset: 0x94
	// Line 2790, Address: 0x19a490, Func Offset: 0xa0
	// Line 2791, Address: 0x19a49c, Func Offset: 0xac
	// Line 2792, Address: 0x19a4a4, Func Offset: 0xb4
	// Line 2794, Address: 0x19a4b0, Func Offset: 0xc0
	// Line 2798, Address: 0x19a4bc, Func Offset: 0xcc
	// Line 2799, Address: 0x19a4e8, Func Offset: 0xf8
	// Line 2798, Address: 0x19a4ec, Func Offset: 0xfc
	// Line 2799, Address: 0x19a4f0, Func Offset: 0x100
	// Line 2802, Address: 0x19a504, Func Offset: 0x114
	// Line 2803, Address: 0x19a518, Func Offset: 0x128
	// Line 2804, Address: 0x19a520, Func Offset: 0x130
	// Line 2803, Address: 0x19a528, Func Offset: 0x138
	// Line 2804, Address: 0x19a534, Func Offset: 0x144
	// Line 2805, Address: 0x19a540, Func Offset: 0x150
	// Line 2807, Address: 0x19a548, Func Offset: 0x158
	// Line 2808, Address: 0x19a554, Func Offset: 0x164
	// Line 2815, Address: 0x19a604, Func Offset: 0x214
	// Line 2816, Address: 0x19a60c, Func Offset: 0x21c
	// Line 2817, Address: 0x19a610, Func Offset: 0x220
	// Line 2821, Address: 0x19a614, Func Offset: 0x224
	// Line 2822, Address: 0x19a620, Func Offset: 0x230
	// Line 2824, Address: 0x19a628, Func Offset: 0x238
	// Line 2825, Address: 0x19a630, Func Offset: 0x240
	// Line 2827, Address: 0x19a638, Func Offset: 0x248
	// Line 2828, Address: 0x19a640, Func Offset: 0x250
	// Line 2835, Address: 0x19a6f0, Func Offset: 0x300
	// Line 2837, Address: 0x19a6f8, Func Offset: 0x308
	// Line 2836, Address: 0x19a6fc, Func Offset: 0x30c
	// Line 2837, Address: 0x19a700, Func Offset: 0x310
	// Line 2841, Address: 0x19a704, Func Offset: 0x314
	// Line 2842, Address: 0x19a710, Func Offset: 0x320
	// Line 2844, Address: 0x19a718, Func Offset: 0x328
	// Line 2847, Address: 0x19a720, Func Offset: 0x330
	// Line 2849, Address: 0x19a728, Func Offset: 0x338
	// Line 2853, Address: 0x19a730, Func Offset: 0x340
	// Line 2855, Address: 0x19a738, Func Offset: 0x348
	// Line 2856, Address: 0x19a744, Func Offset: 0x354
	// Line 2857, Address: 0x19a750, Func Offset: 0x360
	// Line 2858, Address: 0x19a758, Func Offset: 0x368
	// Line 2862, Address: 0x19a764, Func Offset: 0x374
	// Line 2863, Address: 0x19a78c, Func Offset: 0x39c
	// Line 2864, Address: 0x19a798, Func Offset: 0x3a8
	// Line 2866, Address: 0x19a79c, Func Offset: 0x3ac
	// Line 2865, Address: 0x19a7a0, Func Offset: 0x3b0
	// Line 2866, Address: 0x19a7a4, Func Offset: 0x3b4
	// Line 2867, Address: 0x19a7a8, Func Offset: 0x3b8
	// Line 2869, Address: 0x19a7ac, Func Offset: 0x3bc
	// Line 2867, Address: 0x19a7b0, Func Offset: 0x3c0
	// Line 2869, Address: 0x19a7b4, Func Offset: 0x3c4
	// Line 2870, Address: 0x19a7b8, Func Offset: 0x3c8
	// Line 2871, Address: 0x19a7bc, Func Offset: 0x3cc
	// Line 2873, Address: 0x19a7c0, Func Offset: 0x3d0
	// Line 2875, Address: 0x19a7c4, Func Offset: 0x3d4
	// Line 2876, Address: 0x19a7d0, Func Offset: 0x3e0
	// Line 2880, Address: 0x19a7e0, Func Offset: 0x3f0
	// Func End, Address: 0x19a7f4, Func Offset: 0x404
}

// 100% matching!
void bhEne03_Nage(BH_PWORK* epw)
{
	bhEne03_NageMode2[epw->mode2](epw);
}

#pragma divbyzerocheck on 

// 100% matching!
void bhEne03_NG00(BH_PWORK* epw) 
{
	NJS_POINT3 trg_pos[4][2] = 
	{
		{
			{ 2.1e-05f, -2.618032f, -6.719222f },
			{ 2.1e-05f,  -2.61543f, -6.687998f }
		},
		{
			{ 2.1e-05f, -2.618032f, -6.719222f },
			{ 2.1e-05f,  -2.61543f, -6.687998f }
		},
		{
			{ 2.1e-05f, -2.618032f, -6.719222f },
			{ 2.1e-05f,  -2.61543f, -6.687998f }
		},
		{
			{ 2.1e-05f, -2.618032f, -6.719222f },
			{ 2.1e-05f,  -2.61543f, -6.687998f }
		}
	};
    NJS_POINT3 pos;            

    switch (epw->mode3) 
    {                               
    case 0:
        epw->ayp = bhArcTan2(epw->px - plp->px, epw->pz - plp->pz);
        
        EPW_EXP1_I(0) |= 0x4;
        
        plp->flg   |= 0x10004;
        plp->stflg |= 0x10000;
        
        plp->mode0 = 4;
        plp->mode3 = 0;
        
        if (abs((short)(epw->ayp - plp->ay)) < 16384) 
        {
            plp->mode2 = 1;
            
            plp->ayp = epw->ayp;
        } 
        else
        {
            plp->mode2 = 0;
            
            plp->ayp = (short)(epw->ayp + 32768);
        }
        
        epw->mtn_no = 8;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->flg &= ~0x60;
        epw->flg |=  0x100000;
        epw->flg &= ~0x200000;
        
        epw->flg2 |= 0x1;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        epw->ct1 = 0;
        epw->ct2 = 6;
        
        epw->mode3++;
    case 1:
        epw->ct1 += bhEne_LeverCheck();
        
        if ((epw->ct0-- == 0) || (epw->ct1 > 30)) 
        {
            epw->mtn_no = 9;
            epw->frm_no = 0;
            
            epw->hokan_count = 0;
            
            epw->ct0 = 0;
            
            epw->mode3++;
        }
        
        break;
    case 2:
        epw->ct1 += bhEne_LeverCheck();
        
        if (epw->frm_no == 0)
        {
            if (plp->hp < 0) 
            {
                plp->mode0 = 6;
                
                if (plp->mode2 == 0) 
                {
                    plp->mode2 = 0;
                } 
                else 
                {
                    plp->mode2 = 1;
                }
                
                plp->mode3 = 0;
                
                epw->mtn_no = 25;
                epw->frm_no = 0;
                
                epw->hokan_count = 0;
                
                epw->mode3 = 4;
                return;
            }
            
            epw->ct0++;
            
            if ((epw->ct0 == 3) || (epw->ct1 > 30)) 
            {
                if (plp->mode2 == 0) 
                {
                    plp->mode2 = 4;
                }
                else 
                {
                    plp->mode2 = 5;
                }
                
                plp->mode3 = 0;
                
                epw->mtn_no = 10;
                epw->frm_no = 0;
                
                epw->hokan_count = 0;
                
                epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
                
                epw->mode3++;
                return;
            }
        }
        
        if ((epw->frm_no / 65536) == 19) 
        {
            plp->hp -= 12;
            
            if (plp->hp < 0) 
            {
                plp->stflg |= 0x40000;
            }
            
            plp->dvx = -njSin(epw->ay);
            plp->dvy = -1.0f;
            plp->dvz = -njCos(epw->ay);
            
            bhEne_SetBloodEffectBurst(plp, 4, 4, (NJS_POINT3*)&epw->mlwP->owP[35].mtx[12], 1);
            
            StartVibrationEx(1, 9);
        }
        
        break;
    case 3:
        epw->ar += (6.0f - epw->ar) / 16.0f;
        
        njUnitMatrix(NULL);
        
        njRotateY(NULL, epw->ayp);
        
        njCalcVector(NULL, &trg_pos[sys->ply_id][plp->mode2 & 0x1], &pos);
        
        epw->px = plp->px - pos.x;
        epw->pz = plp->pz - pos.z;
        
        if (epw->ct0-- == 0) 
        {
            epw->flg |= 0x20;
            
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
            
            epw->mtn_no = 0;
            epw->frm_no = 0;
            
            epw->hokan_count = 0;
            
            bhEne03_GetPartsPos(epw, spider_tree[0], &pos);
            
            epw->px = pos.x;
            epw->pz = pos.z;
            
            epw->flg  |=  0x60;
            epw->flg2 &= ~0x1;
            
            epw->ar = 6.0f;
            
            EPW_EXP1_I(8) += 30;
        }
        
        break;
    case 4:
        if (epw->frm_no == 0) 
        {
            epw->frm_no = 2031616;
            
            plp->flg |= 0x2;
        }
        
        if (((epw->frm_no / 65536) == 32) || ((epw->frm_no / 65536) == 51)) 
        {
            plp->dvx = njSin(epw->ay);
            plp->dvy = -2.0f;
            plp->dvz = njCos(epw->ay);
            
            bhEne_SetBloodEffectBurst(plp, 4, 4, (NJS_POINT3*)&epw->mlwP->owP[35].mtx[12], 1);
            
            StartVibrationEx(1, 9);
        }
        
        epw->ar += (6.0f - epw->ar) / 16.0f;
        
        njUnitMatrix(NULL);
        
        njRotateY(NULL, epw->ayp);
        
        njCalcVector(NULL, &trg_pos[sys->ply_id][plp->mode2], &pos);
        
        plp->px = epw->px + pos.x;
        plp->pz = epw->pz + pos.z;
        break;
    }

    if ((epw->mode3 == 1) || (epw->mode3 == 2))
    {
        njUnitMatrix(NULL);
        
        njRotateY(NULL, epw->ayp);
        
        njCalcVector(NULL, &trg_pos[sys->ply_id][plp->mode2 & 0x1], &pos);
        
        epw->xn = plp->px - pos.x;
        epw->zn = plp->pz - pos.z;
        
        if (epw->ct2 > 0)
        {
            epw->px += (epw->xn - epw->px) / epw->ct2;
            epw->pz += (epw->zn - epw->pz) / epw->ct2;
            
            epw->ay = bhArcTan2(-EXP0_F(8), EXP0_F(0));
            
            njRotateY((NJS_MATRIX*)epw->exp0, (short)(epw->ayp - epw->ay) / epw->ct2);
            
            epw->ct2--;
        }
        else
        {
            epw->px = epw->xn;
            epw->pz = epw->zn;
        }
    }
}

// 100% matching!
void bhEne03_NG01(BH_PWORK* epw)
{
	NJS_POINT3 trg_pos[4][2] = 
	{
		{
			{ 0.063656f, -0.090291f, -12.650927f },
			{ 0.063656f, -0.090291f, -11.614147f }
		},
		{
			{ 0.063656f, -0.090291f, -13.150927f },
			{ 0.063656f, -0.090291f, -12.114147f }
		},
		{
			{ 0.063656f, -0.090291f, -12.650927f },
			{ 0.063656f, -0.090291f, -11.614147f }
		},
		{
			{ 0.063656f, -0.090291f, -13.150927f },
			{ 0.063656f, -0.090291f, -12.114147f }
		}
	};     
    NJS_POINT3 pos;

    switch (epw->mode3) 
    {                               
    case 0:
        epw->ayp = bhArcTan2(epw->px - plp->px, epw->pz - plp->pz);
        
        EPW_EXP1_I(0) |= 0x4;
        
        plp->flg   |= 0x10004;
        plp->stflg |= 0x10000;
        
        plp->mode0 = 4;
        plp->mode3 = 0;
        
        if (abs((short)(epw->ayp - plp->ay)) < 16384) 
        {
            plp->mode2 = 3;
            
            plp->ayp = epw->ayp;
        } 
        else
        {
            plp->mode2 = 2;
            
            plp->ayp = (short)(epw->ayp + 32768);
        }
        
        epw->mtn_no = 44;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->flg &= ~0x60;
        epw->flg |=  0x100000;
        epw->flg &= ~0x200000;
        
        epw->flg2 |= 0x1;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        epw->ct1 = 0;
        epw->ct2 = 6;

        epw->stflg |= 0x8;
        
        epw->mode3++;
    case 1:
        epw->ct1 += bhEne_LeverCheck();
        
        if (epw->ct0-- == 0)
        {
            epw->stflg &= ~0x8;
            
            if (plp->hp < 0) 
            {
                plp->mode0 = 6;
                
                if (plp->mode2 == 2) 
                {
                    plp->mode2 = 2;
                } 
                else 
                {
                    plp->mode2 = 3;
                }
                
                plp->mode3 = 0;
                
                epw->mtn_no = 55;
                epw->frm_no = 0;
                
                epw->hokan_count = 0;
                
                epw->mode3 = 3;
            } 
            else 
            {
                epw->mtn_no = 46;
                epw->frm_no = 0;
                
                epw->hokan_count = 0;
                
                epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
                
                epw->mode3++;
            }
            
            return;
        }

        njUnitMatrix(NULL);
        
        njRotateY(NULL, epw->ayp);
        
        njCalcVector(NULL, &trg_pos[sys->ply_id][plp->mode2 - 2], &pos);
        
        epw->xn = plp->px - pos.x;
        epw->zn = plp->pz - pos.z;
        
        if (epw->ct2 > 0) 
        {
            epw->px += (epw->xn - epw->px) / epw->ct2;
            epw->pz += (epw->zn - epw->pz) / epw->ct2;
            
            epw->ay = bhArcTan2(-EXP0_F(8), EXP0_F(0));
            
            njRotateY((NJS_MATRIX*)epw->exp0, (short)(epw->ayp - epw->ay) / epw->ct2);
            
            epw->ct2--;
        } 
        else
        {
            epw->px = epw->xn;
            epw->pz = epw->zn;
        }
        
        if ((epw->frm_no == 720896) || (epw->frm_no == 1900544) || (epw->frm_no == 3342336))
        {
            plp->dvx = -njSin(epw->ay);
            plp->dvy = -0.5f;
            plp->dvz = -njCos(epw->ay);
            
            if (epw->ct1 > 30) 
            {
                plp->hp -= 5;
                
                bhEne_SetBloodEffectBurst(plp, 5, 4, (NJS_POINT3*)&epw->mlwP->owP[35].mtx[12], 1);
            }
            else 
            {
                plp->hp -= 12;
                
                bhEne_SetBloodEffectBurst(plp, 4, 4, (NJS_POINT3*)&epw->mlwP->owP[35].mtx[12], 1);
            }

            if (plp->hp < 0) 
            {
                plp->stflg |= 0x40000;
            }
            
            StartVibrationEx(1, 9);
        }
        
        break;
    case 2:
        epw->ar += (6.0f - epw->ar) / 16.0f;
        
        njUnitMatrix(NULL);
        
        njRotateY(NULL, epw->ayp);
        
        njCalcVector(NULL, &trg_pos[sys->ply_id][plp->mode2 - 2], &pos);
        
        epw->xn = plp->px - pos.x;
        epw->zn = plp->pz - pos.z;
        
        if (epw->ct0-- == 0) 
        {
            epw->flg |= 0x20;
            
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
            
            bhEne03_GetPartsPos(epw, spider_tree[0], &pos);
            
            epw->px = pos.x;
            epw->pz = pos.z;

            epw->mtn_no = 30;
            epw->frm_no = 0;

            epw->hokan_count = 0;
            
            epw->flg  |=  0x60;
            epw->flg2 &= ~0x1;
            
            epw->ar = 6.0f;

            epw->flg &= ~0x100000;
            
            EPW_EXP1_I(8) += 20;
        }
        
        break;
    case 3:
        if (epw->frm_no == 0) 
        {
            epw->frm_no = 11206656;
        }

        if (epw->frm_no == 3932160) 
        {
            plp->flg |= 0x2;
        }
        
        if (((epw->frm_no / 65536) == 183) || ((epw->frm_no / 65536) == 194) || ((epw->frm_no / 65536) == 210)) 
        {
            plp->dvx = njSin(epw->ay);
            plp->dvy = -2.0f;
            plp->dvz = njCos(epw->ay);
            
            bhEne_SetBloodEffectBurst(plp, 4, 4, (NJS_POINT3*)&epw->mlwP->owP[35].mtx[12], 1);
            
            StartVibrationEx(1, 9);
        }
        
        epw->ar += (6.0f - epw->ar) / 16.0f;
        
        njUnitMatrix(NULL);
        
        njRotateY(NULL, epw->ayp);
        
        njCalcVector(NULL, &trg_pos[sys->ply_id][plp->mode2 - 2], &pos);
        
        plp->px = epw->px + pos.x;
        plp->pz = epw->pz + pos.z;
        break;
    }
}

#pragma divbyzerocheck off

// 100% matching!
void bhEne03_Damage(BH_PWORK* epw)
{
    if ((epw->flg & 0x4))
    {
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
            if (epw->type == 0) 
            {
                if ((epw->comb_flg & 0x8)) 
                {
                    EXP0_I(124) -= epw->total_dam;
                } 
                else 
                {
                    if ((EXP0_C(105) == 0) && (!(plp->at_flg & 0x8))) 
                    {
                        EXP0_I(124) -= epw->total_dam;
                    }
                    
                    epw->hp -= epw->total_dam;
                }
            } 
            else
            {
                epw->hp -= epw->total_dam;
            }
            
            if ((epw->wpnr_no != 17) || ((epw->flg2 & 0x4))) 
            {
                bhEne03_HitMark(epw);
            } 
        }
    }
    
    bhEne03_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne03_DG00()
{

}

// 100% matching!
void bhEne03_DG01(BH_PWORK* epw)
{
	switch (epw->mode3)                               
    {
    case 0:
        epw->mtn_no = 20;
        epw->frm_no = 0;

        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;

        epw->mtn_add = 65536;

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;

        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;

            epw->flg &= ~0x4;
        }

        break;
    }
}

// 100% matching!
void bhEne03_DG02(BH_PWORK* epw)
{
    NJS_MKEY* mkfP;     
    NJS_POINT3 trans;    
	NJS_MKEY_A_MOD* mkaP;

    switch (epw->mode3) 
    {
    case 0:
        epw->mtn_no = 17;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 45875;
        
        epw->mtn_add = 65536;

        EXP0_F(84) = 0;
        EXP0_F(88) = -1.0f;
        EXP0_F(92) = 0;

        EXP0_C(105) = 0;
        
        bhEne03_MakeMatrix(epw);

        njRotateY((NJS_MATRIX*)epw->exp0, 32768);

        mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
        
        trans.x = *mkfP->key++;
        trans.y = *mkfP->key++;
        trans.z = *mkfP->key++;

        njCalcVector((NJS_MATRIX*)epw->exp0, &trans, &trans);

        epw->px -= trans.x;
        epw->py -= trans.y;
        epw->pz -= trans.z;

        epw->mtn_md |= 0x100;

        mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];
        
        epw->mlwP->objP->ang[0] = *mkaP->key++;
        epw->mlwP->objP->ang[1] = *mkaP->key++;
        epw->mlwP->objP->ang[2] = *mkaP->key++;

        *(ATR_WORK**)&EXP0_I(96) = NULL;
        
        epw->ar = 0.1f;
        
        epw->mode3++;
    case 1:
        if ((ATR_WORK*)EXP0_I(96) != NULL) 
        {
            epw->mtn_no = 18;
            epw->frm_no = 0;
            
            epw->hokan_count = 0;
            epw->hokan_rate  = 0;
            
            epw->mtn_md &= ~0x100;
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
            
            epw->flg2 &= ~0x1;
            
            epw->mode3++;
        } 
        else 
        {
            epw->py += EXP0_F(88);
            
            EXP0_F(88) -= 0.33f;
        }
        
        break;
    case 2:
        if (epw->ct0-- == 0) 
        {
            epw->mtn_no = 16;
            epw->frm_no = 0;
            
            epw->hokan_count = 0;
            epw->hokan_rate  = 0;
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            
            epw->mode3++;
        }
        
        break;
    case 3:
        bhEne03_AddNullTrans(epw, spm_016);
        
        if (epw->ct0-- == 0) 
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;
            
            epw->flg &= ~0x4;
        }
        
        break;
    }

    epw->ar += (6.0f - epw->ar) / 16.0f;
}

// 100% matching!
void bhEne03_DG03(BH_PWORK* epw)
{
	switch (epw->mode3)                               
    {
    case 0:
        epw->mtn_no = 19;
        epw->frm_no = 0;

        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;

        epw->mtn_add = 65536;

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;

        epw->mode3++;
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;

            epw->flg &= ~0x4;
        }

        break;
    }
}

// 100% matching!
void bhEne03_DG04(BH_PWORK* epw) 
{
    int i;        
    NJS_POINT3 pos; 
    O_WORK* owk;    

    switch (epw->mode3) 
    {
    case 0:
        epw->mtn_no = 22;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->ct1 = 0;
        
        epw->mode3++;

        owk = &epw->mlwP->owP[2];
        
        pos.x = 0;
        pos.y = 3.0f;
        pos.z = 4.0f;
        
        njCalcPoint((NJS_MATRIX*)owk->mtx, &pos, &pos);
        
        bhEne_SetBloodEffect4(&pos, &pos, 1, 9, 2);
        bhEne_SetBloodEffect4(&pos, &pos, 1, 9, 1);
        bhEne_SetBloodstain(epw, 1, 2, NULL);

        for (i = 0; i < 6; i++) 
        {
            owk = &epw->mlwP->owP[2];
            
            pos.x =         (4.0f * (-rand() / -2147483648.0f))  - 2.0f;
            pos.y = (3.0f + (4.0f * (-rand() / -2147483648.0f))) - 2.0f;
            pos.z = (4.0f + (6.0f * (-rand() / -2147483648.0f))) - 3.0f;
            
            njCalcPoint((NJS_MATRIX*)owk->mtx, &pos, (NJS_POINT3*)&epw->dpx);
            
            bhEne_SetMinceEffect2(epw, 258, 0.3f, 1);
            bhEne_SetMinceEffect2(epw, 259, 0.3f, 1);
        }

        epw->type = 1;
        
        epw->cpcl = CapColTabB;
        
        bhEne03_HideParts(epw, 2, 1);
        
        bhEne_EraseArrow(epw, 2);
    case 1:
        if (epw->ct1 < 4) 
        {
            owk = &epw->mlwP->owP[2];
            
            pos.x =         (6.0f * (-rand() / -2147483648.0f))  - 3.0f;
            pos.y = (3.0f + (4.0f * (-rand() / -2147483648.0f))) - 2.0f;
            pos.z = (4.0f + (4.0f * (-rand() / -2147483648.0f))) - 2.0f;
            
            njCalcPoint((NJS_MATRIX*)owk->mtx, &pos, &pos);
            
            bhEne_SetBloodEffect4(&pos, &pos, 1, 9, 2);
            
            epw->ct1++;
        }

        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;
            
            epw->flg &= ~0x4;
        }
        
        break;
    }
}

// 100% matching!
void bhEne03_DG05()
{

}

// 100% matching!
void bhEne03_DG06(BH_PWORK* epw)
{
    switch (epw->mode3)                               
    {
    case 0:
        epw->mtn_no = 52;
        epw->frm_no = 0;

        epw->hokan_count = 4;
        epw->hokan_rate  = 32768;

        epw->mtn_add = 65536;

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

        break;
    }
}

// 100% matching!
void bhEne03_DG07(BH_PWORK* epw) 
{
    switch (epw->mode3) 
    {                            
    case 0:                                         
        epw->mtn_no = 50;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->mtn_add = 0;
        
        EXP0_F(84) = EXP0_F(16);
        EXP0_F(88) = EXP0_F(20);
        EXP0_F(92) = EXP0_F(24);
        
        *(ATR_WORK**)&EXP0_I(96) = NULL;
        
        epw->ct0 = 8;
        
        epw->mode3++;
    case 1:                                         
        if (epw->ct0 > 0) 
        {
            epw->ct0--;
            
            njUnitMatrix(NULL);
            
            switch (EXP0_C(105)) 
            {                    
            case 5:                                 
                njRotateX(NULL, -2048);
                break;
            case 3:                                 
                njRotateX(NULL,  2048);
                break;
            case 4:                                 
                njRotateZ(NULL, -2048);
                break;
            case 2:                                 
                njRotateZ(NULL,  2048);
                break;
            case 1:                                
                njRotateX(NULL,  4096);
                break;
            }
            
            njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);
            
            njGetMatrix((NJS_MATRIX*)epw->exp0);
        }
        
        if ((ATR_WORK*)EXP0_I(96) != NULL) 
        {
            EXP0_C(105) = 0;
            
            bhEne03_MakeMatrix(epw);
            
            epw->mtn_no = 49;
            epw->frm_no = 0;
            
            epw->hokan_count = 3;
            epw->hokan_rate  = 32768;
            
            epw->mtn_add = 65536;
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            
            epw->flg2 &= ~0x1;
            
            epw->mode3++;
            break;
        }
        
        epw->px += EXP0_F(84);
        epw->py += EXP0_F(88);
        epw->pz += EXP0_F(92);
        
        EXP0_F(88) -= 0.33f;
        break;
    case 2:                                    
        if (epw->ct0-- == 0) 
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;
            
            epw->flg &= ~0x4;
        }
        
        break;
    }
}

// 100% matching!
void bhEne03_DG08(BH_PWORK* epw)
{
    switch (epw->mode3)                             
    {
    case 0:
        epw->mtn_no = 26;
        epw->frm_no = 0;

        epw->hokan_count = 8;
        epw->hokan_rate  = 32768;

        epw->mtn_add = 65536;

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;

        epw->mode3++;
    case 1:
        bhEne03_AddNullTrans(epw, spm_026);

        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 30;
            epw->frm_no = 0;

            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 3;
            epw->mode3 = 0;

            epw->flg &= ~0x4;
        }

        break;
    }
}

// 100% matching!
void bhEne03_DG09(BH_PWORK* epw)
{
	switch (epw->mode3)                             
    {
    case 0:
        epw->mtn_no = 56;
        epw->frm_no = 0;

        epw->hokan_count = 8;
        epw->hokan_rate  = 32768;

        epw->mtn_add = 65536;

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;

        epw->mode3++;
    case 1:
        bhEne03_AddNullTrans(epw, spmh_026);

        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 30;
            epw->frm_no = 0;

            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 3;
            epw->mode3 = 0;

            epw->flg &= ~0x4;
        }

        break;
    }
}

#pragma divbyzerocheck on 

// 100% matching!
void bhEne03_DG10(BH_PWORK* epw)
{    
    NJS_VECTOR v, ov;  
    float out; 
	int ang;      

    switch (epw->mode3) 
    {                    
    case 0:
        epw->mtn_no = 56;
        epw->frm_no = 0;
        
        epw->mtn_add = 65536;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 32768;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
        
        if ((epw->flg & 0x80000)) 
        {
            if ((EXP0_C(105) == 0) || (EXP0_C(105) == 1))
            {
                *(NJS_POINT3*)&EXP0_F(84) = *(NJS_POINT3*)&EXP0_F(108);
            } 
            else 
            {
                EXP0_F(84) = EXP0_F(16);
                EXP0_F(88) = EXP0_F(20);
                EXP0_F(92) = EXP0_F(24);
            }
            
            epw->flg |= 0x30;
            
            epw->flg &= ~0x80000;
            epw->flg &= ~0x1800000;
            epw->flg &= ~0x300000;
        } 
        else
        {
            EXP0_F(84) = epw->dvx;
            EXP0_F(88) = epw->dvy;
            EXP0_F(92) = epw->dvz;
            
            njUnitVector((NJS_VECTOR*)&EXP0_I(84));
            
            EXP0_F(84) *= 2.0f;
            EXP0_F(92) *= 2.0f;
        }
        
        epw->ct1 = 8;
        
        epw->mode3++;
        break;
    case 1:
        if (epw->ct1 > 0) 
        {
            v.x = 0;
            v.y = 1.0f;
            v.z = 0;
            
            out = njOuterProduct((NJS_VECTOR*)&EXP0_I(16), &v, &ov);
            
            if (out > 0) 
            {
                njUnitVector(&ov);
                njUnitMatrix(NULL);
                
                ang = (int)(10430.381f * asinf(out)) / epw->ct1;
                
                njRotate(NULL, &ov, ang);
                
                njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);
                
                njGetMatrix((NJS_MATRIX*)epw->exp0);
            }
            
            epw->ct1--;
        }
        
        if (epw->ct0 == 0) 
        {
            epw->mtn_add = 0;
        } 
        else
        {
            epw->ct0--;
        }
        
        if ((ATR_WORK*)EXP0_I(96) != NULL) 
        {
            EXP0_C(105) = 0;
            
            bhEne03_MakeMatrix(epw);
            
            epw->flg2 &= ~0x1;
            
            epw->mode3++;
            break;
        }
        
        epw->px += EXP0_F(84);
        epw->py += EXP0_F(88);
        epw->pz += EXP0_F(92);
        
        EXP0_F(88) -= 0.33f;
        break;
    case 2:
        bhEne03_AddNullTrans(epw, spmh_026);
        
        if (epw->ct0-- == 0) 
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 3;
            epw->mode3 = 0;
            
            epw->flg &= ~0x4;
            
            epw->mtn_no = 4;
            epw->frm_no = 0;
            
            epw->hokan_count = 5;
            epw->hokan_rate  = 32768;
            
            epw->mtn_add = 65536;
        }
        
        break;
    }
}

#pragma divbyzerocheck off 

// 
// Start address: 0x19cca0
void bhEne03_DG11(BH_PWORK* epw)
{
	int ang;
	float out;
	NJS_VECTOR ov;
	NJS_VECTOR v;
	//NJS_MKEY_A_MOD* mkaP;
	NJS_MKEY_A_MOD* mkaP;
	// Line 3982, Address: 0x19cca0, Func Offset: 0
	// Line 3983, Address: 0x19ccb0, Func Offset: 0x10
	// Line 3986, Address: 0x19ccdc, Func Offset: 0x3c
	// Line 3991, Address: 0x19ccec, Func Offset: 0x4c
	// Line 3992, Address: 0x19ccf4, Func Offset: 0x54
	// Line 3991, Address: 0x19ccf8, Func Offset: 0x58
	// Line 3992, Address: 0x19cd0c, Func Offset: 0x6c
	// Line 3991, Address: 0x19cd18, Func Offset: 0x78
	// Line 3992, Address: 0x19cd1c, Func Offset: 0x7c
	// Line 3993, Address: 0x19cd24, Func Offset: 0x84
	// Line 3997, Address: 0x19cd38, Func Offset: 0x98
	// Line 4000, Address: 0x19cd3c, Func Offset: 0x9c
	// Line 4002, Address: 0x19cd40, Func Offset: 0xa0
	// Line 4003, Address: 0x19cd44, Func Offset: 0xa4
	// Line 3997, Address: 0x19cd48, Func Offset: 0xa8
	// Line 4000, Address: 0x19cd50, Func Offset: 0xb0
	// Line 4001, Address: 0x19cd54, Func Offset: 0xb4
	// Line 4002, Address: 0x19cd58, Func Offset: 0xb8
	// Line 4003, Address: 0x19cd5c, Func Offset: 0xbc
	// Line 4004, Address: 0x19cd60, Func Offset: 0xc0
	// Line 4005, Address: 0x19cd64, Func Offset: 0xc4
	// Line 4011, Address: 0x19cd74, Func Offset: 0xd4
	// Line 4012, Address: 0x19cd78, Func Offset: 0xd8
	// Line 4011, Address: 0x19cd7c, Func Offset: 0xdc
	// Line 4012, Address: 0x19cd88, Func Offset: 0xe8
	// Line 4011, Address: 0x19cd8c, Func Offset: 0xec
	// Line 4012, Address: 0x19cd9c, Func Offset: 0xfc
	// Line 4013, Address: 0x19cda4, Func Offset: 0x104
	// Line 4014, Address: 0x19cdb4, Func Offset: 0x114
	// Line 4018, Address: 0x19cdc4, Func Offset: 0x124
	// Line 4020, Address: 0x19cde0, Func Offset: 0x140
	// Line 4021, Address: 0x19cdf4, Func Offset: 0x154
	// Line 4022, Address: 0x19cdfc, Func Offset: 0x15c
	// Line 4023, Address: 0x19ce04, Func Offset: 0x164
	// Line 4024, Address: 0x19ce10, Func Offset: 0x170
	// Line 4028, Address: 0x19ce1c, Func Offset: 0x17c
	// Line 4032, Address: 0x19ce20, Func Offset: 0x180
	// Line 4033, Address: 0x19ce28, Func Offset: 0x188
	// Line 4034, Address: 0x19ce30, Func Offset: 0x190
	// Line 4028, Address: 0x19ce34, Func Offset: 0x194
	// Line 4031, Address: 0x19ce38, Func Offset: 0x198
	// Line 4034, Address: 0x19ce3c, Func Offset: 0x19c
	// Line 4037, Address: 0x19ce40, Func Offset: 0x1a0
	// Line 4039, Address: 0x19ce44, Func Offset: 0x1a4
	// Line 4031, Address: 0x19ce48, Func Offset: 0x1a8
	// Line 4032, Address: 0x19ce50, Func Offset: 0x1b0
	// Line 4033, Address: 0x19ce5c, Func Offset: 0x1bc
	// Line 4034, Address: 0x19ce68, Func Offset: 0x1c8
	// Line 4037, Address: 0x19ce74, Func Offset: 0x1d4
	// Line 4039, Address: 0x19ce78, Func Offset: 0x1d8
	// Line 4040, Address: 0x19ce7c, Func Offset: 0x1dc
	// Line 4043, Address: 0x19ce88, Func Offset: 0x1e8
	// Line 4048, Address: 0x19ce94, Func Offset: 0x1f4
	// Line 4049, Address: 0x19ce98, Func Offset: 0x1f8
	// Line 4050, Address: 0x19cea0, Func Offset: 0x200
	// Line 4051, Address: 0x19cea4, Func Offset: 0x204
	// Line 4052, Address: 0x19cebc, Func Offset: 0x21c
	// Line 4053, Address: 0x19ced4, Func Offset: 0x234
	// Line 4056, Address: 0x19cedc, Func Offset: 0x23c
	// Line 4057, Address: 0x19cee4, Func Offset: 0x244
	// Line 4059, Address: 0x19cf00, Func Offset: 0x260
	// Line 4060, Address: 0x19cf24, Func Offset: 0x284
	// Line 4061, Address: 0x19cf44, Func Offset: 0x2a4
	// Line 4062, Address: 0x19cf50, Func Offset: 0x2b0
	// Line 4063, Address: 0x19cf58, Func Offset: 0x2b8
	// Line 4065, Address: 0x19cf60, Func Offset: 0x2c0
	// Line 4066, Address: 0x19cf6c, Func Offset: 0x2cc
	// Line 4067, Address: 0x19cf8c, Func Offset: 0x2ec
	// Line 4068, Address: 0x19cf98, Func Offset: 0x2f8
	// Line 4070, Address: 0x19cfa0, Func Offset: 0x300
	// Line 4074, Address: 0x19cfac, Func Offset: 0x30c
	// Line 4075, Address: 0x19cfbc, Func Offset: 0x31c
	// Line 4076, Address: 0x19cfc0, Func Offset: 0x320
	// Line 4079, Address: 0x19cfc8, Func Offset: 0x328
	// Line 4080, Address: 0x19cfe0, Func Offset: 0x340
	// Line 4081, Address: 0x19cfe4, Func Offset: 0x344
	// Line 4089, Address: 0x19cfec, Func Offset: 0x34c
	// Line 4093, Address: 0x19d024, Func Offset: 0x384
	// Line 4095, Address: 0x19d02c, Func Offset: 0x38c
	// Line 4094, Address: 0x19d030, Func Offset: 0x390
	// Line 4095, Address: 0x19d034, Func Offset: 0x394
	// Line 4096, Address: 0x19d038, Func Offset: 0x398
	// Line 4097, Address: 0x19d040, Func Offset: 0x3a0
	// Line 4100, Address: 0x19d048, Func Offset: 0x3a8
	// Line 4104, Address: 0x19d050, Func Offset: 0x3b0
	// Line 4100, Address: 0x19d054, Func Offset: 0x3b4
	// Line 4102, Address: 0x19d05c, Func Offset: 0x3bc
	// Line 4104, Address: 0x19d080, Func Offset: 0x3e0
	// Line 4106, Address: 0x19d08c, Func Offset: 0x3ec
	// Line 4107, Address: 0x19d094, Func Offset: 0x3f4
	// Line 4109, Address: 0x19d09c, Func Offset: 0x3fc
	// Line 4112, Address: 0x19d0a4, Func Offset: 0x404
	// Line 4109, Address: 0x19d0b4, Func Offset: 0x414
	// Line 4110, Address: 0x19d0bc, Func Offset: 0x41c
	// Line 4111, Address: 0x19d0d0, Func Offset: 0x430
	// Line 4112, Address: 0x19d0e4, Func Offset: 0x444
	// Line 4114, Address: 0x19d0f0, Func Offset: 0x450
	// Line 4116, Address: 0x19d0f8, Func Offset: 0x458
	// Line 4117, Address: 0x19d108, Func Offset: 0x468
	// Line 4118, Address: 0x19d110, Func Offset: 0x470
	// Line 4119, Address: 0x19d114, Func Offset: 0x474
	// Line 4120, Address: 0x19d11c, Func Offset: 0x47c
	// Line 4121, Address: 0x19d120, Func Offset: 0x480
	// Line 4124, Address: 0x19d128, Func Offset: 0x488
	// Line 4121, Address: 0x19d12c, Func Offset: 0x48c
	// Line 4124, Address: 0x19d134, Func Offset: 0x494
	// Line 4130, Address: 0x19d138, Func Offset: 0x498
	// Line 4131, Address: 0x19d160, Func Offset: 0x4c0
	// Func End, Address: 0x19d174, Func Offset: 0x4d4
}

// 
// Start address: 0x19d180
void bhEne03_DG12(BH_PWORK* epw)
{
	int ang;
	float out;
	NJS_VECTOR ov;
	NJS_VECTOR v;
	NJS_POINT3 trans;
	//NJS_MKEY_A_MOD* mkaP;
	NJS_MKEY_A_MOD* mkaP;
	// Line 4141, Address: 0x19d180, Func Offset: 0
	// Line 4142, Address: 0x19d190, Func Offset: 0x10
	// Line 4145, Address: 0x19d1c8, Func Offset: 0x48
	// Line 4150, Address: 0x19d1d8, Func Offset: 0x58
	// Line 4152, Address: 0x19d1dc, Func Offset: 0x5c
	// Line 4150, Address: 0x19d1e0, Func Offset: 0x60
	// Line 4151, Address: 0x19d1e4, Func Offset: 0x64
	// Line 4150, Address: 0x19d1e8, Func Offset: 0x68
	// Line 4152, Address: 0x19d1fc, Func Offset: 0x7c
	// Line 4150, Address: 0x19d200, Func Offset: 0x80
	// Line 4151, Address: 0x19d204, Func Offset: 0x84
	// Line 4152, Address: 0x19d214, Func Offset: 0x94
	// Line 4153, Address: 0x19d21c, Func Offset: 0x9c
	// Line 4154, Address: 0x19d238, Func Offset: 0xb8
	// Line 4155, Address: 0x19d240, Func Offset: 0xc0
	// Line 4160, Address: 0x19d254, Func Offset: 0xd4
	// Line 4161, Address: 0x19d268, Func Offset: 0xe8
	// Line 4162, Address: 0x19d274, Func Offset: 0xf4
	// Line 4163, Address: 0x19d27c, Func Offset: 0xfc
	// Line 4164, Address: 0x19d284, Func Offset: 0x104
	// Line 4165, Address: 0x19d28c, Func Offset: 0x10c
	// Line 4166, Address: 0x19d294, Func Offset: 0x114
	// Line 4167, Address: 0x19d29c, Func Offset: 0x11c
	// Line 4171, Address: 0x19d2a4, Func Offset: 0x124
	// Line 4174, Address: 0x19d2b0, Func Offset: 0x130
	// Line 4177, Address: 0x19d2b4, Func Offset: 0x134
	// Line 4180, Address: 0x19d2b8, Func Offset: 0x138
	// Line 4181, Address: 0x19d2bc, Func Offset: 0x13c
	// Line 4174, Address: 0x19d2c0, Func Offset: 0x140
	// Line 4177, Address: 0x19d2c8, Func Offset: 0x148
	// Line 4178, Address: 0x19d2cc, Func Offset: 0x14c
	// Line 4179, Address: 0x19d2d0, Func Offset: 0x150
	// Line 4180, Address: 0x19d2d4, Func Offset: 0x154
	// Line 4182, Address: 0x19d2d8, Func Offset: 0x158
	// Line 4180, Address: 0x19d2dc, Func Offset: 0x15c
	// Line 4181, Address: 0x19d2e4, Func Offset: 0x164
	// Line 4182, Address: 0x19d2e8, Func Offset: 0x168
	// Line 4188, Address: 0x19d2ec, Func Offset: 0x16c
	// Line 4189, Address: 0x19d2f0, Func Offset: 0x170
	// Line 4188, Address: 0x19d2f4, Func Offset: 0x174
	// Line 4189, Address: 0x19d300, Func Offset: 0x180
	// Line 4188, Address: 0x19d304, Func Offset: 0x184
	// Line 4189, Address: 0x19d314, Func Offset: 0x194
	// Line 4190, Address: 0x19d31c, Func Offset: 0x19c
	// Line 4191, Address: 0x19d32c, Func Offset: 0x1ac
	// Line 4200, Address: 0x19d33c, Func Offset: 0x1bc
	// Line 4201, Address: 0x19d368, Func Offset: 0x1e8
	// Line 4205, Address: 0x19d374, Func Offset: 0x1f4
	// Line 4209, Address: 0x19d378, Func Offset: 0x1f8
	// Line 4210, Address: 0x19d380, Func Offset: 0x200
	// Line 4211, Address: 0x19d388, Func Offset: 0x208
	// Line 4205, Address: 0x19d38c, Func Offset: 0x20c
	// Line 4208, Address: 0x19d390, Func Offset: 0x210
	// Line 4211, Address: 0x19d394, Func Offset: 0x214
	// Line 4213, Address: 0x19d398, Func Offset: 0x218
	// Line 4208, Address: 0x19d39c, Func Offset: 0x21c
	// Line 4209, Address: 0x19d3a4, Func Offset: 0x224
	// Line 4210, Address: 0x19d3b0, Func Offset: 0x230
	// Line 4211, Address: 0x19d3bc, Func Offset: 0x23c
	// Line 4213, Address: 0x19d3c8, Func Offset: 0x248
	// Line 4214, Address: 0x19d3cc, Func Offset: 0x24c
	// Line 4217, Address: 0x19d3d8, Func Offset: 0x258
	// Line 4222, Address: 0x19d3e4, Func Offset: 0x264
	// Line 4223, Address: 0x19d3e8, Func Offset: 0x268
	// Line 4224, Address: 0x19d3f0, Func Offset: 0x270
	// Line 4225, Address: 0x19d3f4, Func Offset: 0x274
	// Line 4226, Address: 0x19d40c, Func Offset: 0x28c
	// Line 4227, Address: 0x19d424, Func Offset: 0x2a4
	// Line 4230, Address: 0x19d42c, Func Offset: 0x2ac
	// Line 4231, Address: 0x19d434, Func Offset: 0x2b4
	// Line 4232, Address: 0x19d450, Func Offset: 0x2d0
	// Line 4233, Address: 0x19d470, Func Offset: 0x2f0
	// Line 4234, Address: 0x19d47c, Func Offset: 0x2fc
	// Line 4235, Address: 0x19d484, Func Offset: 0x304
	// Line 4237, Address: 0x19d48c, Func Offset: 0x30c
	// Line 4238, Address: 0x19d498, Func Offset: 0x318
	// Line 4239, Address: 0x19d4b8, Func Offset: 0x338
	// Line 4240, Address: 0x19d4c4, Func Offset: 0x344
	// Line 4242, Address: 0x19d4cc, Func Offset: 0x34c
	// Line 4246, Address: 0x19d4d8, Func Offset: 0x358
	// Line 4247, Address: 0x19d4e8, Func Offset: 0x368
	// Line 4248, Address: 0x19d4ec, Func Offset: 0x36c
	// Line 4251, Address: 0x19d4f4, Func Offset: 0x374
	// Line 4252, Address: 0x19d4fc, Func Offset: 0x37c
	// Line 4255, Address: 0x19d500, Func Offset: 0x380
	// Line 4259, Address: 0x19d508, Func Offset: 0x388
	// Line 4255, Address: 0x19d50c, Func Offset: 0x38c
	// Line 4257, Address: 0x19d514, Func Offset: 0x394
	// Line 4259, Address: 0x19d538, Func Offset: 0x3b8
	// Line 4261, Address: 0x19d544, Func Offset: 0x3c4
	// Line 4262, Address: 0x19d54c, Func Offset: 0x3cc
	// Line 4264, Address: 0x19d554, Func Offset: 0x3d4
	// Line 4267, Address: 0x19d55c, Func Offset: 0x3dc
	// Line 4264, Address: 0x19d56c, Func Offset: 0x3ec
	// Line 4265, Address: 0x19d574, Func Offset: 0x3f4
	// Line 4266, Address: 0x19d588, Func Offset: 0x408
	// Line 4267, Address: 0x19d59c, Func Offset: 0x41c
	// Line 4269, Address: 0x19d5a8, Func Offset: 0x428
	// Line 4271, Address: 0x19d5b0, Func Offset: 0x430
	// Line 4273, Address: 0x19d5c0, Func Offset: 0x440
	// Line 4274, Address: 0x19d5c8, Func Offset: 0x448
	// Line 4275, Address: 0x19d5cc, Func Offset: 0x44c
	// Line 4276, Address: 0x19d5f0, Func Offset: 0x470
	// Line 4278, Address: 0x19d5f8, Func Offset: 0x478
	// Line 4280, Address: 0x19d600, Func Offset: 0x480
	// Line 4281, Address: 0x19d60c, Func Offset: 0x48c
	// Line 4282, Address: 0x19d61c, Func Offset: 0x49c
	// Line 4283, Address: 0x19d624, Func Offset: 0x4a4
	// Line 4284, Address: 0x19d628, Func Offset: 0x4a8
	// Line 4285, Address: 0x19d62c, Func Offset: 0x4ac
	// Line 4286, Address: 0x19d630, Func Offset: 0x4b0
	// Line 4290, Address: 0x19d640, Func Offset: 0x4c0
	// Func End, Address: 0x19d654, Func Offset: 0x4d4
}

// 100% matching!
void bhEne03_Die(BH_PWORK* epw)
{
	bhEne03_DeadMode2[epw->mode2](epw);
}

// 98.20% matching
void bhEne03_DD00(BH_PWORK* epw)
{
    switch (epw->mode3) 
    {                        
    case 0:
        epw->mtn_no = 23;
        epw->frm_no = 0;
        
        epw->hokan_count = 8;
        epw->hokan_rate  = 32768;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        
        epw->mode3++;
    case 1:
        bhEne03_AddNullTrans(epw, spm_023);
        
        if (epw->ct0-- == 0) 
        {
            epw->mtn_no = 24;
            epw->frm_no = 0;
            
            epw->hokan_count = 0;
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
            
            epw->mode3++;
        }
        
        break;
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->frm_no = 65536.0f * (epw->mnwP[epw->mtn_no].frm_num - 1);
            
            epw->mtn_add = 0;
            
            epw->mode3++;
            
            epw->flg  &= ~0x8;
            epw->flg2 |=  0x1;
            
            epw->ay = bhArcTan2(-EXP0_F(8), EXP0_F(0));
            
            bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
        }
        
        break;
    }
}

#pragma divbyzerocheck on 

// 100% matching!
void bhEne03_DD01(BH_PWORK* epw) 
{
    NJS_MKEY_A_MOD* mkaP;   
    
    switch (epw->mode3) 
    {
    case 0:
        if ((epw->flg & 0x80000)) 
        {
            epw->flg |= 0x30;
            
            epw->flg &= ~0x1800000;
            epw->flg &= ~0x300000;
            
            bhEne03_GetPartsPos(epw, spider_tree[0], (NJS_POINT3*)&epw->px);
            
            mkaP  = epw->mnwP[epw->mtn_no].md2P->p[1];
            mkaP += epw->frm_no / 65536;
            
            njRotateXYZ((NJS_MATRIX*)epw->exp0, *mkaP->key++, *mkaP->key++, *mkaP->key++);
        }
        
        epw->mtn_no = 17;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 45875;
        
        epw->mtn_md |= 0x100;

        {
        NJS_MKEY_A_MOD* mkaP;
        NJS_MKEY* mkfP;       
        NJS_POINT3 trans;       
            
        mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];
            
        epw->mlwP->objP->ang[0] = *mkaP->key++;
        epw->mlwP->objP->ang[1] = *mkaP->key++;
        epw->mlwP->objP->ang[2] = *mkaP->key++;

        EXP0_F(84) = EXP0_F(16) / 2.0f;
        EXP0_F(88) = EXP0_F(20) / 2.0f;
        EXP0_F(92) = EXP0_F(24) / 2.0f;

        njRotateX((NJS_MATRIX*)epw->exp0, 32768);

        mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
            
        trans.x = *mkfP->key++;
        trans.y = *mkfP->key++;
        trans.z = *mkfP->key++;

        njCalcVector((NJS_MATRIX*)epw->exp0, &trans, &trans);

        epw->px -= trans.x;
        epw->py -= trans.y;
        epw->pz -= trans.z;
        }

        if ((epw->flg & 0x80000)) 
        {
            epw->flg &= ~0x80000;
            
            epw->pxb = epw->px;
            epw->pyb = epw->py;
            epw->pzb = epw->pz;
        }

        *(ATR_WORK**)&EXP0_I(96) = NULL;
        
        epw->ar = 0.1f;
        
        epw->flg  &= ~0x8;
        epw->flg2 |=  0x1;
        
        epw->ct0 = 8;
        
        epw->mode3++;
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

            out = njOuterProduct((NJS_VECTOR*)&EXP0_F(16), &v, &ov);
            
            if (out > 0) 
            {
                njUnitVector(&ov);
                njUnitMatrix(NULL);
                
                ang = 10430.381f * asinf(out);
                
                if (EXP0_F(20) < 0)
                {
                    ang = 32768 - ang;
                }
                
                njRotate(NULL, &ov, ang / epw->ct0);
                
                njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);
                
                njGetMatrix((NJS_MATRIX*)epw->exp0);
            }
            
            epw->ct0--;
        }

        if ((ATR_WORK*)EXP0_I(96) != NULL) 
        {
            EXP0_C(105) = 0;
            
            bhEne03_MakeMatrix(epw);
            
            epw->mtn_no = 24;
            epw->frm_no = 0;
            
            epw->hokan_count = 10;
            epw->hokan_rate  = 45875;
            
            epw->mtn_add = 65536;
            
            epw->mtn_md &= ~0x100;
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            
            epw->mode3++;
        } 
        else 
        {
            epw->px += EXP0_F(84);
            epw->py += EXP0_F(88);
            epw->pz += EXP0_F(92);
            
            EXP0_F(88) -= 0.33f;
        }
        
        break;
    }
    case 2:
        if (epw->ct0-- == 0) 
        {
            epw->mtn_add = 0;
            
            epw->mode3++;

            epw->ay = bhArcTan2(-EXP0_F(8), EXP0_F(0));
            
            bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
        }
        
        break;
    }

    epw->ar += (6.0f - epw->ar) / 16.0f;
}

#pragma divbyzerocheck off

// 99% matching
void bhEne03_DD02(BH_PWORK* epw)
{
    NJS_MKEY* mkfP;    
    NJS_POINT3 trans;    
	NJS_MKEY_A_MOD* mkaP; 

    switch (epw->mode3) 
    {
    case 0:
        epw->mtn_no = 17;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 45875;

        EXP0_F(84) = 0;
        EXP0_F(92) = 0;
        EXP0_F(88) = -1.0f;

        njRotateX((NJS_MATRIX*)epw->exp0, 32768);

        mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
        
        trans.x = *mkfP->key++;
        trans.y = *mkfP->key++;
        trans.z = *mkfP->key++;

        njCalcVector((NJS_MATRIX*)epw->exp0, &trans, &trans);

        epw->px -= trans.x;
        epw->py -= trans.y;
        epw->pz -= trans.z;

        epw->mtn_md |= 0x100;

        mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];
        
        epw->mlwP->objP->ang[0] = *mkaP->key++;
        epw->mlwP->objP->ang[1] = *mkaP->key++;
        epw->mlwP->objP->ang[2] = *mkaP->key++;

        *(ATR_WORK**)&EXP0_I(96) = NULL;
        
        epw->flg  &= ~0x8;
        epw->flg2 |=  0x1;
        
        epw->ar = 0.1f;
        
        epw->mode3++;
    case 1:
        if ((ATR_WORK*)EXP0_I(96) != NULL)
        {
            EXP0_C(105) = 0;
            
            bhEne03_MakeMatrix(epw);
            
            epw->mtn_no = 24;
            epw->frm_no = 0;
            
            epw->hokan_count = 0;
            
            epw->mtn_add = 65536;
            
            epw->mtn_md &= ~0x100;
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
            
            epw->mode3++;
        } 
        else 
        {
            epw->py += EXP0_F(88);
            
            EXP0_F(88) -= 0.33f;
        }
        
        break;
    case 2:
        if (epw->ct0-- == 0) 
        {
            epw->frm_no = (epw->mnwP[epw->mtn_no].frm_num - 1) * 65536.0f;
            
            epw->hokan_count = 0;
            
            epw->mtn_add = 0;
            
            epw->mode3++;

            epw->ay = bhArcTan2(-EXP0_F(8), EXP0_F(0));
            
            bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
        }
        
        break;
    case 3:
        break;
    }

    epw->ar += (6.0f - epw->ar) / 16.0f;
}

// 100% matching!
void bhEne03_DD03(BH_PWORK* epw)
{
    O_WORK* owk;       
    unsigned int i;    
	NJS_CNK_OBJECT* p;

    switch (epw->mode3) 
    {
    case 0:
        epw->flg  &= ~0x8;
        epw->flg2 |=  0x1;
        
        epw->flg |= 0x8000;
    
        bhEne_SetMinceEffect2(epw, 2,   0.5f, 6);
        bhEne_SetMinceEffect2(epw, 259, 0.3f, 8);
    
        bhEne_SetBloodEffect4((NJS_POINT3*)&epw->px, (NJS_POINT3*)&epw->px, 1, 9, 1);
        bhEne_SetBloodEffect4((NJS_POINT3*)&epw->px, (NJS_POINT3*)&epw->px, 1, 9, 2);
    
        for (i = 0; i < 8; i++) 
        {
            if (((unsigned char*)epw->exp0)[160 + i] == 0) 
            {
                owk = epw->mlwP->owP;
    					
                owk[BrokenParts[i]].flg     |= 0x3;
                owk[BrokenParts[i] + 1].flg |= 0x2;
                owk[BrokenParts[i] + 2].flg |= 0x2;
    
                EXP0_BYTE(i, 12) = 1;
                EXP0_BYTE(i, 14) = 0;
                EXP0_BYTE(i, 15) = 0; 
                
                EXP0_INT(i, 980) = EXP0_C(105);
            }
        }
    
        epw->mdflg |= 0x20;
        epw->stflg |= 0x8;
    
        p = epw->mlwP->objP;

        p[1].evalflags  |= 0x8;
        p[2].evalflags  |= 0x8;
        p[31].evalflags |= 0x8;
        p[32].evalflags |= 0x8;
        p[33].evalflags |= 0x8;
        p[34].evalflags |= 0x8;
        p[35].evalflags |= 0x8;
        p[36].evalflags |= 0x8;
    
        bhEne_EraseArrow(epw, 1);
        bhEne_EraseArrow(epw, 2);
        bhEne_EraseArrow(epw, 31);
        bhEne_EraseArrow(epw, 32);
        bhEne_EraseArrow(epw, 33);
        bhEne_EraseArrow(epw, 34);
        bhEne_EraseArrow(epw, 35);
        bhEne_EraseArrow(epw, 36);
    
        epw->mtn_no  = 0;
        epw->mtn_add = 0;
        
        epw->frm_no = 0;
        
        epw->mode3++;
        break;
    }
}

// 100% matching!
void bhEne03_DD04(BH_PWORK* epw)
{
    NJS_POINT3 pos;      
	NJS_MKEY_A_MOD* mkaP;
    ATR_WORK* hp; // not from DWARF
    float h;      // not from DWARF

    switch (epw->mode3) 
    {
    case 0:
        bhEne03_GetPartsPos(epw, spider_tree[0], &pos);
        
        epw->px = pos.x;
        epw->py = pos.y;
        epw->pz = pos.z;

        epw->mtn_md |= 0x100;
        
        epw->mtn_no = 50;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate  = 52428;
        
        epw->mtn_add = 0;
        
        epw->mtn_md &= ~0x2;

        if ((EXP0_C(105) == 0) || (EXP0_C(105) == 1)) 
        {
            *(NJS_POINT3*)&EXP0_F(84) = *(NJS_POINT3*)&EXP0_F(108);
        } 
        else 
        {
            EXP0_F(84) = EXP0_F(16);
            EXP0_F(88) = EXP0_F(20);
            EXP0_F(92) = EXP0_F(24);
        }

        mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];
        
        epw->mlwP->objP->ang[0] = *mkaP->key++;
        epw->mlwP->objP->ang[1] = *mkaP->key++;
        epw->mlwP->objP->ang[2] = *mkaP->key++;

        *(ATR_WORK**)&EXP0_I(96) = NULL;
        
        epw->flg |= 0x30;
        
        epw->flg &= ~0x80000;
        epw->flg &= ~0x1800000;
        epw->flg &= ~0x300000;
        
        epw->ar = 3.0f;
        
        epw->ct0 = 8;
        
        epw->mode3++;
    case 1:
        if (epw->ct0 > 0) 
        {
            epw->ct0--;
            
            njUnitMatrix(NULL);

            switch (EXP0_C(105)) 
            {
            case 5: 
                njRotateX(NULL, -2048); 
                break;
            case 3: 
                njRotateX(NULL,  2048); 
                break;
            case 4: 
                njRotateZ(NULL, -2048); 
                break;
            case 2: 
                njRotateZ(NULL,  2048); 
                break;
            case 1: 
                njRotateX(NULL,  4096); 
                break;
            }
            
            njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);
            
            njGetMatrix((NJS_MATRIX*)epw->exp0);
        }

        hp = (ATR_WORK*)EXP0_I(96);
        
        if ((ATR_WORK*)EXP0_I(96) != NULL) 
        {
            EXP0_C(105) = 0;
            
            bhEne03_MakeMatrix(epw);

            hp = (ATR_WORK*)EXP0_I(96);
            
            if (hp->type == 7)
            {
                epw->py = hp->py;
            } 
            else 
            {
                h = hp->h;
                
                if (h == 0.0f) 
                {
                    h = rom->h;
                }
                
                epw->py = hp->py + h;
            }

            epw->mtn_no = 49;
            epw->frm_no = 0;
            
            epw->hokan_count = 3;
            epw->hokan_rate  = 32768;
            
            epw->mtn_add = 65536;
            
            epw->mtn_md &= ~0x100;
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            
            epw->mode3++;
        } 
        else 
        {
            epw->px += EXP0_F(84);
            epw->py += EXP0_F(88);
            epw->pz += EXP0_F(92);
            
            EXP0_F(88) -= 0.33f;
        }
        
        break;
    case 2:
        if (epw->ct0-- == 0) 
        {
            epw->mode0 = 4;
            epw->mode1 = 0;
            epw->mode2 = 5;
            epw->mode3 = 0;
            
            epw->flg  &= ~0x8;
            epw->flg2 |=  0x1;
            
            epw->ar = 6.0f;
        }
        
        break;
    }

    epw->ar += (6.0f - epw->ar) / 16.0f;
}

// 100% matching!
void bhEne03_DD05(BH_PWORK* epw)
{
    switch (epw->mode3)                             
    {
    case 0:
        epw->mtn_no = 27;
        epw->frm_no = 0;

        epw->hokan_count = 8;
        epw->hokan_rate  = 32768;

        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;

        epw->mode3++;
        break;
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
}

// 100% matching!
int bhEne03_DGDirCheck(BH_PWORK* epw)
{
	NJS_VECTOR v;
	
    v.x = -EXP0_F(32);
    v.y = -EXP0_F(36);
    v.z = -EXP0_F(40);

    if (njInnerProduct(&v, (NJS_VECTOR*)&epw->dvx) < 0)
    {
        return 0;
    }

    return 1;
}

// 100% matching!
void bhEne03_SearchPlayer(BH_PWORK* epw, int ang)
{
    NJS_POINT3 dist;
    NJS_POINT3 p1, p2;

    dist.x = epw->px - plp->px;
    dist.y = epw->py - plp->py;
    dist.z = epw->pz - plp->pz;
    
    njSetMatrix(NULL, (NJS_MATRIX*)epw->exp0);
    
    njInvertMatrix(NULL);
    
    njCalcPoint(NULL, &dist, &dist);
    
    EXP0_I(68) = bhArcTan2(dist.x, dist.z);
    
    if (abs(EXP0_I(68)) < ang) 
    {
        p1.x = epw->px + (5.0f * EXP0_F(16));
        p1.y = epw->py + (5.0f * EXP0_F(20));
        p1.z = epw->pz + (5.0f * EXP0_F(24));
        
        p2.x = plp->px;
        p2.y = 10.0f + plp->py;
        p2.z = plp->pz;
        
        if (bhCollisionCheckLine2(&p1, &p2, 0x4400, -1) == NULL) 
        {
            EXP0_UC(104) = 1;
            return;
        }
    }
    
    if (EXP0_UC(104) != 0) 
    {
        EXP0_UC(104)++;
        
        if (EXP0_UC(104) > 90) 
        {
            EXP0_UC(104) = 0;
        }
    }
}

// 100% matching!
int bhEne03_DirTarget(BH_PWORK* epw, NJS_POINT3* pos, int w)
{
	int ang;
	NJS_VECTOR vec;
	
    vec.x = epw->px - pos->x;
    vec.y = epw->py - pos->y;
    vec.z = epw->pz - pos->z;
    
    njSetMatrix(NULL, (NJS_MATRIX*)epw->exp0);
    
    njInvertMatrix(NULL);
    
    njCalcPoint(NULL, &vec, &vec);
    
    ang = bhArcTan2(vec.x, vec.z);
    
    if (w < abs(ang))
    {
        ang = (ang > 0) ? w : -w; 
    }
    
    return ang;
}

// 100% matching!
void bhEne03_GoAHead(BH_PWORK* epw)
{
	epw->px -= EXP0_F(32) * epw->spd;
    epw->py -= EXP0_F(36) * epw->spd;
    epw->pz -= EXP0_F(40) * epw->spd;
}

// 100% matching!
void bhEne03_GetPartsPos(BH_PWORK* epw, char* parts, NJS_POINT3* p)
{
	ML_WORK* mlwP;
	NJS_CNK_OBJECT* objP;

    mlwP = epw->mlwP;

    njPushMatrixEx();

    njUnitMatrix(NULL);

    njTranslateEx((NJS_VECTOR*)&epw->px);

    njMultiMatrix(NULL, (NJS_MATRIX*)epw->exp0);

    while (*parts != -1)
    {
        objP = &mlwP->objP[*parts++];

        njTranslateEx((NJS_VECTOR*)objP->pos);
        njRotateEx(objP->ang, 0);
    }

    njGetTranslation(NULL, p);

    njPopMatrixEx();
}

// 100% matching!
void bhEne03_MakeMatrix(BH_PWORK* epw)
{
    int ang; 
    float px, py, pz; // not from DWARF

    px = -EXP0_F(32);
    py = -EXP0_F(36);
    pz = -EXP0_F(40);
    
    njUnitMatrix((NJS_MATRIX*)epw->exp0);
    
    switch (EXP0_C(105)) 
    {
    case 0:
        ang = bhArcTan2(-px, -pz);
        
        njRotateY((NJS_MATRIX*)epw->exp0, ang);
        break;
    case 1:
        ang = bhArcTan2(-px, -pz);
        
        njRotateY((NJS_MATRIX*)epw->exp0, ang);
        njRotateZ((NJS_MATRIX*)epw->exp0, 32768);
        break;
    case 3:
        ang = bhArcTan2(-px, py);
        
        njRotateX((NJS_MATRIX*)epw->exp0, 16384);
        njRotateY((NJS_MATRIX*)epw->exp0, ang);
        njRotateZ((NJS_MATRIX*)epw->exp0, 32768);
        break;
    case 5:
        ang = bhArcTan2(-px, py);
        
        njRotateX((NJS_MATRIX*)epw->exp0, 16384);
        njRotateY((NJS_MATRIX*)epw->exp0, ang);
        break;
    case 2:
        ang = bhArcTan2(py, -pz);
        
        njRotateZ((NJS_MATRIX*)epw->exp0, -16384);
        njRotateY((NJS_MATRIX*)epw->exp0, ang);
        break;
    case 4:
        ang = bhArcTan2(py, -pz);
        
        njRotateZ((NJS_MATRIX*)epw->exp0, -16384);
        njRotateY((NJS_MATRIX*)epw->exp0, ang);
        njRotateZ((NJS_MATRIX*)epw->exp0, 32768);
        break;
    }
}

// 100% matching!
void bhEne03_HidePartsSub0(NJS_CNK_OBJECT* p)
{
    p->evalflags |= 0x8;

    if (p->child != NULL)
    {
        bhEne03_HidePartsSub0(p->child);
    }

    if (p->sibling != NULL)
    {
        bhEne03_HidePartsSub0(p->sibling);
    }
}

// 100% matching!
void bhEne03_HidePartsSub1(NJS_CNK_OBJECT* p)
{
	p->evalflags &= ~0x8;

    if (p->child != NULL)
    {
        bhEne03_HidePartsSub1(p->child);
    }

    if (p->sibling != NULL)
    {
        bhEne03_HidePartsSub1(p->sibling);
    }
}

// 100% matching!
void bhEne03_HideParts(BH_PWORK* epw, unsigned short PartsNo, unsigned short flg)
{
	NJS_CNK_OBJECT* p;

    p = &epw->mlwP->objP[PartsNo];

    if (flg)
    {
        p->evalflags |= 0x8;

        if (p->child != NULL)
        {
            bhEne03_HidePartsSub0(p->child);
        }
    }
    else
    {
        p->evalflags &= ~0x8;

        if (p->child != NULL)
        {
            bhEne03_HidePartsSub1(p->child);
        }
    }
}

// 100% matching!
int bhEne03_CollisionWalls(BH_PWORK* epw)
{
    NJS_POINT3 body, trans;      
    int ret;             
    NJS_MKEY_A_MOD* mkaP; 
    NJS_CNK_OBJECT* objP; 
    float px, py, pz; // not from DWARF

    px = epw->px;
    py = epw->py;
    pz = epw->pz;

    body.x = 0;
    body.y = epw->ar;
    body.z = 0;

    ret = 0; 

    njSetMatrix(NULL, (NJS_MATRIX*)epw->exp0);

    if ((epw->flg & 0x1000000)) 
    {
        mkaP =  epw->mnwP[epw->mtn_no].md2P->p[1];
        mkaP += epw->frm_no / 65536;
        
        njRotateXYZ(NULL, mkaP->key[0], mkaP->key[1], mkaP->key[2]);
    }

    njCalcVector(NULL, &body, &body);

    objP = epw->mlwP->objP;
    
    trans.x = objP->pos[0];
    trans.y = objP->pos[1];
    trans.z = objP->pos[2];

    if (!(epw->flg & 0x00800000)) 
    {
        trans.y = 0;
    }

    njCalcVector((NJS_MATRIX*)epw->exp0, &trans, &trans);

    epw->px += trans.x;
    epw->py += trans.y;
    epw->pz += trans.z;

    if ((ATR_WORK*)EXP0_I(96) != NULL) 
    {
        epw->px += body.x;
        epw->py += body.y;
        epw->pz += body.z;

        epw->px -= 3.0f * EXP0_F(32);
        epw->py -= 3.0f * EXP0_F(36);
        epw->pz -= 3.0f * EXP0_F(40);
        
        if (bhEne03_Collision2(epw, (ATR_WORK*)EXP0_I(96)) != NULL)
        {
            ret = 1;
        }

        epw->px += 3.0f * EXP0_F(32);
        epw->py += 3.0f * EXP0_F(36);
        epw->pz += 3.0f * EXP0_F(40);
        
        if (bhEne03_Collision2(epw, (ATR_WORK*)EXP0_I(96)) != NULL) 
        {
            ret = 1;
        }

        if (epw->type == 0)
        {
            epw->px += 2.0f * EXP0_F(32);
            epw->py += 2.0f * EXP0_F(36);
            epw->pz += 2.0f * EXP0_F(40);
            
            if (bhEne03_Collision2(epw, (ATR_WORK*)EXP0_I(96)) != NULL) 
            {
                ret = 1;
            }

            epw->px -= 2.0f * EXP0_F(32);
            epw->py -= 2.0f * EXP0_F(36);
            epw->pz -= 2.0f * EXP0_F(40);
        }

        if ((EXP0_C(105) != 0) && (EXP0_C(105) != 1)) 
        {
            bhEne03_CollisionBoxEdge2(epw);
        }

        epw->px -= body.x;
        epw->py -= body.y;
        epw->pz -= body.z;
    } 
    else 
    {
        epw->px += body.x;
        epw->py += body.y;
        epw->pz += body.z;

        if (bhEne03_Collision(epw) != NULL) 
        {
            ret = 1;
        }

        epw->px -= body.x;
        epw->py -= body.y;
        epw->pz -= body.z;
    }

    epw->px -= trans.x;
    epw->py -= trans.y;
    epw->pz -= trans.z;

    if ((ATR_WORK*)EXP0_I(96) != NULL) 
    {
        switch (EXP0_C(105)) 
        {
        case 0:
        case 1:
            epw->py = py;
            break;
        case 2:
        case 4:
            epw->px = px;
            break;
        case 3:
        case 5:
            epw->pz = pz;
            break;
        }
    }

    return ret;
}

// 100% matching!
ATR_WORK* bhEne03_GetWall(BH_PWORK* epw)
{
	NJS_POINT3 p1;
	NJS_POINT3 p2;

    p1.x = epw->px + EXP0_F(0x10);
    p1.y = epw->py + EXP0_F(0x14);
    p1.z = epw->pz + EXP0_F(0x18);
    
    p2.x = p1.x - (999.0f * EXP0_F(0x10));
    p2.y = p1.y - (999.0f * EXP0_F(0x14));
    p2.z = p1.z - (999.0f * EXP0_F(0x18));
    
    return bhCollisionCheckLine(&p1, &p2);
}

// 100% matching!
ATR_WORK* bhEne03_Collision(BH_PWORK* epw)
{
	ATR_WORK* hp;
	ATR_WORK* ret;
    int i;
	int wal_n;

	ret = NULL;
	wal_n = rom->wal_n + sys->mwal_n;

	for (i = 0; i < wal_n; i++)
	{
		if (i < rom->wal_n)
        {
            hp = &rom->walp[i];
        }
        else
        {
            hp = &sys->mwalp[i - rom->wal_n];
        }
			
		if (!(hp->flg & 1)) 
        {
            continue;
        }

		switch (hp->type)
		{
		case 0:
		case 1:
			if ((hp->type & 1) && (epw->flg & 0x400)) 
            {
                continue;
            }
				
			if (bhEne03_CollisionWallBox(hp, (NJS_POINT3*)&epw->px, epw->ar))
            {
                ret = hp;
            }
				
			break;

		case 2:
		case 3:
			if ((hp->type & 1) && (epw->flg & 0x400))
            {
                continue;
            }
            
			if (bhEne03_CollisionWallCylinder(hp, (NJS_POINT3*)&epw->px, epw->ar))
			{
                ret = hp;
            }
            
			break;

		case 4:
		case 5:
			if ((hp->type & 1) && (epw->flg & 0x400))
            {
                continue;
            }
            
			if (bhEne03_CollisionWallTriangle(hp, (NJS_POINT3*)&epw->px, epw->ar))
			{
                ret = hp;
            }
			break;

		case 6:
			if (bhEne03_CollisionWallSlope(hp, (NJS_POINT3*)&epw->px, epw->ar))
			{
                ret = hp;
            }
            
			break;

		case 7:
			if (bhEne03_CollisionWallGround(hp, (NJS_POINT3*)&epw->px, epw->ar))
			{
                ret = hp;
            }
            
			break;
		}
	}
	return ret;
}

// 100% matching!
ATR_WORK* bhEne03_Collision2(BH_PWORK* epw, ATR_WORK* gnd)
{
	ATR_WORK* hp;
	ATR_WORK* ret;
    int i;
	int wal_n;

	ret = NULL;
	wal_n = rom->wal_n + sys->mwal_n;

	for (i = 0; i < wal_n; i++)
	{
		if (i < rom->wal_n)
        {
            hp = &rom->walp[i];
        }
        else
        {
            hp = &sys->mwalp[i - rom->wal_n];
        }
			
		if ((hp->flg & 1) && (hp != gnd)) 
        {
    		switch (hp->type)
    		{
    		case 0:
    		case 1:
    			if ((hp->type & 1) && (epw->flg & 0x400)) 
                {
                    continue;
                }
    				
    			if (bhEne03_CollisionWallBox(hp, (NJS_POINT3*)&epw->px, epw->ar))
                {
                    ret = hp;
                }
    				
    			break;
    
    		case 2:
    		case 3:
    			if ((hp->type & 1) && (epw->flg & 0x400))
                {
                    continue;
                }
                
    			if (bhEne03_CollisionWallCylinder(hp, (NJS_POINT3*)&epw->px, epw->ar))
    			{
                    ret = hp;
                }
                
    			break;
    
    		case 4:
    		case 5:
    			if ((hp->type & 1) && (epw->flg & 0x400))
                {
                    continue;
                }
                
    			if (bhEne03_CollisionWallTriangle(hp, (NJS_POINT3*)&epw->px, epw->ar))
    			{
                    ret = hp;
                }
                
    			break;
    
    		case 6:
    			if (bhEne03_CollisionWallSlope(hp, (NJS_POINT3*)&epw->px, epw->ar))
    			{
                    ret = hp;
                }
                
    			break;
    
    		case 7:
    			if (bhEne03_CollisionWallGround(hp, (NJS_POINT3*)&epw->px, epw->ar))
    			{
                    ret = hp;
                }
                
    			break;
    		}
        }
	}
	return ret;
}

// 100% matching!
int bhEne03_CollisionWallBox(ATR_WORK* hp, NJS_VECTOR* pos, float ar)
{
    // the order of the variables below is different from the one in the DWARF
    float cx;
    float cy;   
    float cz;
    float h;   
    float dx;
    float dy;
    float dz;  
    float px;
    float py;
    float pz;
    float ax;
    float ay;
    float az; 
    float len;


    h = hp->h;
    if (h == 0.0f)
    {
        h = rom->h;
    }

    px = hp->px;
    py = hp->py;
    pz = hp->pz;

    dx = px - ar;
    dy = py - ar;
    dz = pz - ar;

    cx = px + (hp->w / 2.0f);
    cy = py + (h / 2.0f);
    cz = pz + (hp->d / 2.0f);
    
    if ((pos->x > dx) && (pos->x < (ar + (px + hp->w)))
        && (pos->y > dy) && (pos->y < (ar + (py + h)))
        && (pos->z > dz) && (pos->z < (ar + (pz + hp->d))))
    {
        if (pos->x > cx)
        {
            dx = ar + (px + hp->w);
            px += hp->w;
        }

        if (pos->z > cz)
        {
            dz = ar + (pz + hp->d);
            pz += hp->d;
        }

        if (pos->y > cy)
        {
            dy = ar + (py + h);
            py += h;
        }

        ax = fabsf(pos->x - dx);
        ay = fabsf(pos->y - dy);
        az = fabsf(pos->z - dz);

        if ((ax < ar) && (ay < ar) && (az < ar))
        {
            dx = pos->x - px;
            dy = pos->y - py;
            dz = pos->z - pz;
            len = njSqrt((dx * dx) + (dy * dy) + (dz * dz));
            if (len < ar)
            {
                pos->x = px + ((dx * ar) / len);
                pos->y = py + ((dy * ar) / len);
                pos->z = pz + ((dz * ar) / len);
            }
        } 
        else if ((ay < ar) && (az < ar))
        {
            dy = pos->y - py;
            dz = pos->z - pz;
            len = njSqrt((dy * dy) + (dz * dz));
            if (len < ar)
            {
                pos->y = py + ((dy * ar) / len);
                pos->z = pz + ((dz * ar) / len);
            }
        } 
        else if ((ax < ar) && (az < ar))
        {
            dx = pos->x - px;
            dz = pos->z - pz;
            len = njSqrt((dx * dx) + (dz * dz));
            if (len < ar)
            {
                pos->x = px + ((dx * ar) / len);
                pos->z = pz + ((dz * ar) / len);
            }
        } 
        else if ((ax < ar) && (ay < ar))
        {
            dx = pos->x - px;
            dy = pos->y - py;
            len = njSqrt((dx * dx) + (dy * dy));
            if (len < ar)
            {
                pos->x = px + ((dx * ar) / len);
                pos->y = py + ((dy * ar) / len);
            }
        } 
        else
        {
            if ((ay > ax) && (az > ax)) {
                pos->x = dx;
            }
            if ((ax > ay) && (az > ay)) {
                pos->y = dy;
            }
            if ((ax > az) && (ay > az)) {
                pos->z = dz;
            }
        }

        return 1;
    }

    return 0;
}

// 100% matching!
int bhEne03_CollisionWallGround(ATR_WORK* hp, NJS_POINT3* pos, float ar)
{
    ATR_WORK hp2 = *hp;
    
    hp2.type = 0;
    hp2.py = hp->py + hp->h;

    if (!hp->h)
    {
        hp2.h = 0.01f;
        hp2.py -= 0.01f;
    } 
    else
    {
        hp2.h = -hp->h;
    }
    
    return bhEne03_CollisionWallBox(&hp2, pos, ar);
}

// 100% matching!
int bhEne03_CollisionWallCylinder(ATR_WORK* hp, NJS_VECTOR* pos, float ar)
{
	float dx;
	float dy;
	float dz;
	float ln;
	float radius;    
	float h;

	h = hp->h;
	if (h == 0.0f)
    {    
        h = rom->h;
    }
		
	dx = hp->px - pos->x;
    dy = hp->py + h - pos->y;
	dz = hp->pz - pos->z;
	
	ln = njSqrt(dx * dx + dz * dz);
	radius = hp->w + ar;

	if ((dy >= 0.0f) && (hp->py < pos->y) && (ln < radius))
	{
		pos->x = hp->px - (dx * radius) / ln;
		pos->z = hp->pz - (dz * radius) / ln;
		return 1;
	}

	if (fabsf(dy) < ar)
	{
		radius = njSqrt(ar * ar - dy * dy);
		if (ln < hp->w + radius)
		{
			radius += hp->w;
			pos->x = hp->px - (dx * radius) / ln;
			pos->z = hp->pz - (dz * radius) / ln;
			return 1;
		}
	}

	return 0;
}

// 100% matching!
int bhEne03_CollisionWallSlope(ATR_WORK* hp, NJS_POINT3* pos, float ar)
{
    float h;
    float len;
    NJS_POINT3 area[4];
    NJS_POINT3 cp;
    NJS_PLANE pl;
    NJS_LINE ln;  
    signed char xf0;
    signed char xf1;
    signed char zf0;
    signed char zf1;  
    signed char idx;  
    signed char idx2;

    h = hp->h;
    if (h == 0.0f)
    {
        h = rom->h;
    }

    if (pos->x > hp->px - ar)
    {
        if((pos->x < hp->px + hp->w + ar &&
            pos->z > hp->pz - ar &&
            pos->z < hp->pz + hp->d + ar &&
            pos->y > hp->py - ar &&
            pos->y < hp->py + h + ar))
        {    
        
            area[0].x = hp->px;
            area[0].y = hp->py;
            area[0].z = hp->pz;
        
            area[1].x = hp->px;
            area[1].y = hp->py;
            area[1].z = hp->pz + hp->d;
        
            area[2].x = hp->px + hp->w;
            area[2].y = hp->py;
            area[2].z = hp->pz + hp->d;
        
            area[3].x = hp->px + hp->w;
            area[3].y = hp->py;
            area[3].z = hp->pz;
        
            switch (hp->id)
            {
            case 0:
                area[2].y = area[3].y = hp->py + h;
                break;
                
            case 1:
                area[0].y = area[3].y = hp->py + h;
                break;
                
            case 2:
                area[1].y = area[2].y = hp->py + h;            
                break;
                
            case 3:
                area[0].y = area[1].y = hp->py + h;            
                break;
            }
        
            njGetPlaneNormal(area, (NJS_VECTOR*)&pl.vx);
            pl.px = area[0].x;
            pl.py = area[0].y;
            pl.pz = area[0].z;
        
            len = njDistanceP2PL(pos, &pl, &cp);
            if ((len < ar))
            {   
                xf0 = zf0 = xf1 = zf1 = 0;
                
                if (cp.x < hp->px)
                {
                    xf0 = 1;
                }
                if (cp.x > (hp->px + hp->w))
                {
                    xf1 = 1;
                }
                if (cp.z < hp->pz) 
                {
                    zf0 = 1;
                }
                if (cp.z > (hp->pz + hp->d))
                {
                    zf1 = 1;
                }

                if (!xf0 && !zf0 && !xf1 && !zf1)
                {
                    njUnitVector((NJS_VECTOR*)&pl.vx);
                    pos->x = cp.x + pl.vx * ar;
                    pos->y = cp.y + pl.vy * ar;
                    pos->z = cp.z + pl.vz * ar;
                    return 1;
                }
            
                if (xf0 + xf1 + zf0 + zf1 == 1)
                {                    
                    if (xf0)
                    {
                        idx = 0;  
                        idx2 = 1;
                    }
                    else if (xf1)
                    {
                        idx = 2;
                        idx2 = 3;
                    } 
                    else if (zf0)
                    {
                        idx = 0;
                        idx2 = 3;
                    } 
                    else
                    {
                        idx = 1;
                        idx2 = 2;
                    }
            
                    ln.px = area[idx].x;
                    ln.py = area[idx].y;
                    ln.pz = area[idx].z;
                    ln.vx = area[idx2].x - ln.px;
                    ln.vy = area[idx2].y - ln.py;
                    ln.vz = area[idx2].z - ln.pz;
            
                    len = njDistanceP2L(pos, &ln, &cp);
                    if (len < ar)
                    {
                        pos->x = cp.x - ar * (cp.x - pos->x) / len;
                        pos->y = cp.y - ar * (cp.y - pos->y) / len;
                        pos->z = cp.z - ar * (cp.z - pos->z) / len;
                        return 1;
                    }
                }
            
                if (xf0 + xf1 + zf0 + zf1 == 2)
                {
                    if (xf0 && zf0)
                    {
                        idx = 0;
                    }                    
                    if (xf0 && zf1)
                    {
                        idx = 1;
                    }
                    if (xf1 && zf1)
                    {
                        idx = 2;
                    }
                    if (xf1 && zf0)
                    {
                        idx = 3;
                    }
                                    
                    len = njDistanceP2P(&area[idx], pos);
                    if (len < ar)
                    {
                        pos->x = area[idx].x - ar * (area[idx].x - pos->x) / len;
                        pos->y = area[idx].y - ar * (area[idx].y - pos->y) / len;
                        pos->z = area[idx].z - ar * (area[idx].z - pos->z) / len;
                        return 1;
                    }
                } 
            } 
        } 
    }
    return 0;
}

// 100% matching!
int bhEne03_CollisionWallTriangle(ATR_WORK* hp, NJS_VECTOR* pos, float ar)
{
    float h;
    NJS_POINT3 area[4];
    NJS_POINT3 pd;
    NJS_POINT3 vd;
    NJS_LINE ln;
    ATR_WORK bhp;

    // not present in DWARF
    float x1, x2, z1, z2;
    float t;
    float px;

    h = hp->h;
    if (h == 0.0f)
    {
        h = rom->h;
    }

    if ((hp->py <= pos->y - ar))
    {
        if (hp->py + h >= pos->y - ar)           
        {
            if ((hp->py <= pos->y) && (hp->py + h >= pos->y))
            {          
                if (hp->w > 0.0f)
                {
                    x1 = hp->px - ar;
                    x2 = hp->px + hp->w + ar;
                } 
                else
                {
                    x1 = hp->px + hp->w - ar;
                    x2 = hp->px + ar;
                }
            
                if (hp->d > 0.0f)
                {
                    z1 = hp->pz - ar;
                    z2 = hp->pz + hp->d + ar;
                } 
                else
                {
                    z1 = hp->pz + hp->d - ar;
                    z2 = hp->pz + ar;
                }
             
                if ((x1 > pos->x || x2 <= pos->x || z1 > pos->z || z2 <= pos->z))
                {
                    return 0;
                }
                    
                
                if (hp->id == 0 || hp->id == 3)
                {
                    vd.x = hp->d;
                    vd.z = hp->w;
                } 
                else
                {
                    vd.x = -hp->d;
                    vd.z = -hp->w;
                }
                
                vd.y = 0.0f;
                njUnitVector(&vd);
            
                vd.x = vd.x * ar;
                vd.z = vd.z * ar;
            
                area[0].x = hp->px + hp->w - vd.x;
                area[0].y = 0.0f;
                area[0].z = hp->pz - vd.z;
            
                area[1].x = hp->px - vd.x;
                area[1].y = 0.0f;
                area[1].z = hp->pz + hp->d - vd.z;
            
                area[2].x = area[1].x + 2.0f * vd.x;
                area[2].y = 0.0f;
                area[2].z = area[1].z + 2.0f * vd.z;
            
                area[3].x = area[0].x + 2.0f * vd.x;
                area[3].y = 0.0f;
                area[3].z = area[0].z + 2.0f * vd.z;
            
                if (bhInOutCheck(pos, area, NULL, 4))
                {
                    ln.px = area[2].x;
                    ln.py = 0.0f;
                    ln.pz = area[2].z;
                    ln.vx = hp->w;
                    ln.vy = 0.0f;
                    ln.vz = -hp->d;
            
                    njDistanceP2L(pos, &ln, &pd);
            
                    pos->x = pd.x;
                    pos->z = pd.z;        
                } 
                else
                {
                    px = pos->x - hp->px;
                    t = hp->d + (px * -hp->d) / hp->w;
                    switch (hp->id)
                    {
                    case 0:
                    case 2:
                        if (t < pos->z - hp->pz)
                        {
                            return 0;
                        }                                
                        break;
                    case 1:
                    case 3:
                        if (t > pos->z - hp->pz)
                        {
                            return 0;
                        }                                
                        break;
                    }
                
                    bhp.type = 0;
                    bhp.w = fabsf(hp->w);
                    bhp.d = fabsf(hp->d);
                    bhp.h = hp->h;
                
                    switch (hp->id)
                    {
                    case 0:
                        bhp.px = hp->px;
                        bhp.py = hp->py;
                        bhp.pz = hp->pz;
                        break;
                        
                    case 1:
                        bhp.px = hp->px;
                        bhp.py = hp->py;
                        bhp.pz = hp->pz + hp->d;
                        break;
                        
                    case 2:
                        bhp.px = hp->px + hp->w;
                        bhp.py = hp->py;
                        bhp.pz = hp->pz;
                        break;
                        
                    case 3:
                        bhp.px = hp->px + hp->w;
                        bhp.py = hp->py;
                        bhp.pz = hp->pz + hp->d;
                        break;
                    }
                    if (bhEne03_CollisionWallBox(&bhp, pos, ar))
                    {
                        return 1;
                    }
                }              
            }
            return 1;
        }                    
    } 
        
    return 0;
}

// 100% matching! 
int bhEne03_CollisionBoxEdge(ATR_WORK* hp, NJS_VECTOR* pos, float ar)
{
	ATR_WORK ht;
	float h2;
	float r;
    float h1;
	int ret;

	r = ar * 2.0f;
	ret = 0;

	if (hp->type == 7)
	{
		h1 = hp->py;
		h2 = h1 + hp->h;
	}
	else
	{
		if (hp->h)
        {
			h1 = hp->py + hp->h;            
        }
        else
        {
            h1 = hp->py + rom->h;            
        }			
		h2 = hp->py;
	}

	ht.type = 0;

	ht.px = hp->px;
	ht.py = h1;
	ht.pz = hp->pz - r;
	ht.w = hp->w;
	ht.h = r;
	ht.d = r;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	ht.px = hp->px;
	ht.py = h1;
	ht.pz = hp->pz + hp->d;
	ht.w = hp->w;
	ht.h = r;
	ht.d = r;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	ht.px = hp->px - r;
	ht.py = h1;
	ht.pz = hp->pz;
	ht.w = r;
	ht.h = r;
	ht.d = hp->d;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	ht.px = hp->px + hp->w;
	ht.py = h1;
	ht.pz = hp->pz;
	ht.w = r;
	ht.h = r;
	ht.d = hp->d;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	h1 -= h2;

	ht.px = hp->px - r;
	ht.py = h2;
	ht.pz = hp->pz - r;
	ht.w = r;
	ht.h = h1;
	ht.d = r;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	ht.px = hp->px + hp->w;
	ht.py = h2;
	ht.pz = hp->pz - r;
	ht.w = r;
	ht.h = h1;
	ht.d = r;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	ht.px = hp->px - r;
	ht.py = h2;
	ht.pz = hp->pz + hp->d;
	ht.w = r;
	ht.h = h1;
	ht.d = r;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	ht.px = hp->px + hp->w;
	ht.py = h2;
	ht.pz = hp->pz + hp->d;
	ht.w = r;
	ht.h = h1;
	ht.d = r;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	ht.type = 0;
	h2 -= r;

	ht.px = hp->px;
	ht.py = h2;
	ht.pz = hp->pz - r;
	ht.w = hp->w;
	ht.h = r;
	ht.d = r;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	ht.px = hp->px;
	ht.py = h2;
	ht.pz = hp->pz + hp->d;
	ht.w = hp->w;
	ht.h = r;
	ht.d = r;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	ht.px = hp->px - r;
	ht.py = h2;
	ht.pz = hp->pz;
	ht.w = r;
	ht.h = r;
	ht.d = hp->d;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	ht.px = hp->px + hp->w;
	ht.py = h2;
	ht.pz = hp->pz;
	ht.w = r;
	ht.h = r;
	ht.d = hp->d;
	ret |= bhEne03_CollisionWallBox(&ht, pos, ar);

	return ret;
}

// 100% matching!
int bhEne03_CollisionBoxEdge2(BH_PWORK* epw)
{
	NJS_POINT3 p[4];
	NJS_POINT3 p2[4];
	int i;
	float dx;
	float dy;
	float dz;

    // not present in DWARF
    float tmp = 999.0f;

	switch (EXP0_C(0x69))
	{
	case 0:
		dx = 0.0f;
		dy = -tmp;
		dz = 0.0f;
        p[0].x = epw->px - tmp;
		p[0].z = epw->pz - tmp;
		p[1].x = epw->px - tmp;
		p[1].z = epw->pz + tmp;
		p[2].x = epw->px + tmp;
		p[2].z = epw->pz - tmp;
		p[3].x = epw->px + tmp;
		p[3].z = epw->pz + tmp;
        p[0].y = p[1].y = p[2].y = p[3].y = epw->py;
		break;

	case 1:
		dx = 0.0f;
		dy = tmp;
		dz = 0.0f;
        p[0].x = epw->px - tmp;
		p[0].z = epw->pz - tmp;
		p[1].x = epw->px - tmp;
		p[1].z = epw->pz + tmp;
		p[2].x = epw->px + tmp;
		p[2].z = epw->pz - tmp;
		p[3].x = epw->px + tmp;
		p[3].z = epw->pz + tmp;
        p[0].y = p[1].y = p[2].y = p[3].y = epw->py;
		break;

	case 4:
        dx = tmp;
		dy = 0.0f;
		dz = 0.0f;
        p[0].y = epw->py - tmp;
		p[0].z = epw->pz - tmp;
		p[1].y = epw->py - tmp;
		p[1].z = epw->pz + tmp;
		p[2].y = epw->py + tmp;
		p[2].z = epw->pz - tmp;
		p[3].y = epw->py + tmp;
		p[3].z = epw->pz + tmp;
        p[0].x = p[1].x = p[2].x = p[3].x = epw->px;
		break;
                        
    case 2:
		dx = -tmp;
		dy = 0.0f;
		dz = 0.0f;
        p[0].y = epw->py - tmp;
		p[0].z = epw->pz - tmp;
		p[1].y = epw->py - tmp;
		p[1].z = epw->pz + tmp;
		p[2].y = epw->py + tmp;
		p[2].z = epw->pz - tmp;
		p[3].y = epw->py + tmp;
		p[3].z = epw->pz + tmp;
        p[0].x = p[1].x = p[2].x = p[3].x = epw->px;
		break;
        
    case 3:
		dx = 0.0f;
		dy = 0.0f;
        dz = tmp;
        p[0].x = epw->px - tmp;
		p[0].y = epw->py - tmp;
		p[1].x = epw->px - tmp;
		p[1].y = epw->py + tmp;
		p[2].x = epw->px + tmp;
		p[2].y = epw->py - tmp;
		p[3].x = epw->px + tmp;
		p[3].y = epw->py + tmp;
        p[0].z = p[1].z = p[2].z = p[3].z = epw->pz;
		break;

	case 5:
		dx = 0.0f;
		dy = 0.0f;
        dz = -tmp;
        p[0].x = epw->px - tmp;
		p[0].y = epw->py - tmp;
		p[1].x = epw->px - tmp;
		p[1].y = epw->py + tmp;
		p[2].x = epw->px + tmp;
		p[2].y = epw->py - tmp;
		p[3].x = epw->px + tmp;
		p[3].y = epw->py + tmp;
        p[0].z = p[1].z = p[2].z = p[3].z = epw->pz;
		break;
	}
    
	for (i = 0; i < 4; i++)
	{
		p2[i].x = dx + p[i].x;
		p2[i].y = dy + p[i].y;
		p2[i].z = dz + p[i].z;

		if (bhCollisionCheckLine(&p[i], &p2[i]) == 0)
        {
            *(ATR_WORK **)(epw->exp0 + 0x60) = bhEne03_GetWall(epw);
    		if (*(ATR_WORK **)(epw->exp0 + 0x60) != NULL)
            {
                bhEne03_CollisionBoxEdge(*(ATR_WORK **)(epw->exp0 + 0x60), (NJS_POINT3*)&epw->px, epw->ar);
                break;
            }    			
        }         
	}
	return 0;
}

// 100% matching!
void bhEne03_CollisionLine(BH_PWORK* epw)
{
	NJS_VECTOR n;
	ATR_WORK* hp;

    hp = bhCollisionCheckLine((NJS_VECTOR*) &epw->pxb, (NJS_VECTOR*) &epw->px);
    if (hp != NULL)
    {        
        bhGetHitCollisionNormal(&n);
        if (((*(ATR_WORK **)((char *)epw->exp0 + (0x60))) == NULL) && (n.y > 0.0f))
        {
            (*(ATR_WORK **)((char *)epw->exp0 + (0x60))) = hp;
        }
    }
}

// 100% matching!
void bhEne03_CollisionLine2(BH_PWORK* epw)
{
    NJS_VECTOR v;

    v.x = 0.01f * EXP0_F(0x10);
    v.y = 0.01f * EXP0_F(0x14);
    v.z = 0.01f * EXP0_F(0x18);
    
    njAddVector((NJS_VECTOR*) &epw->pxb, &v);
    njAddVector((NJS_VECTOR*) &epw->px, &v);
    
    bhCollisionCheckLine((NJS_VECTOR*) &epw->pxb, (NJS_VECTOR*) &epw->px);
    
    njSubVector((NJS_VECTOR*) &epw->pxb, &v);
    njSubVector((NJS_VECTOR*) &epw->px, &v);
}

// 100% matching!
void bhEne03_SetModelFlg(BH_PWORK* epw, unsigned int and_flg, unsigned int or_flg)
{
	O_WORK* owk;
	unsigned int i;

    owk = epw->mlwP->owP;

    for (i = 0; i < epw->mnwP->obj_num; i++, owk++)
    {
        owk->flg &= and_flg;
        owk->flg |=  or_flg;
    }
}

// 100% matching!
void bhEne03_AddNullTrans(BH_PWORK* epw, NJS_VECTOR* mtn)
{
	NJS_VECTOR v;

    njCalcVector((NJS_MATRIX*)epw->exp0, &mtn[epw->frm_no / 65536], &v);

    epw->px += v.x;
    epw->pz += v.z;
}

// 100% matching!
int bhEne03_CheckClimbWall()
{
	return 0;
}

// 100% matching!
int bhEne03_CheckClimbDownWall()
{
	return 0;
}

// 100% matching!
int bhEne03_AvoidWall()
{
	return 0;
}

// 99.83% matching
int bhEne03_DiveSpace(BH_PWORK* epw)
{
    NJS_POINT3 pos; 
    BH_PWORK* ep;   
    NJS_MKEY* mkfP;
    float dist;    
    int i;        

    if ((EPW_EXP1_I(0) & 0x3)) 
    {
        return 0;
    }

    mkfP =  epw->mnwP[13].md2P->p[0];
    mkfP += epw->mnwP[13].frm_num - 1;
    
    njCalcVector((NJS_MATRIX*)epw->exp0, (NJS_VECTOR*)&mkfP->key[0], &pos); 

    pos.x += epw->px;
    pos.y += epw->py;
    pos.z += epw->pz;

    dist = ((pos.x - plp->px) * (pos.x - plp->px)) + ((pos.z - plp->pz) * (pos.z - plp->pz));

    if (dist < 25.0f)
    {
        return 0;
    }

    ep = ene;

    for (i = 0; i < sys->ewk_n; i++, ep++)
    {
        if (((ep->flg & 0x1)) && (ep->id == 3) && (ep != epw))
        {
            dist = ((pos.x - ep->px) * (pos.x - ep->px)) + ((pos.z - ep->pz) * (pos.z - ep->pz));
            
            if (dist < 10.0f)
            {
                return 0;
            }
        }
    }

    pos.y = bhGetGroundPosition(&pos);

    if (bhCheckWallType(&pos, 0, 5.0f, (epw->py - pos.y) - 10.0f) != NULL) 
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}

// 100% matching!
int bhEne03_GetWallDir(NJS_VECTOR* v)
{
    if (v->y >= 0.9f)
    {
        return 0;
    }    
    else if (v->y <= -0.9f)
    {
        return 1;
    }

    if (v->x >= 0.9f)
    {
        return 2;
    }    
    else if (v->x <= -0.9f)
    {
        return 4;
    }

    if (v->z >= 0.9f)
    {
        return 5;
    }    
    else if (v->z <= -0.9f)
    {
        return 3;
    }
}

// 100% matching!
void bhEne03_DamageInit(BH_PWORK* epw) 
{
    int i;     
    int pno, num;     
    O_WORK* owk; 
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
        if (epw->type == 0) 
        {
            if ((epw->comb_flg & 0x8)) 
            {
                EXP0_I(124) -= epw->total_dam;
            } 
            else 
            {
                if ((EXP0_C(105) == 0) && (!(plp->at_flg & 0x8))) 
                {
                    EXP0_I(124) -= epw->total_dam;
                }
                
                epw->hp -= epw->total_dam;
            }
        } 
        else
        {
            epw->hp -= epw->total_dam;
        }
        
        if (epw->wpnr_no == 20) 
        {
            epw->hp = -1;
        }
        
        if ((epw->wpnr_no == 17) && (!(epw->flg2 & 0x4))) 
        {
            return;
        }
        
        bhEne03_HitMark(epw);
        
        if ((epw->total_dam > 15) && ((-rand() / -2147483648.0f) < 0.3f)) 
        {
            switch (epw->wpnr_no) 
            {
            case 11:
            case 20:
            case 14:
            case 15:
            case 16:
                pno = rand() % 8;

                num = 0;
                
                if (pno < 4)
                {
                    for (i = 0; i < 4; i++) 
                    {
                        num += ((unsigned char*)epw->exp0)[i + 160];
                    }
                } 
                else 
                {
                    for (i = 4; i < 8; i++) 
                    {
                        num += ((unsigned char*)epw->exp0)[i + 160];
                    }
                }
        
                if ((num == 0) && (((unsigned char*)epw->exp0)[160 + pno] == 0) && (((pno != 0) && (pno != 4)) || ((pno == 0) && (EXP0_UC(164) == 0)) || ((pno == 4) && (EXP0_UC(160) == 0)))) 
                {
					((unsigned char*)epw->exp0)[160 + pno] = 1;
					
					owk = epw->mlwP->owP;
					
					owk[BrokenParts[pno]].flg     |= 0x3;
					owk[BrokenParts[pno] + 1].flg |= 0x2;
					owk[BrokenParts[pno] + 2].flg |= 0x2;
	
					EXP0_BYTE(pno, 12) = 1;
					EXP0_BYTE(pno, 14) = 0;
					EXP0_BYTE(pno, 15) = 0;
					
					EXP0_INT(pno, 980) = EXP0_C(105);
	
					epw->mdflg |= 0x20;
					
					bhEne_SetMinceEffect(epw,   2, 3);
					bhEne_SetMinceEffect(epw, 259, 2);
					
					bhEne_SetBloodstain(epw, 2, BrokenParts[pno], NULL);
				}
                
                break;
            }
        }
        
        if (epw->hp < 0) 
        {
            epw->flg |=  0x2;
            epw->flg &= ~0x20;
            
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8977);
            
            epw->mode0 = 4;
            epw->mode1 = 0;
            epw->mode3 = 0;
            
            if (epw->type == 0) 
            {
                if (epw->wpnr_no == 20)
                {
                    epw->mode2 = 3;
                } 
                else if ((epw->flg & 0x80000)) 
                {
                    if ((EXP0_C(105) == 0) || (EXP0_C(106) == 0)) 
                    { 
                        epw->mode2 = 4; 
                    } 
                    else 
                    { 
                        epw->mode2 = 1; 
                    } 
                } 
                else 
                {
                    switch (EXP0_C(105)) 
                    {
                    case 0:
                        switch (epw->wpnr_no) 
                        {
                        case 5:
                        case 6:
                        case 11:
                        case 20:
                        case 14:
                        case 15:
                        case 16:
                            epw->mode2 = 0;
                            break;
                        default:
                            epw->mode2 = 5;
                            break;
                        }
                        
                        break;
                    case 1:
                        epw->mode2 = 2;
                        break;
                    default:
                        epw->mode2 = 1;
                        break;
                    }
                }
            } 
            else 
            {
                if (epw->total_dam > 25) 
                {
                    epw->mode2 = 3;
                }
                else if ((epw->flg & 0x80000)) 
                {
                    if ((EXP0_C(105) == 0) || (EXP0_C(106) == 0)) 
                    { 
                        epw->mode2 = 4; 
                    }
                    else 
                    { 
                        epw->mode2 = 1; 
                    } 
                }
                else
                {
                    switch (EXP0_C(105)) 
                    {
                    case 0:
                        if (EXP0_I(96) != 0) 
                        { 
                            epw->mode2 = 5; 
                        } 
                        else 
                        { 
                            epw->mode2 = 4; 
                        } 
                        
                        break;
                    case 1:
                        epw->mode2 = 2;
                        break;
                    default:
                        epw->mode2 = 1;
                        break;
                    }
                }
            }
            
            if ((epw->flg & 0x80000)) 
            {
                *(int*)epw->exp1 &= 0x2;
            }
            
            bhEne03_DeadMode2[epw->mode2](epw);
            return;
        }
        
        if (epw->type == 0) 
        {
            flg = 0;
            
            if (EXP0_I(124) < 0) 
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
                if (epw->total_dam < 30) 
                {
                    return;
                }
                
                if (epw->total_dam < 50)
                {
                    epw->mode2 = 1;
                } 
                else 
                {
                    epw->mode2 = (EXP0_C(105) == 1) ? 2 : 3;
                }
            }
            
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8976);
            
            if ((epw->flg & 0x80000)) 
            {
                if (epw->mlwP->owP->mtx[5] > 0) 
                {
                    epw->mode2 = 11; 
                } 
                else 
                { 
                    epw->mode2 = 12; 
                }
            }
            
            if (EXP0_I(96) == 0) 
            {
                epw->mode2 = 10;
            }
        } 
        else 
        {
            if (epw->total_dam < 30) 
            {
                return;
            }
            
            if (epw->total_dam < 50) 
            {
                epw->mode2 = 6;
            } 
            else 
            {
                if (EXP0_C(105) == 0) 
                {
                    if ((epw->comb_flg & 0x4)) 
                    { 
                        epw->mode2 = 9; 
                    } 
                    else 
                    {
                        epw->mode2 = 8;
                    } 
                } 
                else 
                {
                    epw->mode2 = 7;
                }
            }
            
            if ((epw->flg & 0x80000)) 
            {
                epw->mode2 = 11;
            }
            
            if (EXP0_I(96) == 0) 
            {
                epw->mode2 = 10;
            }
        }
        
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode3 = 0;
        
        if ((epw->flg & 0x80000)) 
        {
            *(int*)epw->exp1 &= 0x2;
        }
        
        bhEne03_DamageMode2[epw->mode2](epw);
    }
}

// 100% matching!
int bhEne03_CheckJumpSpace(BH_PWORK* epw)
{
    NJS_POINT3 p1, p2; 
    float dist;   
    BH_PWORK* ep;  
    int i;         

    if (EXP0_C(105) == 0) 
    {
        dist = epw->px; // may be fake, but matches
        
        p1.x = dist    - (20.0f * EXP0_F(32));
        p1.y = epw->py - (20.0f * EXP0_F(36));
        p1.z = epw->pz - (20.0f * EXP0_F(40)); 
        
        p2.x = epw->px;
        p2.y = epw->py;
        p2.z = epw->pz;
        
        for (i = 0; i < 5; i++) 
        {
            p2.x -= 4.0f * EXP0_F(32);
            p2.z -= 4.0f * EXP0_F(40);
            
            if (bhCheckWallType(&p2, 0, 5.0f, 15.0f) != 0) 
            {
                return 0;
            }
        }
    }
    else 
    {
        dist = epw->px;
        
        p1.x = dist    + (10.0f * EXP0_F(16));
        p1.y = epw->py + (10.0f * EXP0_F(20));
        p1.z = epw->pz + (10.0f * EXP0_F(24));
        
        p1.y = bhGetGroundPosition(&p1);
        
        if (bhCheckWallType(&p1, 0, 5.0f, 10.0f) != 0) 
        {
            return 0;
        }
        
        p1.y += 1.0f;
        
        p2.x = epw->px;
        p2.y = epw->py + 1.0f;
        p2.z = epw->pz;
        
        if (bhCollisionCheckLine(&p2, &p1) != 0) 
        {
            return 0;
        }
    }

    if ((((18.0f + plp->py) + epw->ar) > p1.y) && ((plp->py - epw->ar) < p1.y)) 
    {
        dist = njSqrt(((p1.x - plp->px) * (p1.x - plp->px)) + ((p1.z - plp->pz) * (p1.z - plp->pz)));
        
        if (dist < 10.0f) 
        {
            return 0;
        }
    }

    ep = ene;
    
    for (i = 0; i < sys->ewk_n; i++, ep++) 
    {
        if ((((ep->flg & 0x1)) && (ep->id == 3) && (ep != epw)) && (njDistanceP2P(&p1, (NJS_POINT3*)&ep->px) < 10.0f))
        {
            return 0;
        }
    }

    return 1;
}

#pragma divbyzerocheck on 

// 100% matching!
void bhEne03_PlayerControl(BH_PWORK* epw) 
{
    float px, pz; // not from DWARF

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
                
                plp->ct1 = 8;
                
                if (plp->mode2 == 0)
                {
                    plp->mtn_no = (sys->ply_id * 14) + 62;
                }
                else
                {
                    plp->mtn_no = (sys->ply_id * 14) + 65;
                }
                
                plp->mnwP = epw->mnwP;
                
                plp->frm_no = 0;
                
                plp->hokan_count = 3;
                plp->hokan_rate  = 32768;
                
                plp->mtn_add = 65536;
                
                plp->ct0 = plp->mnwP[plp->mtn_no].frm_num;
                
                bhEne_CallPlayerVoice(2);
                
                StartVibrationEx(1, 11);
                
                plp->mode3++;
            case 1:                                 
                if (plp->ct1 != 0) 
                {
                    plp->ay += (short)(plp->ayp - plp->ay) / plp->ct1;
                }
                
                if (plp->ct0-- == 0) 
                {
                    if (plp->mode2 == 0)
                    {
                        plp->mtn_no = (sys->ply_id * 14) + 63;
                    } 
                    else 
                    {
                        plp->mtn_no = (sys->ply_id * 14) + 66;
                    }
                    
                    plp->frm_no = 0;
                    
                    plp->mode3++;
                }
                
                break;
            case 2:                                 
                if (plp->ct1 != 0) 
                {
                    plp->ay += (short)(plp->ayp - plp->ay) / plp->ct1;
                }
                
                break;
            }
            
            break;
        case 2:                                     
        case 3:                                     
            switch (plp->mode3) 
            {                 
            case 0:                                 
                plp->flg &= ~0x40000;
                
                plp->flg  |= 0x10000;
                plp->flg2 |= 0x1;
                
                plp->ct0 = 8;
                
                if (plp->mode2 == 2) 
                {
                    plp->mtn_no = (sys->ply_id * 14) + 58;
                } 
                else 
                {
                    plp->mtn_no = (sys->ply_id * 14) + 59;
                }
                
                plp->mnwP = epw->mnwP;
                
                plp->frm_no = 0;
                
                plp->hokan_count = 3;
                plp->hokan_rate  = 32768;
                
                plp->mtn_add = 65536;
                
                plp->mode3++;
                break;
            case 1:                                 
                if (plp->ct0 != 0)
                {
                    plp->ay += (short)(plp->ayp - plp->ay) / plp->ct0;
                }
                
                if (plp->frm_no == 0) 
                {
                    if (plp->mode2 == 2)
                    {
                        plp->mtn_no = (sys->ply_id * 14) + 60;
                    } 
                    else 
                    {
                        plp->mtn_no = (sys->ply_id * 14) + 61;
                    }
                    
                    plp->frm_no = 0;
                    
                    plp->mode3++;
                }
                
                if ((plp->frm_no / 65536) == 4) 
                {
                    bhEne_CallPlayerVoice(2);
                    
                    StartVibrationEx(1, 11);
                }
                
                break;
            case 2:                                 
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
        case 4:                                     
        case 5:                                     
            switch (plp->mode3) 
            {                  
            case 0:                              
                plp->flg &= ~0x40000;
                plp->flg |=  0x10000;
                
                if (plp->mode2 == 4) 
                {
                    plp->mtn_no = (sys->ply_id * 14) + 64;
                } 
                else 
                {
                    plp->mtn_no = (sys->ply_id * 14) + 67;
                }
                
                plp->mnwP = epw->mnwP;
                
                plp->frm_no = 0;
                
                plp->mode3++;
                break;
            case 1:                              
                if (plp->frm_no == 0) 
                {
                    plp->mnwP = plp->mnwPb;
                    
                    plp->flg  &= ~0x10004;
                    plp->flg2 &= ~0x1;
                    
                    plp->flg |= 0x8;
                    
                    plp->at_flg = 0;
                    
                    plp->stflg &= ~0x10000;
                    
                    *(int*)&plp->mode0 = 1;
                    
                    EPW_EXP1_I(0) &= ~0x4;
                }
                
                break;
            }
            
            break;
        }
        
        px = plp->mlwP->owP[5].mtx[12] - plp->px;
        pz = plp->mlwP->owP[5].mtx[14] - plp->pz;
        
        plp->px += px;
        plp->pz += pz;
        
        bhCheckWall(plp);
        
        plp->px -= px;
        plp->pz -= pz;
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
                plp->flg |=  0x10000;
                
                plp->ct1 = 10;
                
                if (plp->mode2 == 0) 
                {
                    plp->mtn_no = (sys->ply_id * 14) + 71;
                } 
                else
                {
                    plp->mtn_no = (sys->ply_id * 14) + 70;
                }
                
                plp->mnwP = epw->mnwP;
                
                plp->frm_no = 0;
                
                plp->hokan_count = 3;
                plp->hokan_rate  = 32768;
                
                plp->mtn_add = 65536;
                
                plp->ct0 = plp->mnwP[plp->mtn_no].frm_num - 1;
                
                bhEne_CallPlayerVoice(1);
                
                StartVibrationEx(1, 11);
                
                plp->mode3++;
            case 1:                                 
                if (plp->ct0-- == 0) 
                {
                    plp->mtn_add = 0;
                }
                
                break;
            }
            
            break;
        case 2:                                     
        case 3:                                     
            switch (plp->mode3) 
            {                   
            case 0:                                 
                plp->flg &= ~0x40000;
                plp->flg |=  0x10000;
                
                plp->ct1 = 10;
                
                if (plp->mode2 == 2) 
                {
                    plp->mtn_no = (sys->ply_id * 14) + 68;
                }
                else 
                {
                    plp->mtn_no = (sys->ply_id * 14) + 69;
                }
                
                plp->mnwP = epw->mnwP;
                
                plp->frm_no = 0;
                
                plp->hokan_count = 3;
                plp->hokan_rate  = 32768;
                
                plp->mtn_add = 65536;
                
                plp->ct0 = plp->mnwP[plp->mtn_no].frm_num - 1;
                
                bhEne_CallPlayerVoice(1);
                
                StartVibrationEx(1, 11);
                
                plp->mode3++;
            case 1:                                 
                if (plp->ct0-- == 0) 
                {
                    plp->mtn_add = 0;
                }
                
                break;
            }
            
            break;
        }
    }
}

#pragma divbyzerocheck off

// 100% matching!
void bhEne03_CallSE(BH_PWORK* epw) 
{
    int fno;

    if (epw->mnwP == epw->mnwPb) 
    {
        fno = epw->frm_no / 65536;
        
        switch (epw->mtn_no) 
        {                     
        case 1:
        case 31:
            if ((fno == 0) || (fno == 9) || (fno == 14)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
            }
            
            break;
        case 2:
        case 3:
        case 32:
        case 33:
            if ((fno == 8) || (fno == 20) || (fno == 28) || (fno == 34)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
            }
            
            break;
        case 6:
        case 7:
            if ((fno == 7) || (fno == 13) || (fno == 18)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
            }
            
            break;
        case 4:
            if ((fno == 0) || (fno == 7)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
            }
            
            break;
        case 37:
            if ((fno == 0) || (fno == 7)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
            }
            
            break;
        case 40:
            if ((fno == 2) || (fno == 6)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
            }
            
            break;
        case 8:
            if (fno == 10) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74500);
            }
            
            break;
        case 9:
            if (fno == 20) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74501);
            }
            
            break;
        case 10:
            if (fno == 30) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74502);
            }
            
            break;
        case 15:
            if (fno == 0) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74510);
            }
            
            break;
        case 18:
            if (fno == 0) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8978);
            }
            
            break;
        case 23:
            if (fno == 10) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8978);
            }
            
            break;
        case 25:
            if ((fno == 35) || (fno == 50)) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74501);
            }
            
            break;
        case 22:
            if (fno == 0) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8980);
            }
            
            break;
        case 41:
            if (fno == 13) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74517);
            }
            
            break;
        case 49:
            if (fno == 1) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74518);
            }
            
            break;
        case 44:
            if (fno == 15) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74519);
            }
            
            if (fno == 43) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74501);
            }
            
            break;
        case 46:
            if (fno == 20) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74502);
            }
            
            break;
        case 55:
            if ((fno == 185) || (fno == 195) || (fno == 210))
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74501);
            }
            
            break;
        }
    }
}

// 99.96% matching
void bhEne03_Acid(BH_PWORK* epw, int type)
{
    int eno;   
    int i;      
    O_WORK* owk; 
    float dt;    
    NJS_POINT3 pos1, pos2; // not from DWARF

    owk = epw->mlwP->owP; 
    
    pos1.x = owk[36].mtx[12];
    pos1.y = owk[36].mtx[13];
    pos1.z = owk[36].mtx[14]; 
    
    pos1.x = (pos1.x + owk[35].mtx[12]) * 0.5f; 
    pos1.y = (pos1.y + owk[35].mtx[13]) * 0.5f;
    pos1.z = (pos1.z + owk[35].mtx[14]) * 0.5f; 

    if (type == 0) 
    {
        pos2.x = -2.5f * EXP0_F(32);
        pos2.y = -2.5f * EXP0_F(40); 
        pos2.z = (EXP0_C(105) == 0) ? 0.5f : 0.0f; 
    } 
    else 
    { 
        pos2.x = -0.5f * EXP0_F(32);
        pos2.y = -0.5f * EXP0_F(40);
        pos2.z = 2.5f;
    }

    sys->ef.id   = 256;
    sys->ef.type = (type != 0) ? 5 : 1;
    
    sys->ef.flg = 1;
    
    sys->ef.px = pos1.x;
    sys->ef.py = pos1.y;
    sys->ef.pz = pos1.z;
    
    for (i = 0; i < 8; i++) 
    {
        dt = 0.5f + (-rand() / -2.1474836E9f);
        
        sys->ef.sx = dt;
        sys->ef.sy = dt;
        sys->ef.sz = dt;
        
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        
        if (eno != -1) 
        {
            eff[eno].stflg |= 0x20; 
            
            eff[eno].txp[0] = epw->mdl[1].texP; 
            eff[eno].tex_id = 1; 

            eff[eno].xn = pos2.x; 
            eff[eno].yn = pos2.z; 
            eff[eno].zn = pos2.y;
            
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
void bhEne03_HitMark(BH_PWORK* epw)
{
    int i;          
    int range;      
    NJS_POINT3 ofp; 
    BLOOD_TBL* blp;

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
            
            bhEne_SetFireEffect(epw, epw->djnt_no, &ofp, 0.5f + (0.5f * (-rand() / -2.1474836E9f)), (rand() % 40) + 20);
        } 
    }
    
    if ((DmgReact[epw->wpnr_no].exef & 0x2)) 
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
        
        epw->mdflg |= 0x400;
    }
}
