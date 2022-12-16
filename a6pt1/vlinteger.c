#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "vlinteger.h"

struct linteger *vlintegerCreate(void) {
    struct linteger *t1 = malloc(sizeof(struct linteger));
    t1->arr = NULL;
    t1->length = 0; // no values in t1.
    return t1;
    }
    

void vlintegerDestroy(struct linteger *v){
    if(v->arr){
        free(v->arr);
        free(v);
    }
};

int power(int bs, int n){
    int total = 1;
    for (int i = 0; i < n; i++){
        total = total * bs;
    }
    return total;
}
// reads digits of a very long integer and stores them in t1.

void vlintegerRead(struct linteger *t1){
    int a;
    int count = 0;
    while(scanf("%d", &a)){
        (*t1).arr = realloc((*t1).arr, (count+1) * sizeof(int));
        (*t1).arr[count] = a;
        count++;
    }
    (*t1).arr = realloc((*t1).arr, (count) * sizeof(int));
    (*t1).length = count;
};


//prints the length then prints the digits with no spaces in between ended by \n.
//check the exact format and the additional text printed in the sample executions
void vlintegerPrint(struct linteger *t1){
    printf("length=%d\n", (*t1).length);
    for(int i = 0; i < (*t1).length; i++){
        printf("%d", (*t1).arr[i]);
    }
    printf("\n");
};




// returns the addition of t1 and t2. No leading zeros to the left should be kept in the array.
struct linteger * vlintegerAdd(struct linteger *t1, struct linteger *t2){

    int newlength = (*t1).length;
    int sum = 0;
    int remainder = 0;
    int newsum;
    int lowlength;
    struct linteger *add = vlintegerCreate();



    if((*t1).length > (*t2).length){
        newlength = (*t1).length;
        lowlength = (*t2).length;
        (*t2).arr = realloc((*t2).arr, (newlength) * sizeof(int));
        (*t2).length = newlength;
        for(int i = 0; i <(newlength-lowlength); i++){
            for(int j = newlength-1; j >= 0; j--){
                if(j == 0){
                    (*t2).arr[j] = 0;
                }
                if(j != 0){
                    (*t2).arr[j] = (*t2).arr[j-1];
                }
            }
        }        for(int i = 0; i < (newlength-lowlength); i++){
            (*t2).arr[i] = 0;
        }

    }
   if ((*t1).length < (*t2).length){
        newlength = (*t2).length;
        lowlength = (*t1).length;
        (*t1).arr = realloc((*t1).arr, (newlength) * sizeof(int));
        (*t1).length = newlength;

        for(int i = 0; i <(newlength-lowlength); i++){
            for(int j = newlength-1; j >= 0; j--){
                if(j == 0){
                    (*t1).arr[j] = 0;
                }
                if(j != 0){
                    (*t1).arr[j] = (*t1).arr[j-1];
                }
            }
        }
        for(int i = 0; i < (newlength-lowlength); i++){
            (*t1).arr[i] = 0;
        }
    }    

    (*add).length = newlength;
    (*add).arr = realloc((*add).arr, (newlength)*sizeof(int));

    for(int i = newlength-1; i >= 0; i--){
        newsum = (*t1).arr[i] + (*t2).arr[i] + remainder;
        remainder = 0;
        if(newsum > 9){
            remainder = newsum/10;
            newsum = newsum%10;
        }
        (*add).arr[i] = newsum;
    }

    if(remainder > 0){
        (*add).arr = realloc((*add).arr, (newlength+1)*sizeof(int));
        (*add).length = newlength+1;
        for(int i = newlength; i > 0; i--){
            (*add).arr[i] = (*add).arr[i-1];
        }
        (*add).arr[0] = remainder;
    }

        (*t1).arr = realloc((*t1).arr, (newlength) * sizeof(int));
        (*t2).arr = realloc((*t2).arr, (newlength) * sizeof(int));

    return add;

};


struct linteger * vlintegerMult(struct linteger *t1, struct linteger *t2){
    int sum;
    int index1;
    int index2;
    int length = (*t1).length+(*t2).length;
    struct linteger *mult = vlintegerCreate();
    (*mult).arr = calloc(length, sizeof(int));
    (*mult).length = length;
    index1 = 1;    

    for(int i = (*t2).length-1; i >= 0; i--){
        index2 = length - index1;
        for(int j = (*t1).length-1; j >= 0; j--){
            sum = (*t2).arr[i]*(*t1).arr[j] + (*mult).arr[index2];
            (*mult).arr[index2] = sum%10;
            (*mult).arr[index2-1] += sum/10;
            index2--;

        }
        index1++;


    }
    while((*mult).arr[0] == 0){
        for(int i = 1; i < (*mult).length; i++){
            (*mult).arr[i-1] = (*mult).arr[i];
        }
        (*mult).length = (*mult).length - 1;
        (*mult).arr = realloc((*mult).arr, (*mult).length*sizeof(int));
    }

    return mult;



}


/*

int main(void){
    struct linteger *int1 = vlintegerCreate();
 printf("Enter the digits separated by a space: \n");
 vlintegerRead(int1); 
 vlintegerPrint(int1);
 assert(int1->arr[0] !=0);

 
 char c;
 scanf("%c", &c);
 struct linteger *int2 = vlintegerCreate();
 printf("Enter the digits separated by a space: \n");
 vlintegerRead(int2);
 vlintegerPrint(int2);
 assert(int2->arr[0] !=0);
 scanf("%c", &c);
 struct linteger *add = vlintegerAdd(int1, int2);
 printf("addition\n");
 vlintegerPrint(add);
 assert(add->arr[0] !=0);
 scanf("%c", &c);
struct linteger *mult = vlintegerMult(int1, int2);
 printf("multiplication\n");
 vlintegerPrint(mult);
 assert(mult->arr[0] !=0);
 vlintegerDestroy(int1);
 vlintegerDestroy(int2);
 vlintegerDestroy(add);
vlintegerDestroy(mult);
 
}
*/