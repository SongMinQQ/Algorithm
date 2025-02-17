#include<bits/stdc++.h>
using namespace std;

int num, arr[9];
void calculate(vector<int> v){
  int sum = 0;
  for(int i : v){
    sum += i;
  }
  if(sum == 100){
    for(int i : v){
      cout << i << '\n';
    }
    exit(0);
  }
}
void combi(int depth, vector<int> v){
  if(v.size() == 7){
    calculate(v);
    return;
  }
  for(int i = depth + 1; i < 9; i++){
    v.push_back(arr[i]);
    combi(i, v);
    v.pop_back();
  }
}
int main(){
  vector<int> v;
  for(int i = 0; i < 9; i++){

    cin >> arr[i];
  }
  combi(-1, v);
  return 0;
}