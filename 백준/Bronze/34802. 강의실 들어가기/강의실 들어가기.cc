#include<bits/stdc++.h>
using namespace std;

string line;
int sNum, eNum;
double t, k;
vector<string> split(string a, string delimiter){
  vector<string> ret;
  long long pos;
  string token = "";
  while((pos = a.find(delimiter)) != string::npos){
    token = a.substr(0, pos);
    ret.push_back(token);
    a.erase(0, pos + delimiter.size());
  }
  ret.push_back(a);
  return ret;
}
int main(){
  cin >> line;
  vector<string> stList = split(line, ":");
  cin >> line;
  vector<string> edList = split(line, ":");
  cin >> t >> k;
  sNum = (3600 * stoi(stList[0])) + (stoi(stList[1]) * 60) + stoi(stList[2]);
  eNum = (3600 * stoi(edList[0])) + (stoi(edList[1]) * 60) + stoi(edList[2]);
  if (sNum > eNum) {
    cout << 0;
    return 0;
  }
  if(k != 0)
  t *= (100 - k) / 100;
  t += sNum;
  abs(t) <= eNum ? cout << 1 : cout << 0;
  return 0;
}