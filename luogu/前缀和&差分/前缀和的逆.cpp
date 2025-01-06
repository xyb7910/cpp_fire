/*
* @Author: Yanpb
* @Date:   2025-01-03 15:27:51
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-03 15:27:56
*/
#include <iostream>
#include <cstring>
#include <algorithm>

const int N = 110;
int s[N];

using namespace std;

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> s[i];
    }
    
    cout << s[1] << " ";
    
    for (int i = 2; i <= n; i ++) {
        cout << s[i] - s[i - 1] << " ";
    }
    return 0;
}