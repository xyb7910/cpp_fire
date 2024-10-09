#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
int cnt;


// 判断闰年
bool LeapYear(int year) {
	if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return true;
	return false;
}

// 判断素数
bool is_prime(int x) {
	if (x < 2) return false;
	for (int i = 2; i < x / i; i ++)
		if(x % i == 0) return false;
	return true;
}

// 判断回文数字
bool isPalindrome(int num) {
	if (num < 0) return false;
	int src_num = num;
	int reverse_num = 0;
	while(num) {
		reverse_num = reverse_num * 10 + num % 10;
		num /= 10;
	}
	return src_num == reverse_num;
}




int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for (int  i = 1; i <= n; i ++) {
		if(isPalindrome(i)) cnt ++;
	}
	cout << cnt << endl;
	return 0;
}