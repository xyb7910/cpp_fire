#include <iostream>
#include <string>

using namespace std;

bool isSimilar(string& str1, string& str2) {
    int len1 = str1.size();
    int len2 = str2.size();
    int diff = 0;
    if (abs(len1 - len2) > 1) {
        return false;
    }
    int i = 0, j = 0;
    while (i < len1 && j < len2) {
        if (str1[i]!= str2[j]) {
            diff++;
            if (len1 > len2) {
                i++;
            } else if (len1 < len2) {
                j++;
            } else {
                i++;
                j++;
            }
            if (diff > 1) {
                return false;
            }
        } else {
            i++;
            j++;
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string str1, str2;
        cin >> str1 >> str2;
        if (isSimilar(str1, str2)) {
            cout << "similar" << endl;
        } else {
            cout << "not similar" << endl;
        }
    }
    return 0;
}