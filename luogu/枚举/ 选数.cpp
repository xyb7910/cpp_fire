/*
* @Author: Yanpb
* @Date:   2025-02-06 10:17:57
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-06 10:18:14
*/
#include <iostream>
using namespace std;
const int N = 30; 
int n, k, a[N];
int ans;
bool is_prime (int x)
{
	if(x < 2) return false;
	
	for (int i = 2; i < x / i; i ++)
	{
		if(x % i == 0) return false;
		return true;
	}
}

void choose(int start, int count, int sum)
{
	if(count == k && is_prime(sum)) ans ++;
	if(start != n) choose(start + 1, count + 1, sum + a[start + 1]);
} 

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	
	choose(1, 0, 0);
	cout << ans << endl;
	return 0;
}