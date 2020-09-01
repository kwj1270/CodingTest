#include <string>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int temp[3];
    int j=0;
    for(int i=0; i < dartResult.size(); i++){
        int powN = 0;
        bool isPass = true;
        if(dartResult[i] == 'S'){isPass = false; powN=1;}
        if(dartResult[i] == 'D'){isPass = false; powN=2;}
        if(dartResult[i] == 'T'){isPass = false; powN=3;}
        if(isPass) continue;
        if(i == 1){
            temp[j] = pow(dartResult[i-1]-'0',powN);
            if(dartResult[i+1] == '*'){
                temp[j] *= 2;
            }
            if(dartResult[i+1] == '#'){
                temp[j] *= -1;
            }
            j++;
            continue;
        }
        if(dartResult[i-2]-'0' == 1 && dartResult[i-1]-'0' == 0){
            temp[j] = pow(10,powN);
        }
        else if(dartResult[i-1]-'0' >= 0 && dartResult[i-1]-'0' <= 9){
            temp[j] = pow(dartResult[i-1]-'0',powN);
        }
        if(i < dartResult.size()-1 && dartResult[i+1] == '*'){
            temp[j] = temp[j] * 2;
            if(j != 0) temp[j-1] *= 2;
            j++;
            continue;
        }
        if(i < dartResult.size()-1 && dartResult[i+1] == '#'){
            temp[j] = temp[j] * -1;
            j++;
            continue;
        }
        j++;
    }
    for(int i=0; i < 3; i++){
        answer += temp[i];
    }
    return answer;
}
