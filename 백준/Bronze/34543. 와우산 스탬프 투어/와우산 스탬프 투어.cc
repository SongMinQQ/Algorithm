#include<bits/stdc++.h>
using namespace std;

int n, w, score;
int main(){
  cin >> n >> w;
  score += (n * 10);
  if(n >= 3) score += 20;
  if(n == 5) score += 50;
  if(w > 1000) score < 15 ? score = 0 : score -= 15;
  cout << score;
  return 0;
}