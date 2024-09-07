#define HOSTNAME_SIZE 256 // change if you have a really long hostname
                          // not buffer overflow because gethostname checks size

#define EMPHASIS_COLOR "\033[34m" // code to set terminal color, default blue
#define RESET_COLOR "\033[0m" // resets terminal to default color


#ifdef ARCH_LINUX

#define ICON "\
    \033[34m                   -`            \033[0m   %s%s%s@%s%s%s\n\
    \033[34m                  .o+`           \033[0m ---------------------------\n\
    \033[34m                 `ooo/           \033[0m   OS: %s        \n\
    \033[34m                `+oooo:          \033[0m   Arch: %s      \n\
    \033[34m               `+oooooo:         \033[0m   Version: %s   \n\
    \033[34m               -+oooooo+:        \033[0m   Terminal: %s  \n\
    \033[34m             `/:-:++oooo+:       \033[0m   Shell: %s     \n\
    \033[34m            `/++++/+++++++:      \033[0m   Memory: %ld MB / %ld MB Free\n\
    \033[34m           `/++++++++++++++:     \033[0m\n \
    \033[34m          `/+++omoooooooooo/`    \033[0m\n \
    \033[34m         ./ooosssso++osssssso+`  \033[0m\n \
    \033[34m        .oossssso-````/ossssss+` \033[0m\n \
    \033[34m       -osssssso.      :ssssssso.\033[0m \n \
    \033[34m      :osssssss/        osssso+++. \033[0m\n \
    \033[34m     /ossssssss/        +ssssooo/-  \033[0m\n \
    \033[34m   `/ossssso+/:-        -:/+osssso+- \033[0m\n \
    \033[34m  `+sso+:-`                 `.-/+oso: \033[0m\n \
    \033[34m `++:.                           `-/+/ \033[0m\n \
    \033[34m .`                                 `/  \033[0m\n \
    "

#endif

#ifdef FREE_BSD

#define ICON "\
    \033[31m              ,        ,        \033[0m   %s%s%s@%s%s%s\n\
    \033[31m             /(        )`       \033[0m ---------------------------\n\
    \033[31m             \\ \\___   / |       \033[0m  OS: %s        \n\
    \033[31m             /- _  `-/  '       \033[0m  Arch: %s      \n\
    \033[31m            (/\\/ \\ \\   /\\       \033[0m  Version: %s   \n\
    \033[31m            / /   | `    \\      \033[0m  Terminal: %s  \n\
    \033[31m            O O   ) /    |      \033[0m  Shell: %s     \n\
    \033[31m            `-^--'`<     '      \033[0m  Free Memory: %ld MB / %ld MB \n\
    \033[31m           (_.)  _  )   /       \033[0m  \n\
    \033[31m            `.___/`    /        \033[0m  \n\
    \033[31m              `-----' /         \033[0m  \n\
    \033[31m <----.     __ / __   \\         \033[0m  \n\
    \033[31m <----|====O)))==) \\) /====     \033[0m  \n\
    \033[31m <----'    `--' `.__,' \\        \033[0m  \n\
    \033[31m              |        |        \033[0m  \n\
    \033[31m               \\       /        \033[0m  \n\
    \033[31m         ______( (_  / \\______  \033[0m  \n\
    \033[31m       ,'  ,-----'   |        \\ \033[0m  \n\
    \033[31m       `--{__________)        \\/\033[0m  \n\
    \n"

#endif

