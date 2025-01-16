#include<bits/stdc++.h>
using namespace std;
int t, n, m;
string s[105];
bool check(int x, int y) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if (i == 0 || i == 3 || j == 0 || j == 3) {
                if(s[i + x][j + y] == '1') return false;
            } else {
                if(s[i + x][j + y] == '0') return false;
            }
        }
    }
    return true;
}
int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;
        bool flag = 0;
        for(int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        for(int i = 1; i <= n - 3; i++) {
            for(int j = 0; j < m - 3; j++) {
                if (check(i, j)) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}