#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
LL happy[N];

// 手写gcd函数
LL gcd(LL a, LL b) {
    while (b != 0) {
        LL temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 输出既约分数
void printReducedFraction(LL numerator, LL denominator) {
    LL common_divisor = gcd(numerator, denominator);
    std::cout << numerator / common_divisor << "/" << denominator / common_divisor << std::endl;
}

void solved() {
    /* your code */
    LL n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
        cin >> happy[i];
        happy[i] += happy[i - 1];
    }
    while(q --) {
        int l, r;
        cin >> l >> r;
        printReducedFraction(happy[r] - happy[l - 1], r - l + 1); 
    }

}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}