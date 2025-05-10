#include<bits/stdc++.h>
using namespace std;

int a, b, c;
float t, de;
int main(){
  cin >> a >> b >> c >> t;
  if(t - 30 > 0){
    de = floor(t / 30.0);
  }
  c <= 30 ? cout << a : cout << a + (c * de);
  return 0;
}