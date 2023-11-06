//Lec2
//1. Factorial (동일)
//Recursion, T(n) = T(n-1) + 1, O(n)
int factorial(int n) {
	if (n <= 1) return(1);
	else return (n * factorial(n - 1));
}

//Iteration, T(n) = O(n)
int factorial_iter(int n) {
	int k, v = 1;
	for (k = n; k > 0; k--)
		v = v * k;
	return(v);
}


//2. Power Computation (재귀가 나음)
//Iteration , T(n) = O(n)
double slow_power(double x, int n) {
	int i;
	double r = 1.0;
	for (i = 0; i < n; i++)
		r = r * x;
	return(r);
}

//Recursion , T(n) = T(n/2) + c, T(n) = log2n
double power(double x, int n) {
	if (n == 0) return 1;
	else if ((n % 2) == 0)
		return power(x * x, n / 2);
	else return x * power(x * x, (n - 1) / 2);
}

//3. Fibonacci Series (반복이 나음)
//Recursion, T(n) = T(n-1) + T(n-2) + 1, T(n) = O(2^n)
int fib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fib(n - 1) + fib(n - 2));
}

//Iteration, T(n) = O(n)
fib_iter(int n) {
	if (n < 2) return n;
	else {
		int i, tmp, current = 1, last = 0;
		for (i = 2; i <= n; i++) {
			tmp = current;
			current += last;
			last = tmp;
		}
		return current;
	}
}

//4. Hanoi Tower (재귀가 오백배나음)
//T(n) = 2T(n-1) + 1, T(n) = 2^n - 1 = O(2^n)
void hanoi_tower(int n, char from, char tmp, char to) {
	if (n == 1)
		printf("Move 1 disc from %c to %c.\n", from, to);
	else {
		hanoi_tower(n - 1, from, to, tmp);
		printf("Move disc %d from %c to %c.\n", from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}

//5. Binary Search
//Iteration, T(n) = O(n)
int search_iter(A, b) {
	for (i = 1 to n) {
		if (A[i] == b)
			k = i;
	}
	return k;
}

//Recursion, T(n) = T(n/2) + c, T(n) = O(log2n)
int search_recur(A, b, start, end) {
	if (start > end) return -1;
	int median = (start + end) / 2;
	if (A[median] < b)
		search_recur(A, b, median, end);
	else if (A[median] > b)
		search_recur(A, b, start, median);
	else
		return median;
}

