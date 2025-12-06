#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    int m[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    string w[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int days = 0;
    for(int i = 1; i < x; i++) days += m[i];
    days += y;
    cout << w[days % 7];
}
