Problem 1
------------
**Describe at least 3 general approaches in memory management than can help solve the external fragmentation problem.**

-------------------------------------------------------
* **Compaction:**
  * Full Compaction: Move all processes to one side of the physical memory and release a big segment of free memory
  * Partial Compaction: Move enough process to create enough segement of free memory
* **Compaction with swapping:** Roll out processes to disks and free those memory, and later reload the memory
* **Paging:** Divide process into fixed size pages, selective allocate pages to frames(a piece of a physical memory), and manage pages in memory
*
* **Garbage Collection**  it collects all the memory which is inaccessible and return them as a free memory


Problem 2
------------
* **A memory manager for a variable-sized region strategy has a free list of blocks of size 600, 400, 1000, 2200, 1600, and 1050 bytes. What block will be selected to honor a request for:**

----------------------------

  * a. 1603 bytes using a best-fit policy?   **Answer: 2200**
  * b. 949 bytes using a best-fit policy?   **Answer: 1000**   
  * c. 1603 bytes using a worst-fit policy?   **Answer: 2200**
  * d. 349 bytes using a worst-fit policy?   **Answer: 2200**
  * e. 1603 bytes using a first-fit policy? (assume the free list is ordered as listed above)   **Answer: 2200**
  * f. 1049 using a first-fit policy?   **Answer: 2200**
  

  
Problem 3
-------------
* **Suppose two processes need to be mapped into main memory using pages. Process P1 consists of 7 pages, and process P2 consists of 4 pages. Assume main memory consists of 16 frames, a logical page is the same size as a physical frame, and that 4 entries in a page table fills up a frame of memory. Assume also that within the process' allocated address spaces, there are two pages of shared code 'X' and 'Y' common to both address spaces. Design a memory management system that can store these two processes and their page tables in RAM. Identify which frames you have chosen to assign to which process pages and page tables in main memory/RAM. Also show possible page tables for P1 and P2 (e.g. page table for P1 should have 7 entries).**

![](http://s24.postimg.org/78w9xt3jp/img001.jpg)

Problem 4
-------------
**Suppose on-demand paging is employed in addition to TLB caching. The time for a TLB hit is T = 1 ns, a memory read M = 10 ns, and a disk read D = 10 ms. Let p_TLB = the probability of a TLB hit, and p = the probability of a page fault given a TLB miss. What is a general formula for the average memory access time expressed as a function of T, M, D, p, and p_TLB? Once parameter values are substituted, and assuming assuming p = .001 and p_TLB = 90%, what is the calculated average memory access time?**

![](http://s30.postimg.org/azy6oxz35/img002.jpg)

Problem 5
------------------------
**The Least Recently Used (LRU) page replacement policy does not suffer from Belady's Anomaly. Explain intuitively why this is the case. Construct an example page fault sequence to illustrate your point.**

Because FIFO assumes that the mere fact that a page has been occupying memory for a long time that it is the safest to replace, where in reality that simply isn't the case. Rather, where FIFO fails is that statistically, if a page has been called frequently, it's more likely to be called again than another page which has been called recently. In other words, frequency is a far better determiner of page loading than age.

![](http://s18.postimg.org/uoq71z1a1/img004.jpg)

Problem 6
--------------------
**Given a frame allocation of 3, and the following sequence of page references 3 2 4 3 4 2 2 3 4 5 6 7 7 6 5 4 5 6 7 2 1, and assuming main memory is initially unloaded, show the page faulting behavior using the following page replacement policies. How many page faults are generated by each page replacement algorithm? Which generates the fewest page faults?**
* a. FIFO 
* b. OPT 
* c. LRU


![](http://s16.postimg.org/xf9jcp9np/img005.jpg)


Problem 7
-------------------------

**Assume the same sequence of page references as in problem #6, and assume memory is initially unloaded, but now assume that a dynamic paging working-set algorithm is applied to the same sequence of page references, with a window size of 6. Draw the page faulting behavior. Your solution chart should show the frame allocation at any given time to the process.**

![](http://s16.postimg.org/sme4qoaw5/img006.jpg)
