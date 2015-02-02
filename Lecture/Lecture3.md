Lecture 3 : Device I/O , Interupt , DMA
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
* Status -- > device --> back to controller to the command(read write so on) -->output data

Polling I/O: A write Example (What happened??? ASK)
---------------------------
```
while(deviceN.busy || deviceN.done) //Check if it's in idle state
deviceN.data[0] = <value to write> //set it to idld state
questio

```

Device Manager I/O methods
-------------------
* Hardware Interrupts
  - CPU incorporates a hardware interrupt flag
  - Whenever a device is finished with read/write, it commucates to the CPU and raises the flag


CPU execution with Interrupts (Compare it to the code from polling)
-------------------------------------------------------------------

******************************************


Interrupts from Multiple Devices
-----------------------------------
* Aggregate the individual flags logically using OR
* if there is at least one device wanting to interrupt the CPU, then raise the aggregate flag


Maskable Interrupte (Don't get it)
----------------------------------

******************************************

Direct Memory Access (DMA)
------------------------------
* The CPU can become a bottleneck if there is a lot of I/O copying data back and forth between memory and devices
  - like watching a MP4 files (generate constantly interupt)

* DMA solution: Bypass the CPU for large data copies, and only rasie interupt at the end of the transfer
* DMA with Interrupts Example
  - 1. device driver told to transfer bytes from disk to memory
  - 2. dev driver informs disk controller
  - 3. disk controlller initiates DMA
  - 4. disk controller sends each byte to DMA controller
  - 5. DMA sends each byte to memory
  - 6. DMA interrupts CPU when done

* Since both CPU and the DMA controller have to move data to/from main memory, how do they share main memory?
  - don't get it , watch slides



