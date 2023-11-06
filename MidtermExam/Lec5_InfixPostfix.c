void infix_to_postfix(char exp[]) {
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);
	StackType s;

	init(&s);// Stack initialization
	for (i = 0; i < len; i++) {
		ch = exp[i];

		switch (ch) {
		case '+': case '-': case '*': case '/': // Operator
			// If the operator priority on the stack is greater than or equal to current operator
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				printf("%c", pop(&s));
			push(&s, ch);
			break;

		case '('://Left parenthesis
			push(&s, ch);
			break;
		case ')'://Right parenthesis
			top_op = pop(&s);
			// Output until the left parenthesis is encountered

			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default:// Operand
			printf("%c", ch);
			break;
		}
	}
	while (!is_empty(&s))// Output operators stored on the stack
		printf("%c", pop(&s));
}

void main() {
		infix_to_postfix("(2+3)*4+9");
} 

int prec(char op) {
	switch (op) {
	case'(': case')': return 0;
	case'+': case '-': return 1;
	case'*': case'/': return 2;
	}
}