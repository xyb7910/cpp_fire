#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T; // 询问次数
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> l(N), r(N);
        
        // 读取li
        for (int i = 0; i < N; ++i) {
            cin >> l[i];
        }
        
        // 读取ri
        for (int i = 0; i < N; ++i) {
            cin >> r[i];
        }
        
        bool possible = true;
        int prev = r[N-1]; // 最后一天的最大值
        
        // 从倒数第二天开始往前处理
        for (int i = N - 2; i >= 0; --i) {
            // 当前天能卖出的最大值不能超过 prev
            if (r[i] > prev) {
                r[i] = prev;
            }
            
            // 如果当前天的最大值仍小于最小要求，则无法满足条件
            if (r[i] < l[i]) {
                possible = false;
                break;
            }
            
            // 更新 prev
            prev = r[i];
        }
        
        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
	return 0;
}