
Lecture 2: Kernel Mode, Traps, System Calls, Multitasking
----------------------------------------------------------

* Announcements : PA #1 due Monday Jan 26  by 8 am
    - Add a system call to Linux
    
* Read chapters 1-2 & 13
:alien:


Recap
------
* An OS is a software layer that sits between applications and I/O devices
  - Main Goals: **Abstraction**, **Arbitration**, & **Protection**

* An OS consists of many componets
  - **Memory manager**, **Scheduler**, **File System** , **Device Management**, **Network Stack**, etc
  
* Linux is a monolithic kernel - complex ,contains many componets

* Mach OS is a microkernel - kernel only contains scheduler, memory manager, and messaging

:heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign::heavy_minus_sign:


Lecture
--------
:facepunch::facepunch:

Operating-System Services
--------------------------
* An operating system **provides an environment** for the execution of programs.
It provides certain services to programs and to the users of those programs.

******************************************************************************

* **Service provide to user**

|Service|Functions|
|-------|---------|
| **User Interface** |:v:|
| **Program execution** | load program into memory and run|
|**I/O operations**|required for a running program|
|**File-system manipulation**|to read and write files and directory|
|**Communication**| A program triggers the other|

* **Service for the sake of the computer**

|Service|Functions|
|-------|---------|
|**Resource allocation**| allocate resources|
|**Accounting**| so software can keep track of usage and charge us :no_mouth:|
|**Protection**| stop one process from interfereing with other|



* **Protection in Operating Systems**
    * Preventing application from **writing into privileged memory**
        - Memory protection via VM: 
           - Recall that an executable only has virtual address.
           - These are translated into physical memory addresses at run time by a page table
           - OS controls the page table (prevent programs to write to others physic memory page)
                - any virtual address given to memory manageer is translated into a non-conflicting physical adress
                - Access to the wrong memory causes a page fault



System Calls :neckbeard::neckbeard:
--------------------------------
   * a system call is how a program **requests a service** from an operating system's kernel
        - to create a file, the program needs to request a service from the operating system

******************************************************************************

   * **API vs. System Call**
        - Application Programming interface specifies a set of functions that available to an application programmer
            - example, github provide an API that allows us to type "git push" 
            - Behind the scenes, the function that make up an API typically invoke the actual system calls

    
![**System Call Flow](http://www.cs.iit.edu/~cs561/cs450/syscalls/2.jpg)

* **System Call Interface**
        - link to system calls made available by the operating system. (a link to the system call table ex: #319)
        - has some command involve to call the trap table (something like syscall(319))

* **Trap Table**
    - The process of indexing into the trap table to jump to the trap handler routine is also called dispatching
    - the trap table is also called a jump table or a branch table
    - "A trap is a software interrupt"

* **System Call Parameter Passing**
    - Three general methods used to pass parameters to the OS
        - 1. pass the parameters in registers
        - 2. **Pointer**: Parameters stored in a block, or table, in memory, and address of block passed as a parameter in register
        - 3. Parameters placed, or **pushed**, onto the **stack** by the program and **popped** off the stack by the Operating System.


:exclamation:O.S vs. multiple applications?:exclamation:
------------------------------------














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
<<<<<<< HEAD
            - Don't support a shell application
            - design jobs to yield much sooner than an I/O block, to give the impression of interactivity
<<<<<<< HEAD
<<<<<<< HEAD


************************************

* **Multitasking**

>>>>>>> 9f5b70e432d2a9775bfdbbf4841b3f9d90ccf322
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
<<<<<<< HEAD
        
<<<<<<< HEAD
<<<<<<< HEAD
=======
       
       
************************************ 
>>>>>>> 9f5b70e432d2a9775bfdbbf4841b3f9d90ccf322

* **Cooperative Multitasking**
<<<<<<< HEAD
>>>>>>> parent of d6b5e3d... Kernel Mode, Traps, System Calls, Multitasking
=======
* **Cooperative Multitasking**
>>>>>>> parent of d6b5e3d... Kernel Mode, Traps, System Calls, Multitasking
=======
>>>>>>> 9f5b70e432d2a9775bfdbbf4841b3f9d90ccf322
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
