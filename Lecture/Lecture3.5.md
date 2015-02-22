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
  * **Ring Buffer** 
    * Producers write into the buffer until it maxs out (check the write pointers), then Consumer read them 
    * After Consumer read the first one, Producer can start writing again.
    
* **Bounded Buffer Problem**
  

  ![](http://s30.postimg.org/aafmmrhg1/image.png)
  
  * **Code Understanding**
    * buf[in] adding character into the buffer
    * in = (in+1)% N reset the pointer to the begining when Size N is filled up (when mod gives back 0)
  * :no_entry_sign: Consumer invoked **regardless** if producers send in anything, it just reads from the buffer and increment.
  
  
* **Semaphores**


  ![](http://s21.postimg.org/qptpobdqv/image.png)
  
* Communication of the states of the Buffer between Producer and Consumer
* **wait(semaphore s)** will block. wait until receive something (if current process is 0, then wait, otherwise s-1)
* **signal(semaphore s)** no block. Increment and return


* **Semaphores for Resource Allocation**


  ![](http://s28.postimg.org/4gkmb0s7h/image.png)

* a Pool of K resources avalible
* to think of this in a consumer perspective when **borrowing laptop**
  * has a maximum numbers of laptops in the Pool
  * need to wait for the laptop, and later return the laptop (wait and signal)



* **Bounded Buffer Problem w/ Semaphores**
  
  ![](http://s1.postimg.org/h248loyfz/image.png)


* 1. Even these two run at the same time, Consumer will block and wait for the signal
* 2. Consumer later receive a signal, will decrement the signal from Producer's pool 
* 3. After finish using, Consumer return the signal to the producer and increment the pool



  

