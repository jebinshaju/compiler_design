#include<stdio.h>

char strr[40];
int current = 0,resultA, resultOUT;

int parseA(){

	if(strr[current] == 'a'){
		
		current++;
		if (strr[current] == 'b'){
		
			current++;
			return 1;
		}
		return 1;
	}
	return 0;
}

int parseOUT(){

	if (strr[current] == 'a'){
		
		current++;
		resultA = parseA();
		if(resultA == 1 && strr[current] == 'd'){
			
			return 1;
		}
		return 0;
	}
	return 0;
}



int main(){
	
	printf("Enter the string: ");
	scanf("%s",strr);
	resultOUT = parseOUT();
	if (resultOUT == 1 && strr[current] == '\n'){
		 printf("Parsed succesfully :)\n");
	}
	else{
		printf("Parsing unsuccesfull  :(\n");
	}
	
	
}


/**
grammer

S --> aAd
A --> a
A --> ab


user@user:~/monkey$ gcc recursive.c 

user@user:~/monkey$ ./a.out
Enter the string: aad
Parsed succesfully :)

user@user:~/monkey$ ./a.out
Enter the string: aaad
Parsing unsuccesfull  :(

user@user:~/monkey$ ./a.out
Enter the string: aabd
Parsed succesfully :)

**/


