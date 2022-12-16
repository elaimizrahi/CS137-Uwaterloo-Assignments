#include <stdio.h>

int power(int bs, int n){
    int total = 1;
    for (int i = 0; i < n; i++){
        total = total * bs;
    }
    return total;
}

int main(void){
    int bs;
    int num;
    int count = 0;
    int total = 0;
    int n = num;

    while (n != 0){
        n = n/10;
        count++;
    }

    int temp = num;

    for (int i = 0; i < count; i++){
        for(int j = 0; j < count; j++){        
            temp = num % 10;
            num = num / 10;
            total += (temp * power(bs, j));   
        }
    }
    return 0;
}