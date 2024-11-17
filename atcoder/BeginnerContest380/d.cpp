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

string s;

char change(char ch) {
    return ch >= 'a' ? (ch - 32) : (ch + 32);
}

char printChar(LL x, bool is_reverse) {
    if(x <= s.size()) {
        if(is_reverse) return change(s[x - 1]);
        else return s[x - 1];
    }

    LL k = s.size();
    while(k * 2 < x) k *= 2;
    return printChar(x - k, !is_reverse);
}

void solved() {
    /* your code */
    cin >> s;
    int q;
    cin >> q;
    while(q --) {
        LL num;
        cin >> num;
        cout << printChar(num, false) << " ";
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}