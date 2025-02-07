#include<bits/stdc++.h>
using namespace std;

int n, score, stu;
float avg;
vector<int> v;

int cal(){
  int cnt = 0;
  for(int i : v){
    if(i > avg) cnt++;
  }
  return cnt;
}
int main(){
  cin >> n;
  while(n--){
    cin >> stu;
    int add = 0;
    for(int i = 0; i < stu; i++){
      cin >> score;
      v.push_back(score);
      add += score;
    }
    avg = add / stu;
    // cout << add << '\n';
    int students = cal();
    float a = (float)students / stu;
    printf("%.3f%\n",a * 100.0);
    v.clear();
  }
  return 0;
}
