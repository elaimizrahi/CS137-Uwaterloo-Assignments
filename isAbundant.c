#include <stdio.h>

int main (void){
    int num;
    int div = 1;
    int count = 0;
    scanf("%d", &num);
    while (div <= num){
        if(num%div == 0){
            count = count + div;
        }
        div++;
        if(div > num/2){
            break;
        }
    }

    if(count < num){
     printf("Deficient\n");
    }    
    if(count == num){
     printf("Perfect\n");
    }    
    if(count > num){
     printf("Abundant\n");
    }

    return 0;
}