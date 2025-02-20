#include<bits/stdc++.h>
using namespace std;
int paper[129][129], w, b, n;

bool check(int s, int e, int mid){
  int checkNum = paper[s][e];
  for(int i = s; i < s + mid; i++){
    for(int j = e; j < e + mid; j++){
      if(paper[i][j] != checkNum) return false;
    }
  }
  return true;
}
void go(int s, int e, int mid){
  if(check(s, e, mid)){
    paper[s][e] == 0 ? w++ : b++;
  }
  else {
    int half = mid/2;
    go(s, e, half);
    go(s, e+half, half);
    go(s + half , e, half);
    go(s + half, e + half, half);
  }
}
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> paper[i][j];
    }
  }
  go(0, 0, n);
  cout << w << '\n' << b;
  return 0;
}