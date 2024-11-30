#include <stdio.h>
#include <sys/types.h> // size_t, pid_t

#include <fcntl.h>      //open
#include <sys/stat.h>   //umask
#include <unistd.h>     //read, write, close
#include <stdlib.h>     //exit

int main (){

    int fd;
    char str[] = "Hello, World!";

    umask(0);

    if((fd = open("My_file", O_WRONLY | O_CREAT, 0666)) < 0){

        printf("ERROR: The file <My_file> wasn't open!\n");
        exit(-1);
    }

    if(write(fd, str, sizeof(str)) != sizeof(str)){

        printf("ERROR: <My_file> wasn't entirely updated by str!\n");
        // exit(-1);
    }

    printf("fd = %d\n", fd);

    if(close(fd) < 0){

        printf("ERROR: <My_file> wasn't correctly closed!\n");

        exit(-1); //  ?
    }

    return 0;
}