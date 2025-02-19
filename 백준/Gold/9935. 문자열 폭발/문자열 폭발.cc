#include<bits/stdc++.h>
using namespace std;

string s, destroyWord, result;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> s >> destroyWord;

  vector<char> a, b;
  for(char i : destroyWord){
    b.push_back(i);
  }
  reverse(b.begin(),b.end());
  for(char i : s){
    a.push_back(i);
    if(i == b[0]){
      bool check = false;
      for(int j = 0; j < b.size(); j++){
        if(a[a.size() - (j + 1)] == b[j])check = true;
        else {check = false; break;}
      }
      if(check){
        for(int j = 0; j < b.size(); j++){
          a.pop_back();
        }
      }
    }
  }
  if(a.size()){
    for(char i : a){
      cout << i;
    }
  }
  else cout << "FRULA";
  return 0;
}