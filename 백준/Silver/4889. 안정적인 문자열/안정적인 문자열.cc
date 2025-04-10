#include<bits/stdc++.h>
using namespace std;

string line;
int main(){
  int cnt = 1;
  while(1){
    cin >> line;
    if(line.find('-') != string::npos)
      break;
    stack<char> s;
    int result = 0;
    for(char i : line){
      if(!s.empty()&& s.top() == '{' && i =='}'){
        s.pop();
      }
        else s.push(i);
    }
    while(!s.empty() && s.size() > 1){
      char isDiff = s.top();
      s.pop();
      if(isDiff == s.top())
        result += 1;
      else result += 2;
      s.pop();
    }
    cout << cnt << ". " << result << '\n';
    cnt++;
  }
  return 0;
}