#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

    pid_t pid, ppid;
    int a = 0;

    fork();

    a = a + 1;

    pid = getpid();
    ppid = getppid();
    
    printf("Mypid = %d, Myppid = %d, result_a = %d\n", pid, ppid, a);

return 0;
}