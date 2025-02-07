/*
* @Author: Yanpb
* @Date:   2025-02-07 17:02:04
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-07 18:28:18
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
/*
1. 先通过年份构造出来回文日期
2. 判断日期是否再范围之内
3. 判断日期是否合法
*/
int st, ed, res;
const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check_valid(int data) {
    int year = data / 10000;
    int month = data % 10000 / 100;
    int day = data % 100;
    if(!month || month > 12) return false;
    if(!day || month != 2 && days[month] < day) return false;
    if(month == 2) {
        int leap = year % 100 && year % 4 == 0 || year % 400 == 0;
        if(leap + 28 < day) return false;
    }
    return true;
}

int main() {
    cin >> st >> ed;
    for (int i = 1000; i < 10000; i ++) {
        int data = i, x = i;
        // 构造出来回文日期
        for (int j = 0; j < 4; j ++) data = data * 10 + x % 10, x /= 10;
        if(st <= data && data <= ed && check_valid(data)) res ++; 
    }
    cout << res;
    return 0;
}