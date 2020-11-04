#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

// 대문자 65 -> 90
// 소문자 97 -> 122
int main() {
    const string insert = "I love you";
    const int UPPER_STANDARD = 65;
    const int LOWER_STANDARD = 97;
    map<char, char> dictionary;
    string answer = "";

    int upper_start = 65;
    int lower_start = 97;
    
    dictionary[' '] = ' ';
    for(int i=25; i >= 0; i--, upper_start++, lower_start++){
        dictionary[upper_start] = UPPER_STANDARD+i;
        dictionary[lower_start] = LOWER_STANDARD+i;
    }
    
    for(int i=0; i < insert.size(); i++){
        answer += dictionary[insert[i]];
    }
    cout << answer << "\n";
    
    return 0;
}


