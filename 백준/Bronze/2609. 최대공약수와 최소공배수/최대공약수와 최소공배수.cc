#include<bits/stdc++.h>
using namespace std;

int n, m, low, high;
int gcd(int a, int b){
  int r;
  while(1){
    r = a % b;
    if(r == 0) return b;
    a = b;
    b = r;
  }
}
int lcm(int a, int b){
  return a * b / gcd(a, b);
}
int main(){
  cin >> n >> m;
  cout << gcd(n, m) << '\n' << lcm(n, m);
  return 0;
}