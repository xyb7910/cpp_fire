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

int sc1[N], sc2[N];

void solved() {
    /* your code */
    int a; cin >> a;
    for (int i = 0; i < a; i ++) {
        int s; cin >> s;
        sc1[s] ++;
    }

    int b; cin >> b;
    for (int i = 0; i < b; i ++) {
        int s; cin >> s;
        sc2[s] ++;
    }
    int res1 = 0, res2 = 0, cnt = 0, ans = 0;
    for (int i = 1; i <= 1440; i ++) {
        if(sc1[i]) ans ++;
        if(sc2[i]) ans ++;
    }
    for (int i = 1; i < 3000; i ++) {
        int back1 = res1, back2 = res2;
        if(back1 == back2 && (sc1[i] || sc2[i])) cnt ++;
        if(sc1[i]) {
            res1 ++;
        } 
        else if(sc2[i]) {
            res2 ++;
        }
    }
    cout << ans << endl;
    cout << -- cnt <<  endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}