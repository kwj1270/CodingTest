#include <iostream>
using namespace std;
    
int d[10000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin >> n;
    
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    
    for(int i=3; i <= n; i++){
        d[i] = (d[i-1]%10)+(d[i-2]%10)%10;
    }
    
    cout << d[n]%10 << "\n";
    
    return 0;
}
