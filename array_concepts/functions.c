#include <stdlib.h>
#include <stdio.h>

void Reverse(int * ptr, size_t size)
{
    size_t start, end;
    start = 0;
    end = size-1;
    int *iter = ptr;
    int temp;

    while(start < end)
    {
        // "no temp variable way"
        iter[start] = iter[start] + iter[end];
        iter[end] = iter[start] - iter[end];
        iter[start] = iter[start] - iter[end];
        // "traditinal way"
       //temp = iter[start];
       //iter[start] = iter[end-1];
       //iter[end-1] = temp; 
        start++;
        end--;
    }  
}

void PrintArray(int ptr[],size_t size)
{
    int * iter = ptr;
    for(iter = ptr; iter < ptr + (int)size; iter++)
    {
        printf(" [%d]",*iter);
    }
    printf("\n");
}
