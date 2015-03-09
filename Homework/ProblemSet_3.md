Problem1
-----------------
* **1. (+25 points) To implement deadlock avoidance, the Banker's Algorithm is applied to the following system, where the total number of resources
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

* **Resource Available**

  R0|R1|R2|R3
---|----|----|----
6|4|4|2

--------------------------
* This is **Safe**. 
* **Sequence**:
  - Step 1: Giving resource to **P0** and update the aviable matrix to:
  
  
    R0|R1|R2|R3
---|----|----|----
8|4|5|2
  
  - Step 2: Giving resource to **P1** and update the aviable matrix to:
  
  
    R0|R1|R2|R3
---|----|----|----
9|5|5|2

  - Step 3: Giving resource to **P2** and update the aviable matrix to:
  
  
    R0|R1|R2|R3
---|----|----|----
10|6|5|2

  - Step 4: Giving resource to **P3** and update the aviable matrix to:
  
  
    R0|R1|R2|R3
---|----|----|----
11|6|6|2

  - Step 5: Giving resource to **P4** and update the aviable matrix to:
  
  
    R0|R1|R2|R3
---|----|----|----
11|7|6|3

  - *Job Finishes*
  
  
-----------------------------------------------



