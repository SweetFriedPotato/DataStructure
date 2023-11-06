void swap(int* px, int* py) {
	int tmp;
	tmp = *px;
	*px = *py;
	*py = tmp;
}

main() {
	int a = 1, b = 2;
	printf("before swap: a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("after swap: a = %d, b = %d\n", a, b);
}