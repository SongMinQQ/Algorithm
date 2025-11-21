#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X, Y;
    if (!(cin >> X >> Y)) return 0;

    long long d = Y - X;

    if (d == 0) {
        cout << 0;
        return 0;
    }

    long long n = sqrt((long double)d);

    if (n * n == d) {
        cout << 2 * n - 1;
    } else if (d <= n * n + n) {
        cout << 2 * n;
    } else {
        cout << 2 * n + 1;
    }

    return 0;
}
