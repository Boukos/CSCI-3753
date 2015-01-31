Problem1
--------
|Process|Time(secs)|
|-------|----------|
|p1|10|
|p2|8.5|
|p3|3| 
Time Slice: 2 seconds

***************************
* **1. Timeline of execution**

|Seconds|Process|
|-------|-------|
|0 :arrow_right: 2|p1|
|2 :arrow_right: 4|p2|
|4 :arrow_right: 6|p3|
|6 :arrow_right: 8|p1|
|8 :arrow_right: 10|p2|
|10 :arrow_right: 11|**p3**(finished)|
|11 :arrow_right: 13|p1|
|13 :arrow_right: 15|p2|
|15 :arrow_right: 17|p1|
|17 :arrow_right: 19|p2|
|19 :arrow_right: 21|**p1**(finished)|
|21 :arrow_right: 21.5|**p2**(finished)|

***************************
* **2. Finishing Time**
  * p3 finishes at 11 seconds
  * p2 finishes at 21.5 seconds
  * p1 finishes at 21 seconds

***************************
* **3. Percentage Overhead**
  - Time Switch : 11 times
  - 0.2 / 2 = 10%  and it's been used 11 times.

***************************

Problem2
---------
|Process|Time(secs)|
|-------|----------|
|p1|10|
|p2|8.5|
|p3|3| 

***************************
* **1. Timeline of execution**

|Seconds|Process|
|-------|-------|
|0 :arrow_right: 10|p1|
|10 :arrow_right: 18.5|p2|
|18.5 :arrow_right: 21.5|p3|

********************************
* **2. Finishing Time**
  * p3 finishes at 21.5 seconds
  * p2 finishes at 18.5 seconds
  * p1 finishes at 10 seconds
  

****************************

* **3. Percentage Overhead**
  - Time Switch : 2 times
  - 0.2 / 2 = 10%  and it's been used 2 times.
