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

        printf("\n  -- Your selected pack contains the following %d snacks: --\n\n", nrOfelements);

        for(i = 0; i < nrOfelements; i++){
            j = 0;
            while(list[i].name[j] != '\0'){
                printf("%c", list[i].name[j]);
                j++;
            }
            printf(" - %d cal\n", list[i].val);
        }
        printf("\n  -- For a total of %d calories --\n", sum(list, nrOfelements));
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

void findSolution(calorie exerciselist[], int targetsum, int index, int nrofexercises, int currsum, int solution[], int lastsum, int *foundsol, FILE *resultfile){

        if(((currsum + targetsum) <= lastsum) && ((currsum + targetsum) >= 0)){
                    lastsum = currsum + targetsum;
           }

        if(lastsum == 0){
            printf("\n  -- Exercise routine found for a total caloric intake of 0: --\n\n");
            fprintf(resultfile ,"       --  Here is your exercise routine  --\n\n");
            for(int i =0; i < 51; i++){
                if(solution[i] == 1){
                    int j = 0;
                    while(exerciselist[i].name[j] != '\0'){
                        printf("%c", exerciselist[i].name[j]);
                        fprintf(resultfile, "%c", exerciselist[i].name[j]);
                        j++;
                    }
                    printf(" -> %d cal\n", exerciselist[i].val);
                    fprintf(resultfile, " -> %d cal\n", exerciselist[i].val);
                    *foundsol = 1;
                }
            }
            printf("\n  -- The routine was saved on your computer in the file 'result.txt' --\n\n");
            return;
        }else{
            if(index == nrofexercises){
                return;
            }else {
                solution[index] = 1;
                currsum = currsum + exerciselist[index].val;
                findSolution(exerciselist, targetsum, index + 1, nrofexercises, currsum, solution, lastsum, foundsol, resultfile);
                currsum = currsum - exerciselist[index].val;
                solution[index] = 0;
                findSolution(exerciselist, targetsum, index + 1, nrofexercises, currsum, solution, lastsum, foundsol, resultfile);
            }
        }

        return;
}
