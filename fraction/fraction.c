#include <stdio.h>
#include <assert.h>
#include "fraction.h"

struct fraction fractionCreate(int numerator, int denominator){
    int temp1 = numerator;
    int temp2 = denominator;
    int ispositive = 1;
    int remainder;

    if(numerator > 0 && denominator < 0){
        ispositive = 0;
    }    
    if(numerator < 0 && denominator > 0){
        ispositive = 0;
    }
    if (denominator < 0){
        denominator = denominator*(-1);
    }
    if(numerator < 0){
        numerator = numerator*(-1);
    }    
    if(temp1 < 0){
        temp1 = temp1*(-1);
    }    
    if(temp2 < 0){
        temp2 = temp2*(-1);
    }

    if(numerator < denominator){
        int temp3 = numerator;
        numerator = denominator;
        denominator = temp3;
    }
    while (numerator != 0){
        remainder = numerator%denominator;
        numerator = denominator;
        denominator = remainder;
    }

    if(ispositive == 0){
        temp2 = temp2*(-1);
    }



    struct fraction c = {temp1/remainder, temp2/remainder};
    return c;
};

int get_numerator(struct fraction a){
    return a.numerator;
}

int get_denominator(struct fraction a){
    return a.denominator;
}

struct fraction fractionAdd(struct fraction a, struct fraction b){

    a.numerator = a.numerator*b.denominator;

    b.numerator = b.numerator*a.denominator;   
    a.denominator = a.denominator*b.denominator;

    struct fraction c;
    c = fractionCreate((a.numerator+b.numerator),a.denominator);
    return c;

}

struct fraction fractionSubtract(struct fraction a, struct fraction b){
    a.numerator = a.numerator*b.denominator;

    b.numerator = b.numerator*a.denominator;   
    a.denominator = a.denominator*b.denominator;

    struct fraction c;
    c = fractionCreate((a.numerator-b.numerator),a.denominator);
    return c;
}

struct fraction fractionMultiply(struct fraction a, struct fraction b){
    a.numerator = a.numerator*b.numerator;
    a.denominator = a.denominator*b.denominator;
    
    struct fraction c;
    c = fractionCreate(a.numerator, a.denominator);
    return c;
}

struct fraction fractionDivide(struct fraction a, struct fraction b){
    a.numerator = a.numerator*b.denominator;
    a.denominator = a.denominator*b.numerator;

    struct fraction c;
    c = fractionCreate(a.numerator, a.denominator);
    return c;

}