#include<bits/stdc++.h>
using namespace std;

float sum;
int n, score, scoreSum;
string a, b;
float scoreToNum(string a){
  if(a == "A+") return 4.3;
  if(a == "A0") return 4.0;
  if(a == "A-") return 3.7;
  if(a == "B+") return 3.3;
  if(a == "B0") return 3.0;
  if(a == "B-") return 2.7;
  if(a == "C+") return 2.3;
  if(a == "C0") return 2.0;
  if(a == "C-") return 1.7;
  if(a == "D+") return 1.3;
  if(a == "D0") return 1.0;
  if(a == "D-") return 0.7;
  if(a == "F") return 0.0;
}

int main(){
  cin >> n;
  while(n--){
    cin >> a >> score >> b;
    scoreSum += score;
    sum += (score * scoreToNum(b));
  }
  printf("%.2f",sum / scoreSum);
  return 0;
}