#include <stdio.h>

char name[50];

int main(){
        void vlun();
	setvbuf(stdout,0,2,0);
        printf("Wlcome to Hebei Normal University CTF\n");
	printf("Give me a good Story:\n");
	read(0,name,50);
        vlun();
	return 0;
}
void vlun()
{
     	char buf[20];
	printf("It can't touch me,try again please:\n");
	gets(buf);
        return 0;
    
}