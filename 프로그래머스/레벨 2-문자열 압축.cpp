#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
 int answer = s.length();
    if(answer == 1) {return 1;}
    for(int i = 1; i <= s.length() / 2; i++){
        string standard = s.substr(0,i); // 0부터 i개까지 짜름
        string next = "";
        string compressed = "";
        int count = 1;
        for(int j = i; j < s.length(); j += i){ //처음부터 쭉 비교하기
            next = s.substr(j,i); // j부터 i개까지 자름
            if(!(standard.compare(next))){ // aabbaccc
                count++;
            }else{
                if(count == 1){
                    compressed += standard;
                    standard = next;
                }else {
                    compressed = compressed+to_string(count)+standard;
                    standard = next;
                    count = 1;
                }
            }
            if(i+j >= s.length()){
                if(count == 1) compressed += s.substr(j);
                else compressed = compressed+to_string(count)+standard;
                break;
            }
        }
        answer = answer < compressed.length()? answer : compressed.length();
    }
    return answer;
}
