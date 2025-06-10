#include<bits/stdc++.h>
using namespace std;
string a, b;
int x, y;
int main(){
  cin >> x >> y;
  while(x--){
    a += "1";
  }
  while(y--){
    b += "1";
  }
  cout << stoi(a) + stoi(b);
  return 0;
}