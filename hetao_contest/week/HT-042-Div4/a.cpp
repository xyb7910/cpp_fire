/*
* @Author: Yanpb
* @Date:   2025-01-17 15:02:29
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-17 16:35:10
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c; cin >> a >> b >> c;
    int p1 = a * 30 + b * 20 + c * 10;
    int d, e, f; cin >> d >> e >> f;
    int p2 = d * 30 + e * 20 + f * 10;
    if(p1 > p2) puts("A");
    else if(p1 == p2) puts("T");
    else puts("B");
    return 0;
}