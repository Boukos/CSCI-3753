Problem1
-----------------
* **There is a one-lane east-west bridge in Hawaii such that when a car is on the bridge going eastbound, no westbound cars are allowed until the eastbound car has left the bridge.  Similarly when a westbound car is on the bridge, no eastbound cars are allowed until the westbound car has left the bridge.  To make matters more complicated, if an eastbound car arrives and sees another eastbound car already on the bridge, then that eastbound car will also proceed onto the bridge.  This is true even if there is a westbound car already waiting to enter the bridge.  Similarly, a westbound car can tailgate behind another westbound car already on the bridge even if an eastbound car was waiting.   Deign a synchronization solution using only locks, semaphores and integer variables that achieves the following: allows all cars bound in a certain direction to continue crossing as long as there is at least one car still on the bridge that is bound in that direction, then toggles to allow all cars in the opposite direction to proceed in a similar manner.  The solution need not be starvation-free.**


```c
//pseudocode

Semaphore bridge = 1;
east_Mutex = 1;
west_Mutex = 1;
int going_east = 0;
int going_west = 0;

east_to_west(){
	p(east_Mutex);  //lock access to counter
	going_east++;   //train counter from east to west
	if(going_east == 1) p(bridge);   //lock the bridge if first train enter
	v(east_Mutex);	//allow train from the same direction to enter
	
	p(east_Mutex);	//lock access to counter
	going_east--;	//decrement train
	if(going_east == 0) v(bridge);	//unlock bridge
	v(east_Mutex);	//unlock counter

//west_to_east is nearly indentical to east_to_west in terms of functionalities.

west_to_east(){
	p(west_Mutex);
	goint_west++;
	if(goint_west == 1) p(bridge);
	v(west_Mutex);

	p(west_Mutex);
	goint_west--;
	if(going_west == 0) v(bridge);
	v(west_Mutex);
}


```



*****************************

Problem2
-------------
* **Suppose task T1 has code C1 that must execute before task T2's code C2.  Design a solution that enforces this ordering using only condition variables, locks, and integer variables.  Semaphores and monitors are not allowed.**



************************************


Problem3
------------
* **Explain why the solution to the 3rd Readers/Writers problem is starvation-free.**



****************************************


Problem4
---------
* **a. Is the swap() function below thread-safe or not?  Explain your reasoning.**

```c
int temp;
 
void swap(int *y, int *z)
{
    int local;
 
    local = temp;
    temp = *y;
    *y = *z;
    *z = temp;
    temp = local;
}
```




* **b.Suppose the swap() function above is called by the interrupt service routine (ISR) below.  Assume that if swap() is interrupted during normal execution, the ISR below is called and calls swap() again, reentering swap() and executing in the context of the interrupted thread.  Is swap() reentrant?  Explain your reasoning.**

```c
void interrupt_service_routine()
{
    int a = 1, b = 2;
    swap(&a, &b);
}
```

*****************************

Problem5
---------------
* **Suppose you are asked to design a server application consisting of two processes P1 and P2, such that (1) P2 is to sleep until woken up by P1, whereupon (2) P2 would take a 10 MB file from P1 and compress it. What forms of IPC would be best suited to implement these types of information sharing? Describe your solution.**
 * (1) signals (for P1 to wakeup P2)
 * (2) shared memory(for sharing the 10 MB file). It seems like we would want something minimalsuch as a signal for P1 to send to P2, and something fast such as sharedmemory for reading/writing the 10 MB file.
 


*****************************


Problem6
-----------
* **Suppose processes P0 and P1 share variable V1, and processes P1 and P2 share variable V2, while processes P0, P1 and P2 share V3.  Operations on V1 are limited to increment() and decrement().  Operations on V2 are limited to square() and squareroot().  Operations on V3 are limited to sin() and cos().  Design a monitor-based solution that synchronizes access to and manipulation of these variables between the three processes so that race conditions are eliminated.**


*****************************
