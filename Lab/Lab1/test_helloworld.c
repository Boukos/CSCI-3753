#include<stdio.h>
#include<unistd.h>
#include<sys/syscall.h>




//#include "syscalls.h"

int main(void)

{

printf("%ld\n", syscall(318));

}