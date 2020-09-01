#include <string>
#include <vector>
#include <iostream>

using namespace std;

int clickNumber(char click, int hand){
    int dest = click;
    int r = dest / 3;
    int c = dest % 3;
    if (c == 0) {
        c = 3;
    }
    int nr = hand / 3;
    int nc = hand % 3;
    if (nc == 0) {
        nr--;
        nc = 3;
    }
    return abs(r - nr) + abs(c - nc);
}

string solution(vector<int> numbers, string hand) { //키패드// 손잡이
    string answer = "";
    int left = 10;
    int right = 12;
    
    for(int i=0; i < numbers.size(); i++){
        int click = numbers[i];
        if(click == 1 || click == 4|| click == 7){
            answer += 'L';
            left = click;
            continue;
        }
        else if(click == 3 || click == 6 || click == 9)   {
            answer += 'R';
            right = click;
            continue;
        } else {
            if(click == 0) click = 11;
            int x = clickNumber(click, left);
            int y = clickNumber(click, right);
            if(x == y) {
                if(hand == "left") {left = click; answer+='L';}
                else {right =click; answer+='R';}
            } 
            if(x < y) {left = click; answer+='L';}
            else if(x > y)  {right = click; answer+='R';}
        }
    }
    return answer;
}
