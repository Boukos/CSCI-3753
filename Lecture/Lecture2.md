Lecture 2: Kernel Mode, Traps, System Calls, Multitasking
----------------------------------------------------------

* Announcements : PA #1 due Monday Jan 26  by 8 am
    - Add a system call to Linux
    
* Read chapters 1-2 & 13
**************************************

Recap
------
* An OS is a software layer that sits between applications and I/O devices
  - Main Goals: Abstraction, Arbitration, & Protection

* An OS consists of many componets
  - Memory manager, Scheduler, File System , Device Management, Network Stack, etc
  
* Linux is a monolithic kernel - complex ,contains many componets

* Mach OS is a microkernel - kernel only contains scheduler, memory manager, and messaging

******************************************************************************************************************

Lecture
--------

* **Protection in Operating Systems**
    - One of an Operating System's main goals is Protection
      - Protect applications from each other
      - Protect OS(kernel) from application
    - 1. Preventing application from writing into privileged memory
        - Memory protection via VM: 
           - Recall that an executable only has virtual address.
           - These are translated into physical memory addresses at run time by a page table
           - OS controls the page table (prevent programs to write to others physic memory page)
                - any virtual address given to memory manageer is translated into a non-conflicting physical adress
                - Access to the wrong memory causes a page fault
    - 2. Protecting the OS via a Mode Bit
        - Processors include a hardware mode bit that identifies whether the system is in user mode or supervisor/kernel mode
              - requires extra support from the cpu hardware for this OS feature
        - Prevents applications from executing privileged instructions
              - Can't reset time slice register, or change interrupt vector register, ...
        - Embedded microcontrollers don't have mode bit
        - Intel 80286 added mode bit in 1982
      

* **Kernel Mode vs User Mode**
    - Supervisor 
        - Can execute all machine instruction, reference all memory and Kernel runs in this.
    - User
        - screwed.
* **Rings of privilege**
   - ring 0 = Kernel
    - ring 1 = Device drivers
    - ring 2 = Device drivers
    - ring 3 = Applications
   * VM runs in ring 0, guest OS runs in ring 1 or 2, Apps run in ring 3.
   * OS like runs in ring 0, Apps run in ring 3, and rings 1-2 are unused.
  








