#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[], char* envp[]){

    execle("/bin/cat", "/bin/cat", "example_exec.c", 0, envp);

    printf("ERROR OCCURED!!\n");

    exit(-1);

    return 0;
}
