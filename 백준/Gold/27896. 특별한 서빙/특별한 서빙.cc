#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, num, a, ret;
priority_queue<ll, vector<ll>, less<ll>> pq;
int main(){
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    cin >> num;
    a += num;
    pq.push(num);
    if(a >= m){
      a -= pq.top() * 2;
      pq.pop();
      ret++;
    }
    
  }
  cout << ret;
  return 0;
}