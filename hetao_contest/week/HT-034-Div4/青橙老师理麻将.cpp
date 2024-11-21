#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;
set<string> se;
unordered_map<string, int> heap;
int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i += 2) {
        string str = s.substr(i, 2);
        heap[str] ++;
    }
    int cnt = 0;
    for (auto a : heap) {
        if(a.second >= 4) {
            cnt ++;
        }
    }
    cout << 27 - cnt << endl;
    return 0;
}