/*
* @Author: Yanpb
* @Date:   2025-01-04 17:56:37
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-17 10:26:59
*/
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


void solved() {
	/* your code */
    int k; cin >> k;
    string T, S; cin >> S >> T;
    // 完全一样
    if(T == S) {
        puts("Yes");
        return;
    }
    // 长度一样
    int n = S.size(), m = T.size();
    if(n == m) {
        int diff = 0;
        for (int i = 0; i < n; i ++) {
            if(T[i] != S[i]) diff += 1;
        }
        if(diff <= 1) puts("Yes");
        else puts("No");
        return ;
    }
    // T 比 S 长 1
    if(n == m - 1) {
        swap(S, T);
        swap(n, m);
    }

    if(n == m + 1) {
        int pre = 0;
        while(pre < m && S[pre] == T[pre]) ++ pre;
        int suf = 0;
        while(suf < m && S[n - suf - 1] == T[m - suf - 1]) ++ suf;
        if(suf + pre >= n - 1) {
            puts("Yes");
        } else {
            puts("No");
        }
        return ;
    }

    puts("No");

}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}