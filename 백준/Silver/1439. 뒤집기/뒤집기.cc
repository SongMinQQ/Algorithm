#include<bits/stdc++.h>
using namespace std;

string line;
int r1, r2;

int getCnt(char delimiter, string input){
  int pos = 0, result = 0;
  char another = delimiter == '0' ? '1' : '0';
  while((pos = input.find(delimiter)) != string::npos){
    input.erase(0, pos + 1);
    pos = input.find(another);
    input.erase(0, pos + 1);
    result++;
  }
  return result;
}
int main(){
  cin >> line;
  r1 = getCnt('0', line);
  r2 = getCnt('1', line);
  cout << min(r1, r2) << '\n';
  return 0;
}