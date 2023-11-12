#include<stdio.h>
int num = 10;

void callForGlobal() {
	printf("Global num from function : %d\n\n", num);
}

void callForLocal() {
	
	int num = 7;
	
	printf("Local num is : %d\n\n", num);
	num++;
	
}

void callForStatic() {
	
	static int num = 7;
	
	printf("Static num is : %d\n\n", num);
	num++;
	
}

int main() {
	
	register int regNum = 0;
	
	printf("Global num from main : %d\n\n", num);
	callForGlobal();
	
	callForLocal();
	callForLocal();
	
	callForStatic();
	num++;
	callForStatic();
	
	printf("Register num is %d now \n\n", num);
	
	while(regNum != 30000) {
		
		regNum++;
	}

	
	printf("Register num is %d now \n\n", num);

	
}
