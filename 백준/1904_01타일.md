#include <iostream>
#include <string>

using namespace std;

int d[1000001];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    
    d[0] = 0; d[1] = 1; d[2] = 2;
    for(int i=3;i<=n;i++){
        d[i] = d[i-2] + d[i-1];
        d[i] %= 15746;
    }

    cout << d[n] << "\n";
    
}
