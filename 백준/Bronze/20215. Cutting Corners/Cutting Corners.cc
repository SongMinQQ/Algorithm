#include <bits/stdc++.h>
using namespace std;

int main() {
    double w, h;
    cin >> w >> h;
    double result = (w + h) - sqrt(w * w + h * h);
    cout << fixed << setprecision(9) << result << "\n";
}