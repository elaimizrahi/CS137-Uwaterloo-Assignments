#include <stdio.h>
//#include <math.h>
#include <assert.h> 
#include <string.h> 
#include <stdlib.h> 
#include <stdbool.h> 

bool unique(int a[], int len){

int *b = malloc(len*sizeof(int));
for(int i = 0; i < len; i++){
    b[i] = 0;
}
for(int i = 0; i < len; i++){
    int c = a[i];
    for(int j =0; j < len; j++){
        if(b[j] == c){
            free(b);
            return false;
        }
    }
    b[i] = c;

}
free(b);
    return true;
}

 int main(void){

    int s[] = {1,3,2,10,5,6,19,13,23};
    assert(unique(s, 9));
 }