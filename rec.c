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
    int width = newrect.width;
    int height = newrect.height;
    rectangle a = checkintersection(rects[0], rects[1], width, height);

    for(int i = 0; i < n-1; i++){
        rectangle a = checkintersection(rects[i], rects[i+1], width, height);
        //printf("%d %d %d %d", a.bottomLeft.x, a.bottomLeft.y, a.width, a.height);
        if(a.bottomLeft.x == 0 && a.bottomLeft.y == 0 && a.width == 0 && a.height == 0){
            return a;
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
        if(temprect.width < width){
            width = temprect.width;
        }        
        if(temprect.height < height){
            height = temprect.height;
        }
    }

    if(a.width == 0){
        width = 0;
    }
    if(a.height == 0){
        height = 0;
    }



    //printf("%d %d %d %d", xcoord, ycoord, width, height);

    rectangle c = {{xcoord, ycoord}, width, height};
    return c;

}
