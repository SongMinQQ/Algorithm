#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, x, y, a, b;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> x >> y;
        a = (x + y) / 2;
        b = x - a;
        cout << a << ' ' << b << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}