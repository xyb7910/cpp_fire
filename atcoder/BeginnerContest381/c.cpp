#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int findMax1122(const string& s) {
    int maxLen = 0;
    int len = s.length();
    
    for (int i = 0; i < len; ++i) {
        int cnt = 0;
        if (s[i] == '/') {
            int left = i;
            while (left > 0 && s[left - 1] == '1') {
                --left;
                cnt ++;
            }
            
            int right = i;
            while (right < len - 1 && cnt && s[right + 1] == '2') {
                ++right;
                cnt --;
            }
            
            int currentLen = right - left + 1;
            if (currentLen % 2 == 1 && abs((i - left) - (right - i)) <= 1) {
                maxLen = max(maxLen, currentLen);
            }
        }
    }
    return maxLen;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << findMax1122(s) << endl;
    
    return 0;
}