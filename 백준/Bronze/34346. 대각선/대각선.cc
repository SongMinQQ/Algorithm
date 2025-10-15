#include<bits/stdc++.h>
using namespace std;

int n;
int main(){
    cin >> n;
    int ret;
    ret = n % 2 == 0 ? 2 : 1;
    cout << ret;
    return 0;
}