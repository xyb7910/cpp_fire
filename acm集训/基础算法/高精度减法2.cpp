#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

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

bool cmp(string &a, string &b) {
	if(a.size() != b.size()) return a.size() > b.size();
	else {
		for (int i = 0; i < a.size(); i ++) {
			if(a[i] != b[i]) 
				return a[i] > b[i];
		}
	}
	return true;
}

vector<int> sub(string &a, string &b) {
	vector<int> res;
	bool negative = false;
	if(!cmp(a, b)) {
		string tmp = a;
		a = b;
		b = tmp;
		negative = true;
	}
	cout << negative << endl;
	int t = 0, i = a.size() - 1, j = b.size() - 1;

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

	if(negative) res.push_back('-');
	reverse(res.begin(), res.end());
	return res;
}

void solved() {
    /* your code */
    string a, b; cin >> a >> b;
    vector<int> res = sub(a, b);
    for (auto a : res) cout << a;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}