#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int n;
    cin >> n;

    int gcd1 = a + b;
    int gcd2 = c + d;
    int gcd3 = e + f;


    int playing1 = (n - 1) % gcd1 < a; 
    int playing2 = (n - 1) % gcd2 < c; 
    int playing3 = (n - 1) % gcd3 < e; 

    int countPlaying = playing1 + playing2 + playing3;

    cout << countPlaying << endl;

    return 0;
}