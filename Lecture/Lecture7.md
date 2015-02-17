Deadlock Avoidance
------

|Process|Max needs|Allocated(total = 12)|
|-------|---------|---------------------|
|p0|10|5|
|P1|4|2|
|P2|9|2|

Sequence (p1 p0 p2) is safe
  - availble was 3
  - request 2 for p1
  - p1 finishes, release 5
  - p0 now has 10, then finish the job
  - p2 now gets the 7 it needs

**not all unsafe state are deadlock, could be deadlock if both maximum requests were trying to be granted**
* Example1  
 - the systen can find a ordered way of granting max request, so no deadlock
 - don't grant if it can't not be satisfied
 - do grant for remaining tasks

* **Dijkstra's Banker's Algorithm**
 * Generalizes deadlock avoidance to multiple resources
 * Before granting request, pretend like if its granted, run Banker's algorithm 
  * Does the worst-case analysis find such a system in safe state?
    - if so , grant request
    - if not, delay requestor, and wait for more 
* Disadvantage: 
 * what if its maximum resource usage can't not be found?



Banker's Algorithm
---------

* Is the system in a safe state? Find a safe sequence.
* **Youtube** 基本上就是俩个matrix，然后计算，



Resource-Request Algorithm
