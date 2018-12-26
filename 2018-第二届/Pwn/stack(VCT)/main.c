#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char flag[] = { 110, 99, 100, 114, 115, 101, 114, 96, 93, 76, 83, 75, 22, 66, 71, 23, 71, 22, 121, 66, 71, 23, 66, 71, 23, 81, 22, 91 };

void magic(){
	//注意！这里可能会被ROP调用system("/bin/sh");
	//配好服务器权限啊......
	system("cat ./flag");
}


void welcome(){
	puts("Tell me your name:");
	char name[12];
	//比较单纯的gets......覆盖返回地址为magic就行了......
	gets(name);
	printf("welcome %s\n", name);
}

int main(int argc, char**argv){
	welcome();
	srand((unsigned)time(NULL));
	int magic = rand() % 1234567 + 1;
	printf("now I have made a number from 1 to 1234567\n");
	printf("you can guess it three times,I will tell you something\n");
	int guess_number;
	for (int i = 0; i < 3; i++){
		printf("guess it:");
		scanf("%d", &guess_number);
		if (guess_number < magic){
			printf("Your number is too small\n");
		}
		else if (guess_number > magic){
			printf("Your number is too big\n");
		}
		else if (guess_number == magic){
			printf("Well done,here is your flag:\n");
			for (int k = 0; k < strlen(flag); k++){
				if (k & 0x80000001 == 0){
					// 32位，k & 0x80000001 == k % 2
					flag[k] ^= 0xab;

					flag[k] ^= 0xef;
					flag[k] ^= 0x28;
					flag[k] ^= 0x74;
					flag[k] ^= 0x7f;
					flag[k] ^= 0xe8;
					flag[k] ^= 0x24;
					//上面这6个异或相当于什么都没做
					flag[k] ^= 0xcd;
				}
				else{
					flag[k] ^= 0x34;

					flag[k] ^= 0x8a;
					flag[k] ^= 0x97;
					flag[k] ^= 0xfb;
					flag[k] ^= 0xc5;
					flag[k] ^= 0x95;
					flag[k] ^= 0x8b;
					flag[k] ^= 0xc7;
					flag[k] ^= 0xfa;
					//上面这8个异或相当于什么都没做
					flag[k] ^= 0x12;
				}
			}
			for (int k = 0; k < strlen(flag); k++){
				//如果3次就猜中了这个数字，就得到了假flag
				printf("%c", flag[k]);
			}
			printf("\nGoodbye~\n");
		}
	}
}

