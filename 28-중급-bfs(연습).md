# 1. 뱀과 사다리 게임 https://www.acmicpc.net/problem/16928   
   
* 100개의 칸으로 나누어져 있는 게임이 있다. 1에서 100으로 가야한다.         
* 주사위를 굴려서 나온 수 만큼 이동할 수 있으며,       
도착한 칸이 사다리인 경우에는 사다리를 타고 더 큰 번호의 칸으로 이동,       
도착한 칸이 뱀인 경우에는 더 작은 번호의 칸으로 이동한다.          
* 주사위에 나온수를 정할 수 있을 때, 최소 몇 번 굴려야 하는지 구하는 문제         
    
___
   
* 게임에서 뱀과 사다리의 구분은 중요하지만 구현에서는 중요하지 않다.    
* x -> y 로 간다는 점만 중요하다   
* 새로운 배열 next[x] 를 만들어서, x 이후에 도착할 곳을 모두 기록  
* 뱀이나 사다리일 경우 next[x] = y
* 일반 주사위로 갈 경우 next[x] = x 
* 나중에 값을 가져올 때 y=next[y] 를 사용하여 바로 이동칸으로 가게끔 한다.  

```c++
#include <iostream>
#include <algorithm>
#include <queue>
#define next _next
using namespace std;
int dist[101];
int next[101];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=100; i++) {
        next[i] = i; // 일반칸 초기화
        dist[i] = -1; // -1로 초기화.
    }
    while (n--) {
        int x, y;
        cin >> x >> y;
        next[x] = y; // 만약 x에 도착하면 그 위치는 y가 된다는 의미이다.
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        next[x] = y; // 마찬가지.
    }
    dist[1] = 0; // 1부터 시작으므로 거리 0으로 초기화.
    queue<int> q; // 큐
    q.push(1); // 큐에 위치 넣기.
    while (!q.empty()) {
        int x = q.front(); q.pop(); // 현재 위치.
        for (int i=1; i<=6; i++) { // 주사위 가능성
            int y = x+i; // 다음 이동 위치.
            if (y > 100) continue; // 100 이상이면 오바니까 넘기고.
            y = next[y]; // 일반 칸일 경우 일반 값이 들어오고 -> 사다리나 뱀일 경우 그 다음 이동할 곳의 값이 온다.
            // 즉 저절로 다음 이동할 곳의 값이 된다.
            if (dist[y] == -1) { // 방문한적이 없다면
                dist[y] = dist[x] + 1; // 이전 dp에서 +1을 한값이다.
                q.push(y);
            }
        }
    }
    cout << dist[100] << '\n';
    return 0;
}

```

# 2. 데스나이트 https://www.acmicpc.net/problem/16948

```c++
#include <iostream>
#include <algorithm>
#include <queue>
#define next _next
using namespace std;

int dx[] = {-2, -2, 0, 0, 2, 2}; // r
int dy[] = {-1, 1, -2, 2, -1, 1}; // c
int n;
int sx, sy, ex, ey;
int main() {
    cin >> n;
    int d[n][n];
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            d[i][j] = -1;
        }
    }
    cin >> sx >> sy >> ex >> ey;
    
    queue<pair<int, int>>q;
    q.push(make_pair(sx, sy));
    d[sx][sy] = 0;
    while (!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        for(int i=0; i < 6; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                if(d[nx][ny] == -1 || d[nx][ny] > d[now_x][now_y]+1){
                    d[nx][ny] = d[now_x][now_y]+1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    
    cout << d[ex][ey] << "\n";
    
    
    return 0;
}

```
