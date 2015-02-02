Problem1
--------
* Suppose we have a round-robin scheduler in the OS kernel of a preemptively time sliced system, and three programs in its ready queue: P1, P2, and P3. P1 takes 10 seconds to complete, P2 takes 8.5 seconds, and P3 takes 3 seconds. Suppose the time slice is 2 seconds, and the overhead for OS context switching is 0.2 seconds. If P1 starts executing first at time 0, when do each of the programs finish executing? Draw a timeline of execution. What is the percentage overhead due to context switching? Assume that a process that finishes early transfers control back to the OS scheduler.


***************************

|Process|Time(secs)|
|-------|----------|
|p1|10|
|p2|8.5|
|p3|3| 
Time Slice: 2 seconds

***************************
* **1. Timeline of execution**
 
|Seconds|Process|
|-------|-------|
|0 :arrow_right: 2|p1|
|2 :arrow_right: 4|p2|
|4 :arrow_right: 6|p3|
|6 :arrow_right: 8|p1|
|8 :arrow_right: 10|p2|
|10 :arrow_right: 11|**p3**(finished)|
|11 :arrow_right: 13|p1|
|13 :arrow_right: 15|p2|
|15 :arrow_right: 17|p1|
|17 :arrow_right: 19|p2|
|19 :arrow_right: 21|**p1**(finished)|
|21 :arrow_right: 21.5|**p2**(finished)|

***************************
* **2. Finishing Time**
  * p3 finishes at 11 seconds
  * p2 finishes at 21.5 seconds
  * p1 finishes at 21 seconds

***************************
* **3. Percentage Overhead**
  - Time Switch : 11 times
  - (0.2 * 11) /21.5 = 10.23% 

***************************

Problem2
---------

* Repeat above for a batch mode multiprogrammed OS. Which system, preemptively multitasked or batch mode multiprogrammed finished execution of all three programs the fastest? Under what conditions might the reverse be true?

******************************************************



|Process|Time(secs)|
|-------|----------|
|p1|10|
|p2|8.5|
|p3|3| 

***************************
* **1. Timeline of execution**

|Seconds|Process|
|-------|-------|
|0 :arrow_right: 10|p1|
|10 :arrow_right: 18.5|p2|
|18.5 :arrow_right: 21.5|p3|

********************************
* **2. Finishing Time**
  * p3 finishes at 21.5 seconds
  * p2 finishes at 18.5 seconds
  * p1 finishes at 10 seconds
  

****************************

* **3. Percentage Overhead**
  - Time Switch : 2 times
  - 0.2 * 2 / 21.5 = 1.9%
  

* **4. Comparison**
  -  1. batch mode multiprogrammed finished execution of all three programs faster than preemptively multitasked due to less context switch percentage overhead
  -  2. if there is many I/O bound that triggers context switch in the batch mode multiprogramming, It can potentially be slower than the other, thus reverse to be true.

****************************

Problem3
---------
* Explain the differences between the four different kinds of exceptions found in an OS exception table. What is a software interrupt, and how does that differ from a hardware interrupt?

****************************
* **1. Exceptions comparison**

|Exceptions|Differences|
|----------|-----------|
|Trap|cause by intentional exception(ex: system call) & always returns to next instruction, synchronous |
|Fault|cause by potentially recoverable error(ex: stack overflow, invalid opcode) & might return to current instruction, synchronous |
|(Hardware) Interupt|cause by signal from I/O device(ex: Disk read finished) & always returns to next instruction, asynchronous|
|Abort| cause by nonrecoverable error(hardware bus failure) & never returns, synchronous|

****************************
* **2. Software interrupt vs. Hardware interrupt**

* A hardware interrupt causes the processor to save its state of execution and begin execution of an interrupt handler. Software interrupts are usually implemented as instructions in the instruction set, which cause a context switch to an interrupt handler similar to a hardware interrupt.


Problem4
---------
* What role does the jump table play in executing a system call?

*****************************

Most of the system calls are relatively static set of functions. By calling the functions using a simple index into the array means retrieving the pointer and calling a function or jumping to the machine code depending on the type of table used. (ex: syscall(318) calls the helloworld function we created from lab1.)


Problem5
-----------
* Explain in what way overlapping I/O with CPU processing is advantageous. Explain two ways that I/O can be overlapped with CPU execution and how they are each an improvement over not overlapping I/O with the CPU.

*****************
Interrupt driven I/O: CPU initiates the I/O and sets up an interrupt handler. After that it performs other useful work in parallel with I/O data transfer being performed by I/O device. When I/O data transfer is complete, the CPU is interrupted to complete the remaining work for completing the I/O. 

DMA based I/O: Similar to interrupt-driven I/O with the addition that DMA controller manages the data transfer between memory and device registers. 


Problem6
----------
* Describe each step of a write() operation to disk, from the application first calling a write() through the OS processing the write() to the final return from the write() call upon completion of the disk operation. Assume interrupt driven I/O operation. You may draw and label a figure if you'd like. Your answer should include components such as the device controller, interrupt handler, device handler, device driver, and any other OS components you deem appropriate to add.

************

![Problem6](http://s30.postimg.org/6yvc2gau9/img001.jpg)
