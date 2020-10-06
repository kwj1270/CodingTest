#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <tuple>
#include <queue>

using namespace std;

int row, column;
int clearTime = 0;
int allCount = 0;
int map[100][100];
int d[100][100];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void searchAir(int x, int y){
    if(d[x][y] == -1) d[x][y] = 0;
    for(int i=0; i < 4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx >= 0 && nx < row && ny >= 0 && ny < column && map[nx][ny] == 0 && d[nx][ny] == -1){
            searchAir(nx, ny);
        }
    }
    return;
}

bool allClear(){
    return true;
}


int main() {
    cin >> row >> column;
    
    for (int i=0; i < row; i++) {
        for(int j=0; j < column; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) allCount++;
        }
    }
    memset(d, -1, sizeof(d));
    
    bool ok = false;
    int checkCount = 0;
    while (true) {
        //if(ok) break;
        if(checkCount == allCount) break;
        searchAir(0, 0);
        
        cout << "\n";
        for(int i=0; i < row; i++){
            for(int j=0; j < column; j++){
                cout << d[i][j] << "\t";
            }
            cout << "\n";
        }
        clearTime++;
        //if(clearTime == 3) ok = true;
    }
    
    return 0;
}


