#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 判断闰年
bool LeapYear(int year) {
	if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return true;
	return false;
}

int main()
{
    int y, m;
    cin >> y >> m;
    if(LeapYear(y) && m == 2) cout << 29 << endl;
    else if(!LeapYear(y) && m == 2) cout << 28 << endl;
    else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) cout << 31 << endl;
    else cout << 30 << endl;
    return 0;
}