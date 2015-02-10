Chapter 7 : Deadlock
------------------

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

Monitor and Condition Variable
-------------------
	- if task T1 calls Mon.f1(), this blocks T1 on x.wait()
	- if task T2 then calls MON.f2(). this calls x.signal(), which unblock T1
	- Now both tasks are inside the monitor, which is a violation of mutual exclustion
	- Need way such that only 1 task is executing in the monitor after a signal.
	Hoare vs Mesa Sematics
	---------------------
		- blah blah blah
Monitor-based Solution to Dining Philosophers
-----------
* Key insight: pick up 2 chopsticks only if both are free
	- this avoids deadlock
	- reword insight: a philosopher moves to his/her eating state only if both neighbors are not in their eating states.
	- need to initiate the state of philospher
	- 2nd insight: if one of my neighbors is eating, and I am hungry, ask them to signal() me when they are done
		- thus states of each person are : thinking , hungry, eating
		- thus need condition variable to signal() waiting hungry
	- also need to pick up and release chipostick
	
* code
```
monitor DP{
	status state[5];
	condition self[5];
	pickup(int i);
	putdown(int i);
	test();
	init();
}

pickup(int i){
	state[i] = hungry;
	test(i); //test neighbor to see if there are eating
	if(state[i]!=eating)
		self[i].wait;
	}
	
test(int i){
	//check i+1 right and i-1 left to see if they are eating
	if (state[(i+1)&5] != eating && state[(i-1)&5] != eating && state[i] == hungry) 
	state[i] = eating;
	self[i].signal();  //to wake up neighbor if they are meet the conditions
	}
	
putdown(int i){
	state[i] = thinking;
	test((i+1)%5) //check neighbor
	test((i-1)%5)
}

init(){
	for i = 0 to 4
}

```






