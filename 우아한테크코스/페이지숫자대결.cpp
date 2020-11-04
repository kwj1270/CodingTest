#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

// 1. 조건 1~400 이 와야한다. // 0이나 401이 오면 return
// 2. 왼쪽 홀수, 오른쪽 짝수

// 이전에 왼쪽 오른쪽이 1차이 나는지 확인
// 왼쪽이 홀수인지 그리고 오른쪽이 짝수인지 검증
// ㅁ 예외사항 발생시 -1 출력하고 끝내기 -> 다음 코드 사용 안하도록

// 계산식
// ㅁ 각 자리 더하기
// ㅁ 각 자리 곱하기

// 포비 승리 1
// 크롱 승리 2
// 무승부 0
// 예외사항 -1

int getSum(string number){
    int sum = 0;
    for(int i=0; i < number.size(); i++){
        sum += number[i] - '0';
    }
    return sum;
}

int getMul(string number){
    int mul = 1;
    for(int i=0; i < number.size(); i++){
        if(number[i] == 0) return 0;
        mul *= number[i] - '0';
    }
    return mul;
}

int main() {
    int pobi[] = {99, 102};
    int crong[] = {211, 212};
    
    
    // 예외처리
    for(int i=0; i < 2; i++){
        if(pobi[i] < 1 || crong[i] < 1 || pobi[i] > 400 || crong[i] > 400) { cout << -1 << "\n"; return -1;}
        if(i == 0 && (pobi[i]%2 == 0 || crong[i]%2 == 0)) { cout << -1 << "\n"; return -1;}
        if(i == 1 && (pobi[i]%2 == 1 || crong[i]%2 == 1)) { cout << -1 << "\n"; return -1;}
        if(i == 1 && (pobi[i]-1 != pobi[i-1] || crong[i]-1 != crong[i-1])) { cout << -1 << "\n"; return -1;}
    }
    //cout << "exception test clear\n";
    

    int pobi_maxValue = 0;
    int crong_maxValue = 0;
    for(int i=0; i < 2; i++){
        pobi_maxValue = max(pobi_maxValue, max(getSum(to_string(pobi[i])), getMul(to_string(pobi[i]))));
        crong_maxValue = max(crong_maxValue, max(getSum(to_string(crong[i])), getMul(to_string(crong[i]))));
    }
    if(pobi_maxValue > crong_maxValue){
        cout << 1 << "\n";
    }
    else if(pobi_maxValue < crong_maxValue){
        cout << 2 << "\n";
    } else {
        cout << 0 << "\n";
    }
    
    //cout << pobi_maxValue << " " << crong_maxValue << "\n";
    
    return 0;
}


