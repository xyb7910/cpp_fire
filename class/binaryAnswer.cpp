#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int n, target;
int num[N];

int main()
{
	cin >> n >> target;
	for (int i = 0; i < n; i ++) cin >> num[i];

	// 数字必然存在
	// 寻找小于 target 的最大元素的下标
	// int l = 0, r = n;
	// while(l < r) {
	// 	int mid = l + r >> 1;
	// 	if(num[mid] >= target) r = mid - 1;
	// 	else l = mid;
	// }

	// 寻找大于 target 的最小元素的下标
    int l = 0, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2; 
        if (num[mid] <= target) {
            l = mid + 1; 
        } else {
            r = mid; 
        }
    }
	cout << r << endl;
	return 0;
}