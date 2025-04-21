#include<bits/stdc++.h>
using namespace std;

set<string> s;
string top, part;
int n;
int main(){
  cin >> n;
  while(n--){
    cin >> top;
    if(top.size() < 6)
      continue;
    part = top.substr(top.size() - 6, top.size());
    if(part == "Cheese") s.insert(top);
  }
  s.size() > 3 ? cout << "yummy\n" : cout << "sad\n";
  return 0;
}