#include <stdio.h>
int main (void){
    int num_people;
    int slices_of_pizza;
    int slices_each;
    int total_pizzas;

    scanf("%d %d %d", &num_people, &slices_of_pizza, &slices_each);

    total_pizzas = (num_people * slices_each);

    if(total_pizzas%slices_of_pizza != 0){
        total_pizzas = total_pizzas/slices_of_pizza;
        total_pizzas++;
    }
    else{
        total_pizzas = total_pizzas/slices_of_pizza;
    }

    printf("%d\n", total_pizzas);

    return 0;
    
}