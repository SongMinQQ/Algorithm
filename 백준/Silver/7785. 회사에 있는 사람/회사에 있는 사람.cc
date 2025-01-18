#include <bits/stdc++.h>
using namespace std;

map<string, string> m;
string a, b;
int n;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(b == "enter"){
            m.insert({a, a});
        }
        else m.erase(a);
    }
    map<string, string>::iterator iter;
    for(iter = m.end(); iter != m.begin(); ){
        --iter;
        cout << iter->second << '\n';
    }
    return 0;
}