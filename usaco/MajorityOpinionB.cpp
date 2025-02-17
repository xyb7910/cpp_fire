#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
/*
判断连续相同的三个就可以，注意最后的去重
*/
const int N = 2e5 + 10;
int t, n;
int grass[N];
vector<int> res;

int main() {
    scanf("%d", &t);
    while(t --) {
        scanf("%d", &n);
        res.clear();
        for (int i = 0; i < n; i ++) cin >> grass[i];
        // 对两个数据进行单独判断
        if(n == 2) {
            if(grass[0] == grass[1]) cout << grass[0] << endl;
            else cout << -1 << endl;
        } else {
            for (int i = 1; i < n - 1; i ++) {
                if(grass[i] == grass[i - 1] && grass[i] == grass[i + 1]) res.push_back(grass[i]);
                else if(grass[i] == grass[i - 1]) res.push_back(grass[i]); 
                else if(grass[i] == grass[i + 1]) res.push_back(grass[i]);
                else if(grass[i - 1] == grass[i + 1]) res.push_back(grass[i - 1]);
            }
            sort(res.begin(), res.end());
            res.erase(unique(res.begin(), res.end()), res.end());
            if(res.size()) for (auto a : res) cout << a << " ";
            else cout << -1;
            cout << endl;
        }
    }
    return 0;
}