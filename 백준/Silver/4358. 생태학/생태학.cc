#include<bits/stdc++.h>
using namespace std;
string s;
map<string, float> m;
int cnt;
int main(){
  while(cin.eof() == false){
    getline(cin, s);
    if(s.empty())break;
    m.find(s) != m.end() ? m[s] += 1.0 : m[s] = 1.0;
    cnt++;
  }
  for(auto i : m){
    printf("%s %.4f\n",i.first.c_str(), ((i.second * 100) / cnt));
  }
  return 0;
}