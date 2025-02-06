#include<bits/stdc++.h>
using namespace std;

int S = 0, m;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> m;
  for(int i = 0; i < m; i++){
    string a;
    int num;
    cin >> a;
    if(a == "add"){
      cin >> num;
      S |= (1 << num-1);
    }
    if(a == "check"){
      cin >> num;
      if(S & (1 << num - 1)) cout << 1 << '\n';
      else cout << 0 << '\n';
    }
    if(a == "remove"){
      cin >> num;
      if(S & (1 << num - 1)) S ^= (1 << num-1);
      else continue;
    }
    if(a == "toggle"){
      cin >> num;
      if(S & (1 << num - 1)){
        S &= ~(1 << num - 1);
      }
      else S |= (1 << num - 1);
    }
    if(a == "all"){
      S = (1 << 20) -1;
    }
    if(a == "empty"){
      S = 0;
    }
  }
}