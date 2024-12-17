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

string s;

void solved() {
    /* your code */
    int n, x; cin >> n >> x;
    while(n) {
    	int tmp = n % x;
    	if(tmp >= 10) s += tmp - 10 + 'A';
    	else s += tmp + '0';	
    	n /= x;
    }
    for (int i = s.length() - 1; i >=0; i --) cout << s[i];
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}