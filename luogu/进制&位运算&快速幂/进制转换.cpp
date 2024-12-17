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


void solved() {
    /* your code */
    int n, r; cin >> n >> r;
    int res = n;
    string s;
    while(n) {
    	int tmp = abs(n % r);
    	if(tmp >= 10) s += tmp - 10 + 'A';
    	else s += tmp + '0';
    	cout << n << endl;
    	n /= r;
    }
    reverse(s.begin(), s.end());
    cout << res << "=" << s << "(base" << r << ")" << endl; 
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}