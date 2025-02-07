/*
* @Author: Yanpb
* @Date:   2025-02-02 15:20:48
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-07 18:28:22
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 60;

string g;
int w[N], b[N], r[N]; 
int n, m, cnt;
int ans = 0x3f3f3f3f;  //要定义成无穷大 方便后面取min使用

//计数当前行全部涂成白蓝红分别需要的操作数 
int check(char a)
{
    int cnt = 0; //每次调用check函数之前记得清零cnt 
    for (int i = 0; i < m; i ++ )
    {
        if (g[i] != a) cnt ++ ; //当当前行第i个格子与我们需要涂的颜色a不同 操作数++ 
    }
    return cnt;
} 

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
    {
        //传入一整行的数据
        //以前缀和的方法计算前i行全部涂成白蓝红分别需要的操作数 
        cin >> g;
        w[i] = w[i - 1] + check('W');
        b[i] = b[i - 1] + check('B');
        r[i] = r[i - 1] + check('R');
    }

    //枚举第1行到第i行都为白色格子  则第i+ 1行到第j行都为蓝色格子 剩下的就是红色格子 
    //白色格子最多覆盖到 n-2 行 要给蓝红格子留空间 红色格子最多覆盖到 n-1 行 要给红色格子留空间 
    for (int i = 1; i <= n - 2; i ++ )
    {
        for (int j = i + 1; j <= n - 1; j ++ )
        {
            ans = min(ans, w[i] + b[j] - b[i] + r[n] - r[j]); //这里用到了求区间和的知识  s[l, r] = s[r] - s[l - 1] 为什么这里没有-1 因为使用的b[i]实际上涂的是白色格子 从b[i + 1]开始才是蓝色格子 所以b[i]并不算在涂蓝色格子的前缀和内 左开右闭(i, j]
            //cout << ans << endl;
        }
    }
    printf("%d\n", ans);

    return 0; 

}
