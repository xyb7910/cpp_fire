/*
* @Author: Yanpb
* @Date:   2025-05-04 14:06:54
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-05-04 14:34:51
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
typedef priority_queue<int,vector<int>,greater<int>> PIG;
typedef priority_queue<int> PIL; 
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void solved() {
	/* your code */
	int a, b, c; cin >> a >> b >> c;
	int d = gcd(a, b);
	cout << gcd(c, d);
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}