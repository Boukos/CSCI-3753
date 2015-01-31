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

* p3 finishes at 11 seconds
* p2 finishes at 21.5 seconds
* p1 finishes at 21 seconds

***************************
