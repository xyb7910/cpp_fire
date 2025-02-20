#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;
/*
优先采摘消耗力气比较小的苹果
x-表示消耗的力气
y-表示苹果的高度
以x为基准元素进行排序
*/
const int N = 5010;
typedef pair<int, int> PII;
int n, s, a,  b;
PII apples[N];
int res;
int main() {
    cin >> n >> s >> a >> b;
    for (int i = 0; i < n; i ++) cin >> apples[i].y >> apples[i].x;  
    sort(apples, apples + n);
    for (int i = 0; i < n; i ++) {
        if(apples[i].y <= a + b && s >= apples[i].x) {
            res ++;
            s -= apples[i].x;
        }
    }
    cout << res;
    return 0;
}