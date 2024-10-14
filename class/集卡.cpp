// #include <iostream>
// #include <cstring>
// #include <algorithm>

// using namespace std;
// const int N = 1e5 + 10;
// typedef long long LL;
// int T;
// int main() {
// 	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
// 	cin >> T;
// 	while(T --) {
// 		int n;
// 		cin >> n;
// 		bool flag = false;
// 		while(n --) {
// 			int num;
// 			cin >> num;
// 			if(num == 0) {
// 				flag = true;
// 			}
// 		}
// 		if(flag) puts("yes");
// 		else puts("no");
// 	}
// 	return 0;
// }

#include<iostream>
using namespace std;

int main() {
    int T, n;
    cin >> T; 
    while (T--) {
        int n;
        cin >> n;
        bool foundHidden = false;
        while (n--) {
            int cardNumber;
            cin >> cardNumber;
            if (cardNumber == 0) {
                foundHidden = true;
            }
        }
        if (foundHidden) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}