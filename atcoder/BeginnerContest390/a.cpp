#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int st[10], cnt;

int main() {
    for (int i = 1; i <= 5; i ++) {
        int x;
        cin >> x;
        if(x == i) st[i] = 1;
        else cnt ++;
    }
    cout << (cnt == 2 ? "Yes" : "No");
    return 0;
}