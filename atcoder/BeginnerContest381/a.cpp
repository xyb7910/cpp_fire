#include <iostream>
#include <string>

using namespace std;

bool is1122String(const string& s) {
    int len = s.length();
    
    if (len % 2 == 0) return false;
    
    int mid = len / 2;
    if (s[mid] != '/') return false;
    
    for (int i = 0; i < mid; ++i) {
        if (s[i] != '1') return false;
    }
    
    for (int i = mid + 1; i < len; ++i) {
        if (s[i] != '2') return false;
    }
    
    return true;
}

int main() {
	int n;
	cin >> n;
    string s;
    cin >> s;
    
    if (is1122String(s)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}