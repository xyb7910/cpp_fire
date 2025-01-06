/*
* @Author: Yanpb
* @Date:   2025-01-03 15:27:08
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-03 15:27:14
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
        int num; cin >> num;
        s[i] += s[i - 1] + num;
        cout << s[i] << " ";
    }
    return 0;
}