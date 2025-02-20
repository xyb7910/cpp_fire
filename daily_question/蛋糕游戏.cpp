#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 5e5 + 10;
int t, n;
int a[N];
/*
每次采用最优于自己的策略进行

每一回合进行两者之一：
    Beixi 选择**相邻**的两个蛋糕，制作出一个大小为**两者之和**的 新蛋糕；
    Aerxi 选择**最左边的**或者**最右边的**的蛋糕

Beixi 先进行， 当剩下一个蛋糕的时候 Beixi 吃掉它 
*/
int main() {
    cin >> t;
    while(t --) {
        cin >> n;
        for (int i = 0; i < n; i ++) cin >> a[i];

    }
    return 0;
}