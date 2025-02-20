#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

set<int> st;//分解出来的数
vector<int> res = { 1 };//乘积结果
int n;

//高精乘
void mul(vector<int>& A, int b)
{
	vector<int> res;
	int t = 0;
	for (int i = 0; i < A.size() || t; i++)
	{
		if (i < A.size()) t += A[i] * b;
		res.push_back(t % 10);
		t /= 10;
	}
	while (res.size() > 1 && !res.back()) res.pop_back();
	A = res;
}

int main()
{
	cin >> n;
	for (int i = 2; ; i++)
	{
		if (n - i >= 0) n -= i, st.insert(i);
		else if (n - i == -1)//加上i后和比x大1的情况
		{
			st.insert(i + 1);//由于待插入的i为最大数，因此插入i+1即可
			st.erase(2);//把2去掉
			break;
		}
		else//加上i后和比x大k的情况
		{
			st.insert(i);
			st.erase(abs(n - i));//把k去掉
			break;
		}
	}
	for (auto x : st) mul(res, x), cout << x << ' ';
	puts("");
	for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
	return 0;
}
