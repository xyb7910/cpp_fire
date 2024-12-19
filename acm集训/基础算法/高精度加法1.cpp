#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B) {
    vector<int> res;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i ++) {
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        res.push_back(t % 10);
        t /= 10;
    }
    if(t) res.push_back(1);
    reverse(res.begin(), res.end());
    return res;
}

int main () {
    string a, b; cin >> a >> b;
    vector<int> A, B;   
    for (int i = a.size() - 1; ~i; i --) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; ~i; i --) B.push_back(b[i] - '0');
    auto ans = add(A, B);
    // reverse(ans.begin(), ans.end());
    for (auto a : ans) cout << a;
    return 0;
}