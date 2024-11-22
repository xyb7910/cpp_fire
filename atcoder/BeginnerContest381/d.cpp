#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int findMax1122(const vector<int>& A) {
    int maxLen = 0;
    int n = A.size();

    for (int start = 0; start < n; ++start) {
        unordered_map<int, int> count;
        int len = 0;
        bool isValid = true;

        for (int end = start; end < n; end += 2) {
            if (end + 1 >= n) break;

            if (A[end] != A[end + 1]) {
                isValid = false;
                break;
            }

            count[A[end]]++;
            count[A[end + 1]]++;

            len += 2;

            if (!all_of(count.begin(), count.end(), [](const pair<int, int>& p) { return p.second == 2; })) {
                isValid = false;
                break;
            }
            if (isValid) maxLen = max(maxLen, len);
        }
    }

    return maxLen;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // 输出结果
    cout << findMax1122(A) << endl;

    return 0;
}