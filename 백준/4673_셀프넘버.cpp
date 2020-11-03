#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    
    vector<bool> selfNumber(10001, true);
    selfNumber[0] = false;
    
    for(int i=0; i < 10001; i++){
        int sum = i;
        string str = to_string(i);
        for (char ch : str) {
            sum += ch -'0';
        }
        selfNumber[sum] = false;
    }
    
    for(int i=0; i < 10001; i++){
         if(selfNumber[i]) cout << i << "\n";
     }
    
    
    return 0;
}


