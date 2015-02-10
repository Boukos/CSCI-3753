Homework
-----------
	- Add a device driver to Linux using kernel modules
	- Download the revised writeup
Recap
--------
* Classic synchronization problems
	- Review on "A Bounded Buffer P/C Solution"
	- Review on "A Reader/Writers Solution"
		- Goal: A writer has exclusive access & reader can share access with other readers
		- has 3 semaphore(what is this)
	- Review on "Dining Philosophers Problem"
		- monitor solution : http://www.csee.wvu.edu/~jdm/classes/cs550/notes/tech/mutex/dp-mon.html  & http://www.cs.fsu.edu/~baker/realtime/restricted/notes/philos.html

Lecture
-----

Condition Variable Example
----------
	- condition wait_until_empty:
		- task1: wait_until_empty.wait()
		- task2: wait_until_empty.signal()
	Problem: if Task2 execute first, task 1 then wait forever(block eternally)

Semaphore Example
----------------
	- semaphore wait_until_empty = 0
		- wait(wait_until_empty);
		- signal(wait_until_empty)
	- Problem solve: task 1 won't block forever, state of signal is preserve , the signal sent from task2 earlier was incremented from 0 to 1, and task 1 will execute it when it's ready


Complex Condition
--------
* task T1 wait until a complex set of conditions in T2 become true
	- task1: while(f!=7.0 && count< 0)   x.wait()
	- task2: f=7.0; count++; x.signal()
	- Problem: could be a race condition in testing and setting shared variables
	- race condition: http://stackoverflow.com/questions/34510/what-is-a-race-condition
	- Solution: require acquire(mutex) to test the set of conditions
* Pthreads replaces complex sequence of relase/wait/acquire() with
	- pthred_cond_wait(&cond_var, &mutex)
	- 
	


