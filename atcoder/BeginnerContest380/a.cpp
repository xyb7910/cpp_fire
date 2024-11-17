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

// 方法一
int num[10];
void solved() {
    /* your code */
    int n;
    cin >> n;
    while(n) {
        num[n % 10] ++;
        n /= 10;
    }
    if(num[1] == 1 && num[2] == 2 && num[3] == 3) cout << "Yes";
    else cout << "No";
}

// 方法二
/*
void solved() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if(s == "122333") cout << "Yes";
    else cout << "No";
}
*/

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}