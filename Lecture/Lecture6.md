Deadlock: General Solution
--------------
* If there's no cycle(dependency), direct graph will help solve Deadlock
* If there's a loop, with extra program to release the instance, there will be **NO** Deadlock

Necessary Conditions for Deadlock
----------
* 1. Mutual exclusion (一个程序要等另外一个结束才能进行)
* 2. Hold and wait (一个程序不仅占用资源，还索要另外资源)
* 3. No preemption (假如程序不自愿结束，资源无法被释放)
* 4. Circular wait (hold and wait in a circular way)

Solutions to Handling Deadlocks
-------------
* 1. Prevention by OS
    - Make at least 1 of the 4 necessary conditions doens't hold(把一个condition干掉)
* 2. Avoidance by OS
    - Give OS information before hand to get a prediction
* 3. Detection and Recovery by OS
    - Check to see if there's anything else that might cause problem
* 4. Application-level solutions
    - application crashed, not something we can do

Detail
--------
* Deadlock Prevention: Mutual Exclusion
    -  kill mutual exculsion condition from being true
      - unrealistic
* Deadlock Prevention: Hold and Wait
  - Prevent a process from holding resources and requesting others
    - Solution1: request all resources at process creation
    - Solution2: release all held resources before requesting a set of new ones simultaneously
    - Solution3: allowing only holding 1 resources at the time
* Flash Drive --> Harddrive --> Printer
  - Solution1 in action
    - Flash Drive --> Harddrive --> Printer
    - request all of these resources before hand
    - BAD:
      - don't know in advance all resources needed
      - a process that is holding multiple resources for a long time may only need each resource for a short time during exe
  - Solution2 in action
    - obtain the usb and hard drive, then release both together
    - obtain the hard drive and printer, do it
    - BAD:
       - a process that is holding multiple resources for a long time may only need each resource for a short time during exe

  - Solution3 in action
    - Request the USB drive then release
    - Request the hardrive then release
    - Request the hardrive again then release
    - Request printer.
    - BAD:  
      - Some processing may require holding more than one resource at a time

* Deadlock Prevention: Hold and Wait
  - Allow resources to be preempted
    - Policy1
      - 假如X在占有资源又不拉屎，release X直到他有拉屎的能力
    - Policy2
      - 假如Y在等另外资源，Y占有不需要的资源that X需要，Y release
  - BAD:
    - 假如你打印东西，你打了一半。。。然后被release了。。不坑爹么
    
* Deadlock Prevention: Circular Wait
  - A process can only hold 1 resource at a time
  - A good approach for Dinng Table with the ordering
    - 从小到大的顺序， P5左边是R1右边是R5，会先从左边找起，R1被干了的话，R5就不占用他，这时候P4就可以用R5了
  - BAD
    - Time consuming(many release and acquire)
    - Headache to manage

Deadlock Avoidance: 
-----------------
    - Goal: analyze the system state to see if there is a way to avoid deadlock(way out of deadlock)(Worst case analysis)
    - BAD:
        - need to priori info
    - Simple strategy：
        - 给一个预算最大值
