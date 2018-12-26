#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char*argv[]){
	//Linux 64
	unsigned int multiply = 0;
	unsigned int x, y;
	printf("Only when what you input is satisfying can you ultimately succeed:)\n");
	scanf("%u%u", &x, &y);
	unsigned int max = (x + y) / 2 + abs(x - y) / 2;
	//绝对值形式的两者最大值，截断小数点后，不然输入0和1就......
	//但是我不也想让输入0......
	if (!x || !y){ printf("Too young\n"); exit(0); }

	multiply = x * y;
	//此处IDA显示x和y都是int，查了下资料据说是int和unsigned int在内存中布局一样
	//可能因此只有multiply显示unsigned int

	if (max == multiply){
		//比如输入某正数和1
		system("cat ./fakeflag");
	}
	else if (max > multiply){
		system("cat ./flag");
	}
	else{
		printf("Well...but where is the flag?\n");
	}
}