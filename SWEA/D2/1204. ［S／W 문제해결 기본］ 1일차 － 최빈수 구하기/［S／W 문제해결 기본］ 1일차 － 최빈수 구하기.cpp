#include<bits/stdc++.h>

using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main(int argc, char** argv)
{
	int test_case;
	int T, num;
    
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{	
        int testNum;
        cin >> testNum;
        map<int, int> m;
		for(int i = 0; i < 1000; i++){
        	cin >> num;
            m[num]++;
        }
        vector<pair<int,int>> v(m.begin(), m.end());
		sort(v.rbegin(), v.rend(), cmp);
        //int ret = 0, flag = v[0].second;
        //for(int i = 0; i < 1000; i++){
        //    if(v[i].second != flag) break;
        //    ret = max(ret, v[i].first);
        //}
        cout << '#' << testNum << ' ' << v[0].first << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}