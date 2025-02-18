#include <stdio.h>
#include <string.h>
#define BUFFER 256
#define SIZE 3
char *GetSubstring(const char source[], int start, int count, char result[]);
void Reverse(int * ptr, size_t size);
void PrintArray(int ptr[],size_t size);
int main(void)
{
    char buffer[BUFFER];
    char result[BUFFER];
    int start;
    int count;
    int testArray[SIZE] = {33,22,11};
    char jArray[SIZE] = {'a','z','z'};
    
    int *ptr;
    char *cptr;
    cptr = jArray;
    ptr = testArray;
   
    
    for (ptr = testArray; ptr < testArray + sizeof(testArray) / sizeof(testArray[0]); ptr++)
    {
        printf("[%d] ",*ptr);
    }
    for (cptr = jArray; cptr < jArray + sizeof(jArray) / sizeof(jArray[0]); cptr++)
    {
        printf("%c ",*cptr);
    }
    printf("\n");
    
    Reverse(testArray, sizeof(testArray)/sizeof(testArray[0]));
    PrintArray(testArray, sizeof(testArray)/sizeof(testArray[0]));
    
    return 0;
}
