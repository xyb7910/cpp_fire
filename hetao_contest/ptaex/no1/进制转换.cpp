/*
* @Author: Yanpb
* @Date:   2025-03-20 13:48:04
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-20 15:34:11
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
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int base_front, base_end;
string num;

int convertToDecimal(string num, int base) {
	int decimal = 0;
	for (auto ch : num) {
		int digit = 0;
		if(ch >= '0' && ch <= '9') digit = ch - '0';
		else if(ch >= 'a' && ch <= 'z') digit = ch - 'a' + 10;
		else if(ch >= 'A' && ch <= 'Z') digit = ch - 'A' + 10;
		decimal = decimal * base + digit;
	}
	return decimal;
}

string decimalToBase(int decimalNumber, int base) {
	string res = "";
	while(decimalNumber) {
		int remainder = decimalNumber % base;
		char digit;
		if(remainder < 10) {
			digit = '0' + remainder;
		} else {
			digit = 'A' + remainder - 10;
		}
		res += digit;
		decimalNumber /= base;
	}
	reverse(res.begin(), res.end());
	return res;
}

void solved() {
	/* your code */
	cin >> base_front >> num >> base_end;
	cout << base_front << " " << num << " " << base_end << endl;
	// 使用 秦九韶算法将任意进制转十进制
	int convert_num = convertToDecimal(num, base_front);
	// 将十进制转任意进制
	string ans = decimalToBase(convert_num, base_end);
	cout << ans;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}