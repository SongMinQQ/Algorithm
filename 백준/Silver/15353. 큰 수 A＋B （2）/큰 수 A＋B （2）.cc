#include <bits/stdc++.h>
using namespace std;

string a, b, sum, result;
void cal(string a, string b){
  int moduler = 0;
  while(a.size() || b.size() || moduler){
    if(a.size()){
      moduler += a.back() - '0';
      a.pop_back();
    }
    if(b.size()){
      moduler += b.back() - '0';
      b.pop_back();
    }
    result += (moduler % 10) + '0';
    moduler /= 10;
  }
  reverse(result.begin(),result.end());
}
int main(){
  cin >> a >> b;
  cal(a, b);
  cout << result << '\n';
  return 0;
}