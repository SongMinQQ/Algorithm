#include <bits/stdc++.h>
using namespace std;

long long a, b, scope = 1000000000;

long long getResult(long long a, long long b, long long cnt){
    // cout << "current roof : " << cnt << " num : " << a << '\n';
    if(a == b) return cnt;
    if(a > b || a > scope) return -1;
    long long r1 = getResult(a * 2, b, cnt + 1);
    long long r2 = getResult(stoll(to_string(a) + '1'),b, cnt + 1);

    if(r1 != -1) return r1; 
    return r2;
}
int main(){
    cin >> a >> b;
    long long ans = getResult(a, b, 1);

    if (ans == -1) cout << ans << "\n";
    else cout << ans << "\n";
    return 0;
}