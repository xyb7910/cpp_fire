/*
* @Author: Yanpb
* @Date:   2025-02-20 12:54:25
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-21 13:11:36
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2e4 + 10, M = 30;
int n, f;
char s[N];
int cnt[M][M];
bool st[M][M];

void update(int l, int r, int v) {
    l = max(0, l), r = min(r, n - 1);
    for (int i = l; i + 2 <= r; i ++) {
        char a = s[i], b = s[i + 1], c = s[i + 2];
        if(a != b && c == b) {
            cnt[a][b] += v;
            if(cnt[a][b] >= f) st[a][b] = true;
        }
    }
}

int main() {
    cin >> n >> f >> s;
    for (int i = 0; i  < n; i ++) s[i] -= 'a';
    update(0, n - 1, 1);
    for (int i = 0; i < n; i ++) {
        // 想要改变这个字母，先让满足 abb 类型的这个字母减少 1
        char t = s[i];
        update(i - 2, i + 2, -1);
        for (int j = 0; j < 26; j ++) {
            if(j != t) {
                s[i] = j; // 尝试除了本身之外的所有字符
                update(i - 2, i + 2, 1);
                update(i - 2, i + 2, -1);
            }
        }
        // 还原现场
        s[i] = t;
        update(i - 2, i + 2, 1);
    }
    int res = 0;
    for (int i = 0; i < 26; i ++)
        for (int j = 0; j < 26; j ++)
            if(st[i][j])
                res ++;
                
    cout << res << endl;
    for (int i = 0; i < 26; i ++)
        for (int j = 0; j < 26; j ++)
            if(st[i][j]) {
                printf("%c%c%c\n", i + 'a', j + 'a', j + 'a');
            }
    return 0;
}	