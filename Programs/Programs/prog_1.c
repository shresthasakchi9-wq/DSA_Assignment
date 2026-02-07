#include <stdio.h>
#include <string.h>

#define MAX 100

/* Stack declaration */
char stack[MAX];
int top = -1;

/* Push an element onto stack */
void push(char ch) {
    if (top < MAX - 1) {
        stack[++top] = ch;
    }
}

/* Pop an element from stack */
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

/* Check matching parentheses */
int isMatching(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

/* Check whether expression is balanced */
int checkBalanced(char exp[]) {
    int i;
    char temp;

    for (i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } 
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1)
                return 0;

            temp = pop();
            if (!isMatching(temp, exp[i]))
                return 0;
        }
    }

    return (top == -1);
}

int main() {
    char expression[100];

    printf("Enter the expression: ");
    gets(expression);

    if (checkBalanced(expression))
        printf("The expression has balanced parentheses.\n");
    else
        printf("The expression has unbalanced parentheses.\n");

    return 0;
}
