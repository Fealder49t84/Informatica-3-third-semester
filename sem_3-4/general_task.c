#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char* argv[], char* envp[]){

    int a = 13;

    int fork_meaning = fork();

    if (fork_meaning > 0){

        /*It's a parrent process*/

        scanf("%d", &a);

        printf("new a = %d, Pid = %d, Ppid = %d\n", a + 5, getpid(), getppid());


    } else if (fork_meaning == 0){

        /*It's a child process*/

        char name[200];

        size_t i = 2;

        for (; argv[0][i + 3] != '\0'; i ++){

            name[i - 2] = argv[0][i];
        }

        name[i - 2] = 'c';
        name[i - 1] = '\n';

        for(size_t j = 0; j < 100; j ++)
            printf("%c", name[j]);

        printf("\n");



        execle("/bin/cat", "/bin/cat", "general_task.c", 0, envp);

        printf("AN ERROR IN A CHILD PROCESS: Pid = %d, Ppid = %d\n", getpid(), getppid());

        exit(-1);

    } else {

        printf("The process was't duplucated: Pid = %d, Ppid = %d\n", getpid(), getppid());
    }

    return 0;
}