#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long i64;
/*
枚举起点 和 终点 就可以。
*/
const int N = 20;
i64 a[N];
i64 test_case, n, res;
int main() {
    while(cin >> n) {
        res = 0;
        ++ test_case;
        for (i64 i = 0; i < n; i ++) cin >> a[i];
        for (i64 st = 0; st < n; st ++)
            for (i64 s = 1, ed = st; ed < n; ed ++) {
                    s *= a[ed];
                    res = max(res, s);  
            }   
        printf("Case #%lld: The maximum product is %lld.\n\n", test_case, res);
    }
    return 0;
}   