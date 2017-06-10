/**
*       @file functions.h
*       @brief this header file will contain essential structure definitions,
*       variable and function declarations.
*
*       @author Matei Nicolae
*
*       @date 06/10/2017
*/

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[31];
    int val;
} calorie;

calorie list[51];
calorie exerciseList[51];

FILE *zefile;
FILE *resultfile;

void readPack(int nrOfelements, calorie list[], FILE *file);

void readExercises(int nrOfexercises, calorie exerciselist[], FILE *exfile);

int sum(calorie list[], int num);

void findSolution(calorie exerciselist[], int targetsum, int index, int nrofexercises, int currsum, int solution[], int lastsum, int *foundsol, FILE* resultfile);

#endif // FUNCTIONS_H_INCLUDED
