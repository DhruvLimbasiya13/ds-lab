#include<stdio.h>
#include<stdlib.h>
void main(){
    int *a = (int*)malloc(sizeof(int)*5);
    float *b = (float*)malloc(sizeof(float)*5);
    int *c = (int*)malloc(sizeof(char)*5);

    if (a && b && c)
    {
        *a=5;
        *b=10.5;
        *c='h';

        printf("%d\t%f\t%c",*a,*b,*c);
    }
    else{
        printf("memory allocation failed");
    }

    free(a);
    free(b);
    free(c);
}