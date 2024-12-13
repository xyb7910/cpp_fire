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

LL BaseTransTen(string s, int to_p) {
	LL res = 0, c = 0;
	int n = s.size();
	for (int i = n - 1; ~i; i --) {
		int t = 0;
		if(s[i] >= 'A' && s[i] <= 'Z') t = 10 + s[i] - 'A';
		if(isdigit(s[i])) t = s[i] - '0';
		res += t * pow(to_p, c);
		cout << res << endl;
		c ++;
	}
	return res;
}

void solved() {
	/* your code */
	string num; cin >> num;
	int from_p, to_p; cin >> from_p >> to_p; 
	cout << BaseTransTen(num, to_p) << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}