/*
* @Author: Yanpb
* @Date:   2025-04-25 20:47:56
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-25 20:55:27
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    string s; cin >> s;
    if(s[0] == '-') cout << "-";
    reverse(s.begin(), s.end());
    int i = 0;
    while(s[i] == '0') i ++;
    if(i == s.size()) cout << '0';
    for (;i < s.size() && s[i] != '-'; i ++) cout << s[i];
    return 0;
}