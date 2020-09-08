#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
#include <algorithm>

using namespace std;

int y, x, h;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int d[100][100][100];
int map[100][100][100];


void bfs(int hh, int xx, int yy){
    d[hh][xx][yy] = 0;
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(hh, xx, yy));
    
    while (!q.empty()) {
        int now_h = get<0>(q.front());
        int now_x = get<1>(q.front());
        int now_y = get<2>(q.front());
        q.pop();
        for(int i=0; i < 4; i++){
            int next_x = now_x+dx[i];
            int next_y = now_y+dy[i];
            if(next_x >=0 && next_x < x && next_y >= 0 & next_y < y){
                if(map[now_h][next_x][next_y] == 0){
                    if(d[now_h][next_x][next_y] == -1 || d[now_h][next_x][next_y] > d[now_h][now_x][now_y]+1){
                        d[now_h][next_x][next_y] = d[now_h][now_x][now_y]+1;
                        q.push(make_tuple(now_h, next_x, next_y));
                    }
                }
            }
        }
        if(now_h+1 < h){
            if(map[now_h+1][now_x][now_y] == 0){
                if(d[now_h+1][now_x][now_y] == -1 || d[now_h+1][now_x][now_y] > d[now_h][now_x][now_y]+1){
                    d[now_h+1][now_x][now_y] = d[now_h][now_x][now_y]+1;
                    q.push(make_tuple(now_h+1, now_x, now_y));
                }
            }
        }
        if(now_h-1 >= 0){
            if(map[now_h-1][now_x][now_y] == 0){
                if(d[now_h-1][now_x][now_y] == -1 || d[now_h-1][now_x][now_y] > d[now_h][now_x][now_y]+1){
                    d[now_h-1][now_x][now_y] = d[now_h][now_x][now_y]+1;
                    q.push(make_tuple(now_h-1, now_x, now_y));
                }
            }
        }
    }
}

int main() {
    cin >> y >> x >> h;
    for(int i=0; i < h; i++){
        for(int j=0; j < x; j++){
            for(int k=0; k < y; k++){
                cin >> map[i][j][k];
                d[i][j][k] = -1;
                if(map[i][j][k] == -1) d[i][j][k] = -2;
            }
        }
    }
    
    for(int i=0; i < h; i++){
        for(int j=0; j < x; j++){
            for(int k=0; k < y; k++){
                if(map[i][j][k] == 1){
                    bfs(i, j, k);
                }
            }
        }
    }
    
    /*
    for(int i=0; i < h; i++){
        for(int j=0; j < x; j++){
            for(int k=0; k < y; k++){
                cout << d[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    */
    
     int max = 0;
     for(int i=0; i < h; i++){
         for(int j=0; j < x; j++){
             for(int k=0; k < y; k++){
                 if(d[i][j][k] == -1){ cout << -1 << "\n"; return 0;}
                 if(d[i][j][k] > max) max = d[i][j][k];
             }
         }
     }
     cout << max << "\n";
     
    
    return 0;
}
