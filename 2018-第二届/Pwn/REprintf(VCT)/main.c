#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char**argv){
	printf("Really easy printf\n");
	char buf[64];
	memset(buf, 0, sizeof(buf));

	char flag[32];
	FILE *fp = fopen("flag.txt", "r");
	fgets(flag, 32, fp);

	fgets(buf, 64, stdin);
	printf(buf);
}



