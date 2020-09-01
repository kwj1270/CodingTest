#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> one = {1,2,3,4,5};
    vector<int> two = {2,1,2,3,2,4,2,5};
    vector<int> three = {3,3,1,1,2,2,4,4,5,5};
    
    vector<int> ans={0,0,0};
    
    for(int i=0, a=0; i < answers.size(); i++, a++){
        if(a == one.size()) a=0;
        if(answers[i] == one[a]) ans[0]++;
    }
    
    for(int i=0, a=0; i < answers.size(); i++, a++){
        if(a == two.size()) a=0;
        if(answers[i] == two[a]) ans[1]++;
    }
    
    for(int i=0, a=0; i < answers.size(); i++, a++){
        if(a == three.size()) a=0;
        if(answers[i] == three[a]) ans[2]++;
    }
    
    int max = *max_element(ans.begin(), ans.end());
    
    for(int i=0; i < ans.size(); i++){
        if(max == ans[i]) answer.push_back(i+1);
    }
    
    return answer;
}
