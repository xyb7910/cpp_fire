/*
* @Author: Yanpb
* @Date:   2025-01-17 16:41:21
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-17 17:05:28
*/
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;


/*
引理1：前 k + 1 位的所有循环长度，一定是 前 k 位循环节长度的子集。
	证明：如果前 k 位不相等， 那么第 k + 1 位一定也不会相等。
引理2：假设最小循环节长度为 t， 那么所有循环节长度一定都是 t 的整数倍
	证明：反证法证明 ==> 视频里面有讲到。

解法：
	从小到大一位一位的枚举出前 k 位的循环节长度
	每一次递归最多枚举 10 次，使用高精度乘法（没有使用 FFT加速）
	时间复杂度位 ${10 * {k ^ 3}$
*/

const int N = 110;

int m;
int nums[N], power[N];

void mul(int c[], int a[], int b[])
{
    static int temp[N];
    memset(temp, 0, sizeof temp);

    for (int i = 0; i < m; i ++ )
        for (int j = 0; j < m; j ++ )
            if (i + j < m)
                temp[i + j] += a[i] * b[j];
    for (int i = 0, t = 0; i < m; i ++ )
    {
        t += temp[i];
        temp[i] = t % 10;
        t /= 10;
    }
    memcpy(c, temp, sizeof temp);
}

void mul(int c[], int a[], int b)
{
    for (int i = 0, t = 0; i < m; i ++ )
    {
        t += a[i] * b;
        c[i] = t % 10;
        t /= 10;
    }
}

int main()
{
    string str;
    cin >> str >> m;
    for (int i = 0, j = str.size() - 1; j >= 0; j --, i ++ ) nums[i] = str[j] - '0';
    memcpy(power, nums, sizeof nums);

    int per[N] = {1};
    int p1[N], pn[N];   // p1 = 1 * p^(kt), pn = n * p^(kt)

    for (int k = 1; k <= m; k ++ )
    {
        memcpy(pn, nums, sizeof nums);
        memset(p1, 0, sizeof p1);
        p1[0] = 1;

        int r = 0;
        while (r <= 10)
        {
            mul(pn, pn, power);
            mul(p1, p1, power);
            r ++ ;
            if (pn[k - 1] == nums[k - 1]) break;
        }
        memcpy(power, p1, sizeof p1);

        if (r > 10)
        {
            memset(per, 0, sizeof per);
            per[0] = -1;
            break;
        }

        mul(per, per, r);
    }

    int k = m;
    while (!per[k]) k -- ;

    while (k >= 0) cout << per[k -- ];

    return 0;
}