# 우아한테크코스 코딩테스트 분석
# 1. 정렬을 생각하라

### 동전 갯수 세기:  
> 돈이 주어지면 그 돈을 각 지폐/동전으로 분류하는데 이때 분류된 갯수를 출력

* 가장 큰 지폐/동전 순서대로 나누기 -> 갯수 
* 가장 큰 지폐/동전 순서대로 나머지 -> 다음 계산될 돈 
* 반복

풀이 : 갯수 담는 배열, 화폐 기준 배열 2개 만들고 반복 진행   
   
https://github.com/kwj1270/CodingTest/blob/master/%EC%9A%B0%EC%95%84%ED%95%9C%ED%85%8C%ED%81%AC%EC%BD%94%EC%8A%A4/%EB%8F%99%EC%A0%84%EA%B0%AF%EC%88%98%EC%84%B8%EA%B8%B0.cpp

### 배달과 갯수 쿠폰: 
> 음식을 여러 개 시키고, 쿠폰도 여러 개 있는 경우(값이 다를 수 있음) 가장 저렴하게 구매할 방법으로 적용한 금액을 구하는 프로그램

* 음식 여러개 존재 
* 쿠폰 여러개 존재
* 가장 효율적인 계산 비용은?  
    
풀이 : Arrays.sort()와 배열, for문, if-else문을 이용함
    
https://github.com/kwj1270/CodingTest/blob/master/%EC%9A%B0%EC%95%84%ED%95%9C%ED%85%8C%ED%81%AC%EC%BD%94%EC%8A%A4/%EB%B0%B0%EB%8B%AC%EA%B3%84%EC%82%B0%EA%B3%BC%EC%BF%A0%ED%8F%B0.java

# 2. 공간지능력 판단 -> 그림을 그려라!
### 토지분양:
> 새로운 토지를 분양하려는데 식수지가 있어야 하고, 같은 토지를 다시 분양하면 안된다.(걸치는 것은 가능)
   
조건 연산자를 얼마나 잘 활용하는지를 확인   
   
* 새로운 토지가 기존 토지에 완전히 포함되어 있으면 안됨 -> 4개 점 안에 다 있는지 확인
* 식수지는 조금이라도 걸쳐도 됨 -> 4개 점 안에 하나라도 있는지 확인

https://github.com/kwj1270/CodingTest/blob/master/%EC%9A%B0%EC%95%84%ED%95%9C%ED%85%8C%ED%81%AC%EC%BD%94%EC%8A%A4/%ED%86%A0%EC%A7%80%EB%B6%84%EC%96%91.cpp   
      
# 3. 문자처리 
### 청개구리 (아스키/유니코드 활용)
> a -> z, A -> Z 

* 각 숫자들은 26차이가 나고 좁혀질수로 25,24,23 을 기안하여 문제를 품 
* 소문자뿐만 아니라 대문자도 같이 해줘야하므로 2가지 나눠서 진행 
* map 을 이용하여 바로 반환값 주도록 변환 -> map<char, char> 인데 숫자를 char 로 넣으면 바로 문자로 사용가능 

https://github.com/kwj1270/CodingTest/blob/master/%EC%9A%B0%EC%95%84%ED%95%9C%ED%85%8C%ED%81%AC%EC%BD%94%EC%8A%A4/%EC%B2%AD%EA%B0%9C%EA%B5%AC%EB%A6%AC.cpp   

### 중복암호(자료구조-스택)   
> browssn -> brown 으로 처리 

* 스택을 이용해서 하나씩 들여오는 방법을 이용 
* 비어있으면 무조건 입력 
* top 이랑 들어오는 값이랑 비교해서 같으면 넣어주지 않고 오히려 기존것을 빼주면 되다.
* 위 2조건이 아니면 그냥 입력 

https://github.com/kwj1270/CodingTest/blob/master/%EC%9A%B0%EC%95%84%ED%95%9C%ED%85%8C%ED%81%AC%EC%BD%94%EC%8A%A4/%EC%A4%91%EB%B3%B5%EC%95%94%ED%98%B8%EC%A0%9C%EA%B1%B0.cpp

# 구현을 해라 (시뮬레이션) -> 예외처리 잘해라 
### 369게임
> 단순히 3의 배수가 들어있으면 손뼉치기 

https://github.com/kwj1270/CodingTest/blob/master/%EC%9A%B0%EC%95%84%ED%95%9C%ED%85%8C%ED%81%AC%EC%BD%94%EC%8A%A4/369%EC%86%90%EB%BC%89%EC%B9%98%EA%B8%B0.cpp

### 티켓팅
> 문자열 처리하고 세션 구현

* 이전에 저장된 세션에 따라 동작 유무바뀜 
* split 이용

https://github.com/kwj1270/CodingTest/blob/master/%EC%9A%B0%EC%95%84%ED%95%9C%ED%85%8C%ED%81%AC%EC%BD%94%EC%8A%A4/%ED%8B%B0%EC%BC%93%ED%8C%85_%EA%B0%9C%EC%84%A0.java


### 페이지 숫자대결
> 문자열 처리, 예외처리 생각 

* 예외처리부터 진행하고 계산 진행 
* 더하기, 곱한 값중 가장 큰값을 정답값으로 

https://github.com/kwj1270/CodingTest/blob/master/%EC%9A%B0%EC%95%84%ED%95%9C%ED%85%8C%ED%81%AC%EC%BD%94%EC%8A%A4/%ED%8E%98%EC%9D%B4%EC%A7%80%EC%88%AB%EC%9E%90%EB%8C%80%EA%B2%B0.cpp







