#ifndef GET_INFO_H_
#define GET_INFO_H_

#include <unistd.h>
#include <sys/utsname.h>

#include "config.h"

struct mem_t{
    long free; // free memory in megabytes
    long total; // total memory in megabytes
};

struct info_t{
    char *shell;
    char *terminal;
    char *user;
    char hostname[HOSTNAME_SIZE];
    struct mem_t mem;
    struct utsname uname;
};

int get_info(struct info_t *info);

#endif
