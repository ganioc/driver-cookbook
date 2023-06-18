/*
* Dummy code
*/

#include <linux/module.h>

static int __init dummy_code_init(void){
    printk(KERN_INFO "dummy-code loaded\n");
    return 0;
}
static void __exit dummy_code_exit(void){
    printk(KERN_INFO "dummy-code unloaded\n");

}

module_init(dummy_code_init);
module_exit(dummy_code_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yang O3");
MODULE_DESCRIPTION("Dummy Code");


