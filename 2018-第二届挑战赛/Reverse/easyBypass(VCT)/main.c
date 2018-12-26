#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char buf[32]; //= { '\5', 'A', 'A', 'A', '\2', 'A', 'A', 'A', 0x44, 'A', 'A', 'A', 0x70 };

void judge(char*buf){
	unsigned int num1 = buf[0];
	unsigned int num2 = buf[4];
	unsigned int cmp1 = (num1*num1 + num2*num2) * 29;
	unsigned int cmp2 = (num1 * 5 + num2 * 2)*(num1 * 5 + num2 * 2);
	
	if (cmp1 > cmp2) {
		printf("You failed\n"); exit(0);
	}
	if ((buf[8] ^ 0x12) != 0x56){
		printf("You failed\n"); exit(0);
	}
	if ((buf[12] ^ buf[8]) != 0x34) {
		printf("You failed\n"); exit(0);
	}
}

int main(int argc, char**argv){
	printf("Give you a hint\n");
	printf("Please tell me: the MAX value of { x + sqrt( 5 - x**4) }\n");
	printf("I think...You may guess MAX == 3 when x==1\n");
	printf("The answer is right\n\n");
	printf("******My solution:******\n");
	printf("Let y = sqrt( 5 - x**4)\n");
	printf("Then, x**4 + y **2 == 5\n");
	printf("You know...An>=Gn\n");
	printf("Well, 12 == (x**4 + 1 + 1 + 1) + (y**2 + 4) >= 4 * x + 4 * y\n");
	printf("The MAX(x+y) is 3 when x == 1\n\n");

	printf("In fact playing RE needs Maths\n");
	printf("Let's start...\n\n");

	unsigned int MAX = -1;
	unsigned int len = strlen(buf);
	if (len - MAX >= 0)
		printf("Input something,and I decide whether to tell you the flag\n");
	else { printf("Impossible\n"); exit(0); }

	fgets(buf, 32, stdin);
	judge(buf);

	printf("OK...Here is your flag\n");
	system("cat ./flag");
}