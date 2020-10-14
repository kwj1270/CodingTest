#include <iostream>
#include <vector>

#define INF 1000000
using namespace std;

int dx[] = {0,1,0,-1}; // 오른 아래 왼 위
int dy[] = {1,0,-1,0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        
        int n, r; cin >> n >> r; // 그리드 크기, 우향우 갯수;
        vector<vector<int>> map(n+2, vector<int>(n+2, -2));
        for(int i=1; i <=n; i++){
            for(int j=1; j <= n; j++){
                map[i][j] = 1;
            }
        }
        for(int i=0; i < r; i++){
            int x, y; cin >> x >> y;
            map[x][y] = -1;
        }
        
        int rager_x, rager_y; cin>> rager_x >> rager_y;
        map[rager_x][rager_y] = 0;
        
        
        int dir = 0;
        if(rager_y == 0) dir = 0; // 오른
        if(rager_x == 0) dir = 1;//아래
        if(rager_y == n+1) dir = 2; // 왼
        if(rager_x == n+1) dir = 3; // 위
        bool isRecursive = false;
        int now_x = rager_x+dx[dir];
        int now_y = rager_y+dy[dir];
        cout << "\n";
        for(int i=0; i < map.size(); i++){
            for(int j=0; j < map[i].size(); j++){
                cout << map[i][j] << " ";
            }
            cout << "\n";
        }
        
        while (true) {
            if(map[now_x][now_y] == -2) {isRecursive = false; break;} // 정상적인 종료
            if(map[now_x][now_y] == 1){
                now_x += dx[dir];
                now_y += dy[dir];
                continue;
            }
            if(map[now_x][now_y] == -1){
                map[now_x][now_y] = 1;
                if(dir == 3) dir = 0;
                else dir++;
                now_x += dx[dir];
                now_y += dy[dir];
                continue;
            }
            if(map[now_x][now_y] == 0){
                isRecursive = true;
                break;
            }
        }
        cout << "\n";
        for(int i=0; i < map.size(); i++){
            for(int j=0; j < map[i].size(); j++){
                cout << map[i][j] << " ";
            }
            cout << "\n";
        }
        if(isRecursive) { cout << "0 0" << "\n"; continue;}
        cout << now_x << " " << now_y << "\n";
    }

}
