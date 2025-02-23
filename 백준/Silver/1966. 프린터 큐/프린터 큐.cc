#include<bits/stdc++.h>
using namespace std;
int N, n, m;
int main(){
    int N;
    cin >> N;
    while(N--){
        deque<pair<int, int>> dq;
        int cnt = 1;
        cin >> n >> m;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
            dq.push_back({v[i], i});
        }
        sort(v.begin(),v.end());
        while(1){
            if(dq.front().first == v[v.size() - 1]){
                if(dq.front().second == m){
                    cout << cnt << '\n';
                    break;
                }
                else{
                    dq.pop_front();
                    v.pop_back();
                    cnt++;
                }
            }
            else{
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
    }
    return 0;
}