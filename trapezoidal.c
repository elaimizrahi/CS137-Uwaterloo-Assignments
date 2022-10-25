#include <stdio.h>
#include <math.h>
#include <assert.h>
#define PI acos(-1)

double f1 (double x){
    return x*x;
}

double f2(double x){
    return cos(x);
}

double f3(double x){
    return sqrt(x);
}

double helper(double (*f)(double), int n, double interval, double a){

    double sum = 0;

    for(int i = 0; i < n; i ++){
        sum += 0.5*(f(a) + f(a+interval))*interval;
        a += interval;
    }
    return sum;
}

double trapezoidal(double (*f)(double), double a, double b, double epsilon, int n){
    double interval = (b-a)/n;    
    double area1 = helper(f, n, interval, a);
    double area2 = helper(f,1,interval,a);

    while(fabs(area1-area2) > epsilon){        
        area2 = area1;
        area1 = 0;
        n = n*2;
        double interval = (b-a)/n;    
        area1 = helper(f, n, interval, a);
    }
    return area1;
}




int main(void){
    assert(fabs(trapezoidal(f1, 5, 10, 0.00001, 2) - 291.667) <= 0.001);
    assert( fabs(trapezoidal(f2, PI/2, 3, 0.00001, 5) - -0.858879) <= 0.000001);
    assert(fabs(trapezoidal(f3, 1, 4, 0.00001, 2) - 4.666) <= 0.001);
 return 0;
}