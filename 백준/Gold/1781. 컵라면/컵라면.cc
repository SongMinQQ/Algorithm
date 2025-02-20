#include<bits/stdc++.h>
using namespace std;

int n, d, c;
long long result;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> d >> c;
    v.push_back({d, c});
  }
  sort(v.begin(),v.end());
  for(pair<int,int> i : v){
    int deadLine = i.first;
    int cupRamen = i.second;
    result += cupRamen;
    pq.push(cupRamen);
    if(pq.size() > deadLine){
      // if(pq.top() < cupRamen){
      result -= pq.top();
      pq.pop();
      // }
    }
  }
  cout << result << '\n';
  return 0;
}