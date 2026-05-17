#include<bits/stdc++.h>

using namespace std;
const int DIS = 2;
int main(int argc, char** argv)
{
	int test_case;
	int T, N;
    stack<int> s;
	for(test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> N;
        vector<int> v(N);
        for(int i = 0; i < N; i++){
        	cin >> v[i];
        }
        int left, right, ret = 0;
		for(int i = 2; i < N - 2; i++){
            int cur = v[i];
        	left = min(cur - v[i - 1], cur - v[i - 2]);
            right = min(cur - v[i + 1], cur - v[i + 2]);
            if(left < 0 || right < 0) continue;
            ret += min(left, right);
        }
        cout << '#' << test_case << ' ' << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}