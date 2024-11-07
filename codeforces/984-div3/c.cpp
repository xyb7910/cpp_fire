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
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};


bool check_1100(string s, LL i) {
	if(i < 0) return false;
	if(i >= s.size() - 3) return false;
	if(s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0') return true;
	return false;
}

void solved() {
	/* your code */
	int T;
	cin >> T;
	while(T --) {
		LL cnt = 0;
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i ++) 
			if(check_1100(s, i)) cnt ++;
		int q;
		cin >> q;
		while(q --) {
			int pos, num;
			cin >> pos >> num;
			pos --;
			if(s[pos] != '0' + num) {	
				bool before = check_1100(s, pos - 3) || check_1100(s, pos - 2) || check_1100(s, pos - 1) || check_1100(s, pos);
				s[pos] = '0' + num;
				bool after = check_1100(s, pos - 3) || check_1100(s, pos - 2) || check_1100(s, pos - 1) || check_1100(s, pos);
				cnt += after - before;
			}
			cout << (cnt ? "YES" : "NO") << endl;
		}
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}