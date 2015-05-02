------------------------------------------------------
* **(2) Suppose you are given a flash memory consisting of 4 KB pages, and there are 1024 pages. How many bytes of memory would the OS need to keep track of free space in the worst case (all of flash memory is free) if**

  * **a. a bitmap was used?**
    - 1024 pages * 1 bit = 1024 bits = 128 bytes
  * **b. a linked list was used? Assume 2 bytes/pointer.**
    - (1024-1)*2 + 2 = 2048 bytes (1023 pointers from pages and one head pointers to pages.)
  * **Under what conditions would a linked list be more memory-efficient than a bitmap?**
    - Under the conditions when there are only few free space blocks
  
------------------------------------------------------
* **(3) The read/write head of a disk is at track 97, moving towards track 199 (the highest-numbered track on the disk), and the disk request queue contains read/write requests for sectors on tracks 84, 155, 103, 96, and 197, respectively. Starting from the current head position, what is the total distance in tracks that the disk arm moves to satisfy all the pending requests for:**
 * FCFS: (97-84) + (155-84) + (155-103) + (103-96) + (197-96) = 244
 * SCAN: (103-97) + (155 - 103) + (197 - 155) + (199 - 197) + (199 - 96) + (96 - 84) = 217
 * LOOK: (103-97) + (155 - 103) + (197 - 155) + (197 - 96) + (96 - 84) = 213
 
* **(4) Describe the SSH protocol in detail, i.e. describe the initial handshaking phase as well as the subsequent data messaging phase. When a user supplies their login password, is it encrypted by a public key or a symmetric key, and why? Explain why or why not SSH is resilient to eavesdropping attacks, man-in-the-middle attacks, and/or replay attacks.**
* 
