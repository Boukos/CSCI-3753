------------------------------------------------------
* **(2) Suppose you are given a flash memory consisting of 4 KB pages, and there are 1024 pages. How many bytes of memory would the OS need to keep track of free space in the worst case (all of flash memory is free) if**

  * **a. a bitmap was used?**
    - 1024 pages * 1 bit = 1024 bits = 128 bytes
  * **b. a linked list was used? Assume 2 bytes/pointer.**
    - (1024-1)*2 + 2 = 2048 bytes (1023 pointers from pages and one head pointers to pages.)
  * **Under what conditions would a linked list be more memory-efficient than a bitmap?**
    - Under the conditions when there are only few free space blocks
  
------------------------------------------------------
