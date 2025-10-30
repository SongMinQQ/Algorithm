#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int Tcases; 
    if(!(cin >> Tcases)) return 0;
    while (Tcases--) {
        int N, M;
        cin >> N >> M;
        int U = 2*M - N;
        int T = N - M;
        cout << U << ' ' << T << '\n';
    }
    return 0;
}
