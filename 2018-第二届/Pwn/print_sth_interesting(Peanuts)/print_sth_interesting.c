#include <stdio.h>
int sth=0;
int main(){

	char buf[0x100];
	setvbuf(stdout,0,2,0);
	puts("Do you know how to use 'printf'?");
	printf("Give me something to printf:");
	read(0,buf,0x100);
	printf(buf);
	if(sth == 0xffff){
           system("/bin/sh");
        }
        else
        {
          puts("Maybe you don't how to use it.'");
        }
}