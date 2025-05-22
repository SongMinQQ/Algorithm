#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  cin >> n;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for(int i = 0; i < n; i++){
    ll x;
    cin >> x;
    pq.push(x);
  }

  int result = 0;
  while(!pq.empty()){
    ll x = pq.top(); 
    pq.pop();

    ll cnt = 1;
    while(!pq.empty() && pq.top() == x){
      cnt++;
      pq.pop();
    }

    if(cnt % 2 == 1) 
      result++;

    ll pairs = cnt / 2;
    for(ll i = 0; i < pairs; i++){
      pq.push(x * 2);
    }
  }

  cout << result << "\n";
  return 0;
}
