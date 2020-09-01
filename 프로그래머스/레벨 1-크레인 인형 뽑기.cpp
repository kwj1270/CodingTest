#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s; // 담을 공간 
    for(int i=0; i < moves.size(); i++){ // 이동 횟수
        for(int j=0; j < board.size(); j++){
            int val = board[j][moves[i]-1];
            if(val > 0){
                if(!s.empty() && s.top() == val){
                    answer +=2;
                    s.pop();
                }
                else s.push(val);
                board[j][moves[i]-1] = 0;
                break;
            }
        }
    }
    
    return answer; // 사라진 인형의 갯수 
}
