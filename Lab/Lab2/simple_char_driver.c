

#include<linux/init.h>
#include<linux/module.h>

#include<linux/fs.h> //function related to the device driver
#include<asm/uaccess.h> //enable data translation from user to kernel

#define BUFFER_SIZE 1024
#define MAJOR 255
#define DEV_NAME "simple_char_device"

static char device_buffer[BUFFER_SIZE];
static int openCount = 0;
static int closeCount = 0;

 



ssize_t simple_char_driver_read (struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
	/* *buffer is the userspace buffer to where you are writing the data you want to be read from the device file*/
	/*  length is the length of the userspace buffer*/
	/*  current position of the opened file*/
	/* copy_to_user function. source is device_buffer (the buffer defined at the start of the code) and destination is the userspace 		buffer *buffer */

	/* Transfering data to user space */ 
  	copy_to_user(buffer,device_buffer,1);

  	/* Changing reading position as best suits */ 
  	if (*offset == 0)
  	{ 
    	*offset+=1; 
    	return 1; 
  	} 
  	else
  	{ 
    	return 0; 
  	}
  	printk(KERN_ALERT "Reading from device.\n");
}



ssize_t simple_char_driver_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
	/* *buffer is the userspace buffer where you are writing the data you want to be written in the device file*/
	/*  length is the length of the userspace buffer*/
	/*  current position of the opened file*/
	/* copy_from_user function. destination is device_buffer (the buffer defined at the start of the code) and source is the userspace 		buffer *buffer */
	
	//return length;
	char *temp;

  	temp = buffer+length-1;
  	copy_from_user(device_buffer,temp,1);
  	return 1;
  	printk(KERN_ALERT "Wrote %d bytes to device.\n", length);
	return length;
}


int simple_char_driver_open (struct inode *pinode, struct file *pfile)
{
	/* print to the log file that the device is opened and also print the number of times this device has been opened until now*/
	openCount++;
	printk(KERN_ALERT "Open Device. Count is now: %d\n",openCount);
	
	return 0;
}


int simple_char_driver_close (struct inode *pinode, struct file *pfile)
{
	/* print to the log file that the device is closed and also print the number of times this device has been closed until now*/
	closeCount++;
	printk(KERN_ALERT "CLose Device. Count is now: %d\n",closeCount);
	return 0;
}

struct file_operations simple_char_driver_file_operations = {
	/* add the function pointers to point to the corresponding file operations. look at the file fs.h in the linux souce code*/
	.owner = THIS_MODULE,
		.open = simple_char_driver_open,
		.release = simple_char_driver_close,
		.read = simple_char_driver_read,
		.write = simple_char_driver_write,

	
};

static int simple_char_driver_init(void)
{
	/* print to the log file that the init function is called.*/
	/* register the device */
	register_chrdev(MAJOR,DEV_NAME,&simple_char_driver_file_operations);
	return 0;
}

static int simple_char_driver_exit(void)
{
	/* print to the log file that the exit function is called.*/
	/* unregister  the device using the register_chrdev() function. */
	unregister_chrdev(MAJOR,DEV_NAME);
	return 0;
}

/* add module_init and module_exit to point to the corresponding init and exit function*/
module_init(simple_char_driver_init);
module_exit(simple_char_driver_exit);
