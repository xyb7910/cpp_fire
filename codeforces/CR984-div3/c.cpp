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
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 2e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
char s[N];
LL n;
bool check_1100(LL i) {
	if(i < 0) return false;
	if(i >= n - 3) return false;
	if(s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0') return true;
	return false;
}

void solved() {
	/* your code */
	LL cnt = 0;
	cin >> s;
	n = strlen(s);
	for (int i = 0; i < n; i ++) 
		if(check_1100(i)) cnt ++;
	int q;
	cin >> q;
	while(q --) {
		int pos, num;
		cin >> pos >> num;
		pos --;
		if(s[pos] != '0' + num) {	
			bool before = check_1100(pos - 3) || check_1100(pos - 2) || check_1100(pos - 1) || check_1100(pos);
			s[pos] = '0' + num;
			bool after = check_1100(pos - 3) || check_1100(pos - 2) || check_1100(pos - 1) || check_1100(pos);
			cnt += after - before;
		}
		cout << (cnt ? "YES" : "NO") << endl;
	}
	
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL T;
    cin >> T;
    while(T --) solved();
    return 0;
}