#include <bits/stdc++.h>
using namespace std;

int n, num, result1, result2;
int gyu[9];
int young[9];

void calculate(){
  //이게 호출되면서 계산해야함
  int gyuScore = 0, youngScore = 0;
  for(int i = 0; i < 9; i++){
    if(gyu[i] > young[i]) gyuScore += (gyu[i] + young[i]);
    else if(gyu[i] < young[i]) youngScore += (gyu[i] + young[i]);
  }
  // cout << young[0] << '\n';
  gyuScore > youngScore ? result1++ : result2++;
}

void makePermutation(int depth){
  if(depth == 8){
    calculate();
    return;
  }
  for(int i = depth; i < 9; i++){
    swap(young[i], young[depth]);
    makePermutation(depth + 1);
    swap(young[i],young[depth]);
  }
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    bool check[19] = {0,};
    result1 = 0; result2 = 0;
    for(int j = 0; j < 9; j++){
      cin >> gyu[j];
      check[gyu[j]] = true;
    }
    int idx = 0;
    for(int j = 1; j < 19; j++){
      if(check[j] == false){
        young[idx] = j;
        idx++;
      }
    }
    makePermutation(0);
    cout << '#' << i + 1 << ' ' << result1 << ' ' << result2 << '\n';
  }
  return 0;
}