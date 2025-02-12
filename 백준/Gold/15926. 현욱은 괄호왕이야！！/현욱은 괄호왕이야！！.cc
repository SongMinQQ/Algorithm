#include<bits/stdc++.h>
using namespace std;

int n, idx, result;
char item;
string s;
stack<pair<char,int>> t;
bool check[200002];

int main(){
  cin >> n;
  cin >> s;
  for(int i = 0; i < n; i++){
    if(s[i] == '(') {
      t.push({s[i], i}); 
    }
    if(s[i] == ')'){
      if(t.empty()){
        continue;
      }
      else {
        tie(item, idx) = t.top();
        t.pop();
        check[i] = true;
        check[idx] = true;
      }
    }
  }
  int calLongestString = 0;
  // for(int i = 0; i < n; i++){
  //   cout << check[i] <<' ';
  // }
  // cout << '\n';
  for(int i = 0; i <= n; i++){
    if(check[i] == true){
      calLongestString++;
    }
    else{
      // cout << calLongestString << '\n';
      result = max(result, calLongestString);
      calLongestString = 0;
    }
  }
  /*
  8
((((((()
  */
  cout << result << '\n';
  return 0;
}