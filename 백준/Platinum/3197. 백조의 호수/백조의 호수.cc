#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int r, c, swanY, swanX, y, x, cnt = 0;
char a[1502][1502];
bool visited[1502][1502];
bool swanVisited[1502][1502];
queue<pair<int, int>> check_water;
queue<pair<int,int>> check_ice;
queue<pair<int, int>> check_swan;
queue<pair<int, int>> check_depth;
void queueClear(queue<pair<int, int>> &q){
    queue<pair<int, int>> cq;
    swap(q, cq);
}
void iceToWater(){
    while(check_water.size()){
        tie(y, x) = check_water.front();
        check_water.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny > r || nx > c || visited[ny][nx]) continue;
            if(a[ny][nx] == 'X'){
                visited[ny][nx] = 1;
                check_ice.push({ny, nx});
                a[ny][nx] = '.';
            }
        }
    }
}
bool isMeetSwan(){
    while (check_swan.size()){
        tie(y, x) = check_swan.front();
        check_swan.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny > r || nx > c || swanVisited[ny][nx]) continue;
            swanVisited[ny][nx] = 1;
            if(a[ny][nx] == '.'){
                check_swan.push({ny, nx});
            }
            else if(a[ny][nx] == 'X'){
                check_depth.push({ny, nx});
            }
            else if(a[ny][nx] == 'L'){
                return true;
            }
        }
    }
    return false;
}
int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        string line;
        cin >> line;
        for(int j = 0; j < line.length(); j++){
            a[i][j] = line[j];
            if(a[i][j] == 'L'){
                swanY = i; swanX = j;
            }
            if(a[i][j] == '.' || a[i][j] == 'L'){
                visited[i][j] = 1;
                check_water.push({i, j});
            }
        }
    }
    check_swan.push({swanY, swanX});
    swanVisited[swanY][swanX] = 1;
    while(1){
        if(isMeetSwan())break;
        iceToWater();
        check_water = check_ice;
        check_swan = check_depth;
        queueClear(check_ice);
        queueClear(check_depth);
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}