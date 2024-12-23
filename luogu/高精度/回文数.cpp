#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

std::vector<char> addBigNumber(int base, vector<char> &a, vector<char> &b) {
    vector<char> res;
    int t = 0, i = a.size() - 1, j = b.size() - 1;
    while(~i || ~j || t) {
        if(~i) {
            if(a[i] >= '0' && a[i] <= '9') t += a[i --] - '0';
            else if(a[i] >= 'A' && a[i] <= 'Z') t += a[i --] - 'A' + 10;  
        }
        if(~j) {
            if(b[j] >= '0' && b[j] <= '9') t += b[j --] - '0';
            else if(b[j] >= 'A' && b[i] <= 'Z') t += b[j --] - 'A' + 10;  
        }
        int r = t % base;
        if(r >= 10 && r < base) {
            res.push_back(r - 10 + 'A');
        }
        else if(r >= 0 && r <= 9) {
            res.push_back(r + '0'); 
        }
        t /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool is_pali(vector<char> a) {
    vector<char> back_up = a;
    reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); i ++) {
        if(back_up[i] != a[i]) return false;
    }
    return true;
}

void printS(vector<char> &s) {
    for (auto a : s) cout << a;
    cout << endl;
}

int main()
{
    int base; cin >> base;
    string a; cin >> a;
    vector<char> A;
    for (int i = 0; i < a.size(); i ++) A.push_back(a[i]);
    vector<char> B = A;
    reverse(A.begin(), A.end());
    int cnt = 0;
    while(!is_pali(addBigNumber(base, A, B))) {
        A = addBigNumber(base, A, B);
        cnt ++;
        // printS(A);
        B = A;
        reverse(A.begin(), A.end());
        if(cnt >= 30) {
            puts("Impossible!");
            return 0;
        }
    }
    cout << "STEP=" << cnt + 1 << endl;
    return 0;
}
