# Book
Linux Device Driver Development Cookbook

# Projects
## chap1

```shell
make CFLAGS="-Wall -O2" helloworld
# cross compiler
aarch64-linux-gnu-gcc --version

make CC=aarch64-linux-gnu-gcc CFLAGS="-Wall -O2" helloworld

# 使用qemu运行 
$ qemu-aarch64-static  -L /usr/aarch64-linux-gnu/ ./helloworld

```

### Adding Debian files,
使用debootstrap,

```
sudo debootstrap  \
    --arch=arm64  \
    --include="sudo,file,openssh-server"  \
    --exclude="debfoster"  \
    stretch ./debian-stretch-arm64  \
    http://deb/debian.org/debian

```

## chap 2 , A peek inside the kernel

```

ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- make Image dtbs modules

KERNEL_DIR=/home/yango/project/rk3568/firefly/rk356x_linux_release_v1.3.0b/rk356x_linux_release/kernel  make

sudo insmod module_par  
sudo rmmod
sudo ls /sys/module/module_par/parameters/
 
```

## chap 3 a Char Drivers,
推荐书籍: <gnulinux-rapid-embedded-programming>

