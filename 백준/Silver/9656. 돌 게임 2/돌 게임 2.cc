#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
  cin >> n;
  ((n & 1) == 0) ? cout << "SK\n" : cout << "CY\n";
  return 0;
}