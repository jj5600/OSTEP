#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

 int main(int argc, char *argv[]) {
 int sz;
 int status;
char *args[2];

args[0] = "/bin/ls";        // first arg is the full path to the executable
args[1] = NULL;             // list of args must be NULL terminated

 int rc = fork();
 if (rc < 0) {
   // fork failed
   fprintf(stderr, "fork failed\n");
   exit(1);
 } else if (rc == 0) {
    // child: redirect standard output to a file
 
     execv( args[0], args );
  
 }else{
   
  // parent goes down this path (main)
   int rc_wait = wait(NULL);

 }
 return 0;
 }
