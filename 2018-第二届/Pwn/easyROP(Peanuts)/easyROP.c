#include <stdio.h>

int main(){
	char buf[20];
	puts("Do you know the ROP?\n");
	printf("Give me you ROP :\n");
	fflush(stdout);
	read(0,buf,100);
	