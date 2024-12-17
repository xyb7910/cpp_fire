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
    string s; cin >> s;
    // cout << s.size() << endl;
    while(s.size() % 3) s = '0' + s;
    for (int i = 0; i < s.size(); i ++) {
        if(i % 3 != 2) continue;
        for (int j = 2, num = 0; ~j; j --) {
            num += (s[i - j] - '0') ? (int)pow(2, j) : 0;
            if(!j) cout << num;
        }
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}