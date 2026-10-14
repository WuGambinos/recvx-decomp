#include <stdio.h>
#include <rxi/log.h>

#include "stubs.h"

int main() {
    printf("Hello World\n");
    log_info("RECVX PORT");

    // INIT
    log_debug("njUserInit");
    njUserInit();

    // MAIN
    log_debug("njUserMain");
    njUserMain();

    /*
    log_debug("njUserMain");
    njUserMain();

    log_debug("njUserMain");
    njUserMain();
    */

    // EXIT
    log_debug("njUserExit");
    njUserExit();
}
