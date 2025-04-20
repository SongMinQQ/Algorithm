#include<bits/stdc++.h>
using namespace std;

int n, ret;
long long num;
string line;
int main(){
  cin >> n >> line;
  // num = stoll(line,nullptr,2);
  // while(num != 0){
  //   num &= (num - 1);
  //   ret++;
  // }
  for(char i : line){
    if(i == '1')
      ret++;
  }
  cout << ret << '\n';
  return 0;
}