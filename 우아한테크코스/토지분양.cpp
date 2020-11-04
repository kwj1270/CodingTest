#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int lands[][4] = {{10,0,30,5}, {0,30,20,50}, {30,30,40,40}};
    int wells[][4] = {{15,15,25,25}, {40,10,50,20}};
    int point[] = {10,10,30,30};
   
    int lands_row = sizeof(lands) / sizeof(lands[0]);
    int wells_row = sizeof(wells) / sizeof(wells[0]);

    //cout << row << "\n";
    
    for(int i=0; i < lands_row; i++){
        if((lands[i][0] <= point[0] && lands[i][2] <= point[0]) &&
           (lands[i][0] <= point[2] && lands[i][2] <= point[2]) &&
           (lands[i][1] <= point[1] && lands[i][3] <= point[1]) &&
           (lands[i][1] <= point[3] && lands[i][3] <= point[3])) { cout << false << "\n"; return -1;}
    }
    
    for(int i=0; i < wells_row; i++){
        if((lands[i][0] <= point[0] && lands[i][2] <= point[0]) or
           (lands[i][0] <= point[2] && lands[i][2] <= point[2]) or
           (lands[i][1] <= point[1] && lands[i][3] <= point[1]) or
           (lands[i][1] <= point[3] && lands[i][3] <= point[3])) { cout << true << "\n"; return -1;}
    }
    cout << false << "\n";
    
    return 0;
}


