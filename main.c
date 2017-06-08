#include "functions.h"


int main()
{
        calorie list[101];
        int test, nrOfelements, i, j;
        char ch;
        FILE *file;
        printf("Select your preferred snack pack:\n\n1.Pack#1\n2.Pack#2\n3.Pack#3\n4.Pack#4\n5.Pack#5\n\n# ");
        scanf("%d", &test);

        switch(test) {
            case 1:
                file = fopen("test1.in", "r");
                break;
            case 2:
                file = fopen("test2.txt", "r");
                break;
            case 3:
                file = fopen("test3.txt", "r");
                break;
            case 4:
                file = fopen("test4.txt", "r");
                break;
            case 5:
                file = fopen("test5.txt", "r");
                break;
        }

        fscanf(file, "%d", &nrOfelements);

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
        return 0;
}
