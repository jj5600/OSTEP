#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){

    printf("hello (pid:%d)\n", (int) getpid());
    int x = 100;
    int rc = fork();
    if (rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) { // child (new process)
        
        printf("child (pid:%d) : Current X values: %d\n", (int) getpid(),x);
        x=4;
    } else { // parent goes down this path

        int rc_wait = wait(NULL);
        printf("parent of %d (rc_wait:%d) (pid:%d): Value of X: %d\n", rc, rc_wait, (int) getpid(),x);
        //printf("parent of %d (rc_wait:%d)  Value of X: %d\n", rc, (int) getpid(),x);
        x=5;
 }
    printf("THIS IS THE FINAL VALUE OF X: %d\n",x);
    return 0;
}
