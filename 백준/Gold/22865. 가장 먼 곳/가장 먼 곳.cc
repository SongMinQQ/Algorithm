#include<bits/stdc++.h>
using namespace std;

int n, a, b, c, m, num1, num2, num3, dist[100002],cCost, cNode, result;
vector<pair<int, int>> v[100002];
void dijkstra(int node){
  dist[node] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, node});
  while(!pq.empty()){
    tie(cCost, cNode) = pq.top();
    pq.pop();
    for(pair<int,int> i : v[cNode]){
      int nCost = i.second;
      int next = i.first;
      if(dist[next] > cCost + nCost){
        dist[next] = cCost + nCost;
        pq.push({dist[next], next});
      }
    }
  }
}
int getResult(){
  int resultNum = 0, resultNode= 0;
  for (int i = 1; i <= n; i++){
    if(resultNum < dist[i]){
      resultNum = dist[i];
      resultNode = i;
    }
  }
  return resultNode;
}
int main(){
  cin >> n;
  fill(&dist[0], &dist[n + 2], 999999999);
  cin >> a >> b >> c >> m;
  for (int i = 0; i < m; i++){
    cin >> num1 >> num2 >> num3;
    v[num1].push_back({num2, num3});
    v[num2].push_back({num1, num3});
  }
  dijkstra(a);
  dijkstra(b);
  dijkstra(c);
  cout << getResult() << '\n';
  return 0;
}