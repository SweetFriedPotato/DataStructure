//postfix 계산
#include <stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100


typedef int element;
typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
}StackType;

int eval(char exp[])
{
    int op1, op2, value, i = 0;
    int len = strlen(exp);
    char ch;
    StackType s;

    init(&s);
    for (i = 0; i < len; i++) {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            value = ch - '0';
            push(&s, value);            // Operand
        }
        else { //Operator
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch) {
            case '+': push(&s, op1 + op2); break;
            case '-': push(&s, op1 - op2); break;
            case '*': push(&s, op1 * op2); break;
            case '/': push(&s, op1 / op2); break;
            }
        }
    }
    return pop(&s);
}

void main() {
    int result;
    printf("Postfix expression : 8 2 / 3 – 3 2 * +\n");
    result = eval("82/3-32*+");
    printf("Result: %d\n", result);
}