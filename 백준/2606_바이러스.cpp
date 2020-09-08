#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool node[101];
int main() {
    int n, k;
    cin >> n >> k;
    vector<int>line[n+1];
    
    for(int i=0; i < k; i++){
        int from, to;
        cin >> from >> to;
        line[from].push_back(to);
        line[to].push_back(from);
    }
    
    queue<int> q;
    node[1] = true;
    q.push(1);
    int cnt = -1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cnt++;
        for(int i=0; i < line[now].size(); i++){
            int next = line[now][i];
            if(node[next] == false){
                node[next] = true;
                q.push(next);
            }
        }
    }
    cout << cnt << "\n";
    
    return 0;
}
