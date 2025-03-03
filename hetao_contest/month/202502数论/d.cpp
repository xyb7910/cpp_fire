/*
* @Author: Yanpb
* @Date:   2025-03-02 15:55:24
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-02 16:11:10
*/
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
const int N = 9999999;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int a, b;

bool is_primes(int x) {
	if(x < 2) return false;
	for (int i = 2; i <= x / i; i ++)
		if(x % i == 0)
			return false;
	return true;
}

void solved() {
	/* your code */
	cin >> a >> b;
	for (int i = a; i <= min(b, N); i ++) {
		string res = to_string(i), rev_res = res;
		reverse(res.begin(), res.end());
		if(res == rev_res && is_primes(i)) {
			cout << i << endl;
		}
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}