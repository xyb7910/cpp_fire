#include <iostream>
using namespace std;

void generateSubsets(int n, int mask, int index) {
    if (index == n) {
        for (int i = 0; i < n; i++) {
            cout << ((mask >> i) & 1 ? 'Y' : 'N');
        }
        cout << endl;
        return;
    }

    // 不选择当前同学
    generateSubsets(n, mask, index + 1);

    // 选择当前同学
    generateSubsets(n, mask | (1 << index), index + 1);
}

int main() {
    int n;
    cin >> n;
    generateSubsets(n, 0, 0);
    return 0;
}

