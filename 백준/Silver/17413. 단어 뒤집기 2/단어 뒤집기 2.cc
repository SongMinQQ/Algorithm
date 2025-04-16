#include<bits/stdc++.h>
using namespace std;
string l, a, b, result;
stack<char> s;
bool tag;
int main(){
  getline(cin, l);
  for(char i : l){
    if(i == '<'){
      s.push(i);
      a += i;
      reverse(b.begin(), b.end());
      result += b;
      b = "";
    }
    else if(i == '>'){
      s.pop();
      a += i;
      result += a;
      a = "";
    }
    else{
      if(s.empty()){
        if(i == ' '){
          reverse(b.begin(), b.end());
          result += (b + i);
          b = "";
        }
        else
        b += i;
      }
      else
        a += i;
    }
  }
  reverse(b.begin(), b.end());
  result += b;
  cout << result;
  return 0;
}