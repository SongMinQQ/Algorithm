#include<bits/stdc++.h>

using namespace std;

int mp[102][102], dist[102][102], n;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dijkstra(){
    dist[0][0] = 0;
	priority_queue<tuple<int, int, int>, vector<tuple<int,int, int>>, greater<tuple<int,int, int>>>pq;
    pq.push({0, 0, 0});
    while(!pq.empty()){
        int cy, cx, cost;
        tie(cy, cx, cost) = pq.top();
        pq.pop();
        for(int i = 0; i < 4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			int nCost = mp[ny][nx];
            if(dist[ny][nx] > cost + nCost){
            	dist[ny][nx] = cost + nCost;
                pq.push({ny, nx, cost + nCost});
            }
        }
    }
    return;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        fill(&mp[0][0], &mp[102][102], 0);
        fill(&dist[0][0], &dist[102][102], 999999999);
		cin >> n;
        for(int i = 0; i < n; i++){
        	string line;
            cin >> line;
            for(int j = 0; j < line.size(); j++){
            	mp[i][j] = line[j] - '0';
            }
        }
        dijkstra();
        cout << '#' << test_case << ' ' << dist[n-1][n-1] << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}