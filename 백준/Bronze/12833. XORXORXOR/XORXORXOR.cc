#include<bits/stdc++.h>
using namespace std;

int a, b, c;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> a >> b >> c;
  int result;
  if(c % 2 == 0) result = a;
  else result = a ^ b;
  cout << result;
  return 0;
}