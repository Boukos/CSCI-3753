khaled.alanezi@colorado.edu for free meal
Chapter 5 & 7

Banker's Algorithm
-----------

* **Deadlock Detection**

* what if in avaible matrix is all 0 , and request matrix all request SOMETHING, will that cause a deadlock?
  - yes
* when to use this algorithm
  - **when**
  - how likely deadlock is going to happen?
  - when in deadlock, how many processes is suck in ?
  - **how**
  - check each resource request(costly)
  - check periodcally (what is a good time interval/???)
  - check if the CPU utilization suddently drops (what is a good threahold // ????????????????)
  - check if resource utilization exceeds some threshold, but what's a good threshold?

* Deadlock Recovery
  - 1. Terminate all processes
  - 2. ONE STEP AT THE TIME 
  - 3. Preempt some process (printer)
  - 4. checkpoint (like Microsoft word automatic saved, when things happend???????????????)
  
Chapter 6: Scheduling (decide the next process to run)
----------------
  * Goals:
    - find in the lecture!!!

  Switching between processes
  - 1. when selecting, which one goes next(some sort of algorithm)
  - 2. Execution time : sum of all the time slices
  - 3. wait time : sum of all the gaps **including the first gap** , NOT INCLUDE waiting time
  - 4. Turnaround time ??????????? the difference from execution time????????????
  - 5. response time: the time that 1st entry to process to get ready
  
 
 How its done: FCFS Scheduling
 ----------------
 - 1. First come first serve
 - 2. use Gantt Chart to draw
 - 3. WAIT TIME 
    - p1 p2 p3 = 3 3 24
    - wait time is (0-3-6)/3 = 3
    - p3 p2 p1 = 24 4 4
    - wait time is (0-24-28)/3 = 17
  
  - 4. Turnaround time , CHECK LECTURE ??????????????

How its done : SJF Schedule
------------
- 1. Shortest Job First (evolve from FCFS Scheduling)
  - 这样的话，waittime和turnaround time就减少了
  
  2. what if there is a program comes in with 24 secs, and the algorithm starts running, and later there is a 3 secs come in?
  ??????????????????
    and when program all come in once, what is the wait time for ordering switching the program
    **can be preemptive**
  
  3. Problem:
    - must know the run times in advance unlike FCFS
      - Solution: estimate by the previous experience (把一个任务切成几块，先运行一段时间，然后根据之前的经验在做预测)
      - how long is this going to take?
  
  
  
  
  
  
