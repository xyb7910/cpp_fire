#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string s, res;

int main()
{
    cin >> s;
    int n = s.size();
    if(s[0] == '1') {
        res = "1";
        for (int i = 1; i < n; i ++ ) {
            if(s[i] == '1') res += "0";
            else res += "1";
        }
    } else {
        res = s;
    }
    cout << res << endl;
    return 0;
}