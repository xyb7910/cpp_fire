#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
int cnt;
int primes[N];
bool st[N];

// 判断闰年
bool LeapYear(int year) {
	if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return true;
	return false;
}

// 判断素数
bool is_prime(int x) {
	if (x < 2) return false;
	for (int i = 2; i <= x / i; i ++)
		if(x % i == 0) return false;
	return true;
}

// 埃氏筛选质数
void get_primes(int n) {
    for (int i = 2; i <= n; i ++) {
        if(!st[i]) {
            primes[cnt ++] = i;
            for (int j = 2 * i; j <= n; j += i)
                st[j] = true;
        }
    }
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

// 选择排序
void selectSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex!= i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// 计数排序
void countingSort(int arr[], int n) {
    int maxVal = arr[0];
    int minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }

    int range = maxVal - minVal + 1;
    int count[1000]; 
    for (int i = 0; i < range; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i] - minVal]++;
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// 计算阶乘
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}


// 试除法求约数
vector<int> get_divisors(int n) {
	vector<int> res;

	for (int i = 1; i <= n / i; i ++) {
		if(n % i == 0) {
			res.push_back(i);
			if(i != n / i) res.push_back(n / i);
		}
	}
	sort(res.begin(), res.end());
	return res;
}

// 寻找最大公约数
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}



int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	
	return 0;
}