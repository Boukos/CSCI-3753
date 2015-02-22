Lecture3.5: Processes, Synchronization & Deadlock
---------------------------

* **Synchronous Communication**

  ![](http://s21.postimg.org/mpqp6fvpz/image.png)

  * Time running down, the Producer sends signal to the Consumer, and Consumer receives the signal
  * First send has to process precede First receive
  * The second send has to wait for the First receive pattern

* **FIFO Buffering**

  ![](http://s17.postimg.org/ysk9magn3/image.png)
  

  * **i** is the first in character, **N** is the character size of the buffer
  * Producor can keep sending in characters to fill up N size in the buffer, Consumer waits.
  
