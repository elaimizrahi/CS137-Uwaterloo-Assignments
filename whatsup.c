#include <stdio.h>

int main(void){
    int div = 1;
    int count = 0;
    int p;
    scanf("%d", &p);
    while (div <= p){
        if (p % div == 0){
            count++;
            div++;
            printf("hi");
        }
        else{
            printf("hello");
            div++;
            continue;
        }
        printf("%d", count);
    }
    if(count != 2){
        return 1000;
    }
    div = 0;
    count = 0;
    while(div <= (2*(p)+1)){
        if(div % (2*(p)+1) == 0){
            count++;
            div++;
            printf("hii");
        }
        else{
            div++;
            continue;
        }
    }

    if(count == 2){
        printf("ew");
        return 1;
    }

    else{
                printf("we");

        return 0;
    }
            printf("weeee");


    return 5;
}


