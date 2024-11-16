#include <iostream>
#include <string>

using namespace std;

// 函数用于切换字符的大小写
char toggleCase(char c) {
    if (isupper(c)) {
        return tolower(c);
    } else {
        return toupper(c);
    }
}

int main() {
    string S;
    int Q;

    // 读取输入的字符串S
    cin >> S;

    // 读取查询次数Q
    cin >> Q;

    // 进行10^100次操作，由于次数非常大，实际上只需要观察规律即可
    // 每次操作会先将S中的大小写反转得到T，然后连接S和T得到新的S
    // 可以发现，第一次操作后，新字符串长度变为原来的2倍，第二次操作后变为原来的2倍再加上第一次操作后字符串长度，即变为原来的2 + 2 = 4倍，第三次操作后变为原来的4 + 4 = 8倍，以此类推，经过n次操作后，字符串长度变为原来的2^n倍
    // 而对于查询从开头找出第三个字符，我们只需要关注第三次操作后的情况，因为第三次操作后字符串长度至少为8，肯定能包含我们要找的第三个字符

    // 进行三次操作
    for (int i = 0; i < 3; ++i) {
        string T;
        for (char c : S) {
            T += toggleCase(c);
        }
        S += T;
    }

    // 处理查询
    for (int i = 0; i < Q; ++i) {
        int query;
        cin >> query;
        if (query <= S.length()) {
            cout << S[query - 1] << " ";
        }
    }

    return 0;
}