#include <iostream>
#include <vector>

using namespace std;

vector<int> mul(vector<int> A, int k) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i++) {
        if (i < A.size()) t += A[i] * k;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int k, num;
        cin >> k >> num;
        vector<int> A = {1};  
        for (int i = 1; i <= k; i++) {
            A = mul(A, i);
        }
        
        int cnt = 0;
        for (auto a : A) {
            if (a == num) {
                cnt++;
            }
        }
        
        cout << cnt << endl;
    }
    return 0;
}