/*
* @Author: Yanpb
* @Date:   2025-01-17 18:40:23
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-17 18:52:58
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

i64 x, sum;

void solved() {
	/* your code */
	cin >> x;
	for (int i = 1; i <= 9; i ++)
		for (int j = 1; j <= 9; j ++) {
			if(i * j != x) sum += i * j;
		}
	cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}