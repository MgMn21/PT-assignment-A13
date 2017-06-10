/**
*       @file functions.c
*       @brief this source file will contain definitions of all of
*       the program's functions.
*
*       @author Matei Nicolae
*
*       @date 06/10/2017
*/

#include "functions.h"

/**
*       This method will be used to compute the total sum of calories
*       in the selected pack
*       @author Matei Nicolae
*       @param list[]   The structure which holds the data
*              num      The total number of snacks in the pack
*/
int sum(calorie list[], int num) {

        int s = 0;                      /// s is used to store the sum
        for(int i = 0; i < num; i++){   /// i is used to iterate trough the list
            s = s + list[i].val;
        }
        return s;
}

/**
*       This method will be used to read the contents of the selected pack
*       from a file
*       @author Matei Nicolae
*       @param nrOfelements   The number of elements/snacks in the pack
*              list[]         The structure which holds the data
*              file           FILE type object for file Input
*/
void readPack(int nrOfelements, calorie list[], FILE *file){

        int i, j;     /// i - iterator for the list[] structure, j - iterator for the name[] string
        char ch;      /// ch - helper for reading the string character by character

        for(i = 0; i < nrOfelements; i++){          /// This reads and stores the name string
            j = 0;
            while((ch = fgetc(file)) != '\n'){
                list[i].name[j] = ch;
                j++;
            }
        }

        for(i = 0; i < nrOfelements; i++){          /// This reads and stores the integer calorie value
            fscanf(file, "%d", &list[i].val);\
        }

        printf("\n  -- Your selected pack contains the following %d snacks: --\n\n", nrOfelements);

        for(i = 0; i < nrOfelements; i++){          /// This goes through the list and prints the data
            j = 0;
            while(list[i].name[j] != '\0'){
                printf("%c", list[i].name[j]);
                j++;
            }
            printf(" - %d cal\n", list[i].val);
        }
        printf("\n  -- For a total of %d calories\n\n --\n", sum(list, nrOfelements));
}

/**
*       This method will be used to read the contents of the selected exercise list
*       from a file
*       @author Matei Nicolae
*       @param nrOfexercises   The number of elements/exercises in the list
*              exerciselist[]  The structure which holds the data
*              exfile          FILE type object for file Input
*/
void readExercises(int nrOfexercises, calorie exerciselist[], FILE *exfile){

        int i, j;        /// i - iterator for the exerciselist[] structure, j - iterator for the name[] string
        char cha;        /// cha - helper for reading the string character by character

        for(i = 0; i < nrOfexercises; i++){         /// This reads and stores the name string
            j = 0;
            while((cha = fgetc(exfile)) != '\n'){
                exerciselist[i].name[j] = cha;
                j++;
            }
        }

        for(i = 0; i < nrOfexercises; i++){                 /// This reads and stores the integer calorie value
            fscanf(exfile, "%d", &exerciselist[i].val);\
        }
}

/**
*       This method will be used to compute the solution for out problem,
*       if a solution exists
*       @author Matei Nicolae
*       @param exerciselist[]   The structure which holds the data
*              targetsum        The target amount of calories we aim to burn
*              index            Variable used to search the data
*              nrofexercises    The number of exercises in the list
*              currsum          Variable used to store the sum at the current iteration
*              solution[]       Array used to store the indexes of the elements that led us to the solution
*              lastsum          Variable used to calculate weather the current sum is, or is closer, to the solution
*              foundsol         Variable used to check if we have reached a solution
*              resultfile       FILE type object for file Output
*/
void findSolution(calorie exerciselist[], int targetsum, int index, int nrofexercises, int currsum, int solution[], int lastsum, int *foundsol, FILE *resultfile){

        if((currsum + targetsum) <= lastsum){     /// This checks if our current sum is closer to the target that the last calculated sum
            lastsum = currsum + targetsum;
        }

        if(lastsum == 0){                         /// If we reach the target we print out the solution

            printf("\n  -- Exercise routine found for a total caloric intake of 0: --\n\n");
            fprintf(resultfile ,"       --  Here is your exercise routine  --\n\n");

            for(int i =0; i < 51; i++){

                if(solution[i] == 1){               /// This checks if an element is part of the solution
                    int j = 0;
                    while(exerciselist[i].name[j] != '\0'){
                        printf("%c", exerciselist[i].name[j]);
                        fprintf(resultfile, "%c", exerciselist[i].name[j]);
                        j++;
                    }

                    printf(" -> %d cal\n", exerciselist[i].val);
                    fprintf(resultfile, " -> %d cal\n", exerciselist[i].val);    /// We also output the solution to a file
                    *foundsol = 1;              /// We confirm that we have found a solution
                }
            }

            printf("\n  -- The routine was saved on your computer in the file 'result.txt' --\n\n");
            exit(1);            /// We exit since we only need to find one of the possible solutions

        }
        else{
            if(index == nrofexercises){
                return;                         /// If we have reached the end of the data structure we stop the current search
            }
            else {
                solution[index] = 1;                            /// The following calls add and remove elements in order to find
                currsum = currsum + exerciselist[index].val;    ///and check every possible combination of elements that could lead us to our solution
                findSolution(exerciselist, targetsum, index + 1, nrofexercises, currsum, solution, lastsum, foundsol, resultfile);
                currsum = currsum - exerciselist[index].val;
                solution[index] = 0;
                findSolution(exerciselist, targetsum, index + 1, nrofexercises, currsum, solution, lastsum, foundsol, resultfile);
            }
        }

        return;
}
