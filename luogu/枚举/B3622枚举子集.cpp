// #include <iostream>
// using namespace std;

// void generateSubsets(int n, int mask, int index) {
//     if (index == n) {
//         for (int i = 0; i < n; i++) {
//             cout << ((mask >> i) & 1 ? 'Y' : 'N');
//         }
//         cout << endl;
//         return;
//     }

//     // 不选择当前同学
//     generateSubsets(n, mask, index + 1);

//     // 选择当前同学
//     generateSubsets(n, mask | (1 << index), index + 1);
// }

// int main() {
//     int n;
//     cin >> n;
//     generateSubsets(n, 0, 0);
//     return 0;
// }

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 0; i < (1 << n); i ++) {
        for (int j = 0; j < n; j ++) {
            if(i & (1 << j)) cout << "Y";
            else cout << "N";
        }
        cout << endl;
    }
    return 0;
}