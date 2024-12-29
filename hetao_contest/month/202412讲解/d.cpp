/*
* @Author: Yanpb
* @Date:   2024-12-28 14:21:32
* @Last Modified by:   Yanpb
* @Last Modified time: 2024-12-28 14:30:21
*/
// 进制转换 + 回文
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
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

char get(int x) {
	if(x <= 9) return x + '0';
	return x - 10 + 'A';
}

string base(int n, int b) {
	string num;
	while(n) {
		num += get(n % b);
		n /= b;
	}
	reverse(num.begin(), num.end());
	return num;
}

bool check(string num) {
	for (int i = 0, j = num.size() - 1; i < j; i ++, j --)
		if(num[i] != num[j])
			return false;
	return true;
}

void solved() {
	/* your code */
	int b; cin >> b;
	for (int i = 1; i <= 300; i ++) {
		string num = base(i * i, b);
		if(check(num)) {
			cout << base(i, b) << " " << num << endl;
		}
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}