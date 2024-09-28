#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[5] = {1, 5, 3, 4, 7};

int main()
{
	sort(a, a + 5);
	for (int i = 0; i < 5; i ++) cout << a[i] << " ";
	cout << endl;
	// 一定要 - a
	int eg_index = lower_bound(a, a + 5, 4) - a;
	// lower_bound(begin, end, target) 返回第一个大于等于 target 的下标
	cout << a[eg_index] << endl;
	int g_index = upper_bound(a, a + 5, 4) - a;
	// upper_bound(begin, end, target) 返回第一个大于 target 的下标
	cout << a[g_index] << endl;
	return 0;
}