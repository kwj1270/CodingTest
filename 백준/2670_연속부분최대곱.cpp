#include <iostream>
using namespace std;
    
double a[10000];
double d[10000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;

    for(int i=0; i < num; i++){
        cin >> a[i];
    }

    d[0] = a[0];
    for(int i=1; i < num; i++){
        d[i] = a[i];
        if(d[i] < d[i-1]*a[i]){
            d[i] = d[i-1]*a[i];
        }
    }

    double max = -99999;
    for(int i=0; i < num; i++){
        if(max < d[i]){
            max = d[i];
        }
    }
    
    cout.setf(ios::fixed);
    cout.precision(3);
    cout << max << "\n";
    
    return 0;
}
