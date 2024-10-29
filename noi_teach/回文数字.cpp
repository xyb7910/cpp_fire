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
    string s;
    cin >> s;
    int l = s.length() - 1;

    // 特判：如果全为9，则输出"100...0"形式的下一个回文数
    int i = 0;
    while (s[i] == '9') {
        if (i == l) {
            s = "1";
            for (int j = 1; j <= l + 1; ++j) {
                s += "0";
            }
            break;
        }
        ++i;
    }

    // 创建回文数
    string k = s;
    reverse(k.begin(), k.end());

    // 如果生成的回文数小于等于原数，则需要将中间的字符加1
    if (k <= s) {
        i = l / 2;  // 中间位置
        while (k[i] == '9') {
            --i;  // 处理进位
        }
        k[i] = char(int(k[i]) + 1);  // 加1
        ++i;
        while (i <= l / 2) {  // 将后面的字符设置为0
            k[i] = '0';
            k[l - i] = '0';
            ++i;
        }
    }

    cout << k << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}