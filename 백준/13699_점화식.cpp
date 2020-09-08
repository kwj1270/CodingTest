#include <iostream>
using namespace std;

long long d[36];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    
    d[0] = 1;
    for(int i=1; i <= n; i++){
        for(int j=0; j < i; j++){
            d[i] += d[j] * d[i-1-j];
        }
    }
    cout << d[n] << "\n";
    return 0;
}
