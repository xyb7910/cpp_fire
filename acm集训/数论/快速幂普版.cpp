#include <iostream>
using namespace std;

// 求 a mod n
int qmi(int a, int b, int n) {
    int t = 1;
    int y = a;
    while (b > 0) {
        if (b % 2 == 1)
            t = (t * y) % n;
        y = (y * y) % n;
        b /= 2;
    }
    return t;
}

int main() {
	int n; cin >> n;
	while(n --) {
		int a, b, n; cin >> a >> b >> n;
		cout << qmi(a, b, n) << endl; 
	}
	return 0;
}