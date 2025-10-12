#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a,b,n,k;
    if(!(cin>>a>>b>>n>>k)) return 0;
    long long t = (k-1)/n;
    long long i = t / b + 1;
    long long j = t % b + 1;
    cout << i << ' ' << j << '\n';
    return 0;
}
