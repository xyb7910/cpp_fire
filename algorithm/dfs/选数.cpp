#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
	for (int i = 2; i < x / i; i ++)
		if(x % i == 0) return false;
	return true;
}

void dfs(vector<int>& nums, int index, int k, int sum, int& count) {
    if (k == 0) {
        if (isPrime(sum)) {
            count++;
        }
        return;
    }
    if (index >= nums.size()) return;
    dfs(nums, index + 1, k - 1, sum + nums[index], count);
    dfs(nums, index + 1, k, sum, count);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int count = 0;
    dfs(nums, 0, k, 0, count);
    cout << count << endl;
    return 0;
}