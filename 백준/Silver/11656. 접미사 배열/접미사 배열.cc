#include <bits/stdc++.h>
using namespace std;

string s;
set<string> se;
int main(){
  cin >> s;
  for (int i = 0; i < s.size(); i++){
    se.insert(s.substr(i));
  }
  for(auto &i : se){
    cout << i << '\n';
  }
  return 0;
}