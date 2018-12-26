;Ë®Ìâ¡£¡£¡£¡£¡£´ð°¸£º5778
#include<stdio.h>
int fibonacci(int n){
	if (n ==2){
		return 1;
		}
	if (n == 1){
		return 1;
		}
	return fibonacci(n-1)+ fibonacci(n - 2);

}
int main(){
	int x;
	scanf("%d",&x);
	
	if (x==fibonacci(20)-fibonacci(16))
		printf("Win");
	else
		printf("Wrong");
	return 0;
	
}
