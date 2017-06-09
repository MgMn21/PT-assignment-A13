#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[3];
    int val;
} calorie;

void readPack(int nrOfelements, calorie list[], FILE *file);

void readExercises(int nrOfexercises, calorie exerciselist[], FILE *exfile);

int sum(calorie list[], int num);

#endif // FUNCTIONS_H_INCLUDED
