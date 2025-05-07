#include<bits/stdc++.h>
using namespace std;
int result, n, m;
int main(){
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cin >> m;
    while(m--){
        cin >> n;
        result += v[n - 1];
    }
    cout << result;
    return 0;
}