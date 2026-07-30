#ifndef _EFFSUB4_H_
#define _EFFSUB4_H_

#include "types.h"

void bhEff_SetPtcl(BH_PWORK* epw, NJS_POINT3* pos, int tex_id);
void bhEff_SetPtcl1(BH_PWORK* epw, NJS_POINT3* pos, int tex_id, int wcnt);
void bhEff_SetPtcl2(NJS_POINT3* pos, float mtx[16]);
void bhEff_SetPtcl2V(NJS_POINT3* pos, NJS_POINT3* dv, int wcnt);
void bhEff_SetBlood5(NJS_POINT3* pos, NJS_POINT3* vec, float size, int col);
void bhEff_Sub350(O_WRK* op);
void bhEff_Sub351(O_WRK* op);
void bhEff_Sub352(O_WRK* op);
void bhEff_Sub353(O_WRK* op);
void bhEff_Sub354(O_WRK* op);
void bhEff_Sub355(O_WRK* op);
void bhEff_Sub356(O_WRK* op);
void bhEff_Sub357();
void bhEff_Sub360(O_WRK* op);
void bhEff_Sub361(O_WRK* op);
void bhEff_Sub362(O_WRK* op);
void bhEff_Sub363(O_WRK* op);
void bhEff_Sub364(O_WRK* op);
void bhEff_Sub365(O_WRK* op);
void bhEff_Sub366(O_WRK* op);
void bhEff_Sub367(O_WRK* op);
void bhEff_Sub368(O_WRK* op);
void bhEff_Sub369(O_WRK* op);
void bhEff_Sub370(O_WRK* op);
void bhEff_Sub371(O_WRK* op);
void bhEff_Sub372(O_WRK* op);
void bhEff_Sub373(O_WRK* op);
void bhEff_Sub398(O_WRK* op);
O_WRK* bhEff_AllocOwork();
void bhEff_PtclSpriteDraw(O_WRK* op);
void bhEff_LineDraw(O_WRK* op);
void bhEff_SetSprite(O_WRK* op, UV_WORK* uvp, int mode);
void bhEff_SetSpriteAnime(O_WRK* op, EFF_ANIM* eff_anim, UV_WORK* uvp, int mode);
void bhEff_3DSpriteDraw(O_WRK* op);
void bhEff_ModelDraw(O_WRK* op);

#endif
