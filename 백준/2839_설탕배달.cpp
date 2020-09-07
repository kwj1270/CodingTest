#include <iostream>
#include <algorithm>
using namespace std;

int d[5001];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    
    d[0] = -1;
    d[1] = -1;
    d[2] = -1;
    d[3] = 1;
    d[4] = -1;
    d[5] = 1;
    
    for(int i=6; i <= n; i++){
        d[i] = -1;
        if(i%3 == 0 || d[i-3] != -1) d[i] = d[i-3]+1;
        if(i%5 == 0 || d[i-5] != -1) d[i] = d[i-5]+1;
    }
    
    cout << d[n] << "\n";
    return 0;
}
