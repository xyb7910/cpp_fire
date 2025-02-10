#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

/*
使用递归求解1 ~ n的排列：
递归关键在于对出口的设计（递归边界）：
*/

const int N = 1e5 + 10;
int n;
int num[N], st[10];
void print_permutation(int cur) {
    if(cur == n) {
        for (int i = 0; i < n; i ++) printf("%d ", num[i]);
        puts("");
        return ;
    }

    for (int i = 1; i <= n; i ++) {
        if(!st[i]) {
            num[cur] = i; 
            st[i] = 1;
            print_permutation(cur + 1);
            st[i] = 0;
            num[cur] = 0;
        }
        
    }
}

int main() {
    cin >> n;
    print_permutation(0);
    return 0;
}