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

bool cmp(string &A, string &B) {
	if(A.size() != B.size()) return A.size() > B.size();
	// A.size() == B.size()
	for (int i = 0; i < A.size(); i ++) {
		if(A[i] != B[i]) 
			return A[i] > B[i];
	}
	return true;
}

vector<int> sub(string &a, string &b) {
	vector<int> res;
	int t = 0, i = a.size() - 1, j = b.size() - 1;
	// 111 22
	while(~i || ~j) {
		int n1 = ~i ? a[i --] - '0' : 0;
		int n2 = ~j ? b[j --] - '0' : 0;
		int diff = n1 - n2 - t;
		if(diff < 0) {
			diff += 10;
			t = 1;
		} else {
			t = 0;
		}
		res.push_back(diff);
	}
	while(res.size() > 1 && res.back() == 0) res.pop_back();
	reverse(res.begin(), res.end());
	return res;
}

void solved() {
	/* your code */
	string a, b; cin >> a >> b;

	vector<int> ans;
	// cout << cmp(a, b) << endl;
	// A B
	if(cmp(a, b)) {
		// A > B
		ans = sub(a, b);
	} else {
		cout << "-";
		ans = sub(b, a);
	}
	for (auto a : ans) cout << a;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}