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
    - One of an Operating System's main goals is **Protection**
      - Protect applications from each other
      - Protect OS(kernel) from application
    - 1. Preventing application from **writing into privileged memory**
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

************************************

|Rings of privilege|
|----------------|
|ring 0 : Kernel|
|ring 1 : Device drivers|
|ring 2 : Device drivers|
|ring 3 : Applications|
    
* VM runs in ring 0, guest OS runs in ring 1 or 2, Apps run in ring 3.
* OS like runs in ring 0, Apps run in ring 3, and rings 1-2 are unused.

************************************


* **Mode changes, How Apps and the OS commucated**
    - System call between user mode(mode bit = 1) and kernel mode (mode bit = 0)
         - user process exe -> system call -> trap to the OS, interupt the exe of the software -> transfer control to the kernel , execute system call ->handle system call and reset the mode bit to 1 -> return to user from the system call
    - the **trap** instrcution is used to switch from user to supervisor mode, thereby enter the OS
        - trap sets the mode bit to 0
        - mode bit reset to 1

************************************

* **Trap Table**
    - The process of indexing into the trap table to jump to the trap handler routine is also called dispatching
    - the trap table is also called a jump table or a branch table
    - "A trap is a software interrupt"

************************************

* **System Call Parameter Passing**
    - Often, more information is required than simply identity of desired system call
        - exact type and amount of information vary according to OS and call
    - Three general methods used to pass parameters to the OS
        - Simplest: pass the parameters in registers
        - **Pointer**: Parameters stored in a block, or table, in memory, and address of block passed as a parameter in register
        - Parameters placed, or **pushed**, onto the **stack** by the program and **popped** off the stack by the Operating System.
     * Stardard C Library Example
        - C program invoking printf() library call, wich calls write() system call

************************************

* **How does an OS support multiple applications?**
    - Batching of jobs
    - executing continuously until program is finished
        - Poor utilization, maybe billions of wasted instruction cycles.(other program has to wait, compares to now day, we can make use of those free memory)
    - Multiprogramming :) (or Multiprogrammed batch system)
        - much efficient to share CPU
        - Submit your program, called a job,into a job queue, when CPU is availble, OS exe your job.
        - is not suitable with Interactive applications like the shell program(require waiting finish for programs)
    - limitation of Multiprogramming
         - Batch jobs are very non-interative
         - Don't support a shell application

************************************

* **Multitasking**

    - CPU rapidly switches between multiple programs
        - Each program gets a small slice of the CPU, then yields the CPU to another program
        - This switching happens often enough that each program still gets a fair percentage of the CPU, and call still make significant progress
        - At the same time, interactive programs like shells are now supported (**INNOVATION**)
     - **Advantage**
        - efficient CPU usage
        - Better isolation - a misbehaving program can't stop other programs from executing
        - supports interactivity
    - **Disadvantage**
        - Switching from one program to another is called a **context switch**
        - there is **overhead** due to this context switching
            - with each context switch, the CPU has to save the current state of application 1
            - and then load the state of the new application 2 when app 2 was last switched out
        - All of this takes time and no useful work can be done by program during a context switch
       
       
************************************ 

* **Cooperative Multitasking**
    - How does an OS achieve Multitasking
         - **Cooperative multitaksing**
            - voluntarily yield CPU before they're done (1 program wait for another to finish first)
            - problem with program hogs the CPU, the we are screwed!
         - **Preemptive multitaksing**
            - Force programs to release CPU 
            - OS forces rapid switching between multiple executing programs by setting a hardware timer
            - The timer periodically interruptes CPU execution, invoking OS scheduler to schedule the next program
            - Time Slices
                - Each program is given a short interval on the CPU called a time slice
            - **Benifits**
                - Efficient sharing of CPU
                - Fault isolation solved
                - Support for long-running jobs
                - Support for interactive programs
