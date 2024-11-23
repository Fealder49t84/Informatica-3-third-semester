#include <stdio.h>

int main (int argc, char* argv[], char* envp[]){

    printf("Answers:\n\nargc = %d,\n\nargv = [\n", argc);

    for(size_t i = 0; i < argc; i++){

        printf("\t%d) %s\n", i + 1, argv[i]);
    }

    printf("],\n\nenvp = [\n");

    char* not_end = envp[0];

    for(size_t i = 0; not_end;){

        printf("\t%d} %s\n", i + 1, not_end);

        not_end = envp[++ i];
    }

    printf("];\n\nEND OF AN ANSWER\n");
    return 0;
}