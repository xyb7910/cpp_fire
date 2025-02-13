#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110;
int n;
int a[N];
void print_permutation(int n, int a[], int cur) {
    if(cur == n) {
        for (int i = 0; i < n; i ++) printf("%d ", a[i]);
        puts("");
    }

    for (int i = 1; i <= n; i ++) {
        int ok = 1;
        for (int j = 0; j < cur; j ++) 
            if(a[j] == i) ok = 0;
        if(ok) a[cur] = i;
        print_permutation(n, a, cur + 1);
    }
}

int main() {
    cin >> n;
    print_permutation(n, a, 1);
    return 0;
}