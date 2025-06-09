/*
* @Author: Yanpb
* @Date:   2025-05-04 14:07:09
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-05-04 14:38:42
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

bool check_5(int i) {
	while(i) {
		int r = i % 5;
		if(!r) return 0;
		i /= 5;
	}
	return 1;
}

bool check_7(int i) {
	while(i) {
		int r = i % 7;
		if(!r) return 0;
		i /= 7;
	}
	return 1;
}

bool check_9(int i) {
	while(i) {
		int r = i % 9;
		if(!r) return 0;
		i /= 9;
	}
	return 1;
}

void solved() {
	/* your code */
	int a, b; cin >> a >> b;
	int cnt = 0;
	for (int i = a; i <= b; i ++) {
		if(check_5(i) && check_7(i) && check_9(i)) cnt ++;
	}
	cout << cnt;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}