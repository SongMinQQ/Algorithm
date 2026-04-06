#include<bits/stdc++.h>
using namespace std;

bool check(int a){
  if(a >= 630 && a <= 900){
    return true;
  }
  else if(a >= 950 && a <= 1000){
    return true;
  }
  else if(a >= 1050 && a <= 1100){
    return true;
  }
  else if(a >= 1150 && a <= 1200){
    return true;
  }
  else if(a >= 1250 && a <= 1350){
    return true;
  }
  else if(a >= 1440 && a <= 1450){
    return true;
  }
  else if(a >= 1540 && a <= 1550){
    return true;
  }
  else if(a >= 1640 && a <= 2250){
    return true;
  }
  else
    return false;
}
int q, w;
int main(){
  cin >> q >> w;
  if(check(q * 100 + w)){
    cout << "Yes";
  }
  else cout << "No";
  return 0;
}