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
char s[N], k[N];
void solved() {
    /* your code */
    cin >> s;
    int l = strlen(s) - 1;
    char k[l + 1];
    // 特判：如果全为9，则输出"100...0"形式的下一个回文数
    int i = 0;
    while (s[i ++] == '9') {
        if (i == l + 1) {
            for (s[0] = '1', l ++; i > 0; i --)
                s[i] = '0';
        }
    }

    // 创建回文数
    for (i = 0; i <= l - i; i ++)
        k[i] = k[l - i] = s[i];

    // 如果生成的回文数小于等于原数，则需要将中间的字符加1
    if (strcmp(k, s) <= 0) {
        while(k[-- i] == '9') {
            k[i] = k[l - i] = ++ k[i];
        }
        i ++;
        for (i; i <= l - i; i ++) {
            k[i] = k[l - i] = '0';
        }
    }

    cout << k << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}