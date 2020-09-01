#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    vector<int> map(n);
    for(int i=0; i < n; i++){
        map[i] = arr1[i] | arr2[i];
    }
    for(int i=0; i < n; i++){
    string str = "";
    int number = map[i];
        
    for(int j=0;j<n;j++){
        if(number%2 == 1) str += '#';
        else str += ' ';
        number = number/2;
    }
        reverse(str.begin(), str.end()); 
        answer[i] = str;
    }    
    return answer;
}
