#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if(!(cin >> T)) return 0;
    const long long PERIOD = 25LL * 60;
    const long long AWAKE  = 17LL * 60;

    while (T--) {
        long long t; 
        cin >> t;
        long long minutes = (t * 60 + 30) % PERIOD;
        cout << (minutes < AWAKE ? "ONLINE" : "OFFLINE") << '\n';
    }
    return 0;
}
