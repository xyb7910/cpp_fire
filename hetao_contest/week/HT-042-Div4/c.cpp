#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;
const int N = 1e5 + 10;
unordered_map<string, string> fr;
unordered_map<string, int> pos;
string t[N];
int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n / 2; i ++ ) {
        string a, b; cin >> a >> b;
        fr[a] = b, fr[b] = a;
    }
    int s = 0;
    for (int i = 0; i < n; i ++) {
        cin >> t[i];
        auto a = t[i];
        int point = (s % 3) + 1;
        if(pos.find(t[i]) != pos.end()) continue;
        pos[a] = point, pos[fr[a]] = point;
        s ++;
    }
    
    for (int i = 0; i < n; i ++ ) cout << pos[t[i]] << " ";
    return 0;
}