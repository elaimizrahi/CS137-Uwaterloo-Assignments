#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
int jump_stair_v1 (int n){
    
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    return jump_stair_v1(n-1) + jump_stair_v1(n-2);
}

int jump_stair_v2(int n){
    if( n == 0){
        return 0;
    }
    if(n - 6 >= 0){
        return 2 + jump_stair_v2(n-6);
    }
    if(n - 3 >= 0){
        return 1 + jump_stair_v2(n-3);
    }
    if(n == 1){
        return 1;
    }
    else return 2;
    
}

int jump_stair_v3(int n){
    if (n %6 == 0 && n % 9 == 0 && n != 0){
        return (n/54)*(15);
    }
    if(n % 6==0 && n != 0){
        return 1 + jump_stair_v3(n-6);
    }
    if(n%9 == 0 && n != 0){
        return 1 + jump_stair_v3(n-9);
    }
    else return 0;
}
