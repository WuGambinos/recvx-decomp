#include "../../../ps2/veronica/prog/en30.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/en03.h"
#include "../../../ps2/veronica/prog/macros.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/effect.h"

// ENEMY: Alexia's Baby 

/*typedef struct npobj;
typedef struct _anon0;
typedef struct BH_PWORK;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;
typedef struct _anon7;
typedef struct _anon8;
typedef struct _anon9;
typedef struct _anon10;
typedef struct _anon11;
typedef struct _anon12;
typedef struct _anon13;
typedef struct _anon14;
typedef struct _anon15;
typedef struct _anon16;
typedef struct _anon17;
typedef struct _anon18;
typedef struct _anon19;
typedef struct _anon20;
typedef struct _anon21;
typedef struct _anon22;
typedef struct _anon23;
typedef struct _anon24;
typedef struct _anon25;
typedef struct _anon26;
typedef struct _anon27;
typedef struct _anon28;
typedef struct _anon29;
typedef struct _anon30;
typedef struct _anon31;
typedef struct _anon32;

typedef void(*type_8)(BH_PWORK*);
typedef void(*type_44)(BH_PWORK*);
typedef void(*type_69)(BH_PWORK*);
typedef void(*type_73)(BH_PWORK*);
typedef void(*type_78)(void*);
typedef void(*type_90)(BH_PWORK*);

typedef unsigned int type_0[4];
typedef _anon0* type_1[512];
typedef _anon0* type_2[32];
typedef _anon1* type_3[16];
typedef _anon0* type_4[32];
typedef _anon0* type_5[512];
typedef _anon1* type_6[16][16];
typedef _anon1* type_7[16][16][100];
typedef char type_9[8];
typedef void(*type_10)(BH_PWORK*)[8];
typedef _anon0* type_11[32];
typedef char type_12[3];
typedef _anon0* type_13[512];
typedef _anon1* type_14[1300];
typedef char type_15[32];
typedef _anon0* type_16[512];
typedef _anon1* type_17[200];
typedef short type_18[32];
typedef _anon14 type_19[1];
typedef _anon0* type_20[128];
typedef unsigned int type_21[1];
typedef _anon5 type_22[256];
typedef _anon1* type_23[8];
typedef int* type_24[16];
typedef _anon0* type_25[128];
typedef npobj* type_26[16];
typedef _anon0* type_27[128];
typedef int type_28[4];
typedef _anon1* type_29[16];
typedef unsigned int type_30[4];
typedef _anon8 type_31[16];
typedef _anon0* type_32[512];
typedef char type_33[256];
typedef float type_34[4];
typedef float type_35[4];
typedef float type_36[4];
typedef _anon4* type_37[128];
typedef unsigned char type_38[64];
typedef float type_39[16];
typedef char type_40[8];
typedef BH_PWORK type_41[0];
typedef void* type_42[2];
typedef _anon0 type_43[0];
typedef void(*type_45)(BH_PWORK*)[2];
typedef _anon1* type_46[256];
typedef int type_47[4];
typedef unsigned char* type_48[256];
typedef unsigned int type_49[2];
typedef short type_50[256];
typedef _anon20 type_51[4];
typedef float type_52[3];
typedef _anon15 type_53[3];
typedef short type_54[256];
typedef int type_55[3];
typedef int type_56[8];
typedef float type_57[3];
typedef _anon1* type_58[256];
typedef _anon7 type_59[256];
typedef _anon14 type_60[450];
typedef _anon22 type_61[16];
typedef short type_62[256];
typedef char type_63[3];
typedef int type_64[64];
typedef _anon8 type_65[450];
typedef _anon25 type_66[4];
typedef _anon2 type_67[4];
typedef int type_68[450];
typedef void(*type_70)(BH_PWORK*)[1];
typedef unsigned int type_71[8];
typedef unsigned char type_72[450];
typedef void(*type_74)(BH_PWORK*)[2];
typedef int type_75[16];
typedef char type_76[16];
typedef char type_77[4];
typedef unsigned int type_79[32];
typedef unsigned int type_80[16];
typedef _anon27 type_81[64];
typedef unsigned int type_82[16];
typedef _anon27 type_83[64];
typedef unsigned int type_84[32];
typedef _anon27 type_85[64];
typedef unsigned int type_86[16];
typedef unsigned int type_87[3];
typedef BH_PWORK* type_88[16];
typedef unsigned int type_89[8];
typedef void(*type_91)(BH_PWORK*)[6];
typedef unsigned int type_92[1];
typedef unsigned int type_93[384];
typedef unsigned int type_94[2];
typedef unsigned char type_95[2];
typedef unsigned int type_96[4];
typedef int* type_97[16];
typedef char type_98[32];
typedef npobj* type_99[16];
typedef char type_100[64];
typedef _anon1* type_101[16];
typedef char type_102[4];
typedef _anon8 type_103[16];
typedef short type_104[4];
typedef int type_105[3];
typedef unsigned char type_106[4];
typedef _anon23 type_107[16];
typedef unsigned int type_108[32];
typedef _anon3 type_109[32];
typedef _anon0* type_110[512];
typedef _anon0* type_111[128];
typedef int type_112[3];
typedef _anon0* type_113[512];
typedef unsigned char type_114[64];
typedef _anon0* type_115[512];

struct npobj
{
	unsigned int evalflags;
	_anon21* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
};

struct _anon0
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	char flr_no;
	char flr_nob;
	unsigned char mdlver;
	unsigned char param;
	unsigned char mode0;
	unsigned char mode1;
	unsigned char mode2;
	unsigned char mode3;
	float px;
	float py;
	float pz;
	int ax;
	int ay;
	int az;
	float ar;
	float aw;
	float ah;
	float ad;
	float car;
	float cah;
	float pxb;
	float pyb;
	float pzb;
	int axb;
	int ayb;
	int azb;
	float gpx;
	float gpy;
	float gpz;
	float lox;
	float loy;
	float loz;
	float aox;
	float aoy;
	float aoz;
	float spd;
	unsigned int flg2;
	unsigned int mdflg;
	unsigned int stflg;
	unsigned int Dummy3;
	int draw_tp;
	int mdl_n;
	void* mskp;
	unsigned int Dummy[1];
	int* skp[16];
	npobj* mbp[16];
	_anon1* txp[16];
	_anon8 mdl[16];
	_anon8* mlwP;
	unsigned int mdl_no;
	int lkono;
	unsigned char* lkwkp;
	unsigned char* exp0;
	unsigned char* exp1;
	unsigned char* exp2;
	unsigned char* exp3;
	unsigned char mtxbuf[64];
	float mtx[16];
	npobj* obj_a;
	npobj* obj_b;
	float shp_ct;
	char clp_jno[8];
	int lok_jno;
	_anon4* mnwP;
	_anon4* mnwPb;
	unsigned int mtn_attr;
	unsigned int mtn_no;
	int frm_no;
	unsigned int frm_mode;
	int hokan_rate;
	unsigned int hokan_count;
	unsigned int hokan_ctbak;
	int mtn_add;
	unsigned int mtn_md;
	unsigned char* mtn_tp;
	int axp;
	int ayp;
	int azp;
	short psh_ct;
	short psh_idx;
	int idx_ct;
	int mtn_chk;
	float ofx;
	float ofy;
	float ofz;
	float sx;
	float sy;
	float sz;
	float sxb;
	float syb;
	float szb;
	float xn;
	float yn;
	float zn;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
	unsigned char* objbak;
	_anon31 cspr;
	int pn;
	_anon25* pvp;
	_anon2* tvp;
	_anon25 pv[4];
	_anon2 tv[4];
	int bl_src;
	int bl_dst;
	int ani_ct;
	int tex_id;
	int aspd;
	unsigned int gidx;
	int bank;
	char jno[16];
	char hide[4];
	void(*func)(void*);
	int idx;
	int Dummy2;
};

struct BH_PWORK
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	char flr_no;
	char flr_nob;
	unsigned char mdlver;
	unsigned char param;
	unsigned char mode0;
	unsigned char mode1;
	unsigned char mode2;
	unsigned char mode3;
	float px;
	float py;
	float pz;
	int ax;
	int ay;
	int az;
	float ar;
	float aw;
	float ah;
	float ad;
	float car;
	float cah;
	float pxb;
	float pyb;
	float pzb;
	int axb;
	int ayb;
	int azb;
	float gpx;
	float gpy;
	float gpz;
	float lox;
	float loy;
	float loz;
	float aox;
	float aoy;
	float aoz;
	float spd;
	unsigned int flg2;
	unsigned int mdflg;
	unsigned int stflg;
	unsigned int Dummy3;
	int draw_tp;
	int mdl_n;
	void* mskp;
	unsigned int Dummy[1];
	int* skp[16];
	npobj* mbp[16];
	_anon1* txp[16];
	_anon8 mdl[16];
	_anon8* mlwP;
	unsigned int mdl_no;
	int lkono;
	unsigned char* lkwkp;
	unsigned char* exp0;
	unsigned char* exp1;
	unsigned char* exp2;
	unsigned char* exp3;
	unsigned char mtxbuf[64];
	float mtx[16];
	npobj* obj_a;
	npobj* obj_b;
	float shp_ct;
	char clp_jno[8];
	int lok_jno;
	_anon4* mnwP;
	_anon4* mnwPb;
	unsigned int mtn_attr;
	unsigned int mtn_no;
	int frm_no;
	unsigned int frm_mode;
	int hokan_rate;
	unsigned int hokan_count;
	unsigned int hokan_ctbak;
	int mtn_add;
	unsigned int mtn_md;
	unsigned char* mtn_tp;
	int axp;
	int ayp;
	int azp;
	short psh_ct;
	short psh_idx;
	int idx_ct;
	int mtn_chk;
	float ofx;
	float ofy;
	float ofz;
	float sx;
	float sy;
	float sz;
	float sxb;
	float syb;
	float szb;
	float xn;
	float yn;
	float zn;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
	int wpnr_no;
	int wpnl_no;
	unsigned int at_flg;
	_anon32 watr;
	_anon15* cpcl;
	short wax;
	short way;
	short waz;
	short waxp;
	short wayp;
	short wazp;
	int hp;
	int dam[64];
	int djnt_no;
	int cpcl_no;
	int dax;
	int day;
	float dpx;
	float dpy;
	float dpz;
	float dvx;
	float dvy;
	float dvz;
	int flr_snd;
	int ko_num;
	int footeff;
	int src_no;
	unsigned char* kdnp;
	int kdnidx;
	void* dan_ap;
	unsigned int comb_flg;
	unsigned int comb_wep;
	int comb_pnt;
	int comb_timeout;
	int total_dam;
	unsigned int Dummy2[2];
};

struct _anon1
{
	_anon14* textures;
	unsigned int nbTexture;
};

struct _anon2
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int col;
};

struct _anon3
{
	float x;
	float y;
	float z;
};

struct _anon4
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon13* md2P;
	unsigned short* atrP;
};

struct _anon5
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _anon6
{
	unsigned int Type;
	unsigned int BitDepth;
	unsigned int PixelFormat;
	unsigned int nWidth;
	unsigned int nHeight;
	unsigned int TextureSize;
	unsigned int fSurfaceFlags;
	unsigned int* pSurface;
	unsigned int* pVirtual;
	unsigned int* pPhysical;
};

struct _anon7
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct _anon8
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon1* texP;
	_anon18* owP;
};

struct _anon9
{
	unsigned int id;
	unsigned int support;
	unsigned int on;
	unsigned int off;
	unsigned int press;
	unsigned int release;
	unsigned short r;
	unsigned short l;
	short x1;
	short y1;
	short x2;
	short y2;
	char* name;
	void* extend;
	unsigned int old;
	_anon29* info;
};

struct _anon10
{
	unsigned int ssd_ver;
	unsigned int ssd_flg;
	unsigned int ssd_reserve;
	char keytype;
	char adjust_x;
	char adjust_y;
	char vibration;
	int best_tm[8];
	unsigned int sys_partid;
	unsigned int itm_partid;
	unsigned int fil_partid;
	unsigned int dor_partid;
	unsigned int ss_flg;
	int pdm_no;
	unsigned int typ_flg;
	unsigned short typ_md0;
	unsigned short typ_md1;
	void* typ_exp;
	unsigned int tk_flg;
	unsigned int ts_flg;
	unsigned int gm_flg;
	unsigned int st_flg;
	unsigned int cb_flg;
	unsigned int rm_flg;
	unsigned int pt_flg;
	unsigned int sp_flg;
	unsigned int ef_flg;
	unsigned int error;
	unsigned int version;
	int save_ct;
	char ply_id;
	char stg_no;
	char rom_no;
	char rcase;
	char pos_no;
	char cut_no;
	char flr_no;
	char reserve0;
	int gm_mode;
	unsigned int ev_flg[32];
	unsigned int it_flg[16];
	unsigned int ic_flg[16];
	unsigned int ed_flg[32];
	unsigned int ky_flg[16];
	unsigned int mp_flg[8];
	unsigned int itm[384];
	unsigned int ply_stflg[4];
	_anon3 ply_pos;
	int ply_ang;
	char ply_wno[4];
	short ply_hp[4];
	unsigned char evt_posno[4];
	int time;
	int stv_tm;
	short spray_ct;
	short retry_ct;
	short clear_ct;
	short reserve1;
	unsigned int save_end;
	char stg_nob;
	char rom_nob;
	char pos_nob;
	char rcase_b;
	unsigned int en_flg[4];
	_anon1* et_lp[16][16][100];
	_anon1* ot_lp[1300];
	_anon1* it_lp[200];
	int eft_n;
	_anon1* eft_lp[8];
	int loop_ct;
	int loop_now;
	int cng_pid;
	_anon9* p1per;
	_anon9* p2per;
	_anon9* kbper;
	_anon9* msper;
	_anon9 ms_per;
	int pad_port;
	unsigned int pad_on;
	unsigned int pad_oncpy;
	unsigned int pad_ps;
	unsigned int pad_rs;
	unsigned int pad_old;
	unsigned int pad_onb;
	unsigned int pad_psb;
	unsigned int pad_oldb;
	short pad_ax;
	short pad_ay;
	short pad_dx;
	short pad_dy;
	unsigned short pad_ar;
	unsigned short pad_al;
	int fixcno;
	int fixkno;
	unsigned int exm_attr;
	short evc_no;
	short evc_kn;
	short evc_ono;
	short evc_okn;
	int evc_sc;
	unsigned char mn_mode0;
	unsigned char mn_mode1;
	unsigned char mn_mode2;
	unsigned char mn_mode3;
	unsigned char mn_md0;
	unsigned char mn_md1;
	unsigned char mn_md2;
	unsigned char mn_md3;
	int mn_setct;
	unsigned int mn_stack[8];
	unsigned int sdm_flg;
	unsigned int sdm_mode;
	unsigned char* ltc_bp;
	unsigned int ltc_tsbak;
	int ewk_n;
	unsigned int enow;
	unsigned int onow;
	unsigned int efnow;
	int vsyc_ct;
	int vsyc_flg;
	int fog_ct;
	int bcl_ct;
	int gfrm_ct;
	int gframe;
	int eor_ct;
	unsigned int pfm_cts;
	int evt_tmd;
	int evt_tim;
	int evt_tdg;
	int evt_fcd;
	unsigned int evt_fcdct;
	unsigned int fsize;
	unsigned int rdtsz;
	unsigned char* memp;
	unsigned char* mempb;
	unsigned char* endp;
	unsigned char* rdtp;
	unsigned char* plmdlp;
	unsigned char* lmmdlp;
	unsigned char* wrmdlp;
	unsigned char* wlmdlp;
	unsigned char* plmthp;
	unsigned char* plbmtp;
	unsigned char* plwmtp;
	unsigned char* plzmtp;
	unsigned char* plemtp;
	unsigned char* plexwp;
	unsigned char* plhdwp;
	unsigned char* pletcp;
	unsigned char* subtxp;
	unsigned char* doordp;
	unsigned char* sbs_sp;
	_anon0* obwp;
	_anon0* itwp;
	_anon4* emtp[128];
	_anon4* rmthp;
	unsigned char* mspp;
	unsigned char* lspp;
	unsigned int* mes_ip;
	unsigned int* mes_sp;
	void* mes_tp;
	short txr_n;
	short txr_ct;
	_anon1* txlp[256];
	unsigned char* txdp[256];
	short txloff[256];
	short txb_ct;
	short txb_n;
	short txb[256];
	_anon1* txblp[256];
	_anon7 txbp[256];
	unsigned char* ef_psp;
	_anon14 ef_tex[450];
	_anon1 ef_tlist;
	_anon26 ef;
	short efid[256];
	_anon8 efm[450];
	int ef_ct;
	int ef_ctb;
	int ef_extn;
	int ef_tn[450];
	unsigned char ef_pbkb[450];
	int ef_pbnk;
	int ef_slow;
	int ef_ctrn;
	int yk_ct;
	int mg_ct;
	int bl_ct;
	int windr;
	float winds;
	int windrb;
	float windsb;
	unsigned int thunder;
	float gas_py;
	int en_objn;
	BH_PWORK* en_obj[16];
	int ef_poln;
	int ef_mdfn;
	int ef_linn;
	int ef_ntxn;
	int ef_trsn;
	int ef_pncn;
	int ef_opqn;
	int ef_thln;
	int ef_ntx2dn;
	int ef_trs2dn;
	int ef_pnc2dn;
	int ef_fncn;
	_anon0* ef_pol[512];
	_anon0* ef_mdf[128];
	_anon0* ef_lin[512];
	_anon0* ef_ntx[512];
	_anon0* ef_trs[512];
	_anon0* ef_pnc[512];
	_anon0* ef_opq[512];
	_anon0* ef_thl[512];
	_anon0* ef_ntx2d[128];
	_anon0* ef_trs2d[128];
	_anon0* ef_pnc2d[128];
	_anon0* ef_fnc[512];
	int ob_nlgn;
	int ob_hlgn;
	int ob_spcn;
	_anon0* ob_nlg[32];
	_anon0* ob_hlg[32];
	_anon0* ob_spc[32];
	unsigned int ren_gid;
	_anon12 ren_info;
	_anon14 ren_tex[1];
	_anon1 ren_tlist;
	_anon5 rpb[256];
	int ren_n;
	int ren_idx[4];
	int wt_nbpt;
	float wt_px;
	float wt_pz;
	int wt_xp;
	int wt_zp;
	int wt_minx;
	int wt_minz;
	int wt_maxx;
	int wt_maxz;
	unsigned char* wt_wvp;
	_anon28 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon16* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon20 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon22 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon27* pl_htp;
	int costume;
	_anon3 hd_pos;
	_anon3 apos;
	_anon27* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon27 mwalp[64];
	_anon27 metcp[64];
	_anon27 mflrp[64];
	int dla_n;
	_anon27* htp;
	int psh_snd;
	int fog_cngct;
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
	float fade_ct;
	float fade_hkn;
	float fade_ao;
	float fade_an;
	float fade_ap;
	float fade_ro;
	float fade_rn;
	float fade_rp;
	float fade_go;
	float fade_gn;
	float fade_gp;
	float fade_bo;
	float fade_bn;
	float fade_bp;
	unsigned int fade_pbk;
	unsigned short ssv_md0;
	unsigned short ssv_md1;
	int ssv_tim;
	float ssv_ct;
	float ssv_hkn;
	float ssv_ao;
	float ssv_an;
	float ssv_ap;
	short fil_no;
	short fil_rt;
	float rvf_sc;
	float rvf_sn;
	unsigned int rvfc[4];
	float cine_an;
	float cine_ap;
	unsigned int sco_flg;
	float amb_r[4];
	float amb_g[4];
	float amb_b[4];
	int sb_id;
	int sb_cmd;
	int sb_rdid;
	int sb_rdsz;
	void* sb_rdp;
	void* sb_mlb;
	void* sb_ppp;
	_anon1* sb_tlist;
	int ddmd;
	_anon11 door;
	int mpmd;
	int mp_prm[4];
	unsigned short gov_md0;
	unsigned short gov_md1;
	int gov_ct;
	void* gov_exp;
	unsigned int com_flg;
	unsigned short com_md0;
	unsigned short com_md1;
	unsigned int com_num;
	void* com_exp;
	short ond_tnm;
	short ond_ud;
	char ond_cx;
	char ond_n[3];
	unsigned char ufo_md;
	unsigned char ufo_flg;
	short ufo_oidx;
	_anon3 ufo_pos;
	unsigned int opt_flg;
	unsigned short opt_md0;
	unsigned short opt_md1;
	void* opt_exp;
	unsigned int etc_idx;
	unsigned int flr_idx;
	int mvi_no;
	int mvi_tp;
	unsigned short mvi_md;
	unsigned short mvi_flg;
	unsigned int mvi_tsb;
	unsigned int mvi_spb;
	unsigned char* mvi_memp;
	unsigned int dcg_tkbak;
	unsigned int dcg_tsbak;
	unsigned int pau_spbak;
	unsigned int pau_pad_on;
	unsigned int pau_pad_ps;
	unsigned int pau_pad_old;
	unsigned char* pdm_dp;
	unsigned char* pdm_pd;
	int pdm_keytpb;
	int gat_ct;
	_anon23 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon3 ghtp[32];
	unsigned short db_md0;
	unsigned short db_md1;
	char db_stgno;
	char db_romno;
	char db_rcase;
	char db_muteki;
	short db_px;
	short db_py;
	int db_mes;
	int calc_v;
	unsigned int brkfg;
	char brkfg_typ[32];
	short brkfg_bit[32];
	unsigned int brkfg_tkb;
	unsigned int brkfg_tsb;
	int brkfg_ct;
	unsigned int bmt_size;
	unsigned int lmt_size;
	unsigned int emt_size;
	unsigned int wmt_size;
	char mes[256];
	float sfx;
	float sfy;
	float sfxn;
	float sfyn;
	float sfct;
};

struct _anon11
{
	unsigned int flg;
	char stg_no;
	char rom_no;
	unsigned char pos_no;
	unsigned char dor_tp;
	unsigned char mode0;
	unsigned char mode1;
	unsigned char mode2;
	unsigned char mode3;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
};

struct _anon12
{
	void* texaddr;
	_anon6 texsurface;
};

struct _anon13
{
	void* p[2];
};

struct _anon14
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon15
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon16
{
	unsigned int flg;
	unsigned int type;
	int aspd;
	int lkflg;
	int lkno;
	int lkono;
	int lsrc;
	float px;
	float py;
	float pz;
	float lx;
	float ly;
	float lz;
	float vx;
	float vy;
	float vz;
	float spc;
	float dif;
	float amb;
	float r;
	float g;
	float b;
	float nr;
	float fr;
	int iang;
	int oang;
	int ax;
	int ay;
	int az;
	unsigned int mode;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
	float wpx;
	float wpy;
	float wpz;
	float wvx;
	float wvy;
	float wvz;
	float wspc;
	float wdif;
	float wamb;
	float wr;
	float wg;
	float wb;
	float wnr;
	float wfr;
	int wiang;
	int woang;
	int wax;
	int way;
	int waz;
	unsigned char* lkwkp;
	unsigned char* exp;
	_anon19* light;
};

struct _anon17
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon18
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon19
{
	float mtrx[16];
	_anon3 pnt;
	_anon3 vctr;
	int stat;
	int reserve;
	_anon24 ltcal;
	_anon30 attr;
};

struct _anon20
{
	_anon3 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon21
{
	int* vlist;
	short* plist;
	_anon3 center;
	float r;
};

struct _anon22
{
	float x;
	float y;
};

struct _anon23
{
	_anon3 c1;
	_anon3 c2;
	float r1;
	float r2;
};

struct _anon24
{
	float ratten;
	float ipd;
	float nrr;
	float frr;
	float cosi;
	float cose;
	float idev;
	float odev;
	float rate;
	float intns;
	int exp;
	int reserve;
	_anon3 lpnt;
	_anon3 lvctr;
	_anon3 lmvctr;
	_anon17 atten;
	_anon17 amb;
	_anon17 dif;
	_anon17 spc;
	_anon17 mamb;
	_anon17 mdif;
	_anon17 mspc;
};

struct _anon25
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon26
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	short flr_no;
	unsigned short mdlver;
	float px;
	float py;
	float pz;
	float sx;
	float sy;
	float sz;
	short ay;
	short ax;
};

struct _anon27
{
	unsigned char flg;
	unsigned char type;
	unsigned char id;
	char flr_no;
	unsigned int attr;
	float px;
	float py;
	float pz;
	float w;
	float h;
	float d;
	unsigned char prm0;
	unsigned char prm1;
	unsigned char prm2;
	unsigned char prm3;
};

struct _anon28
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon29
{
	unsigned int type;
	unsigned int reserved[3];
	unsigned char is_root;
	unsigned char area_code;
	unsigned char connector_dir[2];
	char product_name[32];
	char license[64];
	unsigned short stdby_pow;
	unsigned short max_pow;
};

struct _anon30
{
	int lsrc;
	float iamb;
	float idif;
	float ispc;
	float nrang;
	float frang;
	void* func;
	int iang;
	int oang;
	_anon17 argb;
};

struct _anon31
{
	_anon3 c;
	float r;
};

struct _anon32
{
	_anon3 c1;
	_anon3 c2;
	float r;
};
*/

int ENE30_HITPOINT[16] = {0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x14, 0x14};
char SdwTab[3] = {0x1, 0x4, 0xFF};
CPCL CapColTab[3] =
{
    { 0, 0, 16 },
    { 5, 0, 0},
    { 0, 0, 0},
};


/*void(*bhEne30_Mode0)(BH_PWORK*)[6];
void(*bhEne30_BrainType)(BH_PWORK*)[1];
void(*bhEne30_MoveMode2)(BH_PWORK*)[8];
void(*bhEne30_DamageMode2)(BH_PWORK*)[2];
void(*bhEne30_DeadMode2)(BH_PWORK*)[2];
BH_PWORK* plp;
_anon10* sys;
BH_PWORK ene[0];
_anon0 eff[0];*/

void(*bhEne30_Mode0[6])(BH_PWORK*) = {
    bhEne30_Init,
    bhEne30_Move, 
    bhEne30_Nage,
    bhEne30_Damage,
    bhEne30_Die,
    bhEne_Event,
};

void(*bhEne30_BrainType[2])(BH_PWORK*) = {
    bhEne30_BR00,
};

void(*bhEne30_MoveMode2[8])(BH_PWORK*) = {
    bhEne30_MV00,
    bhEne30_MV01,
    bhEne30_MV02,
    bhEne30_MV03,
    bhEne30_MV04,
    bhEne30_MV05,
    bhEne30_MV06,
    bhEne30_MV07,
};

void(*bhEne30_DamageMode2[2])(BH_PWORK*) = {
    bhEne30_DG00,
    bhEne30_DG01,
};

void(*bhEne30_DeadMode2[2])(BH_PWORK*) = {
    bhEne30_DD00,
    bhEne30_DD01,
};

// 100% matching!
void bhEne30(BH_PWORK* epw) {
    float wy;

    bhEne30_Mode0[epw->mode0](epw);

    if (((BH_PWORK*)epw->lkwkp)->stflg & 0x01000000) {
        epw->stflg |= 0x01000000;
    }
    
    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    
    if (!(epw->flg & 0x80000)) {
        bhCheckPlayer(epw);
        bhCheckEnemies(epw);
    }
    
    if (!(epw->flg & 0x80000)) {
        bhEne30_CheckEnemies(epw);
    }
    
    if (epw->flg & 0x10) {
        bhEne30_CollisionLine(epw);
        wy = epw->py;
        epw->py = wy + epw->ar;
        bhEne03_Collision(epw);
        epw->py -= epw->ar;
        if (!(epw->flg & 0x200000)) {
            epw->py = wy;
        }
    }
    
    bhCalcModel(epw);
    bhEne_SetWeponAtr(epw, 0, 3, 3.0f);
}

// 100% matching!
void bhEne30_Init(BH_PWORK* epw)
{
    NJS_CNK_OBJECT* obj;
    int idx;
    NJS_CNK_OBJECT* pObj;
    int i;

    epw->flg = (epw->flg & ~0x78);
    epw->flg = (epw->flg & ~6);
    epw->flg = (epw->flg & 0xFFE7FFFF);

    epw->flg2 = (epw->flg2 & ~1);
    epw->flg2 = (epw->flg2 | 0x10);

    epw->mdflg = (epw->mdflg | 1);

    epw->ar  = 3.0f;
    epw->ah  = 1.0f;
    epw->car = 2.0f;
    epw->cah = 1.0f;

    epw->mlwP   = &epw->mdl[0];
    epw->mdl_no = 0;

    epw->mdflg = (epw->mdflg & ~2);

    idx = (int)(16.0f * ((float)-rand() / -2147483648.0f));
    epw->hp = ENE30_HITPOINT[idx];

    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;

    epw->hokan_rate  = 0x10000;
    epw->hokan_count = 0;
    epw->mtn_no      = 0;
    epw->mtn_md      = 0;
    epw->mtn_add     = 0x10000;
    epw->frm_no      = 0;

    epw->clp_jno[0] = 1;
    epw->clp_jno[1] = 7;
    epw->clp_jno[2] = 9;
    epw->clp_jno[3] = 0xB;
    epw->clp_jno[4] = 0xD;
    epw->clp_jno[5] = 0xF;
    epw->clp_jno[6] = -1;

    epw->mdflg = (epw->mdflg & ~0x20);

    if (epw->exp0 == NULL) {
        epw->exp0 = bhEne_CallocWork(0xFC, 8);
        pObj = epw->mdl[1].objP;
        
        for(i = 0; i < epw->mdl[1].obj_num; i++, pObj++) {
            ((float*)(epw->exp0))[3*i+0]= pObj->pos[0];
            ((float*)(epw->exp0))[3*i+1]= pObj->pos[1];
            ((float*)(epw->exp0))[3*i+2]= pObj->pos[2];
        }
    }

    {
        NJS_CNK_OBJECT* p = &epw->mlwP->objP[5];
        i = 5;
        for(i = 5; i <= 15; i++, p++) {
            p->pos[1] = 0.0f;
        }
    }

    epw->mdl[0].objP[1].evalflags  &= ~8;
    epw->mdl[0].objP[16].evalflags &= ~8;
    epw->mdl[1].objP[1].evalflags  &= ~8;
    epw->mdl[1].objP[16].evalflags &= ~8;

    if (!(epw->flg & 0x800)) {
        bhSetShadow(SdwTab, (unsigned char*)epw, 0x10, 4.0f, 5.0f, 6.0f);
        epw->flg |= 0x800;
    }

    epw->stflg &= ~8;
    epw->cpcl = CapColTab;

    idx = (int)(20.0f * ((float)-rand() / -2147483648.0f));
    EXP0_I(0xF0) = idx + 0x14;

    epw->obj_a = epw->mdl[0].objP;
    epw->obj_b = epw->mdl[1].objP;

    epw->mdflg &= ~2;
    epw->shp_ct = 0;
}

// 100% matching!
void bhEne30_Brain(BH_PWORK* epw) {
    bhEne30_BrainType[epw->type](epw);
}

// 100% matching!
void bhEne30_BR00(BH_PWORK* epw) {
    int* temp_v1;

    EXP0_F(0xF4) = njSqrt((epw->px - plp->px) * (epw->px - plp->px) + (epw->pz - plp->pz) * (epw->pz - plp->pz));
    temp_v1 = &((int*)epw->exp0)[0x3C];

    if (temp_v1[0] != 0) {
        temp_v1[0] -= 1;
    }

    if (EXP0_I(0xF0) != 0) {
        return;
    }
    
    if ((float) -rand() / -2147483648.0f > 0.3f
        && EXP0_F(0xF4) < 15.0f
        && bhEne_CheckDirTarget(epw, plp->px, plp->pz, 0x1555) ) {
        epw->mode1 = 0;
        epw->mode2 = 7;
        epw->mode3 = 0;
        EXP0_I(0xF0) = (int)(20.0f * ((float) -rand() / -2147483648.0f)) + 0x14;
    } else if (EXP0_F(0xF4) < 15.0f) {
        epw->mode1 = 0;
        epw->mode2 = 2;
        epw->mode3 = 0;
        EXP0_I(0xF0) = (int)(20.0f * ((float) -rand() / -2147483648.0f)) + 0x14;
        return;
    }
}

// 100% matching!
void bhEne30_Move(BH_PWORK* epw) {

    if (epw->mode1 != 0) {
        bhEne30_Brain(epw);
    }
    
    bhEne30_MoveMode2[epw->mode2](epw);
    
    if (epw->flg & 4) {
        epw->flg =  (epw->flg & ~4);
        bhEne30_DamageInit(epw);
    }
}

// 100% matching!
void bhEne30_MV00() {

}

// 100% matching!
void bhEne30_MV01(BH_PWORK* epw) {
	NJS_POINT3 pos;
	ATR_WORK* hp;
	NJS_POINT3 vec;
	int i;
	BH_PWORK* ep;
	float dist;
	float wdist;
    int ang;

    switch (epw->mode3) {                             
    case 0:
        
        epw->flg &= 0xFFF7FFFF;
        epw->flg2 &= ~1;
        epw->flg |=  0x100000;
        epw->mtn_no = 0;
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 0xB333;
        epw->axp = 0;
        epw->ct0 = 0x2D;
        epw->ct1 = 0;
        epw->ayp =  epw->ay;
        epw->mode3 += 1;
        /* fallthrough */
    case 1:
        ep = ene;
        wdist = 100.0f;
        for(i = 0; i < sys->ewk_n; i++, ep++) {
            if (ep != epw) {
                if ((ep->flg & 1) && (ep->id == 0x1E) && (ep->flg & 0x100000)) {
                    {
                        float px = epw->px - ep->px;
                        float pz = epw->pz - ep->pz;
                        dist = njSqrt((px * px) + (pz * pz));
                    }
                    if (!(wdist <= dist)) {
                        ang = (short) ((bhArcTan2(epw->px - ep->px, epw->pz - ep->pz) - epw->ay));
                        if ((ang < 0x4000) && (ang > -0x4000)) {
                            wdist = dist;
                            if (epw->ct1 == 0) {
                                if (ang < 0) {
                                    epw->ct1 = 1;
                                } else {
                                    epw->ct1 = -1;
                                }
                            }
                        }
                    }
                }
            }
        }

        if (wdist < 10.0f) {
            epw->ayp = epw->ayp + (epw->ct1 * 0x444);
        }
        else if ((bhCheckRoute((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px, &pos) & 0xFF) != 0xFF) {
            epw->ay =  epw->ayp;
            epw->ayp = epw->ayp + bhEne_DirTarget(epw, pos.x, pos.z, 0x888);
        } else {
            pos.x = epw->px - (7.0f * njSin(epw->ay));
            pos.y = epw->py;
            pos.z = epw->pz - (7.0f * njCos(epw->ay));
            if ((hp = bhCollisionCheckLine((NJS_POINT3*)&epw->px, &pos)) != 0) {
                if (epw->ct1 == 0) {
                    bhGetHitCollisionNormal(&vec);
                    njUnitVector(&vec);
                    njUnitMatrix(NULL);
                    njRotateY(NULL, -epw->ay);
                    njCalcVector(NULL, &vec, &vec);
                    
                    if  (vec.x < 0.0f) {
                        epw->ayp += 0x444;
                        epw->ct1 = 1;
                    } else {
                        epw->ayp -= 0x444;
                        epw->ct1 = -1;
                    }
                }
                
                epw->ayp = epw->ayp + (epw->ct1 * 0x444);
            } else {
                epw->ay = epw->ayp;
                epw->ayp = epw->ayp + bhEne_DirTarget(epw, plp->px, plp->pz, 0x888);
            }
        }
        
        epw->axp += 0x38E;
        epw->ay = (epw->ayp + (int)(910.0f * njSin(epw->axp)));
        epw->spd = (0.5f + fabsf(0.5f * njSin(epw->axp * 2)));
        
        bhAddSpeed(epw, 0);
        if (epw->ct0 != 0) {
            epw->ct0--;
            return;
        }
        
        epw->mode1 = 1;
        epw->ct0 = 0x96;
        epw->ct1 = 0;
        break;
    }
}

// 100% matching!
void bhEne30_MV02(BH_PWORK* epw) {
    int i;
    NJS_POINT3 v;
    NJS_POINT3 pos;
    float size;
    NJS_CNK_OBJECT* objA;
    NJS_CNK_OBJECT* objB;
    int j;

    switch (epw->mode3) {
    case 0:
        epw->flg |= 0x80000;
        epw->mtn_no = 2;
        epw->frm_no = 0;
        epw->hokan_count = 0;
        epw->mlwP = epw->mdl;
        epw->obj_a = epw->mdl[0].objP;
        epw->obj_b = epw->mdl[1].objP;
        epw->mdflg |= 2;
        epw->shp_ct = 0.0f;

        for (i = 0; i < 8; i++) {
            pos.x = (epw->px + (2.0f * ((float) -rand() / -2.1474836e9f))) - 1.0f;
            pos.y = epw->py + (2.0f * ((float) -rand() / -2.1474836e9f));
            pos.z = (epw->pz + (2.0f * ((float) -rand() / -2.1474836e9f))) - 1.0f;
            size = 0.1f + (0.2f * ((float) -rand() / -2.1474836e9f));
            v.x = 0.1f;
            v.z = 0.1f;
            v.y = 0.5f + (0.7f * ((float) -rand() / -2.1474836e9f));
            njUnitMatrix(NULL);
            njRotateY(NULL, (int)(65536.0f * ((float) -rand() / -2.1474836e9f)));
            njCalcVector(NULL, &v, &v);
            bhEne30_SetFluidEffect(&pos, &v, 0, size);
        }

        for(i = 0; i < 4; i++) {
            pos.x = (epw->px + (2.0f * ((float) -rand() / -2.1474836e9f))) - 1.0f;
            pos.y = epw->py + (2.0f * ((float) -rand() / -2.1474836e9f));
            pos.z = (epw->pz + (2.0f * ((float) -rand() / -2.1474836e9f))) - 1.0f;
            size = 0.1f + (0.2f * ((float) -rand() / -2.1474836e9f));
            v.x = 0.2f;
            v.z = 0.2f;
            v.y = 0.4f + (0.7f * ((float) -rand() / -2.1474836e9f));
            njUnitMatrix(NULL);
            njRotateY(NULL, (int)(65536.0f * ((float) -rand() / -2.1474836e9f)));
            njCalcVector(NULL, &v, &v);
            bhEne30_SetFluidEffect(&pos, &v, 1, size);
        }

        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x1230B);
        epw->mode3 += 1;
        /* fallthrough */
        
    case 1:
        epw->shp_ct += 300.0f;
        if (!(epw->shp_ct < 1000.0f)) {
            epw->shp_ct = 1000.0f;
            epw->mlwP = &epw->mdl[1];
            epw->mdflg &= ~2;
            epw->mode1 = 0;
            epw->mode2 = 5;
            epw->mode3 = 0;
        }

        objA = &epw->obj_a[5];
        objB = &epw->obj_b[5];
        
        for (j = 5; j <= 15; j++, objA++, objB++) {
            objA->pos[1] = objB->pos[1] = (epw->shp_ct * (*(float*)(epw->exp0 + j * 0xC + 4))) / 1000.0f;
        }
        
        break;
    }
}

// 100% matching!
void bhEne30_MV03(BH_PWORK* epw) {
    NJS_CNK_OBJECT* objA;
    NJS_CNK_OBJECT* objB;
    int i;

    switch (epw->mode3) {
    case 0:
        epw->flg |= 0x80000;
        epw->mtn_no = 2;
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 0xB333;
        epw->mlwP = epw->mdl;
        epw->obj_a = epw->mdl[0].objP;
        epw->obj_b = epw->mdl[1].objP;
        epw->mdflg |= 2;
        epw->shp_ct = 1000.0f;
        epw->mode3 += 1;

    case 1:
        epw->shp_ct -= 35.0f;
        if (epw->shp_ct < 0.0f) {
            epw->shp_ct = 0.0f;
            epw->mlwP = epw->mdl;
            epw->mdflg &= ~2;
            epw->flg &= ~0x80000;
            epw->flg2 &= ~1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }

        objA = &epw->obj_a[5];
        objB = &epw->obj_b[5];
        
        for (i = 5; i <= 15; i++) {
            objA->pos[1] = objB->pos[1] = (epw->shp_ct * (*(float*)(epw->exp0 + i * 0xC + 4))) / 1000.0f;
            objA++;
            objB++;
        }
        
        break;
    }
}

// 100% matching!
void bhEne30_MV04(BH_PWORK* epw) {
    int mtn[3] = {2, 5, 6};
    
    switch (epw->mode3) {
        case 0:
            break;
        default:
            return;
    } 
    
    epw->flg |= 0x80000;
    epw->mtn_no = mtn[(((int)(3.0f * ((float) -rand() / -2.1474836e9f))))];
    epw->frm_no = 0;
    epw->hokan_count = 8;
    epw->hokan_rate = 0xB333;
    epw->mode3 += 1;
}

// 100% matching!
void bhEne30_MV05(BH_PWORK* epw) {
	int mtn[3] = {8, 7, 8};
	NJS_POINT3 pos;
	int i;
    O_WORK* owk;
    float temp_f1;

    switch (epw->mode3) {                           
    case 0:
        epw->flg |=  0x80000;
        
        temp_f1 = ((float*)epw->exp0)[61];
        
        if (temp_f1 < 30.0f) {
            epw->ct1 = (int)(3.0f * ((float) -rand() / -2.1474836e9f));
        } else if (temp_f1 < 70.0f) {
            epw->ct1 = (int)(2.0f * ((float) -rand() / -2.1474836e9f));
        } else {
            epw->ct1 = 0;
        }
        
        epw->mtn_no = mtn[epw->ct1];
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 0x6666;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num  - 2;
        epw->ct1  = 1;
        epw->mode3 += 1;
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x1230C);
        break;
        
    case 1:
        if (epw->ct0-- == 0) {
            epw->mode2 = 3;
            epw->mode3  = 0U;
        }
        break;
    }
    
    if ((epw->ct1 != 0) && !(plp->flg & 4) && !(plp->stflg & 0x30)) {
            for(i = 8; i <= 15; i++) {
                
            owk = &epw->mlwP->owP[i];
            pos.x = owk->mtx[12];
            pos.y = owk->mtx[13];
            pos.z = owk->mtx[14];
            
            if (bhEne_AttackHitCheck(plp, &pos, 3.0f)) {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x1230D);
                plp->flg |= 0x10004;
                plp->stflg |= 0x10000;
                plp->hp -= 5;
                
                if (plp->hp < 0) {
                    plp->hp = 0;
                }
                
                bhEne_SetBloodEffect5(plp, 0xA, 1);
                plp->mode0 = 2;
                plp->mode2 = 0;
                plp->mode3 = 0;
                
                if (abs((short)(epw->ay - plp->ay)) > 0x4000) {
                    plp->mode1 = 0;
                } else {
                    plp->mode1 = 1;
                }
                
                epw->ct1 = 0;
                return;
            }
        }
    }
}

/*// 
// Start address: 0x214c80
void bhEne30_MV06(BH_PWORK* epw)
{
	float size;
	float spd;
	_anon3 pos;
	_anon3 v;
	int i;
	// Line 923, Address: 0x214c80, Func Offset: 0
	// Line 924, Address: 0x214ca8, Func Offset: 0x28
	// Line 926, Address: 0x214cc8, Func Offset: 0x48
	// Line 927, Address: 0x214cd4, Func Offset: 0x54
	// Line 928, Address: 0x214cd8, Func Offset: 0x58
	// Line 926, Address: 0x214cdc, Func Offset: 0x5c
	// Line 927, Address: 0x214ce4, Func Offset: 0x64
	// Line 932, Address: 0x214ce8, Func Offset: 0x68
	// Line 927, Address: 0x214cec, Func Offset: 0x6c
	// Line 928, Address: 0x214cf4, Func Offset: 0x74
	// Line 929, Address: 0x214d00, Func Offset: 0x80
	// Line 930, Address: 0x214d04, Func Offset: 0x84
	// Line 931, Address: 0x214d08, Func Offset: 0x88
	// Line 932, Address: 0x214d0c, Func Offset: 0x8c
	// Line 933, Address: 0x214d10, Func Offset: 0x90
	// Line 935, Address: 0x214d14, Func Offset: 0x94
	// Line 938, Address: 0x214d18, Func Offset: 0x98
	// Line 939, Address: 0x214d24, Func Offset: 0xa4
	// Line 941, Address: 0x214d30, Func Offset: 0xb0
	// Line 944, Address: 0x214d3c, Func Offset: 0xbc
	// Line 947, Address: 0x214d48, Func Offset: 0xc8
	// Line 954, Address: 0x214d58, Func Offset: 0xd8
	// Line 955, Address: 0x214d64, Func Offset: 0xe4
	// Line 954, Address: 0x214d68, Func Offset: 0xe8
	// Line 955, Address: 0x214d6c, Func Offset: 0xec
	// Line 956, Address: 0x214d70, Func Offset: 0xf0
	// Line 958, Address: 0x214d84, Func Offset: 0x104
	// Line 960, Address: 0x214d88, Func Offset: 0x108
	// Line 961, Address: 0x214dcc, Func Offset: 0x14c
	// Line 962, Address: 0x214e04, Func Offset: 0x184
	// Line 965, Address: 0x214e4c, Func Offset: 0x1cc
	// Line 968, Address: 0x214e8c, Func Offset: 0x20c
	// Line 969, Address: 0x214ebc, Func Offset: 0x23c
	// Line 968, Address: 0x214ec0, Func Offset: 0x240
	// Line 969, Address: 0x214ec8, Func Offset: 0x248
	// Line 970, Address: 0x214ed0, Func Offset: 0x250
	// Line 971, Address: 0x214ed8, Func Offset: 0x258
	// Line 974, Address: 0x214f00, Func Offset: 0x280
	// Line 971, Address: 0x214f04, Func Offset: 0x284
	// Line 974, Address: 0x214f24, Func Offset: 0x2a4
	// Line 975, Address: 0x214f2c, Func Offset: 0x2ac
	// Line 976, Address: 0x214f80, Func Offset: 0x300
	// Line 978, Address: 0x214f90, Func Offset: 0x310
	// Line 979, Address: 0x214fa4, Func Offset: 0x324
	// Line 981, Address: 0x214fb4, Func Offset: 0x334
	// Line 983, Address: 0x214fb8, Func Offset: 0x338
	// Line 984, Address: 0x214ffc, Func Offset: 0x37c
	// Line 985, Address: 0x215030, Func Offset: 0x3b0
	// Line 988, Address: 0x215074, Func Offset: 0x3f4
	// Line 991, Address: 0x2150b4, Func Offset: 0x434
	// Line 992, Address: 0x2150e4, Func Offset: 0x464
	// Line 991, Address: 0x2150e8, Func Offset: 0x468
	// Line 992, Address: 0x2150f0, Func Offset: 0x470
	// Line 993, Address: 0x2150f8, Func Offset: 0x478
	// Line 994, Address: 0x215100, Func Offset: 0x480
	// Line 997, Address: 0x215128, Func Offset: 0x4a8
	// Line 994, Address: 0x21512c, Func Offset: 0x4ac
	// Line 997, Address: 0x21514c, Func Offset: 0x4cc
	// Line 998, Address: 0x215154, Func Offset: 0x4d4
	// Line 999, Address: 0x2151a8, Func Offset: 0x528
	// Line 1001, Address: 0x2151b8, Func Offset: 0x538
	// Line 1002, Address: 0x2151cc, Func Offset: 0x54c
	// Line 1003, Address: 0x2151dc, Func Offset: 0x55c
	// Line 1005, Address: 0x2151e0, Func Offset: 0x560
	// Line 1007, Address: 0x2151f8, Func Offset: 0x578
	// Line 1008, Address: 0x215200, Func Offset: 0x580
	// Line 1009, Address: 0x215204, Func Offset: 0x584
	// Line 1011, Address: 0x215208, Func Offset: 0x588
	// Line 1014, Address: 0x215214, Func Offset: 0x594
	// Line 1017, Address: 0x21521c, Func Offset: 0x59c
	// Func End, Address: 0x215244, Func Offset: 0x5c4
}*/

// 100% matching!
void bhEne30_MV07(BH_PWORK* epw) {
    float dist;
    float px;
    float pz;
    
    switch (epw->mode3) {                             
    case 0:
        epw->flg &= 0xFFF7FFFF;
        epw->flg2 &= ~1;
        epw->flg &= ~0x60;
        epw->flg |= 0x200000;
        epw->mtn_no = 0;
        epw->frm_no = 0;
        epw->mtn_add = 0;
        epw->hokan_count = 0;
        epw->ct0 = 0x64;
        
        px = plp->px - epw->px;
        pz = plp->pz - epw->pz;
        dist = njSqrt((px * px) + (pz * pz));
        
        epw->xn =  ((dist * -njSin(epw->ay)) / 10.0f);
        epw->zn =  ((dist * -njCos(epw->ay)) / 10.0f);
        epw->yn = 3.0f;
        epw->mode3 += 1;
        
    case 1:
        if (epw->flg & 0x200000) {
            epw->px += epw->xn;
            epw->py += epw->yn;
            epw->pz += epw->zn;
            

            epw->yn -= 0.4f;
            if (!(epw->yn <= 0.0f)) {
                {
                    int temp;
                    temp = ((short)((0x4000 - epw->ax)));
                    epw->ax += (temp >> 2);
                }
            } else {
                epw->ax = epw->ax - (epw->ax >> 2);
            }
            
            if (!(plp->flg & 4) && (bhEne_AttackHitCheck(plp, (NJS_POINT3*)&epw->px, 2))) {
                plp->flg |= 0x10004;
                plp->stflg |= 0x10000;
                plp->hp -= 5;
                
                if (plp->hp < 0) {
                    plp->hp = 0;
                }
                
                plp->mode0 = 2;
                plp->mode1 = 0;
                plp->mode2 = 0;
                plp->mode3 = 0;
                
                bhEne_SetBloodEffect4((NJS_POINT3*)&epw->px, (NJS_POINT3*)&epw->xn, 0, 0xA, 1);
                
                epw->xn *= -0.6f;
                epw->zn *= -0.6f;
                epw->yn = 0.5f;
                
            }
        } else {
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0U;
            epw->flg |= 0x60;
            epw->mtn_add = 0x10000;
            epw->ax = 0;
            epw->py = 24.0f;
        }
        
        if (epw->ct0-- == 0) {
            epw->mode0 = 0;
        }

        break;
    }
}

/*// 
// Start address: 0x215580
void bhEne30_Nage()
{
	// Line 1113, Address: 0x215580, Func Offset: 0
	// Func End, Address: 0x215588, Func Offset: 0x8
}

// 
// Start address: 0x215590
void bhEne30_Damage(BH_PWORK* epw)
{
	// Line 1124, Address: 0x215590, Func Offset: 0
	// Func End, Address: 0x2155b0, Func Offset: 0x20
}*/

// 100% matching!
void bhEne30_DG00(BH_PWORK* epw) {

    switch (epw->mode3) {                             
    case 0:
        epw->mtn_no = 2;
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 0x6666;
        epw->mtn_add = 0x20000;
        epw->ct0 = 0xA;
        epw->mode3 += 1;
        break;
        
    case 1:
        if (epw->ct0-- == 0) {
            epw->mtn_add = 0x10000;
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 3;
            epw->mode3 = 0U;
        }
        break;
    }
}

// 100% matching!
void bhEne30_DG01(BH_PWORK* epw) {
    switch (epw->mode3) {                              
    case 0:
        epw->mtn_no = 9;
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 0x6666;
        epw->mtn_add = 0x10000;
        epw->mode3 += 1;
        break;
        
    case 1:
        if (epw->frm_no == 0) {
            epw->mtn_add = 0x10000;
            epw->mode0= 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0U;
        }
        break;
    }
}

/*// 
// Start address: 0x2156c0
void bhEne30_Die(BH_PWORK* epw)
{
	// Line 1195, Address: 0x2156c0, Func Offset: 0
	// Func End, Address: 0x2156e0, Func Offset: 0x20
}*/

// 100% matching!
void bhEne30_DD00(BH_PWORK* epw)
{
    NJS_CNK_OBJECT* objA;
    NJS_CNK_OBJECT* objB;
    int i;
    O_WORK* owk;

    switch (epw->mode3) {
    case 0:
        epw->flg = (epw->flg | 0x8002);
        epw->flg = (epw->flg & ~0x28);
        epw->flg = (epw->flg & 0xFFEFFFFF);
        epw->stflg = (epw->stflg | 8);
        epw->mtn_no = 4;
        epw->frm_no = 0;
        epw->hokan_count = 8;
        epw->hokan_rate = 0x6666;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mlwP->objP[1].evalflags |= 8;
        epw->mlwP->objP[16].evalflags |= 8;
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x1230E);
        epw->mode3++;
        /* fallthrough */
        
    case 1:
        if (epw->ct0-- == 0) {
            epw->mtn_add = 0;
        }

        epw->shp_ct -= 15.0f;
        if (epw->shp_ct < 200.0f) {
            epw->shp_ct = 0.0f;
            epw->mode3++;
        }

        objA = &epw->obj_a[5];
        objB = &epw->obj_b[5];
        for(i = 5; i <= 15; i++, objA++, objB++) {
            objA->pos[1] = objB->pos[1] = (epw->shp_ct * *(float*)(epw->exp0 + i * 0xC + 4)) / 1000.0f;
        }

        if (epw->ct1-- == 0) {
            owk = epw->mlwP->owP;
            epw->dvx = owk[7].mtx[12];
            epw->dvy = owk[7].mtx[13];
            epw->dvz = owk[7].mtx[14];
            owk = epw->mlwP->owP;
            njSubVector((NJS_VECTOR*)&epw->dvx, (NJS_VECTOR*)&owk[6].mtx[12]);
            bhEne_SetBloodEffectBurst(epw, 0, 7, NULL, 0);
            epw->ct1 = (int)(8.0f * ((float)-rand() / -2147483648.0f)) + 0x10;
        }
        break;

    case 2:
        epw->mdflg |= 1;
        bhEne_SetBloodEffectBurst(epw, 3, 7, NULL, 0);
        epw->ct0 = 0x3C;
        epw->mode3++;
        /* fallthrough */
        
    case 3:
        
        if (epw->ct0-- == 0) {
            epw->mode0 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne30_DD01(BH_PWORK* epw) {
    switch (epw->mode3) {                         
    case 0:
        epw->flg |= 0x8002;
        epw->flg &= ~0x28;
        epw->flg &= 0xFFEFFFFF;
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 0x1230E);
        epw->stflg |= 8; 
        epw->mdflg |= 1;
        epw->ct0 = 0x3C;
        epw->mode3 += 1;
        
    case 1:
        if (epw->ct0-- == 0) {
            epw->mode0 = 0;
        }
        return;
    }
}

// 100% matching!
void bhEne30_CheckEnemies(BH_PWORK* epw) {
    int i;
    float dx;
    float dz;
    float len;
    BH_PWORK* ep;

    ep = ene;
    for (i = 0; i < sys->ewk_n; i++, ep++) {
        if ((ep->flg & 1) && (ep->flg & 8) && (ep->id == 0x1E) && (ep->flg & 0x80000)) {
            dx = epw->px - ep->px;
            dz = epw->pz - ep->pz;
            

            len = njSqrt((dx * dx) + (dz * dz));

            if (len != 0.0f) {
                if (len < (epw->car + ep->car)) {
                    epw->px = ep->px + (dx * (epw->car + ep->car)) / len;
                    epw->pz = ep->pz + (dz * (epw->car + ep->car)) / len;
                }
            }
        }
    }
}

// 100% matching!
void bhEne30_DamageInit(BH_PWORK* epw) {
	int i;
	int dam;
    NJS_POINT3 ofp;

    //  NOT IN DWARF
    int flg;


    dam = 0;
    for(i = 0; i < epw->mlwP->obj_num; i++) {
        if (epw->dam[i] != 0) {
            dam += epw->dam[i];
            epw->dam[i] = 0;
        }
    }
    
    if (dam != 0) {
        epw->hp =  (epw->hp - dam);
        bhEne_SetBloodEffectBurst(epw, 2, 1, NULL, 0);
        
        if ((epw->hp < 0) || (flg = epw->flg & 0x80000, (flg != 0))) {
            ofp.x = 0.0f;
            ofp.y = 1.0f;
            ofp.z = 0.0f;
            epw->dvz = 0;
            epw->dvx = 0;
            epw->dvy = -1.0f;
            
            bhEne_SetBloodstain(epw, 2, 5, &ofp);
            epw->mode0 = 4;
            epw->mode1 = 0;
            epw->mode3 = 0;
            
            bhEne_SetMinceEffect(epw, 0x102, 3);
            bhEne_SetMinceEffect(epw, 0x103, 2);
            
            if (epw->flg & 0x80000) {
                epw->mode2 = 0;
                return;
            }
            
            epw->mode2 = 1;
            return;
        }
        
        if (!(epw->flg & 0x200000)) {
            if (flg != 0) {
                epw->mode2 = 0;
            } else {
                epw->mode2= 1;
            }
            
            epw->mode0 = 3;
            epw->mode1 = 0;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne30_CollisionLine(BH_PWORK* epw) {
    NJS_POINT3 n;
    
    if ((bhCollisionCheckLine((NJS_POINT3*)&epw->pxb,  (NJS_POINT3*)&epw->px) != NULL) && (epw->flg & 0x200000)) {
        bhGetHitCollisionNormal(&n);
        njUnitVector(&n);
        if (!(n.y < 0.99f)) {
            epw->flg &= 0xFFDFFFFF;
        }
    }
}

// 100% matching!
void bhEne30_SetFluidEffect(NJS_POINT3* pos, NJS_POINT3* vec, int type, float size) {
    int eno;

    sys->ef.id = 0x10B;
    sys->ef.flg = 1;
    sys->ef.type = type;
    sys->ef.px = pos->x;
    sys->ef.py = pos->y;
    sys->ef.pz = pos->z;
    sys->ef.sx = size;
    sys->ef.sy = size;
    sys->ef.sz = size;
    eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
    
    if (eno != -1) {
        eff[eno].xn = vec->x;
        eff[eno].yn = vec->y;
        eff[eno].zn = vec->z;
    }
}

