/*
* @Author: Yanpb
* @Date:   2024-12-29 23:28:41
* @Last Modified by:   Yanpb
* @Last Modified time: 2024-12-30 10:45:27
*/
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
    string s; cin >> s;
    for (int i = s.size() - 1; ~i; i --) {
    	if(s[i] == 'p') cout << 'q';
    	else if(s[i] == 'q') cout << 'p';
    	else cout << s[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T; cin >> T; while(T --) solved();
    return 0;
}