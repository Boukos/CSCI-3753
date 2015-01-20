Lecture 3 : Device I/O , Interupt
------------------------------------
* Chapter 13 (I/O) for this Lecture

Recap
-------
  * 1. Mode bit for kernel mode vs. user mode (O.S protection)
  * 2. System calls
      - Special trap assembly instruction invokes OS, passing the system call #
      - Trap table
      - Different classes
  * 3. Efficient CPU usage
      - Batch mode multiprogramming
      - Multitasking
      

Lecture
-------

******************************************

Multitasking & Abstract Machines
----------------------------------
* CPU is time-multiplexed between multiple programs
  - Programs share the CPU

* Memory is space-multiplexed between multiple programs
  - programs share RAM
 
* Each program thus sees its own abstract machine

******************************************

Von Neumann Computer Architecture
----------------------------------
 * digital computer in which memory stored both instructions and data
 * CPU **stores info** , so it erase the mess when doing computation 
 * System bus evolved to handle multiple I/O devices

******************************************

Modern Computer Archiecture
-----------------------------
* **Insert the picture**
* CPU Bus interface <-system bus->**I/O bridge** <-memory bus-> Main memory
* I/O bridge also connect to I/O bus
* Bus interface received interupt from I/O and decide to execute them

******************************************

Classes of Exceptions
----------------------
* finish it
|Class|Cause|Examples|Return behavior
------|-----|--------|--------------|
Trap|Intentional exception, i.e "Software Interrupt"|System calls| Always returns to next instuction
Fault|Potentially recoverable error|Divide by 0, stack overflow, invalid opcode,page fault, seg fault| might return to current instaction|
|Interupt|

******************************************

Device Management Organization
--------------------------------
* Device System Call Interface
  - Create a simple standard interface to access most devices (open,close,read,write etc..)
  

Device System Call Interface
-----------------------------
* Block vs character devices
  - Character devices generate or process data as a linear stream of bytes
    - keyboards, mice , audio, modems, printers
  - Block devices read/write data in discrete blocks(process put on wait queue until I/O read or write finished)
    - disks

******************************************

Queuing of Device Requests
----------------------------
* More than one application may want access to the same device
* Device requests may be reordered in some cases

******************************************

Device Drivers 
------------------
* Support the device system call interface function open, read etc. for that device
* Interact directly with the device controllers
  - Know the details of what commands the device can handle, how to set/get bits in device controller registers
  - by certain registor from the device controller, it will trigger the corresponding device driver
* Control flows

******************************************

Device Controller
------------------------------------
* **Lecture picture of Device controller states**

Polling I/O: A write Example (What happened??? ASK)
---------------------------
```
while(deviceN.busy || deviceN.done) //Check if it's in idle state
deviceN.data[0] = <value to write> //set it to idld state
questio

```






