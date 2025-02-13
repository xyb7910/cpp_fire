#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

/*
使用 stl 库函数 next_permutation(start_idx, end_idx)生成下一个排列
*/
const int N = 110;
int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) a[i] = i;
    do {
        for (int i = 1; i <= n; i ++) printf("%d ", a[i]);
        puts("");

    }while(next_permutation(a + 1, a + n + 1));
    return 0;
}
