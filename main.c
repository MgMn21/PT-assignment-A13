#include "functions.h"

calorie list[51], exerciseList[51];

int main()
{
        FILE *zefile;
        FILE *resultfile = fopen("result.txt", "w");
        int test, nrOfsnacks, nrOfexercises, routines;
        printf("Select your preferred snack pack:\n\n1.Pack#1\n2.Pack#2\n3.Pack#3\n4.Pack#4\n5.Pack#5\n\n   #");
        scanf("%d", &test);

        switch(test) {
            case 1:
                zefile = fopen("test1.txt", "r");
                break;
            case 2:
                zefile = fopen("test2.txt", "r");
                break;
            case 3:
                zefile = fopen("test3.txt", "r");
                break;
            case 4:
                zefile = fopen("test4.txt", "r");
                break;
            case 5:
                zefile = fopen("test5.txt", "r");
                break;
        }

        fscanf(zefile, "%d", &nrOfsnacks);
        readPack(nrOfsnacks, list, zefile);
        int targetSum = sum(list, nrOfsnacks);
        fclose(zefile);

        printf("\n\n\nSelect your preferred exercise list:\n\n1.Routine#1\n2.Routine#2\n3.Routine#3\n\n    #");
        scanf("%d", &routines);

        switch(test) {
            case 1:
                zefile = fopen("routine1.txt", "r");
                break;
            case 2:
                zefile = fopen("routine2.txt", "r");
                break;
            case 3:
                zefile = fopen("routine3.txt", "r");
                break;
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
        } else{
              printf("\n  -- Unfortunately we can not find a balanced exercise routine for snack pack #%d from exercise list %d --\n\n", test, routines);
              return 0;
          }
}
