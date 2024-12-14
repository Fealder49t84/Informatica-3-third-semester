#include <stdio.h>
#include <sys/types.h>  //size_t, pid_t

#include <unistd.h>     //fork, read, write, close
#include <stdlib.h>     //exit

int main(){

    int fd[2], result;
    size_t size;
    char resstring[14];


    if(pipe(fd) < 0){

        printf("ERROR: pipe wasn\'t correctrly created!\n");
        exit(-1);
    }

    result = fork();

    if(result < 0){ //ERROR

        printf("ERROR: fork wasn't done");
        exit(-1);

    }
    else if (result > 0){ //Child process

        close(fd[0]);

        size = write(fd[1], "Hello, world!", 14);

        if(size != 14){

            printf("ERROR: Can\'t write all string\n");
            exit(-1);
        }

        close(fd[1]);
        printf("Parent exit\n");

    }
    else{ //Parent process

        close(fd[1]);

        size = read(fd[0], resstring, 14);
        if(size < 0){

        printf("ERROR: Can\'t read string\n");
        exit(-1);
        }

        printf("%s\n",resstring);

        close(fd[0]);
        printf("Child exit\n");
    }

    return 0;
}