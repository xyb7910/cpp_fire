#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int st[10];
int n;

bool is_valid(int x, int y) {
    memset(st, 0, sizeof st);
    int cnt = 0;
    while(x) {
        st[x % 10] ++;
        x /= 10;
        cnt ++;
    }
    if(cnt == 4) st[0] ++;
    while(y) {
        st[y % 10] ++;
        y /= 10;
    }
    for (int i = 0; i < 10; i ++)
        if(st[i] != 1) return false;
    return true;
}

int main() {
    int test_case = 0;
    while(cin >> n && n) {
        if(test_case ++) puts("");
        int f = 0;
        for (int i = 0; i < 10; i ++)
            for (int j = 0; j < 10; j ++)
                for (int q = 0; q < 10; q ++)
                    for (int p = 0; p < 10; p ++)
                        for (int l = 0; l < 10; l ++) {
                            int b = i * 10000 + j * 1000 + q * 100 + p * 10 + l; // 除数
                            int a = n * b; // 被除数
                            if(is_valid(b, a)) {
                                f = 1;
                                printf("%05d / %05d = %d\n", a, b, n);
                            }
                        }
        if(!f) printf("There are no solutions for %d.\n", n);
    }
    return 0;
}