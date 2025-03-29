#include<bits/stdc++.h>
using namespace std;

int n,m, num, result, loaded;
vector<int> box;
vector<pair<int, int>> crain;
bool contain[10002];

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> num;
    crain.push_back({num, 0});
  }
  cin >> m;
  for(int i = 0; i < m; i++){
    cin >> num;
    box.push_back(num);
  }
  sort(crain.rbegin(), crain.rend());
  sort(box.rbegin(), box.rend());
  if(box[0] > crain[0].first) { cout << -1; return 0;}
  while(loaded < m){
    for (int i = 0; i < n; i++){
      while(crain[i].second < m){
        if(!contain[crain[i].second] && crain[i].first >= box[crain[i].second]){
          contain[crain[i].second] = true;
          loaded++;
          crain[i].second++;
          break;
        }
        crain[i].second++;
      }
    }
    result++;
  }
  cout << result << '\n';
  return 0;
}