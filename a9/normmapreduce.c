#include <stdio.h>
#include <math.h>
#include <assert.h> 
/*
void map(void *src, size_t n, size_t src_bytes,
void *dest, size_t dest_bytes,
void (*f) (void *, void *)) {
if (n == 0)
return;
 f(src, dest);
 // f writes to dest itself:

 map(src + src_bytes, --n, src_bytes, dest + dest_bytes, dest_bytes, f);
 }

 void reduce(void *src, size_t n, size_t src_bytes,
 void *dest, void (*f) (void *, void *)) {
 if (n == 1) {
 f(src, dest);
 return;
 }
 reduce((char *)src + src_bytes, n - 1, src_bytes, dest, f);
 f(src, dest);
 }
*/
  typedef struct Vector {
    double x, y, z;
 } Vector;


 void EuclideanNorm(void *src, void *dest){
    Vector *vec = (Vector *)src;

    int result = vec->x * vec->x +vec->y * vec->y +vec->z * vec->z; 
    double norm = sqrt(result);
    *(double *)dest = norm;

 }


 void sum(void *src, void *dest){
    *(double *)dest = *(double *)src + *(double *)dest;
 }

/*
 int main(void) {
    Vector a[2] = { {1, 0, 1}, {2, 0, 3} };
 double b[2] = { 0 };
 double res = 0;
 map(a, 2, sizeof(Vector), b, sizeof(double), EuclideanNorm);
 reduce(b, 2, sizeof(double), &res, sum);
 assert(fabs(res - 5.019765)<= 0.000001);
 return 0;
 }
*/
 