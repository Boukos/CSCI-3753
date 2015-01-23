
#include<stdio.h>
#include<unistd.h>
#include<sys/syscall.h>

//#include "syscalls.h"
int main(void)

{
    int a, b;
    int ret;
    //syscall(319, 10, 20, &ret);
  	//printf("%d\n", &ret);				 // 0  --> return 0 meaning sucsess
    printf("%ld\n", syscall(319,10,20,&ret)); 			// 30 --> return a value stored in pointer c
}



/*#include <linux/kernel.h>
#include <linux/linkage.h>

asmlinkage long sys_simple_add(int number1, int number2, int* result)
{
 *result = (number1+number2);
 printk(KERN_ALERT "Number one: %d \n", number1);
 printk(KERN_ALERT "Number two: %d \n", number2);
 printk(KERN_ALERT "Sum: %d \n", *result);
 return 0;
}
*/

