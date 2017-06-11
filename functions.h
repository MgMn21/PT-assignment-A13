///\file functions.h
///\brief Header file containing essential structure definitions, variable and function declarations.
///\author Popescu Matei

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/**
    \struct calorie
    \brief A type definition for a data structure.

    The structure will be used to store the names and caloric impact of our objects.
*/
typedef struct{
    char name[31];
    int val;
} calorie;

/**
    \var calorie list[]
    \brief Used to store the names and caloric impact of the snacks.
*/
calorie list[51];

/**
    \var calorie exerciseList[]
    \brief Used to store the names and caloric impact of the activities.
*/
calorie exerciseList[51];

/**
    \var FILE *zefile
    \brief Object used to manipulate the file input
*/
FILE *zefile;

/**
    \var FILE *resultfile
    \brief Object used to manipulate the file output
*/
FILE *resultfile;

/**
    \fn void readPack(int nrOfelements, calorie list[], FILE *file)
    \brief This method will be used to read the contents of the selected pack from a file
    \param nrOfelements The number of elements/snacks in the pack
    \param list[] The structure which holds the data
    \param file FILE type object for file Input
*/
void readPack(int nrOfelements, calorie list[], FILE *file);
/**
    \fn void readExercises(int nrOfexercises, calorie exerciselist[], FILE *exfile)
    \brief This method will be used to read the contents of the selected exercise list from a file
    \param nrOfexercises   The number of elements/exercises in the list
    \param exerciselist[]  The structure which holds the data
    \param exfile          FILE type object for file Input
*/
void readExercises(int nrOfexercises, calorie exerciselist[], FILE *exfile);

/**
    \fn int sum(calorie list[], int num)
    \brief This method will be used to compute the total sum of calories in the selected pack
    \param list[] The structure which holds the data
    \param num The total number of snacks in the pack
*/
int sum(calorie list[], int num);

/**
    \fn void findSolution(calorie exerciselist[], int targetsum, int index, int nrofexercises, int currsum, int solution[], int lastsum, int *foundsol, FILE *resultfile)
    \brief This method will be used to compute the solution for out problem, if a solution exists
    \param exerciselist[] The structure which holds the data
    \param targetsum The target amount of calories we aim to burn
    \param index Variable used to search the data
    \param nrofexercises The number of exercises in the list
    \param currsum Variable used to store the sum at the current iteration
    \param solution[] Array used to store the indexes of the elements that led us to the solution
    \param foundsol Variable used to check if we have reached a solution
    \param resultfile FILE type object for file Output
*/
void findSolution(calorie exerciselist[], int targetsum, int index, int nrofexercises, int currsum, int solution[], int *foundsol, FILE* resultfile);


#endif // FUNCTIONS_H_INCLUDED
