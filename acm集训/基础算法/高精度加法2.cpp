#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

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

vector<int> add(string &A, string &B) {
    vector<int> res;
    int t = 0, i = A.size() - 1, j = B.size() - 1;
    while(~i || ~j || t > 0) {
        if(~i) t += A[i --] - '0';
        if(~j) t += B[j --] - '0';
        res.push_back(t % 10);
        t /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

void solved() {
    /* your code */
    string a, b; cin >> a >> b;
    vector<int> A, B;

    vector<int> res = add(a, b);
    for (auto a : res) cout << a;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}