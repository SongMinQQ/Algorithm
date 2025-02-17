#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;
vector<bool> visited;

void makeVector(){
    if(v.size() == m) {
        for(int i : v){
                cout << i << ' ';
            }
            cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            visited[i] = 1;
            v.push_back(i);
            makeVector();
            v.pop_back();
            visited[i] = 0;
        }
    }
}
int main(){
    cin >> n >> m;
    visited.assign(n + 1, false);
    makeVector();
    return 0;
}