#include <stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100


typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

int check_matchint(char* in) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);
	init(&s);

	for (i = 0; i < n; i++) {
		ch = in[i];
		switch (ch) {
		case '(': case '[': case '{':
			push(&s, ch);
			break;
		case ')': case ']': case '}':
			if (is_empty(&s)) return FALSE;
			else {
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}')) {
					return FALSE;
				}
				break;
			}
		}
	}
	if (!is_empty(&s)) return FALSE;
	return TRUE;
}

int main() {
	if (check_matchint("{A[(i+1)]=0;}") == TRUE)
		printf("success\n");
	else
		printf("fail\n");
}