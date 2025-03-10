#include <iostream>
using namespace std;
/*
* @Author: Yanpb
* @Question: f(n) = f(n - 1) + 3
* @example: f(5) = f(4) + 3 = 13; 
*           f(4) = f(3) + 3 = 10;
*           f(3) = f(2) + 3 = 7;        
*           f(2) = f(1) + 3 = 4;
*           f(1) = 1;
*/
int f(int n) {
    int res = 0;
    if(n == 1) {
        res = 1;
    } else {
        res = f(n - 1) + 3;
    }
    return res;
}
int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i ++)
        cout << f(i) << endl;
    return 0;
}