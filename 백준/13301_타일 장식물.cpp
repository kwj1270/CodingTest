#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long fibo[81];
int main () {
    int n;
    cin >> n;
    fibo[0] = 1;
    fibo[1] = 1;
    for(int i=2; i <= n; i++){
        fibo[i] = fibo[i-1]+fibo[i-2];
    }
    cout << (fibo[n-1]+fibo[n-2]+fibo[n-1])*2 << "\n";
   
    return 0;
}
