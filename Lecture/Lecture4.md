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






   
  
