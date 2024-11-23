#include <stdio.h>
#include <sys/types.h>  //size_t, pid_t

#include <sys/stat.h>   //umask
#include <fcntl.h>      //open
#include <unistd.h>     //write, read, pipe
#include <stdlib.h>     //exit

const char str [] = "Hello, World!";
const unsigned int lenth_str = sizeof(str);

int main (){

    int fd[2] = {0, 0};
    char resstr[lenth_str];

    if(pipe(fd) < 0){

        printf("ERROR: pipe wasn\'t correctrly created!\n");
        exit(-1);
    }
printf("fd1 = %d, fd2 = %d\n", fd[1], fd[2]);
    if(write(fd[0], str, lenth_str) != lenth_str){

        printf("ERROR: string wasn\'t completely written into pipe_in!\n");
        // exit(-1);
    }

    if(read(fd[1], resstr, lenth_str) != lenth_str){

        printf("ERROR: str wasn\'t completely read from pipe_out!\n");
        // exit(-1);
    }

    if(close(fd[0]) < 0){

        printf("ERROR: pipe_in wasn\'t closed!\n");
        exit(-1);
    }

    if(close(fd[1]) < 0){

        printf("ERROR: pipe_out wan\'t closed!\n");
        exit(-1);
    }

    printf("%s", resstr);

    return 0;
}