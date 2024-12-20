#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

std::vector<char> addBigNumber(int base, string &a, string &b) {
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

int main()
{
    int base; cin >> base;
    string a, b; cin >> a >> b;
    auto ans = addBigNumber(base, a, b);
    for (int i = 0; i < ans.size(); i ++) cout << ans[i];
    return 0;
}