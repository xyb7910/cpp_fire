#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int a[N], b[N];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) {
        int num; cin >> num;
        a[i] += a[i - 1] + num;
    }
    for (int i = 1; i <= n; i ++) {
        int num; cin >> num;
        b[i] += b[i - 1] + num;
    }
    
    int ans = 0;
    for (int i = n; i >= 1; i --) {
        if(a[i] == b[i]) {
            ans = i; 
            break;
        }
    }
    cout << ans << endl;
    return 0;
}