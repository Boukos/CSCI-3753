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
* **R0 = Chopstic**
* **R1 = Spoon**
* **P0-P5 = 5 philosophers**





* **Maximum Claims:**

  :white_circle:|R0|R1
---|---|---
**P0**|2|1
**P1**|2|1
**P2**|2|1
**P3**|2|1
**P4**|2|1


* **Current Allocation:**

  :white_circle:|R0|R1
---|---|---
**P0**|1|1
**P1**|1|0
**P2**|1|0
**P3**|1|0
**P4**|1|0

* **Current Needs:**

  :white_circle:|R0|R1
---|---|---
**P0**|1|0
**P1**|1|1
**P2**|1|1
**P3**|1|1
**P4**|1|1

* **Current Resource Available**

  |R0|R1
|---|---
0|1

* **Deadlock detection algorithm**
  - **P0-P5** all need 1 extra chopstick where 0 chopstick is available
  - **P1-P5** all need 1 extra spoon where 1 spoon is available
  - Thus, **none** of the philosopher can get enough resources resulting **deadlock**

