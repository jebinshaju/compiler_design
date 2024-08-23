#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int current = 0,error = 0;
int str[20];

void parseexpression();
void parseexpressionprime();
void parseterm();
void parsef();

void parseexpression(){
	
	parseterm();
	parseexpressionprime();
}

void parseexpressionprime(){
	
	if (str[current] == "+"){
		
		current++;
		parseterm();
		parseexpressionprime();
	
	}
}

void parseterm(){
	
	parsef();
	parsetermprime();
}

void parsetermprime(){

	if(str[current] == "*"){
	
		current ++;
		parsef();
		parsetermprime();
		if(str[current] != "*"){
	
			return ;
		}
	}
}

void parsef(){
	
	if (str[current] == "("){
		
		current ++;
		parseexpression();
		if(str[current] == ')'){
		
			current ++;
		}
		else{
			error = 1;
		}
		
	}
	else if (isalnum(str[current])){
	
		current++;
	}
	else{
		
		error = 1;
	}
}

int main(){
	
	printf("Enter the string: ");
	scanf("%s",str);
	if (current == strlen(str) && error ==0){
	
		printf("Parsed succesfully\n");
	}
	else{
		printf("unsuccesfull");
	}
}




























