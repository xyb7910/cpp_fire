#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
/*
第i头奶牛 成为 “领导者”：
 1. 名单上包含 该品种的所有奶牛
 2. 名单上有另一种奶牛的领导者
*/
const int N = 2e5 + 10;
int n;
int E[N];
string s;

int main() {
    cin >> n >> s;
    for (int i = 1; i <= n; i ++) cin >> E[i];
    
    return 0;
}