#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X, Y, Z;
    long long U, V, W;
    if (!(cin >> X >> Y >> Z)) return 0;
    cin >> U >> V >> W;

    long long total = (U / 100) * X + (V / 50) * Y + (W / 20) * Z;
    cout << total << '\n';
    return 0;
}
