/**
*       @file main.c
*       @brief this source file will contain local helper variables for our
*       functions, calls to the functions and implementation of a basic UI.
*
*       @author Matei Nicolae
*
*       @date 06/10/2017
*/

#include "functions.h"

int main()
{
        resultfile = fopen("result.txt", "w");

        int test;                  /// This is used to select the pack we will test
        int nrOfsnacks;            /// Used to store the number of snacks in the pack
        int nrOfexercises;         /// Used to store the number of exercises in the list
        int routines;              /// Used to select the exercise routine we will be searching the solution in
        int valid = 0;             /// Used to check if the user has selected a valid option

        while(valid == 0){
            printf("Select your preferred snack pack:\n\n1.Pack#1\n2.Pack#2\n3.Pack#3\n4.Pack#4\n5.Pack#5\n\n   #");
            scanf("%d", &test);
            switch(test) {
                case 1:
                    zefile = fopen("test1.txt", "r");
                    valid = 1;
                    break;
                case 2:
                    zefile = fopen("test2.txt", "r");
                    valid = 1;
                    break;
                case 3:
                    zefile = fopen("test3.txt", "r");
                    valid = 1;
                    break;
                case 4:
                    zefile = fopen("test4.txt", "r");
                    valid = 1;
                    break;
                case 5:
                    zefile = fopen("test5.txt", "r");
                    valid = 1;
                    break;
                default:
                    printf("\n  -- Please select a valid option --\n\n");
                    break;
            }
        }

        fscanf(zefile, "%d", &nrOfsnacks);          /// We read the number of snacks in the pack from the file
        readPack(nrOfsnacks, list, zefile);         /// We read and store the selected pack

        int targetSum = sum(list, nrOfsnacks);      /// We compute and store the total calorie count of the selected pack

        fclose(zefile);

        valid = 0;          /// We reinitialize the validity check for the routine selection

        while(valid == 0){

            printf("Select your preferred exercise list:\n\n1.Routine#1\n2.Routine#2\n3.Routine#3\n\n    #");
            scanf("%d", &routines);

            switch(routines) {
                case 1:
                    zefile = fopen("routine1.txt", "r");
                    valid = 1;
                    break;
                case 2:
                    zefile = fopen("routine2.txt", "r");
                    valid = 1;
                    break;
                case 3:
                    zefile = fopen("routine3.txt", "r");
                    valid = 1;
                    break;
                default:
                    printf("\n  -- Please select a valid option --\n\n");
                    break;
            }
        }

        fscanf(zefile, "%d", &nrOfexercises);               /// We read the number of exercises in the routine from the file
        readExercises(nrOfexercises, exerciseList, zefile);     /// We read and store the selected routine

        int index = 0;              /// We initialize the index used in the findSolution function
        int lastsum = (2^31)-1;     /// We set the lastsum variable to a very high number
        int currsum = 0;            /// We initialize the current sum with 0
        int sollution[51];          /// We will store the indexes of the used elements in this array
        int foundsol = 0;           /// We initialize the solution check with 0

        findSolution(exerciseList, targetSum, index, nrOfexercises, currsum, sollution, lastsum, &foundsol, resultfile);

        fclose(zefile);         /// We close the I/O streams
        fclose(resultfile);

        if(foundsol == 1){      /// We check if we have found a solution
            return 0;           /// If we have we end the program
        }
        else{                   /// If we haven't we tell the user that no solution has been found and end the program
              printf("\n  -- Unfortunately we can not find a balanced exercise routine for snack pack #%d from exercise list #%d --\n\n", test, routines);
              return 0;
        }
}
