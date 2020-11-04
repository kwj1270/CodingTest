#include <iostream>

using namespace std;

int main() {
    // 5만 1만  5천 1천  500 100 50 10 1
    int insert  = 15000;
    
    int money [] = {50000, 10000, 5000, 1000, 500, 100, 50, 10, 1};
    int answer [9] = {0,};
    
    for(int i=0; insert != 0; i++){
        answer[i] = (insert/money[i]);
        insert %= money[i];
    }
    for(int i=0; i < 9 ; i++){
        cout << answer[i] << "\n";
    }
    
    return 0;
}


