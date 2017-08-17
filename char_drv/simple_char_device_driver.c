#include <linux/module.h>
#include <linux/moduleparam.h> /* To add a module parameter to the kernel which can be accessed via sysfs and userspace */
#include <linux/fs.h> /* For Char Drv Support */

int count = 5;
module_param(count 	/* variable name */,
			int 	/*Data type*/,
			0644 	/*Permissions*/);


/* Refer to include/linnux/fs.h struct file_opreations to know the structure of the file_opreation parameters */

int simple_char_device_driver_open (struct inode *pinode, struct file *pfile)
{

	printk(KERN_ALERT"Inside %s Right Now\n",__FUNCTION__);
	return 0;
}

ssize_t simple_char_device_driver_read (struct file *pfile, char __user *buffer, size_t lenght, loff_t *offset)
{

	printk(KERN_ALERT"Inside %s Right Now\n",__FUNCTION__);
	return 0;
}

ssize_t simple_char_device_driver_write (struct file *pfile, const char __user *buffer, size_t lenght, loff_t *offset)
{

	printk(KERN_ALERT"Inside %s Right Now\n",__FUNCTION__);
	return lenght;
}

int simple_char_device_driver_release (struct inode *pinode, struct file *pfile)
{

	printk(KERN_ALERT"Inside %s Right Now\n",__FUNCTION__);
	return 0;
}

/* To hold the file operations performed on this device */
struct file_operations simple_char_device_driver_file_operations = {
		.owner 	= THIS_MODULE,
		.open 	= simple_char_device_driver_open,
		.read 	= simple_char_device_driver_read,
		.write 	= simple_char_device_driver_write,
		.release = simple_char_device_driver_release,
};

static __init int simple_char_device_driver_init(void)
{
	int i = 0;
	printk(KERN_ALERT"Inside %s Right Now\n",__FUNCTION__);

	
	/* Register with the kernel and indicate that we are registering  char device drv */
	register_chrdev(240 										/*Major Number*/,
					"Simple Char Device Drv"					/*Name of the drv*/,
					&simple_char_device_driver_file_operations	/*File Operations*/);
	
	
	for(i=0;i < count;i++)
	{
		printk(KERN_ALERT"Inside %s For Loop for the %d\n",__FUNCTION__,i);
	}
	
	return 0;
}
static void __exit simple_char_device_driver_exit(void)
{
	int i = 0;
	
	for(i=0;i < count;i++)
	{
		printk(KERN_ALERT"Inside %s For Loop for the %d\n",__FUNCTION__,i);
	}
	
	
	/* Unregister the char device drv */
	unregister_chrdev(240,"Simple Char Device Drv");
	
	
	printk(KERN_ALERT"Inside %s Right Now\n",__FUNCTION__);
	
	return;
}

module_init(simple_char_device_driver_init);
module_exit(simple_char_device_driver_exit);
MODULE_AUTHOR("Tarun93 <tarunmyid@gmail.com>");
// MODULE_NAME("Simple Char Drv")
MODULE_LICENSE("GPL");
