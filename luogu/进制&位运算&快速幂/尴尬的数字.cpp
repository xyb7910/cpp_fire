#include <iostream>
#include <cmath>
using namespace std;

long long binTodec(string str) {//二进制转十进制
	int len = int(str.size());
	int power = 1;
	long long sum = 0;
	for (int i = len - 1; i >= 0; i--) {
		sum += power * (str[i] - '0');
		power *= 2;
	}
	return sum;
}

long long threeTodec(string str) {//三进制转十进制
	int len = int(str.size());
	int power = 1;
	long long sum = 0;
	for (int i = len - 1; i >= 0; i--) {
		sum += power * (str[i] - '0');
		power *= 3;
	}
	return sum;
}

int main() {
	string str_1, str_2;
	cin >> str_1 >> str_2;
	long long t_1 = binTodec(str_1);
	long long t_2 = threeTodec(str_2);
	int power = pow(2, int(str_1.size()) - 1);
	for (int i = 0; i < int(str_1.size()); i++, power /= 2) {//枚举二进制错误
		long long t_3, t_4;
		if ((str_1[i] - '0') ^ 1)//异或操作
			t_3 = abs((t_4 = t_1 + power) - t_2);
		else
			t_3 = abs((t_4 = t_1 - power) - t_2);
		while (t_3 % 3 == 0) t_3 /= 3;//检测是否正确
		if (t_3 < 3) {
			cout << t_4 << endl;
			break;
		}
	}
	return 0;
}

