#include<bits/stdc++.h>
using namespace std;

string s, result;
int isJ, isC;
string changeC(){
  for(char i : s){
    if(i - 'a' < 0){
      result += '_';
      result += tolower(i);
    }
    else
      result += i;
  }
  return result;
}
string changeJ(){
  bool check = false;
  for(char i : s){
    if(i == '_'){
      check = true;
      continue;
    }
    if(check){
      result += toupper(i);
      check = false;
    }
    else
      result += i;
  }
  return result;
}
bool errCheck(){
  if(s[0] - 'a' < 0 || s[0] == '_' || s[s.size() - 1] == '_' || (isJ > 0 && isC > 0))
    return true;
  stack<char> t;
  for(char i : s){
    if(!t.empty() && i != '_'){
      t.pop();
    }
    else if(!t.empty() && i == '_'){ 
      return true;
    }
    if(i == '_') t.push(i);
  }
  return false;
}
int main(){
  cin >> s;
  for(char i : s){
    if(i - 'a' < 0 && i != '_')
      isJ++;
    else if(i == '_')
      isC++;
  }
  if(errCheck()){
    cout << "Error!\n";
    return 0;
  }
  isJ ? cout << changeC() << '\n' : cout << changeJ() << '\n';
  return 0;
}