#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



int main(int argc, char * argv[])
{

    printf("Hello World!\n");

    int x=5;
    printf("This is the sizeof(int): %d bytes \n", sizeof(int));

    int * ptr = (int *)malloc(sizeof(int));
    if(ptr == NULL)
    {

        printf("MEM ALLOCATION FAILED");
        exit(1);
    
    }
    printf("This is the value ref by pointer: %d\n",*ptr);
    printf("This is the addr ref by pointer: %x\n", ptr);
    *ptr=7;

    printf("This is the value ref by pointer: %d\n",*ptr);
    printf("This is the addr ref by pointer: %x\n", ptr);

    free(ptr);
    printf("******************************************\n");


    int * zPtr = (int*)malloc(sizeof(int)*10);
    printf("here is each element in zPtr array: ");
    int t=0;
    for(int i=0; i<9; i++){
        
        printf("%d",*(zPtr+i));
    }
    

    printf("\nDONE");

    printf("Now I am changing the values in here\n");

    for(int i=0; i<9; i++){
        
      *(zPtr+i)= 9;

    }

  printf("here is each element in zPtr array: ");

    for(int i=0; i<9; i++){
        
        printf("%d",*(zPtr+i));
    }


    free(zPtr);

    printf("\nFREED\n*******************\n");
    char *src = "BooBoo";
    char srcA[]= "JOSEPH";
    int size = sizeof(src)+1;
    char * destPtr = (char *)malloc(strlen(src)+1);
    if(destPtr == NULL)
    {

        printf("Error with Mem allocation\n");
        exit(1);

    }

    strcpy(destPtr,src);
    printf("This is the size: %d\n",size);
    printf("Thi sis the sizeof(char *): %d\n",sizeof(char*));
    printf("This is the sizeof(src): %d\n",sizeof(src));
    printf("This is the sizeof(*src): %d\n",sizeof(*src));

     printf("This is the srcA: %c\n",srcA);
    //printf("Thi sis the sizeof(char *): %d\n",sizeof(char*));
    printf("This is the sizeof(srcA): %d\n",sizeof(srcA));
    printf("This is the string: %s!\n",srcA);
    //printf("This is the sizeof(*src): %d\n",sizeof(*src));
    for(int i=0;i<sizeof(srcA)+1; i++){

        printf("%c.\n",*(srcA+i));

        if((*srcA+i) == '\0')
        {

            printf("**FOUND THE NULL char**");
        }
    }



    free(destPtr);
    return 0;
}
