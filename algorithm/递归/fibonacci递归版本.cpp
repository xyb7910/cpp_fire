#include <iostream>

typedef long long LL;

LL Fibonacci(LL n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// 求 Fibonacci 数列的第 n 项
int main() {
	int n;
	std::cin >> n;
	std::cout << Fibonacci(n) << std::endl;
	return 0;
}