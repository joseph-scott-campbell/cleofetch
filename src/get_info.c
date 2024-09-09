#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <unistd.h>

#include "config.h" // contains definitions that should be configured by user
#include "get_info.h"

#ifdef FREE_BSD
    #include <sys/sysctl.h>
#endif

static int get_mem_info(struct mem_t *mem){
    long pages = sysconf(_SC_PHYS_PAGES); // get total pages
 
    // if OS is freebsd (needs to be defined in config.h) then use the freebsd
    // version of getting memeory
    #ifdef FREE_BSD
        long free_pages;
        size_t len = sizeof(free_pages);
        if (sysctlbyname("vm.stats.vm.v_free_count", &free_pages, &len,
                    NULL, 0) == -1) {
            printf("Error: getting free ram through sysctl\n");
            return 1;
        }
    #endif

    // if not freebsd use the linux version
    #ifndef FREE_BSD
        long free_pages = sysconf(_SC_AVPHYS_PAGES);
    #endif

    long page_size = sysconf(_SC_PAGE_SIZE);

    // if anything errored return error to get_info where it will print
    if(pages == -1 || free_pages == -1 || page_size == -1){
        return 1;
    }
    
    // use page information to calculate
    mem->total = (pages * page_size)/1000000;
    mem->free = (free_pages * page_size)/1000000;
    
    return 0;
}

int get_info(struct info_t *info){
    // take direct pointer to environment variable from shell
    info->shell = getenv("SHELL");
    info->terminal = getenv("TERM");
    info->user = getlogin();

    // exiting early on error
	if(uname(&info->uname) != 0){
        printf("ERROR: Unable to get uname information\n");
		return 1;
	}

    if(info->shell == NULL){
        printf("ERROR: $SHELL not set\n");
        return 1;
    }

    if(info->terminal == NULL){
        printf("ERROR: $TERM not set\n");
        return 1;
    }

    if(info->user == NULL){
        printf("ERROR: Not able to get user\n");
        return 1;
    }

    if(gethostname(info->hostname, sizeof(info->hostname)) != 0){
         printf("ERROR: Not able to get hostname\n");
         return 1;
    }
    
    if(get_mem_info(&info->mem)){
        printf("ERROR: Failed getting memory\n");
        return 1;
    }

    return 0;
}
