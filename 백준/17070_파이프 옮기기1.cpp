#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <tuple>
#include <queue>

#define MAX 16
#define DIRECTION 3

using namespace std;

int n;
int map[MAX][MAX];
int d[DIRECTION][MAX][MAX];
int main() {
    cin >> n;
    
    memset(map, -1, sizeof(map));

    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            cin >> map[i][j];
        }
    }
    
    // 0 -> ,1 | ,2 \
    
    d[0][0][1] = 1;
    
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0,0,1));
    
    while (!q.empty()) {
        int dir = get<0>(q.front());
        int now_x = get<1>(q.front());
        int now_y = get<2>(q.front());
        q.pop();
        if((dir == 0 || dir == 2) && (now_y+1 < n && now_y+1 >= 0)){
            if(map[now_x][now_y+1] == 1) continue;
            d[0][now_x][now_y+1]++;
            q.push(make_tuple(0, now_x, now_y+1));
        }
        if((dir == 1 || dir == 2) && (now_x+1 < n && now_x+1 >= 0)){
            if(map[now_x+1][now_y] == 1) continue;
            d[1][now_x+1][now_y]++;
            q.push(make_tuple(1, now_x+1, now_y));
        }
        if((now_y+1 < n && now_y+1 >= 0) && (now_x+1 < n && now_x+1 >= 0)){
            if(map[now_x][now_y+1] == 1) continue;
            if(map[now_x+1][now_y] == 1) continue;
            if(map[now_x+1][now_y+1] == 1) continue;
            
            d[2][now_x+1][now_y+1]++;
            q.push(make_tuple(2, now_x+1, now_y+1));
        }
    }
    /*
    for(int k=0; k < DIRECTION; k++){
        for(int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                cout << d[k][i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }
    */
    
    int answer = 0;
    for(int k=0; k < DIRECTION; k++){
        answer += d[k][n-1][n-1];
    }
    cout << answer << "\n";
    
    return 0;
}


