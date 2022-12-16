#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
bool divide (int a, int b){
    if( b < 0){
        b = -b;
    }
    if(a < 0){
        a = -a;
    }
	if(b-a==0){
		return 1;
	}
	if(b-a < 0){
		return 0;
	}
    else{
        return divide(a, b-a);
    }
	}

int IntegerDivision(a,b){
    if(a-b < 0){
        return 0;
    }
    if(a-b == 0){
        return 1;
    }
    else{
        return 1 + IntegerDivision(a-b, b);
    }
}
