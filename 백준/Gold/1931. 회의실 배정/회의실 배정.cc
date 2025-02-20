#include<bits/stdc++.h>
using namespace std;

int n, s, e;
vector<pair<int,int>> meeting;
priority_queue<int> pq;
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s >> e;
    meeting.push_back({e, s});
  }
  sort(meeting.begin(), meeting.end());
  pq.push(meeting[0].first);
  for(int i = 1; i < n; i++){
    if(pq.top() <= meeting[i].second) pq.push(meeting[i].first);
  }
  cout << pq.size();
  return 0;
}