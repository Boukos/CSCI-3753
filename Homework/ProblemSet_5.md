* **(1) You are asked to allocate a file according to either a File Allocation Table (FAT) or multi-level indexed allocation (UNIX inode - triply indirect). Assume that the file is 2000 disk blocks long, there are 4 KB per disk block, each pointer in the FAT occupies 4 bytes, the first index block contains 15 entries (of which 12 are direct, and one each is singly indirect, doubly indirect, and triply indirect - see slides or textbook), every other index block contains 15 entries (may be indirect depending on the nesting level), each index block entry takes 4 bytes, and unused index blocks don't count in the total memory cost, though unusued entries in partially filled index blocks do count. How many bytes are used to lay out the file when using** 
 * **a. a FAT file system?**
    * first level index blocks = 12*4 bytes
    * single indrect blocks = 15*4 bytes
    * second indrect blocks = 13*4 + 15*4*2 bytes
    * third indrect blocks = 13*4 + 13*4*2 + 15*4*4 bytes
  
    * (12 * 4)+(15 * 4)+(13 * 4)+(15 * 4 *2)+(13 * 4)+(13 * 4 * 2)+(15 * 4 * 4)+(12 * 4 * 15) = 1396 bytes   
 * **b. a UNIX-style file system?**


 

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

 * note: N = p*q
 * Description: Server first sends N to the user, the user stores N, and then send N back to the server. Server verifys the N with p&q. User randomly generates encrypted message K with pre-stored N, and send it to the server, server then use K for AES . Then the SSH session is now encryped with K.
 * It is encryped by a symmetric key K, because only the server knows the private key, and can solve that to decrpted the symmetrick key K. If the hack is fake a encrpted message K , the server will decript that and send back to user some non-sense characters because the user can't decript the message.
