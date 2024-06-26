/*
 *	Fork example 2 for INU OS class
 * 
 *  Orignial code: p2.c in the book OS Three Easy Pieces (Section Process API )
 *  Modified by ypkim@inu.ac.kr
 *  Created: 2024. 4
 *  Updated: 
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

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
    } else {
        int wc = wait(NULL);
        printf("I am parent of %d, and I am %d\n", rc, (int) getpid());
    }
    return 0;
}
