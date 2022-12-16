#include <stdio.h>

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

int main(void){
    int bs = 5;
    int num = 1659;
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

    printf("%d", total);
    return 0;
}