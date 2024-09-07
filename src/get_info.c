#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <unistd.h>

#include "config.h" // contains definitions that should be configured by user
#include "get_info.h"

static int get_mem_info(struct mem_t *mem){
    long pages = sysconf(_SC_PHYS_PAGES);
    long free_pages = sysconf(_SC_AVPHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);

    if(pages == -1 || free_pages == -1 || page_size == -1){
        return 1;
    }
    
    mem->total = (pages * page_size)/1000000;
    mem->free = (free_pages * page_size)/1000000;
    
    return 0;
}

int get_info(struct info_t *info){

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
