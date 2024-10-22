#include <iostream>
#include <string>
using namespace std;

char shiftCharacter(char c, int n) {
    int base;
    int range = 26;

    if (c >= 'a' && c <= 'z') {
        base = 'a';
        // range = 26;
    } else if (c >= 'A' && c <= 'Z') {
        base = 'A';
        // range = 26;
    } else {
        return c; // 对于非字母字符，直接返回原字符
    }

    int newPos = (c - base + n + range) % range;
    // if (newPos < 0) {
    //     newPos += range; // 处理负数情况
    // }

    char newChar = base + newPos;
    // cout << newChar << endl;

    if (newChar < c && base == 'a') {
        newChar = 'A' + (newChar - 'a');
    } else if (newChar < c && base == 'A') {
        newChar = 'a' + (newChar - 'A');
    }
    // cout << newChar << endl;
    return newChar;
}

string shiftString(const string& s, int n) {
    string result = "";
    for (char c : s) {
        result += shiftCharacter(c, n);
    }
    return result;
}

int main() {
    int n;
    string s;
    
    cin >> n;
    cin >> s;
    
    cout << shiftString(s, n) << endl;
    
    return 0;
}