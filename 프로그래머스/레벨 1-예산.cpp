#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    
    int sum = 0;
    for(int i=0; i < d.size(); i++){
        sum += d[i];
        if(sum <= budget){
            answer++;
        }
    }
    return answer;
}
