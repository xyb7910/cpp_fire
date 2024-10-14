#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;

struct Card{
	int num;
	int price;

	bool operator<(const Card& t) {
		return price > t.price;
	}
};

Card s[N];
int n, m;
int sum;

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 0 ; i < m; i ++) cin >> s[i].price >> s[i].num;
	sort(s, s + m);
	for (int  i = m - 1; i  >= 0; i --) {
		if(n >= s[i].num) {
			n -= s[i].num;
			sum += s[i].num * s[i].price;	
		} else {
			sum += n * s[i].price;
			break;
		}
	}
	cout << sum << endl;
	return 0;
}