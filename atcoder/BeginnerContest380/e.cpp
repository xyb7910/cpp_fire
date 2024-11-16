#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int p[N], cnt[N];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        p[i] = i;
        cnt[i] = 1;
    }
    while (m -- )
    {
        int op, a, b;
        cin >> op;

        if(op == 1)
        {
            cin >> a >> b;
            a = find(a), b= find(b);
            if(a != b)
            {
                p[a] = b;
                cnt[b] += cnt[a];
            }
        }
        else 
        {
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }
    return 0;
}