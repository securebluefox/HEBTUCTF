#include<stdio.h>
#include<stdlib.h>

int calc(int x){
	int val = 0;
	while (x){
		val ^= x;
		x >>= 1;
	}
	return val & 0x1;
}

int main(int argc, char**argv){
	char set[] = "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM!@#$%^&*()_+-={}[]<>,.?";
	char magic[80] = { '\0', '\1', '\1', '\0', '\1', '\0', '\0', '\1', '\0', '\1', '\0', '\1', '\1', '\0', '\1', '\0', '\0', '\1', '\0', '\1', '\0', '\1', '\1', '\0', '\1', '\0', '\0', '\1', '\0', '\1', '\0', '\1', '\1', '\0', '\1', '\0', '\0', '\1', '\0', '\1', '\0', '\1', '\1', '\0', '\1', '\0', '\0', '\1', '\0', '\1', '\0', '\1', '\1', '\0', '\1', '\0', '\0', '\1', '\0', '\1', '\0', '\1', '\1', '\0', '\1', '\0', '\0', '\1', '\0', '\1', '\0', '\1', '\1', '\0', '\1', '\0', '\0', '\1', '\0', '\1' };
	int calc_1 = 0, calc_0 = 0;
	char ji[50]; char ou[50];
	int ji_index = 0, ou_index = 0;
	for (int i = 0; i < strlen(set); i++){
		if (calc(set[i])){ calc_1++; ji[ji_index++] = set[i]; }
		else{ calc_0++; ou[ou_index++] = set[i]; }
	}
	ji[ji_index] = '\0';
	ou[ou_index] = '\0';

	printf("ji=%d\nou=%d\n", calc_1, calc_0);
	printf("ji_set = %s\n", ji);
	printf("ou_set = %s\n", ou);

	ji_index = 0, ou_index = 0;
	for (int i = 0; i < 80; i++){
		if (magic[i]){
			printf("%c", ji[ji_index++]);
		}
		else{
			printf("%c", ou[ou_index++]);
		}
	}

	//最后输出一串，3125469708qyuwperatsidgohfjklzxvbcnYUmPQAWESRDGTHIKOFZJVBLNXMC@!#$(%_^+&*-){}=<[

}