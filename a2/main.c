#include <stdio.h>
#include <assert.h>
#include "functions.h"

int main(void){
    assert(isSophieGermainPrime(11));
    assert(isSophieGermainPrime(41));
    assert(base2nat(5,23114)==1659);
    assert(base2nat(7,1)==1);
    assert(base2nat(3,1211012)==1328);
    assert(base2nat(8,715)==461);
    assert(nat2base(5,1659)==23114);
    assert(nat2base(9,1331)==1738);
}