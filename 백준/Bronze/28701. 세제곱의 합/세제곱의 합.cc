#include<bits/stdc++.h>
using namespace std;

long long n, result;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        result += i;
    }
    cout << result << '\n';
    result = result * result;
    cout << result << '\n'<< result;
    return 0;
}