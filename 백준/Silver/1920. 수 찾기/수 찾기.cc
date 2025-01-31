#include<bits/stdc++.h>
using namespace std;

int n, m, result[100002], check[100002];
map<long long, int> mp;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  long long num;

  for(int i = 0; i < n; i++){
    cin >> num;
    mp.insert({num, 1});
  }
  cin >> m;
  for(int i = 0; i < m; i++){
    cin >> check[i];
  }
  for(int i = 0; i < m; i++){
    if(mp.find(check[i]) != mp.end()){
      result[i] = 1;
    }
    else result[i] = 0;
  }
  for(int i = 0; i < m; i++){
    cout << result[i] << '\n';
  }
  return 0;
}