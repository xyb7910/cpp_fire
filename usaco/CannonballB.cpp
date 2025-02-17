#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;
const int N = 1e6 + 10;

/*
会从s的位置开始，其实能量为1，并且初始方向为向右
如果q为1，则这个位置为炮击的目标；为0则为跳板，跳板会使方向反向，
并且使得能量增加v。
如果Bessie的能量 >= 炮击目标的能量，则会将目标击坏。
可以重复向击破的目标移动    
*/

int n, s;
// dir 1 left -1 right
int dir = 1, power = 1, cnt;
int direct[N], powers[N];
bool st[N];
PII line[N];

int main() {
    cin >> n >> s;
    for (int i = 1; i <= n; i ++) cin >> line[i].x >> line[i].y;
    while(s >= 1 && s <= n) {
        // 炮击目标 q 等于 1 并且 能量是大于等于 炮击目标
        if(line[s].x) {
            // 判断是否出现死循环 ，如果方向和能量一直不变
            if(direct[s] == dir && powers[s] == power) break;
            if(!st[s] && power >= line[s].y) direct[s] = dir, powers[s] = power, cnt ++, st[s] = 1;
        } else {
            power += line[s].y;
            dir *= -1;
        }
        s += power * dir;
    }
    cout << cnt;
    return 0;
}
