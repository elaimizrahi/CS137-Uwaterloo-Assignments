#include <stdio.h>

int gcd(a,b){
    if(a < 0){
        a = a*(-1);
    }
    if(b < 0){
        b = b*(-1);
    }
    if(a%b == 0){
        return b;
    }
    return(gcd(b, a%b));
}

int main(void){
    int a;
    int b;
    scanf("%d %d", &a, &b);
        printf("%d", gcd(a,b));
        
    
    return 0;
}