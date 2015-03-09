Problem1
-----------------
* **To implement deadlock avoidance, the Banker's Algorithm is applied to the following system, where the total number of resources
available for each of four resource types is R0=6, R1=4, R2=4, and R3=2. Is the system in a safe state? If not, then explain why not, or if so, find a safe sequence. Show your work**

--------------------------


* **Maximum Claims:**

  :white_circle:|R0|R1|R2|R3
---|----|----|----|----
**P0**|3|2|1|1|
**P1**|1|2|0|2|
**P2**|1|1|2|0|
**P3**|3|2|1|0|
**P4**|2|1|0|1|


* **Current Allocation:**

  :white_circle: |R0|R1|R2|R3
---|----|----|----|----
**P0**|2|0|1|0
**P1**|1|1|0|0
**P2**|1|1|0|0
**P3**|1|0|1|0
**P4**|0|1|0|1

* **Current Needs:**

  :white_circle: |R0|R1|R2|R3
---|----|----|----|----
**P0**|1|2|0|1
**P1**|0|1|0|2
**P2**|0|0|2|0
**P3**|2|2|0|0
**P4**|2|0|0|0

* **Current Resource Available**

  R0|R1|R2|R3
---|----|----|----
1|1|2|1

--------------------------
* This is **Safe**. 
* **Sequence**:
  - Step 1: Giving resource to **P2** and update the aviable matrix to:
  
  
    R0|R1|R2|R3
---|----|----|----
2|2|2|1 
  
  - Step 2: Giving resource to **P3** and update the aviable matrix to:
  
  
    R0|R1|R2|R3
---|----|----|----
3|2|3|1

  - Step 3: Giving resource to **P4** and update the aviable matrix to:
  
  
    R0|R1|R2|R3
---|----|----|----
3|3|3|2

  - Step 4: Giving resource to **P1** and update the aviable matrix to:
  
  
    R0|R1|R2|R3
---|----|----|----
4|4|3|2

  - Step 5: Giving resource to **P0** and update the aviable matrix to:
  
  
    R0|R1|R2|R3
---|----|----|----
6|4|4|2

  - *Job Finishes*
  
  
-----------------------------------------------
Problem2
-------------

* **Suppose we have 5 dining philosophers and 5 shared chopsticks, and that the philosophers are circularly deadlocked.  Assume also that there are two serving spoons, one allocated to philopher 1, and the other available.  Assume that philosopher 4 wants a serving spoon.  Show how this situation can be modeled according to the various data structures, e.g. Allocation and Request matrices, used in the Deadlock detection algorithm.  Run the Deadlock detection algorithm on your model to prove that the dining philosophers are in deadlock.**

--------------------------
* **R1 = Chopstic**
* **R2 = Spoon**
* **P1-P5 = 5 philosophers**





* **Maximum Claims:**

  :white_circle:|R1|R2
---|---|---
**P1**|2|1
**P2**|2|1
**P3**|2|1
**P4**|2|1
**P5**|2|1


* **Current Allocation:**

  :white_circle:|R1|R2
---|---|---
**P1**|1|1
**P2**|1|0
**P3**|1|0
**P4**|1|0
**P5**|1|0

* **Current Needs:**

  :white_circle:|R1|R2
---|---|---
**P1**|1|0
**P2**|1|0
**P3**|1|0
**P4**|1|1
**P5**|1|0

* **Current Resource Available**

  |R1|R2
|---|---
0|1
 
* **Deadlock detection algorithm**
  - **P1-P5** all need 1 extra chopstick where 0 chopstick is available
  - **P4** needs 1 spoon and it is available
  - **None** of the philosopher can get enough resources because of lacking in chopstick resulting **deadlock**

Problem3
---------------
* **Consider the following set of processes, with the length of
the CPU execution time given in seconds:**


Process|	Execution Time	|Priority
-----------|-------------|-------------
P1|	10 	|3
P2|	1|	1
P3	|2|	3
P4	|1	|4
P5	|5|	2

* **Draw four Gantt charts that illustrate the timeline of execution of
the processes when scheduled according to FCFS, SJF, nonpreemptive
priority (priority 1 is most important), and round robin (time
slice=1). Which one has the lowest average wait time? Which one
has the lowest average turnaround time?**

![](http://s7.postimg.org/3uhyqsegr/img001.jpg)



Problem4
--------------

* **Suppose the Completely Fair Scheduler (CFS) algorithm is applied to the following scenario.  There exist two processes P1 and P2 that need to be scheduled.  P1 has two threads T1 and T2 that are implemented as kernel threads.  P2 has three threads T3, T4, and T5 that are implemented as user space threads.  We apply round robin scheduling to all schedulable tasks, where each task schedulable by the kernel receives a time slice of size T seconds.**

  - **a. Draw the table of wait times (times owed on an ideal CPU) for one round robin of this scenario, i.e. what are the wait time balances as each time slice is allocated to a kernel-schedulable task, and what is the final wait time for each such task?  See for example slide 21 of the Chapter 6.3 lecture slides.**
  
:white_circle:|:white_circle:|:white_circle:|:white_circle:
-------------|-------------|-------------|--------------
T1|T2|P2|T1


Giving time T to task:|T1|T2|P2
----------------|-----------|-------------|--------------
T1|-2T/3|T/3|T/3
T2|-1T/3|-1T/3|2T/3
P2|0|0|0


  - **b. Is this system fair at the level of schedulable tasks?  Is this system fair at the level of processes?  Justify your answers.**
