#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int num;
int main(){
    for(int i = 0; i < 3; i++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    cout << v[1];
    return 0;
}