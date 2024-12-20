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

char map[10][100];

void solved() {
    /* your code */
    string s; cin >> s;
    int n = s.size();
    int len = n * 4 + 1;
    for (int i = 0; i < 5; i ++)
        for (int j = 0; j < len; j ++)
            map[i][j] = '.';

    for (int i = 0; i < n; i ++) {
        int dx = 2, dy = 2 + (i * 4);  
        map[dx][dy] = s[i];
        map[0][dy] = map[4][dy] = '#';  
        map[2][dy - 2] = map[2][dy + 2] = '#';
        map[1][dy - 1] = map[1][dy + 1] = map[3][dy + 1]  = map[3][dy - 1] = '#';
    } 

    for (int i = 0; i < n; i ++) {
        int dx = 2, dy = 2 + (i * 4);
        if(i % 3 == 2) {
            map[0][dy] = map[4][dy] = '*';
            map[2][dy - 2] = map[2][dy + 2] = '*';
            map[1][dy - 1] = map[1][dy + 1] = map[3][dy + 1]  = map[3][dy - 1] = '*';
        }
        
    }

    for (int i = 0; i < 5; i ++) {
        for (int j = 0; j < len; j ++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}