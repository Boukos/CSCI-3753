Problem1
--------
Suppose we have a round-robin scheduler in the OS kernel of a preemptively time sliced system, and three programs in its ready queue: P1, P2, and P3. P1 takes 10 seconds to complete, P2 takes 8.5 seconds, and P3 takes 3 seconds. Suppose the time slice is 2 seconds, and the overhead for OS context switching is 0.2 seconds. If P1 starts executing first at time 0, when do each of the programs finish executing? Draw a timeline of execution. What is the percentage overhead due to context switching? Assume that a process that finishes early transfers control back to the OS scheduler.


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

Repeat above for a batch mode multiprogrammed OS. Which system, preemptively multitasked or batch mode multiprogrammed finished execution of all three programs the fastest? Under what conditions might the reverse be true?

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
Explain the differences between the four different kinds of exceptions found in an OS exception table. What is a software interrupt, and how does that differ from a hardware interrupt?
