#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
LL x;
LL b, c;
LL cost;
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> x;
	string s;
	cin >> s;
	for (int  i = 0; i < 2; i ++) {
		if(s[i] == 'B') b ++;
		else if(s[i] == 'C') c ++;
	}
	// cerr << b << " " << c << endl;
	LL a = 10;
	if(b && !c) a = 8;
    else if(!b && c) a = 7;
    else if(b && c) a = 6;
    
    cost = (x / 10) * a;
    cout << cost << endl;
	return 0;
}