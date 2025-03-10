#include <iostream>
using namespace std;

int s, n; // sum, number
void sum(int cur) {
    if(cur <= n) {
        s += cur;
        sum(cur + 1);
    } 
}
int main() {
    cin >> n;
    sum(1);
    cout << s << endl;
    return 0;
}