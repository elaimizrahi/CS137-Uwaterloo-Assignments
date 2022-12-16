#include <stdio.h>
#include <assert.h>
void stars (long int n){
    if(n == 0){
        return;
    }

    if(n%10 == (n/10)%10){         
        stars(n/10);         
        printf("*");        
        printf("%ld", n%10);
    }

    else{
        stars(n/10);
        printf("%ld", n%10);
    }
    }
