#include <iostream>

using namespace std;
int n;
int sum(int cur) {
    if(cur <= n) {
        return cur + sum(cur + 1);
    } else {
        return 0;
    }
}

int main() {
    cin >> n;
    cout << sum(1);    
    return 0;
}