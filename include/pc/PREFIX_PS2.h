#ifndef	__PREFIX_PS2__
#define	__PREFIX_PS2__

/*	pragma	*/
#include <PRAGMA_PS2.h>

/*	mips	*/
#define mips
#define _mips
#define __mips__
/*	MIPSEL	*/
#define MIPSEL
#define _MIPSEL
#define __MIPSEL__
/*	R5900	*/
#define R5900
#define _R5900
#define __R5900__
/*	ee	*/
#define	__ee__

/*	floating point	*/
#if	1
	#define __mips_single_float
#else
	#define __mips_soft_float
#endif

/*	c/c++ language	*/
#define __STDC__

#ifdef __cplusplus
	#define	LANGUAGE_C_PLUS_PLUS
	#define	_LANGUAGE_C_PLUS_PLUS
	#define	__LANGUAGE_C_PLUS_PLUS
#else
	#define	LANGUAGE_C
	#define	_LANGUAGE_C
	#define	__LANGUAGE_C
#endif

/*	typedef	*/
#ifndef	long128
typedef	signed __int128		long128;
#endif
#ifndef	u_long128
typedef	unsigned __int128	u_long128;
#endif

/*	__ATTRIBUTE_IMPURE_PTR__	*/
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__section__(".data")))

#endif	/* __PREFIX_PS2__ */
