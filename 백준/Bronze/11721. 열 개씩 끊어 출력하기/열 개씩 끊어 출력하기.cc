#include<bits/stdc++.h>
using namespace std;

string n, a;

int main(){
  cin >> n;
  while(n.size() > 10){
    a = n.substr(0, 10);
    n.erase(0, 10);
    cout << a << '\n';
  }
  cout << n;
  return 0;
}