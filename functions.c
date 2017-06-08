#include "functions.h"

int sum(calorie list[], int num) {
        int s = 0;
        for(int i = 0; i < num; i++){
            s = s + list[i].val;
        }
        return s;
}
