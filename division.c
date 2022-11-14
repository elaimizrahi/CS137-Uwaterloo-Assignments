#include<stdio.h>

int main (void){
    int num;
    int denom;

    scanf("%d", &num);
    scanf("%d", &denom);

    int quotient = num/denom;
    if(num < 0 && denom < 0){
        quotient++;
    }
    else if(num%denom < 0){
        quotient--;
    }
    else if(num%denom > 0){
        if(denom < 0){
            quotient -= 2;
        }
        quotient++;
    }

    printf("%d", quotient);
    return 0;
}
