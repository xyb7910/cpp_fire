#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 110;
int n;
int a[N];
bool st[N];

// 增量构造法
void print_subset(int n, int a[], int cur) {
    // 判断是否符合输出条件
    for (int i = 1; i < cur; i ++) printf("%d ", a[i]);
    puts("");
    int s = cur ? a[cur - 1] + 1: 0;
    for (int i = s; i <= n; i ++) {
        a[cur] = i;
        print_subset(n, a, cur + 1);
    }
} 

// 位向量
void print_subset(int n, bool st[], int cur) {
    if(cur == n) {
        for (int i = 0; i < cur; i ++) // 打印当前集合
            if(st[i]) printf("%d ", i);
        puts("");
        return ;
    }

    st[cur] = true; // 选择第 cur 个元素
    print_subset(n, st, cur + 1);
    st[cur] = 0; // 不选择第 cur 个元素
    print_subset(n, st, cur + 1);
}

// 二进制法
void print_subset(int n, int s) {
    for (int i = 0; i < n; i ++)
        if(s & (1 << i)) printf("%d ", i);
    puts("");
}


int main() {
    cin >> n;
    // print_subset(n, st, 0);
    for (int i = 0; i < (1 << n); i ++)
        print_subset(n, i);
    return 0;
}