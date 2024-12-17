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

int cnt[100];

void solved() {
    /* your code */
    LL n; cin >> n;
    // 先统计出来，每一位 1 的个数
    for (int i = 1; i <= n; i ++) {
        LL num, j = 1;
        cin >> num;
        while(num) {
            cnt[j] += num % 2;
            num /= 2;
            j ++;
        }
    }

    LL sum = 0;
    for (int i = 1; i <= 30; i ++) {
        sum += cnt[i] * (n - cnt[i]) * (1 << (i - 1));
    }
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}