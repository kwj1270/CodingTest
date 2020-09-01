#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize == 0) return cities.size()*5;
    int answer = 0;
    vector<string> v;
    for(int i=0; i < cities.size(); i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);
        int j=0;
        for(; j < v.size();j++){
            if(cities[i] == v[j]){
                v.erase(v.begin()+j);
                v.push_back(cities[i]);
                answer++;
                break;
            }
        }
        if(j == v.size()){
            answer += 5;
            if(v.size() >= cacheSize){
                v.erase(v.begin());
            }
            v.push_back(cities[i]);
        }
    }
    
    return answer;
}
