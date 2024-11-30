#include <stdio.h>
#include <sys/types.h>  //size_t/pid_t

#include <fcntl.h>      //open
#include <sys/stat.h>   //umask
#include <unistd.h>     //read/write/close
#include <stdlib.h>     //exit

const unsigned int lenth_of_reading = 100;
const unsigned int standard_IO_stream = 0;

int main (){

    int fd = -1;
    char buf[lenth_of_reading];

    if((fd = open("My_file", O_RDONLY)) < 0){

        printf("ERROR: <My_file> wasn't open!\n");
        exit(-1);
    }

    if(read(fd, buf, lenth_of_reading) < lenth_of_reading){

        printf("ERROR: <My_file> was't entirely read!\n");
        //exit(-1);
    }


    if(write(standard_IO_stream, buf, sizeof(buf)) != /*!!*/ sizeof(buf)){ //size of buf could be less, than expected lenth of the file

        printf("ERROR: standart stream denied outing!\n");
        exit(-1);
    }


    if(close(fd) < 0){

        printf("ERROR: My_file wasn't closed!\n");
        exit(-1);
    }

    return 0;
}