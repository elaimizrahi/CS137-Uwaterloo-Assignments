#include <stdio.h>
#include <stdbool.h>
bool divide (int a, int b){
	if(b < 0) b = -b;
	if(a < 0) a = -a;
	if(b-a==0){
		return 0;
	}
	if(b-a < 0){
		return 1;
	}
		return divide(b-a, b);
	}

int main()
{
	int a,b;
	scanf("%d %d", &a, &b);
	int c = divide(a,b);
	if (c){
		printf("hi");
	}
	else{
		print("bye");
	}
}	
