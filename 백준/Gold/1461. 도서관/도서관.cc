#include<bits/stdc++.h>
using namespace std;
int maxNum = -10001, minNum = 10001, n, m, result, cnt;

int main(){
  cin >> n >> m;
  deque<int> dq(n);
  for (int i = 0; i < n; i++){
    cin >> dq[i];
    maxNum = max(maxNum, dq[i]);
    minNum = min(minNum, dq[i]);
  }
  sort(dq.begin(),dq.end());
  if (abs(minNum) > maxNum) {
        result += abs(minNum);
        int cntc = 0;
        while (cntc < m && !dq.empty() && dq.front() < 0) {
            dq.pop_front();
            cntc++;
        }
    } else {
        result += maxNum;
        int cntc = 0;
        while (cntc < m && !dq.empty() && dq.back() > 0) {
            dq.pop_back();
            cntc++;
        }
    }
  vector<int> lefts, rights;
  while(!dq.empty()){
    int x = dq.front(); 
    dq.pop_front();
    if (x < 0) lefts.push_back(-x);
    else rights.push_back(x);
  }

  sort(lefts.rbegin(), lefts.rend());
  sort(rights.rbegin(), rights.rend());

  for(int i = 0; i < (int)lefts.size(); i += m){
      result += lefts[i] * 2;
  }
  for(int i = 0; i < (int)rights.size(); i += m){
      result += rights[i] * 2;
  }

  cout << result;
  return 0;
}