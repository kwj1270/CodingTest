# DP
* 큰 문제를 작은 문제로 나눠서 푸는 알고리즘
* 주로 패턴이 있으며 한단계 한단계 진행되서 올라온다고 보면 된다.   
* 다이나믹 프로그래밍이 수행되려면 2가지 속성이 만족해야 된다.
  * Overlapping Subproblem : 겹치는 부분(작은)문제
  * Optimal Substructure : 최적부분구조
* 우선 문제에서 출력하기 원하는 값은 dp 의 값이다.    


## Overlapping Subproblem : 겹치는 부분 문제
```c++
// 피보나치 수열   
0,1,1,2,3,5,8,13,21,34,55....
```
* 큰 문제 : N번째 피보나치 수를 구하는 문제
* 작은 문제 : N-1 번째 피보나치 수를 구하는 문제, N-2 번째 피보나치 수를 구하는 문제
문제를 작은 문제로 쪼갬으로 같은 형식의 구조를 취하고 있으니 **큰 문제와 작은 문제를 같은 방법으로 풀 수 있다.**

## Optimal Substructure : 최적 부분 구조
* 문제의 정답을 작은 문제의 정답을 통해 얻을 수 있다.    
* 서울에서 대구를 찍고 대전 으로 가는 방법의 갯수 구하기        
* 서울에서 대구로 가는 경우의 수  * 대구에서 대전으로 가는 경우의 수       

## 다이나믹 프로그래밍의 특징 
* 다이나믹 프로그래밍에서 각 문제는 한 번만 풀어야 한다.
* Optimal Substructure를 만족하기 때문에, 같은 문제는 구할 때마다 정답이 같다.
* 따라서, 정답을 한 번 구했으면, 정답을 어딘가에 메모해놓는다.
* 이렇게 저장함으로써 중복된 계산을 진행하지 않고 빠르게 값만 활용할 수 있도록 한다.
* 이런 메모하는 것을 코드의 구현에서는 배열에 저장하는 것으로 할 수 있다.
* 메모를 한다고 해서 영어로 Memorization이라고 한다.

```c++
int memo[100];
int fibonacci(int n){
  if(n <= 1) {
    return n;
  } else {
    if(memo[n] > 0){ // 메모라이제이션
      return memo[n];
    }
    memo[n] = fibonacci(n-1) + fibonacci(n-2); 
    return memo[n];
  }
}
```
  
## TOP_DOWN     
* 재귀방식을 이용하여 문제를 푸는 것을 의미합니다.      
* 누적되는 것이 아니라면 메모라이제이션을 사용하는 것이 권장됩니다.       
* 탈출 조건을 설정해야하고 리턴값을 무엇을 줘야할지도 결정합니다. (대부분은 dp에 들어가는 값입니다.)       

```c++
int memo[100];
int fibonacci(int n){
  if(n <= 1) {
    return n;
  } else {
    if(memo[n] > 0){ // 여기서 0은 아직 값을 넣지 않았다는 뜻
      return memo[n];
    }
    memo[n] = fibonacci(n-1) + fibonacci(n-2); 
    return memo[n];
  }
}
```
## BOTTOM_UP
* 하나하나 차근차근 올라가는 방식으로 구현합니다.          
* 리턴과 매개변수를 신경써줘도 되지 않으니 대부분의 dp에서는 이러한 방식을 사용합니다.        
* 2,3차원 구현에도 편합니다.   

```c++
int d[100];
int fibonacci(int n){
   d[0] = 0;
   d[1] = 1;
   for(int i=2; i <= n; i++){
      d[i] = d[i-1] + d[i-2];
   }
   return d[n];
}
```

## DP 전략 - 차원 늘리기 (이전 값)
```c++
#include <iostream> 
using namespace std; 

int d[101][10]; // 길이, 현재 계단의 높이     
int mod = 1000000000;

int main(void) { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    cin.ignore();
    
	for(int i=1;i <=9 ; i++){ d[1][i] = 1;} // 길이가 1인 경우는 1가지 경우밖에 없으므로 1로 초기화   

	for(int i=2; i <= n ;i++){
		for(int j=0 ; j <= 9;j++){
			d[i][j] = 0; // 시작은 우선 0으로 
			if (j-1 >= 0) d[i][j] += d[i-1][j-1]; // 현재 계단이 1이상이라면 아래에서 올라올 수 있다.   
			if (j+1 <= 9) d[i][j] += d[i-1][j+1]; // 현재 계단이 8이하라면 위에서 내려올 수 있다.  
			d[i][j] %= mod;  
		}
	}
	long long result = 0;
	for(int i=0;i<=9;i++) result += d[n][i]; // 1부터 9까지의 모든 경우의 수 추가 
	result %= mod;

	cout << result << "\n";

    return 0; 
}
```
