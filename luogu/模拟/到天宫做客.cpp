#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 将日期转换为一年中的第几天
int dateToDay(int month, int day) {
    // 4000年是闰年，2月有29天
    int monthDays[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfYear = 0;
    for (int i = 1; i < month; ++i) {
        dayOfYear += monthDays[i];
    }
    dayOfYear += day;
    return dayOfYear;
}

int main() {
    int N;
    cin >> N;
    vector<int> dates;

    // 读取必须呆在人间的日期，并转换为一年中的第几天
    for (int i = 0; i < N; ++i) {
        int month, day;
        cin >> month >> day;
        dates.push_back(dateToDay(month, day));
    }

    // 如果没有必须呆在人间的天数，最长空闲时间段为366天
    if (N == 0) {
        double timeInHeaven = 366 * 86400.0 / 366;
        cout << static_cast<int>(round(timeInHeaven)) << endl;
        return 0;
    }

    // 对日期排序
    sort(dates.begin(), dates.end());

    // 计算最长空闲时间段
    int maxGap = 0;

    // 计算相邻日期之间的间隔
    for (int i = 1; i < N; ++i) {
        int gap = dates[i] - dates[i - 1] - 1;
        if (gap > maxGap) {
            maxGap = gap;
        }
    }

    // 处理跨年的情况（从最后一个日期到第一个日期）
    int gap = (366 - dates[N - 1]) + (dates[0] - 1);
    if (gap > maxGap) {
        maxGap = gap;
    }

    // 如果所有天数都必须呆在人间，最长空闲时间段为0天
    if (N == 366) {
        maxGap = 0;
    }

    // 计算在天上的时间（秒）
    double timeInHeaven = maxGap * 86400.0 / 366;
    int timeInHeavenRounded = static_cast<int>(round(timeInHeaven));

    // 输出结果
    cout << timeInHeavenRounded << endl;

    return 0;
}