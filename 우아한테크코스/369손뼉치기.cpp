#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int insert = 33;
    int d[10001] = {0,};
    
    for(int i=1; i < 10001; i++){
        d[i] = d[i-1];
        string number = to_string(i);
        //cout << number << "\n"; break;
        for(int j=0; j < number.size(); j++){
            if(number[j] != '0' && ((number[j]-'0') % 3 == 0)) d[i]++;
        }
    }
    cout << d[insert] << "\n";

    return 0;
}
