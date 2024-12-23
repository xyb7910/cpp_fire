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

vector<char> add(string &a, string &b, int base) {
	vector<char> res;
	// 123 78
	int t = 0, i = a.size() - 1, j = b.size() - 1;
	while(~i || ~j || t) {
		if(~i) {
			if(a[i] >= '0' && a[i] <= '9') t += a[i --] - '0';
			else if(a[i] >= 'A' && a[i] <= 'Z') t += a[i --] - 'A' + 10;	
		} 
		if(~j) {
			if(b[j] >= '0' && b[j] <= '9') t += b[j --] - '0';
			else if(b[j] >= 'A' && b[j] <= 'Z') t += b[j --] - 'A' + 10;
		} 
		int r = t % base;
		if(r >= 10 && r < base) {
			res.push_back(r - 10 + 'A');
		} else if(r >= 0 && r <= 9) {
			res.push_back(r + '0');
		}
		t /= base;
	}
	reverse(res.begin(), res.end());
	return res;
}


void solved() {
	/* your code */
	int base; cin >> base;
	string a, b; cin >> a >> b;
	vector<char> ans = add(a, b, base);
	for (auto a : ans ) cout << a;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}