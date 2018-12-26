#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//此函数用于计算参数x的奇偶性，利用了XOR的性质
//二进制表示x，如果有奇数个1就返回1，偶数个1就返回0
//稍加难度，把这个函数“内联”了
/*
int calc(int x){
	int val = 0;
	while (x){
		val ^= x;
		x >>= 1;
	}
	return val & 0x1;
}
*/

char buf[81];

//此函数是为了确保输入的64个字符中没有相同的两个，秒解也太丢人了
void judge(char*s){
	for (int i = 0; i < 64; i++){
		for (int j = 1; j < 64 - i; j++){
			if (s[i] == s[i + j]){
				printf("You failed\n");
				exit(0);
			}
		}
	}
}

int main(int argc, char**argv){
	printf("You should input a string,which length is 80\n");
	printf("It can't contain the same character twice\n");
	scanf("%s", buf);
	if(strlen(buf)!=80) {
		printf("length must be 80!!!\n");
		exit(0);
	}
	buf[80]='\0';

	judge(buf);

	char magic[80] = { '\0', '\1', '\1', '\0', '\1', '\0', '\0', '\1', '\0', '\1', '\0', '\1', '\1', '\0', '\1', '\0', '\0', '\1', '\0', '\1', '\0', '\1', '\1', '\0', '\1', '\0', '\0', '\1', '\0', '\1', '\0', '\1', '\1', '\0', '\1', '\0', '\0', '\1', '\0', '\1', '\0', '\1', '\1', '\0', '\1', '\0', '\0', '\1', '\0', '\1', '\0', '\1', '\1', '\0', '\1', '\0', '\0', '\1', '\0', '\1', '\0', '\1', '\1', '\0', '\1', '\0', '\0', '\1', '\0', '\1', '\0', '\1', '\1', '\0', '\1', '\0', '\0', '\1', '\0', '\1' };
	for (int i = 0; i < 80; i++){
		int val = 0;
		char temp = buf[i];
		while (temp){
			val ^= temp;
			temp >>= 1;
		}
		//val & 0x1相当于calc函数的返回值
		//magic[0] == '\0'，表明必须calc(buf[0])=='\0'，也就是必须为“偶”
		if ((val & 0x1) != magic[i]){
			printf("You failed\n");
			exit(0);
		}
	}
	printf("You bypass them successfully\n");

	system("cat ./flag");

}