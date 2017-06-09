#include "functions.h"

int main()
{
        calorie list[51], exerciseList[51];
        FILE *zefile;
        int test, nrOfsnacks, nrOfexercises;
        printf("Select your preferred snack pack:\n\n1.Pack#1\n2.Pack#2\n3.Pack#3\n4.Pack#4\n5.Pack#5\n\n# ");
        scanf("%d", &test);

        memset(list, 0, 51);
        memset(exerciseList, 0, 51);

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

        zefile = fopen("exerfile.txt", "r");
        fscanf(zefile, "%d", &nrOfexercises);
        readExercises(nrOfexercises, exerciseList, zefile);


        return 0;
}
