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
        int test;
        int nrOfsnacks;
        int nrOfexercises;
        int routines;
        int valid = 0;

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

        fscanf(zefile, "%d", &nrOfsnacks);
        readPack(nrOfsnacks, list, zefile);

        int targetSum = sum(list, nrOfsnacks);

        fclose(zefile);

        valid = 0;

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

        fscanf(zefile, "%d", &nrOfexercises);
        readExercises(nrOfexercises, exerciseList, zefile);

        int index = 0;
        int lastsum = (2^31)-1;
        int currsum = 0;
        int sollution[51];
        int foundsol = 0;

        findSolution(exerciseList, targetSum, index, nrOfexercises, currsum, sollution, lastsum, &foundsol, resultfile);

        fclose(zefile);
        fclose(resultfile);

        if(foundsol == 1){
            return 0;
        }
        else{
              printf("\n  -- Unfortunately we can not find a balanced exercise routine for snack pack #%d from exercise list #%d --\n\n", test, routines);
              return 0;
        }
}
