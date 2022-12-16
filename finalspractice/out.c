#include <stdio.h>
//#include <math.h>
#include <assert.h> 
#include <string.h> 
#include <stdlib.h> 

void remove_whitespace(char* s, int n, char c){
    char *p;
    int i;

    for(p = s; *p != c && *p != '\0'; p++);
    if(*p == '\0')
        printf("no");
    else
        for(int i = 0; *(p+i) != '\0'&& i < n; i++)
            printf("%c", *(p+i));


}


 int main(void){

    char s[] = "Welcome to the Jungle";                //printf("hi");

    remove_whitespace(s, 4, 'J');
    //assert(!strcmp(a, "hellowhatsup"));
 }