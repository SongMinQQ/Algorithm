#include<bits/stdc++.h>
using namespace std;
int n;
string s, f, a, b;
int main(){
  cin >> n >> s;
  int idx = s.find('*');
  a = s.substr(0, idx);
  s.erase(0, idx + 1);
  b = s;
  while(n--){
    cin >> f;
    if(f.size() < a.size() + b.size()){
      cout << "NE\n";
      continue;
    }
    string compA = f.substr(0, a.size()), compB = f.substr(f.size() - b.size(), b.size());
    // cout << compA << ' ' << compB << '\n';
    (compA == a && compB == b) ? cout << "DA\n" : cout << "NE\n";
  }
  return 0;
}