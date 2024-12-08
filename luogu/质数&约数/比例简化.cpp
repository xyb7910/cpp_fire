#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int A, B, L;
    cin >> A >> B >> L;

    int a, b;
    double delta = 1e9;
    for (int i = 1; i <= L; i ++ )
        for (int j = 1; j <= L; j ++ )
            if (gcd(i, j) == 1)
            {
                double x = i * 1.0 / j;
                double X = A * 1.0 / B;

                if (x >= X && x - X < delta)
                {
                    delta = x - X;
                    a = i, b = j;
                }
            }

    cout << a << ' ' << b << endl;

    return 0;
}