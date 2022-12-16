#include <stdio.h>
#include "functions.h"
int isPrime(int p){
    int div = 2;
    while (div*div <= p){
        if(p%div == 0)break;
        div++;
    }
    if (div*div <= p){       
return 0;}
    else{        
    return 1;};
}

int power(int bs, int n){
    int total = 1;
    for (int i = 0; i < n; i++){
        total = total * bs;
    }
    return total;
}

int isSophieGermainPrime(int p){
    
    int q = (2 * p) + 1;

    if ((isPrime(p) == 1) && (isPrime(q) == 1)){
        return 1;
    }
    else{

        return 0;
    }

}

int base2nat(int bs, int num){
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
    return total;
}
int NewPower(int bs, int n){
    if(bs == 0){
        return 0;
    }
    int total = 1;
    for (int i = 0; i < n; i++){
        total = total * bs;
    }
    return total;
}

int nat2base(int bs, int num){
    int count = 0;
    int total = 0;


    

    for (int i = 9; i >= 0; i--){
    if(num >= NewPower(bs, i)){
        
        while(num >= NewPower(bs, i) && num != 0){
            num -= NewPower(bs,i);
            count++;
            
        }
        total += (count * NewPower(10, i));
        count = 0;
        }
        if(i == 0){
            break;
        }
        


    }
    return total;
}

