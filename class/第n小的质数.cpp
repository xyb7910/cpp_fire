#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e8 + 10;
typedef long long LL;
int n, cnt;
int primes[N];
bool st[N];

// 建议不要使用预处理

// 埃氏筛选质数
void get_primes(int n) {
    for (int i = 2; i <= n; i ++) {
        if(!st[i]) {
            primes[cnt ++] = i;
            for (int j = 2 * i; j <= n; j += i)
                st[j] = true;
        }
    }
}

// 判断素数
bool is_prime(int x) {
	if (x < 2) return false;
	for (int i = 2; i <= x / i; i ++)
		if(x % i == 0) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	std::cin >> n;
	get_primes(N);
	// int x = 1;
	// while(n != 0) {
	// 	x ++;
	// 	if(is_prime(x)) n --;
	// }
	// std::cout << x << std::endl;
	std::cout << primes[n - 1];
	return 0;
}