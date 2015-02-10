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

* Condition Variable Example
	- condition wait_until_empty:
		- task1: wait_until_empty.wait()
		- task2: wait_until_empty.signal()
	Problem: if Task2 execute first, task 1 then wait forever(block eternally)
	




