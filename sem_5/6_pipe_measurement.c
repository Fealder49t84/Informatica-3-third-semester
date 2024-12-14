#include <stdio.h>
#include <sys/types.h>  //size_t, pid_t

#include <fcntl.h>      //open
#include <sys/stat.h>   //umask

#include <unistd.h>     //fork, read, write, close, pipe
#include <stdlib.h>     //exit

int main (){

    int fd[2];
    size_t i = 0;
    
    if(pipe(fd) < 0){

        printf("ERROR: pipe wans't correctly opened!\n");
        exit(-1);
    }

    while(write(fd[1], "1", 1)){

        // printf("%u\n", i);
        i++;
    }

    printf("%u\n", i);

    return 0;
}