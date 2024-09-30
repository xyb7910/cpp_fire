#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
int n, k;
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> k;
	std::vector<int> num(n + 1, 0);
	for (int i = 1; i <= n; i ++) cin >> num[i];
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());
	if(k < num.size()) cout << num[k] << endl;
	else puts("NO RESULT");
	return 0;
}