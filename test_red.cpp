#include <iostream>

#define ARRAYSIZE 10


int main(){
    int array[ARRAYSIZE] = {0, 1 , 2, 3, 4, 5, 6, 7, 8, 9};
    int sum;
    for(int i = 0; i < ARRAYSIZE; i++){
        sum += array[i];
    }

    for(int i = 0; i < ARRAYSIZE; i++){
        sum = sum + array[i];
    }
    for(int i = 0; i < ARRAYSIZE; i++){
        sum = sum + array[i+1];
    }
    int j = 0;
    for(int i = 0; i < ARRAYSIZE; i++){
        sum = sum + array[j];
    }

    for(int i = 0; i < ARRAYSIZE; i++){
        sum = sum / array[i];
    }

    for(int i = 0; i < ARRAYSIZE; i++){
        sum = sum + sum;
    }

    for(int i = 0; i < ARRAYSIZE; i++){
        sum = sum + array[i] + sum;
    }
    return 0;
}
