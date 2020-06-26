BFS 알고리즘
=======================
* BFS의 목적은 임의의 정점에서 시작해서, 모든 정점을 **무조건 최소 한번씩** 방문하는 것이다.  
* BFS는 DFS와 달리 **모든 가중치가 1일때, 최단 거리**를 구하는 알고리즘이다.     
   
**BFS를 이용해 해결할 수 있는 문제의 조건**   
1. 최소 비용 문제이어야 한다. (최대 비용x)         
2. 간선의 가중치가 1이어야 한다.        
3. 정점과 간선의 개수가 적어야 한다. (적다는 것은 문제의 조건에 맞춰서 해결할 수 있다는 것을 의미한다.)   
   
* 간선의 가중치가 문제에서 구하라고 하는 최소 비용의 의미와 일치해야한다.    
* 즉, 거리의 최소값을 구하는 문제라면 가중치 == 거리,      
시간의 최소값을 구하는 문제라면 가중치 == 시간    

# 1. BFS - 숨바꼭질
* 수빈이의 위치 : N
* 동생의 위치 : K  
* 동생을 찾는 가장 빠른 **시간을 구하는 문제** (시간)    
___
* 수빈이가 할 수 있는 행동(K)   
1. 걷기 : X+1 또는 X-1로 이동 (1초)    
2. 순간이동: 2 ``*`` X로 이동 (1초)       
     
**여기서 간선은 x+1, x-1, x```*```2가 된다.**    
이러한 최소 비용을 얻고자 할 때 2번 이상 같은 곳을 방문하면 안되므로  
```check[]``` 를 사용해주고 순차적 단계가 이루어지고 ```dist[]```를 사용해주자.   
cnt로 하는 방법도 생각해봤는데 굳이 그럴 필요가 없어보인다. -> 더 복잡하게 만든다.  

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;
const int MAX = 200000;
bool check[MAX+1];
int dist[MAX+1];
int n, k;
void bfs(int start){
	queue<int> q;
	q.push(start);
	check[start] = true;
	dist[start] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();

		if(x-1 >= 0){
			if(check[x-1] == false){
				check[x-1] = true;
				q.push(x-1);
				dist[x-1] = dist[x]+1;
			}
		}
		if(x+1 < MAX){
			if(check[x+1] == false){
				check[x+1] = true;
				q.push(x+1);
				dist[x+1] = dist[x]+1;
			} 
		}
		if(x*2 < MAX){
			if(check[x*2] == false){
				check[x*2] = true;
				q.push(x*2);
				dist[x*2] = dist[x]+1;
			}
		}
	}
}



int main (void){
	cin >> n >> k;

	bfs(n);
	cout << dist[k] << "\n";

	return 0;
}
```  
    
***
# 2. BFS - 숨바꼭질4
* 수빈이의 위치 : N
* 동생의 위치 : K  
* 동생을 찾는 가장 **빠른 시간**과 **이동하는 방법**을 구하는 문제 (시간 및 방법)    
___  
* 수빈이가 할 수 있는 행동(K)   
1. 걷기 : X+1 또는 X-1로 이동 (1초)    
2. 순간이동: 2 ``*`` X로 이동 (1초)     


```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;
const int MAX = 200000;
bool check[MAX+1];
int dist[MAX+1];
int from[MAX+1];
int n, k;

void bfs(int start){
	queue<int> q;
	q.push(start);
	check[start] = true;
	dist[start] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(x-1 >= 0){
			if(check[x-1] == false){
				from[x-1] = x;
				check[x-1] = true;
				q.push(x-1);
				dist[x-1] = dist[x]+1;
			}
		}
		if(x+1 < MAX){
			if(check[x+1] == false){
				from[x+1] = x;
				check[x+1] = true;
				q.push(x+1);
				dist[x+1] = dist[x]+1;
			} 
		}
		if(x*2 < MAX){
			if(check[x*2] == false){
				from[x*2] = x;
				check[x*2] = true;
				q.push(x*2);
				dist[x*2] = dist[x]+1;
			}
		}
	}
}

void print(int go, int to){
	if(go != to){
		print(go, from[to]);
	}
	cout << to << " ";
}


int main (void){
	cin >> n >> k;

	bfs(n);
	cout << dist[k] << "\n";

	// 방법 1 //
	print(n, k);
	cout << "\n";

	
	// 방법 2 //
	stack<int> ans;
	for(int i=k; i != n; i=from[i]){
		ans.push(i);
	}
	while(!ans.empty()){
		cout << ans.top() << " ";
		ans.pop();
	}
	cout << "\n";

	return 0;
}
```
   
***
# 3. 이모티콘   
* 화면에 이모티콘은 1개다   
* 할 수 있는 연산 
	* 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장  
	* 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기  
	* 화면에 있는 이모티콘 중 하나를 삭제 
* S개의 이모티콘을 만드는데 걸리는 시간의 최소값을 구하는 문제  	
___
* 복사 : (s , c) -> (s,s)     
* 붙여넣기 : (s,c) -> (s+c, c)        
* 삭제 : (s,c) -> (s-1, c)      
* 2 <= S <= 1000 이기 때문에 BFS 탐색으로 가능하다.        

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;
const int MAX = 1000;
int s;
int dist[MAX+1][MAX+1];

void bfs(){
    memset(dist,-1,sizeof(dist));
    queue<pair<int,int>> q;
    q.push(make_pair(1,0));
    dist[1][0] = 0;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		if(dist[x][x] == -1){
			dist[x][x] = dist[x][y] +1;
			q.push(make_pair(x,x));
		}

		if(x + y <= s && dist[x+y][y] == -1){
			dist[x+y][y] = dist[x][y] +1;
			q.push(make_pair(x+y,y));
		}

		if(x - 1 >= 0 && dist[x-1][y] == -1){
			dist[x-1][y] = dist[x][y] +1;
			q.push(make_pair(x-1,y));
		}
	}
}

int main (void){
	cin >> s;
	bfs();

	int ans = -1;
	for(int i=0; i<= s; i++){
		if(dist[s][i] != -1){
			if(ans == -1 || ans > dist[s][i] ){
				ans = dist[s][i];
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
```

   
***
# 4. 숨바꼭질 3 
* 수빈이의 위치 : N
* 동생의 위치 : K  
* 동생을 찾는 가장 빠른 **시간을 구하는 문제** (시간)    
___
* 수빈이가 할 수 있는 행동(K)   
1. 걷기 : X+1 또는 X-1로 이동 (1초)      
2. 순간이동: 2 ``*`` X로 이동 (0초)        

가중치가 다를 경우 다른 종류만큼 큐를 만들어야 한다.     
       
```c++
#include <iostream>
#include <queue>
#include <deque>
using namespace std;
bool c[1000000];
int d[1000000];
int MAX = 1000000;
int main() {
    int n, m;
    cin >> n >> m;
    c[n] = true;
    d[n] = 0;
    queue<int> q;
    queue<int> next_queue;
    q.push(n);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now*2 < MAX) {
            if (c[now*2] == false) {
                q.push(now*2);
                c[now*2] = true;
                d[now*2] = d[now]; // 아무 가중치를 주지 않는 방법
            }
        }
        if (now-1 >= 0) {
            if (c[now-1] == false) {
                next_queue.push(now-1); // 2번째 큐
                c[now-1] = true;
                d[now-1] = d[now] + 1;
            }
        }
        if (now+1 < MAX) {
            if (c[now+1] == false) {
                next_queue.push(now+1); // 2번째 큐
                c[now+1] = true;
                d[now+1] = d[now] + 1;
            }
        }
        if (q.empty()) {// 첫번째 큐가 비면 
            q = next_queue; // 2번째 큐를 1번째 큐로 전환
            next_queue = queue<int>(); // 2번째 큐는 새로 생산
        }
    }
    cout << d[m] << '\n';
    return 0;
}
```
**덱을 이용한 방법**
```c++
#include <iostream>
#include <queue>
#include <deque>
using namespace std;
bool c[1000000];
int d[1000000];
int MAX = 1000000;
int main() {
    int n, m;
    cin >> n >> m;
    c[n] = true;
    d[n] = 0;
    deque<int> q;
    q.push_back(n);
    while (!q.empty()) {
        int now = q.front();
        q.pop_front();
        if (now*2 < MAX) {
            if (c[now*2] == false) {
                q.push_front(now*2); // 0일 경우 앞에다 넣기 
                c[now*2] = true;
                d[now*2] = d[now];
            }
        }
        if (now-1 >= 0) {
            if (c[now-1] == false) {
                q.push_back(now-1); // 가중치가 1인 경우 뒤에다 넣기
                c[now-1] = true;
                d[now-1] = d[now] + 1;
            }
        }
        if (now+1 < MAX) {
            if (c[now+1] == false) {
                q.push_back(now+1); // 가중치가 1인 경우 뒤에다 넣기
                c[now+1] = true;
                d[now+1] = d[now] + 1;
            }
        }
    }
    cout << d[m] << '\n';
    return 0;
}
```
   
***
# 5. BFS - 알고스팟 (어려운 문제니까 잘 알아보자)          
* 미로는 N x M 크기이고, 총 1 x 1 크기의 방으로 이루어져 있다.                 
* 빈 방은 자유롭게 다닐 수 있지만, 벽은 부수지 않으면 이동할 수 없다.              
* (x,y) 에 있을 때, 이동할 수 있는 방은 (x+1,y),(x-1,y),(x,y+1),(x,y-1)         
* (1,1)에서 (n,m)으로 이동하려면 벽을 최소 몇 개 부수어야 하는지 구하는 문제   
    
문제에서 가중치는 최소로 구해야 하는 값과 일치해야한다.   
즉, 벽을 부순 최소갯수를 구하는 문제이기에   
    
* 0 -> 0 의 가중치는 0     
* 0 -> 1 의 가중치는 1      
이런식으로 생각을 해서 문제를 풀 수 있다.   
  
```c++
#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;     
int d[555][555];      
int a[555][555];     
int n,m;     
int dx[] = {0,0,1,-1}; // <- 4방향
int dy[] = {1,-1,0,0}; // <- 4방향
int main() {
    scanf("%d %d",&m,&n); // 가로 세로 크기    
    for (int i=0; i<n; i++) { // 세로 반복문      
        for (int j=0; j<m; j++) { // 가로 반복문   
            scanf("%1d",&a[i][j]); // 여러개 입력받지만 한개씩 처리 <- 기존 배열     
            d[i][j] = -1; // 거리는 -1로 초기화 <- 거리 배열 
        }
    }
    deque<pair<int,int>> q; // 덱 준비 
    q.push_back(make_pair(0,0)); // 시작 점 넣기 
    d[0][0] = 0; // 시작점 거리0  
    while (!q.empty()) { 
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front(); // 앞에서 값 빼기  
        for (int k=0; k<4; k++) {  
            int nx = x+dx[k]; // 다음 이동 
            int ny = y+dy[k]; // 다음 이동  
            if (0 <= nx && nx < n && 0 <= ny && ny < m) { // 범위내에 있으면 
                if (d[nx][ny] == -1) { // 그리고 이동을 하지 않았다면   
                    if (a[nx][ny] == 0) { // 다음 이동할 곳이 0 이라면 
                        d[nx][ny] = d[x][y]; // 가중치 0이므로 그냥 그대로 값을 가져온다.
                        q.push_front(make_pair(nx,ny)); //큐에 넣기 -> 앞에다.  
                    } else { 
                        d[nx][ny] = d[x][y]+1; // 다른 값이면 가중치 1 추가 
                        q.push_back(make_pair(nx,ny)); // 큐에 넣기 <- 뒤에 놓기 
                    }
                }
            }
        }
    }
    printf("%d\n",d[n-1][m-1]); // 0부터 시작했으므로 -1 처리 해준다.  
    return 0;
}
```
```c++
#include <cstdio>
#include <queue>
using namespace std;
int d[555][555];
int a[555][555];
int n,m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    scanf("%d %d",&m,&n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d",&a[i][j]);
            d[i][j] = -1;
        }
    }
    queue<pair<int,int>> q;
    queue<pair<int,int>> next_queue;
    q.push(make_pair(0,0));
    d[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (d[nx][ny] == -1) {
                    if (a[nx][ny] == 0) {
                        d[nx][ny] = d[x][y];
                        q.push(make_pair(nx,ny));
                    } else {
                        d[nx][ny] = d[x][y]+1;
                        next_queue.push(make_pair(nx,ny));
                    }
                }
            }
        }
        if (q.empty()) {
            q = next_queue;
            next_queue = queue<pair<int,int>>();
        }
    }
    printf("%d\n",d[n-1][m-1]);
    return 0;
}
```
   
***
# 6. BFS - 알고스팟 2 벽 부수고 이동하기   

* N x M 의 행렬로 나타내는 지도에서 ```(1,1)```에서 ```N,M```으로 최단 거리로 이동하는 문제       
* 0은 빈칸, 1은 벽       
* 단, 벽은 한 번 부수고 지나갈 수 있다.            
  
```
(0) 빈칸 ---> 빈칸
     |
     ㄴ------> 벽

(1) 빈칸 ----> 빈칸
```
벽을 부수고 안부수고의 차이로 인해 할 수 있는 선택이 달라지게 된다.      
이는 앞서 봤던 파란 선 1개만 사용한다는 예시와 똑같다.       
    
즉 벽을 부수면 완전히 다른 영역이 된다고 생각하면 되고 이는 같은 값을 가지는 정점도 다른 영역이라 보면된다.  
그럼 어떻게 구분을 해주어야 할까?     

우리는 앞서 이모티콘 문제에서 배경화면과 클립보드 를 나타낸 이차원 배열을 나타냈다.        
예를 들어 배경화면에 7개가 있고 클립보드에 2개가 있는 것과      
배경화면에 7개가 있고 클립보드에 3개가 있는 것은 이전 과정이 똑같았을까?     
다르다 그래서 우리는 배경화면만 계산해도 될 것을 클립보드라는 차원을 같이 사용했다.     
       
위 문제도 마찬가지이다. 내가 지나온 ```[x][y]``` 라는 지점이 1번 부수고 왔을때랑 한번도 부수고 오지 않았을 때랑 다른 것이다.   
즉 정점이 다른것이다.   
그렇기에 우리는 ```[x][y]``` 에 이어서 벽을 부수었는지 안 부수었는지를 나타내는 차원을 하나더 만들어주면 된다.     
```[x][y][0] ,  [x][y][1]```       
그리고 앞서 말했듯이 x,y 값이 같더라도 세번째 자리수가 다르면 다른 값이고 다른 정점인 것이다.           
          
* 벽을 부순다는 조건이 없으면 일반적인 미로탐색 문제이다.         
* 어떤 칸에 방문했을 때, 벽을 부순 적이 있는 경우와 아직 부순 적이 없는 경우는 다른 경우이기 때문에  
* 상태 ```(i,j)``` 대신에 ```(i,j,k)``` ```(k==0 이면 벽을 부순 적이 없음, 1이면 있음)```으로 BFS 탐색을 진행한다.      
    

```c++
#include <iostream>
#include <queue>
#include <cstdio>
#include <tuple>
using namespace std;
int a[1000][1000]; // 입력받을 배열 
int d[1000][1000][2]; // distance 이고 3차원 -> 벽 부수고 안 부수고가 정점이 다르다.   
int dx[] = {0, 0, 1, -1}; // x 4방향 
int dy[] = {1, -1, 0, 0}; // y 4방향  
int main() {
    int n, m;
    scanf("%d %d",&n,&m);  
    for (int i=0; i<n; i++) {  
        for (int j=0; j<m; j++) {  
            scanf("%1d",&a[i][j]); // 배열에 한개씩 입력받기  
        }
    }
    queue<tuple<int,int,int>> q; // 튜플이란 자료형은 3개씩 입력받는 것이다.   
    d[0][0][0] = 1; // distance를 구하는 문제이기에 1을 추가 -> 빈칸이든 벽을 부수든 1씩 증가될 것이다.   
    q.push(make_tuple(0,0,0)); // 큐에 넣기 BFS 동작 
    while (!q.empty()) { // 큐가 빈다면   
        int x, y, z; // 3개의 값 
        tie(x,y,z) = q.front(); // 3개의 값 빼는 방법 tie() 이거 알아두자   
		q.pop(); // 큐에서 빼기 
        for (int k=0; k<4; k++) { // 4방향을 위한 방복문  
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위를 벗어나면 continue 즉, 넘겨라  
            if (a[nx][ny] == 0 && d[nx][ny][z] == 0) { // 다음 칸이 벽이 아니고 이동하지 않았다면  
                d[nx][ny][z] = d[x][y][z] + 1; // 현재에서 +1 값 증가시켜서 가라  
                q.push(make_tuple(nx,ny,z)); // 큐에 넣기  
            }
            if (z == 0 && a[nx][ny] == 1 && d[nx][ny][z+1] == 0) { // 만약 벽을 한번도 안 부수었다면 그리고 벽이고 이동하지 않았다면 -> 부수었다면 조건 성립x   
                d[nx][ny][z+1] = d[x][y][z] + 1; // 벽을 부수었다는 가정하에 값을 증가시켜라 -> 1번밖에 못하니 z에서 +1   
                q.push(make_tuple(nx,ny,z+1)); // 큐에 넣어라  
            }
        }
    }
    if (d[n-1][m-1][0] != 0 && d[n-1][m-1][1] != 0) { // 안부수고 간거랑 부수고 간거랑 둘다 끝까지 도착했다면 
        cout << min(d[n-1][m-1][0], d[n-1][m-1][1]); // 둘중 작은 친구로 
    } else if (d[n-1][m-1][0] != 0) { // 안부순 친구만 끝까지 도착했다면 
        cout << d[n-1][m-1][0]; // 안 부순 친구로 
    } else if (d[n-1][m-1][1] != 0) { // 부순 친구만 끝까지 도착했다면 
        cout << d[n-1][m-1][1]; // 부순 친구로 
    } else { // 도착을 못한다면 
        cout << -1; // -1 출력 
    }
    cout << '\n';
    return 0;
}
```
   
***
# 7. BFS - 탈출  
  
* 지도는 R행 C열이다. -> [R][C]    
* 비어있는 곳은 ```.``` 이다.     
* 물이 차있는 지역은 ```*``` 이다.     
* 돌은 ```X``` 이다.      
* 비버의 굴은 ```D``` 이다.       
* 고슴도치의 위치는 ```S``` 이다.     
* S -> D로 가는 문제이다.   
* 물은 인접한 곳에 1초에 1칸씩 퍼지는 형태이다   
* 물이 차 있으면 고슴도치는 이동을 못하니 물이 차기전에 이동해야 하는 문제이다.  





