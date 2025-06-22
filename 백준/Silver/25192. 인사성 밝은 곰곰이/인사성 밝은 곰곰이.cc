#include<bits/stdc++.h>
using namespace std;

map<string, int> m;
int n, result;
string a;
int main(){
  cin >> n;
  while(n--){
    cin >> a;
    if(a == "ENTER"){
      m.clear();
    }
    else{
      if(m.find(a) != m.end())
      continue;
      else{
        m[a]++;
        result++;}
    }
  }
  cout << result;
  return 0;
}