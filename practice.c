# include <stdio.h>

int isPrime(int p, int div, int count){
while (div <= p){
        if (p % div == 0){
            count++;
            div++;
        }
        else{
            div++;
            continue;
        }
    }
    if(count != 2){
        return 0;
    }
    div = 0;
    count = 0;
    while(div <= (2*(p)+1)){
        if((2*(p)+1)% div  == 0){
            count++;
            div++;
        }
        else{
            div++;
            continue;
        }
    }

    if(count == 2){
        printf("%d", 1);
        return 1;
    }

    else{

        return 0;
    }
    return 0;
}

int main(void){
    int p;
    int div = 1;
    int count = 0;
    scanf("%d", &p);
    printf("%d", isPrime(p, div, count));

    

}
