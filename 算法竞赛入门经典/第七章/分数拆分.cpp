#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

/*
题目要求我们计算出来 1/k = 1/x + 1/y;
进行化简可得: (x - k)(y - k) = k^2  "初中数学,交叉相乘，横着写"

暴力枚举就可以
最后答案输出的时候，记得还原公式。
*/
const int N = 1e5 + 10;
int k;
int x[N], y[N];

int main() {
    while(cin >> k) {
        memset(x, 0, sizeof x);
        memset(y, 0, sizeof y);
        int n = k * k, cnt = 0;
        for (int i = 1; i <= k; i ++) 
            if(n % i == 0) {
                x[++ cnt] = n / i;
                y[cnt] = i;
            }
        printf("%d\n", cnt);
        for (int i = 1; i <= cnt; i ++)
            printf("1/%d = 1/%d + 1/%d\n", k, x[i] + k, y[i] + k);
    }
    return 0;
}