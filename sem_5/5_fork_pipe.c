#include <stdio.h>
#include <sys/types.h>  //size_t, pid_t

// #include <fcntl.h>      //open
// #include <sys/stat.h>   //umask

#include <unistd.h>     //fork, read, write, close, pipe
#include <stdlib.h>     //exit

unsigned int lenth_of_buffer = 100;
enum{ERROR_NUMBER = -1333};

int main (){

    int pipe_rw[2] = {0, 0};
    char buf[lenth_of_buffer];

    if(pipe(pipe_rw) < 0){

        printf("ERROR: pipe wasn't correctly open!\n");
        exit(-1);
    }

    int fork_ret = fork();

    if(fork_ret < 0){

        printf("ERROR: fork wan't done!\n");
        exit(-1);
    }
    else if(fork_ret == 0){ // Child process

        close(pipe_rw[1]);

        if((read(pipe_rw[0], buf, lenth_of_buffer)) < 0){

            printf("ERROR: pipe wasn't correctly read!\n");
            exit(-1);
        }

        int a = ERROR_NUMBER;
        int b = ERROR_NUMBER;

        sscanf(buf, "%d %d", &a, &b);

        printf("buf =\'%s\'\n%d + %d = %d\n", buf, a, b, a + b);

        printf("Child died!\n");
    }
    else{ // Parent process

        close(pipe_rw[0]);

        char * str[lenth_of_buffer];

        scanf("%[^\n]", str);

        if((write(pipe_rw[1], str, lenth_of_buffer)) != lenth_of_buffer){

            printf("ERROR: elements weren;t correctrly written into pipe!\n");
            exit(-1);
        }

        printf("Parent died!\n");
    }

    return 0;
}