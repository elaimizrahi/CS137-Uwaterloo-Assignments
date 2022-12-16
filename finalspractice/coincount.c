#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
int least(int firstval, int amount, int *coinList, int len, int prev){
    int total = amount - firstval;
    int count = 1;
    int i = len-1;
    while(total > 0 || i >= 0){
        if(total -coinList[i] >= 0){
            total = total - coinList[i];
            printf("total: %d\n",total);
            count++;
        }
        else{
            i--;
        }
    }
    if(total < 0 || total > 0){
                        printf("prev: %d\n",prev);

        return prev;
    }
                printf("count: %d\n",count);

    return count;
}


unsigned int leastCoins(int amount, int *coinList, int len){

    int prev = amount;
    int cur = 0;
    for(int i =0; i < len; i++){
        if(coinList[i] < amount){
                        printf("%d\n",coinList[i]);
                            printf("amt: %d\n",amount);

            cur = least(coinList[i],amount, coinList, len, prev);
                            printf("cur: %d\n",cur);
                printf("prev1: %d\n", prev);

            if(cur < prev){
                prev = cur;
                printf("prev: %d\n", prev);
            }
        }
    }
    return prev;
}


int main() {
int coinList[3] = {1, 13, 24};
assert(leastCoins(26, coinList, 3) == 2);
int coinList1[3] = {1, 13, 24};
assert(leastCoins(53, coinList1, 3) == 5);
int coinList2[5] = {1, 13, 24, 27, 35};
assert(leastCoins(41, coinList2, 5) == 3);
int coinList3[2] = {1, 13};
assert(leastCoins(15, coinList3, 2) == 3);
}