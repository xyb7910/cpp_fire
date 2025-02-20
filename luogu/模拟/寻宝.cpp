#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010, M = 110, mod = 20123;

int n, m, k;
bool st[N][M];
int x[N][M];

int main()
{
    scanf("%d%d", &n, &m);

    int res = 0;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            scanf("%d%d", &st[i][j], &x[i][j]);

    scanf("%d", &k);
    for (int i = 0; i < n; i ++ )
    {
        int s = 0;
        for (int j = 0; j < m; j ++ ) s += st[i][j];
        int t = x[i][k];
        res = (res + t) % mod;
        t %= s;
        if (!t) t = s;

        for (int j = k; ;j = (j + 1) % m)
        {
            if (st[i][j])
            {
                if (-- t == 0)
                {
                    k = j;
                    break;
                }
            }
        }
    }

    printf("%d\n", res);
    return 0;
}