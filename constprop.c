#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void input();
void output();
void change(int p, char *res);
void constant();

struct expr {
    char op[2];
    char op1[5];
    char op2[5];
    char res[5];
    int flag;
} arr[10];

int n;

int main() {
    input();
    constant();
    output();
    return 0;
}

void input() {
    int i;
    printf("\n\nEnter the maximum number of expressions: ");
    scanf("%d", &n);
    if (n > 10) {
        printf("The maximum number of expressions is 10.\n");
        n = 10;
    }
    printf("\nEnter the input (operation, operand1, operand2, result): \n");
    for (i = 0; i < n; i++) {
        scanf("%s %s %s %s", arr[i].op, arr[i].op1, arr[i].op2, arr[i].res);
        arr[i].flag = 0;
    }
}

void constant() {
    int i;
    int op1, op2, res;
    char op;
    char res1[5];

    for (i = 0; i < n; i++) {
        if (strcmp(arr[i].op, "=") == 0) {
            // Convert operands to integers
            op1=atoi(arr[i].op1);
		op2=atoi(arr[i].op2);
		op=arr[i].op[0];
		res=op1;
		sprintf(res1,"%d",res);
		arr[i].flag=1;
		change(i,res1);
        }
    }
}

void output() {
    int i;
    printf("\nOptimized code is:\n");
    for (i = 0; i < n; i++) {
        if (!arr[i].flag) {
            printf("%s %s %s %s\n", arr[i].op, arr[i].op1, arr[i].op2, arr[i].res);
        }
    }
}

void change(int p, char *res) {
    int i;
    for (i = p + 1; i < n; i++) {
        if (strcmp(arr[p].res, arr[i].op1) == 0) {
            strcpy(arr[i].op1, res);
        } else if (strcmp(arr[p].res, arr[i].op2) == 0) {
            strcpy(arr[i].op2, res);
        }
    }
}

