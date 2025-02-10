#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long i64;
const int N = 100;
int n;
int num[N];
int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> num[i];
    for (int i = 1; i + 1 < n; i ++) 
        if(i64(num[i] * num[i]) != i64(num[i - 1] * num[i + 1])) {
            cout << "No" << endl;
            return 0;
        }
    cout << "Yes" << endl;
    return 0;
}