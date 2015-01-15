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

Computer System
----------------------
* Hardware
	-the central processing unit ( CPU ), the memory, and the input/output ( I/O ) devices—provides the basic computing resources for the system. 

* Operating System
	-for a single user, the goal is to maximize the work that the user is performing.In this case, the operating system is designed mostly for ease of use, with some attention paid to performance and none paid to resource utilization (how various hardware and software resources are shared.)
	-for user who use terminal connected to a mainframe or a minicomputer, other users are accessing the same computer through other terminals.These users share resources and may exchange information. The operating system in such cases is designed to maximize resource utilization — to assure that all available CPU time, memory, and I/O are used efficiently and that no individual user takes more than her fair share.

* Application: Chrome, Office, games etc.
	- define the ways in which these resources are used to solve users’ computing problems.
* I/O : Mouse, Keyboard, Display etc.


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









