/*
* @Author: Yanpb
* @Date:   2025-04-25 13:21:41
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-25 15:56:47
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define x first
#define y second

using namespace std;
typedef long long i64;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef priority_queue<int,vector<int>,greater<int>> PIG;
typedef priority_queue<int> PIL; 
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

PIL q1, q2, q3, q4;
int k, d, m, f, q;

void solved() {
	/* your code */
	cin >> k >> d >> m >> f;
	int num = 0;
	for (int i = 0; i < k; i ++) {
		cin >> num; 
		q1.push(num); 
	} 
	for (int i = 0; i < d; i ++)
	{
		cin >> num; 
		q2.push(num); 
	} 
	for (int i = 0; i < m; i ++) {
		cin >> num; 
		q3.push(num); 
	} 
	for (int i = 0; i < f; i ++) 
	{
		cin >> num; 
		q4.push(num); 
	} 
	// cout << q1.size() << " " << q2.size() << " " << q3.size() << " " << q4.size() << endl;
	cin >> q;	
	while(q --) {
		int a, b, c; cin >> a >> b >> c;
		double sum = 0;
		sum += q1.top(); 
		// cout << q1.top() << endl;
		for (int i = 1; i <= a; i ++)  {
			// cout << q2.top() << " "; 
			sum += q2.top(); 
			q2.pop(); 
		}
		// cout << endl;
		for (int i = 1; i <= b; i ++) {
			// cout << q3.top() << " "; 
			sum += q3.top(); 
			q3.pop(); 
		}
		// cout << endl;
		for (int i = 1; i <= c; i ++) {
			// cout << q4.top() << " "; 
			sum += q4.top(); 
			q4.pop(); 
			
		}
		// cout << endl;
		// cout << sum << endl;
		printf("%.2lf\n", sum / 11);
		q1.pop();
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}