#include<bits/stdc++.h>
using namespace std;

vector<string> v;
int n;
bool cmp(string a, string b){
  if(a.size() != b.size()){
    return a.size() < b.size();
  }
  if(a.size() == b.size()){
    int q = 0, w = 0;
    for(char i : a){
      if(i - 'A' < 0){
        q += i - '0';
      }
    }
    for(char i : b){
      if(i - 'A' < 0){
        w += i - '0';
      }
    }
    if(q != w)
    return q < w;
  }
  return a < b;
}
int main(){
  cin >> n;
  while(n--){
    string line;
    cin >> line;
    v.push_back(line);
  }
  sort(v.begin(), v.end(), cmp);
  for(string i : v){
    cout << i << '\n';
  }
  return 0;
}