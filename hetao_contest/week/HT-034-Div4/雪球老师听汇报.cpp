#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int tt = -1;
int s[N];
int n;

int main() {
    cin >> n;
    while(n --) {
        int  num;
        cin >> num;
        if(num) {
            s[++ tt] = num;
        } else {
            tt --;
        }
    }
    int sum = 0;
    for (int i = tt; ~i; i --) {
        sum += s[i];

    }
    cout << sum;
    return 0;
}