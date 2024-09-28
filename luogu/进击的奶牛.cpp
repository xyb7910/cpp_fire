#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int n, c;
int p[N];

// 二分牛棚之间的距离

bool check(int k) {
    int sum = 1;
    int f = 0;
    for (int i = 1; i < n; i ++) {
        if(p[i] - p[f] >= k) {
            sum ++;
            f = i;
        }
    }
    return sum >= c;
}

int main()
{
    cin >> n >> c;
    int r = -1;
    for (int i = 0; i < n; i ++) {
        cin >> p[i];
        r = max(r, p[i]);
    }
    sort(p, p + n);

    int l = 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if(check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}

