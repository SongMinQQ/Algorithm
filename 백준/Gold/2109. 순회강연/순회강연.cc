#include<bits/stdc++.h>
using namespace std;

int n, d, p, result;
vector<pair<int, int>> lecture;
priority_queue<int> pq;
bool check[10002];

bool checkSchedule(int idx){
  for(int i = idx; i > 0; i--){
    if(check[i] == false) {
      check[i] = true;
      return true;
    }
  }
  return false;
}
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> p >> d;
    lecture.push_back({p, d});
  }
  // int idx = 1;
  sort(lecture.rbegin(),lecture.rend());
  // for(pair<int,int> i : lecture){
  //   cout << i.first << '\n';
  // }
  for(int i = 0; i < n; i++){
    if(checkSchedule(lecture[i].second)){
      result += lecture[i].first;
    }
  }

  cout << result << '\n';
  return 0;
}