#include<bits/stdc++.h>
using namespace std;

string a;
vector<string> v;
int ret;

int clockNum(int a, int b, int c, int d) {
  int n1 = a * 1000 + b * 100 + c * 10 + d;
  int n2 = b * 1000 + c * 100 + d * 10 + a;
  int n3 = c * 1000 + d * 100 + a * 10 + b;
  int n4 = d * 1000 + a * 100 + b * 10 + c;
  return min(min(n1, n2), min(n3, n4));
}

int main(){
  for(int i = 0; i < 4; i++){
    cin >> a;
    v.push_back(a);
  }
  vector<int> cal;
  for (int i = 0; i < 4; i++){
    string ret = v[i] + v[(i + 1) % 4] + v[(i + 2) % 4] + v[(i + 3) % 4];
    int stringToInt = stoi(ret);
    cal.push_back(stringToInt);
  }
  sort(cal.begin(), cal.end());
  int minimum = cal[0];
  int thousand, hundred, ten;
  for (int i = 1111; i < 10000; i++){
    int cur = i;
    thousand = i / 1000;
    cur -= thousand * 1000;
    hundred =  cur / 100;
    cur -= hundred * 100;
    ten = cur / 10;
    cur -= ten * 10;
    if(thousand == 0 || hundred == 0 || ten == 0 || cur == 0) continue;
    if(clockNum(thousand, hundred, ten, cur) == i) ret++;
    if(i == minimum) break;
  }
  cout << ret;
  return 0;
}