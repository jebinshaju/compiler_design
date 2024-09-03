#include <stdio.h>
#include <string.h>

int k = 0, z = 0, i = 0, j = 0, c = 0;
char input[16], ac[20], stk[15], action[10];

void check();

int main() {
    printf("GRAMMAR is E->E+E \nE->E*E \nE->(E) \nE->id");
    printf("Enter input string: ");
    scanf("%s", input);
    
    c = strlen(input);
    strcpy(action, "SHIFT->");
    
    printf("stack \t input \t action");
    
    for (k = 0, i = 0, j = 0; j < c; k++, i++, j++) {
        if (input[j] == 'i' && input[j + 1] == 'd') {
            stk[i] = input[j];
            stk[i + 1] = input[j + 1];
            stk[i + 2] = '\0';
            input[j] = ' ';
            input[j + 1] = ' ';
            printf("\n$%s\t%s$\t%sid", stk, input, action);
            check();
        } else {
            stk[i] = input[j];
            stk[i + 1] = '\0';
            input[j] = ' ';
            printf("\n$%s\t%s$\t%ssymbol", stk, input, action);
            check();
        }
    }
    return 0;
}

void check() {
    strcpy(ac, "REDUCE TO E");
    
    for (z = 0; z < c; z++) {
        if (stk[z] == 'i' && stk[z + 1] == 'd') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stk, input, ac);
            j++;
        }
    }
    
    for (z = 0; z < c; z++) {
        if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, input, ac);
            i = i - 2;
        }
    }
    
    for (z = 0; z < c; z++) {
        if (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, input, ac);
            i = i - 2;
        }
    }
    
    for (z = 0; z < c; z++) {
        if (stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, input, ac);
            i = i - 2;
        }
    }
}
/*
*************************************************************************
OUTPUT
------
user@user:~/monkey$ gcc shrepa.c
user@user:~/monkey$ ./a.out
GRAMMAR is E->E+E 
E->E*E 
E->(E) 
E->idEnter input string: id+id*id
stack 	 input 	 action
$id	  +id*id$	SHIFT->id
$E	  +id*id$	REDUCE TO E
$E+	   id*id$	SHIFT->symbol
$E+id	     *id$	SHIFT->id
$E+E	     *id$	REDUCE TO E
$E	     *id$	REDUCE TO E
$E*	      id$	SHIFT->symbol
$E*id	        $	SHIFT->id
$E*E	        $	REDUCE TO E
$E	        $	REDUCE TO E
*/
