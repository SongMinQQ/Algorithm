#include<bits/stdc++.h>
using namespace std;
string line;
map<string, float> m;
int cnt;
int main(){
  while(cin.eof() == false){
    getline(cin, line);
    if(line.empty())break;
    m.find(line) != m.end() ? m[line] += 1.0 : m[line] = 1.0;
    cnt++;
  }
  for(auto i : m){
    printf("%s %.4f\n",i.first.c_str(), ((i.second * 100) / cnt));
  }
  return 0;
}