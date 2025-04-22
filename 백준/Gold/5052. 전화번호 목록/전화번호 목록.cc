#include<bits/stdc++.h>
using namespace std;

int t, n;
string a, b;

int main(){
  cin >> t;
  while(t--){
    cin >> n ;
    bool isFind = false;
    int pos = -1;
    vector<string> v(n);
    for (int i = 0; i < n; i++){
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    if(n == 1){
      cout << "YES\n";
      continue;
    }
    for (int i = 0; i + 1 < n; i++){
      if (v[i+1].compare(0, v[i].size(), v[i]) == 0) {
        isFind = true;
        break;
      }
    }
    if (isFind) cout << "NO\n";
    else cout << "YES\n";
  }
  return 0;
}