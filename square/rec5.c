#include <stdio.h>
#include <assert.h>

typedef struct Point{
int x;
int y;
} point;

typedef struct Rectangle {
point bottomLeft; // represents the bottom left corner of the rectangle
int width;
int height;
} rectangle;

rectangle checkintersection(rectangle rect1, rectangle rect2, int width, int height){
    rectangle a = {{0,0},0,0};
    rectangle b = {{1,1},1,1};
    if((rect1.bottomLeft.x + rect1.width) < rect2.bottomLeft.x){
        return a;
    }    
    if(rect1.bottomLeft.x > (rect2.bottomLeft.x + rect2.width)){
        return a;
    }    
    if((rect1.bottomLeft.y + rect1.height) < rect2.bottomLeft.y){
        return a;
    }
    if(rect1.bottomLeft.y > (rect2.bottomLeft.y + rect2.height)){
        return a;
    }    
    if((rect1.bottomLeft.y + rect1.height) == rect2.bottomLeft.y){
        b.height = 0;
    }    
    if((rect1.bottomLeft.x + rect1.width) == rect2.bottomLeft.x){
        b.width = 0;
    }   
    if(rect1.bottomLeft.y == (rect2.bottomLeft.y + rect2.height)){
        b.height = 0;
    }    
    if(rect1.bottomLeft.x == (rect2.bottomLeft.y + rect2.width)){
        b.width = 0;
    }
    return b;
}


rectangle intersection(rectangle rects[], int n){
    rectangle newrect = rects[0];
    int xcoord = newrect.bottomLeft.x;
    int ycoord = newrect.bottomLeft.y;
    int width = newrect.width + newrect.bottomLeft.x;
    int height = newrect.height + newrect.bottomLeft.y;
    rectangle a = checkintersection(rects[0], rects[1], width, height);

    for(int i = 0; i < n-1; i++){
        rectangle a = checkintersection(rects[i], rects[i+1], width, height);
        if(a.bottomLeft.x == 0 && a.bottomLeft.y == 0 && a.width == 0 && a.height == 0){
            return a;
        }
        if(a.height == 0){
            height = 0;
        }
        if(a.width == 0){
            width = 0;
        }
        
    }

    for(int i = 1; i < n; i++){
        rectangle temprect = rects[i];
        if(temprect.bottomLeft.x > xcoord){
            xcoord = temprect.bottomLeft.x;
        }
        if(temprect.bottomLeft.y > ycoord){
            ycoord = temprect.bottomLeft.y;
        }
        if(width != 0){
        if (temprect.bottomLeft.x + temprect.width < width){
            width = temprect.bottomLeft.x + temprect.width;
        }
        }
        if(height != 0){
        if (temprect.bottomLeft.y + temprect.height < height){
            height = temprect.bottomLeft.y + temprect.height;
        }  
        }      
    }

    if(width != 0){
        width = width - xcoord;
    }
    if(height != 0){
        height = height - ycoord;
    }
    rectangle c = {{xcoord, ycoord}, width, height};
    return c;

}

/*
 int main(){

 rectangle result;
 rectangle r = {{2,6},3,4};
 rectangle s = {{0,7},7,1};
 rectangle t = {{3,5},1,6};
 rectangle u = {{5,6},3,4};

 rectangle a = {{0, 0}, 5, 2};
rectangle b = {{2, 0}, 3, 3};
rectangle c = {{0, 1}, 4, 2};
rectangle d = {{0, 3} ,5, 4};

rectangle rects10[4] = {a,b,c,d};
result = intersection(rects10, 4);


 // Test 1
 rectangle rects1[2] = {r, s};
 result = intersection(rects1, 2);
 assert(result.bottomLeft.x == 2);
 assert(result.bottomLeft.y == 7);
 assert(result.width == 3);
 assert(result.height == 1);

 // Test 2
 rectangle rects2[3] = {r, s, t};
 result = intersection(rects2, 3);
 assert(result.bottomLeft.x == 3);
 assert(result.bottomLeft.y == 7);
 assert(result.width == 1);
 assert(result.height == 1);

 // Test 3
 rectangle rects3[4] = {r, s, t, u};
 result = intersection(rects3, 4);
 assert(result.bottomLeft.x == 0);
 assert(result.bottomLeft.y == 0);
 assert(result.width == 0);
 assert(result.height == 0);

 return 0;
 }
 */
 
