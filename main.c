///@file main.c
///@brief Source file containing local helper variables for our functions, calls to the functions and implementation of a basic UI.

#include "functions.h"

int main()
{

        ///@fn int main()
        ///@brief Main function
        ///Function calls for sum, readPack, readExercises and findSolution imported from functions.h
        ///The calorie structure is defined in functions.h
        ///The FILE and calorie type variables are declared in functions.h
        ///@var test Helper for the UI, selects the pack
        ///@var nrOfsnacks The number of snacks in a pack
        ///@var nrOfexercises The number of exercises in a list
        ///@var routines Helper for the UI, selects the exercise list
        ///@var valid Helper for the UI, checks if the user introduced a valid input
        ///@var index Parameter for the findSolution function
        ///@var lastsum Parameter for the findSolution function
        ///@var currsum Parameter for the findSolution function
        ///@var sollution Parameter for the findSolution function
        ///@var foundsol Parameter for the findSolution function

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

        fscanf(zefile, "%d", &nrOfexercises);
        readExercises(nrOfexercises, exerciseList, zefile);

        int index = 0;
        int lastsum = (2^31)-1;
        int currsum = 0;
        int sollution[51];
        int foundsol = 0;

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
