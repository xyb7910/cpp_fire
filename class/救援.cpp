#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
typedef long long LL;

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
    cin >> n;
    double x, y;
    int m;
    double s, t = 0;
    while (n -- ) {
        cin >> x >> y >> m;
        s = sqrt(x * x + y * y);
        t += 2 * s / 50 + 1.5 * m;
    }
    // 方式一 ceil & floor 的返回值都为 float 必须转为 int
    cout << (int)ceil(t) << endl;

    // 方式二
    // int T;
    // T = (int)t;
    // if(t > T) {
    //     T ++;
    // }
    // cout << T;
	return 0;
}





