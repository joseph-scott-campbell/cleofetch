# Cleofetch (Yet Another Neofetch Clone)

Cleofetch is a neofetch clone written in Posix Compliant C. It is more of a fun
afternoon project than a serious command line utility, but it does have a few
genuine advantages.

* Simple, readable, maintainable C
* Significantly faster than Neofetch
* Maintained

If you just want neofetch functionality with reasonable performance there are
other projects that offer a better utility such as
[fastfetch](https://github.com/fastfetch-cli/fastfetch).

## Installation

```
# cloning relevant files
git clone https://github.com/joseph-scott-campbell/cleofetch.git 

cd cleofetch.git # entering cleofetch directory

# editing config file, replace with OS of choice if supported
sed -i '1i #define ARCH_LINUX\n' include/config.h

make # compile

# /usr/bin on GNU/Linux, /usr/local/bin on FreeBSD
cp cleofetch </directory/in/your/path> 

cleofetch # test if it worked
```

## FAQ

### Q: My OS of choice does not have an icon

I only made icons for FreeBSD and Arch Linux because that is what I use, if
you would like icons for your OS of choice feel free to create a pull
request with a new icon.

To create a new icon simply added a new `#define ICON` string to 
`include/config.h` surrounded by `#ifdef <MY_OS>` and `#endif`. 

Unfortunately Windows will likely never be supported outside of WSL because it
does not have `unistd.h`.

### Q: Why is this configured through config.h

I chose to configure this through `config.h` because it reduces the amount of
code needed while still maintaining the desired functionality. One of the goals
of this project is using the minimal amount of code.

### Q: Why should I use this over fastfetch or neofetch

Most people should use neofetch or fastfetch, they are more feature complete
and do the job just fine. 

Cleofetch offers two main advantages:
* The code is simple enough to be thoroughly audited in less than an hour
* It is faster than both neofetch and fastfetch

If you are not the special kind of power user that likes to read all of the code
they use, or are very concerned with how fast you can check your system
information the other options are better for you.
