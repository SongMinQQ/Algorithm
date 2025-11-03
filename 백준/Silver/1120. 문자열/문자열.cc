#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string A, B;
    if (!(cin >> A >> B)) return 0;

    int n = A.size();
    int m = B.size();
    int ans = INT_MAX;

    for (int i = 0; i <= m - n; i++) {
        string seg = B.substr(i, n);
        int diff = 0;
        for (int j = 0; j < n; j++) {
            if (A[j] != seg[j]) diff++;
        }
        ans = min(ans, diff);
    }

    cout << ans << "\n";
    return 0;
}
