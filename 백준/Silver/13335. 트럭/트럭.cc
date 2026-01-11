#include<bits/stdc++.h>
using namespace std;

int n, w, l, a, idx, curLoad, t;
vector<int> truck;
int main(){
  cin >> n >> w >> l;
  for (int i = 0; i < n; i++){
    cin >> a;
    truck.push_back(a);
  }
  queue<int> bridge;
  for (int i = 0; i < w; i++) bridge.push(0);

  while (idx < n || curLoad > 0) {
    t++;
    curLoad -= bridge.front();
    bridge.pop();
    if (idx < n && curLoad + truck[idx] <= l) {
      bridge.push(truck[idx]);
      curLoad += truck[idx];
      idx++;
    } else {
      bridge.push(0);
    }
  }

  cout << t;
  return 0;
}