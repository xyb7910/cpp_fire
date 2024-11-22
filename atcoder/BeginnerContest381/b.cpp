#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool is1122String(const string& s) {
    int len = s.length();
    

    if (len % 2 != 0) return false;
    
    for (int i = 0; i < len; i += 2) {
        if (s[i] != s[i + 1]) return false;
    }
    

    unordered_map<char, int> charCount;
    for (char c : s) {
        charCount[c]++;
    }
    
    for (auto& count : charCount) {
        if (count.second != 0 && count.second != 2) return false;
    }
    
    return true;
}

int main() {
    string s;
    cin >> s;
    
    if (is1122String(s)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}