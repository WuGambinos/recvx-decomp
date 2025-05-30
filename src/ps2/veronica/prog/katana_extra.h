#include <sg_bup.h>

// TODO: include sg_sybt.h and remove the below struct
struct tag_SYS_BT_SYSTEMID{                   /*                    */
    Sint32 nNo ;                              /*                    */
    Sint32 nAll ;                             /*                    */
    Sint8  szProduct[16];                     /*                    */
} ;                                           /*                    */
typedef struct tag_SYS_BT_SYSTEMID SYS_BT_SYSTEMID ;

/******** ?申?申?申?申?申?申?申J?申[?申h?申?申?申\?申?申?申?申 *******************************************/
/******** Memory card information structure ********************************/
typedef struct {
	Uint16 Ready;               /* ?申?申?申?申?申?申?申J?申[?申h?申?申?申}?申E?申?申?申g?申?申?申?申��鐃�?申���      */
	                            /* Is memory card mounted ?                */
	Uint16 IsFormat;            /* ?申t?申H?申[?申}?申b?申g?申?申?申?申��鐃�?申���?申��鐃�?申?申          */
	                            /* Is memory card formatted ?              */
	Uint32 LastError;           /* ?申��鐃宿�鐃�?申?申?申?申?申?申?申G?申?申?申[?申R?申[?申h              */
	                            /* Error code which occured last.          */
	Uint32 ProgressCount;       /* ?申?申?申?申?申o?申��J?申E?申?申?申g                        */
	                            /* Operation progress count.               */
	Uint32 ProgressMax;         /* ?申?申?申?申?申o?申��J?申E?申?申?申g?申��鐃�                    */
	                            /* Operattion progress count maximum.      */
	Uint32 Operation;           /* ?申?申?申?申?申?申?申��I?申y?申?申?申[?申V?申?申?申?申?申R?申[?申h            */
	                            /* Operation code in handling now.         */
	BUS_DISKINFO DiskInfo;      /* ?申h?申?申?申C?申u?申?申?申                            */
	                            /* Drive information.                      */
	Uint32 Connect;             /* ?申?申?申?申?申?申?申[?申J?申[?申h?申?申?申��鐃�?申?申?申?申��鐃�?申���        */
	                            /* Is memory card connected ?              */
	void* Work;                 /* ?申?申?申[?申N?申A?申h?申?申?申X                          */
	                            /* Work address.                           */
	Uint32 WorkSize;            /* ?申?申?申[?申N?申T?申C?申Y                            */
	                            /* Work size (bytes).                      */
	Uint32 Capacity;            /* ?申?申?申?申?申?申?申J?申[?申h?申��e?申��t?申?申?申O(BUD_CAPACITY)  */
	                            /* Capacity flag of memory card.           */
    Sint32 MemMode;             // manually added
} BACKUPINFO;

/*===============================================================*/
/* ?申��鐃�?申?申?申��??申?申?申?申?申[?申J?申[?申h?申����鐃�e?申?申                              */
/* Mamimum volume to use.                                        */
/*===============================================================*/

#define MAX_CAPS BUD_CAPACITY_1MB

/*===============================================================*/
/* ?申��鐃�?申?申?申��??申?申?申?申?申[?申J?申[?申h?申��h?申?申?申C?申u?申?申                            */
/* Number of memory card to use.                                 */
/*===============================================================*/

#define MAX_DRIVES 8
#define USE_DRIVES BUD_USE_DRIVE_ALL

#define set_imask(mask)             _builtin_set_imask(mask)

/* SH-4 program area address. */
#define P1AREA   0x80000000

/* Define work RAM end address (16 MB). */
#define WORK_END (((Uint32) _BSG_END) & 0xe0000000 | 0x0d000000)

#define HEAP_AREA ((void*) ((((Uint32) _BSG_END | P1AREA) & 0xffffffe0) + 0x20))
#define HEAP_SIZE (WORK_END - (Uint32) HEAP_AREA)