#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkAll(size_t n, unsigned int* total, int *coinlist, int quantity, int amount){
    if(quantity == 0){
        return (*total)-amount;
    }

    for(int i = 0; i < n; i++){
        *total += coinlist[i];
        if(checkAll(n, total, coinlist, quantity-1, amount)){
            return true;
        }
        *total -= coinlist[i];
    }
    return false;

}

unsigned int leastCoins(int amount, size_t n, int *coinlist) {
    unsigned int total = 0;
    if(amount == 0){
        return 0;
    }

    for(int i = 0; i < amount; i++){
        if(checkAll(n, &total,coinlist, i, amount)){
            return i;
        }
        
    }

    return -1;
}


int main(){
    int coinList[] = {1, 13, 24};
    printf("%d\n", leastCoins(26, 3, coinList));
    return 0;
}
