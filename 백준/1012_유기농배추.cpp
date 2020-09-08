#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int m, n, k; // 가로 세로 갯수
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int map[50][50];
bool d[50][50];

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    d[x][y] = true;
    while (!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        for(int i=0; i < 4; i++){
            int next_x = now_x+ dx[i];
            int next_y = now_y+ dy[i];
            if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < m){
                if(d[next_x][next_y] == false && map[next_x][next_y] == 1){
                    d[next_x][next_y] = true;
                    q.push(make_pair(next_x, next_y));
                }
            }
        }
    }
}


int main() {
    int t; cin >> t;
    while (t--) {
        cin >> m >> n >> k; //
        memset(map, 0, sizeof(map));
        memset(d, false, sizeof(d));
        
        for(int i=0; i < k; i++){
            int y, x;
            cin >> y >> x;
            map[x][y] = 1;
        }
        
        int cnt = 0;
        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++){
                if(d[i][j] == false && map[i][j] == 1){
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        
        cout << cnt << "\n";
    }
    
    return 0;
}
