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

```shell
# 查看设备, /proc/devices文件可以看到设备的major number, 
# 有了驱动之后，还需要生成设备文件,
mknod chrdev c 237 0

dd if=/dev/zero bs=100 count=3 of=chrdev
cat chrdev | tr '\000' '0'


```

## chap 4 Device Tree,
所有的驱动都从dts来获得配置数据, DTS, Device Tree Source, DTB, Device Tree Binary,

```
dtc -v, 1.6.1

uboot, firefly-rk3568
RK_KERNEL_DEFCONFIG=firefly_linux_defconfig
RK_KERNEL_DEFCONFIG_FRAGMENT=rk356x_linux.config
RK_KERNEL_DTS=rk3568-firefly-roc-pc
RK_KERNEL_FIT_ITS=bootramdisk.its
DTC     arch/arm64/boot/dts/rockchip/rk3568-firefly-roc-pc.dtb
kernel/arch/arm64/boot/dts/rockchip/rk3568-firefly-roc-pc.dts


```

演示驱动如何读取DTS的信息,
```shell
return -EINVALID, 直接unload the module and return, 
sudo insmod get_dt_data.ko path=/cpus

# 接下来驱动使用DTS的信息来进行初始化,
probe,

platform driver, 

修改dts, 重新下载firefly img,
测试driver代码, 
首先安装chrdev.ko, 然后安装chrdev-req.ko, 否则会找不到, chrdev_device__register, chrdev_device_unregister,
ls -l /sys/devices/platform/chrdev/chrdev/
可以看见, cdev-eeprom@2, cdev-rom@4,
driver,?
of_node, ?
# 观察udev事件,
udevadm monitor -k -p -s chrdev
/dev/cdev-eeprom@2, /dev/cdev-rom@4,


```

如何给驱动下载软件呢？

```shell
request_firmware(), 驱动发起请求时，kernel开始在以下位置寻找
# boot image file, location,
# kernel command line, firmware_class.path="<path>",
# /lib/firmware/updates/<UTS_RELEASE>, kernel-release, uname -r
# /lib/firmware/updates/
# /lib/firmware/
# Generic Driver Options, Firmware loader entries,

# 实验读取firmware.bin给驱动，防止污染GPL环境
```

### 配置Pin脚,


```shell
# 查看uart的pin脚配置,
cat /sys/kernel/debug/pinctrl/
kernel/drivers/gpio/gpio-firefly.c,
2种gpio:
firefly-gpio,
firefly-irq-gpio,
ls 


```

## chap 5 中断和concurrency,


