/*
* @Author: Yanpb
* @Date:   2025-02-08 17:09:16
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-09 15:32:10
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int a = 2; a <= N; ++a) {
        for (int b = 2; b < a; ++b) {
            for (int c = b; c < a; ++c) {
                for (int d = c; d < a; ++d) {
                    int a_cube = a * a * a;
                    int b_cube = b * b * b;
                    int c_cube = c * c * c;
                    int d_cube = d * d * d;
                    if (a_cube == b_cube + c_cube + d_cube) {
                        cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
                    }
                }
            }
        }
    }

    return 0;
}