/*
    Unfortunately I couldn't include this file in the doxigen documentation because
    it would've taken all of the functions twice, but since the comments for the functions are
    in the header file this one only needed comments on a few variables anyway so no major loss.
*/

#include "functions.h"

int sum(calorie list[], int num){

        int s = 0;                      //s - used to store the sum
        for(int i = 0; i < num; i++){   //i - used to iterate trough the list
            s = s + list[i].val;
        }
        return s;
}

void readPack(int nrOfelements, calorie list[], FILE *file){

        int i, j;                       //i and j - used to iterate trough the list structure and name string respectively
        char ch;                        //ch - a helper for reading the name string character by character

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
        printf("\n  -- For a total of %d calories\n\n --\n", sum(list, nrOfelements));
}

void readExercises(int nrOfexercises, calorie exerciselist[], FILE *exfile){

        int i, j;                       //i and j - used to iterate trough the list structure and name string respectively
        char cha;                       //cha - a helper for reading the name string character by character

        for(i = 0; i < nrOfexercises; i++){
            j = 0;
            while((cha = fgetc(exfile)) != '\n'){
                exerciselist[i].name[j] = cha;
                j++;
            }
        }

        for(i = 0; i < nrOfexercises; i++){
            fscanf(exfile, "%d", &exerciselist[i].val);\
        }
}

void findSolution(calorie exerciselist[], int targetsum, int index, int nrofexercises, int currsum, int solution[], int *foundsol, FILE *resultfile){

        if((currsum + targetsum) == 0){                       //check if we've found a solution

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

                    printf(" -> %d cal\n", exerciselist[i].val);                //print the solution and save it in a file
                    fprintf(resultfile, " -> %d cal\n", exerciselist[i].val);
                    *foundsol = 1;              //confirm that we've found a solution
                }
            }

            printf("\n  -- The routine was saved on your computer in the file 'result.txt' --\n\n");
            exit(1);                            //exit the function since we've found the solution

        }
        else{
            if(index == nrofexercises){
                return;                         //return if we've reached the end of the list
            }
            else {
                solution[index] = 1;                            //otherwise continue adding or removing elements until we have
                currsum = currsum + exerciselist[index].val;    //every possible combination or we've reached a solution
                findSolution(exerciselist, targetsum, index + 1, nrofexercises, currsum, solution, foundsol, resultfile);
                currsum = currsum - exerciselist[index].val;
                solution[index] = 0;
                findSolution(exerciselist, targetsum, index + 1, nrofexercises, currsum, solution, foundsol, resultfile);
            }
        }

        return;
}
