#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct linteger {
int length;
int *arr; // array of digits to represent a very long positive integer, most left digit is in index 0.
};

struct linteger *vlintegerCreate(void) {
    struct linteger *t1 = malloc(sizeof(struct linteger));
    t1->arr = NULL;
    t1->length = 0; // no values in t1.
    return t1;
    }

void vlintegerDestroy(struct linteger *v){

};
// reads digits of a very long integer and stores them in t1.
void vlintegerRead(struct linteger *t1){

};
//prints the length then prints the digits with no spaces in between ended by \n.
//check the exact format and the additional text printed in the sample executions
void vlintegerPrint(struct linteger *t1){

};
// returns the addition of t1 and t2. No leading zeros to the left should be kept in the array.
struct linteger * vlintegerAdd(struct linteger *t1, struct linteger *t2){

    return t1;

};
// returns the multiplication of t1 and t2. No leading zeros to the left should be kept in the array.
struct linteger * vlintegerMult(struct linteger *t1, struct linteger *t2){
    return t1;

};


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