/*
* @Author: Yanpb
* @Date:   2025-01-23 15:11:56
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-23 16:20:01
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10;

int primes[N];
bool st[N];
int cnt;

void get_primes(int n) {
	for (int i = 2; i <= n; i ++) {
		if(!st[i]) primes[cnt ++] = i;
		for (int j = 0; primes[j] <= n / i; j ++) {
			st[primes[j] * i] = 1;
			if(i % primes[j] == 0) break;
		}
	}
}

int change(int num) {
	int res = 0;
	while(num) {
		res = res * 10 + num % 10;
		num /= 10;
	}
	return res;
}

int main()
{
    get_primes(110);
	int a, b; cin >> a >> b;
// 	for (int i = 0; i < cnt; i ++) cout << primes[i] << " ";
	for (int i = a; i <= b; i++) {
		if(!st[i]) {
			int reverse_num = change(i);
			if(!st[reverse_num]) cout << i << endl;
		}
	}
	return 0;
}