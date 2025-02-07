/*
* @Author: Yanpb
* @Date:   2025-02-01 21:45:38
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-07 16:56:03
*/
#include <bits/stdc++.h>

using namespace std;

int b3[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; //将所有可能用到的数字罗列出来
int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int ans = 0;
    do{
        int a1 = 100 * b3[0] + 10 * b3[1] + b3[2];
        int b1 = 100 * b3[3] + 10 * b3[4] + b3[5];
        int c1 = 100 * b3[6] + 10 * b3[7] + b3[8];
        if ((a1 * b == b1 && a1 * c == c1) || (a1 == a && b1 == b && c1 == c))
        {
            ans ++ ;
            printf("%d %d %d\n", a1, b1, c1);
        }
    }while (next_permutation(b3, b3 + 9));

    if (!ans) puts("No!!!");

    return 0;
}