#include <stdio.h>
//#include <math.h>
#include <assert.h> 
#include <string.h> 
#include <stdlib.h> 

char* remove_whitespace(char* s){

    int len = strlen(s);
            printf("%s", s);

    for(int i = 0; i < len; i++){
        printf("%c", s[i]);
        if(s[i] == 32){
            printf("%d", i);
            for(int j = i; j < len; j++){
                s[j] = s[j+1];
                printf("%d\n", j);
            }
            //len--;
            printf("len%d\n", len);
        }
        
    }//
    printf("\n%s", s);
    return s;
}


 int main(void){

    char s[] = "hello whatsup";                //printf("hi");

    char* a = remove_whitespace(s);
    assert(!strcmp(a, "hellowhatsup"));
 }