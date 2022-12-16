#include <stdio.h>

int firstshape(n){
    int i = 1;
    while (i <= n){
        for(int j = 1; j <= i; j++){
            printf("*");
        }
    i++;
    printf("\n");
    }
    return 0;
}

int biggestprime(n){
    int biggestprime = 1;
    for(int i = 2; i <= n; i++){
        int div = 2;
        int count = 0;
        while(div*div <= i){
            if(i%div == 0){
                count++;
            }
        div++;
        }
        if(count == 0){
            biggestprime = i;
        }
    }
    return biggestprime;
    }

int reversearray(int a[], int length){
    for(int i = 0; i <= length/2; i++){
        int temp = a[i];
        a[i] = a[length - i-1];
        a[length - i-1] = temp;
    }
    for(int i = 0; i < length; i++){
        printf("%d ", a[i]);
    }
    return 0;
}

int sums(int size, int b[size][size]){
    int totalsum = 0;
    for(int i = 0; i < size; i++){
        totalsum += b[0][i];
    }
    int rowsum = 0;
    for(int i = 0; i < size; i++){
        rowsum = 0;
        for (int j = 0; j < size; j++){
            rowsum += b[i][j];
        }
        if(rowsum != totalsum){
            return 0;  
    }
    }    
    int columnsum = 0;
    for(int i = 0; i < size; i++){
        columnsum = 0;
        for (int j = 0; j < size; j++){
            columnsum += b[j][i];
        }
        if(columnsum != totalsum){
            return 0;  
    }
    
}return 1;
    }


int main(void){
    int a[] = {123, 32, 4, 543, 3};
    int b[3][3] = {{4,9,2},{3,5,7},{8,1,6}};
    int c[3][3] = {{4,2,2},{3,32,7},{3,23,6}};
      

    reversearray(a, 6);
    printf("\n%d",sums(3,b));
    printf("\n%d",sums(3,c));
}