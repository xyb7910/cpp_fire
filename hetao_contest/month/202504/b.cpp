/*
* @Author: Yanpb
* @Date:   2025-04-25 13:21:29
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-25 14:48:16
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

int n, q;
int cnt1[N], cnt2[N], cnt3[N];

void solved() {
	/* your code */
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) {
		int id; cin >> id;
		if(id == 1) cnt1[i] = 1;
		if(id == 2) cnt2[i] = 1;
		if(id == 3) cnt3[i] = 1;
	} 

	for (int i = 1; i <= n; i ++) {
		cnt1[i] += cnt1[i - 1];
		cnt2[i] += cnt2[i - 1];
		cnt3[i] += cnt3[i - 1];
		// cout << cnt1[i] << " " << cnt2[i] << " " << cnt3[i] << endl;
	}


	while(q --) {
		int l, r; cin >> l >> r;
		cout << cnt1[r] - cnt1[l - 1] << " "; 
		cout << cnt2[r] - cnt2[l - 1] << " ";
		cout << cnt3[r] - cnt3[l - 1] << " ";
		cout << endl;
	}

}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}