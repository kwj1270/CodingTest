BFS 알고리즘
=======================
* BFS의 목적은 임의의 정점에서 시작해서, 모든 정점을 **무조건 최소 한번씩** 방문하는 것이다.  
* BFS는 DFS와 달리 ** 모든 가중치가 1일때, 최단 거리**를 구하는 알고리즘이다.     
   
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
