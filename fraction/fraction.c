#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "fraction.h"

struct fraction fractionCreate(int numerator, int denominator){
    if(numerator < 0 && denominator < 0){
        numerator = -numerator;
        denominator = -denominator;
    }
    int a = numerator;
    int b = denominator;
    int remainder = 0;

    if( a < b){
        int temp = a;
        a = b;
        b = temp;
    }

    if(a < 0){
        a = -a;
    }
    if(b < 0){
        b = -b;
    }

    while ( b != 0){
        remainder = a % b ;
        a = b ;
        b = remainder;
    }     

    if(numerator < 0 && denominator > 0){
        numerator = -numerator;
        denominator = -denominator;
    }   
    if(numerator == 0){
        denominator = a;
    }
    struct fraction c = {numerator/a, denominator/a};
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