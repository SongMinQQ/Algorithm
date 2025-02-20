#include<bits/stdc++.h>
using namespace std;

int n, m, v, k, pack;
long long result;
vector<pair<int,int>> jew;
vector<int> bag;
priority_queue<int> pq;
int main(){
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    cin >> m >> v;
    jew.push_back({m, v});
  }
  for(int i = 0; i < k; i++){
    cin >> pack;
    bag.push_back(pack);
  }
  sort(bag.begin(), bag.end());
  sort(jew.begin(), jew.end());
  int j = 0;
  for(int i = 0; i < k; i++){
    while(j < n && jew[j].first <= bag[i]) pq.push(jew[j++].second);
    if(pq.size()){
      result+= pq.top();
      pq.pop();
    }
  }
  cout << result << '\n';
  return 0;
}