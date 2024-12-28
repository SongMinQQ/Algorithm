#include <bits/stdc++.h>
using namespace std;
int n, result = 999999999, a[50];

void go(int here){
    if(here == n + 1){
        int sum = 0;
        for(int i = 1; i <= (1 << (n - 1)); i *= 2){
            int cnt = 0;
            for(int j = 1; j <= n; j++)if(a[j] & i) cnt++;
            sum += min(cnt, n - cnt);
        }
        result = min(result, sum);
        return;
    }
    go(here + 1);
    a[here] = ~a[here];
    go(here + 1);
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        int value = 1;
        for(int j = 0; j < line.length(); j++){
            if(line[j] == 'T')a[i + 1] |= value;
            value *= 2;
        }
    }
    // for(int i = 1; i <= n; i++) cout << a[i] << ' ';
    go(1);
    cout << result << '\n';
    return 0;
}