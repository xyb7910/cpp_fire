#include <iostream>
using namespace std;

/*
* @Author: Yanpb
* @example: 值传递与地址传递
*/

void func1(int num) {
    num += 2;
}

void func2(int num[]) {
    num[0] *= 10;
}

int main() {
    // 1. 值传递 无法修改
    int num = 1;
    func1(num);
    cout << num << endl;

    // 2. 指针传递 可以修改
    int a[5] = {3};
    a[0] = 1;
    cout << a[0] << endl;

    // 3. 指针传递 可以修改
    func2(a);
    cout << a[0] << endl;
    return 0;
}