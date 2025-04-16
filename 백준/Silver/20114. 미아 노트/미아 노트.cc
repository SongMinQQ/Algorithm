#include<bits/stdc++.h>
using namespace std;
int n, h, w;
string line, result;
int main(){
  cin >> n >> h >> w;
  for (int i = 0; i < n; i++){
    result +='?';
  }
  for (int i = 0; i < h; i++){
    cin >> line;
    int cnt = 0;
    while(line.size()){
      string a = line.substr(0,w);
      for (int i = 0; i < w; i++){
        if(a[i] != '?') result[cnt] = a[i];
      }
      line.erase(0, w);
      cnt++;
    }
  }
  cout << result;
  return 0;
}