#include<bits/stdc++.h>
using namespace std;

int result;
string a;
vector<int> n;
vector<char> v;
bool visited[100];
vector<string> split(string input){
  vector<string> ret;
  long long pos = 0;
  string token = "";
  while(1){
    int a = input.find('-'), b = input.find('+');
    if(a == -1 && b == -1) break;
    if(a >= 0 || b >= 0){
      if(a >= 0){
        if(b == -1) pos = a;
        else pos = a < b ? a : b;
      }
      else pos = b;
    }
    token = input.substr(0,pos);
    ret.push_back(token);
    v.push_back(input[pos]);
    input.erase(0, pos + 1);
  }
  ret.push_back(input);
  return ret;
}
int main(){
  v.push_back('+');
  cin >> a;
  vector<string> nums = split(a);
  bool minus = false;

  for (int i = 0; i < (int)nums.size(); i++){
    int val = stoi(nums[i]);
    char op = v[i];
    if (minus){
      result -= val;
    } else {
      if (op == '-'){
        result -= val; 
        minus = true;
      } else {
        result += val;
      }
    }
  }

  cout << result;
  return 0;
}