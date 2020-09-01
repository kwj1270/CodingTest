#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int max = skill.size();
    map<char, int> m;
    
    for(int i=max, a=0; i > 0; i--, a++){
        m.insert(make_pair(skill[a], i));
    }
    for(int i=0; i < skill_trees.size(); i++){
        int previousValue = max;
        bool ok = true;
        for(int j=0; j < skill_trees[i].size(); j++){
            if(m.find(skill_trees[i][j]) == m.end()){continue;}
            if(previousValue > m[skill_trees[i][j]]){ ok =false; break;}
            previousValue--;
        }
        if(ok) answer++;
    }
    return answer;
}
