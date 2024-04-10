#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

int main(int argc, char* argv[]) {

    printf("Process %d start\n",  (int)getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child
        printf("I am child: %d\n", (int) getpid());        
        char *myargs[3];
        myargs[0] = strdup("wc");
        myargs[1] = strdup("fork3.c");
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
        printf("Can we reach here?\n");

    } else {
        int wc = wait(NULL);
        printf("I am parent of %d, and I am %d\n", rc, (int) getpid());
    }
    return 0;
}
