#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long d[91];
int main () {
    int n; cin >> n;
    d[0] = 0;
    d[1] = 1;
    
    for(int i=2; i <= 90; i++){
        d[i] = d[i-1]+d[i-2];
    }
    
    cout << d[n] << "\n";
    
    return 0;
}
