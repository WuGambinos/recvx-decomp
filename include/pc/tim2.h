#ifndef _TIM2_H_
#define _TIM2_H_

#include <stdint.h>

typedef struct TIM2_FHEADER {
    int8_t FileId[4];
    uint8_t FormatVersion;
    uint8_t FormatId;
    uint16_t Pictures;
    int8_t Reserved[8];
} TIM2_FHEADER;

typedef struct TIM2_PHEADER {
    uint32_t TotalSize;
    uint32_t ClutSize;
    uint32_t ImageSize;
    uint16_t HeaderSize;
    uint16_t ClutColors;
    uint8_t PictFormat;
    uint8_t MipMapTextures;
    uint8_t ClutType;
    uint8_t ImageType;
    uint16_t ImageWidth;
    uint16_t ImageHeight;
    uint64_t GsTex0;
    uint64_t GsTex1;
    uint32_t GsRegs;
    uint32_t GsTexClut;
} TIM2_PHEADER;

#endif
