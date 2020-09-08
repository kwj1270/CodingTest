#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int d[100001];
int main () {
    int n; cin >> n;
    d[0] = -1;
    d[1] = -1;
    d[2] = 1;
    d[3] = -1;
    d[4] = 2;
    d[5] = 1;
    
    for(int i=6; i <= n; i++){
        if(i%2 == 0 || d[i-2] != -1) d[i] = d[i-2]+1;
        if(i%5 == 0 || d[i-5] != -1) d[i] = d[i-5]+1;
    }
    
    cout << d[n] << "\n";

    
    return 0;
}
