#include<bits/stdc++.h>
using namespace std;
int n, num;
vector<int> v;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.rbegin(), v.rend());
    for(int i : v){
        cout << i << '\n';
    }
    return 0;
}