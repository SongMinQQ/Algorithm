#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int t, n;
string p, input;
deque<int> v;
int main(){
  cin >> t;
  for(int i = 0; i < t; i++){
    bool isEmpty = false;
    cin >> p >> n >> input;
    input = input.substr(1,input.size() - 1);
    // cout << input << '\n';
    istringstream ss(input);
    string input2;
    if(input.size() > 1){
      while(getline(ss,input2, ',')){
        v.push_back(stoi(input2));
      }
    }
    int cnt = 0;
    for(int j = 0; j < p.size(); j++){
      if(p[j] == 'R') cnt++;
      else{
        if(v.empty()) {
          cout << "error\n";
          isEmpty = true;
          break;
        }
        else if(cnt % 2 == 0) v.pop_front();
        else v.pop_back();
      }
    }
    if(!isEmpty){
    if(!v.empty() && cnt % 2 == 1) reverse(v.begin(),v.end());
    cout << '[';
    for(int j = 0; j < v.size(); j++){
      if(j == v.size() - 1) cout << v[j];
      else cout << v[j]<<',';
    }
    cout << "]\n";
    v.clear();}
    else v.clear();
  }
}