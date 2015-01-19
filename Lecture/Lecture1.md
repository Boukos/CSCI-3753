Lecture 1 - Introduction
------------------------
 
Office Hour: Tuesday 1:30 - 2:30 pm 
			 Wednesday 1:30 - 2:30 pm

Moodle （Grading info）

Enrollment Key: osrocks15

*********************************************************************

What is an Operating System?
-----------------------------
* a layer of software between many applications/diverse hardware and hardware that provides useful services to applications.

System View of Operating System
---------------------------------

* From the computer’s point of view, the operating system is the program most intimately involved with the hardware. In this context, we can view an operating system as a resource allocator. A computer system has many resources that may be required to solve a problem: CPU time, memory space, file-storage space, I/O devices, and so on. The operating system acts as the manager of these resources. Facing numerous and possibly conflicting requests for resources, the operating system must decide how to allocate them to specific programs and users so that it can operate the computer system efficiently and fairly. As we have seen, resource allocation is especially important where many users access the same mainframe or minicomputer.

* A slightly different view of an operating system emphasizes the need to control the various I/O devices and user programs. An operating system is a control program. A control program manages the execution of user programs to prevent errors and improper use of the computer. It is especially concerned with the operation and control of I/O devices.

Computer System
----------------------
* **Hardware**
	- the central processing unit ( CPU ), the memory, and the input/output ( I/O ) devices—provides the basic computing resources for the system. 

* **Operating System**
	- for a single user, the goal is to maximize the work that the user is performing.In this case, the operating system is designed mostly for ease of use, with some attention paid to performance and none paid to resource utilization (how various hardware and software resources are shared.)
	- for user who use terminal connected to a mainframe or a minicomputer, other users are accessing the same computer through other terminals.These users share resources and may exchange information. The operating system in such cases is designed to maximize resource utilization — to assure that all available CPU time, memory, and I/O are used efficiently and that no individual user takes more than her fair share.

* **Application**: Chrome, Office, games etc.
	- define the ways in which these resources are used to solve users’ computing problems.
* **I/O** : Mouse, Keyboard, Display etc.


Storage Structure
-----------------
* **volatile storage** loses its contents when the power to the device is removed. In the absence of expensive battery and generator backup systems, data must be written to **nonvolatile storage** for safekeeping.



|Storage Hierarchy|
|----------------|
|register|
|cache           |
|main memory     |
|solid-state disk|
|magnetic disk   |
|optical disk    |

* The wide variety of storage systems can be organized in a hierarchy according to speed and cost. The higher levels are expensive, but they are fast. As we move down the hierarchy, the cost per bit generally decreases, whereas the access time generally increases.

I/O Structure
-------------
* **device driver**: software that understands the device controller and provides the rest of the operating system with a uniform interface to the device
* **device controller**: The controller is the hardware(chips) that controls the communication between the system and the peripheral(外围) drive unit (for example : a disc drive). 
* **register** : The amount of information(storage) that a processor can process at once.

*********************************************************************
|To start an I/O operation:|
|----------------------------|
|- 1. the device driver loads the appropriate registers within the device controller.|
|- 2. The device controller, in turn, examines the contents of these registers to determine what action to take (such as “read a character from the keyboard”).|
|- 3. The controller starts the transfer of data from the device to its local buffer.|
|- 4. Once the transfer of data is complete, the device controller informs the device driver via an interrupt that it has finished its operation. |
|- 5. The device driver then returns control to the operating system, possibly returning the data or a pointer to the data if the operation was a read. For other operations, the device driver returns status information.|

*********************************************************************

* This form of interrupt-driven I/O is fine for moving small amounts of data but can produce high overhead when used for bulk data movement such as disk I/O. To solve this problem, direct memory access (DMA) is used. After setting up buffers, pointers, and counters for the I/O device, the device controller transfers an entire block of data directly to or from its own buffer storage to memory, with no intervention by the CPU. Only one interrupt is generated per block, to tell the device driver that the operation has completed, rather than the one interrupt per byte generated for low-speed devices. While the device controller is performing these operations, the CPU is available to accomplish other work.

Kernel
-------
* A more common definition, and the one that we usually follow, is that the operating system is the one program running at all times on the computer—usually called the kernel. 
	- Along with the kernel, there are two other types of programs: system programs, which are associated with the operating system but are not necessarily part of the kernel, and application programs, which include all programs not associated with the operation of the system.


O.S Functionality (OS "Kernel")
------------------------------------
* Arbitrates access to resources among multiple applications
* Provides Protection


O.S Components
---------------
* A typical OS consists of multiple components
	- A process manager with a scheduler, thread management, and atomic synchronization
	- Memory management (virtual memory) system (applications to memory)
	- file system (applications to disk)
	- device management (applications to display)
	- others ...




Monolithic vs Microkernel OS Architectures
------------------------------------------
* Monolithic kernel is highly complex and contains many components (linux)
* Microkernel has minimal functionality, perhaps only vm, scheduler, and IPC message passing (old MacOX)




Distributed OS
---------------
* watch slides









