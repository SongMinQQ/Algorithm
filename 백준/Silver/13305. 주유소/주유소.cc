#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll>> pq;
ll n, num, result;
vector<ll> load, oil;
int main(){
  cin >> n;
  for (int i = 0; i < n - 1; i++){
    cin >> num;
    load.push_back(num);
  }
  for (int i = 0; i < n; i++){
    cin >> num;
    oil.push_back(num);
  }
  for (int i = 0; i < n - 1; i++){
    pq.push(oil[i]);
    result += pq.top() * load[i];
  }
  cout << result;
  return 0;
}