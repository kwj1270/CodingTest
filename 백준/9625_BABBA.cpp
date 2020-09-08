#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    int n; cin >> n;
    
    pair<int, int> d[46];
    d[0] = make_pair(1, 0);
    d[1] = make_pair(0, 1); // a , b
    d[2] = make_pair(1, 1); // a , b
    for(int i=3; i <= n; i++){
        d[i] = make_pair(d[i-2].first+d[i-1].first , d[i-2].second+d[i-1].second);
    }
    cout << d[n].first << " " << d[n].second << "\n";
    
    return 0;
}
