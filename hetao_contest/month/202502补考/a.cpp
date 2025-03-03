/*
* @Author: Yanpb
* @Date:   2025-03-03 16:40:16
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-03 16:46:41
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
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int cnt = 0;

void solved() {
	/* your code */
	int k; cin >> k;
	for (int i = 10000; i <= 30000; i ++) {
		int num1 = i / 100;
		int num2 = i / 10 % 1000;
		int num3 = i % 1000;
		if(num1 % k == 0 && num2 % k == 0 && num3 % k == 0)  {
			cout << i << endl;
			cnt ++;
		}
	}
	if(!cnt) puts("No");
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}