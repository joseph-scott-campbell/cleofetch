// Cleofetch, a neofetch clone written in C
// Written by Scott Campbell 9/1/2024
// Licensed AGPLv3 https://www.gnu.org/licenses/agpl-3.0.en.html

#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <unistd.h>

#include "config.h" // contains definitions that should be configured by user
#include "get_info.h"

int main(){
    struct info_t info;
    int ret = get_info(&info);

    // getinfo prints error message
    if(ret != 0){
        return ret;
    }

    printf(ICON, EMPHASIS_COLOR, info.user, RESET_COLOR, EMPHASIS_COLOR,
            info.hostname, RESET_COLOR, info.uname.nodename,
            info.uname.machine, info.uname.release, info.terminal,
            info.shell, info.mem.free, info.mem.total);

   return 0;
}
