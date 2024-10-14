#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 60;
int n, m;
char map[N][N];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool st[N][N];
int cnt;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < m; j ++ ) {
            cin >> map[i][j];
        }   
    }
    
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < m; j ++ ) {
            if(i == 0 || i == n - 1 || j == 0 || j == m - 1 || map[i][j] == '#') st[i][j] = true;
        }   
    }

    
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < m; j ++) {
            if(map[i][j] == '#') {
                for (int k = 0; k < 8; k ++ ) {
                    int a = i + dx[k], b = j + dy[k];
                    if(a == 0 || a == n - 1 || b == 0 || b == m - 1 || map[a][b] == '#') {
                        continue;
                    } else {
                        st[a][b] = true;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < m; j ++ ) {
            if(!st[i][j]) {
                cnt ++;
                // cout << i + 1 << " " << j + 1 << endl;
            }
        }   
    }
    cout << cnt << endl;
    return 0;
}