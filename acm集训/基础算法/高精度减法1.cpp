#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool cmp(vector<int> A, vector<int> B) {
    if(A.size() != B.size()) return A.size() > B.size();
    // A.size() == B.size()
    for (int i = A.size() - 1; ~i; i --) {
        if(A[i] != B[i])
            return A[i] > B[i];
    }
    return true;
}


vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> res;
    int t = 0;
    // 处理的是A - B; A > B
    // t = A[i] - B[i] - t;
    for (int i = 0; i < A.size(); i ++) {
        t = A[i] - t;
        if(i < B.size()) t -= B[i];
        res.push_back((t + 10) % 10);
        if(t < 0) t = 1;
        else t = 0;
    }
    
    while(res.size() > 1 && res.back() == 0) res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}


int main()
{
    string a, b; cin >> a >> b;
    vector<int> A, B; 
    for (int i = a.size() - 1; ~i; i --) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; ~i; i --) B.push_back(b[i] - '0');
    
    vector<int> ans;
    if(!cmp(A, B)) {
        cout << "-";
        ans = sub(B, A);
    } else {
        ans = sub(A, B);
    }
    for (auto a: ans) cout << a;
    return 0;
}