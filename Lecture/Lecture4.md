Lecture 4 
------

* Reading Chapter 5

Recap
-----
Inter-Process Communication (IPC)
- Shared Memory
- Message Passing

Chapter 5: Synchronization
  - Race conditions occur when 2 processes/threads try to access the wsame shared variable
  
A Race Condition 
--------------
* Let brackets denote local value of counter in either the producer or consumer's process. counter = 5 initially.
* Counter should be 5 with 1 producer and 1 consumer, but counter = 4!
* Unprotected.


Solution?: Critical Section
--------------------
* Understand this

* How do we protect access to critical section:
  - want to prevent another process from executing while current process is modifying this variable - mutual exclution
  - Userspace: see Chapter 5.2 for solution 
  - Hardware-based - disable interrupts
  
  
Disabling Interrupt
------------

Check Code from Lectures
- Drawback : Greedy program that basically block out execution of all other processes
If disable Interrupt , I/O is very much sad.

Alternative: Locks
-----------------
Goals: Achieve mutual exclusion without the drawbacks of fully disabling interrupts
- Set a flag

Lock Sematics:
- Acquire(lock) before entering its critical section
  - if a task grabs the lock, then proceed
  - if not , the calling task blocks (???)
- Release(lock) when done

Advantage: Achieves mutal exclusion without blocking all procecsses
  - Other tasks are blocked from execution their critical secions due to locking.
  - This only works if all program has same lock code(all play the game) and they shared data
  - Acquire and Release are system calls
  
More lock
---------

**Falwed in lock implementation:**
- if these two program run at the same time, they will exits from the while loop, then both enter to the critical section at the same time!!!

To fix: Achieve by disabling interrupts

* Correct Lock Implementation
  - Advantage: no race condition 
 
  - Disadvantage: busy waiting for acquire lock
    - stuck in Acquire() FOREVER NOOOOOO

So, Test-and-Set Instruction
---------------
* understand this s!*@

Blocking on locks
--------------
* understand this s!*@


Semaphores , nope don't get it
-------------
* Alternative to Locks
* more general solution to mutual exclusion proposed by Dijkstra
* Semaphore S is an integer variable that, apart from initialization, is accessed only through 2 standard atomic operations
  - P(), also called wait()
    * somewhat equivalent to test-and-set , but also decrements the value of S
  - V(), also called signal()
    * increments the value of S
  - OS provides ways to create and manipulate it.
  
A Revised Semaphore Definition
---------------------
P : make sure the value strickly less than 0. if so add this to the blocklist, block
V: Remove a process from the block list and then awake the process
Processes now yield the CPU if the semaphore value is negative (instead of waste time waiting)

**Why FIFO not LIFO ?????????**

Mutual exclusion with Revised Semaphore
-----------------
**How to decrements s to -1 and -2 ??**
* V is call the signaling
FIFO quene


Deadlock
----------
* Semaphores provide synchronization, but can introduce more complicated higher level problems like deadlock
  - two processes deadlock when each wants a resource that has been locked by the other
  - e.g.  P1 wants resource R2 that is locked by p2 with s2 and vice versa  **BOOM**






