Contact Info: Yu Zhou (100630825)   
Email: yu.zhou@colorado.edu

Files:
----------
* helloworld.c 
	- system call for helloworld
	- store in x86/kernel
* Makefile
	- a general Makefile 
	- store in x86/kernel

* simple_add.c
	- system call for simple_add
	- store in x86/kernel

* syscall_x64.tbl
	- adding the system call into a 64 bit system call section
	- store in x86/syscalls

* syscalls.h
	- header files contains prototype of the system calls
	- include/linux

* syslog
	- a log that shows the system call'
	- include/log

* test_add_number.c  & test_helloworld.c
	- test files
	- run anywhere, doesn't matter


Instructions for building and running 
-----------------------------------------

* 1. move helloworld.c & simple_add.c to  /home/kernel/linux-3.13.0/arch/x86/kernel/
* 2. move Make file to  arch/x86/kernel/
* 3. move syscall_64.tbl to    arch/x86/syscalls/
* 4. move syscalls.h into include/linux
* 5. compile the kernel
* 6. compile and run the test code
* 7. check result from syslog
* 8. done


