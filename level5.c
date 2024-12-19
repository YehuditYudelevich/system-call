#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yehudit Yudelevich");
MODULE_DESCRIPTION("A simple kernel module to write to a file");
MODULE_VERSION("1.0");
:
static int __init start_module(void) {
    struct file *file; 
    loff_t pos = 0; 
    const char *buf = "Hi, writing to a file using kernel module\n";
    ssize_t ret; 

  
    file = filp_open("/tmp/level5.txt", O_WRONLY | O_CREAT, 0644);
    if (IS_ERR(file)) {
        printk(KERN_ALERT "Failed to open /tmp/level5.txt\n");
        return PTR_ERR(file);
    }
    ret = kernel_write(file, buf, strlen(buf), &pos);
    if (ret < 0) {
        printk(KERN_ALERT "Failed to write to /tmp/level5.txt\n");
    } 
    filp_close(file, NULL);

    printk(KERN_INFO "File /tmp/level5.txt created successfully.\n");
    return 0;
}
static void __exit stop_module(void) {
    printk(KERN_INFO "Kernel module stopped.\n");
}

module_init(start_module);
module_exit(stop_module);
