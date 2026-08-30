#ifndef _EN19_H_
#define _EN19_H_

#include "types.h"

typedef enum _br_mde0 {
    TY_BR0_NORMAL = 0,
    TY_BR0_DOWN = 1,
    TY_BR0_LAY = 2,
    TY_BR0_DIE = 3,
    TY_BR0_PINCH = 4,
} _br_mde0; 

typedef enum _br_mde1 {
    TY_BR1_NORMAL = 0,
    TY_BR1_WALK = 1,
    TY_BR1_ROTATE = 2,
    TY_BR1_ATTACK = 3,
    TY_BR1_DASH_ATTACK = 4,
    TY_BR1_WAIT = 5,
    TY_BR1_DAMAGE = 6,
    TY_BR1_CHANGE = 7,
} _br_mde1; 

typedef enum _br_mde2 {
    TY_BR2_FIRST = 0,
    TY_BR2_LOOP0 = 1,
    TY_BR2_LOOP1 = 2,
    TY_BR2_LOOP2 = 3,
} _br_mde2; 

typedef struct FW_WORK 
{
    // total size: 0x204
    float mtx_bak[16]; // offset 0x0, size 0x40
    signed int status; // offset 0x40, size 0x4
    signed int act_flg; // offset 0x44, size 0x4
    void (* prgP)(struct BH_PWORK *, struct _en19_freework *, signed int); // offset 0x48, size 0x4
    signed int act_frm; // offset 0x4C, size 0x4
    signed int act_now; // offset 0x50, size 0x4
    signed int mtn_rte; // offset 0x54, size 0x4
    signed int chg_rte; // offset 0x58, size 0x4
    signed int act_cnt; // offset 0x5C, size 0x4
    signed int b_status; // offset 0x60, size 0x4
    signed int b_act_flg; // offset 0x64, size 0x4
    void (* b_prgP)(struct BH_PWORK *, struct _en19_freework *, signed int); // offset 0x68, size 0x4
    signed int b_act_frm; // offset 0x6C, size 0x4
    signed int b_act_now; // offset 0x70, size 0x4
    signed int b_mtn_rte; // offset 0x74, size 0x4
    signed int b_chg_rte; // offset 0x78, size 0x4
    signed int b_act_cnt; // offset 0x7C, size 0x4
    signed int b_mtn_md; // offset 0x80, size 0x4
    signed int dummy; // offset 0x84, size 0x4
    struct /* @anon1 */ {
        // total size: 0x38
        signed int p_status; // offset 0x0, size 0x4
        signed int p_mode; // offset 0x4, size 0x4
        signed int p_act_flg; // offset 0x8, size 0x4
        void (* p_prgP)(struct BH_PWORK *, void *); // offset 0xC, size 0x4
        void * p_paramP; // offset 0x10, size 0x4
        signed int p_act_frm; // offset 0x14, size 0x4
        signed int p_chg_frm; // offset 0x18, size 0x4
        signed int p_mtn_rte; // offset 0x1C, size 0x4
        signed int p_act_jmp; // offset 0x20, size 0x4
        signed int p_frm_num; // offset 0x24, size 0x4
        signed int p_act_now; // offset 0x28, size 0x4
        struct /* @anon11 */ {
            // total size: 0x18
            unsigned int flg; // offset 0x0, size 0x4
            unsigned int obj_num; // offset 0x4, size 0x4
            unsigned int frm_num; // offset 0x8, size 0x4
            void * datP; // offset 0xC, size 0x4
            struct /* @anon27 */ {
                // total size: 0x8
                void * p[2]; // offset 0x0, size 0x8
            } * md2P; // offset 0x10, size 0x4
            unsigned short * atrP; // offset 0x14, size 0x4
        } * ene_mnwP; // offset 0x2C, size 0x4
        struct /* @anon2 */ {
            // total size: 0x10
            signed short mtn_no; // offset 0x0, size 0x2
            signed short frm_no; // offset 0x2, size 0x2
            unsigned char hkn_lvl; // offset 0x4, size 0x1
            unsigned char hkn_cnt; // offset 0x5, size 0x1
            unsigned char chg_frm; // offset 0x6, size 0x1
            signed char act_jmp; // offset 0x7, size 0x1
            signed int flag; // offset 0x8, size 0x4
            void * prgP; // offset 0xC, size 0x4
        } * act_tblP; // offset 0x30, size 0x4
        signed int tbl_num; // offset 0x34, size 0x4
    } ply_act; // offset 0x88, size 0x38
    struct BH_PWORK * ewP; // offset 0xC0, size 0x4
    _br_mde0 br_mde0; // offset 0xC4, size 0x4
    _br_mde1 br_mde1; // offset 0xC8, size 0x4
    _br_mde2 br_mde2; // offset 0xCC, size 0x4
    signed int br_wait1; // offset 0xD0, size 0x4
    signed int ct_dash; // offset 0xD4, size 0x4
    signed int ct_pinch; // offset 0xD8, size 0x4
    struct /* @anon6 */ {
        // total size: 0xC
        float x; // offset 0x0, size 0x4
        float y; // offset 0x4, size 0x4
        float z; // offset 0x8, size 0x4
    } ClwPos[4]; // offset 0xDC, size 0x30
    struct /* @anon6 */ {
        // total size: 0xC
        float x; // offset 0x0, size 0x4
        float y; // offset 0x4, size 0x4
        float z; // offset 0x8, size 0x4
    } fix_adj; // offset 0x10C, size 0xC
    struct /* @anon6 */ {
        // total size: 0xC
        float x; // offset 0x0, size 0x4
        float y; // offset 0x4, size 0x4
        float z; // offset 0x8, size 0x4
    } adj_vx; // offset 0x118, size 0xC
    struct /* @anon6 */ {
        // total size: 0xC
        float x; // offset 0x0, size 0x4
        float y; // offset 0x4, size 0x4
        float z; // offset 0x8, size 0x4
    } adj_vz; // offset 0x124, size 0xC
    struct /* @anon6 */ {
        // total size: 0xC
        float x; // offset 0x0, size 0x4
        float y; // offset 0x4, size 0x4
        float z; // offset 0x8, size 0x4
    } tgt_pos; // offset 0x130, size 0xC
    float ply_dst; // offset 0x13C, size 0x4
    float tgt_dst; // offset 0x140, size 0x4
    signed int tgt_ang; // offset 0x144, size 0x4
    signed int trn_spd; // offset 0x148, size 0x4
    signed int dir_dlt; // offset 0x14C, size 0x4
    signed int trw_dir; // offset 0x150, size 0x4
    float trw_spd; // offset 0x154, size 0x4
    signed int ply_mde; // offset 0x158, size 0x4
    struct /* @anon6 */ {
        // total size: 0xC
        float x; // offset 0x0, size 0x4
        float y; // offset 0x4, size 0x4
        float z; // offset 0x8, size 0x4
    } wnd_spd; // offset 0x15C, size 0xC
    signed int dmg_obj; // offset 0x168, size 0x4
    signed int dmg_cnt; // offset 0x16C, size 0x4
    signed int dwn_cnt; // offset 0x170, size 0x4
    signed int bnd_tim; // offset 0x174, size 0x4
    signed int hp_bak; // offset 0x178, size 0x4
    signed int watr_top; // offset 0x17C, size 0x4
    float watr_rad; // offset 0x180, size 0x4
    signed int snd_no; // offset 0x184, size 0x4
    float ovl_rte; // offset 0x188, size 0x4
    float atk_rng_a_near; // offset 0x18C, size 0x4
    float atk_rng_b_near; // offset 0x190, size 0x4
    float atk_rng_a_far; // offset 0x194, size 0x4
    float atk_rng_b_far; // offset 0x198, size 0x4
    signed int dmg_flg; // offset 0x19C, size 0x4
    enum /* @enum */ {
        TY_DMG_NON = 0,
        TY_DMG_LVL0 = 1,
        TY_DMG_LVL1 = 2,
        TY_DMG_LVL2 = 3,
        TY_DMG_LVL3 = 4,
        TY_DMG_LVL4 = 5,
        TY_DMG_SPECIAL = 6,
    } dmg_lvl; // offset 0x1A0, size 0x4
    signed int cmb_lvl; // offset 0x1A4, size 0x4
    signed int dmg_dly; // offset 0x1A8, size 0x4
    float pos_tmp[3]; // offset 0x1AC, size 0xC
    signed int ang_tmp[3]; // offset 0x1B8, size 0xC
    struct /* @anon6 */ {
        // total size: 0xC
        float x; // offset 0x0, size 0x4
        float y; // offset 0x4, size 0x4
        float z; // offset 0x8, size 0x4
    } vct_tmp; // offset 0x1C4, size 0xC
    signed int cnt_tmp; // offset 0x1D0, size 0x4
    struct /* @anon10 */ {
        // total size: 0x20
        signed int type; // offset 0x0, size 0x4
        signed int ang_fst; // offset 0x4, size 0x4
        signed int add_ax; // offset 0x8, size 0x4
        float x_rang; // offset 0xC, size 0x4
        float x_rate; // offset 0x10, size 0x4
        signed int add_ay; // offset 0x14, size 0x4
        float y_rang; // offset 0x18, size 0x4
        float y_rate; // offset 0x1C, size 0x4
    } * e0aP; // offset 0x1D4, size 0x4
    signed int eff_tim; // offset 0x1D8, size 0x4
    struct /* @anon13 */ {
        // total size: 0x70
        struct /* @anon41 */ {
            // total size: 0x24
            float (* mtxP)[16]; // offset 0x0, size 0x4
            struct /* @anon3 */ {
                // total size: 0x8
                struct /* @anon28 */ {
                    // total size: 0xC
                    void * filename; // offset 0x0, size 0x4
                    unsigned int attr; // offset 0x4, size 0x4
                    unsigned int texaddr; // offset 0x8, size 0x4
                } * textures; // offset 0x0, size 0x4
                unsigned int nbTexture; // offset 0x4, size 0x4
            } * texP; // offset 0x4, size 0x4
            struct /* @anon5 */ {
                // total size: 0x28
                struct /* @anon6 */ {
                    // total size: 0xC
                    float x; // offset 0x0, size 0x4
                    float y; // offset 0x4, size 0x4
                    float z; // offset 0x8, size 0x4
                } * points; // offset 0x0, size 0x4
                struct /* @anon6 */ {
                    // total size: 0xC
                    float x; // offset 0x0, size 0x4
                    float y; // offset 0x4, size 0x4
                    float z; // offset 0x8, size 0x4
                } * normals; // offset 0x4, size 0x4
                signed int nbPoint; // offset 0x8, size 0x4
                struct /* @anon51 */ {
                    // total size: 0x18
                    unsigned short type_matId; // offset 0x0, size 0x2
                    unsigned short nbMesh; // offset 0x2, size 0x2
                    signed short * meshes; // offset 0x4, size 0x4
                    unsigned int * attrs; // offset 0x8, size 0x4
                    struct /* @anon6 */ {
                        // total size: 0xC
                        float x; // offset 0x0, size 0x4
                        float y; // offset 0x4, size 0x4
                        float z; // offset 0x8, size 0x4
                    } * normals; // offset 0xC, size 0x4
                    union /* @anon26 */ {
                        unsigned int color; // offset 0x0, size 0x4
                        struct /* @anon22 */ {
                            // total size: 0x4
                            signed short u; // offset 0x0, size 0x2
                            signed short v; // offset 0x2, size 0x2
                        } tex; // offset 0x0, size 0x4
                        struct /* @anon23 */ {
                            // total size: 0x4
                            unsigned char b; // offset 0x0, size 0x1
                            unsigned char g; // offset 0x1, size 0x1
                            unsigned char r; // offset 0x2, size 0x1
                            unsigned char a; // offset 0x3, size 0x1
                        } argb; // offset 0x0, size 0x4
                    } * vertcolor; // offset 0x10, size 0x4
                    union /* @anon26 */ {
                        unsigned int color; // offset 0x0, size 0x4
                        struct /* @anon22 */ {
                            // total size: 0x4
                            signed short u; // offset 0x0, size 0x2
                            signed short v; // offset 0x2, size 0x2
                        } tex; // offset 0x0, size 0x4
                        struct /* @anon23 */ {
                            // total size: 0x4
                            unsigned char b; // offset 0x0, size 0x1
                            unsigned char g; // offset 0x1, size 0x1
                            unsigned char r; // offset 0x2, size 0x1
                            unsigned char a; // offset 0x3, size 0x1
                        } argb; // offset 0x0, size 0x4
                    } * vertuv; // offset 0x14, size 0x4
                } * meshsets; // offset 0xC, size 0x4
                struct /* @anon44 */ {
                    // total size: 0x14
                    union /* @anon26 */ {
                        unsigned int color; // offset 0x0, size 0x4
                        struct /* @anon22 */ {
                            // total size: 0x4
                            signed short u; // offset 0x0, size 0x2
                            signed short v; // offset 0x2, size 0x2
                        } tex; // offset 0x0, size 0x4
                        struct /* @anon23 */ {
                            // total size: 0x4
                            unsigned char b; // offset 0x0, size 0x1
                            unsigned char g; // offset 0x1, size 0x1
                            unsigned char r; // offset 0x2, size 0x1
                            unsigned char a; // offset 0x3, size 0x1
                        } argb; // offset 0x0, size 0x4
                    } diffuse; // offset 0x0, size 0x4
                    union /* @anon26 */ {
                        unsigned int color; // offset 0x0, size 0x4
                        struct /* @anon22 */ {
                            // total size: 0x4
                            signed short u; // offset 0x0, size 0x2
                            signed short v; // offset 0x2, size 0x2
                        } tex; // offset 0x0, size 0x4
                        struct /* @anon23 */ {
                            // total size: 0x4
                            unsigned char b; // offset 0x0, size 0x1
                            unsigned char g; // offset 0x1, size 0x1
                            unsigned char r; // offset 0x2, size 0x1
                            unsigned char a; // offset 0x3, size 0x1
                        } argb; // offset 0x0, size 0x4
                    } specular; // offset 0x4, size 0x4
                    float exponent; // offset 0x8, size 0x4
                    unsigned int attr_texId; // offset 0xC, size 0x4
                    unsigned int attrflags; // offset 0x10, size 0x4
                } * mats; // offset 0x10, size 0x4
                unsigned short nbMeshset; // offset 0x14, size 0x2
                unsigned short nbMat; // offset 0x16, size 0x2
                struct /* @anon6 */ {
                    // total size: 0xC
                    float x; // offset 0x0, size 0x4
                    float y; // offset 0x4, size 0x4
                    float z; // offset 0x8, size 0x4
                } center; // offset 0x18, size 0xC
                float r; // offset 0x24, size 0x4
            } * mdlP; // offset 0x8, size 0x4
            float pos[3]; // offset 0xC, size 0xC
            signed int ang[3]; // offset 0x18, size 0xC
        } prm; // offset 0x0, size 0x24
        signed int mode; // offset 0x24, size 0x4
        signed int erase; // offset 0x28, size 0x4
        float (* mtxP)[16]; // offset 0x2C, size 0x4
        signed char mtx_buf[64]; // offset 0x30, size 0x40
    } * clw0P; // offset 0x1DC, size 0x4
    struct /* @anon13 */ {
        // total size: 0x70
        struct /* @anon41 */ {
            // total size: 0x24
            float (* mtxP)[16]; // offset 0x0, size 0x4
            struct /* @anon3 */ {
                // total size: 0x8
                struct /* @anon28 */ {
                    // total size: 0xC
                    void * filename; // offset 0x0, size 0x4
                    unsigned int attr; // offset 0x4, size 0x4
                    unsigned int texaddr; // offset 0x8, size 0x4
                } * textures; // offset 0x0, size 0x4
                unsigned int nbTexture; // offset 0x4, size 0x4
            } * texP; // offset 0x4, size 0x4
            struct /* @anon5 */ {
                // total size: 0x28
                struct /* @anon6 */ {
                    // total size: 0xC
                    float x; // offset 0x0, size 0x4
                    float y; // offset 0x4, size 0x4
                    float z; // offset 0x8, size 0x4
                } * points; // offset 0x0, size 0x4
                struct /* @anon6 */ {
                    // total size: 0xC
                    float x; // offset 0x0, size 0x4
                    float y; // offset 0x4, size 0x4
                    float z; // offset 0x8, size 0x4
                } * normals; // offset 0x4, size 0x4
                signed int nbPoint; // offset 0x8, size 0x4
                struct /* @anon51 */ {
                    // total size: 0x18
                    unsigned short type_matId; // offset 0x0, size 0x2
                    unsigned short nbMesh; // offset 0x2, size 0x2
                    signed short * meshes; // offset 0x4, size 0x4
                    unsigned int * attrs; // offset 0x8, size 0x4
                    struct /* @anon6 */ {
                        // total size: 0xC
                        float x; // offset 0x0, size 0x4
                        float y; // offset 0x4, size 0x4
                        float z; // offset 0x8, size 0x4
                    } * normals; // offset 0xC, size 0x4
                    union /* @anon26 */ {
                        unsigned int color; // offset 0x0, size 0x4
                        struct /* @anon22 */ {
                            // total size: 0x4
                            signed short u; // offset 0x0, size 0x2
                            signed short v; // offset 0x2, size 0x2
                        } tex; // offset 0x0, size 0x4
                        struct /* @anon23 */ {
                            // total size: 0x4
                            unsigned char b; // offset 0x0, size 0x1
                            unsigned char g; // offset 0x1, size 0x1
                            unsigned char r; // offset 0x2, size 0x1
                            unsigned char a; // offset 0x3, size 0x1
                        } argb; // offset 0x0, size 0x4
                    } * vertcolor; // offset 0x10, size 0x4
                    union /* @anon26 */ {
                        unsigned int color; // offset 0x0, size 0x4
                        struct /* @anon22 */ {
                            // total size: 0x4
                            signed short u; // offset 0x0, size 0x2
                            signed short v; // offset 0x2, size 0x2
                        } tex; // offset 0x0, size 0x4
                        struct /* @anon23 */ {
                            // total size: 0x4
                            unsigned char b; // offset 0x0, size 0x1
                            unsigned char g; // offset 0x1, size 0x1
                            unsigned char r; // offset 0x2, size 0x1
                            unsigned char a; // offset 0x3, size 0x1
                        } argb; // offset 0x0, size 0x4
                    } * vertuv; // offset 0x14, size 0x4
                } * meshsets; // offset 0xC, size 0x4
                struct /* @anon44 */ {
                    // total size: 0x14
                    union /* @anon26 */ {
                        unsigned int color; // offset 0x0, size 0x4
                        struct /* @anon22 */ {
                            // total size: 0x4
                            signed short u; // offset 0x0, size 0x2
                            signed short v; // offset 0x2, size 0x2
                        } tex; // offset 0x0, size 0x4
                        struct /* @anon23 */ {
                            // total size: 0x4
                            unsigned char b; // offset 0x0, size 0x1
                            unsigned char g; // offset 0x1, size 0x1
                            unsigned char r; // offset 0x2, size 0x1
                            unsigned char a; // offset 0x3, size 0x1
                        } argb; // offset 0x0, size 0x4
                    } diffuse; // offset 0x0, size 0x4
                    union /* @anon26 */ {
                        unsigned int color; // offset 0x0, size 0x4
                        struct /* @anon22 */ {
                            // total size: 0x4
                            signed short u; // offset 0x0, size 0x2
                            signed short v; // offset 0x2, size 0x2
                        } tex; // offset 0x0, size 0x4
                        struct /* @anon23 */ {
                            // total size: 0x4
                            unsigned char b; // offset 0x0, size 0x1
                            unsigned char g; // offset 0x1, size 0x1
                            unsigned char r; // offset 0x2, size 0x1
                            unsigned char a; // offset 0x3, size 0x1
                        } argb; // offset 0x0, size 0x4
                    } specular; // offset 0x4, size 0x4
                    float exponent; // offset 0x8, size 0x4
                    unsigned int attr_texId; // offset 0xC, size 0x4
                    unsigned int attrflags; // offset 0x10, size 0x4
                } * mats; // offset 0x10, size 0x4
                unsigned short nbMeshset; // offset 0x14, size 0x2
                unsigned short nbMat; // offset 0x16, size 0x2
                struct /* @anon6 */ {
                    // total size: 0xC
                    float x; // offset 0x0, size 0x4
                    float y; // offset 0x4, size 0x4
                    float z; // offset 0x8, size 0x4
                } center; // offset 0x18, size 0xC
                float r; // offset 0x24, size 0x4
            } * mdlP; // offset 0x8, size 0x4
            float pos[3]; // offset 0xC, size 0xC
            signed int ang[3]; // offset 0x18, size 0xC
        } prm; // offset 0x0, size 0x24
        signed int mode; // offset 0x24, size 0x4
        signed int erase; // offset 0x28, size 0x4
        float (* mtxP)[16]; // offset 0x2C, size 0x4
        signed char mtx_buf[64]; // offset 0x30, size 0x40
    } * clw2P; // offset 0x1E0, size 0x4
    enum /* @enum */ {
        TY_PRG_INIT = 0,
        TY_PRG_MOVE = 1,
        TY_PRG_DAMAGE = 2,
        TY_PRG_DIE = 3,
        TY_PRG_UNKKOWN = 4,
        TY_PRG_EVENT = 5,
    } mode0_bak; // offset 0x1E4, size 0x4
    struct /* @anon8 */ {
        // total size: 0x44
        struct /* @anon10 */ {
            // total size: 0x20
            signed int type; // offset 0x0, size 0x4
            signed int ang_fst; // offset 0x4, size 0x4
            signed int add_ax; // offset 0x8, size 0x4
            float x_rang; // offset 0xC, size 0x4
            float x_rate; // offset 0x10, size 0x4
            signed int add_ay; // offset 0x14, size 0x4
            float y_rang; // offset 0x18, size 0x4
            float y_rate; // offset 0x1C, size 0x4
        } prm_a; // offset 0x0, size 0x20
        signed int mode; // offset 0x20, size 0x4
        signed int ang_x; // offset 0x24, size 0x4
        signed int ang_y; // offset 0x28, size 0x4
        struct /* @anon6 */ {
            // total size: 0xC
            float x; // offset 0x0, size 0x4
            float y; // offset 0x4, size 0x4
            float z; // offset 0x8, size 0x4
        } off_pos; // offset 0x2C, size 0xC
        struct /* @anon6 */ {
            // total size: 0xC
            float x; // offset 0x0, size 0x4
            float y; // offset 0x4, size 0x4
            float z; // offset 0x8, size 0x4
        } dst_pos; // offset 0x38, size 0xC
    } * cam_clrP; // offset 0x1E8, size 0x4
    _br_mde0 br_mde0_bak; // offset 0x1EC, size 0x4
    _br_mde1 br_mde1_bak; // offset 0x1F0, size 0x4
    _br_mde2 br_mde2_bak; // offset 0x1F4, size 0x4
    signed int comb_flg; // offset 0x1F8, size 0x4
    unsigned int Dummy[2]; // offset 0x1FC, size 0x8
} FW_WORK;

void bhEne19(BH_PWORK* ewP);
void bhEne19_Init(BH_PWORK* ewP);
void bhEne19_Move(BH_PWORK* ewP);
void bhEne19_Damage();
void bhEne19_Die(BH_PWORK* ewP);
void bhEne19_Event(BH_PWORK* ewP);
void bhEne19_Br00(BH_PWORK* ewP);
void bhEne19_Br01(BH_PWORK* ewP);
void bhEne19_Br02(BH_PWORK* ewP);
void bhEne19_Mv00();
void bhEne19_Mv01();
/*void bhEne19_Mv02(FW_WORK* fwP, int count);*/
void bhEne19_Mv03();
/*void bhEne19_Mv04a(FW_WORK* fwP, int count);
void bhEne19_Mv04b(FW_WORK* fwP, int count);
void bhEne19_Mv05(FW_WORK* fwP, int count);*/
void bhEne19_Mv06();
/*void bhEne19_Mv07(BH_PWORK* ewP, FW_WORK* fwP, int count);
void bhEne19_Mv08(BH_PWORK* ewP, FW_WORK* fwP);
void bhEne19_Mv09(BH_PWORK* ewP, FW_WORK* fwP);
void bhEne19_Mv10(BH_PWORK* ewP, FW_WORK* fwP, int count);
void bhEne19_Mv11(BH_PWORK* ewP, FW_WORK* fwP);
void bhEne19_Mv12(BH_PWORK* ewP, FW_WORK* fwP);
void bhEne19_Mv13(BH_PWORK* ewP, FW_WORK* fwP, int count);
void bhEne19_Mv14(BH_PWORK* ewP, FW_WORK* fwP, int count);
void bhEne19_Mv15(FW_WORK* fwP, int count);
void bhEne19_Mv16(FW_WORK* fwP, int count);
void bhEne19_Mv17(FW_WORK* fwP, int count);
void bhEne19_Mv18(BH_PWORK* ewP, FW_WORK* fwP, int count);
void bhEne19_Mv19(FW_WORK* fwP, int count);
void bhEne19_Mv20(BH_PWORK* ewP, FW_WORK* fwP, int count);
_anon48* bhEne19_ActionSearch(int act_nw, int act_no);
int bhEne19_ActionChange(BH_PWORK* ewP, FW_WORK* fwP, int act_dst);
int bhEne19_ActionMain(BH_PWORK* ewP, FW_WORK* fwP);
void bhEne19_TargetAnalyze(BH_PWORK* ewP, FW_WORK* fwP);
void bhEne19_PositonFix(BH_PWORK* ewP, FW_WORK* fwP);
void bhEne19_HeadTurn(BH_PWORK* ewP, FW_WORK* fwP, int mode);
int bhEne19_AttackHitCheck(BH_PWORK* ewP, _enum_2 arm_no, float ar, int* angP);
void bhEne19_CalcEnemy(BH_PWORK* ewP, FW_WORK* fwP);
void bhEne19_DmgCheck(BH_PWORK* ewP, FW_WORK* fwP);
void bhEne19_SetDmgEffect(BH_PWORK* ewP, int set_obj, int eff_typ, _anon6* dirP);
int bhEne19_CollisionCircle2Oval(float basP[16], float ra, float rb, _anon6* posP, float rc);
void bhEne19_TyBloodSet(_anon21* ebP);
void bhEne19_ClawReset(BH_PWORK* ewP, FW_WORK* fwP);
void bhEne19_SoundSet(BH_PWORK* ewP, FW_WORK* fwP);*/
int bhEne19_MtnAttrbuteGet(BH_PWORK* ewP);
/*int bhEne19_PlySetDamage(BH_PWORK* plP, FW_WORK* fwP, int dmg_mod);
void bhEne19_PlyMoveMain(BH_PWORK* plP, FW_WORK* fwP);
void bhEne19_PlyDmg042(BH_PWORK* plP, FW_WORK* fwP);
void bhEne19_PlyDmg043(BH_PWORK* plP, FW_WORK* fwP);
void bhEne19_PlyDmg044(BH_PWORK* plP, FW_WORK* fwP);
void bhEne19_PlyDmg045(BH_PWORK* plP, FW_WORK* fwP);
void bhEne19_PlyDmg046_047(BH_PWORK* plP, FW_WORK* fwP);
void bhEne19_PlyDmg050_051(BH_PWORK* plP, FW_WORK* fwP);
void bhEne19_PlyDmg052_053(BH_PWORK* plP, FW_WORK* fwP);
void bhEne19_PlyDmg117_118(BH_PWORK* plP, FW_WORK* fwP);*/
void bhEne19_PlyDmgDie(BH_PWORK* plP, FW_WORK* fwP);
/*void bhEne19_PlyDmgRtn(BH_PWORK* plP, FW_WORK* fwP);
void bhEne19_PlyDmgFal(BH_PWORK* plP, FW_WORK* fwP);
void bhEne_PlyActionInit(BH_PWORK* ewP, _anon1* pawP, _anon2* act_tblP, int tbl_num);
void bhEne_PlyActionMain(BH_PWORK* plP, _anon1* pawP);
int bhEne_PlyActionChange(BH_PWORK* plP, _anon1* pawP, int act_no);
int bhEne_CalcCombRate(BH_PWORK* ewP, _anon47* cwP);
_enum_4 bhEne19_CheckDmgLvl0(BH_PWORK* ewP, FW_WORK* fwP);
_enum_4 bhEne19_CheckDmgLvl1(BH_PWORK* ewP, FW_WORK* fwP);
_enum_4 bhEne19_CheckDmgLvl2(BH_PWORK* ewP, FW_WORK* fwP);
_anon13* bhEne19_SetLeftClaw(_anon17* mlwP, _enum_6 tgt_bas, _enum_6 tgt_obj);*/
void bhEne19_SetClawPlane(BH_PWORK* ewP, float mtxP[16], int col, int tim, float src_x, float dst_x);

#endif
