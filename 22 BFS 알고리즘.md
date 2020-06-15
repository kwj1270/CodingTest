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
* 동생을 찾는 가장 빠른 시간을 구하는 무넺    
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


## 1.1. 소 주제
### 1.1.1. 내용1
```
내용1
```
## 1.2. 소 주제
### 1.2.1. 내용1
```
내용1
```

***
# 2. 대주제
> 인용
## 2.1. 소 주제
### 2.1.1. 내용1
```
내용1
```   

***
# 3. 대주제
> 인용
## 3.1. 소 주제
### 3.1.1. 내용1
```
내용1
```
