#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    cout << a.front() * a.back() << "\n";
    return 0;
}
