#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;

int a[N], b[N];

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++) {
        cin >>  b[i];
    }
    sort(a, a + n), sort(b, b + n);
    LL minv = 0, maxv = 0;
    for (int i = 0; i < n; i ++ ) {
        minv += max(a[i], b[i]);
    }
    
    for (int i = 0, j = n - 1; i < n && ~j; i ++, j -- ) {
            maxv += max(a[i], b[j]);
    }
    cout << minv << endl << maxv << endl;
    return 0;
}