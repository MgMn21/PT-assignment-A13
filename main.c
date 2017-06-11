///\file main.c
///\brief Source file containing the main function.
///\author Popescu Matei

#include "functions.h"

int main(){
        /*!
            \fn int main()
            \brief This is the main function
        */
        resultfile = fopen("result.txt", "w");

        /*!
            \var int test
            \brief Variable for the UI

            Used to select the pack
        */
        int test;

        /*!
            \var int nrOfsnacks
            \brief Used to store the number of snacks in the pack
        */
        int nrOfsnacks;

        /*!
            \var int nrOfexercises
            \brief Used to store the number of activities in the list
        */
        int nrOfexercises;

        /*!
            \var int routines
            \brief Variable for the UI

            Used to select the exercise list
        */
        int routines;

        /*!
            \var int valid
            \brief Variable for the UI

            Used to check if the user entered a valid option
        */
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

        /*!
            \var int targetsum
            \brief Used to store the total caloric impact of the snacks
        */
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

        /*!
            \var int index
            \brief Used to iterate trough the data
        */
        int index = 0;

        /*!
            \var int lastsum
            \brief Used to check if the current sum is close to a solution
        */
        int lastsum = (2^31)-1;

        /*!
            \var int currsum
            \brief Used to store the current sum
        */
        int currsum = 0;

        /*!
            \var int solution
            \brief Used to store the indexes of the elements whose sum led us to the solution
        */
        int sollution[51];

        /*!
            \var int foundsol
            \brief Used to check if a solution was found
        */
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
