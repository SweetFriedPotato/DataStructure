#include <stdio.h>

void hanoi(int n) {
	char stick = 'A';
	for (int i = 1; i <= n; i++) {
		stick++;
		printf("Move disc %d from %c to %c\n", i, 'A', stick);
	 }
	char reg = stick;

	for (int i = n-1; i >= 1; i--) {
		stick--;
		printf("Move disc %d from %c to %c\n", i, stick, reg);
	}


}

int main() {
	int n = 0;
	printf("Enter the number of discs >>");
	scanf("%d", &n);
	hanoi(n);
	return 0;
}