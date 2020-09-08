#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a,b,c;
int cad;
int d[301];
int main () {
    cin >> a >> b >> c;
    cin >> cad;
    
    for(int i=0; i <= cad; i+=a){
        for(int j=0; i+j <= cad; j+=b){
            for(int k=0; i+j+k <= cad; k+=c){
                d[i+j+k] = 1;
            }
        }
    }
    
    cout << d[cad] << "\n";
    
    
    return 0;
}
