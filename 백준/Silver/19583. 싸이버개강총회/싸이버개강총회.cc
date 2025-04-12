#include<bits/stdc++.h>
using namespace std;

string line;
vector<int> tme;
int result;
unordered_map<string, pair<int,bool>> m;
vector<string> split(string input, string delimiter){
  vector<string> ret;
  long long pos;
  string token;
  while((pos = input.find(delimiter)) != string::npos){
    token = input.substr(0, pos + delimiter.length());
    ret.push_back(token);
    input.erase(0, pos + delimiter.length());
  }
  ret.push_back(input);
  return ret;
}

int changeTime(string t){
  t.replace(t.find(":"), 1, "");
  return stoi(t);
}
int main(){
  getline(cin, line);
  vector<string> times = split(line, " ");
  for(string i : times){
    tme.push_back(changeTime(i));
  }
  while(cin.eof()==false){
    getline(cin, line);
    if(line.empty()) continue; 
    // cout << "get : " << line << '\n';
    vector<string> timeline = split(line, " ");
    int mTm = changeTime(timeline[0]);
    string mName = timeline[1];
    // map에 멤버가 존재한다면
    if(m.find(mName) != m.end()){
      // 만약 퇴장시간 이내라면 결과1증가, 시간 업데이트
      if(mTm >= tme[1] && mTm <= tme[2] && m[mName].second == false){
        result++;
        m[mName].first = mTm;
        m[mName].second = true;
      }
      else m[mName].first = mTm;
    }
    // 없으면 추가시킴
    else {
      if(mTm <= tme[0]) m.insert({mName, {mTm, false}});}
  }
  cout << result << '\n';
  return 0;
}