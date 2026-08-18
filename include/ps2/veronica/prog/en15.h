#ifndef _EN15_H_
#define _EN15_H_

#include "types.h"
#include "macros.h"

typedef union _ATTACK_COL 
{
    NJS_CAPSULE cap; // offset 0x0, size 0x1C
    NJS_BOX box;     // offset 0x0, size 0x60
} ATTACK_COL; 

typedef struct _ATTACK_COL_TBL 
{
    // total size: 0x24
    int* obj_no;      // offset 0x0, size 0x4
    int start_frm;    // offset 0x4, size 0x4
    int end_frm;      // offset 0x8, size 0x4
    int damage;       // offset 0xC, size 0x4
    int impact_ang;   // offset 0x10, size 0x4
    float spd;        // offset 0x14, size 0x4
    float volume;     // offset 0x18, size 0x4
    int sp_start_frm; // offset 0x1C, size 0x4
    int sp_end_frm;   // offset 0x20, size 0x4
} ATTACK_COL_TBL;

int target_direction(BH_PWORK* epw);
float target_distance(BH_PWORK* epw);
int GetLocalEneNo(BH_PWORK* epw);
void SetMtnSE(BH_PWORK* epw);
void bhEne15(BH_PWORK* epw);
void Init(BH_PWORK* epw);
void Move(BH_PWORK* epw);
void Stand(BH_PWORK* epw);
void __attack(BH_PWORK* epw);
void CloseTurn(BH_PWORK* epw);
void Chase(BH_PWORK* epw);
void __goalAng(BH_PWORK* epw, NJS_POINT3* vec, NJS_POINT3* ans);
int _goalAng(BH_PWORK* epw);
int _goalAng2(BH_PWORK* epw);
void KeepFar(BH_PWORK* epw);
void Attack(BH_PWORK* epw);
void Throw(BH_PWORK* epw);
void Damage(BH_PWORK* epw);
void Die(BH_PWORK* epw);
int NearestCapsule(BH_PWORK* epw, NJS_POINT3* pos, NJS_CAPSULE* dest, short* jnt);
void CheckDamage(BH_PWORK* epw);
/*int GetRelay(BH_PWORK* epw, _MTN_RELAY** ret);*/
void SetMtn(BH_PWORK* epw);
void ReqMtn(BH_PWORK* epw, unsigned int mtn_no);
void SetPlyMtn(unsigned int mtn_no);
int VacumeToPoint(BH_PWORK* pw, NJS_POINT3* pos);
void LockLeg(BH_PWORK* epw);
int bhEne15_AttackPlayerCC(NJS_CAPSULE* cap, NJS_VECTOR* attack_v, int damage);
int bhEne15_AttackPlayerBC(NJS_BOX* box, NJS_VECTOR* attack_v, int damage);
int bhEne15_AttackPlayerSS(NJS_SPHERE* spr, NJS_VECTOR* attack_v, int damage);
void SetSmoke(NJS_POINT3* pos);
void SpecialAttack(BH_PWORK* epw, NJS_VECTOR* splash_v);
void _bhEne_SetPoison(BH_PWORK* epw, NJS_POINT3* ofp, short ry);
void _bhEne_SetPoison2(O_WRK* op, int type, NJS_POINT3* ofp);
/*void bhEne_SetPoison(BH_PWORK* epw, _anon37* bt);*/
void PoisonAttack(O_WRK* op);
void AddWindForce(O_WRK* op, float reg);
void bhEff_E15_Poison(O_WRK* op);
void bhEne15_RotChar(BH_PWORK* pw, int goal, int add_ang);
int AbleToFall(BH_PWORK* pp);
int _DrivePlayer();
void DrivePlayer(BH_PWORK* epw);
void FallingPlayer(BH_PWORK* epw);
void SlidePlayer(BH_PWORK* epw);
void StandupPlayer(BH_PWORK* epw);
void HoldPlayer(BH_PWORK* epw);
void FlyingPlayer(BH_PWORK* epw);
void FallDiePlayer(BH_PWORK* epw);
void DiePlayer(BH_PWORK* epw);
void ChangeAmbient(short* plist, unsigned char add);
void SetMince(BH_PWORK* epw, int type, int num);
void CoreInit(BH_PWORK* epw);
void CoreMove(BH_PWORK* epw);
void CoreDie(BH_PWORK* epw);
void bhEne53(BH_PWORK* epw);

#endif
