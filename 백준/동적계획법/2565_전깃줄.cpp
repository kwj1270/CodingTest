#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <tuple>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<pair<int, int>> line;
    
    for(int i=0; i < n; i++){
        int a,b; cin >> a >> b;
        line.push_back(make_pair(a, b));
    }
    sort(line.begin(), line.end());
    
    int len = 0;
    int d[100];
    for (int i=0; i < n; i++) {
        d[i] = 1;
        for(int j=0; j < i; j++){
            if(line[i].second > line[j].second && d[i] < d[j]+1) d[i] = d[j]+1;
        }
        len = max(len, d[i]);
    }
   
    cout << n-len << "\n";
    
    
    return 0;
}


