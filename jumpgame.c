#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool canComplete (int i, int arr[], int length){

    for(int k = i; k < length; k++){
        if(arr[k] == 0){
            for (int j = k-1; j >= 0; j--){
                
                if(j==0 && arr[j] <= k-j){
                    return false;
                }
                if(arr[j] > k-j){
                    break;
                }
                if(arr[j] < k-j){
                    continue;
                }
                
            }
        }
    }

    return true;
}


int main (void){
int arr1[5] = {2, 3, 1, 2, 2};
int arr2[4] = {2, 1, 0, 2};
int arr3[10] = {1,1,1,2,0,1,2,3,1,1};

assert(canComplete(0, arr1, 5) == true);
assert(canComplete(0, arr2, 4) == false);
assert(canComplete(0, arr3, 10) == true);
arr3[8]=0;
arr3[9]=0;
assert(canComplete(0, arr3, 10) == true);
arr3[7]=1;
 assert(canComplete(0, arr3, 10) == false);

return 0;
}
