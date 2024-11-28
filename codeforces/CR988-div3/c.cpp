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


void solved() {
    /* your code */
    int n; cin >> n;
    if(n < 5) {
        cout << "-1" << endl;
        return ;
    }
    // 首先输出所有的偶数
    for (int i = 2; i <= n; i += 2) 
        if(i != 4) cout << i << " ";
    // 输出 4 5
    cout << "4 5 ";
    // 输出所有的奇数

    for (int i = 1; i <= n; i += 2) 
        if(i != 5) cout << i << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t; cin >> t; while(t--) solved();
    return 0;
}