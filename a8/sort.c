 #include <stdio.h>
 #include <stdbool.h>

 struct point
 {
 int x;
 int y;
 };

 void sort(void *arr, int n, size_t elemsize, bool (*compare)(const void *a, const void *b), void (*swap)(void *a, void *b)){

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){ 
            if(compare(((char*)(arr + j*elemsize)),(char*)(arr+i*elemsize))){
                swap(((char*)arr + j*elemsize),(char*)(arr+ i*elemsize));
            }
        }
    }

    for(int i = 0; i < n-1; i++){
        if(compare(((char*)(arr + (n-1)*elemsize)),(char*)(arr+ i*elemsize))){
            swap(((char*)(arr + (n-1)*elemsize)),(char*)(arr+ i*elemsize));
        }
    }
 };

 bool pointCompare1(struct point *p1, struct point *p2)
 {
 if (p1->x < p2->x) return true;
 else return false;
 }

 bool pointCompare2(struct point *p1, struct point *p2)
 {
 if (p1->x > p2->x) return true;
 else return false;
 }

 bool pointCompare3(struct point *p1, struct point *p2)
 {
 if (p1->x <= p2->x) return true;
 else return false;
 }

 bool pointCompare4(struct point *p1, struct point *p2)
 {
 if (p1->x >= p2->x) return true;
 else return false;
 }

 void pointSwap(struct point *p1, struct point *p2)
 {
 struct point temp = *p1;   
 *p1=*p2;
 *p2=temp;
 }

 int main (void)
 {
 struct point points[4] = {{10,5},{0,0},{-4,-5},{0,10}};
 sort(points,4, sizeof(struct point), pointCompare1, pointSwap);
 for (int i=0; i<4; i++)
 printf("%d %d\n", points[i].x, points[i].y);
 printf("\n\n");

 struct point points2[4] = {{10,5},{0,0},{-4,-5},{0,10}};
 sort(points2,4, sizeof(struct point), pointCompare2, pointSwap);
 for (int i=0; i<4; i++)
 printf("%d %d\n", points2[i].x, points2[i].y);
 printf("\n\n");

 struct point points3[4] = {{10,5},{0,0},{-4,-5},{0,10}};
 sort(points3,4, sizeof(struct point), pointCompare3, pointSwap);
 for (int i=0; i<4; i++)
 printf("%d %d\n", points3[i].x, points3[i].y);
 printf("\n\n");

 struct point points4[4] = {{10,5},{0,0},{-4,-5},{0,10}};
 sort(points4,4, sizeof(struct point), pointCompare4, pointSwap);
 for (int i=0; i<4; i++)
 printf("%d %d\n", points4[i].x, points4[i].y);
 printf("\n\n");

  struct point points5[5] = {{6,5},{-100,0},{4,-5},{5,10},{7,-100}};
 sort(points5,5, sizeof(struct point), pointCompare3, pointSwap);
 for (int i=0; i<5; i++)
 printf("%d %d\n", points5[i].x, points5[i].y);
 printf("\n\n");

  struct point points6[3] = {{0,10},{0,-5},{0,0}};
 sort(points6,3, sizeof(struct point), pointCompare4, pointSwap);
 for (int i=0; i<3; i++)
 printf("%d %d\n", points6[i].x, points6[i].y);
 printf("\n\n");

  struct point points7[1] = {{10,5}};
 sort(points7,1, sizeof(struct point), pointCompare1, pointSwap);
 for (int i=0; i<1; i++)
 printf("%d %d\n", points7[i].x, points7[i].y);
 printf("\n\n");

  struct point points8[10] = {{7,5}, {-10,5}, {90,5}, {10,5}, {10,8}, {10,0}, {-1,5}, {5,-15}, {0,5}, {8,5}};
 sort(points8,10, sizeof(struct point), pointCompare3, pointSwap);
 for (int i=0; i<10; i++)
 printf("%d %d\n", points8[i].x, points8[i].y);
 printf("\n\n");

 
 }