#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

const int N = 1e6 + 10;
int h[N];
int n, m;

bool check(int k) {
	LL sum = 0;
	for (int i = 0; i < n; i ++)
	{
		if(h[i] > k) sum += h[i] - k;
	}
	return sum >= m;
}

int find() 
{
	int l = 1, r = 1e9;
	while(l < r) 
	{
		int mid = l + (r - l + 1) / 2;
		if(check(mid))
		{
			l = mid;
		} 
		else
		{
			r = mid - 1;
		}
	}	
	return r;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> h[i];
	cout << find() << endl;
	return 0;
}