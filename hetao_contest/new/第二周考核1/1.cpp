#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, s, t;
int h[N];

int main()
{
    cin >> n >> s >> t;
    for (int i = 0; i < n; i ++ ) cin >> h[i];
    
    int h0 = h[0];
    for (int i = 1; i < n; i ++ ) {
        h[i] += h[i - 1];
    }
    
    // for (int i = 0; i < n; i ++ ) cout << h[i] << " ";
    int cnt = 0;
    for (int i = 0; i < n; i ++ ) {
        if(h[i] >= s && h[i] <= t) cnt ++;
    }
    cout << cnt << endl;
    return 0;
}