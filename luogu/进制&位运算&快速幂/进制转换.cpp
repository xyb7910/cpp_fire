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
    int p1, p2; 
    string s;
    cin >> p1 >> s >> p2;
    int n = s.size(), sum = 0, c = 0;
    for (int i = n - 1; ~i; i --) {
    	int t = 0;
    	if(s[i] >= 'A' && s[i] <= 'Z') t = s[i] - 'A' + 10;
    	else t = s[i] - '0';
    	sum += t * pow(p1, c);
    	c ++;
    }

    string ans;
    while(sum) {
    	int m = sum % p2;
    	if(m >= 10) ans += m - 10 + 'A';
    	else ans += m + '0';
    	sum /= p2;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i ++) cout << ans[i];
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}