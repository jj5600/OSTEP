#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

 int main(int argc, char *argv[]) {
 int sz;
 int fd = open("booboo.txt", O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
 int rc = fork();
 if (rc < 0) {
   // fork failed
   fprintf(stderr, "fork failed\n");
   exit(1);
 } else if (rc == 0) {
    // child: redirect standard output to a file
     //open("booboo.txt", O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
    printf("THIS IS FD IN CHILD PROCESS: %d \n", fd);
    sz = write(fd, "BOOBOO\n", strlen("BOOBOO\n")); 
 } else {
 // parent goes down this path (main)
   int rc_wait = wait(NULL);
   printf("THIS IS FD IN PARENT PROCESS: %d \n", fd);
   sz = write(fd, "hello geeks from parent\n", strlen("hello geeks from parent\n")); 
 }
 return 0;
 }
