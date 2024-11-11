#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e9 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n, m;
set<int> hori, vert, diag, anti_diag;

void solved() {
    /* your code */
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        hori.insert(x);
        vert.insert(y);
        diag.insert(x - y); // x - y = d
        anti_diag.insert(x + y); // x + y = d
    }

    LL ans = (LL)(n - hori.size()) * (n - vert.size());

    // 加入主对角线之后，考虑会有多少个新增加的不能放棋子的位置
    for (auto d : diag) {
        set<int> cross_x; // 所有交点的x坐标（因为要去重）
        for (auto x : hori) {
            // 枚举每一条水平线，看看它是否和对角线 d 相交与否
            // d = x - y ==> y = x - d
            int y = x - d;
            if(1 <= y && y <= n) {
                cross_x.insert(x);
            }
        }

        for (auto y : vert) {
            // 枚举每一条垂直线，看看它和对角线 d 相交与否
            int x = d + y; // x = d + y
            if(1 <= x && x <= n) {
                cross_x.insert(x);
            }
        }

        int cross_num = cross_x.size();
        // 枚举每一条对角线的长度
        int d_len = n - abs(d); // n - |d|
        ans -= d_len - cross_num;
    }

    // 加入副对角线之后，考虑会有多少个新增的不能放棋子的位置
    for (auto e : anti_diag) {
        set<int> cross_x;
        for (auto x : hori) {
            // e = x + y ==> y = e - x;
            int y = e - x;
            if(1 <= y && y <= n) {
                cross_x.insert(x);
            }
        }   

        for (int y : vert) {
            // e = x + y ==> x = e - y;
            int x = e - y;
            if (1 <= x && x <= n) {
                cross_x.insert(x);
            }
        }

        for (auto d : diag) {
            // 枚举每一条对角线，检查两者是都相交，并记录交点的 x 坐标
            int x = (d + e) / 2;
            int y = (e - d) / 2;
            if ((d + e) % 2 == 0 && 1 <= x && x <= n && 1 <= y && y <= n) {
                cross_x.insert(x);
            } 
        }
        int cross_num = cross_x.size();
        // 副对角线的长度
        int e_len = n - abs(e - (n + 1));
        ans -= e_len - cross_num;
    }
    cout << ans << endl;
} 

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}