#include <iostream>
#include <deque>
#include <queue>
#define INF 10000000
using namespace std;

vector<int> line[16];
long long cost[16][1 << 16];

int node;
long long answer_bit;

long long dfs(long long now, long long bit){
    if(bit == answer_bit){
        if (line[now][0] == 0) return INF;
        else return line[now][0];
    }
    if (cost[now][bit] != -1) return cost[now][bit]; // 메모라이제이션.
    
    cost[now][bit] = INF;
    
    for(int i=0; i < line[now].size(); i++){
        if(line[now][i] == 0) continue;
        long long next_value = line[now][i];
        if (next_value == 0) continue;
        if ((bit & (1 << i)) == (1 << i)) continue; // 방문했던 적이 있으면
        cost[now][bit] = min(cost[now][bit], next_value + dfs(i, bit | 1 << i));
     }
     return cost[now][bit];

}

int main() {
    cin >> node;
    for(int i=0; i < node; i++){
        for(int j=0; j < node; j++){
            long long value; cin >> value;
            line[i].push_back(value);
        }
    }
    answer_bit = (1 << node)-1;
    
    for(int i=0; i < node; i++){
        for(int j=0; j < (1 << node); j++){
            cost[i][j] = -1;
        }
    }
    
    cout << dfs(0,1) << "\n";
    return 0;
}
