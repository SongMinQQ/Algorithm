#include<bits/stdc++.h>
using namespace std;

int n, q, w;
string a;
int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a;
    if(a == "yonsei")
      q = i;
    else if(a == "korea")
      w = i;
  }
  q < w ? cout << "Yonsei Won!" : cout << "Yonsei Lost...";
  return 0;
}