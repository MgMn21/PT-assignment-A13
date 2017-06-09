#include "functions.h"

int sum(calorie list[], int num) {

        int s = 0;
        for(int i = 0; i < num; i++){
            s = s + list[i].val;
        }
        return s;
}

void readPack(int nrOfelements, calorie list[], FILE *file){

        int i, j;
        char ch;

        for(i = 0; i < nrOfelements; i++){
            j = 0;
            while((ch = fgetc(file)) != '\n'){
                list[i].name[j] = ch;
                j++;
            }
        }

        for(i = 0; i < nrOfelements; i++){
            fscanf(file, "%d", &list[i].val);\
        }

        printf("\nYour selected pack contains the following %d snacks:\n\n", nrOfelements);

        for(i = 0; i < nrOfelements; i++){
            j = 0;
            while(list[i].name[j] != '\0'){
                printf("%c", list[i].name[j]);
                j++;
            }
            printf(" - %d\n", list[i].val);
        }
        printf("\nFor a total of %d calories.\n", sum(list, nrOfelements));
}

void readExercises(int nrOfexercises, calorie exerciselist[], FILE *exfile){

        int k, q;
        char cha;

        for(k = 0; k < nrOfexercises; k++){
            q = 0;
            while((cha = fgetc(exfile)) != '\n'){
                exerciselist[k].name[q] = cha;
                q++;
            }
        }

        for(k = 0; k < nrOfexercises; k++){
            fscanf(exfile, "%d", &exerciselist[k].val);\
        }
}
