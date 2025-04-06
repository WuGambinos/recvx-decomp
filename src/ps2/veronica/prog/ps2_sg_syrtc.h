#ifndef _SYRTC_H_
#define _SYRTC_H_

#include <libcdvd.h>

#include <ninja.h>
#include <sg_syrtc.h>

void syRtcFinish( void );
Sint32 syRtcGetDate( SYS_RTC_DATE *date );
Sint32 syRtcInit( void );

#endif
