/*
* @Author: Yanpb
* @Date:   2024-12-29 16:26:33
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-02 13:48:29
*/
//  P1217 回文数字 + 质数判断

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define x first
#define y second

using namespace std;
typedef long long i64;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e8 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int palis[N];
int cnt;

void get_pali(int m, int n) {
	for (int i = m; i <= n; i += 2) {
		int num = i, res = 0;
		while(num) {
			int k = num % 10;
			res = res * 10 + k; 
			num /= 10;
		}
		if(res == i) palis[cnt ++] = i;  
	}
}

int cnt1;
int primes[N];
bool st[N];

void get_primes(int n) {
	for (int i = 2; i <= n; i ++) {
		if(!st[i]) primes[cnt1 ++] = i;
		for (int j = 0; primes[j] * i <= n; j ++) {
			st[primes[j] * i] = 1; // 1 表示合数
			if(i % primes[j] == 0) break;
		}
	}
}


void solved() {
	/* your code */
	int a, b; cin >> a >> b;
	get_pali(a, b);
	get_primes(b);
	for (int i = 0; i < cnt; i ++) {
		int num = palis[i];
		if(!st[num]) cout << num << endl;
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}