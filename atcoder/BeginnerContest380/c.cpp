#include <iostream>
#include <vector>

#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;

int n, k;
string s;


void solved1() {
    cin >> n >> k;
    cin >> s;
    
    vector<PII> blocks;

    int start = -1;
    for (int i = 0; i <= n; i ++) {
        if(i < n && s[i] == '1') {
            if(start == -1) start = i;
        } else {
            if(start != -1) {
                blocks.emplace_back(start, i - 1);
                start = -1;
            }
        }
    }

    int k_start = blocks[k - 1].x;
    int k_end = blocks[k - 1].y;

    string t = s;
    string b_str = t.substr(k_start, k_end - k_start + 1);
    t.erase(k_start, k_end - k_start + 1);
    t.insert(blocks[k -2].y + 1, b_str);

    cout << t << endl;
}

int main() {
    cin >> n >> k;
    cin >> s;
    s += '.';
    vector<PII> b;
    int now = s[0], num = 0;
    for (int i = 0; i < s.size(); i ++) {
        if(s[i] == now) num ++;
        else {
            b.push_back({now - '0', num});
            now = s[i], num = 1;    
        } 
    }

    int cnt = 0; // 统计当前是第几个 1 块
    for (int i = 0; i < b.size(); i ++) {
        if(b[i].first == 1) {
            cnt ++;
            if(cnt == k) {
                swap(b[i], b[i - 1]);
            }
        } 
    }

    for (auto a : b) {
        for (int i = 0; i < a.second; i ++) {
            cout << a.first;
        }
    }
    return 0;
}
