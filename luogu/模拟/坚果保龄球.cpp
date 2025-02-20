#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;
const int N = 2010, M = 1e5 + 10;
/*
输入 所在的行数 && 所出现的时间
*/
int n;
PII pos[N];
set<string> res;

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> pos[i].x >> pos[i].y;
    sort(pos, pos + n);
    for (int i = 0; i < n; i ++) {
        char s1 = (pos[i].x - '0');
        char s2 = s1 + ((pos[i].y + 1 - '0') / 60 - '0');
        res.insert(s2);
    }
    cout << res.size();
    return 0;
}