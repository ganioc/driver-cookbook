cmd_/home/yango/project/driver-cookbook/chap2/dummy-code/dummy-code.ko := aarch64-linux-gnu-ld -r -EL  -maarch64elf -T ./scripts/module-common.lds -T ./arch/arm64/kernel/module.lds  --build-id  -o /home/yango/project/driver-cookbook/chap2/dummy-code/dummy-code.ko /home/yango/project/driver-cookbook/chap2/dummy-code/dummy-code.o /home/yango/project/driver-cookbook/chap2/dummy-code/dummy-code.mod.o ;  true