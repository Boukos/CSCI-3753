Recitation 1
----------------------


* TA: Rahat Ibn Rafiq
* Email: rahat.rafiq@colorado.edu 

 Lecture
 --------

 * **Kernel** 
 	- userspace -> Kernel -> Harddisk
 	- open a file in the harddisk, need to go through Kernel
 		- function open() call Kernel --> Kernel with some function system call --> Harddisk

* **Userspace** 
	- on the same machine:
		- User A  write  programs p1
		- User B  write  programs p2
		- can User A access User B ? no
		- if use some C program to hack Kernel, then you can access all userspace

why VM > Linux for writing assignment : when you mess with Kernel, is very dangrous.

Lab
------
* **Grub**
	-Grub is the boot loader installed with Ubuntu 10.04. It provides configuration options
to boot from a list of different kernels available on the machine. 
	
	- 1. sudo gedit/etc/default/grub
	- 2. sudo grub-update
	- 3. sudo reboot

* **Source Code**
	- 1. cd\home
	- 2. sudo mkdir Kernel
	- 3. cd Kernel
	- 4. sudo apt-get source linux-image-$(uname -r)


* **Compile**
	- 1. sudo apt-get install ccache  //make it faster to recompile
	- 2. sudo make localconfig
	- 3. sudo make menuconfig
	- 4. sudo make -j2 CC="ccache gcc" //comepile everything , -j2 = 2 core running
	- 5. sudo make -j2 modules_install
	- 6. sudo make -j2 install
	- 7. sudo reboot

* **Write System's Call**
	- 1. printk : print in the log file in var/log/syslog
		- display lately print from printk: sudo tail var/log/stslog
	- 2. system call always return 0 or -1


* system call code
	```c

	int main()
	{
		int x = SYSCALL(318);
		printf(x)
	}
 	```


Homework
--------
	```c
	sys_simadd(int a, int b, int *ret)
	{
		printk(a, b) //print log file
		ret = a+b
		return 0
	}

	int main()
	{
		a,b,ret
		int x = SYSCALL(318, 10, 20, &c)
		printf(x); // 0  --> return 0 meaning sucsess
		print(c); // 30 --> return a value stored in pointer c
	}
	```








