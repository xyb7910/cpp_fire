#include <iostream>
#include <string>
#include <cctype> // for isdigit function

typedef long  long LL;
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) { // 读取每一行
        LL sum = 0; // 使用长整型来存储和，以防止溢出
        bool hasNumber = false; // 标记当前行是否包含数字
        LL currentNumber = 0; // 当前解析的数字
        bool isNegative = false; // 标记当前数字是否为负数

        for (char c : line) {
            if (isdigit(c)) { // 如果当前字符是数字
                hasNumber = true;
                currentNumber = currentNumber * 10 + (c - '0'); // 解析数字
            } else if (c == '-' && !isdigit(line[line.find(c) + 1])) {
                // 如果当前字符是'-'，并且后面不是数字，则忽略它
                continue;
            } else { // 遇到非数字字符
                if (isNegative) {
                    currentNumber = -currentNumber; // 如果是负数，转换符号
                }
                sum += currentNumber; // 将当前数字加到总和中
                currentNumber = 0; // 重置当前数字
                isNegative = (c == '-'); // 如果遇到'-'，标记为负数
            }
        }

        // 处理行末的数字
        if (isNegative) {
            currentNumber = -currentNumber;
        }
        sum += currentNumber;

        // 如果行中包含数字，则输出总和
        if (hasNumber) {
            cout << sum << endl;
        }
    }

    return 0;
}