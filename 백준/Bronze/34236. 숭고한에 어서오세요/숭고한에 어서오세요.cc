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
    int x = v[1] - v[0];
    cout << v[v.size()-1] + x;
    return 0;
}