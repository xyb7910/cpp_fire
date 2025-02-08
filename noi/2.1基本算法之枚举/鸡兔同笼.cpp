/*
* @Author: Yanpb
* @Date:   2025-02-08 17:00:08
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-08 17:00:19
*/
#include <cstdio>
#include <iostream>
using namespace std;

/*
先考虑无解情况：如果脚的数量是 奇数的话，必然无解
如果动物数量最小，那么假设全是鸡，
如果动物数量最大，那么假设全是兔子，
*/
int main() {
    int n;
    cin >> n;
    if(n & 1) puts("0 0");
    else {
        // 动物数量最少
        int min_num = (n + 3) / 4;
        // 动物数量最多
        int max_num = n / 2;
        cout << min_num << " " << max_num;
    }
    return 0;
}