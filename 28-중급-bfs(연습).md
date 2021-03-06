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

* 데스 나이트는 r,c 에서 (r-2,c-1) / (r-2,c+1)/ (r,c-2)/ (r,c+2)/ (r+2,c-1)/ (r+2,c+1) 이동할 수 있다.   
* 크기가 N x N 인 체스판과 두 칸 (r1,c1) (r2,c2) 가 주어졌을 때 (r1,c1) -> (r2,c2) 이동하는 최소 이동횟수를 구하는 문제
* 5 <= N <= 200
* BFS로 해결할 수 있는 문제이다.  

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
# 3. DSLR https://www.acmicpc.net/problem/9019
* 4자리 숫자 A 와 B가 주어졌을 때   
* A -> B 로 바꾸는 최소 연산 
* D : N = ```2*N```
* S : N = ```N-1```
* L : 한자리씩 왼쪽으로  
* R : 한자리씩 오른쪽으로
   
또한  
* 이 문제는 최소값을 구해야 하는건 맞지만   
* 어떠한 과정을 거쳐야 하는지를 구해야한다.   
* 배열을 하나 더 이용해서 어떤 과정을 거쳤는지를 저장해야 한다.   
* ```how[i] = i```;    
* 단, 모두 기록하면 안된다. -> 모두 기록하면 공간이 너무 많이 필요해진다.     
  
```c++
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
bool check[10001];
int dist[10001];
char how[10001];
int from[10001];
void print(int n, int m) {
    if (n == m) return;
    print(n, from[m]);
    cout << how[m];
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        // 초기화.
        memset(check,false,sizeof(check));
        memset(dist,0,sizeof(dist));
        memset(how,0,sizeof(how));
        memset(from,0,sizeof(from));
        
        check[n] = true; // a의 위치를 true
        dist[n] = 0; // 거리는 0일 테고
        from[n] = -1; // -1로 부터 왔다 -> 역추적 종료 시점
        queue<int> q; // 큐 생성
        q.push(n); // 큐시작
        
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            int next = (now*2) % 10000;
            if (check[next] == false) {
                q.push(next);
                check[next] = true;
                dist[next] = dist[now]+1;
                from[next] = now;
                how[next] = 'D';
            }
            next = now-1; // now 가 0이면?
            if (next == -1) next = 9999; // 아 넥스트를 9999로 바꾸는 구나
            if (check[next] == false) {
                q.push(next);
                check[next] = true;
                dist[next] = dist[now]+1;
                from[next] = now;
                how[next] = 'S';
            }
            next = (now%1000)*10 + now/1000;
            if (check[next] == false) {
                q.push(next);
                check[next] = true;
                dist[next] = dist[now]+1;
                from[next] = now;
                how[next] = 'L';
            }
            next = (now/10) + (now%10)*1000;
            if (check[next] == false) {
                q.push(next);
                check[next] = true;
                dist[next] = dist[now]+1;
                from[next] = now;
                how[next] = 'R';
            }
        }
        print(n, m);
        /*
        string ans = "";
        while (m != n) {
            ans += how[m];
            m = from[m];
        }
        reverse(ans.begin(), ans.end());
         */
        cout << '\n';
    }
    return 0;
}

```

# 4. 연구소 https://www.acmicpc.net/problem/14502
   
* N x M 크기의 직사각형 지도가 있고, 1 x 1 크기의 칸으로 이루어져 있다. (3 <= N,M <= 8)   
* 칸, 빈칸, 벽으로 이루어짐 
* 일부 빈칸에는 바이러스가 있거, 인접하 빈 칸으로 계속 퍼져나간다.   
* 벽을 3개 세워서 바이러스가 퍼질 수 없는 곳의 크기를 구하는 문제  

```c++
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;


int n, m;
int map[8][8];
int virus[8][8];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs(){
    queue<pair<int,int>> q;
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            virus[i][j] = map[i][j];
            if(virus[i][j] == 2) q.push(make_pair(i, j));
        }
    }
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(virus[nx][ny] == 0){
                    virus[nx][ny] = 2;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    int cnt = 0;
    for(int i=0; i < n;i++){
        for(int j=0; j < m; j++){
            if(virus[i][j] == 0) cnt++;
        }
    }
    
    return cnt;
}


int main() {
    cin >> n >> m;
    memset(map, 1, sizeof(map));
    memset(virus, -1, sizeof(virus));
    
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            cin >> map[i][j];
        }
    }
    
    int ans = 0;
    for (int x1=0; x1<n; x1++) { // 일차 x
        for (int y1=0; y1<m; y1++) { // 일차 y
            if (map[x1][y1] != 0) continue; // 0이 아니라면 넘겨라
            for (int x2=0; x2<n; x2++) { // 2차 x
                for (int y2=0; y2<m; y2++) { // 2차 y.
                    if (map[x2][y2] != 0) continue; // 0이 아니라면 넘겨라.
                    for (int x3=0; x3<n; x3++) { //3차 x
                        for (int y3=0; y3<m; y3++) { // 3차 y
                            if (map[x3][y3] != 0) continue; // 0이 아니라면 넘겨라.
                            if (x1 == x2 && y1 == y2) continue; // 같으면 넘겨라
                            if (x1 == x3 && y1 == y3) continue; // 같으면 넘겨라
                            if (x2 == x3 && y2 == y3) continue; // 같으면 넘겨라
                            map[x1][y1] = 1;
                            map[x2][y2] = 1;
                            map[x3][y3] = 1;
                            int cur = bfs();
                            if (ans < cur) ans = cur;
                            map[x1][y1] = 0;
                            map[x2][y2] = 0;
                            map[x3][y3] = 0;
                        }
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    
    return 0;
}

```

# 5. 돌그룸 https://www.acmicpc.net/problem/12886

* 돌이 3개의 그룹으로 나누어져있고, 각 그룹에는 돌이 A,B,C 개 있다. (A,B,C <= 500)   
* 돌은 단계별로 움직이고, 각 단계는 다음과 같다.   
   1. 크기가 같지 않은 두 그룹을 고른다. 돌의 갯수가 작은쪽을 x, 큰쪽을 y라고 한다.   
   2. x에 있는 돌의 갯수를 x+x개로, y에 있는 돌의 갯수를 y-x 로 만든다.   
   3. ABC 가 주어졌을 때, 모든 그룹에 들어있는 돌의 개수를 같게 만들 수 있는지 구하는 문제   
   
```c++
#include <iostream>
#include <queue>
using namespace std;
bool check[1501][1501]; // 1500 - x - y == z 이기 때문에 2개만 사용한다.
int sum; // 총합
void go(int x, int y) {
    if (check[x][y]) return; // 이미 온적이 있다면 반환
    check[x][y] = true; // 없으니 true 표시.
    int a[3] = {x, y, sum-x-y}; // 값 3개 생성 -> x,y,z
    for (int i=0; i<3; i++) { // 3번 돌리고
        for (int j=0; j<3; j++) { // 또 3번 돌려서
            if (a[i] < a[j]) { // 00 01 02, 10 11 12, 20,21,22
                int b[3] = {x, y, sum-x-y}; // x,y,z
                b[i] += a[i]; // i랑 j만 사용해서 값 합치기
                b[j] -= a[i]; // 값빼기
                go(b[0], b[1]); // 다음 값 넣어서 재귀.
            }
        }
    }
}
int main() {
    int x, y, z;
    cin >> x >> y >> z;
    sum = x + y + z;
    if (sum % 3 != 0) { // 처음부터 값이 만들어지지 않으면 0 리턴
        cout << 0 << '\n';
        return 0;
    }
    go(x, y);
    if (check[sum/3][sum/3]) { // 값이 나눠지면 ok
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n'; // 값이 나눠지지 않으면 false
    }
    return 0;
}

```
