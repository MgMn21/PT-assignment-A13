///@file functions.c
///@brief Source file containing definitions of all of the program's functions.

#include "functions.h"

///@fn int sum(calorie list[], int num)
///@brief This method will be used to compute the total sum of calories in the selected pack
///@param list[] The structure which holds the data
///@param num The total number of snacks in the pack
///@var s Used to store the sum
///@var i Used to iterate through the list
int sum(calorie list[], int num){

        int s = 0;                      /// s is used to store the sum
        for(int i = 0; i < num; i++){   /// i is used to iterate trough the list
            s = s + list[i].val;
        }
        return s;
}

///@fn void readPack(int nrOfelements, calorie list[], FILE *file)
///@brief This method will be used to read the contents of the selected pack from a file
///@param nrOfelements The number of elements/snacks in the pack
///@param list[] The structure which holds the data
///@param file FILE type object for file Input
///@var i Used to iterate through the list
///@var j Used to iterate through the name string
///@var ch Helper for reading the names character by character
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
        printf("\n  -- For a total of %d calories\n\n --\n", sum(list, nrOfelements));
}

///@fn void readExercises(int nrOfexercises, calorie exerciselist[], FILE *exfile)
///@brief This method will be used to read the contents of the selected exercise list from a file
///@param nrOfexercises   The number of elements/exercises in the list
///@param exerciselist[]  The structure which holds the data
///@param exfile          FILE type object for file Input
///@var i Used to iterate through the list
///@var j Used to iterate through the name string
///@var cha Helper for reading the names character by character
void readExercises(int nrOfexercises, calorie exerciselist[], FILE *exfile){

        int i, j;
        char cha;

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

///@fn void findSolution(calorie exerciselist[], int targetsum, int index, int nrofexercises, int currsum, int solution[], int lastsum, int *foundsol, FILE *resultfile)
///@brief This method will be used to compute the solution for out problem, if a solution exists
///@param exerciselist[] The structure which holds the data
///@param targetsum The target amount of calories we aim to burn
///@param index Variable used to search the data
///@param nrofexercises The number of exercises in the list
///@param currsum Variable used to store the sum at the current iteration
///@param solution[] Array used to store the indexes of the elements that led us to the solution
///@param lastsum Variable used to calculate weather the current sum is, or is closer, to the solution
///@param foundsol Variable used to check if we have reached a solution
///@param resultfile FILE type object for file Output
///@var i Used to iterate through the list
///@var j Used to iterate through the name string
void findSolution(calorie exerciselist[], int targetsum, int index, int nrofexercises, int currsum, int solution[], int lastsum, int *foundsol, FILE *resultfile){

        if((currsum + targetsum) <= lastsum){
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
            exit(1);

        }
        else{
            if(index == nrofexercises){
                return;
            }
            else {
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
