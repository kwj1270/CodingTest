#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<double,int> &a, pair<double, int> &b){
    if(a.first == b.first){
        return a.second < b.second; // 인덱스가 낮은 친구부터
    }
    return a.first > b.first; // 실패율이 높은친구부터
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> d(501, 0);
    vector<int> people(501, 0);
    vector<pair<double, int>> per(N+1);
    per[0] = make_pair(0,0);
    people[0] = stages.size();
    
    for(int i=0; i < stages.size(); i++){
        d[stages[i]]++;
    }
    for(int i=1; i < 501; i++){
        people[i] = people[i-1]-d[i];
        if(people[i] == 0) break;
    }
    for(int i=1; i <= N; i++){
        if(d[i] == 0){
            per[i] = make_pair(0,i); continue;
        }
        if(people[i-1] == 0){break;} 
        double value = (double)d[i]/people[i-1];
        per[i] = make_pair(value, i);
    }    
    
    sort(per.begin()+1, per.end(), compare); 
    for(int i=1; i <= N; i++){
        answer.push_back(per[i].second);
    }
    
    return answer;
}
