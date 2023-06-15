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

