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
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

vector<int> mul(vector<int> A, int b) {
	vector<int> res;
	int t = 0;
	for (int i = 0; i < A.size() || t; i ++) {
		if(i < A.size()) t += A[i] * b;
		res.push_back(t % 10);
		t /= 10;
	}
	while(res.size() > 1 && res.back() == 0) res.pop_back();
	return res;
}

void solved() {
	/* your code */
	string a; 
	int b; 
	cin >> a >> b;
	vector<int> A;
	for (int i = a.size() - 1; ~i; i --) A.push_back(a[i] - '0');
	vector<int> ans = mul(A, b);
	reverse(ans.begin(), ans.end());
	for (auto a : ans) cout << a; 
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}
