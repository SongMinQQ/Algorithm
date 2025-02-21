#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, a[27][27],cnt = 0;
bool visited[27][27];
vector<int> v;

void dfs(int y, int x){
    visited[y][x] = 1;
    cnt++;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || a[ny][nx] == 0) continue;
        if(a[ny][nx] == 1 && !visited[ny][nx] ){
            dfs(ny, nx);
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        for (int j = 0; j < n; j++) {
            a[i][j] = line[j] - '0';
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 1 && visited[i][j] == 0){
                dfs(i,j);
                v.push_back(cnt);
                cnt = 0;
            }
        }
    }
    sort(v.begin(),v.end());
    cout << v.size() << '\n';
    for(int i : v){
        cout << i << '\n';
    }
    return 0;
}