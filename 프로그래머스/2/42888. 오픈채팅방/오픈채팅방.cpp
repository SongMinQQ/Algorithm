#include <bits/stdc++.h>

using namespace std;
vector<string> split(string input, string delimiter){
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while((pos = input.find(delimiter)) != string::npos){
        token = input.substr(0,pos);
        ret.push_back(token);
        input.erase(0,pos + delimiter.length());
    }
    ret.push_back(input);
    return ret;
}
vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    for(string i : record){
        vector<string> sliceString = split(i, " ");
        if(sliceString[0] == "Enter"){
            m.insert({sliceString[1], sliceString[2]});
            if(m[sliceString[1]] != sliceString[2])m[sliceString[1]] = sliceString[2];
        }
        else if(sliceString[0] == "Change"){
            m[sliceString[1]] = sliceString[2];
        }
    }
    for(string i : record){
        string result;
        vector<string> sliceString = split(i, " ");
        if(sliceString[0] == "Enter"){
            result = m[sliceString[1]] + "님이 들어왔습니다.";
        }
        else if(sliceString[0] == "Leave"){
            result = m[sliceString[1]] + "님이 나갔습니다.";
        }
        else continue;
        answer.push_back(result);
    }
    return answer;
}