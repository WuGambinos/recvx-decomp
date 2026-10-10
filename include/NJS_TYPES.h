#ifndef NJS_TYPES
#define NJS_TYPES

#include <stdint.h>
#include <stdbool.h>

#include <recvx-decomp-cri/cri/mwlib/include/cri_adxt.h>

// Type Definitions
//
#ifndef	long128
typedef	signed __int128		long128;
#endif
#ifndef	u_long128
typedef	unsigned __int128	u_long128;
#endif

typedef uint8_t    Uint8;
typedef int8_t     Sint8;

typedef uint16_t    Uint16;
typedef int16_t     Sint16;

typedef uint32_t    Uint32;
typedef int32_t     Sint32;

typedef uint64_t    Uint64;
typedef int64_t     Sint64;

typedef float Float;
typedef float Float32;
typedef double  Float64;

typedef int     Int;
typedef int32_t  Angle;
typedef Float   NJS_MATRIX[16];
typedef Float NJS_FOG_TABLE[128];

typedef bool Bool;
typedef void Void;

#define NULL 0


typedef uint8_t    Uint8;
typedef int8_t     Char8;

typedef uint16_t    Uint16;
typedef int16_t     Short16;

typedef uint32_t    Uint32;
typedef int32_t     Int32;

typedef uint64_t    Uint64;
typedef int64_t     Long64;

// SCE types
typedef unsigned char  u_char;
typedef unsigned short u_short;
typedef unsigned int   u_int;
typedef unsigned long  u_long;

#endif
