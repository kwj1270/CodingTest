#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    
    for(int i=0; i < participant.size(); i++){
        m[participant[i]]++;
    }
    
    for(int i=0; i < completion.size(); i++){
        if(m.find(completion[i]) != m.end()){
            if(m[completion[i]] == 1){m.erase(completion[i]);}
            else m[completion[i]]--;
        }
    }
    

    for(int i=0; i < participant.size(); i++){
        if(m.find(participant[i]) != m.end()){
            if(m[participant[i]] == 1){
                answer += participant[i];
                break;
            }
        }
    }
    
    return answer;
}
