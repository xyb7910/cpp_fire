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

std::vector<int> add(vector<int> &a, vector<int> &b) {
	vector<int> c;
	// t 表示进位
	for(int i = 0; i < a.size() || i < b.size(); i ++) {
		if(i < a.size()) t += a[i];
		if(i < b.size()) t += b[i];
		c.push_back(t % 10);
		t /= 10;
	}
	if(t) c.push_back(1);
	return c;
}

void solved() {
    /* your code */
    string a, b; cin >> a >> b;
    std::vector<int> A, B;
    for (int i = a.size() - 1; ~ i; i ++) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; ~ i; i ++) B.push_back(b[i] - '0');
    	
    std::vector<int> ans = add(a, b);
	reverse(ans.begin(), ans.end());
	cout << ans <<endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}