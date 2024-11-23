#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>

int main (){

    pid_t pid, ppid, fork_que;
    int a = 0;

    fork_que = fork();

    switch(fork_que){

        case -1:

            /*ERROR*/
            printf("\t\t\tTHE ERROR OCCURED!!\n\n\n");
            break;

        case 0:

            /*This is a child process*/
            int b = -1;
            scanf("%d", &b);

            a += abs(b);

            break;

        default:

            /*This is a parrent process*/
            a += 10;

            printf("\t");
    };

    pid     = getpid();
    ppid    = getppid();

    printf("MyPid = %d, MyPPid = %d, result_a = %d\n", pid, ppid, a);

return 0;
}