#include<bits/stdc++.h>
using namespace std;

stack<char> s;
string a;
int result;
int main(){
  cin >> a;
  for(int i = 0; i < a.size(); i++){
    if(a[i] == '(') {
      s.push('(');
    } 
    else { 
      s.pop();
      if(a[i-1] == '('){
        result += s.size();
      } else {
        result += 1;
      }
    }
  }
  cout << result;
  return 0;
}