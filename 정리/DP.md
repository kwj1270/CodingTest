# DP
* 큰 문제를 작은 문제로 나눠서 푸는 알고리즘
* 주로 패턴이 있으며 한단계 한단계 진행되서 올라온다고 보면 된다.   
* 다이나믹 프로그래밍이 수행되려면 2가지 속성이 만족해야 된다.
  * Overlapping Subproblem : 겹치는 부분(작은)문제 -> 큰 문제와 작은 문제의 풀이가 같다.   
  * Optimal Substructure : 최적부분구조 -> 작은 문제의 조합으로 큰 문제를 풀 수 있다.  
* **문제에서 출력하기 원하는 값은 dp 의 값이다.**        

## 다이나믹 프로그래밍의 특징 
* 다이나믹 프로그래밍에서 각 문제는 한 번만 풀어야 한다.
* Optimal Substructure를 만족하기 때문에, 같은 문제는 구할 때마다 정답이 같다.
* 따라서, 정답을 한 번 구했으면, 정답을 어딘가에 메모해놓는다.
* 이렇게 저장함으로써 중복된 계산을 진행하지 않고 빠르게 값만 활용할 수 있도록 한다.
* 이런 메모하는 것을 코드의 구현에서는 배열에 저장하는 것으로 할 수 있다.
* 메모를 한다고 해서 영어로 Memorization이라고 한다.

## 점화식 세우기    
    
**기본적인 DP 문제들**
* 2 X N 타일 : https://www.acmicpc.net/problem/11726
	* 아주 베이직한 점화식 문제
	* 2x1, 1x2 이므로 한칸전 모든 경우의수 + 두칸전 모든 경우의수 = 답 
	* 여기서 얻어갈 점은 **도식화하여 생각하는 기초를 얻을 수 있다.**   
* 2 X N 타일 :https://www.acmicpc.net/problem/11727
	* 2 X N 타일의 변형문제 
	* 
*
*
*
*

## DP 전략 - 차원 늘리기
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
## dp 전략 


