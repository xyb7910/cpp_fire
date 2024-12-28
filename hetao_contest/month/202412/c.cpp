/*
* @Author: Yanpb
* @Date:   2024-12-27 22:10:36
* @Last Modified by:   Yanpb
* @Last Modified time: 2024-12-28 08:50:39
*/
#include <iostream>

using namespace std;

const int N = 1e7 + 10;
int cnt;
int primes[N];
bool st[N];

void get_primes(int n) {
	for (int i = 2; i <= n; i ++) {
		if(!st[i]) primes[cnt ++] = i;
		for (int j = 0; primes[j] * i <= n; j ++) {
			st[primes[j] * i] = 1;
			if(i % primes[j] == 0) break;
		}
	}
}

int main() {
	int m, n; cin >> m >> n;
	get_primes(N);
	for (int i = m; i <= n; i ++) {
		if(!st[i]) {
			bool f = 1;
			int num = i;
			while(num) {
				if(st[num] || num < 2)  {
					f = 0;
					break;
				}
				num /= 10;
			}
			if(f) cout << i << endl;
		}
	}
	return 0;
}