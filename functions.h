#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[3];
    int val;
} calorie;


int sum(calorie list[], int num);

#endif // FUNCTIONS_H_INCLUDED