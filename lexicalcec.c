#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{

	FILE *input;
	int j=0;
	int op_c =0;
	int sp_c = 0;
	int di_c = 0;
	int ke_c = 0;
	int id_c = 0;
	int i,flag;
	char ch,str[20];
	input = fopen("input.c","r");
	char keyword[30][30] = {"int","main","if","else","do","while","include","printf","void"};
	printf("Token \t\t Lexeme\n\n");

	while(!feof(input))
	{
		i=0;
		flag=0;
		ch=getc(input);


		if( ch=='+'|| ch== '-' || ch=='*' || ch=='/' || ch == '=')
		{
			printf(" Operator\t %7c\n",ch);
			
			op_c++;
		}
		
		else if( ch==';' || ch=='{' || ch=='}' || ch=='(' || ch==')' || ch=='?' || ch=='@' ||ch=='!' || ch=='%')

		{

			printf(" Special symbol\t %7c\n",ch);
			
			sp_c++;
		}

		else if(isdigit(ch))
		{
			printf(" Digit\t\t %7c\n",ch);
			
			di_c++;
		}

		else if(isalpha(ch))
		{

			while(isalnum(ch) && ch!=' ')
			{
				str[i]=ch;
				i++;
				ch=fgetc(input);
			}

			str[i]='\0';

			for(j=0;j<=30;j++)

			{
				if(strcmp(str,keyword[j])==0)
				{
					flag=1;
					break;
				}
			}

			if(flag==1)
			{
				printf(" Keyword\t %7s\n",str);
				
				ke_c++;
			}

			else
			{
				printf(" Identifier\t %7s\n",str);
				
				id_c++;
			}

		}

		else if(ch=='\n')

		{
			
		}
	}

	fclose(input);
	printf("\nKeyword Count : %d",ke_c);
	printf("\nOperator Count : %d",op_c);
	printf("\nSpecial symbol Count : %d",sp_c);
	printf("\nDigit Count : %d",di_c);
	printf("\nIdentifier Count : %d\n",id_c);

	return 0;

	}
	
	
/*
input 


#include <stdio.h>

void main()
{
    int a = 3;
    int b = 4;
    int c;
    c = a + b;
    printf("%d",c);
}





output

Token 		 Lexeme

 Keyword	 include
 Identifier	   stdio
 Identifier	       h
 Keyword	    void
 Keyword	    main
 Special symbol	       )
 Special symbol	       {
 Keyword	     int
 Identifier	       a
 Operator	       =
 Digit		       3
 Special symbol	       ;
 Keyword	     int
 Identifier	       b
 Operator	       =
 Digit		       4
 Special symbol	       ;
 Keyword	     int
 Identifier	       c
 Identifier	       c
 Operator	       =
 Identifier	       a
 Operator	       +
 Identifier	       b
 Keyword	  printf
 Special symbol	       %
 Identifier	       d
 Identifier	       c
 Special symbol	       ;
 Special symbol	       }

Keyword Count : 7
Operator Count : 4
Special symbol Count : 7
Digit Count : 2
Identifier Count : 10


*/
