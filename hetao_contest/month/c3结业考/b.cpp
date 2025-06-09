/*
* @Author: Yanpb
* @Date:   2025-05-09 13:04:42
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-05-09 15:43:49
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


int t;
void solved() {
	/* your code */
	cin >> t;
	while(t --) {
		i64 n; cin >> n;
		if(n > 1)
			cout << i64(n * (n - 1)) << endl;
		else 
			cout << 1 << endl;
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}