#include <bits/stdc++.h>
using namespace std;

int main() {
    string X;
    cin >> X;
    int base = 10;
    if (X[0] == '0') {
        if (X.size() > 1 && X[1] == 'x') {
            base = 16;
        } else {
            base = 8;
        }
    }
    int result = stoi(X, nullptr, base);
    cout << result;
    return 0;
}
